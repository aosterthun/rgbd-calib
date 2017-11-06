//
//  ZMQMessageResolver.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 21.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include "ZMQMessageResolver.hpp"

ZMQMessageResolver::ZMQMessageResolver()
{
	this->thread_mutex = std::make_shared<std::mutex>();
}

ZMQMessageResolver::~ZMQMessageResolver()
{
	
}

void ZMQMessageResolver::update(Observable* _observable)
{
	std::cout << "ZMQMessageResolver::update(Observable* _observable)" << std::endl;
}

void ZMQMessageResolver::update(std::shared_ptr<Observable> _observable)
{
    std::cout << "ZMQMessageResolver::update(std::shared_ptr<Observable> observable)" << std::endl;
}

void ZMQMessageResolver::update(Observable* _observable, std::shared_ptr<Event> _event)
{
	std::cout << "ZMQMessageResolver::update(Observable* _observable, std::shared_ptr<Event> _event)" << std::endl;
}

void ZMQMessageResolver::update(std::shared_ptr<Observable> _observable, std::shared_ptr<Event> _event)
{
	std::cout << "ZMQMessageResolver::update(std::shared_ptr<Observable> _observable, std::shared_ptr<Event> _event)" << std::endl;
//	std::shared_ptr<ThreadEvent<std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>>>> _thread_event = std::make_shared<ThreadEvent<std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>>>>(1);
	//std::shared_ptr<ZMQMessageEvent> _zmq_event(static_cast<ZMQMessageEvent*>(_event.get()));
//	_thread_event->get_event_data()->set_data(_zmq_event->get_data());
//	//ThreadManager::instance()->executeTask(std::bind(&ZMQMessageResolver::resolve_message, this, _event));
//	ThreadManager::instance()->executeTask(std::bind(&ZMQMessageResolver::execute, this, _thread_event));
//	
//	
//
	for(auto id : finished_threads)
	{
		std::cout << "test" << std::endl;
	}
	std::shared_ptr<boost::thread> _thr = std::make_shared<boost::thread>(&ZMQMessageResolver::resolve_message, this , _event, unique_thread_id);
	
	this->resolver_threads.insert(std::make_pair(unique_thread_id,_thr));
	++unique_thread_id;
	std::lock_guard<std::mutex> _lock{*this->thread_mutex.get()};
	for(auto id : finished_threads){
		auto thread = this->resolver_threads.find(id);
		thread->second->join();
		this->finished_threads.erase(std::remove(this->finished_threads.begin(), this->finished_threads.end(), id), this->finished_threads.end());
	}
	
	
}

void ZMQMessageResolver::execute(std::shared_ptr<Event> _event)
{
	std::shared_ptr<ThreadEvent<std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>>>> _thread_event(static_cast<ThreadEvent<std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>>>*>(_event.get()));
	std::cout << "ZMQMessageResolver::execute(std::shared_ptr<Event> _event)" << std::endl;
	std::cout << "ZMQMessageResolver::thread_id: " << _thread_event->get_id() << std::endl;
}

void ZMQMessageResolver::resolve_message(std::shared_ptr<Event> _event, unsigned _unique_thread_id)
{
	std::cout << "ZMQMessageResolver::resolve_message(std::shared_ptr<Event> _event, unsigned _unique_thread_id)" << std::endl;
	
	std::shared_ptr<ZMQMessageEvent> _zmq_event = std::static_pointer_cast<ZMQMessageEvent>(_event);
	//(static_cast<ZMQMessageEvent*>(_event.get()));
	ZMQMessageType _type;
	PlayCommand _cmd = PlayCommand();
	
	auto _messages = _zmq_event->get_data();
	auto _type_string = std::string(static_cast<char*>(_messages->front()->data()), _messages->front()->size());
	auto _cmd_string = std::string(static_cast<char*>(_messages->back()->data()), _messages->back()->size());
	
	std::stringstream _type_stream{_type_string};
	std::stringstream _cmd_stream{_cmd_string};
	
	boost::archive::text_iarchive _type_archive{_type_stream};
	boost::archive::text_iarchive _cmd_archive{_cmd_stream};

	_type_archive >> _type;
	_cmd_archive >> _cmd;
	
	_cmd.execute(std::make_shared<Event>());

	std::lock_guard<std::mutex> _lock{*this->thread_mutex};
	this->finished_threads.push_back(_unique_thread_id);
}


