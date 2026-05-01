#include <iostream>

using namespace std;
#include "Bibliotecas/Elemento.h"
#include "Bibliotecas/Nodo.h"
#include "Bibliotecas/FuncionesAuxiliares.h"
#include "Bibliotecas/Lista.h"

int main() {
    struct Elemento elemento{};
    struct Lista listaInicio,listaFin,listaOrdenada;

    construirLista(listaInicio);
    construirLista(listaFin);
    construirLista(listaOrdenada);

    if (esListaVacia(listaInicio)) {
        cout<<"La listaInicio esta vacia"<<endl;
    }


    for (int i=0;i<10;i++) {
        elemento.dni=i;
        insertarAlInicio(listaInicio,elemento);
    }
    imprimir(listaInicio);

    cout<<endl;

    for (int i=0;i<10;i++) {
        elemento.dni=i+10;
        isertarAlFinal(listaFin,elemento);
    }
    imprimir(listaFin);

    elemento.dni=12;
    insertarEnOrden(listaOrdenada,elemento);
    elemento.dni=35;
    insertarEnOrden(listaOrdenada,elemento);
    elemento.dni=7;
    insertarEnOrden(listaOrdenada,elemento);

    cout<<endl;
    imprimir(listaOrdenada);

    elemento.dni=35;
    eliminaNodo(listaOrdenada,elemento);
    cout<<endl;
    imprimir(listaOrdenada);

    return 0;
}
