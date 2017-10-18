//
//  ThreadEvent.hpp
//  ZMQ
//
//  Created by Arne Osterthun on 30.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#ifndef ThreadEvent_hpp
#define ThreadEvent_hpp

#include <stdio.h>
#include <memory>
#include "../Framework/Event.hpp"
#include "../Framework/EventData.hpp"

template<class T>
class ThreadEvent : public Event{
private:
	unsigned id;
	std::shared_ptr<EventData<T>> event_data;
public:
	ThreadEvent(unsigned _id)
	{
		this->id = _id;
		this->event_data = std::make_shared<EventData<T>>();
	}
	unsigned get_id()
	{
		return this->id;
	}
	std::shared_ptr<EventData<T>> get_event_data()
	{
		return this->event_data;
	}
};

#endif /* ThreadEvent_hpp */
