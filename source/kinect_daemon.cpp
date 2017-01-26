#include <sys/stat.h>
#include <zmq.hpp>
#include <iostream>
#include <vector>
#include <boost/thread/thread.hpp>

#include "CMDParser.hpp"
#include "FileBuffer.hpp"
#include "ChronoMeter.hpp"
#include "timevalue.hpp"
#include "clock.hpp"
#include "zmq_messages.cpp"
#define STR_BOOL(s) ((s=="1")?true:false)

bool play(std::string const filename, unsigned const num_kinect_cameras, float const max_fps, bool const rgb_is_compressed, bool const loop = true) {
	unsigned min_frame_time_ns = 1000000000/max_fps;

	const unsigned colorsize = rgb_is_compressed ? 691200 : 1280 * 1080 * 3;
	const unsigned depthsize = 512 * 424 * sizeof(float);
	const unsigned framesize = (colorsize + depthsize) * num_kinect_cameras;

	struct stat stat_buf;
	stat(filename.c_str(), &stat_buf);

	const float length_recording = (float)stat_buf.st_size / ((float)framesize * 20.0f);


	FileBuffer fb(filename.c_str());
	if(!fb.open("r")){
		std::cerr << "error opening " << filename << " exiting..." << std::endl;
		return 1;
	}
	fb.setLooping(loop);

	zmq::context_t ctx(1); // means single threaded
	zmq::socket_t  socket(ctx, ZMQ_PUB); // means a publisher
	uint32_t hwm = 1;
	socket.setsockopt(ZMQ_SNDHWM,&hwm, sizeof(hwm));
	std::string endpoint("tcp://141.54.147.23:7000");
	socket.bind(endpoint.c_str());

	sensor::timevalue ts(sensor::clock::time());


	ChronoMeter cm;
	const double starttime = cm.getTick();

	bool running = true;
	// unsigned frame_number = start_number;
	while(running){

		// ++frame_number;
		// if(frame_number >= end_frame){
		// 	running = false;
		// 	fb.rewind();
		// }

		zmq::message_t zmqm(framesize);

		unsigned offset = 0;
		for(unsigned i = 0; i < num_kinect_cameras; ++i){
			fb.read((unsigned char*) zmqm.data() + offset, colorsize);
			offset += colorsize;
			fb.read((unsigned char*) zmqm.data() + offset, depthsize);
			offset += depthsize;
		}

		// send frames
		socket.send(zmqm);

		const double currtime = cm.getTick();
		const double elapsed = currtime - starttime;

		if(!loop && elapsed > length_recording) { running = false; }

		// check if fps is correct
		sensor::timevalue ts_now = sensor::clock::time();
		long long time_spent_ns = (ts_now - ts).nsec();
		long long rest_sleep_ns = min_frame_time_ns - time_spent_ns;
		ts = ts_now;
		if(0 < rest_sleep_ns){
			sensor::timevalue rest_sleep(0,rest_sleep_ns);
			nanosleep(rest_sleep);
		}

	}

	return true;
}


bool play(std::string const filename) {
	return play(filename, 4, 20.0, true);
}


bool play_segment(std::string const filename, unsigned const num_kinect_cameras, float const max_fps, bool const rgb_is_compressed,
	unsigned const first_frame, unsigned const last_frame) {

	unsigned min_frame_time_ns = 1000000000/max_fps;

	const unsigned colorsize = rgb_is_compressed ? 691200 : 1280 * 1080 * 3;
	const unsigned depthsize = 512 * 424 * sizeof(float);
	const unsigned framesize = (colorsize + depthsize) * num_kinect_cameras;
	const unsigned num_frames = (last_frame - first_frame +1);
	const unsigned bytesize = num_frames * framesize;

	FileBuffer fb(filename.c_str());
	if(!fb.openRange("r", bytesize, framesize, first_frame, last_frame)){
		std::cerr << "error opening " << filename << " exiting..." << std::endl;
		return 1;
	}
	fb.setLooping(false);

	zmq::context_t ctx(1); // means single threaded
	zmq::socket_t  socket(ctx, ZMQ_PUB); // means a publisher
	uint32_t hwm = 1;
	socket.setsockopt(ZMQ_SNDHWM,&hwm, sizeof(hwm));
	std::string endpoint("tcp://127.0.0.1:7000");
	socket.bind(endpoint.c_str());

	sensor::timevalue ts(sensor::clock::time());

	for (int i = 0; i < num_frames; ++i) {
		zmq::message_t zmqm(framesize);
		fb.read((unsigned char*) zmqm.data(), framesize);

		// send frame
		socket.send(zmqm);

		// check if fps is correct
		sensor::timevalue ts_now = sensor::clock::time();
		long long time_spent_ns = (ts_now - ts).nsec();
		long long rest_sleep_ns = min_frame_time_ns - time_spent_ns;
		ts = ts_now;
		if(0 < rest_sleep_ns){
			sensor::timevalue rest_sleep(0,rest_sleep_ns);
			nanosleep(rest_sleep);
		}
	}

	return true;
}


bool record(std::string const record_to_this_filename, std::string const serverport, unsigned const num_kinect_cameras,
	float const num_seconds_to_record, bool const rgb_is_compressed) {

	std::cout << "Num:" << num_seconds_to_record <<std::endl;
	std::cout << "Start recording to.. " << record_to_this_filename << std::endl;

	const unsigned colorsize = rgb_is_compressed ? 691200 : 1280 * 1080 * 3;
	const unsigned depthsize = 512 * 424 * sizeof(float);
	const unsigned framesize = (colorsize + depthsize) * num_kinect_cameras;

	const unsigned min_frame_time_ns = 1000000000/15.0f;

	FileBuffer fb(record_to_this_filename.c_str());
	if(!fb.open("w", 0)){
		std::cerr << "error opening " << record_to_this_filename << " exiting..." << std::endl;
		return 1;
	}
	fb.setLooping(false);

	zmq::context_t ctx(1); // means single threaded
	zmq::socket_t  socket(ctx, ZMQ_SUB); // means a subscriber
	socket.setsockopt(ZMQ_SUBSCRIBE, "", 0);

	uint32_t hwm = 1;
	socket.setsockopt(ZMQ_RCVHWM,&hwm, sizeof(hwm));

	std::string endpoint("tcp://" + serverport);
	socket.connect(endpoint.c_str());

	sensor::timevalue ts(sensor::clock::time());


	ChronoMeter cm;
	const double starttime = cm.getTick();

	bool running = true;
	while(running){
		zmq::message_t zmqm(framesize);

		socket.recv(&zmqm); // blocking

		const double currtime = cm.getTick();
		const double elapsed = currtime - starttime;
		std::cout << elapsed << std::endl;
		if(elapsed > num_seconds_to_record) { running = false; }

		memcpy((char*) zmqm.data(), (const char*) &currtime, sizeof(double));

		// this should write the data from all cameras consecutively
		fb.write((unsigned char*) zmqm.data(), framesize);

		// check if fps is correct
		sensor::timevalue ts_now = sensor::clock::time();
		long long time_spent_ns = (ts_now - ts).nsec();
		long long rest_sleep_ns = min_frame_time_ns - time_spent_ns;
		ts = ts_now;
		if(0 < rest_sleep_ns){
			sensor::timevalue rest_sleep(0,rest_sleep_ns);
			nanosleep(rest_sleep);
		}
	}

	fb.close();
	std::cout << "Recording has finished!" << std::endl;
	return true;
}


/*bool play_record_in_sync(const std::string filename, const std::string rec_serverport, const std::string output_file,
	const int num_loops, unsigned const num_kinect_cameras, bool const rgb_is_compressed) {
	std::cout << "hello" << std::endl;

	const unsigned colorsize = rgb_is_compressed ? 691200 : 1280 * 1080 * 3;
	const unsigned depthsize = 512 * 424 * sizeof(float);
	const unsigned framesize = (colorsize + depthsize) * num_kinect_cameras;

	struct stat stat_buf;
	stat(filename.c_str(), &stat_buf);

	const float length_recording = (float)stat_buf.st_size / ((float)framesize * 20.0f);

	std::cout << stat_buf.st_size << std::endl;
	std::cout << framesize << std::endl;
	std::cout << length_recording << std::endl;

	for (int i = 0; i < num_loops-1; ++i) {
		std::cout << "Looping play.. " << i << std::endl;
		play(filename, num_kinect_cameras, 20, rgb_is_compressed, false);
	}

	std::cout << "RECORDING from " << rec_serverport << " to: " << output_file << std::endl;
	boost::thread th(record, output_file, rec_serverport, num_kinect_cameras, length_recording, rgb_is_compressed);
	play(filename, num_kinect_cameras, 20, rgb_is_compressed, false);
	th.join();
	return true;
}*/

bool play_record_in_sync(const std::string play_filename,
						const std::string rec_serverport,
						const std::string rec_file,
						const unsigned num_loops_before_rec,
						const unsigned start_frame,
						const unsigned end_frame,
						const float max_fps,
						const unsigned num_kinect_cameras,
						const bool rgb_is_compressed) {
	std::cout << "Starting play_record_in_sync.. " << std::endl;
	std::cout << "start_frame: " << start_frame << std::endl;
	std::cout << "end_frame: " << end_frame << std::endl;

	if (start_frame >= end_frame) {
		std::cout << "ERROR: start after end. "
				 << "start_frame is: " << start_frame
				 << "end_frame is: " << end_frame << std::endl;
	}


	const unsigned min_frame_time_ns = 1000000000/max_fps;

	const unsigned colorsize = rgb_is_compressed ? 691200 : 1280 * 1080 * 3;
	const unsigned depthsize = 512 * 424 * sizeof(float);
	const unsigned framesize = (colorsize + depthsize) * num_kinect_cameras;
	std::cout << "framesize is: " << framesize << std::endl;

	// 1. open play_filename set loop true
	struct stat stat_buf;
	stat(play_filename.c_str(), &stat_buf);

	FileBuffer fb_play(play_filename.c_str());
	if(!fb_play.open("r")){
		std::cerr << "error opening " << play_filename << " exiting..." << std::endl;
		return 1;
	}

	// open rec_filename
	FileBuffer fb_rec(rec_file.c_str());
	if(!fb_rec.open("w", 0)){
		std::cerr << "error opening " << rec_file << " exiting..." << std::endl;
		return 1;
	}

	// open rec_server_connection
	zmq::context_t ctx(1); // means single threaded
	zmq::socket_t  socket_rec(ctx, ZMQ_SUB); // means a subscriber
	socket_rec.setsockopt(ZMQ_SUBSCRIBE, "", 0);
	uint32_t hwm = 1;
	socket_rec.setsockopt(ZMQ_RCVHWM,&hwm, sizeof(hwm));
	std::string endpoint{"tcp://" + rec_serverport};
	socket_rec.connect(endpoint.c_str());

	//open play_server_connection
	zmq::socket_t  socket_play(ctx, ZMQ_PUB); // means a publisher
	socket_play.setsockopt(ZMQ_SNDHWM,&hwm, sizeof(hwm));
	std::string endpoint_play("tcp://141.54.147.23:7000");
	socket_play.bind(endpoint_play.c_str());

	ChronoMeter cm;
	sensor::timevalue ts(sensor::clock::time());

	const unsigned num_frames = fb_play.calcNumFrames(framesize);


	// loop play_filename for num_loops_before_rec
	for (int i = 0; i < num_loops_before_rec; ++i) {
		std::cout << "Looping play.. " << i << std::endl;
		fb_play.rewindFileTo(start_frame*framesize);
		// play(filename, num_kinect_cameras, 20, rgb_is_compressed, false);

		unsigned frames_run = start_frame;
		while(frames_run < end_frame && frames_run < num_frames){
			++frames_run;
			zmq::message_t zmqm(framesize);

			// this should read the data from all cameras consecutively
			fb_play.read((unsigned char*) zmqm.data(), framesize);

			// send frames
			socket_play.send(zmqm);

			// check if fps is correct
			sensor::timevalue ts_now = sensor::clock::time();
			long long time_spent_ns = (ts_now - ts).nsec();
			long long rest_sleep_ns = min_frame_time_ns - time_spent_ns;
			ts = ts_now;
			if(0 < rest_sleep_ns){
				sensor::timevalue rest_sleep(0,rest_sleep_ns);
				nanosleep(rest_sleep);
			}
		}
	}


	// now a last loop plus synchronized recording
	std::cout << "RECORDING from " << rec_serverport << " to: " << rec_file << std::endl;
	fb_play.rewindFileTo(start_frame*framesize);
	unsigned frames_run = start_frame;
	while(frames_run < end_frame && frames_run < num_frames){
		++frames_run;
		std::cout << "frames_run " << frames_run << std::endl;
		std::cout << "num_frames " << num_frames << std::endl;

		zmq::message_t zmqm_send(framesize);

		// play frame:

		// this should read the data from all cameras consecutively
		fb_play.read((unsigned char*) zmqm_send.data(), framesize);
		socket_play.send(zmqm_send);


		// write frame:

		zmq::message_t zmqm_recv(framesize);
		socket_rec.recv(&zmqm_recv); // blocking

		const double currtime = cm.getTick();
		memcpy((char*) zmqm_recv.data(), (const char*) &currtime, sizeof(double));

		// this should write the data from all cameras consecutively
		fb_rec.write((unsigned char*) zmqm_recv.data(), framesize);

		// check if fps is correct
		sensor::timevalue ts_now = sensor::clock::time();
		long long time_spent_ns = (ts_now - ts).nsec();
		long long rest_sleep_ns = min_frame_time_ns - time_spent_ns;
		ts = ts_now;
		if(0 < rest_sleep_ns){
			sensor::timevalue rest_sleep(0,rest_sleep_ns);
			nanosleep(rest_sleep);
		}
	}

	std::cout << "FINISH synchronized record and play!" << std::endl;

	fb_play.close();
	fb_rec.close();
	return true;
}


int main(int argc, char* argv[])
{
	std::cout << "INFO: Daemon started" << std::endl;
	CMDParser p("serverport");
	p.init(argc,argv);

	// record("/home/moka3156/kinect-daemon-tests/test-record.stream", "127.0.0.1:7000", 4, 5, true);
	// play("/opt/kinect-resources/rgbd-framework/recordings/steppo_standing/steppo_standing.stream");
	// play_segment("/opt/kinect-resources/rgbd-framework/recordings/steppo_standing/steppo_standing.stream", 4, 20, true, 20*5, 20*8);
	// play_record_in_sync("/opt/kinect-resources/rgbd-framework/recordings/steppo_standing/steppo_standing.stream",
	// 	"127.0.0.1:7000", "/mnt/project_avatars/kinect_recordings/kinect-daemon-tests/rec_test.stream", 2, 4, false);

	zmq::context_t ctx(1); // means single threaded
	zmq::socket_t  socket(ctx, ZMQ_SUB); // means a subscriber
	socket.setsockopt(ZMQ_SUBSCRIBE, "", 0);
	uint32_t hwm = 1;
	socket.setsockopt(ZMQ_RCVHWM,&hwm, sizeof(hwm));
	std::string connection_socket = "tcp://" + p.getArgs()[0];
	socket.connect(connection_socket.c_str());

	// replace with message interface
	int cmd_id;
	while(true){
		zmq::message_t zmqm;
		std::vector<std::string> resolvedRequest{};
		pykinecting::Message_Type mtype;
		while(true){
			socket.recv(&zmqm);
			std::cout << "INFO: Received message" << std::endl;
			int64_t more = 0;
			size_t more_size = sizeof(more);
			socket.getsockopt(ZMQ_RCVMORE, &more, &more_size);
			if(more){
				char type[3];
				memcpy(&type, zmqm.data(), 3);
				int test = atoi(type);
				std::cout << type << std::endl;
				std::cout << test << std::endl;
				mtype = static_cast<pykinecting::Message_Type>(test);
			}else{
				resolvedRequest = pykinecting::resolveResponse(mtype, &zmqm);
				for (auto i : resolvedRequest){
					std::cout << i << std::endl;
				}
				break;
			}
		}

		switch(mtype) {
			case pykinecting::PLAY:
				std::cout << "INFO: Stream started" << std::endl;
				play(/* filename = */resolvedRequest.at(1));
				break;

			case pykinecting::PLAY_FRAMES:
				play_segment(
					/* filename = */resolvedRequest.at(1),
					/* num_kinect_cameras = */std::stoi(resolvedRequest.at(6)),
					/* max_fps = */20,
					/* rgb_is_compressed = */false,
					/* first_frame = */std::stoi(resolvedRequest.at(2)),
					/* last_frame = */std::stoi(resolvedRequest.at(3)));
				break;

			case pykinecting::RECORD:
				std::cout << "INFO: Recording started" << std::endl;
				std::cout << resolvedRequest.at(1) << std::endl;
				std::cout << resolvedRequest.at(2) << std::endl;
				std::cout << resolvedRequest.at(3) << std::endl;
				std::cout << resolvedRequest.at(4) << std::endl;
				std::cout << resolvedRequest.at(5) << std::endl;
				record(
					/* record_to_this_filename = */resolvedRequest.at(1),
					/* serverport = */resolvedRequest.at(2),
					/* num_kinect_cameras = */std::stoi(resolvedRequest.at(3)),
					/* num_seconds_to_record = */(float)(std::stoi(resolvedRequest.at(4))),
					/* rgb_is_compressed = */STR_BOOL(resolvedRequest.at(5)));
				break;

			case pykinecting::RECORD_PLAY:
				std::cout << std::stoi(resolvedRequest.at(7)) << std::endl;
				play_record_in_sync(
				/*play_filename*/resolvedRequest.at(1),
				/*rec_serverport*/"141.54.147.33:7000",
				/*rec_file*/resolvedRequest.at(4),
				/*num_loops_before_rec*/std::stoi(resolvedRequest.at(7)),
				/*start_frame*/std::stoi(resolvedRequest.at(2)),
				/*end_frame*/std::stoi(resolvedRequest.at(3)),
				/*max_fps*/15.0f,
				/*num_kinect_cameras*/std::stoi(resolvedRequest.at(5)),
				/*rgb_is_compressed*/true);
				break;

			case pykinecting::RESPONSE:
				break;

		}



		/*socket.recv(&zmqm);
		std::cout << "Received command." << std::endl;
		std::string responseString;
		char responseArray[531-4];
		memcpy(&responseArray, zmqm.data(), 531);
		responseString = responseArray;
		std::cout << responseString << std::endl;
		switch(cmd_id) {
			case 1: {
				play("/opt/kinect-resources/rgbd-framework/recordings/steppo_standing/steppo_standing.stream");
				break;
			}

			case 2: {
				boost::thread* th = new boost::thread(record,
					"/home/moka3156/kinect-daemon-tests/test-record.stream", "127.0.0.1:7000", 4, 5, true);
				thg.add_thread(th);
				break;
			}

			case 3: {
				play_segment("/opt/kinect-resources/rgbd-framework/recordings/steppo_standing/steppo_standing.stream", 4, 20, true, 20*5, 20*8);
				break;
			}

		}*/

		//std::cout << cmd_id << std::endl;
	}



	return 0;
}
