cmake_minimum_required(VERSION 4.2)
project(lab25_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab25_2 main.cpp
        Bibliotecas/NodoArbol.h
        Bibliotecas/ElementoArbol.h
        Bibliotecas/Arbol.h
        Bibliotecas/FuncionesArbol.cpp
        Bibliotecas/FuncionesArbol.h)
