#include <iostream>

#include "Bibliotecas/BibliotecaCola/ElementoCola.h"
#include "Bibliotecas/BibliotecaCola/funcionesCola.h"
#include "Bibliotecas/BibliotecaCola/Cola.h"
using namespace std;

void rotarCola(Cola &cola,int k) {
    if (k==0) {
        return;
    }

    ElementoCola ele=desencolar(cola);
    rotarCola(cola,k-1);
    encolar(cola,ele);
}
void insertarElementoRestantes(Cola &cola,int longRestante) {
    int longitud=1;
    while (longitud<=longRestante) {
        ElementoCola ele=desencolar(cola);
        encolar(cola,ele);
        longitud++;
    }
}
int main() {
    Cola cola;
    construir(cola);

    ElementoCola ele{};
    ele.num=1;
    encolar(cola,ele);

    ele.num=2;
    encolar(cola,ele);

    ele.num=3;
    encolar(cola,ele);

    ele.num=4;
    encolar(cola,ele);

    ele.num=5;
    encolar(cola,ele);

    cout<<cola.longitud<<endl;

    int k=3;

    imprimir(cola);
    rotarCola(cola,k);
    imprimir(cola);
    insertarElementoRestantes(cola,cola.longitud-k);
    imprimir(cola);

    return 0;
}
