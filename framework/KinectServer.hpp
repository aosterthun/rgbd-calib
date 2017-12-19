//
// Created by arne on 07.11.17.
//

#ifndef RGBD_CALIB_KINECTSERVER_HPP
#define RGBD_CALIB_KINECTSERVER_HPP
#include <iostream>
#include <memory>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <zmq.hpp>
#include <KinectDaemonHandshake.hpp>
#include <mutex>
#include <PlayCommand.hpp>
#include <ZMQMessageType.hpp>
#include <ZMQMessageReceiver.hpp>
#include <ZMQMessageResolver.hpp>
#include <KinectServer.hpp>
#include <Observable.hpp>
#include <ZMQComManager.hpp>

class KinectServer : public Observable {
public:
	KinectServer(std::string const& _serverport);
    void start();
private:
	std::string serverport;
};


#endif //RGBD_CALIB_KINECTSERVER_HPP
