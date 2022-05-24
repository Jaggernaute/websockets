//
// Created by jaggernaute on 5/24/22.
//

#ifndef WEBSOCKETS_CONNECTION_LISTENER_HPP
#define WEBSOCKETS_CONNECTION_LISTENER_HPP

#include <condition_variable>
#include <iostream>
#include "libs/socket.io-client-cpp/src/sio_client.h"

std::mutex _lock;

std::condition_variable_any _cond;
bool connect_finish = false;

class connection_listener
{
    sio::client &handler;

public:

    explicit connection_listener(sio::client& h):
            handler(h)
    {
    }


    void on_connected()
    {
        _lock.lock();
        _cond.notify_all();
        connect_finish = true;
        _lock.unlock();
    }
    void on_close(sio::client::close_reason const& reason)
    {
        std::cout<<"sio closed "<<std::endl;
        exit(0);
    }

    void on_fail()
    {
        std::cout<<"sio failed "<<std::endl;
        exit(0);
    }

    void on_reconnecting()
    {
        std::cout<<"sio reconnecting "<<std::endl;
    }
};

#endif //WEBSOCKETS_CONNECTION_LISTENER_HPP
