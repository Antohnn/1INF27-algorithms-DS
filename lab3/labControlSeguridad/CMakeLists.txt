cmake_minimum_required(VERSION 4.2)
project(labControlSeguridad)

set(CMAKE_CXX_STANDARD 20)

add_executable(labControlSeguridad main.cpp
        Bibliotecas/funcionesPila.h
        Bibliotecas/funcionesPila.cpp)
