#include <zmq.hpp>
#include <iostream>
#include <CMDParser.hpp>
#include <FileBuffer.hpp>
#include <ChronoMeter.hpp>

#include <boost/thread/thread.hpp>


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
  	std::string endpoint("tcp://127.0.0.1:7001");
  	socket.bind(endpoint.c_str());

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
	  }

	return true;
}


bool play(std::string const filename) {
	return play(filename, 4, 20.0, false);
}

bool record(std::string const record_to_this_filename, std::string const serverport, unsigned const num_kinect_cameras,
	float const num_seconds_to_record, bool const rgb_is_compressed) {
	/*
	*	TODO: run this in a separate thread !
	*/

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


int main(int argc, char* argv[])
{
	CMDParser p("serverport");
	p.init(argc,argv);

	record("/home/moka3156/kinect-daemon-tests/test-record.stream", "127.0.0.1:7000", 1, 1, true);

	zmq::context_t ctx(1); // means single threaded
	zmq::socket_t  socket(ctx, ZMQ_SUB); // means a 	subscriber
	socket.setsockopt(ZMQ_SUBSCRIBE, "", 0);
	uint32_t hwm = 1;
	socket.setsockopt(ZMQ_RCVHWM,&hwm, sizeof(hwm));
	std::string connection_socket = "tcp://" + p.getArgs()[0];
	socket.connect(connection_socket.c_str());
	float cmd_id;
  	while(true){
		zmq::message_t zmqm(sizeof(float));
		socket.recv(&zmqm);
    	memcpy( &cmd_id, (const unsigned char*) zmqm.data(), sizeof(float));
    	if (cmd_id == 5.0f) {
    		play("/opt/socialvr/recordings/Jojo/idiot.stream");
    	}
    	std::cout << cmd_id << std::endl;
  	}

	return 0;
}
