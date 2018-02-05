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
	cmd_num_kinect_cameras = 4;
	cmd_max_fps = 20;
	cmd_rgb_is_compressed = true;
	cmd_loop = true;
	cmd_startframe = 0;
	cmd_endframe = 0;
	this->is_running = true;
}

void PlayCommand::listen_on_backchannel()
{
 	std::cout << this->get_backchannel_port(true)[0]+":"+std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)) << std::endl;
	this->zmq_sub_socket->connect(this->get_backchannel_port(true)[0]+":"+std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)));
	while (this->is_running) {
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
				case UNPAUSE:
					this->is_running = true;
					std::cout << "[UNPAUSE]" << std::endl;
					this->send_on_backchannel(CommandStatus::UNPAUSED);
					break;
				case STOP:
					this->is_running = false;
					std::cout << "[STOP]" << std::endl;
					this->send_on_backchannel(CommandStatus::STOPED);
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
	std::cout <<  std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)) << std::endl;
	this->zmq_pub_socket->bind("tcp://0.0.0.0:"+std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)));
	std::cout <<  std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)) << std::endl;
	std::cout << "connected" << std::endl;
	sleep(1);
	CommandStatus _cmd_status = static_cast<CommandStatus>(_status);
/*
	GenericMessage _msg;
	_msg.set_type();*/

	std::stringstream _cmd_status_stream;
	boost::archive::text_oarchive _cmd_status_archive(_cmd_status_stream);
	_cmd_status_archive << _cmd_status;
	std::string _cmd_status_msg_str = _cmd_status_stream.str();
	zmq::message_t _cmd_status_msg(_cmd_status_msg_str.length());
	memcpy(_cmd_status_msg.data(), _cmd_status_msg_str.data(), _cmd_status_msg_str.length());
	this->zmq_pub_socket->send(_cmd_status_msg);
	std::cout << "send"  << std::endl;

	this->zmq_pub_socket->unbind("tcp://0.0.0.0:" + std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)));


}

std::vector<std::string> PlayCommand::get_backchannel_port(bool _seperated) {
    //std::cout << "[START] std::vector<std::string> RecordCommand::get_backchannel_port(bool _seperated)" << std::endl;
	//this->cmd_backchannel_com_port = "tcp://141.54.147.106:8001";
	//std:: cout << "1" << std::endl;
    std::vector<std::string> _port;
    if(_seperated){
    	//std:: cout << "2" << std::endl;
        size_t _first = this->cmd_backchannel_com_port.find(":");
        _port.push_back(this->cmd_backchannel_com_port.substr(0,this->cmd_backchannel_com_port.find(":",_first+1)));
        _port.push_back(this->cmd_backchannel_com_port.substr(this->cmd_backchannel_com_port.find(":",_first+1)+1,this->cmd_backchannel_com_port.length()));
        //std::cout <<  this->cmd_backchannel_com_port.substr(0,this->cmd_backchannel_com_port.find(":",_first+1)) << std::endl;
        //std::cout <<  this->cmd_backchannel_com_port.substr(this->cmd_backchannel_com_port.find(":",_first+1)+1,this->cmd_backchannel_com_port.length()) << std::endl;
    }else{
    	//std:: cout << "3" << std::endl;
        _port.push_back(this->cmd_backchannel_com_port);
    }
    //std::cout << "[END] std::vector<std::string> RecordCommand::get_backchannel_port(bool _seperated)" << std::endl;
    return _port;
}

void PlayCommand::set_backchannel_com_port(std::string const &_com_port) {
    this->cmd_backchannel_com_port = _com_port;
}

void PlayCommand::execute(std::shared_ptr<Event> _event)
{
	std::cout << "[START] void PlayCommand::execute(std::shared_ptr<Event> _event)" << std::endl;
  std::shared_ptr<ThreadEvent> _thread_event = std::static_pointer_cast<ThreadEvent>(_event);
  this->set_backchannel_com_port(_thread_event->get_data());
    //std::cout << "[FILENAME]: " << this->filename() << std::endl;
	std::shared_ptr<std::thread> _backchannel_listen_thread = std::make_shared<std::thread>(&PlayCommand::listen_on_backchannel,this);
	this->send_on_backchannel(CommandStatus::STARTED);

	//std::cout << ZMQPortManager::get_instance().get_next_free_port() << std::endl;

	unsigned min_frame_time_ns = 1000000000/cmd_max_fps;

	const unsigned colorsize = cmd_rgb_is_compressed ? 691200 : 1280 * 1080 * 3;
	const unsigned depthsize = 512 * 424 * sizeof(float);

	FileBuffer fb(this->filename().c_str());
	if(!fb.open("r")){
		std::cerr << "error opening  exiting..." << std::endl;

	}
	fb.setLooping(cmd_loop);


	zmq::context_t ctx(1); // means single threaded
	zmq::socket_t  socket(ctx, ZMQ_PUB); // means a publisher
	#if ZMQ_VERSION_MAJOR < 3
	uint64_t hwm = 1;
	socket.setsockopt(ZMQ_HWM,&hwm, sizeof(hwm));
	#else
	uint32_t hwm = 1;
	socket.setsockopt(ZMQ_SNDHWM,&hwm, sizeof(hwm));
	#endif
	std::cout << this->cmd_server_address << std::endl;
	std::string endpoint("tcp://"+ this->server_address());
	socket.bind(endpoint.c_str());

	sensor::timevalue ts(sensor::clock::time());



	while(this->is_running){
		zmq::message_t zmqm((colorsize + depthsize) * cmd_num_kinect_cameras);

		unsigned offset = 0;
		for(unsigned i = 0; i < cmd_num_kinect_cameras; ++i){
			fb.read((unsigned char*) zmqm.data() + offset, colorsize);
			offset += colorsize;
			fb.read((unsigned char*) zmqm.data() + offset, depthsize);
			offset += depthsize;
		}

		// send frames
		socket.send(zmqm);

		// check if fps is correct
		sensor::timevalue ts_now = sensor::clock::time();
		long long time_spent_ns = (ts_now - ts).nsec();
		long long rest_sleep_ns = min_frame_time_ns - time_spent_ns;
		ts = ts_now;
		if(0 < rest_sleep_ns){
			sensor::timevalue rest_sleep(0,rest_sleep_ns);
			nanosleep(rest_sleep);
		}
	}
	_backchannel_listen_thread->join();
	socket.unbind("tcp://" + this->server_address());
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
