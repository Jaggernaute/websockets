#include <iostream>
#include "libs/socket.io-client-cpp/src/sio_client.h"
#include "libs/socket.io-client-cpp/src/sio_socket.h"
#include "libs/socket.io-client-cpp/src/sio_message.h"


auto main() -> int {
    sio::client h;
    h.connect("http://127.0.0.1:3000");

    return 0;
}