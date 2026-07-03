#include <iostream>

#include "Bibliotecas/estructuras.h"
#include "Bibliotecas/FuncionesArbol.h"
#include "Bibliotecas/FuncionesCola.h"

using namespace std;

int main() {
    int A[6] = {3, 5, 7, 2, 8, 9};

    NodoArbol *raiz = nullptr;

    Cola colaPadres;
    construirCola(colaPadres);

    cout << "Insertando valores en el min-heap:" << endl;

    for (int i = 0; i < 6; i++) {
        ElementoArbol elemento{};
        elemento.dato = A[i];
        cout << "Insertar " << A[i] << ": ";
        insertarMinHeap(raiz, colaPadres, elemento);
        imprimirPorNiveles(raiz);
    }

    return 0;
}
