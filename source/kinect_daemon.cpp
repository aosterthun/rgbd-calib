#include <zmq.hpp>
#include <iostream>
#include <boost/thread/thread.hpp>

#include "CMDParser.hpp"
#include "FileBuffer.hpp"
#include "ChronoMeter.hpp"
#include "timevalue.hpp"
#include "clock.hpp"
#include "zmq_messages.hpp"


bool play(std::string const filename, unsigned const num_kinect_cameras, float const max_fps, bool const rgb_is_compressed) {
	unsigned min_frame_time_ns = 1000000000/max_fps;

	const unsigned colorsize = rgb_is_compressed ? 691200 : 1280 * 1080 * 3;
	const unsigned depthsize = 512 * 424 * sizeof(float);
	const unsigned framesize = (colorsize + depthsize) * num_kinect_cameras;

	FileBuffer fb(filename.c_str());
	if(!fb.open("r")){
		std::cerr << "error opening " << filename << " exiting..." << std::endl;
		return 1;
	}
	fb.setLooping(true);

	zmq::context_t ctx(1); // means single threaded
	zmq::socket_t  socket(ctx, ZMQ_PUB); // means a publisher
	uint32_t hwm = 1;
	socket.setsockopt(ZMQ_SNDHWM,&hwm, sizeof(hwm));
	std::string endpoint("tcp://127.0.0.1:7000");
	socket.bind(endpoint.c_str());

	sensor::timevalue ts(sensor::clock::time());


	while(true){
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
	return play(filename, 4, 20.0, false);
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

	const unsigned colorsize = rgb_is_compressed ? 691200 : 1280 * 1080 * 3;
	const unsigned depthsize = 512 * 424 * sizeof(float);
	const unsigned framesize = (colorsize + depthsize) * num_kinect_cameras;

	FileBuffer fb(record_to_this_filename.c_str());
	if(!fb.open("w")){
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


	ChronoMeter cm;
	const double starttime = cm.getTick();

	bool running = true;
	while(running){
		zmq::message_t zmqm(framesize);

		socket.recv(&zmqm); // blocking

		const double currtime = cm.getTick();
		const double elapsed = currtime - starttime;

		if(elapsed > num_seconds_to_record) { running = false; }

		memcpy((char*) zmqm.data(), (const char*) &currtime, sizeof(double));

		// this should write the data from all cameras consecutively
		fb.write((unsigned char*) zmqm.data(), framesize);
	}

	fb.close();
	return true;
}


bool play_record_in_sync(const std::string filename, const std::string rec_serverport, const std::string output_file, const int num_loops) {
	/*
	UNFINISHED
	Plays a recording num_loops times and records from rec_serverport on the last loop.
	*/

	unsigned length_recording = 0;

	struct stat stat_buf;
	int filesize = stat(filename.c_str(), &stat_buf);
	filesize == 0 ? stat_buf.st_size : -1;


	for (int i = 0; i < num_loops-1; ++i) {
		play(filename);
		std::cout << "Looping play.. " << i << std::endl;
	}

	std::cout << "RECORDING from " << rec_serverport << " to: " << output_file << std::endl;
	boost::thread th(record,
		"/home/moka3156/kinect-daemon-tests/test-record.stream", "127.0.0.1:7000", 4, 5, true);
	play(filename);

	return true;
}


int main(int argc, char* argv[])
{
	CMDParser p("serverport");
	p.init(argc,argv);

	// record("/home/moka3156/kinect-daemon-tests/test-record.stream", "127.0.0.1:7000", 4, 5, true);
	// play("/opt/kinect-resources/rgbd-framework/recordings/steppo_standing/steppo_standing.stream");
	// play_segment("/opt/kinect-resources/rgbd-framework/recordings/steppo_standing/steppo_standing.stream", 4, 20, true, 20*5, 20*8);

	zmq::context_t ctx(1); // means single threaded
	zmq::socket_t  socket(ctx, ZMQ_SUB); // means a subscriber
	socket.setsockopt(ZMQ_SUBSCRIBE, "", 0);
	uint32_t hwm = 1;
	socket.setsockopt(ZMQ_RCVHWM,&hwm, sizeof(hwm));
	std::string connection_socket = "tcp://" + p.getArgs()[0];
	socket.connect(connection_socket.c_str());

	boost::thread_group thg;

	// replace with message interface
	int cmd_id;
	while(true){
		zmq::message_t zmqm(531);
		socket.recv(&zmqm);
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
		}

		//std::cout << cmd_id << std::endl;
	}



	return 0;
}
