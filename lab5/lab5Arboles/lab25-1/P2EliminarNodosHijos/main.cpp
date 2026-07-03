#include <iostream>

#include "Bibliotecas/FuncionesArbol.h"
#include "Bibliotecas/NodoArbol.h"

int main() {

    NodoArbol *raiz = nullptr;

    insertarCodigo(raiz, 100);
    insertarCodigo(raiz, 50);
    insertarCodigo(raiz, 150);
    insertarCodigo(raiz, 25);
    insertarCodigo(raiz, 75);
    insertarCodigo(raiz, 125);
    insertarCodigo(raiz, 175);
    insertarCodigo(raiz, 30);
    insertarCodigo(raiz, 200);
    insertarCodigo(raiz, 28);

    eliminarNodosHijos(raiz);

    enOrden(raiz);

    return 0;
}
