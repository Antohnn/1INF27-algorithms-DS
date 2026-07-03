//
// Created by ANTONIO on 1/07/2026.
//

#include "NodoArbol.h"
#include "FuncionesArbol.h"
#include <iostream>
using namespace std;

NodoArbol *CrearNodoArbol(ElementoArbol &elemento) {
    NodoArbol *nuevo=new NodoArbol();

    nuevo->elemento=elemento;
    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;

    return nuevo;
}

void insertar_dia_turno(NodoArbol  *&raiz,int arr[4][7],int ini,int fin) {
    if (ini>fin) {
        raiz=nullptr;
        return;
    }
    int medio=(ini+fin)/2;

    int dia=medio/4+1;
    int turno=medio%4+1;
    ElementoArbol elemento{};
    elemento.dia=dia;
    elemento.turno=turno;
    elemento.cantidad=arr[turno-1][dia-1];

    raiz=CrearNodoArbol(elemento);

    insertar_dia_turno(raiz->izquierda,arr,ini,medio-1);
    insertar_dia_turno(raiz->derecha,arr,medio+1,fin);
}

ElementoArbol crearElemento(int turno,int dia,int cantidad) {
    ElementoArbol elemento{};
    elemento.cantidad=cantidad;
    elemento.dia=dia;
    elemento.turno=turno;
    return elemento;
}
void enOrden(NodoArbol *raiz) {
    if (raiz==nullptr) return;

    enOrden(raiz->izquierda);
    cout<<raiz->elemento.dia<<"/"<<raiz->elemento.turno<<" "<<raiz->elemento.cantidad<<endl;
    enOrden(raiz->derecha);
}
int altura(NodoArbol *raiz) {
    if (raiz==nullptr) return -1;

    int izq=altura(raiz->izquierda);
    int der=altura(raiz->derecha);

    if (izq>der) return izq+1;
    else return der+1;
}
bool estaEquilibrado(NodoArbol *raiz) {
    if (raiz==nullptr) return true;

    int alturaIzq=altura(raiz->izquierda);
    int alturaDer=altura(raiz->derecha);

    int diferencia=alturaIzq-alturaDer;

    if (diferencia<0) diferencia=-diferencia;

    if (diferencia>1) return false;

    return estaEquilibrado(raiz->izquierda) and estaEquilibrado(raiz->derecha);
}
bool esMenorCantidad(ElementoArbol &a,ElementoArbol &b) {
    if (a.cantidad!=b.cantidad) {
        return a.cantidad<b.cantidad;
    }
    if (a.dia!=b.dia) {
        return a.dia<b.dia;
    }
    return a.turno<b.turno;
}
void llenarArreglo(int arr[4][7],ElementoArbol datos[]) {
    int k=0;
    for (int i=0;i<4;i++) {
        for (int j=0;j<7;j++) {
            datos[k].dia=j+1;
            datos[k].turno=i+1;
            datos[k].cantidad=arr[i][j];
            k++;
        }
    }
}
void ordenarArreglo(ElementoArbol datos[]) {

    for (int i=0;i<28-1;i++) {
        int menor=i;
        for (int j=i+1;j<28;j++) {
            if (esMenorCantidad(datos[j],datos[menor])) {
                menor=j;
            }
        }
        if (menor!=i) {
            intercambiar(datos[i],datos[menor]);
        }
    }
}
void intercambiar(ElementoArbol &a,ElementoArbol &b) {
    ElementoArbol aux=a;
    a=b;
    b=aux;
}
void insertar_cantidad(NodoArbol *&raiz,ElementoArbol datos[],int ini,int fin) {
    if (ini>fin) {
        raiz=nullptr;
        return;
    }
    int medio=(ini+fin)/2;

    raiz=CrearNodoArbol(datos[medio]);
    insertar_cantidad(raiz->izquierda,datos,ini,medio-1);
    insertar_cantidad(raiz->derecha,datos,medio+1,fin);
}
