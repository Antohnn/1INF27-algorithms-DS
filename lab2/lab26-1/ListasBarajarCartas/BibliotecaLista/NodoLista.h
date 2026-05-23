//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef LISTASIMPLEMENTEENLAZADA_NODOLISTA_H
#define LISTASIMPLEMENTEENLAZADA_NODOLISTA_H
#include "ElementoLista.h"
struct NodoBaraja {
    struct ElementoBaraja elemento;
    struct NodoBaraja * siguiente;
};
#endif //LISTASIMPLEMENTEENLAZADA_NODOLISTA_H