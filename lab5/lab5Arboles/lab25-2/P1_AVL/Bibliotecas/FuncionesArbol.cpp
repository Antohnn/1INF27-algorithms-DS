//
// Created by ANTONIO on 1/07/2026.
//

#include <iostream>

#include "NodoArbol.h"
using namespace std;
#include "FuncionesArbol.h"

NodoArbol *crearNodo(ElementoArbol &elemento) {
    NodoArbol *nuevo=new NodoArbol();
    nuevo->elemento.altura=1;
    nuevo->elemento.dni=elemento.dni;

    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;
    return nuevo;
}

int altura(NodoArbol *raiz) {
    if (raiz==nullptr) {
        return 0;
    }
    return raiz->elemento.altura;
}
int factor_balance(NodoArbol *raiz) {
    if (raiz==nullptr) {
        return 0;
    }
    int altura_izq=altura(raiz->izquierda);
    int altura_der=altura(raiz->derecha);

    return altura_izq-altura_der;
}

NodoArbol *rotacionDerecha(NodoArbol *y) {
    NodoArbol *x=y->izquierda;
    NodoArbol *T2=x->derecha;

    //rotar
    x->derecha=y;
    y->izquierda=T2;

    //actualizamos la altura
    y->elemento.altura=1+max(altura(y->izquierda),altura(y->derecha));
    x->elemento.altura=1+max(altura(x->izquierda),altura(x->derecha));

    return x;
}
NodoArbol *rotacionIzquierda(NodoArbol *x) {
    NodoArbol *y=x->derecha;
    NodoArbol *T2=y->izquierda;

    //rotar
    y->izquierda=x;
    x->derecha=T2;

    //actualizamos la altura
    x->elemento.altura=1+max(altura(x->izquierda),altura(x->derecha));
    y->elemento.altura=1+max(altura(y->izquierda),altura(y->derecha));

    return y;
}

// insertar AVL

NodoArbol *insertarAVL(NodoArbol *nodo,ElementoArbol &elemento) {
    if (nodo==nullptr) {
        nodo=crearNodo(elemento);
        return nodo;
    }

    //insercion ABB normal
    if (elemento.dni<nodo->elemento.dni) {
        nodo->izquierda=insertarAVL(nodo->izquierda,elemento);
    }else if (elemento.dni>nodo->elemento.dni) {
        nodo->derecha=insertarAVL(nodo->derecha,elemento);
    }else {
        return nodo;
    }

    //actualizamos la altura del nodo actual
    nodo->elemento.altura=1+max(altura(nodo->izquierda),altura(nodo->derecha));

    int FB=factor_balance(nodo);

    if (FB > 1 and elemento.dni < nodo->izquierda->elemento.dni) {
        return rotacionDerecha(nodo); // caso LL
    }

    if (FB < -1 and elemento.dni > nodo->derecha->elemento.dni) {
        return rotacionIzquierda(nodo); // caso RR
    }

    if (FB > 1 and elemento.dni > nodo->izquierda->elemento.dni) {
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo); // caso LR
    }

    if (FB < -1 and elemento.dni < nodo->derecha->elemento.dni) {
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo); // caso RL
    }

    return nodo;
}
void crearElemento(ElementoArbol &elemento, int dni) {
    elemento.dni = dni;
    elemento.altura = 1;
}
void enOrden(NodoArbol *raiz) {
    if (raiz == nullptr) return;

    enOrden(raiz->izquierda);

    cout << raiz->elemento.dni
         << "(h:" << raiz->elemento.altura << ") ";

    enOrden(raiz->derecha);
}
