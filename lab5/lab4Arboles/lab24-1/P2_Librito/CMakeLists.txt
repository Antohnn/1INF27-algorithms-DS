cmake_minimum_required(VERSION 4.2)
project(P2_Librito)

set(CMAKE_CXX_STANDARD 20)

add_executable(P2_Librito main.cpp
        Bibliotecas/estructuras.h
        Bibliotecas/FuncionesCola.cpp
        Bibliotecas/FuncionesCola.h
        Bibliotecas/FuncionesArbol.cpp
        Bibliotecas/FuncionesArbol.h)
