cmake_minimum_required(VERSION 4.2)
project(lab25_1_listasCuadrigas)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab25_1_listasCuadrigas main.cpp
        Bibliotecas/ElementoLista.h
        Bibliotecas/funcionesLista.cpp
        Bibliotecas/funcionesLista.h
        Bibliotecas/Lista.h)
