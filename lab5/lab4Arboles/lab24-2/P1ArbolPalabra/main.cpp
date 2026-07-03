#include <iostream>

#include "Bibliotecas/Arbol.h"
#include "Bibliotecas/FuncionesArbol.h"
using namespace std;
int main() {

    Arbol arbol;
    arbol.raiz=nullptr;
    ElementoArbol elemento;

    //izquierda
    NodoArbol *nodoN=nullptr;
    NodoArbol *nodoE=nullptr;
    NodoArbol *nodoI=nullptr;
    //bilbao
    NodoArbol *nodoO=nullptr;
    NodoArbol *nodoA=nullptr;
    NodoArbol *nodoB=nullptr;
    NodoArbol *nodoL=nullptr;

    crearElemento(elemento,'O');
    plantarArbol(nodoO,nullptr,elemento,nullptr);
    crearElemento(elemento,'A');
    plantarArbol(nodoA,nodoO,elemento,nullptr);
    crearElemento(elemento,'B');
    plantarArbol(nodoB,nodoA,elemento,nullptr);
    crearElemento(elemento,'L');
    plantarArbol(nodoL,nodoB,elemento,nullptr);

    crearElemento(elemento,'N');
    plantarArbol(nodoN,nullptr,elemento,nullptr);
    crearElemento(elemento,'E');
    plantarArbol(nodoE,nodoN,elemento,nullptr);
    crearElemento(elemento,'I');
    plantarArbol(nodoI,nodoE,elemento,nodoL);

    //derecha
    NodoArbol *nodoU=nullptr;
    //
    NodoArbol *nodoELeft=nullptr;
    NodoArbol *nodoNLeft=nullptr;
    NodoArbol *nodoALeft=nullptr;
    NodoArbol *nodoOLeft=nullptr;
    NodoArbol *nodoSLeft=nullptr;

    //
    NodoArbol *nodoRRight=nullptr;
    NodoArbol *nodo2RRight=nullptr;
    NodoArbol *nodoORight=nullptr;
    NodoArbol *nodoARight=nullptr;
    NodoArbol *nodoSRight=nullptr;
    //
    crearElemento(elemento,'S');
    plantarArbol(nodoSRight,nullptr,elemento,nullptr);
    crearElemento(elemento,'O');
    plantarArbol(nodoORight,nullptr,elemento,nodoSRight);
    crearElemento(elemento,'A');
    plantarArbol(nodoARight,nullptr,elemento,nullptr);
    crearElemento(elemento,'R');
    plantarArbol(nodo2RRight,nodoARight,elemento,nodoORight);
    crearElemento(elemento,'R');
    plantarArbol(nodoRRight,nullptr,elemento,nodo2RRight);
    //
    crearElemento(elemento,'S');
    plantarArbol(nodoSLeft,nullptr,elemento,nullptr);
    crearElemento(elemento,'O');
    plantarArbol(nodoOLeft,nullptr,elemento,nodoSLeft);
    crearElemento(elemento,'A');
    plantarArbol(nodoALeft,nullptr,elemento,nullptr);
    crearElemento(elemento,'N');
    plantarArbol(nodoNLeft,nodoALeft,elemento,nodoOLeft);
    crearElemento(elemento,'E');
    plantarArbol(nodoELeft,nodoNLeft,elemento,nullptr);

    crearElemento(elemento,'U');
    plantarArbol(nodoU,nodoELeft,elemento,nodoRRight);
    //ultima insercion
    crearElemento(elemento,'B');
    plantarArbol(arbol.raiz,nodoI,elemento,nodoU);

    preOrden(arbol.raiz);

    cout<<endl;

    char palabra[30];

    imprimirPalabras(arbol.raiz,palabra,0);


    return 0;
}
