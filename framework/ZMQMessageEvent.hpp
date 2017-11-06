//
//  ZMQMessageEvent.hpp
//  ZMQ
//
//  Created by Arne Osterthun on 23.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#ifndef ZMQMessageEvent_hpp
#define ZMQMessageEvent_hpp

#include <stdio.h>
#include <zmq.hpp>
#include <Event.hpp>
#include <memory>

class ZMQMessageEvent : public Event
{
private:
	std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>> messages;
	std::string event_message;
public:
	ZMQMessageEvent(std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>> _data);
	void set_event_message(std::string const& _event_message);
	void set_data(std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>> _data);
	void add_data(std::shared_ptr<zmq::message_t> _message);
	std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>> get_data();
	std::string get_event_message();
};

#endif /* ZMQMessageEvent_hpp */
