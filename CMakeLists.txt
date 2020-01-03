cmake_minimum_required(VERSION 3.15)
project(InfProjekt)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors)

include_directories(.)

add_executable(
        InfProjekt
        main.cpp
        package.cpp
        package.h
        storage_types.cpp
        storage_types.h
        types.h
        nodes.cpp
        nodes.h
        helpers.cpp helpers.h)
