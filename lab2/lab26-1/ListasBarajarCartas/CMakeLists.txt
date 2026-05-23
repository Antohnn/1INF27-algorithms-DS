cmake_minimum_required(VERSION 4.2)
project(ListasBarajarCartas)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListasBarajarCartas main.cpp
        BibliotecaLista/funcionesLista.cpp
        BibliotecaLista/FuncionesAuxiliares.cpp
        BibliotecaLista/FuncionesAuxiliares.h)
