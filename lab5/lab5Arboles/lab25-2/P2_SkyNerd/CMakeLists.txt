cmake_minimum_required(VERSION 4.2)
project(P2_SkyNerd)

set(CMAKE_CXX_STANDARD 20)

add_executable(P2_SkyNerd main.cpp
        Bibliotecas/NodoArbol.h
        Bibliotecas/ElementoArbol.h
        Bibliotecas/Arbol.h
        Bibliotecas/FuncionesArbol.cpp
        Bibliotecas/FuncionesArbol.h
        Bibliotecas/Pila/ElementoPila.h
        Bibliotecas/Pila/NodoPIla.h
        Bibliotecas/Pila/Pila.h
        Bibliotecas/Pila/FuncionesPila.cpp
        Bibliotecas/Pila/FuncionesPila.h
)
