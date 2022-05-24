#include <iostream>
#include <string>

#include "libs/socket.io-client-cpp/src/sio_client.h"
#include "libs/socket.io-client-cpp/src/sio_socket.h"
#include "libs/socket.io-client-cpp/src/sio_message.h"

#include "connection_listener.hpp"

#define HIGHLIGHT(__O__) std::cout<<"\e[1;31m"<<__O__<<"\e[0m"<<std::endl
#define EM(__O__) std::cout<<"\e[1;30;1m"<<__O__<<"\e[0m"<<std::endl

sio::socket::ptr current_socket;
int participants =-1;

auto main() -> int {

    sio::client h;
    connection_listener l(h);
    h.set_open_listener([ObjectPtr = &l] { ObjectPtr->on_connected(); });
    h.set_close_listener([ObjectPtr = &l](auto && PH1) { ObjectPtr->on_close(std::forward<decltype(PH1)>(PH1)); });
    h.set_fail_listener([ObjectPtr = &l] { ObjectPtr->on_fail(); });
    h.connect("http://127.0.0.1:6969");
    if(!connect_finish)
    {
        _cond.wait(_lock);
    }
    current_socket = h.socket();

    // send ping to server
    std::string payload = "ping";
    current_socket->emit("ping", payload);
    std::cout<<"sent ping"<<std::endl;
    h.close();
}