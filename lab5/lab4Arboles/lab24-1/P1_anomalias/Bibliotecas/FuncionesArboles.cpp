//
// Created by ANTONIO on 2/07/2026.
//

#include "estructuras.h"
#include "FuncionesArboles.h"

NodoArbol *crearNodo(int dato) {
    NodoArbol *nuevo = new NodoArbol;

    nuevo->dato = dato;
    nuevo->izquierda = nullptr;
    nuevo->derecha = nullptr;

    return nuevo;
}
void insertarABB(NodoArbol *&raiz, int dato) {
    if (raiz == nullptr) {
        raiz = crearNodo(dato);
        return;
    }

    if (dato < raiz->dato) {
        insertarABB(raiz->izquierda, dato);
    } else if (dato > raiz->dato) {
        insertarABB(raiz->derecha, dato);
    }
}
void construirArbolSistema(Arbol &arbol) {
    arbol.raiz = crearNodo(1);

    arbol.raiz->izquierda = crearNodo(7);
    arbol.raiz->derecha = crearNodo(8);

    arbol.raiz->izquierda->izquierda = crearNodo(2);
    arbol.raiz->izquierda->derecha = crearNodo(3);
}
int contarNodos(NodoArbol *raiz) {
    if (raiz == nullptr) return 0;

    return 1 +
           contarNodos(raiz->izquierda) +
           contarNodos(raiz->derecha);
}
int contarHojas(NodoArbol *raiz) {
    if (raiz == nullptr) return 0;

    if (raiz->izquierda == nullptr && raiz->derecha == nullptr) {
        return 1;
    }

    return contarHojas(raiz->izquierda) +
           contarHojas(raiz->derecha);
}
NodoArbol *aplicar_arbol(NodoArbol *paquetes, NodoArbol *sistema) {
    /*
     Forma de solucion:
     Se recorren ambos árboles en paralelo. La forma del árbol resultado
     sigue la estructura del árbol de paquetes. Para cada nodo de paquetes
     se calcula el nuevo valor sumando la cantidad de nodos del subárbol
     correspondiente de sistema y restando la cantidad de hojas de dicho
     subárbol.
    */

    if (paquetes == nullptr) {
        return nullptr;
    }

    int nodosSistema = contarNodos(sistema);
    int hojasSistema = contarHojas(sistema);

    int nuevoDato = paquetes->dato + nodosSistema - hojasSistema;

    NodoArbol *resultado = crearNodo(nuevoDato);

    NodoArbol *sistemaIzq = nullptr;
    NodoArbol *sistemaDer = nullptr;

    if (sistema != nullptr) {
        sistemaIzq = sistema->izquierda;
        sistemaDer = sistema->derecha;
    }

    resultado->izquierda = aplicar_arbol(paquetes->izquierda, sistemaIzq);
    resultado->derecha = aplicar_arbol(paquetes->derecha, sistemaDer);

    return resultado;
}
bool esABB(NodoArbol *raiz, int minimo, int maximo) {
    if (raiz == nullptr) return true;

    if (raiz->dato <= minimo || raiz->dato >= maximo) {
        return false;
    }

    return esABB(raiz->izquierda, minimo, raiz->dato) &&
           esABB(raiz->derecha, raiz->dato, maximo);
}
int sumarNodos(NodoArbol *raiz) {
    if (raiz == nullptr) return 0;

    return raiz->dato +
           sumarNodos(raiz->izquierda) +
           sumarNodos(raiz->derecha);
}
bool determinar_anomalia(NodoArbol *resultado) {
    /*
     Forma de solucion:
     Se verifica si el árbol resultado cumple dos condiciones:
     primero, que sea un ABB; segundo, que la suma de todos sus nodos sea par.
     Si alguna condición falla, se considera anomalía.
    */

    bool cumpleABB = esABB(resultado, INT_MIN, INT_MAX);
    int suma = sumarNodos(resultado);

    if (cumpleABB && suma % 2 == 0) {
        return false; // no hay anomalía
    }

    return true; // hay anomalía
}
void imprimirEnOrden(NodoArbol *raiz) {
    if (raiz == nullptr) return;

    imprimirEnOrden(raiz->izquierda);
    cout << raiz->dato << " ";
    imprimirEnOrden(raiz->derecha);
}