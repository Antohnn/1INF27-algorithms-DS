#include <iostream>

#include "Bibliotecas/estructuras.h"
#include "Bibliotecas/FuncionesArbol.h"

using namespace std;
int main() {
    Arbol arbol;
    arbol.raiz = nullptr;
    arbol.tamanio = 0;

    construirArbol(arbol);

    cout << "Arbol original por niveles:" << endl;
    int nivel = buscarPrincipalBFS(arbol.raiz);

    cout << "El nivel es:" << nivel << endl;
    cout << "Tamanio del arbol: " << arbol.tamanio << endl;

    cout << endl;

    cout << "Despues de eliminar la parte derecha del arbol:" << endl;
    removerParte(arbol, arbol.raiz, 'D');

    buscarPrincipalBFS(arbol.raiz);

    cout << "Tamanio del arbol: " << arbol.tamanio << endl;

    return 0;
}