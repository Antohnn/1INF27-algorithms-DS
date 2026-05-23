#include <cstring>
#include <fstream>
#include <iostream>

#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"

using namespace std;

void encolarPreferente(Cola &colaAtencion,int codigo,int prioridad) {
   NodoCola *nuevoNodo=new NodoCola();
    nuevoNodo->elemento.codigo=codigo;
    nuevoNodo->elemento.prioridad=prioridad;
    nuevoNodo->siguiente=nullptr;
    //primero validamos si hay algun elemento con anterioridad
    if (colaAtencion.inicio==nullptr) {
        colaAtencion.inicio=nuevoNodo;
        colaAtencion.fin=nuevoNodo;
        if (prioridad==1) {
            colaAtencion.list1=nuevoNodo;
        }else {
            colaAtencion.list1=nullptr;
        }
        colaAtencion.longitud++;
        return;
    }
    //si llega prioridad 1
    if (prioridad==1) {
        //como existe el caso en el cual list1 pueda apuntar a nullptr lo cual significa que la lista aun estaria vacia
        if (colaAtencion.list1==nullptr) {
            nuevoNodo->siguiente=colaAtencion.inicio;
            colaAtencion.inicio=nuevoNodo;
            colaAtencion.list1=nuevoNodo;
        }else {
            nuevoNodo->siguiente=colaAtencion.list1->siguiente;
            colaAtencion.list1->siguiente=nuevoNodo;
            if (colaAtencion.list1==colaAtencion.fin) {
                colaAtencion.fin=nuevoNodo;
            }
            colaAtencion.list1=nuevoNodo;
        }
    }else {
        colaAtencion.fin->siguiente=nuevoNodo;
        colaAtencion.fin=nuevoNodo;
    }
    colaAtencion.longitud++;
}
void atenderUno(Cola &colaAtencion,ofstream &archRep) {
    if (colaAtencion.inicio==nullptr) {
        return;
    }
    NodoCola *sale=colaAtencion.inicio;

    archRep<<"Atendido: "<<sale->elemento.codigo<<" (P"<<sale->elemento.prioridad<<")"<<endl;
    bool eraLast1=false;
    if (sale==colaAtencion.list1) {
        eraLast1=true;
    }
    colaAtencion.inicio=colaAtencion.inicio->siguiente;
    if (colaAtencion.inicio==nullptr) {
        colaAtencion.fin=nullptr;
    }
    if (eraLast1) {
        colaAtencion.list1=nullptr;
    }

    colaAtencion.longitud--;

    delete sale;
}
void atender(Cola &colaAtencion,int k,ofstream &archRep) {
    for (int i=0;i<k;i++) {
        if (colaAtencion.inicio==nullptr) {
            return;
        }
        atenderUno(colaAtencion,archRep);
    }
}
void imprimir(Cola &colaAtencion,ofstream &archRep) {
    NodoCola *recorrido=colaAtencion.inicio;

    archRep<<"Estado: [P1:";

    bool primero = true;
    while (recorrido!=nullptr and recorrido->elemento.prioridad==1) {
        if (!primero) {
            archRep<<",";
        }
        archRep<<recorrido->elemento.codigo;
        primero=false;
        recorrido=recorrido->siguiente;
    }
    archRep<<"][P2:";
    primero=true;
    while (recorrido!=nullptr) {
        if (!primero) {
            archRep<<", ";
        }
        archRep<<recorrido->elemento.codigo;
        primero=false;
        recorrido=recorrido->siguiente;
    }
    archRep<<"]"<<endl;
}
int main() {
    Cola colaAtencion;

    construir(colaAtencion);

    ifstream arch("eventos.txt", ios::in);
    ofstream archRep("salida.txt", ios::out);

    char comando[20];
    while (arch>>comando) {
        if (strcmp(comando, "llegada") == 0) {
            int codigo;
            char tipo[20];
            arch>>codigo>>tipo;
            if (strcmp(tipo, "preferente") == 0) {
                encolarPreferente(colaAtencion,codigo,1);
            }else {
                encolarPreferente(colaAtencion,codigo,2);
            }
        }else if (strcmp(comando,"atender")==0){
            int k;
            arch>>k;
            atender(colaAtencion,k,archRep);
        }else if (strcmp(comando,"imprimir")==0) {
            imprimir(colaAtencion,archRep);
        }
    }
    return 0;
}
