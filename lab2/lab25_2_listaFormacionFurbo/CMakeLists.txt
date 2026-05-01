cmake_minimum_required(VERSION 4.2)
project(lab25_2_listaFormacionFurbo)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab25_2_listaFormacionFurbo main.cpp
        Bibliotecas/funcionesLista.h
        Bibliotecas/funcionesLista.cpp
        Bibliotecas/ElementoLista.h
)
