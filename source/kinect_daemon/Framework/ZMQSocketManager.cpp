//
//  ZMQSocketManager.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 25.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include "ZMQSocketManager.hpp"

ZMQSocketManager::ZMQSocketManager(){}

std::shared_ptr<ZMQSocketManager> ZMQSocketManager::get_instance()
{
	if(!ZMQSocketManager::instance){
		ZMQSocketManager::instance = std::make_shared<ZMQSocketManager>();
	}
	return ZMQSocketManager::instance;
}

std::shared_ptr<zmq::socket_t> ZMQSocketManager::get_socket()
{
	//Check if any ports are available in port range
	//If a port is available change its state to false and open socket
	//return socket
	return nullptr;
}
