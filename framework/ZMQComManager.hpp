//
// Created by arne on 07.11.17.
//

#ifndef RGBD_CALIB_ZMQCOMMANAGER_HPP
#define RGBD_CALIB_ZMQCOMMANAGER_HPP

#include <Observable.hpp>
#include <KinectDaemonHandshake.hpp>
#include <ThreadEvent.hpp>
#include <zmq.hpp>
#include <memory>


class ZMQComManager : public Observable{
public:
    void listen_for_new_connections();
};


#endif //RGBD_CALIB_ZMQCOMMANAGER_HPP
