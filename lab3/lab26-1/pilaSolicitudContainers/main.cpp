#include <iostream>

#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/Pila.h"

using namespace std;

bool cumplirSolicitud(const int containers[],const int solicitado[],int n) {
    Pila pila;
    construir(pila);

    int i=0;
    int j=0;
    while (j<n) {
        if (!esPilaVacia(pila) and cima(pila).numero==solicitado[j]) {
            desapilar(pila);
            j++;
        }else if (i<n){
            if (containers[i]==solicitado[j]) {
                i++;
                j++;
            }else {
                ElementoPila elemento{};
                elemento.numero=containers[i];
                apilar(pila,elemento);
                i++;
            }
        }else {
            return false;
        }
    }
    return true;
}

int main() {

    int containers[4]={1,2,3,4};
    int solicitado[4]={1,4,2,3};
    int n=4;

    if (cumplirSolicitud(containers,solicitado,n)) {
        cout<<"Cumple con la solicitud"<<endl;
    }else {
        cout<<"Cumple no con la solicitud"<<endl;
    }
    return 0;
}
