#include <iostream>



using namespace std;

#include "Bibliotecas/Pila.h"
#include "Bibliotecas/funcionesPila.h"

bool esMayor(ElementoPila a,ElementoPila b) {
    if (a.grado>b.grado) return true;
    if (a.grado==b.grado and a.tiempo>b.tiempo) return true;
    return false;
}

void resolver(ElementoPila datos[],int n) {
    Pila pila;
    construir(pila);

    int limite[100];

    for (int i = n-1; i >= 0; i--) {
        while (!esPilaVacia(pila) and esMayor(datos[i],datos[pila.inicio->elemento.efectivo])) {
            desapilar(pila);
        }

        if (esPilaVacia(pila)) {
            limite[i]=n;
        }else {
            limite[i]=pila.inicio->elemento.efectivo;
        }

        ElementoPila elemento{};
        elemento.efectivo=i;
        elemento.grado=0;
        elemento.tiempo=0;
        apilar(pila,elemento);
    }
    int total = 0;

    cout << "Agrupaciones:" << endl;

    for (int tam = 1; tam <= n; tam++) {
        for (int i = 0; i + tam <= n; i++) {
            int j = i + tam - 1;

            if (j < limite[i]) {
                cout << "{";

                for (int k = i; k <= j; k++) {
                    cout << datos[k].efectivo;
                    if (k < j) cout << ",";
                }

                cout << "}" << endl;
                total++;
            }
        }
    }

    cout << "Cantidad de agrupaciones: " << total << endl;
}
int main() {
    ElementoPila datos[]={
        {1,3,1},
        {2,2,1},
        {3,2,4},
    };

    int n=3;

    resolver(datos,n);
    return 0;
}
