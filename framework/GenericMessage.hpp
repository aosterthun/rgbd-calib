#ifndef GenericMessage_hpp
#define GenericMessage_hpp

#include <PlayCommand.hpp>
#include <RecordCommand.hpp>
#include <AbstractCommand.hpp>
#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <sstream>
#include <zmq.hpp>
#include <ZMQMessageType.hpp>
#include <KinectDaemonHandshake.hpp>

class GenericMessage
{
public:
	GenericMessage();
	GenericMessage(zmq::message_t* _msg);
	void set_type(ZMQMessageType _type);
	void set_type(int _type);
	void set_payload_size(unsigned _size_payload_byte);
	void set_payload(std::shared_ptr<AbstractCommand> _cmd);
	void set_payload(std::string const& _cmd);
	unsigned get_message_size();
	zmq::message_t build_zmq_message();
	int type();
	unsigned size_payload_byte();
	const char* payload();
	~GenericMessage();
	
private:
	int type_;
	unsigned size_payload_byte_;
	std::string payload_;
};

#endif