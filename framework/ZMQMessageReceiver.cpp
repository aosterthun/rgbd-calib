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

    /*std::shared_ptr<ThreadEvent> _message_event = std::make_shared<ThreadEvent>("New Message");
    this->receive(_thread_event->get_data(),_event);*/

    std::shared_ptr<std::thread> _thr = std::make_shared<std::thread>(&ZMQMessageReceiver::receive, this , _thread_event->get_data(), _event, this->unique_thread_id);

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

void ZMQMessageReceiver::receive(std::string const &_server, std::shared_ptr<Event> _event, unsigned _unique_thread_id) {
    std::cout << "[START] void ZMQMessageReceiver::receive(std::string const &_server, std::shared_ptr<Event> _event)" << std::endl;
    zmq::context_t _ctx(1);
    zmq::socket_t _skt(_ctx, ZMQ_SUB);
    _skt.setsockopt(ZMQ_SUBSCRIBE,"",0);
    uint32_t hwm = 10000;
    _skt.setsockopt(ZMQ_RCVHWM,&hwm, sizeof(hwm));
    _skt.connect("tcp://"+_server);

    
    while(true){
        zmq::message_t _msg;
        
        _skt.recv(&_msg, 0);
    
        GenericMessage _gen_msg(&_msg);
        PlayCommand _cmd;

        std::stringstream _cmd_stream{_gen_msg.payload()};
        boost::archive::text_iarchive _cmd_archive{_cmd_stream};
        _cmd_archive >> _cmd;

        std::shared_ptr<ThreadEvent> _message_event = std::make_shared<ThreadEvent>("tcp://"+_server);
        _cmd.execute(_message_event);

        std::lock_guard<std::mutex> _lock{*this->thread_mutex};
        this->finished_threads.push_back(_unique_thread_id);

    }
    

    std::cout << "[END] void ZMQMessageReceiver::receive(std::string const &_server, std::shared_ptr<Event> _event)" << std::endl;
}
