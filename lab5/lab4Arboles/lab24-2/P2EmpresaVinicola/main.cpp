#include <iostream>


#include "Bibliotecas/Arbol.h"
#include "Bibliotecas/ElementoArbol.h"
#include "Bibliotecas/FuncionesArbol.h"

int main() {

    Arbol arbol;
    ElementoArbol elemento;

    crearElemento(elemento,2023,200);
    ingresa_lote(arbol.raiz,elemento);
    crearElemento(elemento,2022,50);
    ingresa_lote(arbol.raiz,elemento);

    crearElemento(elemento,2020,75);
    ingresa_lote(arbol.raiz,elemento);
    crearElemento(elemento,2019,125);
    ingresa_lote(arbol.raiz,elemento);
    crearElemento(elemento,2018,100);
    ingresa_lote(arbol.raiz,elemento);
    crearElemento(elemento,2017,25);
    ingresa_lote(arbol.raiz,elemento);
    crearElemento(elemento,2011,300);
    ingresa_lote(arbol.raiz,elemento);
    crearElemento(elemento,2010,175);
    ingresa_lote(arbol.raiz,elemento);

    reporteDeStock(arbol.raiz);




    return 0;
}


