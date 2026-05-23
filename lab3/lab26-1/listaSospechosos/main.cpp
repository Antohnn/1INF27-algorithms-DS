#include <iostream>

#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"

using namespace std;

void llenarLista(Lista &listaIntentos) {
    ElementoLista elemento{};

    elemento={410};
    insertarAlFinal(listaIntentos,elemento);
    elemento={102};
    insertarAlFinal(listaIntentos,elemento);
    elemento={205};
    insertarAlFinal(listaIntentos,elemento);
    elemento={102};
    insertarAlFinal(listaIntentos,elemento);
    elemento={205};
    insertarAlFinal(listaIntentos,elemento);
    elemento={330};
    insertarAlFinal(listaIntentos,elemento);
    elemento={102};
    insertarAlFinal(listaIntentos,elemento);
    elemento={205};
    insertarAlFinal(listaIntentos,elemento);
    elemento={410};
    insertarAlFinal(listaIntentos,elemento);
    elemento={205};
    insertarAlFinal(listaIntentos,elemento);
    elemento={777};
    insertarAlFinal(listaIntentos,elemento);
}
bool yaEstaba(Lista &listaIntentos,NodoLista *nodoActual) {
    NodoLista *recorrido=listaIntentos.inicio;
    while (recorrido!=nullptr and recorrido!=nodoActual) {
        if (recorrido->elemento.codigo==nodoActual->elemento.codigo) {
            return true;
        }
        recorrido=recorrido->siguiente;
    }
    return false;
}
int contarIntentos(Lista &listaIntentos,NodoLista *nodoActual) {
    //para contar los intentos necesitamos recorrer la lista nuevamente e ir contado segun coincida nada mas
    NodoLista *recorrido=listaIntentos.inicio;
    int contador=0;
    while (recorrido!=nullptr) {
        if (recorrido->elemento.codigo==nodoActual->elemento.codigo) {
            contador++;
        }
        recorrido=recorrido->siguiente;
    }
    return contador;
}
void desconectarNodo(Lista &listaIntentos,NodoLista *&siguiente,NodoLista *&anterior) {
    if (anterior==nullptr) {
        listaIntentos.inicio=siguiente;
    }else {
        anterior->siguiente=siguiente;
    }
}
void insertarNodoAlFinal(Lista &listaSospechosos,NodoLista *&nodo) {

    NodoLista *recorrido=listaSospechosos.inicio;
    bool yaEstaEnLista=false;
    while (recorrido!=nullptr) {
        if (recorrido->elemento.codigo==nodo->elemento.codigo) {
            yaEstaEnLista=true;
            break;
        }
        recorrido=recorrido->siguiente;
    }
    if (!yaEstaEnLista) {
        if (listaSospechosos.inicio==nullptr) {
            listaSospechosos.inicio=nodo;
        }else {
            NodoLista *aux=listaSospechosos.inicio;
            while (aux->siguiente!=nullptr) {
                aux=aux->siguiente;
            }
            aux->siguiente=nodo;
        }
        listaSospechosos.longitud++;
    }
}
void extraeNodoEIngresarALista(Lista &listaIntentos,NodoLista *&nodoActual,Lista &listaSospechosos) {
    int codBuscado=nodoActual->elemento.codigo;
    NodoLista *recorrido=listaIntentos.inicio;
    NodoLista *anterior=nullptr;
    while (recorrido!=nullptr) {
        NodoLista *siguiente=recorrido->siguiente;
        if (recorrido->elemento.codigo==codBuscado) {
            desconectarNodo(listaIntentos,siguiente,anterior);
            recorrido->siguiente=nullptr;
            listaIntentos.longitud--;

            insertarNodoAlFinal(listaSospechosos,recorrido);
        }else {
            anterior=recorrido;
        }
        recorrido=siguiente;
    }
}
void hallarSospechosos(Lista &listaIntentos,Lista &listaSospechosos) {
    NodoLista *recorrido=listaIntentos.inicio;
    //para este problema se necesita recorrer dos veces la lista por cada elemento ya que es necesario verificar que el
    //elemento pasado no haya salido antes
    while (recorrido!=nullptr) {
        NodoLista *siguiente=recorrido->siguiente;
        //se recorre la lista de nuevo comparando al elemento actual para ver si ya se habia encontrado con anterioridad
        // bool yaEsta=false;
        // NodoLista *recorridoDeNuevo=listaIntentos.inicio;
        // while (recorridoDeNuevo!=nullptr and recorrido!=recorridoDeNuevo) {
        //     if (recorridoDeNuevo->elemento.codigo==recorrido->elemento.codigo) {
        //         yaEstaba=true;
        //         break;
        //     }
        //     recorridoDeNuevo=recorridoDeNuevo->siguiente;
        // }
        //si el elemento no se habia contado con aterioridad entonces se procede a contar
        if (!yaEstaba(listaIntentos,recorrido)) {
            int contador=contarIntentos(listaIntentos,recorrido);
            // NodoLista *recorridoAgain=listaIntentos.inicio;
            // while (recorridoAgain!=nullptr) {
            //     if (recorridoAgain->elemento.codigo==recorrido->elemento.codigo) {
            //         contador++;
            //     }
            //     recorridoAgain=recorridoAgain->siguiente;
            // }
            // cout<<recorrido->elemento.codigo<<" esta "<<contador<<endl;
            if (contador>=3) {
                extraeNodoEIngresarALista(listaIntentos,recorrido,listaSospechosos);
            }
        }
        recorrido=siguiente;
    }
}
int main() {

    Lista listaIntentos,listaSospechosos;

    construir(listaIntentos);
    construir(listaSospechosos);

    llenarLista(listaIntentos);
    hallarSospechosos(listaIntentos,listaSospechosos);

    imprimir(listaIntentos);

    imprimir(listaSospechosos);
    return 0;
}
