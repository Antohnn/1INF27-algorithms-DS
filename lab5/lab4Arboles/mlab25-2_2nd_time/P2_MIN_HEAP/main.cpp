#include <iostream>

#include "Bibliotecas/Arbol.h"
#include "Bibliotecas/FuncionesArbol.h"
#include "Bibliotecas/Cola/Cola.h"
#include "Bibliotecas/Cola/FuncionesCola.h"

using namespace std;

int main() {

    Arbol arbol;
    arbol.raiz=nullptr;

    int arr[6]{3,5,7,9,8,6};

    Cola cola;
    construirCola(cola);

    for(int i=0;i<6;i++) {
        ElementoArbol elem{};
        elem.dato = arr[i];

        insertarMinHeap(arbol.raiz,cola,elem);
    }
    imprimirPorNiveles(arbol.raiz);


    return 0;
}
