//
//  RecordCommand.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 21.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//

#include "RecordCommand.hpp"

RecordCommand::RecordCommand()
{
	this->zmq_context = std::make_shared<zmq::context_t>(1);
	this->zmq_pub_socket = std::make_shared<zmq::socket_t>(*this->zmq_context,ZMQ_PUB);
	this->zmq_sub_socket = std::make_shared<zmq::socket_t>(*this->zmq_context,ZMQ_SUB);
	this->zmq_sub_socket->setsockopt(ZMQ_SUBSCRIBE, "", 0);

	this->is_running = true;
	this->cmd_filename = "";
	this->cmd_server_address = "";
    this->cmd_backchannel_com_port = "";
	this->cmd_num_kinect_cameras = 4;
	this->cmd_num_seconds_to_record = 0;
	this->cmd_rgb_is_compressed = true;
	this->cmd_wait_frames_to_before_start = 0;
}

void RecordCommand::listen_on_backchannel()
{
	//std::cout << "[START] void RecordCommand::listen_on_backchannel()" << std::endl;
	this->zmq_sub_socket->connect(this->get_backchannel_port(true)[0]+":"+std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)));
	//std:: cout << this->get_backchannel_port(true)[0]+":"+std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)) << std::endl;
	while (this->is_running) {
		std::shared_ptr<zmq::message_t> _msg = std::make_shared<zmq::message_t>();

		if(this->zmq_sub_socket->recv(_msg.get()))
		{
			CommandStatus _status;
			auto _cmd_string = std::string(static_cast<char*>(_msg->data()), _msg->size());

			std::stringstream _cmd_stream{_cmd_string};

			boost::archive::text_iarchive _cmd_archive{_cmd_stream};

			_cmd_archive >> _status;

			switch (_status) {
				case PAUSE:
					//std::cout << "[PAUSE]" << std::endl;
					this->send_on_backchannel(CommandStatus::PAUSED);
					break;
				case STOP:
					//std::cout << "[STOP]" << std::endl;
					this->is_running = false;
					this->send_on_backchannel(CommandStatus::STOPED);
				default:
					break;
			}
		}
	}
}

void RecordCommand::send_on_backchannel(const int _status)
{
	//std::cout << "RecordCommand::send_on_backchannel(const int _status)" << std::endl;
	this->zmq_pub_socket->bind("tcp://0.0.0.0:"+std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)));
	//std::cout <<  std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)) << std::endl;
	//std::cout << "connected" << std::endl;
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
	//std::cout << "send"  << std::endl;

	this->zmq_pub_socket->unbind("tcp://0.0.0.0:" + std::to_string((std::stoi(this->get_backchannel_port(true)[1],nullptr) + 1)));
	sleep(1);
}

std::vector<std::string> RecordCommand::get_backchannel_port(bool _seperated) {
	////std::cout << "[START] std::vector<std::string> RecordCommand::get_backchannel_port(bool _seperated)" << std::endl;
	//this->cmd_backchannel_com_port = "tcp://141.54.147.106:8001";
	//std:: cout << "1" << std::endl;
    std::vector<std::string> _port;
    if(_seperated){
    	//std:: cout << "2" << std::endl;
        size_t _first = this->cmd_backchannel_com_port.find(":");
        _port.push_back(this->cmd_backchannel_com_port.substr(0,this->cmd_backchannel_com_port.find(":",_first+1)));
        _port.push_back(this->cmd_backchannel_com_port.substr(this->cmd_backchannel_com_port.find(":",_first+1)+1,this->cmd_backchannel_com_port.length()));
        ////std::cout <<  this->cmd_backchannel_com_port.substr(0,this->cmd_backchannel_com_port.find(":",_first+1)) << std::endl;
        ////std::cout <<  this->cmd_backchannel_com_port.substr(this->cmd_backchannel_com_port.find(":",_first+1)+1,this->cmd_backchannel_com_port.length()) << std::endl;
    }else{
    	//std:: cout << "3" << std::endl;
        _port.push_back(this->cmd_backchannel_com_port);
    }
    ////std::cout << "[END] std::vector<std::string> RecordCommand::get_backchannel_port(bool _seperated)" << std::endl;
    return _port;
}

void RecordCommand::set_backchannel_com_port(std::string const &_com_port) {
    this->cmd_backchannel_com_port = _com_port;
}

void RecordCommand::execute(std::shared_ptr<Event> _event)
{
	//std::cout << "[START] void RecordCommand::execute(std::shared_ptr<Event> _event)" << std::endl;

    std::shared_ptr<ThreadEvent> _thread_event = std::static_pointer_cast<ThreadEvent>(_event);
    this->set_backchannel_com_port(_thread_event->get_data());
	std::shared_ptr<std::thread> _backchannel_listen_thread = std::make_shared<std::thread>(&RecordCommand::listen_on_backchannel,this);




	const unsigned colorsize = this->cmd_rgb_is_compressed ? 691200 : 1280 * 1080 * 3;
	const unsigned depthsize = 512 * 424 * sizeof(float);

	FileBuffer fb(this->cmd_filename.c_str());
	if(!fb.open("w", 0/*1073741824 1 GB buffer*/)){
		std::cerr << "error opening " << this->cmd_filename << " exiting..." << std::endl;
	}


	zmq::context_t ctx(1); // means single threaded
	zmq::socket_t  socket(ctx, ZMQ_SUB); // means a subscriber
	socket.setsockopt(ZMQ_SUBSCRIBE, "", 0);
	#if ZMQ_VERSION_MAJOR < 3
	uint64_t hwm = 1;
	socket.setsockopt(ZMQ_HWM,&hwm, sizeof(hwm));
	#else
	uint32_t hwm = 1;
	socket.setsockopt(ZMQ_RCVHWM,&hwm, sizeof(hwm));
	#endif
	////std::cout << "Connect on " << this->cmd_server_address << std::endl;
	std::string endpoint("tcp://" + this->cmd_server_address);
	socket.connect(endpoint.c_str());

	////std::cout << "Connected" << std::endl;
	////std::cout << std::to_string(this->cmd_num_kinect_cameras) << std::endl;
	while(this->cmd_wait_frames_to_before_start > 0){

		zmq::message_t zmqm((colorsize + depthsize) * this->cmd_num_kinect_cameras);
		socket.recv(&zmqm); // blocking

		////std::cout << "countdown: " << this->cmd_wait_frames_to_before_start << std::endl;

		--this->cmd_wait_frames_to_before_start;
	}

	////std::cout << "START!!!!!!!!!!!!!!!!!!!!!!!!!!!!: " << std::endl;

	ChronoMeter cm;
	const double starttime = cm.getTick();
	while(this->is_running){

		zmq::message_t zmqm((colorsize + depthsize) * this->cmd_num_kinect_cameras);
		socket.recv(&zmqm); // blocking

		const double currtime = cm.getTick();
		const double elapsed = currtime - starttime;
		//std::cout << "remaining seconds: " << this->cmd_num_seconds_to_record - elapsed << std::endl;
		if(this->cmd_num_seconds_to_record != 0){
			if(elapsed > this->cmd_num_seconds_to_record)
			this->is_running = false;
		}
		memcpy((char*) zmqm.data(), (const char*) &currtime, sizeof(double));

		unsigned offset = 0;
		for(unsigned i = 0; i < this->cmd_num_kinect_cameras; ++i){
			fb.write((unsigned char*) zmqm.data() + offset, colorsize);
			offset += colorsize;
			fb.write((unsigned char*) zmqm.data() + offset, depthsize);
			offset += depthsize;
		}
	}

	fb.close();

	//this->notify();
	_backchannel_listen_thread->join();
	//std::cout << "[END] void RecordCommand::execute(std::shared_ptr<Event> _event)" << std::endl;
}

ZMQMessageType RecordCommand::get_type() {
	return ZMQMessageType::PLAY;
}

void RecordCommand::filename(std::string const& _filename)
{
	this->cmd_filename = _filename;
}
std::string RecordCommand::filename() const
{
	return this->cmd_filename;
}
void RecordCommand::server_address(std::string const& _server_address)
{
	this->cmd_server_address = _server_address;
}
std::string RecordCommand::server_address() const
{
	return this->cmd_server_address;
}
void RecordCommand::num_kinect_cameras(unsigned _num_kinect_cameras)
{
	this->cmd_num_kinect_cameras = _num_kinect_cameras;
}
unsigned RecordCommand::num_kinect_cameras() const
{
	return this->cmd_num_kinect_cameras;
}
void RecordCommand::num_seconds_to_record(unsigned _num_seconds_to_record)
{
	this->cmd_num_seconds_to_record = _num_seconds_to_record;
}
unsigned RecordCommand::num_seconds_to_record() const
{
	return this->cmd_num_seconds_to_record;
}
void RecordCommand::rgb_is_compressed(bool _rgb_is_compressed)
{
	this->cmd_rgb_is_compressed = _rgb_is_compressed;
}
bool RecordCommand::rgb_is_compressed() const
{
	return this->cmd_rgb_is_compressed;
}
void RecordCommand::wait_frames_to_before_start(unsigned _wait_frames_to_before_start)
{
	this->cmd_wait_frames_to_before_start = _wait_frames_to_before_start;
}
unsigned RecordCommand::wait_frames_to_before_start() const
{
	return this->cmd_wait_frames_to_before_start;
}