cmake_minimum_required(VERSION 3.22)
project(websockets)

set(CMAKE_CXX_STANDARD 23)
find_package(cpprestsdk REQUIRED)

add_executable(websockets main.cpp)
target_link_libraries(websockets PRIVATE cpprestsdk::cpprest)