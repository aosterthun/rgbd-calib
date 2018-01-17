#include "GenericMessage.hpp"

GenericMessage::GenericMessage(){}

GenericMessage::GenericMessage(zmq::message_t* _msg)
	: type_(),
	  size_payload_byte_(),
	  payload_()

{
	int type;
    unsigned size_payload_byte;
    std::string payload;

    memcpy((unsigned char*) &type_,((const unsigned char*)_msg->data()),sizeof(int));
    memcpy((unsigned char*) &size_payload_byte_, ((const unsigned char*)_msg->data()) + sizeof(int), sizeof(unsigned));
    payload_.reserve(size_payload_byte_);
    memcpy((unsigned char*) payload_.c_str(), ((const unsigned char*)_msg->data()) + sizeof(int) + sizeof(unsigned), size_payload_byte_);
  
    std::cout << "Payload: " << payload_.c_str() << std::endl;
	/*this->set_type(type);
	std::cout << this->type() << std::endl;
	this->set_payload_size(size_payload_byte);
	std::cout << this->size_payload_byte_ << std::endl;
	this->set_payload(payload);	
	std::cout << this->payload() << std::endl;*/
}

int GenericMessage::type(){
	return this->type_;
}

unsigned GenericMessage::size_payload_byte(){
	return this->size_payload_byte_;
}

const char* GenericMessage::payload(){
	return this->payload_.c_str();
}

void GenericMessage::set_type(ZMQMessageType _type){
	this->type_ = _type;
}

void GenericMessage::set_type(int _type){
	this->type_ = _type;
}

void GenericMessage::set_payload_size(unsigned _size_payload_byte){
	this->size_payload_byte_ = _size_payload_byte;
}

unsigned GenericMessage::get_message_size(){
	return sizeof(int) + sizeof(unsigned) + this->size_payload_byte_;
}

void GenericMessage::set_payload(std::shared_ptr<AbstractCommand> _cmd){
	std::shared_ptr<PlayCommand> _exe(std::dynamic_pointer_cast<PlayCommand>(_cmd));

	std::stringstream _exe_stream;

    boost::archive::text_oarchive _exe_archive{_exe_stream};
    _exe_archive << *_exe;
	this->payload_ = _exe_stream.str();
}

void GenericMessage::set_payload(std::string const& _cmd){
	this->payload_ = _cmd.c_str();
}

zmq::message_t GenericMessage::build_zmq_message(){
	this->set_type(ZMQMessageType::PLAY);

	this->set_payload_size(this->payload_.size() + 1);

	zmq::message_t _exe_msg{this->get_message_size()};

	memcpy((unsigned char*) _exe_msg.data(), (const unsigned char*) this->type_, sizeof(int));
	memcpy((unsigned char*) _exe_msg.data(), (const unsigned char*) this->size_payload_byte_, sizeof(unsigned));
	memcpy((unsigned char*) _exe_msg.data(), (const unsigned char*) this->payload_.c_str(), this->size_payload_byte_);

	return _exe_msg;
}

GenericMessage::~GenericMessage(){}