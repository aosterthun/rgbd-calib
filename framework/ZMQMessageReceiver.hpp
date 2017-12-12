//
//  ZMQMessageReceiver.hpp
//  ZMQ
//
//  Created by Arne Osterthun on 21.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#ifndef ZMQMessageReceiver_hpp
#define ZMQMessageReceiver_hpp

#include <stdio.h>
#include <zmq.hpp>
#include <vector>
#include <sstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include "ZMQMessageType.hpp"
#include "Observable.hpp"
#include "PlayCommand.hpp"
#include "ZMQMessageEvent.hpp"
#include <AbstractObserver.hpp>
#include <NotImplementedException.hpp>
#include <ThreadEvent.hpp>
#include <mutex>
#include <GenericMessage.hpp>

class ZMQMessageReceiver : public Observable , public AbstractObserver
{
private:
    std::string server;
    std::map<unsigned, std::shared_ptr<std::thread>> running_threads;
    std::vector<unsigned> finished_threads;
    unsigned unique_thread_id;
    std::shared_ptr<std::mutex> thread_mutex;
    
public:
    ZMQMessageReceiver();
    void receive(std::string const &_server, std::shared_ptr<Event> _event, unsigned _unique_thread_id);
    virtual void update(std::shared_ptr<Observable> _observable);
    virtual void update(Observable* _observable);
    virtual void update(std::shared_ptr<Observable> _observable, std::shared_ptr<Event> _event);
    virtual void update(Observable* _observable, std::shared_ptr<Event> _event);
};

#endif /* ZMQMessageReceiver_hpp */
