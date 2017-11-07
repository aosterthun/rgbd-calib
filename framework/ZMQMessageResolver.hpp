//
//  ZMQMessageResolver.hpp
//  ZMQ
//
//  Created by Arne Osterthun on 21.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#ifndef ZMQMessageResolver_hpp
#define ZMQMessageResolver_hpp

#include <stdio.h>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <boost/thread.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include "AbstractObserver.hpp"
#include "ZMQMessageEvent.hpp"
#include "ZMQMessageType.hpp"
#include "PlayCommand.hpp"
#include "AbstractCommand.hpp"
#include "ThreadEvent.hpp"
#include <NotImplementedException.hpp>
#include <KinectDaemonHandshake.hpp>


class ZMQMessageResolver : public AbstractObserver, public AbstractCommand, public std::enable_shared_from_this<ZMQMessageResolver>
{
private:
	std::map<unsigned, std::shared_ptr<std::thread>> resolver_threads;
	std::vector<unsigned> finished_threads;
	unsigned unique_thread_id;
	std::shared_ptr<std::mutex> thread_mutex;
public:
	ZMQMessageResolver();
    void resolve_message(std::shared_ptr<Event> _event, unsigned _unique_thread_id);
	void execute(std::shared_ptr<Event> _event);
    void update(std::shared_ptr<Observable> _observable);
	void update(Observable* _observable);
	void update(std::shared_ptr<Observable> _observable, std::shared_ptr<Event> _event);
	void update(Observable* _observable, std::shared_ptr<Event> _event);
	~ZMQMessageResolver();
};

#endif /* ZMQMessageResolver_hpp */
