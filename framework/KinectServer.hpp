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
    void start();
    void receive(unsigned _unique_thread_id, std::string const& _com_port);
private:
    std::map<unsigned, std::shared_ptr<boost::thread>> running_threads;
    std::vector<unsigned> finished_threads;
    unsigned unique_thread_id;
    std::shared_ptr<std::mutex> thread_mutex;
};


#endif //RGBD_CALIB_KINECTSERVER_HPP
