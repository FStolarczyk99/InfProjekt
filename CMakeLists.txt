cmake_minimum_required(VERSION 3.15)
project(NetSim)

set(CMAKE_CXX_STANDARD 14)

add_executable(NetSim main.cpp package.cpp package.h storage_types.cpp storage_types.h types.h main.cpp)