#include <iostream>

using namespace std;
#include "Bibliotecas/funcionesLista.h"
#include "Bibliotecas/ElementoLista.h"
#include "Bibliotecas/Lista.h"
#include "Bibliotecas/NodoLista.h"

void ordenarLista(Lista &listaCuadrigas) {
    //defino los punteros para manejar mis "listas" de pares e impares
    NodoLista *iniPares=nullptr;
    NodoLista *finPares=nullptr;
    NodoLista *iniImpares=nullptr;
    NodoLista *finImpares=nullptr;
    //puntero para recorrer la lista
    NodoLista *recorrido=listaCuadrigas.inicio;
    //recorro la lista
    while (recorrido) {
        //defino un siguiente para tener un mejor manejo en este caso no es necesario
        // NodoLista *siguiente=recorrido->siguiente;
        //como se va a insertar en la lista par o impar segun encuentro no es necesario manejar anterior o siguiente
        //por lo que puedo desvincular el nodo segun lo encuentro
        //se desvincula el nodo actual de la lista
        NodoLista *siguiente=recorrido->siguiente;
        recorrido->siguiente=nullptr;
        //valido si el id es par
        if (recorrido->elemento.id % 2==0) {
            //si es par y no entro ningun par con aterioridad se incia la "lista" de pares
            if (iniPares==nullptr) {
                iniPares=recorrido;
                finPares=recorrido;
            }else {
                //si ya habia algun par guardado se maneja el puntero finPares para apuntar al dato anterior al actual
                // y se actualiza el pu
                finPares->siguiente=recorrido;
                finPares=recorrido;
            }
        }else {
            if (iniImpares==nullptr) {
                iniImpares=recorrido;
                finImpares=recorrido;
            }else {
                finImpares->siguiente=recorrido;
                finImpares=recorrido;
            }

        }
        recorrido=siguiente;
    }
    if (iniPares==nullptr) {
        listaCuadrigas.inicio=iniImpares;
    }else {
        listaCuadrigas.inicio=iniPares;
        finPares->siguiente=iniImpares;
    }
}
int main() {

    struct ElementoLista elemento{};
    struct Lista listaCuadrigas;
    int n;
    construir(listaCuadrigas);
    // cout<<"Inserte el numero de cuadrigas en la competencia: "<<endl;
    // cin>>n;
    // cout<<"Inserte las cuadrigas (id,nombre,equipo): "<<endl;
    // for (int i=0;i<n;i++) {
    //     cin>>elemento.id;
    //     cin.ignore();
    //     cin.getline(elemento.nombre,50,',');
    //     cin.getline(elemento.equipo,50);
    //     insertarAlFinal(listaCuadrigas,elemento);
    // }
    // imprimir(listaCuadrigas);

    elemento={0,17,"Messala","Rojo"};
    insertarAlFinal(listaCuadrigas, elemento);
    elemento={0,4,"Ben-Hur","Azul"};
    insertarAlFinal(listaCuadrigas, elemento);
    elemento={0,12,"Artax","Verde"};
    insertarAlFinal(listaCuadrigas, elemento);
    elemento={0,7,"Drusus","Negro"};
    insertarAlFinal(listaCuadrigas, elemento);

    //imprimir(listaCuadrigas);

    ordenarLista(listaCuadrigas);
    imprimir(listaCuadrigas);


    return 0;
}
