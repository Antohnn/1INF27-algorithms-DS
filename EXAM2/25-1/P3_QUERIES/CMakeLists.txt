cmake_minimum_required(VERSION 4.2)
project(P3_QUERIES)

set(CMAKE_CXX_STANDARD 20)

add_executable(P3_QUERIES main.cpp
        Bibliotecas/BibliotecaArbolBinario/ArbolBinario.h
        Bibliotecas/BibliotecaArbolBinario/ElementoArbolBinario.h
        Bibliotecas/BibliotecaArbolBinario/funcionesArbolBinario.h
        Bibliotecas/BibliotecaArbolBinario/funcionesArbolBinario.cpp
        Bibliotecas/BibliotecaArbolBinario/enum.h
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.h)
