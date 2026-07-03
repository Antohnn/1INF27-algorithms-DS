cmake_minimum_required(VERSION 4.2)
project(P1EmpresaPaletasABB)

set(CMAKE_CXX_STANDARD 20)

add_executable(P1EmpresaPaletasABB main.cpp
        Bibliotecas/NodoArbol.h
        Bibliotecas/ElementoArbol.h
        Bibliotecas/Arbol.h
        Bibliotecas/FuncionesArbol.cpp
        Bibliotecas/FuncionesArbol.h)
