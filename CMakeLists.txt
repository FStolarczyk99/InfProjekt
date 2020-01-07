cmake_minimum_required(VERSION 3.15)
project(InfProjekt)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors)

include_directories(.)

add_executable(
        InfProjekt
        main.cpp
        package.cpp
        package.hpp
        storage_types.cpp
        storage_types.hpp
        types.hpp
        nodes.cpp
        nodes.hpp
        helpers.cpp helpers.hpp)
