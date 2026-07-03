//
// Created by ANTONIO on 1/07/2026.
//

#include <iostream>

#include "NodoArbol.h"
#include "Pila/FuncionesPila.h"
#include "Pila/Pila.h"
using namespace std;
#include "FuncionesArbol.h"

NodoArbol *crearNodoArbol(ElementoArbol &elemento) {
    NodoArbol *nuevo = new NodoArbol();

    nuevo->dato=elemento;
    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;
    return nuevo;
}
void insertarABB(NodoArbol *&raiz,ElementoArbol &elemento) {
    if (raiz == nullptr) {
        raiz=crearNodoArbol(elemento);
        return;
    }

    if (elemento.idServidor<raiz->dato.idServidor) {
         insertarABB(raiz->izquierda,elemento);
    }else {
         insertarABB(raiz->derecha,elemento);
    }
}
void insertarEnArbol(NodoArbol *&raiz,int idServer,char flag,ElementoArbol &dato) {
    crearElemento(dato,idServer,flag);
    insertarABB(raiz,dato);
}
ElementoArbol crearElemento(ElementoArbol &dato,int idServer,char flag) {
    dato.idServidor=idServer;
    dato.flag=flag;

    return dato;
}
void enOrden(NodoArbol *raiz) {
    if (raiz == nullptr) return;

    enOrden(raiz->izquierda);
    cout<<raiz->dato.idServidor<<" "<<raiz->dato.flag<<endl;
    enOrden(raiz->derecha);
}

NodoArbol *buscarNodoSkyNerd(NodoArbol *raiz) {
    Pila pila;
    construirPila(pila);

    apilar(pila,raiz,true);


    while (!esPilaVacia(pila)) {
        NodoArbol *actual=desapilar(pila);

        cout << actual->dato.flag << "-" << actual->dato.idServidor << " ";

        if (actual->dato.flag=='S') {
            return actual;
        }

        if (actual->derecha!=nullptr) {
            apilar(pila,actual->derecha,true);
        }

        if (actual->izquierda!=nullptr) {
            apilar(pila,actual->izquierda,true);
        }
    }
    return nullptr;
}
void eliminarHijosSkynerd(NodoArbol *nodoSkyNerd) {
    Pila pila;
    construirPila(pila);

    if (nodoSkyNerd==nullptr) return;

    if (nodoSkyNerd->derecha!=nullptr) {
        apilar(pila,nodoSkyNerd->derecha,false);
    }
    if (nodoSkyNerd->izquierda!=nullptr) {
        apilar(pila,nodoSkyNerd->izquierda,false);
    }


    while (!esPilaVacia(pila)) {
        ElementoPila elemento=desapilarElemento(pila);
        NodoArbol *actual=elemento.nodo;

        if (elemento.valido==false) {
            apilar(pila,actual,true);

            if (actual->derecha!=nullptr) {
                apilar(pila,actual->derecha,false);
            }

            if (actual->izquierda!=nullptr) {
                apilar(pila,actual->izquierda,false);
            }

        }else {
            cout<<actual->dato.flag<<"-"<<actual->dato.idServidor<<" ";
            delete actual;
        }
    }
    nodoSkyNerd->derecha=nullptr;
    nodoSkyNerd->izquierda=nullptr;
}