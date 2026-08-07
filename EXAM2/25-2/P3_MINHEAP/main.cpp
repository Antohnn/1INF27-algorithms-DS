#include <iostream>

#include "Bibliotecas/estructuras.h"
#include "Bibliotecas/FuncionesArbol.h"
#include "Bibliotecas/FuncionesCola.h"

using namespace std;

int main() {
    NodoHeap *heap = nullptr;

    Cola colaPadres;
    construirCola(colaPadres);

    insertarMinHeap(heap, colaPadres, 2);
    insertarMinHeap(heap, colaPadres, 5);
    insertarMinHeap(heap, colaPadres, 7);
    insertarMinHeap(heap, colaPadres, 9);
    insertarMinHeap(heap, colaPadres, 8);
    insertarMinHeap(heap, colaPadres, 6);
    insertarMinHeap(heap, colaPadres, 3);

    NodoHeap *minimo = buscarElementoDerecha(heap);

    cout<<minimo->dato<<endl;

    eliminarMinimo(heap);
    imprimirPorNiveles(heap);


    return 0;
}
