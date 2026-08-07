//
// Created by ANTONIO on 6/07/2026.
//

#include "estructuras.h"
#include "FuncionesArbol.h"

#include <iostream>
using namespace std;

NodoArbol *crearNodoArbol(int dato) {
    NodoArbol *nuevo= new NodoArbol();

    nuevo->dato=dato;
    nuevo->derecha=nullptr;
    nuevo->izquierda=nullptr;

    return nuevo;
}

void insertarEquilibrado(int arr[],NodoArbol *&raiz,int ini,int fin) {
    if (ini>fin) {
       return;
    }
    int med=(ini+fin)/2;

    raiz=crearNodoArbol(arr[med]);
    insertarEquilibrado(arr,raiz->izquierda,ini,med-1);
    insertarEquilibrado(arr,raiz->derecha,med+1,fin);

}
void preOrden(NodoArbol *raiz) {
    if (raiz==nullptr) {
        return;
    }

    cout << raiz->dato << " ";
    preOrden(raiz->izquierda);
    preOrden(raiz->derecha);
}
