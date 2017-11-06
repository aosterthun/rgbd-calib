//
//  ZMQMessageReceiver.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 21.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include <mutex>
#include "ZMQMessageReceiver.hpp"

void receive(std::string const& _server){
    zmq::context_t _ctx(1);
    zmq::socket_t _skt(_ctx, ZMQ_SUB);
    _skt.setsockopt(ZMQ_SUBSCRIBE,"",0);
    _skt.bind("tcp://" + _server);

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


        this->notify();
    }
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