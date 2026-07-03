cmake_minimum_required(VERSION 4.2)
project(P2EliminarNodosHijos)

set(CMAKE_CXX_STANDARD 20)

add_executable(P2EliminarNodosHijos main.cpp
        Bibliotecas/NodoArbol.h
        Bibliotecas/ElementoArbol.h
        Bibliotecas/Arbol.h
        Bibliotecas/Pila/NodoPila.h
        Bibliotecas/Pila/ElementoPila.h
        Bibliotecas/Pila/Pila.h
        Bibliotecas/Pila/FuncionesPila.cpp
        Bibliotecas/Pila/FuncionesPila.h
        Bibliotecas/FuncionesArbol.cpp
        Bibliotecas/FuncionesArbol.h)
