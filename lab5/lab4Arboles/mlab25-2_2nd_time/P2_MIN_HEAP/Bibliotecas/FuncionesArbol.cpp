//
// Created by ANTONIO on 3/07/2026.
//

#include <iostream>

#include "ElementoArbol.h"
#include "NodoArbol.h"
#include "Cola/Cola.h"
#include "Cola/FuncionesCola.h"
using namespace std;
#include "FuncionesArbol.h"

NodoArbol *crearNodoArbol(ElementoArbol &elemento) {
    NodoArbol *nuevo = new NodoArbol();

    nuevo->elemento=elemento;
    nuevo->padre=nullptr;
    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;

    return nuevo;
}
// como queremos insertar de manera min heap entonces
void insertarMinHeap(NodoArbol *&raiz,Cola &cola,ElementoArbol &elemento) {
    NodoArbol *nuevo = crearNodoArbol(elemento);

    //primero para el caso en el cual el arbol este vacio
    if (raiz==nullptr) {
        raiz=nuevo;
        //enconlamos el primer nivel del arbol
        encolarNodoArbol(cola,nuevo);
        return;
    }
    //ahora analizamos en el caso de que hayan nodos queremos desencolar el nodo guardado en la cola para ver si tiene
    //izq y der
    //primero vemos el primer elemento de la cola y lo guardamos en un aux
    NodoCola *frente=cola.frente;
    //guardamos ese nodo en frente, que seria el padre, en otro aux para poder realizar la comparacion
    NodoArbol *padre=frente->elemento.nodo;

    //si el nodo padre o raiz no tiene ningun elemento insertado a la izquierda entonces hacemos que el nuevo nodo vaya
    // a ese lado caso contrario al derecho
    if (padre->izquierda==nullptr) {
        padre->izquierda=nuevo;
        nuevo->padre=padre;
    }else {
        padre->derecha=nuevo;
        nuevo->padre=padre;

        //para este caso como este nodo padre ya estaria completo entonces lo desencolamos de la cola porque no queremos
        //voler a analizarlo
        desencolar(cola);
    }

    //encolamos el nuevo nodo para analizarlo como padre si fuese necesario
    encolarNodoArbol(cola,nuevo);
    //realizamos el heapifyUp
    heapifyup(nuevo);
}
//tenemos el nodo nuevo entonces vamos a hacer un recorrido utilizando los punteros a padre que tiene cada nodo
//si el nuevo es menor al elemento padre se hace un swap sino no pasa nada
void heapifyup(NodoArbol *nuevo) {
    while (nuevo->padre!=nullptr and nuevo->elemento.dato<nuevo->padre->elemento.dato) {
        intercambiarDatos(nuevo,nuevo->padre);
        nuevo=nuevo->padre;
    }
}
void intercambiarDatos(NodoArbol *nuevo,NodoArbol *padre) {
    ElementoArbol aux=nuevo->elemento;
    nuevo->elemento=padre->elemento;
    padre->elemento=aux;
}
//quiero imprimir por niveles asi que utilizamos una cola auxiliar para ir imprimiendo por nivel
void imprimirPorNiveles(NodoArbol *raiz) {
    Cola cola;
    construirCola(cola);

    if (raiz==nullptr) return;
    
    encolarNodoArbol(cola,raiz);

    while (!esColaVacia(cola)) {
        //desencolamos el nodo guardado en la cola y lo imprimimos
        ElementoCola aux=desencolar(cola);
        NodoArbol *actual=aux.nodo;

        cout<<actual->elemento.dato<<" ";

        //verificamos si el nodo actual tiene izquierda y derecha
        // de ser el caso encolamos para imprimir el nivel de izquierda a derecha
        if (actual->izquierda!=nullptr) {
            encolarNodoArbol(cola,actual->izquierda);
        }
        if (actual->derecha!=nullptr) {
            encolarNodoArbol(cola,actual->derecha);
        }
    }
    cout<<endl;
}
