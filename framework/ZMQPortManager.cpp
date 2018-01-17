#include "ZMQPortManager.hpp"

ZMQPortManager& ZMQPortManager::get_instance(){
	static ZMQPortManager instance{8000};
    return instance;
}

ZMQPortManager::ZMQPortManager(unsigned _start_port){
	this->next_free_port = _start_port;
}

unsigned ZMQPortManager::get_next_free_port(){
	unsigned _cur_free_port = this->next_free_port;
	this->next_free_port += this->port_offset;
	return _cur_free_port;
}