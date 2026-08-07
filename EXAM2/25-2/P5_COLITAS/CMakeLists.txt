cmake_minimum_required(VERSION 4.2)
project(P5_COLITAS)

set(CMAKE_CXX_STANDARD 20)

add_executable(P5_COLITAS main.cpp
        Bibliotecas/BibliotecaCola/ElementoCola.h
        Bibliotecas/BibliotecaCola/NodoCola.h
        Bibliotecas/BibliotecaCola/funcionesCola.cpp)
