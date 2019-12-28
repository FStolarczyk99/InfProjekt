cmake_minimum_required(VERSION 3.15)
project(InfProjekt)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(InfProjekt
        package.cpp
        package.h
        storage_types.cpp
        storage_types.h
        types.h main.cpp)
