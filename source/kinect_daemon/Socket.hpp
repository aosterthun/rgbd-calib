//
//  Socket.hpp
//  ZMQ
//
//  Created by Arne Osterthun on 18.09.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#ifndef Socket_hpp
#define Socket_hpp

#include <stdio.h>
#include <zmq.hpp>
#include <chrono>
#include <mutex>
#include <thread>
#include <memory>
#include <map>
#include <iostream>


class ZMQSocket
{
private:
	std::shared_ptr<zmq::context_t> ctx;
	std::unique_ptr<zmq::socket_t> pub_skt;
	std::unique_ptr<zmq::socket_t> sub_skt;
	std::map<unsigned, std::shared_ptr<std::thread>> resolver_threads;
	std::vector<unsigned> finished_threads;
	unsigned unique_thread_id;
	std::shared_ptr<std::mutex> thread_mutex;
	bool receive_helper(unsigned _unique_thread_id);
	void send_helper(std::shared_ptr<std::string> _data);
public:
	ZMQSocket();
	/*
	 ZMQ Socket is not threadsafe so every ZMQSocket instance has to create it's own ZMQ Sockets
	
	 ZMQSocket(std::shared_ptr<zmq::context_t> _ctx);
	*/
	void send(std::shared_ptr<std::string> _data);
	void receive();
};
#endif /* Socket_hpp */
