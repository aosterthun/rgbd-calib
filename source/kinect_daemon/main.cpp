//
//  main.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 21.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include <iostream>
#include <memory>
#include <boost/thread.hpp>
#include <zmq.hpp>

void zmq_thread()
{
//    std::shared_ptr<ZMQMessageReceiver> _receiver = std::make_shared<ZMQMessageReceiver>();
//    std::shared_ptr<ZMQMessageResolver> _resolver = std::make_shared<ZMQMessageResolver>();
//    
//    _receiver->attach(_resolver);
//    
//    _receiver->set_server("*:8000");
//    _receiver->start_listening();

//	auto _main_skt = std::make_unique<ZMQSocket>();
//	
//	_main_skt->receive();
//
//	_main_skt->send(std::make_shared<std::string>("Hello World"));
	
}


void command_thread()
{
	
}


int main(int argc, const char * argv[]) {
    
//    boost::thread _zmq(&zmq_thread);
//    boost::thread _commands(&command_thread);
//    
//    _zmq.join();
//    _commands.join();
	
	zmq::context_t ctx(1);
	//zmq::socket_t pub_skt(ctx, ZMQ_PUB);
	zmq::socket_t sub_skt(ctx, ZMQ_SUB);
	sub_skt.setsockopt(ZMQ_SUBSCRIBE, "", 0);
	//pub_skt.connect("tcp://127.0.0.1:8002");
	
	
	sub_skt.bind("tcp://*:8001");
	sleep(1);
	std::cout << "before recv" << std::endl;
	while (true)
	{
		zmq::message_t msg(sizeof(int));
		sub_skt.recv(&msg);
		int val;
		memcpy((char*) &val, (const char* ) msg.data(), sizeof(int));
		std::cout << "recv: " << val << std::endl;
	}
//	auto _ctx = std::make_shared<zmq::context_t>(1);
//	auto _pub_skt = std::make_shared<zmq::socket_t>(*_ctx.get(), ZMQ_PUB);
//	auto _sub_skt = std::make_shared<zmq::socket_t>(*_ctx.get(), ZMQ_SUB);
//	
//	_pub_skt->connect("tcp://127.0.0.1:8002");
//	_sub_skt->bind("tcp://127.0.0.1:8001");
	
//	while (true) {
//		std::shared_ptr<zmq::message_t> _msg = std::make_shared<zmq::message_t>();
//		std::cout << "Start" << std::endl;
//		if(sub_skt.recv(_msg.get()))
//		{
//			std::cout << "Received message" << std::endl;
//			std::shared_ptr<KinectDaemonHandshake> _recv_handshake = std::make_shared<KinectDaemonHandshake>();
//			auto _handshake_string = std::string(static_cast<char*>(_msg->data()), _msg->size());
//			std::stringstream _handshake_stream(_handshake_string);
//			boost::archive::text_iarchive _handshake_archive(_handshake_stream);
//			_handshake_archive >> *_recv_handshake.get();
//			std::cout << _recv_handshake->client_ip() << std::endl;
//			
//			
////			std::shared_ptr<KinectDaemonHandshake> _repl_handshake = std::make_shared<KinectDaemonHandshake>();
////			_repl_handshake->client_ip("127.0.0.123");
////			
////			std::stringstream _repl_handshake_stream;
////			boost::archive::text_oarchive _repl_handshake_archive(_repl_handshake_stream);
////			_repl_handshake_archive << _repl_handshake.get();
////			std::string _repl_handshake_msg_str = _repl_handshake_stream.str();
////			
////			std::shared_ptr<zmq::message_t> _send_repl_handshake = std::make_shared<zmq::message_t>(_repl_handshake_msg_str.length());
////			memcpy(_send_repl_handshake->data(), _repl_handshake_msg_str.data(), _repl_handshake_msg_str.length());
////			
////			pub_skt.send(*_send_repl_handshake.get());
//		}
//	}
}
