cmake_minimum_required(VERSION 4.2)
project(P2_MIN_HEAP)

set(CMAKE_CXX_STANDARD 20)

add_executable(P2_MIN_HEAP main.cpp
        Bibliotecas/NodoArbol.h
        Bibliotecas/ElementoArbol.h
        Bibliotecas/Arbol.h
        Bibliotecas/Cola/NodoCola.h
        Bibliotecas/Cola/ElementoCola.h
        Bibliotecas/Cola/Cola.h
        Bibliotecas/Cola/FuncionesCola.cpp
        Bibliotecas/Cola/FuncionesCola.h
        Bibliotecas/FuncionesArbol.cpp
        Bibliotecas/FuncionesArbol.h)
