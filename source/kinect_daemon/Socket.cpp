//
//  Socket.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 18.09.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include "Socket.hpp"

ZMQSocket::ZMQSocket()
{
	/*
	 The sockets also can not be initialized in the constructor because they are not thread safe.
	 They now get initialized inside the thread.
	 
	 this->ctx = std::make_shared<zmq::context_t>(1);
	 this->sub_skt = std::make_unique<zmq::socket_t>(*this->ctx, ZMQ_SUB);
	 this->pub_skt = std::make_unique<zmq::socket_t>(*this->ctx, ZMQ_PUB);
	*/
	
	this->thread_mutex = std::make_shared<std::mutex>();
}

/*
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
*/

bool ZMQSocket::receive_helper(unsigned _unique_thread_id)
{
	std::cout << "[START] bool ZMQSocket::receive_helper()" <<std::endl;
	
	auto _ctx = std::make_shared<zmq::context_t>(1);
	auto _sub_skt = std::make_unique<zmq::socket_t>(*_ctx, ZMQ_SUB);

	_sub_skt->bind("tcp://*:8000");
	_sub_skt->setsockopt(ZMQ_SUBSCRIBE, "", 0);
	
	while (true){
		std::unique_ptr<std::vector<std::unique_ptr<zmq::message_t>>> _messages = std::make_unique<std::vector<std::unique_ptr<zmq::message_t>>>();
		while (true) {
			std::unique_ptr<zmq::message_t> _msg = std::make_unique<zmq::message_t>();
			
			if(_sub_skt->recv(_msg.get()))
			{
				std::cout << "Received message" << std::endl;
				int64_t more = 0;
				size_t more_size = sizeof(more);
				_sub_skt->getsockopt(ZMQ_RCVMORE, &more, &more_size);
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
//	std::lock_guard<std::mutex> _lock{*this->thread_mutex};
//	this->finished_threads.push_back(_unique_thread_id);
	return true;
}

void ZMQSocket::receive()
{
	std::shared_ptr<std::thread> _thr = std::make_shared<std::thread>(&ZMQSocket::receive_helper, this, unique_thread_id);
	
	this->resolver_threads.insert(std::make_pair(unique_thread_id,_thr));
	++unique_thread_id;
	std::lock_guard<std::mutex> _lock{*this->thread_mutex.get()};
	for(auto id : finished_threads){
		auto thread = this->resolver_threads.find(id);
		thread->second->join();
		this->finished_threads.erase(std::remove(this->finished_threads.begin(), this->finished_threads.end(), id), this->finished_threads.end());
	}
}

void ZMQSocket::send_helper(std::shared_ptr<std::string> _data)
{
	auto _ctx = std::make_shared<zmq::context_t>(1);
	auto _pub_skt = std::make_unique<zmq::socket_t>(*_ctx, ZMQ_PUB);
	
	auto _msg = std::make_shared<zmq::message_t>(_data->length());
	memcpy(_msg->data(), _data->data(), _data->length());
	_pub_skt->send(*_msg.get());
}

void ZMQSocket::send(std::shared_ptr<std::string> _data)
{
//	auto _functor = std::bind(&ZMQSocket::send_helper,this,_data);
//	boost::thread _t(_functor);
//	_t.detach();
}
