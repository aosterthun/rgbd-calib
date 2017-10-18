//
//  ZMQSocket.cpp
//  NetChannel
//
//  Created by Arne Osterthun on 17.09.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include "ZMQSocket.hpp"

ZMQSocket::ZMQSocket()
{
	this->ctx = std::make_shared<zmq::context_t>(1);
	this->sub_skt = std::make_unique<zmq::socket_t>(*this->ctx, ZMQ_SUB);
	this->pub_skt = std::make_unique<zmq::socket_t>(*this->ctx, ZMQ_PUB);
}

ZMQSocket::ZMQSocket(std::shared_ptr<zmq::context_t> _ctx)
{
	this->ctx = std::move(_ctx);
	
	//Subscriber
	this->sub_skt = std::make_unique<zmq::socket_t>(*this->ctx, ZMQ_SUB);
	this->sub_skt->bind("tcp://*:8000");
	this->sub_skt->setsockopt(ZMQ_SUBSCRIBE, "", 0);
	
	//Publisher
	this->pub_skt = std::make_unique<zmq::socket_t>(*this->ctx, ZMQ_PUB);
	this->pub_skt->connect("tcp://127.0.0.1:8000");
	
}

void ZMQSocket::receive_helper()
{
	while (true){
		std::unique_ptr<std::vector<std::unique_ptr<zmq::message_t>>> _messages = std::make_unique<std::vector<std::unique_ptr<zmq::message_t>>>();
		while (true) {
			std::unique_ptr<zmq::message_t> _msg = std::make_unique<zmq::message_t>();
			
			if(this->sub_skt->recv(_msg.get()))
			{
				std::cout << "Received message" << std::endl;
				int64_t more = 0;
				size_t more_size = sizeof(more);
				this->sub_skt->getsockopt(ZMQ_RCVMORE, &more, &more_size);
				if(more)
				{
					_messages->push_back(std::move(_msg));
				}
				else
				{
					_messages->push_back(std::move(_msg));
					break;
				}
			}
		}
	}
}

void ZMQSocket::receive()
{
	auto _functor = std::bind(&ZMQSocket::receive_helper,this);
	std::thread _t(_functor);
	_t.detach();
}

void ZMQSocket::send(std::shared_ptr<std::string> _data)
{
	auto _msg = std::make_shared<zmq::message_t>(_data->length());
	memcpy(_msg->data(), _data->data(), _data->length());
	this->pub_skt->send(*_msg.get());
}
