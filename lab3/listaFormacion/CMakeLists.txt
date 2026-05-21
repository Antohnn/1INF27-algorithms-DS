cmake_minimum_required(VERSION 4.2)
project(listaFormacion)

set(CMAKE_CXX_STANDARD 20)

add_executable(listaFormacion main.cpp
        Bibliotecas/ElementoLista.h
        Bibliotecas/funcionesLista.cpp
        Bibliotecas/funcionesLista.h)
