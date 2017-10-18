//
//  CommandEvent.hpp
//  ZMQ
//
//  Created by Arne Osterthun on 28.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#ifndef CommandEvent_hpp
#define CommandEvent_hpp

#include <stdio.h>
#include "Event.hpp"
#include "CommandStatus.hpp"

class CommandEvent : public Event
{
private:
	CommandStatus status;
public:
	CommandEvent(CommandStatus const& _status);
	CommandStatus get_status();
	void set_status(CommandStatus const& _status);
};

#endif /* CommandEvent_hpp */
