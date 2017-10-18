//
//  ZMQMessagingChannel.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 28.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include "ZMQMessagingChannel.hpp"

ZMQMessagingChannel::ZMQMessagingChannel()
{
	this->receiver->attach(shared_from_this());
}

void ZMQMessagingChannel::update(std::shared_ptr<Observable> _observable)
{
	std::cout << "ZMQMessagingChannel::update(std::shared_ptr<Observable> observable)" << std::endl;
}

void ZMQMessagingChannel::update(std::shared_ptr<Observable> _observable, std::shared_ptr<Event> _event)
{
	std::cout << "ZMQMessagingChannel::update(std::shared_ptr<Observable> _observable, std::shared_ptr<Event> _event)" << std::endl;
	ZMQMessageEvent* _zmq_event(static_cast<ZMQMessageEvent*>(_event.get()));
}
