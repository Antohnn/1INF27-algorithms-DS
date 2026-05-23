#include <cstring>
#include <iostream>

using namespace std;

#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/NodoLista.h"

void desconectarNodo(Lista &listaProd,NodoLista *&anterior,NodoLista *&siguiente) {
    if (anterior==nullptr) {
        listaProd.inicio=siguiente;
    }else {
        anterior->siguiente=siguiente;
    }
}
void guardarNodoEnOrdenado(NodoLista *&ordenado,NodoLista *&recorrido) {
    if (ordenado==nullptr) {
        ordenado=recorrido;
    }else {
        NodoLista *aux=ordenado;
        while (aux->siguiente!=nullptr) {
            aux=aux->siguiente;
        }
        aux->siguiente=recorrido;
    }
}
char cambiarTipo(char &tipoBuscado) {
    if (tipoBuscado=='A') tipoBuscado='B';
    else if (tipoBuscado=='B')tipoBuscado='C';
    else if (tipoBuscado=='C')tipoBuscado='A';
    return tipoBuscado;
}
void reordenarLista(Lista &listaProd) {
    //necesitamos encontrar las letras en orden y si son econtradas extraerlas de la lista y guardarlas en un puntero
    //auxiliar¿Como se logra esto? Recorriendo la lista de manera que encuentre el nodo y extraiga para esto necesitamos
    // que la lista se recorra desde el inicio despues de una extraccion por lo que vamos a recorrer la lista mientras
    // el puntero inicio de la lista sea diferente de nullptr osea que no este vacia digamos.

    //definimos nuestro puntero auxiliar en el cual vamos a "almacenar" nuestros nodos
    NodoLista *ordenado=nullptr;
    //definimos tambien la letra a buscar
    char tipoBuscado='A';
    while (listaProd.inicio!=nullptr) {
        //recorremos la lista en busqueda del elemento buscado
        NodoLista *recorrido=listaProd.inicio;
        NodoLista *anterior=nullptr;
        //hacemos un while de busqueda basicamente que nos devuelve el anterior al nodo encontrado para poder modificar
        // la lista de manera adecuada
        while (recorrido!=nullptr and recorrido->elemento.tipoProd!=tipoBuscado) {
            anterior=recorrido;
            recorrido=recorrido->siguiente;
        }
        //una vez encontrado procedemos a quitar el nodo encontrado de la lista
        if (recorrido!=nullptr) {
            NodoLista *siguiente=recorrido->siguiente;
            //se desconecta el nodo de la listaProd
            desconectarNodo(listaProd,anterior,siguiente);
            //se hace que el nodo encontrado apunte a  nullptr
            recorrido->siguiente=nullptr;
            //se "almacena" el nodo en el puntero ordenado
            guardarNodoEnOrdenado(ordenado,recorrido);
        }
        tipoBuscado=cambiarTipo(tipoBuscado);
    }
    listaProd.inicio=ordenado;
}
int main() {

    Lista listaProd;

    construir(listaProd);

    ElementoLista dato{};

    dato={3,'C'};
    insertarAlFinal(listaProd, dato);
    dato={9,'A'};
    insertarAlFinal(listaProd, dato);
    dato={8,'C'};
    insertarAlFinal(listaProd, dato);
    dato={4,'A'};
    insertarAlFinal(listaProd, dato);


    reordenarLista(listaProd);

    imprimir(listaProd);

    return 0;
}
