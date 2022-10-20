cmake_minimum_required(VERSION 3.23)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 20)

add_executable(ConnectFour main.cpp game.cpp game.h display.cpp display.h)
