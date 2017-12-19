ZMQPortManager& ZMQPortManager::getInstance() {
    static ZMQPortManager instance;
    return instance;
}