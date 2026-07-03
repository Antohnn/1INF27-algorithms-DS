cmake_minimum_required(VERSION 4.2)
project(P2_arbolMinHeap)

set(CMAKE_CXX_STANDARD 20)

add_executable(P2_arbolMinHeap main.cpp
        Bibliotecas/estructuras.h
        Bibliotecas/FuncionesCola.cpp
        Bibliotecas/FuncionesCola.h
        Bibliotecas/FuncionesArbol.cpp
        Bibliotecas/FuncionesArbol.h
)
