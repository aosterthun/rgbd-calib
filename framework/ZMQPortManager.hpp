class ZMQPortManager
{
public:
	ZMQPortManager& ZMQPortManager::getInstance();
	ZMQPortManager(ZMQPortManager const&) = delete;
	void operator=(ZMQPortManager const&) = delete;
};