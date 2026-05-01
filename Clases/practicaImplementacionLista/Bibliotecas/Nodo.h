//
// Created by ANTONIO on 30/04/2026.
//

#ifndef PRACTICAIMPLEMENTACIONLISTA_NODO_H
#define PRACTICAIMPLEMENTACIONLISTA_NODO_H
#include "Elemento.h"

struct Nodo {
    struct Elemento elemento;
    struct Nodo *siguiente;
};
#endif //PRACTICAIMPLEMENTACIONLISTA_NODO_H
