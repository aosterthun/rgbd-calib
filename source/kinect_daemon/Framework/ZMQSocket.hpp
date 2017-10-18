//
//  ZMQSocket.hpp
//  NetChannel
//
//  Created by Arne Osterthun on 17.09.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#ifndef ZMQSocket_hpp
#define ZMQSocket_hpp

#include <stdio.h>
#include <zmq.hpp>
#include <thread>
#include <chrono>
#include <iostream>

class ZMQSocket
{
private:
	std::shared_ptr<zmq::context_t> ctx;
	std::shared_ptr<zmq::socket_t> pub_skt;
	std::shared_ptr<zmq::socket_t> sub_skt;
	void receive_helper();
public:
	ZMQSocket();
	ZMQSocket(std::shared_ptr<zmq::context_t> _ctx);
	void send(std::shared_ptr<std::string> _data);
	void receive();
};

#endif /* ZMQSocket_hpp */
