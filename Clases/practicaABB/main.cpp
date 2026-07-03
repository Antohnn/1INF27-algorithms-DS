#include <iostream>

#include "Bibliotecas/FuncionesArbolBinario.h"
#include "Bibliotecas/NodoArbolBinario.h"


int main() {

    NodoArbolBinario *raiz = nullptr;
    ElementoNodo elemento{};

    elemento.dato = 10;
    insertarAbb(raiz, elemento);

    elemento.dato = 6;
    insertarAbb(raiz, elemento);

    elemento.dato = 15;
    insertarAbb(raiz, elemento);

    elemento.dato = 3;
    insertarAbb(raiz, elemento);

    elemento.dato = 8;
    insertarAbb(raiz, elemento);

    elemento.dato = 20;
    insertarAbb(raiz, elemento);

    elemento.dato = 7;
    insertarAbb(raiz, elemento);

    cout<<"En orden: "<<endl;
    enOrden(raiz);
    cout<<endl;

    NodoArbolBinario *raiz1 = nullptr;
    ElementoNodo elemento1{};

    elemento1.dato = 12;
    insertarAbb(raiz1, elemento1);

    elemento1.dato = 5;
    insertarAbb(raiz1, elemento1);

    elemento1.dato = 18;
    insertarAbb(raiz1, elemento1);

    elemento1.dato = 2;
    insertarAbb(raiz1, elemento1);

    elemento1.dato = 9;
    insertarAbb(raiz1, elemento1);

    elemento1.dato = 15;
    insertarAbb(raiz1, elemento1);

    elemento1.dato = 25;
    insertarAbb(raiz1, elemento1);

    elemento1.dato = 7;
    insertarAbb(raiz1, elemento1);

    cout<<"En orden: "<<endl;
    enOrden(raiz1);
    cout<<endl;

    elemento1.dato = 15;

    if (buscarAbb(raiz1, elemento1)) {
        cout << "Encontrado" << endl;
    } else {
        cout << "No encontrado" << endl;
    }

    return 0;
}
