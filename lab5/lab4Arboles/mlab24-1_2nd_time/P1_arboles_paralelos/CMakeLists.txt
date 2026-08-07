cmake_minimum_required(VERSION 4.2)
project(P1_arboles_paralelos)

set(CMAKE_CXX_STANDARD 20)

add_executable(P1_arboles_paralelos main.cpp
        Bibliotecas/estructurasArbol.h
        Bibliotecas/FuncionesArbol.cpp
        Bibliotecas/FuncionesArbol.h)
