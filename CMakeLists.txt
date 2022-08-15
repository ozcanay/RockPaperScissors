cmake_minimum_required(VERSION 3.21)
project(rps)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp rps.cpp rps.h player.cpp player.h Human.cpp Human.h Computer.cpp Computer.h utility.cpp utility.h constants.h)
