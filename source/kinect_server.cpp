//
//  main.cpp
//  ZMQ
//
//  Created by Arne Osterthun on 21.08.17.
//  Copyright © 2017 Arne Osterthun. All rights reserved.
//
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

void msg_resolver(unsigned _unique_thread_id, std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>> _messages){
    std::shared_ptr<ZMQMessageType> _type;
    std::shared_ptr<PlayCommand> _cmd = std::make_shared<PlayCommand>();

    auto _type_string = std::string(static_cast<char*>(_messages->front()->data()), _messages->front()->size());
    auto _cmd_string = std::string(static_cast<char*>(_messages->back()->data()), _messages->back()->size());

    std::stringstream _type_stream{_type_string};
    std::stringstream _cmd_stream{_cmd_string};

    boost::archive::text_iarchive _type_archive{_type_stream};
    boost::archive::text_iarchive _cmd_archive{_cmd_stream};

    _type_archive >> *_type.get();
    _cmd_archive >> *_cmd.get();

    _cmd->execute(std::make_shared<Event>());
}

void com_handler(unsigned _unique_thread_id, std::string _com_port) {
    zmq::context_t _ctx(1);
    zmq::socket_t _skt(_ctx, ZMQ_SUB);
    _skt.setsockopt(ZMQ_SUBSCRIBE,"",0);
    _skt.bind(_com_port);

    while (true) {
        std::shared_ptr<std::vector<std::shared_ptr<zmq::message_t>>> _messages = std::make_shared<std::vector<std::shared_ptr<zmq::message_t>>>();
        while (true) {
            std::shared_ptr<zmq::message_t> _msg = std::make_shared<zmq::message_t>();

            if (_skt.recv(_msg.get())) {
                std::cout << "Received message" << std::endl;
                int64_t more = 0;
                size_t more_size = sizeof(more);
                _skt.getsockopt(ZMQ_RCVMORE, &more, &more_size);
                if (more) {
                    _messages->push_back(_msg);
                } else {
                    _messages->push_back(_msg);
                    break;
                }
            }
        }

        //resolver
        std::map<unsigned, std::shared_ptr<std::thread>> _com_threads;
        std::vector<unsigned> _finished_threads;
        unsigned _unique__resolver_thread_id;
        std::shared_ptr<std::mutex> _thread_mutex;

        std::shared_ptr<std::thread> _com_thread = std::make_shared<std::thread>(msg_resolver, _unique_thread_id, _messages);
        _com_threads.insert(std::make_pair(_unique__resolver_thread_id,_com_thread));
        ++_unique__resolver_thread_id;
    }
}

int main(int argc, const char * argv[]) {
	auto _ctx = std::make_shared<zmq::context_t>(1);
	auto _pub_skt = std::make_shared<zmq::socket_t>(*_ctx.get(), ZMQ_PUB);
	auto _sub_skt = std::make_shared<zmq::socket_t>(*_ctx.get(), ZMQ_SUB);
	_sub_skt->setsockopt(ZMQ_SUBSCRIBE,"",0);
	_sub_skt->bind("tcp://*:8000");

    sleep(1);



    std::shared_ptr<zmq::message_t> _msg = std::make_shared<zmq::message_t>();
    std::cout << "Start" << std::endl;
	if (_sub_skt->recv(_msg.get())) {
        try {
            std::cout << "Received message" << std::endl;
            std::shared_ptr<KinectDaemonHandshake> _recv_handshake = std::make_shared<KinectDaemonHandshake>();
            auto _handshake_string = std::string(static_cast<char *>(_msg->data()), _msg->size());
            std::stringstream _handshake_stream(_handshake_string);
            boost::archive::text_iarchive _handshake_archive(_handshake_stream);
            _handshake_archive & *_recv_handshake.get();
            std::cout << _recv_handshake->client_ip() << std::endl;


            _pub_skt->connect("tcp://"+_recv_handshake->client_ip()+":8000");

            sleep(1);

            //std::cout << _recv_handshake->client_ip() << std::endl;


            std::string com_port = "141.54.147.35:8006";

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

            //Open communication on desired port

            //receiver
            std::shared_ptr<ZMQMessageReceiver> _receiver = std::make_shared<ZMQMessageReceiver>();
            std::map<unsigned, std::shared_ptr<std::thread>> _com_threads;
            std::vector<unsigned> _finished_threads;
            unsigned _unique_thread_id;
            std::shared_ptr<std::mutex> _thread_mutex;

            std::shared_ptr<std::thread> _com_thread = std::make_shared<std::thread>(com_handler, _unique_thread_id, com_port);
            _com_threads.insert(std::make_pair(_unique_thread_id,_com_thread));
            ++_unique_thread_id;


        }catch (boost::archive::archive_exception exception)
        {
            std::cout << exception.what() << std::endl;
        }
	}



}
