//
// Created by ANTONIO on 1/07/2026.
//

#include <iostream>

#include "NodoArbol.h"
using namespace std;
#include "FuncionesArbol.h"

NodoArbol *crearNodoArbol(ElementoArbol &elemento) {
    NodoArbol *nuevo=new NodoArbol();
    nuevo->elemento=elemento;
    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;

    return nuevo;
}
void plantarArbol(NodoArbol *&raiz , NodoArbol *izquierda,ElementoArbol &elemento,NodoArbol *derecha) {
    raiz=crearNodoArbol(elemento);
    raiz->izquierda=izquierda;
    raiz->derecha=derecha;
}
void crearElemento(ElementoArbol &elemento,char letra) {
    elemento.letra=letra;
}

void preOrden(NodoArbol *raiz) {
    if (raiz==nullptr) return;

    cout<<raiz->elemento.letra<<" ";
    preOrden(raiz->izquierda);
    preOrden(raiz->derecha);
}
void imprimirPalabras(NodoArbol *raiz,char palabra[],int pos) {
    if (raiz==nullptr) return;

    //imprimimos cuando se llega a la hoja
    palabra[pos]=raiz->elemento.letra;
    if (raiz->izquierda==nullptr and raiz->derecha==nullptr) {
        palabra[pos+1]='\0';
        cout<<palabra<<endl;
        return;
    }
    imprimirPalabras(raiz->izquierda,palabra,pos+1);
    imprimirPalabras(raiz->derecha,palabra,pos+1);
}