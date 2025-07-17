cmake_minimum_required(VERSION 3.16.3)
project(Network)

set(CMAKE_CXX_STANDARD 20)

add_executable(Client Client.cpp)
add_executable(Server Server.cpp)