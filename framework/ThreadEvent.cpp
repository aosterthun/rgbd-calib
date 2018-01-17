//
//  ThreadEvent.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 30.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include "ThreadEvent.hpp"

ThreadEvent::ThreadEvent(std::string const &_data) {
    this->data = _data;
}

std::string ThreadEvent::get_data() {
    return this->data;
}

void ThreadEvent::set_cmd(std::shared_ptr<AbstractCommand> _cmd){
	this->cmd = _cmd;
}

std::shared_ptr<AbstractCommand> ThreadEvent::get_cmd(){
	return this->cmd;
}