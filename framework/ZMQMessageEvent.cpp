//
//  ZMQMessageEvent.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 23.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include "ZMQMessageEvent.hpp"

ZMQMessageEvent::ZMQMessageEvent(std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>> _data)
{
	this->messages = _data;
}

void ZMQMessageEvent::set_data(std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>> _data)
{
	this->messages = _data;
}

void ZMQMessageEvent::add_data(std::shared_ptr<zmq::message_t> _message)
{
	this->messages->push_back(_message);
}

void ZMQMessageEvent::set_event_message(const std::string &_event_message)
{
	this->event_message = _event_message;
}

std::string ZMQMessageEvent::get_event_message()
{
	return this->event_message;
}

std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>> ZMQMessageEvent::get_data()
{
	return this->messages;
}
