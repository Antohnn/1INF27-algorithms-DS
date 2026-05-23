cmake_minimum_required(VERSION 4.2)
project(listaSospechosos)

set(CMAKE_CXX_STANDARD 20)

add_executable(listaSospechosos main.cpp
        BibliotecaLista/funcionesLista.cpp)
