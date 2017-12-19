//
//  PlayCommand.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 21.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include "PlayCommand.hpp"

PlayCommand::PlayCommand()
{
	this->zmq_context = std::make_shared<zmq::context_t>(1);
	this->zmq_pub_socket = std::make_shared<zmq::socket_t>(*this->zmq_context,ZMQ_PUB);
	this->zmq_sub_socket = std::make_shared<zmq::socket_t>(*this->zmq_context,ZMQ_SUB);
	this->zmq_sub_socket->setsockopt(ZMQ_SUBSCRIBE, "", 0);

	cmd_filename = "";
	cmd_server_address = "";
    cmd_backchannel_com_port = "";
	cmd_num_kinect_cameras = 0;
	cmd_max_fps = 0;
	cmd_rgb_is_compressed = false;
	cmd_loop = false;
	cmd_startframe = 0;
	cmd_endframe = 0;
}

void PlayCommand::listen_on_backchannel()
{
 	std::cout << this->get_backchannel_port(true)[0]+":"+std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)) << std::endl;
	this->zmq_sub_socket->connect(this->get_backchannel_port(true)[0]+":"+std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)));
	while (true) {
		std::cout << "connected" << std::endl;
		std::shared_ptr<zmq::message_t> _msg = std::make_shared<zmq::message_t>();
		
		if(this->zmq_sub_socket->recv(_msg.get()))
		{
			std::cout << "PlayCommand::listen_on_backchannel()" << std::endl;
			CommandStatus _status;
			auto _cmd_string = std::string(static_cast<char*>(_msg->data()), _msg->size());
			
			std::stringstream _cmd_stream{_cmd_string};
			
			boost::archive::text_iarchive _cmd_archive{_cmd_stream};
			
			_cmd_archive >> _status;

			switch (_status) {
				case PAUSE:
					this->is_running = false;
					std::cout << "[PAUSE]" << std::endl;
					this->send_on_backchannel(CommandStatus::PAUSED);
					break;
					
				default:
					std::cout << "[UNVALID COMMAND STATUS]" << std::endl;
					break;
			}
		}
	}
}

void PlayCommand::send_on_backchannel(const int _status)
{
	std::cout << "PlayCommand::send_on_backchannel(const int _status)" << std::endl;
	this->zmq_pub_socket->bind("tcp://0.0.0.0:"+std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)));
	sleep(1);
	CommandStatus _cmd_status = static_cast<CommandStatus>(_status);
	std::stringstream _cmd_status_stream;
	boost::archive::text_oarchive _cmd_status_archive(_cmd_status_stream);
	_cmd_status_archive << _cmd_status;
	std::string _cmd_status_msg_str = _cmd_status_stream.str();
	zmq::message_t _cmd_status_msg(_cmd_status_msg_str.length());
	memcpy(_cmd_status_msg.data(), _cmd_status_msg_str.data(), _cmd_status_msg_str.length());
	this->zmq_pub_socket->send(_cmd_status_msg);

	this->zmq_pub_socket->unbind("tcp://0.0.0.0:" + std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)));
	
}

std::vector<std::string> PlayCommand::get_backchannel_port(bool _seperated) {
    std::vector<std::string> _port;
    if(_seperated){
        size_t _first = this->cmd_backchannel_com_port.find(":");
        _port.push_back(this->cmd_backchannel_com_port.substr(0,this->cmd_backchannel_com_port.find(":",_first+1)));     
        _port.push_back(this->cmd_backchannel_com_port.substr(this->cmd_backchannel_com_port.find(":",_first+1)+1,this->cmd_backchannel_com_port.length()));
    }else{
        _port.push_back(this->cmd_backchannel_com_port);
    }
    return _port;
}

void PlayCommand::set_backchannel_com_port(std::string const &_com_port) {
    this->cmd_backchannel_com_port = _com_port;
}

void PlayCommand::execute(std::shared_ptr<Event> _event)
{
	std::cout << "[START] void PlayCommand::execute(std::shared_ptr<Event> _event)" << std::endl;
	this->is_running = true;
    std::shared_ptr<ThreadEvent> _thread_event = std::static_pointer_cast<ThreadEvent>(_event);
    this->set_backchannel_com_port(_thread_event->get_data());
	std::shared_ptr<std::thread> _backchannel_listen_thread = std::make_shared<std::thread>(&PlayCommand::listen_on_backchannel,this);
	this->send_on_backchannel(CommandStatus::STARTED);
    std::cout << "PlayCommand::execute()" << std::endl;
    int i = 0;
	while(this->is_running){
		if (i == 300){
			i = 0;
			std::cout << "Restart stream" << std::endl;
		}
		sleep(1);
		std::cout << "Play frame no: " + std::to_string(i) << std::endl;
		++i;
	}
	this->send_on_backchannel(CommandStatus::FINISHED);
	
	//this->notify();
	_backchannel_listen_thread->join();
	std::cout << "[END] void PlayCommand::execute(std::shared_ptr<Event> _event)" << std::endl;
}

void PlayCommand::filename(std::string const& _filename)
{
	this->cmd_filename = _filename;
}
std::string PlayCommand::filename() const
{
	return this->cmd_filename;
}
void PlayCommand::server_address(std::string const& _server_address)
{
	this->cmd_server_address = _server_address;
}
std::string PlayCommand::server_address() const
{
	return this->cmd_server_address;
}
void PlayCommand::num_kinect_cameras(unsigned _num_kinect_cameras)
{
	this->cmd_num_kinect_cameras = _num_kinect_cameras;
}
unsigned PlayCommand::num_kinect_cameras() const
{
	return this->cmd_num_kinect_cameras;
}
void PlayCommand::max_fps(unsigned _max_fps)
{
	this->cmd_max_fps = _max_fps;
}
unsigned PlayCommand::max_fps() const
{
	return this->cmd_max_fps;
}
void PlayCommand::rgb_is_compressed(bool _rgb_is_compressed)
{
	this->cmd_rgb_is_compressed = _rgb_is_compressed;
}
bool PlayCommand::rgb_is_compressed() const
{
	return this->cmd_rgb_is_compressed;
}
void PlayCommand::loop(bool _loop)
{
	this->cmd_loop = _loop;
}
bool PlayCommand::loop() const
{
	return this->cmd_loop;
}
void PlayCommand::startframe(int _startframe)
{
	this->cmd_startframe = _startframe;
}
int PlayCommand::startframe() const
{
	return this->cmd_startframe;
}
void PlayCommand::endframe(int _endframe)
{
	this->cmd_endframe = _endframe;
}
int PlayCommand::endframe() const
{
	return this->cmd_endframe;
}

