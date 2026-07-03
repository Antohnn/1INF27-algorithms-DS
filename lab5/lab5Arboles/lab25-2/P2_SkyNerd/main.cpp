#include <iostream>

#include "Bibliotecas/Arbol.h"
#include "Bibliotecas/ElementoArbol.h"
#include "Bibliotecas/FuncionesArbol.h"

using namespace std;

int main() {
    Arbol arbol{};
    ElementoArbol dato{};

    insertarEnArbol(arbol.raiz,100,'N',dato);
    insertarEnArbol(arbol.raiz,50,'N',dato);
    insertarEnArbol(arbol.raiz,25,'N',dato);
    insertarEnArbol(arbol.raiz,75,'N',dato);
    insertarEnArbol(arbol.raiz,150,'N',dato);
    insertarEnArbol(arbol.raiz,125,'S',dato);
    insertarEnArbol(arbol.raiz,175,'N',dato);
    insertarEnArbol(arbol.raiz,200,'N',dato);
    insertarEnArbol(arbol.raiz,140,'N',dato);
    insertarEnArbol(arbol.raiz,130,'N',dato);
    insertarEnArbol(arbol.raiz,110,'N',dato);
    insertarEnArbol(arbol.raiz,115,'N',dato);
    insertarEnArbol(arbol.raiz,105,'N',dato);

    enOrden(arbol.raiz);

    NodoArbol *nodoSkyNerd=buscarNodoSkyNerd(arbol.raiz);

    // cout<<nodoSkyNerd->dato.idServidor<<" "<<nodoSkyNerd->dato.flag<<endl;

    cout<<endl;
    eliminarHijosSkynerd(nodoSkyNerd);
    cout<<endl;

    return 0;
}
