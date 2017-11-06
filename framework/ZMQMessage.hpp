//
//  ZMQMessage.hpp
//  ZMQ
//
//  Created by Arne Osterthun on 22.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#ifndef ZMQMessage_hpp
#define ZMQMessage_hpp

#include <stdio.h>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <sstream>
#include <memory>
#include "ZMQMessageType.hpp"
#include "AbstractCommand.hpp"

class ZMQMessage
{
private:
    ZMQMessageType type;
	std::shared_ptr<AbstractCommand> data;
    
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version){
        ar & type;
        ar & data;
    }
public:
    ZMQMessageType get_type();
    std::shared_ptr<AbstractCommand> get_data();
    void set_type(ZMQMessageType const& _type);
    void set_data(std::shared_ptr<AbstractCommand> _command);
    friend std::ostream& operator<< (std::ostream& _stream, const ZMQMessage& _zmq_message);
};

#endif /* ZMQMessage_hpp */
