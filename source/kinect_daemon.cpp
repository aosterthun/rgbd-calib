#include <zmq.hpp>
#include <iostream>
#include <CMDParser.hpp>
int main(int argc, char* argv[])
{
	CMDParser p("serverport");
	p.init(argc,argv);

	zmq::context_t ctx(1); // means single threaded
	zmq::socket_t  socket(ctx, ZMQ_SUB); // means a subscriber
	socket.setsockopt(ZMQ_SUBSCRIBE, "", 0);
	uint32_t hwm = 1;
	socket.setsockopt(ZMQ_RCVHWM,&hwm, sizeof(hwm));
	std::string connection_socket = "tcp://" + p.getArgs()[0];
	socket.connect(connection_socket.c_str());
	float received_data;
  	while(true){
		zmq::message_t zmqm(sizeof(float));
		socket.recv(&zmqm);
    	memcpy( &received_data, (const unsigned char*) zmqm.data(), sizeof(float));
    	std::cout << received_data << std::endl;
  	}
  	
	return 0;
}