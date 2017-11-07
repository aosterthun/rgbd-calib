//
// Created by arne on 07.11.17.
//

#include "KinectServer.hpp"

void KinectServer::start() {
    std::shared_ptr<ZMQComManager> _com_manager = std::make_shared<ZMQComManager>();
    std::shared_ptr<ZMQMessageReceiver> _receiver = std::make_shared<ZMQMessageReceiver>();
    std::shared_ptr<ZMQMessageResolver> _resolver = std::make_shared<ZMQMessageResolver>();

    _com_manager->attach(_receiver);
    _receiver->attach(_resolver);

    _com_manager->listen_for_new_connections();
}
