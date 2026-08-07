#include <iostream>

#include "Bibliotecas/estructurasArbol.h"
#include "Bibliotecas/FuncionesArbol.h"

using namespace std;

int main() {

    Arbol arbol;
    arbol.raiz=nullptr;

    insertar(arbol.raiz,100);
    insertar(arbol.raiz,50);
    insertar(arbol.raiz,75);
    insertar(arbol.raiz,25);
    insertar(arbol.raiz,30);
    insertar(arbol.raiz,28);
    insertar(arbol.raiz,150);
    insertar(arbol.raiz,175);
    insertar(arbol.raiz,125);
    insertar(arbol.raiz,200);

    enOrden(arbol.raiz);
    cout<<endl;

    eliminarHojasHijos(arbol.raiz);

    enOrden(arbol.raiz);
    cout<<endl;


    return 0;
}
