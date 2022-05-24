cmake_minimum_required(VERSION 3.22)
project(websockets)

set(CMAKE_CXX_STANDARD 23)

add_executable(websockets main.cpp connection_listener.hpp)
target_link_libraries(websockets PRIVATE sioclient)