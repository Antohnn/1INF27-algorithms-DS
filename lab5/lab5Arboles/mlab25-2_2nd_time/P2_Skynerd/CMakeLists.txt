cmake_minimum_required(VERSION 4.2)
project(P2_Skynerd)

set(CMAKE_CXX_STANDARD 20)

add_executable(P2_Skynerd main.cpp
        Bibliotecas/estructurasArbol.h
        Bibliotecas/estructurasPila.h
        Bibliotecas/FuncionesPila.cpp
        Bibliotecas/FuncionesPila.h
        Bibliotecas/FuncionesArbol.cpp
        Bibliotecas/FuncionesArbol.h)
