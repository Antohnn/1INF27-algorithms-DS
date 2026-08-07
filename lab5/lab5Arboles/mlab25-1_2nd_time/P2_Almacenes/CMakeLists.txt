cmake_minimum_required(VERSION 4.2)
project(P2_Almacenes)

set(CMAKE_CXX_STANDARD 20)

add_executable(P2_Almacenes main.cpp
        Bibliotecas/estructurasArbol.h
        Bibliotecas/FuncionesArbol.cpp
        Bibliotecas/FuncionesArbol.h
        Bibliotecas/estructurasPilas.h
        Bibliotecas/FuncionesPila.cpp
        Bibliotecas/FuncionesPila.h)
