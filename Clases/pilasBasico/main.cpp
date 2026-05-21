#include <iostream>

using namespace std;

#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/ElementoPila.h"
#include "BibliotecaPila/NodoPila.h"

int main() {

    Pila pila1,pila2;

    construir(pila1);
    construir(pila2);

    apilar(pila1,{1,9});
    apilar(pila1,{2,9});
    apilar(pila1,{5,9});
    apilar(pila1,{8,9});
    apilar(pila1,{7,9});

    while (!esPilaVacia(pila1)) {
        ElementoPila valor=desapilar(pila1);
        int n=0;
        while (!esPilaVacia(pila1)) {
            apilar(pila2,valor);
            valor=desapilar(pila1);
            n++;
        }
        while (!esPilaVacia(pila2) and n>0) {
            ElementoPila aux=desapilar(pila2);
            apilar(pila1,aux);
            n--;
        }
    }

    return 0;
}
