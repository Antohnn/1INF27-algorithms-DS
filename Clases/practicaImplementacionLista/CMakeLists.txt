cmake_minimum_required(VERSION 4.2)
project(practicaImplementacionLista)

set(CMAKE_CXX_STANDARD 20)

add_executable(practicaImplementacionLista main.cpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.h
        Bibliotecas/Nodo.h
        Bibliotecas/Elemento.h
        Bibliotecas/Lista.h)
