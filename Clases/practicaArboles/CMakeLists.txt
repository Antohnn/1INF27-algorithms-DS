cmake_minimum_required(VERSION 4.2)
project(practicaArboles)

set(CMAKE_CXX_STANDARD 20)

add_executable(practicaArboles main.cpp
        Bibliotecas/NodoArbol.h
        Bibliotecas/ElementoNodo.h
        Bibliotecas/FuncionesArbol.cpp
        Bibliotecas/FuncionesArbol.h
)
