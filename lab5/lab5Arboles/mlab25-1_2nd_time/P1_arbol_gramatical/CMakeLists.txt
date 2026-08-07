cmake_minimum_required(VERSION 4.2)
project(P1_arbol_gramatical)

set(CMAKE_CXX_STANDARD 20)

add_executable(P1_arbol_gramatical main.cpp
        Bibliotecas/estructurasArbol.h
        Bibliotecas/enum.h
        Bibliotecas/FuncionesArbol.cpp
        Bibliotecas/FuncionesArbol.h)
