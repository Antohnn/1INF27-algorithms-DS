#include <iostream>

using namespace std;

#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/ElementoPila.h"
#include "BibliotecaPila/NodoPila.h"
bool puedoMover(Pila &origen,Pila &destino) {
    if (esPilaVacia(origen)) return false;
    if (esPilaVacia(destino)) return true;

    int pesoOrigen=origen.inicio->elemento.numero;
    int pesoDestino=destino.inicio->elemento.numero;

    return pesoOrigen<=pesoDestino;
}
void moverCima(Pila &origen,Pila &destino) {
    if (!puedoMover(origen,destino)) {
        cout<<"Movimiento invalido "<<endl;
        return;
    }

    NodoPila *cima=origen.inicio;

    origen.inicio=origen.inicio->siguiente;
    origen.longitud--;

    cima->siguiente=destino.inicio;
    destino.inicio=cima;
    destino.longitud++;
}
void moverTorre(int n,Pila &origen,Pila& destino,Pila &auxiliar) {
    if (n==0)return;
    moverTorre(n-1,origen,auxiliar,destino);
    moverCima(origen,destino);
    moverTorre(n-1,auxiliar,destino,origen);
}
int fondo(Pila &pila) {
    NodoPila *recorrido=pila.inicio;
    while (recorrido->siguiente!=nullptr) {
        recorrido=recorrido->siguiente;
    }
    return recorrido->elemento.numero;
}
void fusionarPilas(Pila &pilaA,Pila &pilaB,Pila &pilaC,Pila &auxiliar) {
    if (esPilaVacia(pilaA) and esPilaVacia(pilaB)) {
        return;
    }
    if (esPilaVacia(pilaA)) {
        moverTorre(pilaB.longitud,pilaB,pilaC,auxiliar);
        return;
    }
    if (esPilaVacia(pilaB)) {
        moverTorre(pilaA.longitud,pilaA,pilaC,auxiliar);
        return;
    }

    int fondoA=fondo(pilaA);
    int fondoB=fondo(pilaB);

    if (fondoA>=fondoB) {
        moverTorre(pilaA.longitud-1,pilaA,auxiliar,pilaC);
        moverCima(pilaA,pilaC);

        fusionarPilas(pilaB,auxiliar,pilaC,pilaA);
    }else {
        moverTorre(pilaB.longitud-1,pilaB,auxiliar,pilaC);
        moverCima(pilaB,pilaC);

        fusionarPilas(pilaA,auxiliar,pilaC,pilaB);
    }

}
int main() {

    Pila pilaA,pilaB,pilaC;
    ElementoPila elemento{};

    construir(pilaA);
    construir(pilaB);
    construir(pilaC);
    Pila auxiliar;
    construir(auxiliar);

    elemento={20};
    apilar(pilaA,elemento);
    elemento={15};
    apilar(pilaA,elemento);
    elemento={5};
    apilar(pilaA,elemento);

    elemento={18};
    apilar(pilaB,elemento);
    elemento={12};
    apilar(pilaB,elemento);
    elemento={10};
    apilar(pilaB,elemento);
    elemento={2};
    apilar(pilaB,elemento);

    imprimir(pilaA);
    cout<<endl;
    imprimir(pilaB);

    fusionarPilas(pilaA,pilaB,pilaC,auxiliar);

    imprimir(pilaC);

    return 0;
}
