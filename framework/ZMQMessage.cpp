//
//  ZMQMessage.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 22.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include "ZMQMessage.hpp"

void ZMQMessage::set_data(std::shared_ptr<AbstractCommand> _command)
{
	this->data = _command;
}

void ZMQMessage::set_type(const ZMQMessageType &_type)
{
    this->type = _type;
}

std::shared_ptr<AbstractCommand> ZMQMessage::get_data(){
	return this->data;
}

ZMQMessageType ZMQMessage::get_type()
{
    return this->type;
}

std::ostream& operator<< (std::ostream& _stream, const ZMQMessage& _zmq_message)
{
    _stream << "[TYPE]" << std::endl;
    _stream << _zmq_message.type << std::endl;
    
    _stream << "[DATA]" << std::endl;
    _stream << _zmq_message.data << std::endl;
    
    return _stream;
}
