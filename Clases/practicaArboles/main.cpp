#include <iostream>

#include "Bibliotecas/NodoArbol.h"
#include "Bibliotecas/ElementoNodo.h"
#include "Bibliotecas/FuncionesArbol.h"


int main() {
    ElementoNodoArbol elemento{};

    NodoArbol *raiz;
    elemento.dato=10;
    raiz= crearNodo(elemento);
    elemento.dato=6;
    raiz->izquierda=crearNodo(elemento);
    elemento.dato=15;
    raiz->derecha=crearNodo(elemento);
    elemento.dato=3;
    raiz->izquierda->izquierda = crearNodo(elemento);
    elemento.dato=8;
    raiz->izquierda->derecha = crearNodo(elemento);
    elemento.dato=20;
    raiz->derecha->derecha = crearNodo(elemento);
    elemento.dato=7;
    raiz->izquierda->derecha->izquierda = crearNodo(elemento);

    cout<<"Preorden: "<<endl;
    preOrden(raiz);
    cout<<endl;

    cout<<"EnOrden: "<<endl;
    enOrden(raiz);
    cout<<endl;

    cout<<"PostOrden: "<<endl;
    postOrden(raiz);
    cout<<endl;

    cout<<endl;
    cout<<"Numero de nodos: "<<contarNodos(raiz)<<endl;
    cout<<endl;
    cout<<"Numero de hojas: "<<contarHojas(raiz)<<endl;
    cout<<"Altura: "<<altura(raiz)<<endl;

    elemento.dato=7;
    if (buscarElemento(raiz, elemento)) {
        cout<<"El elemento "<<elemento.dato<<" esta en el arbol "<<endl;
    }else {
        cout<<"El elemento "<<elemento.dato<<" no esta en el arbol "<<endl;
    }


    return 0;
}
