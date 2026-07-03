//
// Created by ANTONIO on 2/07/2026.
//
#include "estructuras.h"
#include "FuncionesCola.h"
#include "FuncionesArbol.h"

NodoArbol *crearNodo(const char *titulo, int relevancia) {
    NodoArbol *nuevo = new NodoArbol;

    strcpy(nuevo->elemento.titulo, titulo);
    nuevo->elemento.relevancia = relevancia;

    nuevo->izquierda = nullptr;
    nuevo->derecha = nullptr;

    return nuevo;
}

void construirArbol(Arbol &arbol) {
    /*
     Forma de solucion:
     Se construye directamente el árbol binario descrito en el enunciado,
     conectando manualmente cada capítulo o sección en la posición indicada.
     Cada vez que se crea un nodo, se incrementa el tamaño del árbol.
    */

    arbol.raiz = crearNodo("Titulo", 7);
    arbol.tamanio = 1;

    arbol.raiz->izquierda = crearNodo("Capitulo1", 8);
    arbol.tamanio++;

    arbol.raiz->derecha = crearNodo("Capitulo2", 5);
    arbol.tamanio++;

    arbol.raiz->izquierda->izquierda = crearNodo("Seccion1.1", 6);
    arbol.tamanio++;

    arbol.raiz->izquierda->derecha = crearNodo("Principal", 10);
    arbol.tamanio++;

    arbol.raiz->derecha->izquierda = crearNodo("Seccion2.1", 3);
    arbol.tamanio++;

    arbol.raiz->derecha->derecha = crearNodo("Seccion2.2", 4);
    arbol.tamanio++;

    arbol.raiz->izquierda->izquierda->izquierda = crearNodo("Seccion1.1.1", 4);
    arbol.tamanio++;

    arbol.raiz->izquierda->izquierda->derecha = crearNodo("Seccion1.1.2", 2);
    arbol.tamanio++;
}
int buscarPrincipalBFS(NodoArbol *raiz) {
    /*
     Forma de solucion:
     Se recorre el árbol en amplitud usando una cola. Cada elemento de la cola
     guarda el puntero al nodo y su nivel. Así se puede imprimir el árbol por
     niveles y detectar en qué nivel se encuentra el capítulo Principal.
    */

    if (raiz == nullptr) return -1;

    Cola cola;
    construirCola(cola);

    encolar(cola, raiz, 0);

    int nivelActual = 0;
    int nivelPrincipal = -1;

    while (!esColaVacia(cola)) {
        ElementoCola elemento = desencolar(cola);

        NodoArbol *actual = elemento.nodo;
        int nivel = elemento.nivel;

        if (nivel != nivelActual) {
            cout << endl;
            nivelActual = nivel;
        }

        cout << actual->elemento.titulo << " "
             << actual->elemento.relevancia << ", ";

        if (strcmp(actual->elemento.titulo, "Principal") == 0 &&
            actual->elemento.relevancia == 10) {
            nivelPrincipal = nivel;
            }

        if (actual->izquierda != nullptr) {
            encolar(cola, actual->izquierda, nivel + 1);
        }

        if (actual->derecha != nullptr) {
            encolar(cola, actual->derecha, nivel + 1);
        }
    }

    cout << endl;

    return nivelPrincipal;
}
void eliminarSubarbol(NodoArbol *&raiz, int &tamanio) {
    /*
     Forma de solucion:
     Se elimina el subárbol usando postorden. Primero se eliminan los hijos
     izquierdo y derecho, y finalmente el nodo actual. Por cada nodo borrado
     se actualiza el tamaño total del árbol.
    */

    if (raiz == nullptr) return;

    eliminarSubarbol(raiz->izquierda, tamanio);
    eliminarSubarbol(raiz->derecha, tamanio);

    delete raiz;
    raiz = nullptr;
    tamanio--;
}
void removerParte(Arbol &arbol, NodoArbol *nodo, char lado) {
    /*
     Forma de solucion:
     Desde el nodo indicado se elimina su subárbol izquierdo o derecho,
     dependiendo del lado recibido. La eliminación actualiza el tamaño
     del árbol automáticamente.
    */

    if (nodo == nullptr) return;

    if (lado == 'I') {
        eliminarSubarbol(nodo->izquierda, arbol.tamanio);
    } else if (lado == 'D') {
        eliminarSubarbol(nodo->derecha, arbol.tamanio);
    }
}