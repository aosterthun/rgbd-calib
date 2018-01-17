#ifndef ZMQPortManager_hpp
#define ZMQPortManager_hpp

class ZMQPortManager
{
public:
	static ZMQPortManager& get_instance();
	//ZMQPortManager(unsigned _start_port, unsigned _port_offset);
  	unsigned get_next_free_port();
private:
  	unsigned next_free_port;
  	unsigned port_offset;

	ZMQPortManager()= default;
	ZMQPortManager(unsigned _start_port);
	~ZMQPortManager()= default;
	ZMQPortManager(const ZMQPortManager&)= delete;
	ZMQPortManager& operator=(const ZMQPortManager&)= delete;

};

#endif