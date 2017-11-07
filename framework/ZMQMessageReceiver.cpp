//
//  ZMQMessageReceiver.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 21.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include "ZMQMessageReceiver.hpp"

ZMQMessageReceiver::ZMQMessageReceiver() {
    this->unique_thread_id = 0;
    this->thread_mutex = std::make_shared<std::mutex>();
}

void ZMQMessageReceiver::update(Observable *_observable) {
    throw NotImplemented();
}

void ZMQMessageReceiver::update(Observable *_observable, std::shared_ptr<Event> _event) {
    throw NotImplemented();
}

void ZMQMessageReceiver::update(std::shared_ptr<Observable> _observable, std::shared_ptr<Event> _event) {
    std::cout << "[START] void ZMQMessageReceiver::update(std::shared_ptr<Observable> _observable, std::shared_ptr<Event> _event)" << std::endl;

    std::shared_ptr<ThreadEvent> _thread_event = std::static_pointer_cast<ThreadEvent>(_event);
    std::cout << _thread_event->get_data() << std::endl;

    std::shared_ptr<ThreadEvent> _message_event = std::make_shared<ThreadEvent>("New Message");
    this->receive(_thread_event->get_data(),_event);

    std::shared_ptr<std::thread> _thr = std::make_shared<std::thread>(&ZMQMessageReceiver::receive, this , _thread_event->get_data(), _event);

    this->running_threads.insert(std::make_pair(unique_thread_id,_thr));
    ++unique_thread_id;
    std::lock_guard<std::mutex> _lock{*this->thread_mutex.get()};
    for(auto id : finished_threads){
        auto thread = this->running_threads.find(id);
        thread->second->join();
        this->finished_threads.erase(std::remove(this->finished_threads.begin(), this->finished_threads.end(), id), this->finished_threads.end());
    }
    std::cout << "[END] void ZMQMessageReceiver::update(std::shared_ptr<Observable> _observable, std::shared_ptr<Event> _event)" << std::endl;
}

void ZMQMessageReceiver::update(std::shared_ptr<Observable> _observable) {
    throw NotImplemented();
}

void ZMQMessageReceiver::receive(std::string const &_server, std::shared_ptr<Event> _event) {
    std::cout << "[START] void ZMQMessageReceiver::receive(std::string const &_server, std::shared_ptr<Event> _event)" << std::endl;
    zmq::context_t _ctx(1);
    zmq::socket_t _skt(_ctx, ZMQ_SUB);
    _skt.setsockopt(ZMQ_SUBSCRIBE,"",0);
    _skt.connect("tcp://"+_server+":8006");
    sleep(1);
    while (true) {
        std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>> _messages = std::make_shared<std::vector<std::shared_ptr<zmq::message_t>>>();
        while (true) {
            std::shared_ptr<zmq::message_t> _msg = std::make_shared<zmq::message_t>();

            if (_skt.recv(_msg.get())) {
                std::cout << "Received message" << std::endl;
                int64_t more = 0;
                size_t more_size = sizeof(more);
                _skt.getsockopt(ZMQ_RCVMORE, &more, &more_size);
                if (more) {
                    _messages->push_back(_msg);
                } else {
                    _messages->push_back(_msg);
                    break;
                }
            }
        }

        std::shared_ptr<ZMQMessageEvent> _message_event = std::make_shared<ZMQMessageEvent>(_messages);
        _message_event->set_event_message("test");
        this->notify(_message_event);
    }
    std::cout << "[END] void ZMQMessageReceiver::receive(std::string const &_server, std::shared_ptr<Event> _event)" << std::endl;
}
/*
void ZMQMessageReceiver::start_listening()
{
    zmq::context_t _ctx(1);
    zmq::socket_t _skt(_ctx, ZMQ_SUB);
    _skt.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    _skt.bind("tcp://" + this->server);
	
	while (true){
		std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>> _messages = std::make_shared<std::vector<std::shared_ptr<zmq::message_t>>>();
		while (true) {
			std::shared_ptr<zmq::message_t> _msg = std::make_shared<zmq::message_t>();
			
			if(_skt.recv(_msg.get()))
			{
				std::cout << "Received message" << std::endl;
				int64_t more = 0;
				size_t more_size = sizeof(more);
				_skt.getsockopt(ZMQ_RCVMORE, &more, &more_size);
				if(more)
				{
					_messages->push_back(_msg);
				}
				else
				{
					_messages->push_back(_msg);
					break;
				}
			}
		}
		std::shared_ptr<ZMQMessageEvent> _event = std::make_shared<ZMQMessageEvent>(_messages);
		_event->set_event_message("Hallo Welt");
		
		this->notify(_event);
	}
}

void ZMQMessageReceiver::set_server(const std::string &server)
{
    this->server = server;
}
*/