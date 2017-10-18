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

class ZMQMessageReceiver : public Observable
{
private:
    std::string server;
    
public:
    void start_listening();
    void set_server(std::string const& server);
};

#endif /* ZMQMessageReceiver_hpp */
