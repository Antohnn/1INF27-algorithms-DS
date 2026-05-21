cmake_minimum_required(VERSION 4.2)
project(robotApiladorFusionador)

set(CMAKE_CXX_STANDARD 20)

add_executable(robotApiladorFusionador main.cpp
        BibliotecaPila/Pila.h
        BibliotecaPila/funcionesPila.h
        BibliotecaPila/NodoPila.h
        BibliotecaPila/ElementoPila.h
        BibliotecaPila/funcionesPila.cpp)
