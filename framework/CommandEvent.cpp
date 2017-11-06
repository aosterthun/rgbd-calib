//
//  CommandEvent.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 28.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include "CommandEvent.hpp"

CommandEvent::CommandEvent(const CommandStatus &_status)
{
	this->status = _status;
}

CommandStatus CommandEvent::get_status()
{
	return this->status;
}

void CommandEvent::set_status(const CommandStatus &_status)
{
	this->status = _status;
}
