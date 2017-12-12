//
// Created by arne on 07.11.17.
//

#include "ZMQComManager.hpp"

void ZMQComManager::listen_for_new_connections() {
    std::cout << "[START] void ZMQComManager::listen_for_new_connections()" << std::endl;
    auto _ctx = std::make_shared<zmq::context_t>(1);
    auto _pub_skt = std::make_shared<zmq::socket_t>(*_ctx.get(), ZMQ_PUB);
    auto _sub_skt = std::make_shared<zmq::socket_t>(*_ctx.get(), ZMQ_SUB);
    _sub_skt->setsockopt(ZMQ_SUBSCRIBE,"",0);
    _sub_skt->bind("tcp://*:8000");

    sleep(1);
    while(true){
        std::shared_ptr<zmq::message_t> _msg = std::make_shared<zmq::message_t>();
        std::cout << "Start" << std::endl;
        if (_sub_skt->recv(_msg.get())) {
            std::cout << "Received message" << std::endl;
            std::shared_ptr<KinectDaemonHandshake> _recv_handshake = std::make_shared<KinectDaemonHandshake>();
            auto _handshake_string = std::string(static_cast<char *>(_msg->data()), _msg->size());
            std::stringstream _handshake_stream(_handshake_string);
            boost::archive::text_iarchive _handshake_archive(_handshake_stream);
            _handshake_archive & *_recv_handshake.get();
            std::cout << _recv_handshake->client_ip() << std::endl;


            _pub_skt->connect("tcp://" + _recv_handshake->client_ip() + ":8000");

            sleep(1);

            std::string com_port = "141.54.147.101:8001";

            KinectDaemonHandshake _repl_handshake{};
            _repl_handshake.client_ip(com_port);

            std::stringstream _repl_handshake_stream;
            {
                boost::archive::text_oarchive _repl_handshake_archive(_repl_handshake_stream);
                _repl_handshake_archive << _repl_handshake;
            }
            std::string _repl_handshake_msg_str{_repl_handshake_stream.str()};

            zmq::message_t _send_repl_handshake{_repl_handshake_msg_str.size()};
            memcpy(_send_repl_handshake.data(), _repl_handshake_msg_str.data(), _repl_handshake_msg_str.size());
            _pub_skt->send(_send_repl_handshake);

            std::shared_ptr<ThreadEvent> _thread_event = std::make_shared<ThreadEvent>(_recv_handshake->client_ip()+":8001");
            this->notify(_thread_event);
        }
    }
    std::cout << "[END] void ZMQComManager::listen_for_new_connections()" << std::endl;

}