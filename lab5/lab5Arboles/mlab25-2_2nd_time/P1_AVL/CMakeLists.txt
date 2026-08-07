cmake_minimum_required(VERSION 4.2)
project(P1_AVL)

set(CMAKE_CXX_STANDARD 20)

add_executable(P1_AVL main.cpp
        Biblioteca/EstructurasArbol.h
        Biblioteca/FuncionesArbol.cpp
        Biblioteca/FuncionesArbol.h)
