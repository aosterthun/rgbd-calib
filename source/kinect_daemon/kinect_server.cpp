//
//  main.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 21.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//
#include <iostream>
#include <memory>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <zmq.hpp>
#include "Framework/KinectDaemonHandshake.hpp"

int main(int argc, const char * argv[]) {

    KinectDaemonHandshake _hs{};
    _hs.client_ip("127.0.0.1:8001");

    std::stringstream _hs_ss;
    boost::archive::text_oarchive _hs_arc{_hs_ss};
    _hs_arc << _hs;

    KinectDaemonHandshake _ohs{};
    boost::archive::text_iarchive _hs_oarc{_hs_ss};
    _hs_oarc >> _ohs;

    std::cout << _ohs.client_ip() << std::endl;







	auto _ctx = std::make_shared<zmq::context_t>(1);
	auto _pub_skt = std::make_shared<zmq::socket_t>(*_ctx.get(), ZMQ_PUB);
	auto _sub_skt = std::make_shared<zmq::socket_t>(*_ctx.get(), ZMQ_SUB);
	
	_pub_skt->connect("tcp://127.0.0.1:8002");
	_sub_skt->bind("tcp://127.0.0.1:8001");

    std::shared_ptr<zmq::message_t> _msg = std::make_shared<zmq::message_t>();
    std::cout << "Start" << std::endl;
	while (_sub_skt->recv(_msg.get())) {
        std::cout << "Received message" << std::endl;
        std::shared_ptr<KinectDaemonHandshake> _recv_handshake = std::make_shared<KinectDaemonHandshake>();
        auto _handshake_string = std::string(static_cast<char *>(_msg->data()), _msg->size());
        std::stringstream _handshake_stream(_handshake_string);
        boost::archive::text_iarchive _handshake_archive(_handshake_stream);
        _handshake_archive >> *_recv_handshake.get();
        //std::cout << _recv_handshake->client_ip() << std::endl;


//			std::shared_ptr<KinectDaemonHandshake> _repl_handshake = std::make_shared<KinectDaemonHandshake>();
//			_repl_handshake->client_ip("127.0.0.123");
//			
//			std::stringstream _repl_handshake_stream;
//			boost::archive::text_oarchive _repl_handshake_archive(_repl_handshake_stream);
//			_repl_handshake_archive << _repl_handshake.get();
//			std::string _repl_handshake_msg_str = _repl_handshake_stream.str();
//			
//			std::shared_ptr<zmq::message_t> _send_repl_handshake = std::make_shared<zmq::message_t>(_repl_handshake_msg_str.length());
//			memcpy(_send_repl_handshake->data(), _repl_handshake_msg_str.data(), _repl_handshake_msg_str.length());
//			
//			pub_skt.send(*_send_repl_handshake.get());

	}
}
