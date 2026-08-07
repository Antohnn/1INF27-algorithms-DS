#include <iostream>

#include "Bibliotecas/estructuras.h"
#include "Bibliotecas/FuncionesArbol.h"

using namespace std;

int main() {
    Arbol arbol;

    int arr[7]={2,4,6,8,10,12,14};

    insertarEquilibrado(arr,arbol.raiz,0,6);
    preOrden(arbol.raiz);


    return 0;
}
