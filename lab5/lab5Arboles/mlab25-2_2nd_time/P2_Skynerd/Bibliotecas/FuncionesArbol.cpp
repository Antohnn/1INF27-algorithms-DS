//
// Created by ANTONIO on 3/07/2026.
//

#include "estructurasPila.h"
#include "estructurasArbol.h"
#include "FuncionesPila.h"

#include <iostream>
using namespace std;
#include "FuncionesArbol.h"

NodoArbol *crearNodoArbol(ElementoArbol &elemento) {
    NodoArbol *nuevo= new NodoArbol();

    nuevo->dato=elemento;
    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;

    return nuevo;
}
void insertarEnArbol(NodoArbol *&raiz,char flag,int idServer) {
    ElementoArbol elemento{};
    elemento.flag=flag;
    elemento.idServidor=idServer;
    insertarABB(raiz,elemento);
}
void insertarABB(NodoArbol *&raiz,ElementoArbol &elemento) {
    if (raiz==nullptr) {
        raiz=crearNodoArbol(elemento);
        return;
    }
    if (elemento.idServidor<raiz->dato.idServidor) {
        insertarABB(raiz->izquierda,elemento);
    }else {
        insertarABB(raiz->derecha,elemento);
    }
}
void enOrden(NodoArbol *raiz) {
    if (raiz==nullptr) {
        return;
    }
    enOrden(raiz->izquierda);
    cout<<raiz->dato.flag<<" "<<raiz->dato.idServidor<<"  ";
    enOrden(raiz->derecha);
}
//buscamos a skynerd usando una pila auxiliar
NodoArbol *buscarSkyNerd(NodoArbol *raiz) {
    Pila pila;
    crearPila(pila);

    //apilamos la raiz
    apilar(pila,raiz,true);

    while (!esPilaVacia(pila)) {
        //desapilamos el elemento en la cima para poder verificar si es la flag
        ElementoPila ele=desapilar(pila);
        NodoArbol *actual=ele.nodo;

        cout<<actual->dato.flag<<"-"<<actual->dato.idServidor<<"  ";

        //si es la flag devolvemos el actual
        if (actual->dato.flag=='S') {
            return actual;
        }

        //si la cima tiene derecha entonces apilamos derecha
        if (actual->derecha!=nullptr) {
            apilar(pila,actual->derecha,true);
        }
        //si la cima tiene izquierda apilamos izquierda
        if (actual->izquierda!=nullptr) {
            apilar(pila,actual->izquierda,true);
        }
        //se hace de esta forma ya que al ser una pila y queremos revisar primero la parte izquierda del arbol cuando se apila queda de esta forma
        // izquierda derecha nodo un postOrden interesante
    }
    cout<<endl;
    return nullptr;
}
void eliminarHijosSkyNerd(NodoArbol *skynerd) {
    //para realizar la eliminacion utilizamos una pila auxiliar al igual que con la busqueda seguimos un DFS
    //depth first

    Pila pila;
    crearPila(pila);

    if (skynerd->derecha!=nullptr) {
        apilar(pila,skynerd->derecha,false);
    }
    if (skynerd->izquierda!=nullptr) {
        apilar(pila,skynerd->izquierda,false);
    }

    while (!esPilaVacia(pila)) {
        //desapilamos el nodo y verificamos si ya lo visitamos de no ser el caso se vuelve a apilar con el valor
        //booleano de visitado en true
        ElementoPila ele=desapilar(pila);
        NodoArbol *actual=ele.nodo;
        if (ele.visitado==false) {
            apilar(pila,actual,true);
            //apilamos los dos hijos del actual en caso de que existan con valores de visitado en false
            if (actual->derecha!=nullptr) {
                apilar(pila,actual->derecha,false);
            }
            if (actual->izquierda!=nullptr) {
                apilar(pila,actual->izquierda,false);
            }
        }else {
            //una vez ya recorri el nodo puedo eliminarlo tranquilamente
            cout<<actual->dato.flag<<"-"<<actual->dato.idServidor<<"  ";
            delete actual;
        }
    }
    cout<<endl;
    skynerd->derecha=nullptr;
    skynerd->izquierda=nullptr;
}
