//
//  ZMQMessagingChannel.hpp
//  ZMQ
//
//  Created by Arne Osterthun on 28.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#ifndef ZMQMessagingChannel_hpp
#define ZMQMessagingChannel_hpp

#include <stdio.h>
#include <memory>
#include "Event.hpp"
#include "ZMQMessageReceiver.hpp"
#include "AbstractObserver.hpp"

class ZMQMessageReceiver;

class ZMQMessagingChannel : public AbstractObserver, public std::enable_shared_from_this<ZMQMessagingChannel>, public Observable

{
private:
	std::shared_ptr<ZMQMessageReceiver> receiver;
public:
	ZMQMessagingChannel();
	void send(std::shared_ptr<Event> _event);
	void update(std::shared_ptr<Observable> _observable);
	void update(std::shared_ptr<Observable> _observable, std::shared_ptr<Event> _event);

};

#endif /* ZMQMessagingChannel_hpp */
