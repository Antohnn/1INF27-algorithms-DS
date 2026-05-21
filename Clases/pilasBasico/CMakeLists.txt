cmake_minimum_required(VERSION 4.2)
project(pilasBasico)

set(CMAKE_CXX_STANDARD 20)

add_executable(pilasBasico main.cpp
        BibliotecaPila/ElementoPila.h
        BibliotecaPila/funcionesPila.cpp
        BibliotecaPila/funcionesPila.h)
