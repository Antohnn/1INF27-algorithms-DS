cmake_minimum_required(VERSION 4.2)
project(listaProManu)

set(CMAKE_CXX_STANDARD 20)

add_executable(listaProManu main.cpp
        BibliotecaLista/funcionesLista.h
        BibliotecaLista/funcionesLista.cpp)
