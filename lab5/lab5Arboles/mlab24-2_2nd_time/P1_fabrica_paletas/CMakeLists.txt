cmake_minimum_required(VERSION 4.2)
project(P1_fabrica_paletas)

set(CMAKE_CXX_STANDARD 20)

add_executable(P1_fabrica_paletas main.cpp
        Bibliotecas/estructurasArbol.h
        Bibliotecas/FuncionesArbol.cpp
        Bibliotecas/FuncionesArbol.h)
