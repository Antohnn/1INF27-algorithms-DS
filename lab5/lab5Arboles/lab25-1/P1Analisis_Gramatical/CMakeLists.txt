cmake_minimum_required(VERSION 4.2)
project(P1Analisis_Gramatical)

set(CMAKE_CXX_STANDARD 20)

add_executable(P1Analisis_Gramatical main.cpp
        Bibliotecas/NodoArbol.h
        Bibliotecas/ElementoArbol.h
        Bibliotecas/enum.h
        Bibliotecas/Arbol.h
        Bibliotecas/FuncionesArbol.cpp
        Bibliotecas/FuncionesArbol.h
)
