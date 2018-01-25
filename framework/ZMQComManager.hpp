//
// Created by arne on 07.11.17.
//

#ifndef RGBD_CALIB_ZMQCOMMANAGER_HPP
#define RGBD_CALIB_ZMQCOMMANAGER_HPP

#include <Observable.hpp>
#include <KinectDaemonHandshake.hpp>
#include <ThreadEvent.hpp>
#include <ZMQPortManager.hpp>
#include <zmq.hpp>
#include <memory>


class ZMQComManager : public Observable{
public:
	ZMQComManager(std::string const& _serverport);
    void listen_for_new_connections();
private:
	std::string serverport;
};


#endif //RGBD_CALIB_ZMQCOMMANAGER_HPP
