cmake_minimum_required(VERSION 4.2)
project(practicaABB)

set(CMAKE_CXX_STANDARD 20)

add_executable(practicaABB main.cpp
        Bibliotecas/NodoArbolBinario.h
        Bibliotecas/ElementoNodo.h
        Bibliotecas/FuncionesArbolBinario.cpp
        Bibliotecas/FuncionesArbolBinario.h
)
