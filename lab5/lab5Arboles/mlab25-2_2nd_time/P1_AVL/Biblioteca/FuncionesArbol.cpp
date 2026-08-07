//
// Created by ANTONIO on 3/07/2026.
//

#include "EstructurasArbol.h"

#include <iostream>
using namespace std;
#include "FuncionesArbol.h"

int altura(NodoArbol *nodo) {
    if (nodo==nullptr) return 0;
    return nodo->altura;
}
int factor_balance(NodoArbol *nodo) {
    if (nodo==nullptr) return 0;

    int altura_izq=altura(nodo->izquierda);
    int altura_der=altura(nodo->derecha);

    return altura_izq-altura_der;
}
//rotaciones
//caso cuando el arbol:
//     1
//   2
// 3

NodoArbol *rotacionDerecha(NodoArbol *y) {
    NodoArbol *x=y->izquierda;
    NodoArbol *T2=x->derecha;

    //rotar
    x->derecha=y;
    y->izquierda=T2;

    //actualizar alturas

    y->altura=1+max(altura(y->izquierda),altura(y->derecha));
    x->altura=1+max(altura(x->izquierda),altura(x->derecha));

    return x;
}
//caso cuando el arbol esta para la derecha
NodoArbol *rotacionIzquierda(NodoArbol *x) {
    NodoArbol *y=x->derecha;
    NodoArbol *T2=y->izquierda;

    //rotar
    y->izquierda=x;
    x->derecha=T2;

    //actualizar alturas

    y->altura=1+max(altura(y->izquierda),altura(y->derecha));
    x->altura=1+max(altura(x->izquierda),altura(x->derecha));

    return y;
}

NodoArbol *insertarAVL(NodoArbol *&nodo, int dni) {
    if (nodo==nullptr) {
        nodo=new NodoArbol();
        nodo->dni=dni;
        nodo->altura=1;
        nodo->izquierda=nullptr;
        nodo->derecha=nullptr;
        return nodo;
    }
    if (dni<nodo->dni) {
        nodo->izquierda=insertarAVL(nodo->izquierda,dni);
    }else if (dni>nodo->dni) {
        nodo->derecha=insertarAVL(nodo->derecha,dni);
    }else {
        return nodo;
    }

    nodo->altura=1+max(altura(nodo->izquierda),altura(nodo->derecha));

    int FB=factor_balance(nodo);

    if (FB>1 and dni>nodo->izquierda->dni) {
        nodo->izquierda=rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }
    if (FB>1 and dni<nodo->izquierda->dni) {
        return rotacionDerecha(nodo);
    }
    if (FB<-1 and dni<nodo->izquierda->dni) {
        nodo->derecha=rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }
    if (FB<-1 and dni<nodo->izquierda->dni) {
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

void enOrden(NodoArbol *raiz) {
    if (raiz==nullptr) return;

    enOrden(raiz->izquierda);
    cout<<raiz->dni<<"(h:"<<raiz->altura<<")"<<" ";
    enOrden(raiz->derecha);
}