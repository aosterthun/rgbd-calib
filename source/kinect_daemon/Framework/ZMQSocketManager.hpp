//
//  ZMQSocketManager.hpp
//  ZMQ
//
//  Created by Arne Osterthun on 25.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#ifndef ZMQSocketManager_hpp
#define ZMQSocketManager_hpp

#include <stdio.h>
#include <memory>
#include <map>
#include <zmq.hpp>

class ZMQSocketManager
{
private:
	static std::shared_ptr<ZMQSocketManager> instance;
	ZMQSocketManager();
	std::shared_ptr<std::map<bool,std::string>> available_ports;
	std::shared_ptr<std::map<int,int>> port_range;
public:
	static std::shared_ptr<ZMQSocketManager> get_instance();
	std::shared_ptr<zmq::socket_t> get_socket();
	
};

#endif /* ZMQSocketManager_hpp */
