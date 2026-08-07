//
// Created by ANTONIO on 4/07/2026.
//

#include "estructurasArbol.h"

#include <iostream>
using namespace std;
#include "FuncionesArbol.h"

NodoArbol *crearNodoArbol(ElementoArbol &elemento) {
    NodoArbol *nuevo=new NodoArbol();

    nuevo->dato=elemento;
    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;

    return nuevo;
}

void insertar_dia_turno(NodoArbol *&raiz,int arr[4][7],int ini,int fin) {
    if (ini>fin) {
        raiz=nullptr;
        return;
    }

    int medio=(ini+fin)/2;
    int dia=medio/4+1;
    int turno=medio%4+1;

    ElementoArbol elem{};
    elem.turno=turno;
    elem.dia=dia;
    elem.cantidad=arr[turno-1][dia-1];

    raiz=crearNodoArbol(elem);

    insertar_dia_turno(raiz->izquierda,arr,ini,medio-1);
    insertar_dia_turno(raiz->derecha,arr,medio+1,fin);
}

void llenarArreglo(int arr[4][7],ElementoArbol datos[]) {
    int k=0;
    for (int i=0;i<4;i++) {
        for (int j=0;j<7;j++) {
            datos[k].cantidad=arr[i][j];
            datos[k].turno=i+1;
            datos[k].dia=j+1;
            k++;
        }
    }
}
void ordenarArreglo(ElementoArbol datos[]) {
    for (int i=0;i<28-1;i++) {
        int menor=i;
        for (int j=i+1;j<28;j++) {
            if (esMenor(datos[j],datos[menor])) {
                menor=j;
            }
        }
        if (menor!=i) {
            intercambiar(datos[i],datos[menor]);
        }
    }
}
bool esMenor(ElementoArbol &a,ElementoArbol &b) {
    if (a.cantidad!=b.cantidad) {
        return a.cantidad<b.cantidad;
    }
    if (a.dia!=b.dia) {
        return a.dia<b.dia;
    }
    return a.turno<b.turno;
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
    raiz=crearNodoArbol(datos[medio]);

    insertar_cantidad(raiz->izquierda,datos,ini,medio-1);
    insertar_cantidad(raiz->derecha,datos,medio+1,fin);
}
void enOrden(NodoArbol *raiz) {
    if (raiz==nullptr) {
        return;
    }
    enOrden(raiz->izquierda);
    cout<<raiz->dato.cantidad<<endl;
    enOrden(raiz->derecha);
}
