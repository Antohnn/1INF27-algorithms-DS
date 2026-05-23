#include <iostream>
using namespace std;

struct NodoPila {
    int numero;
    NodoPila *siguiente;
};

struct Pila {
    NodoPila *cima;
    int longitud;
};

struct SistemaPilas {
    Pila principal;
    Pila minimos;
};

void construir(Pila &pila) {
    pila.cima = nullptr;
    pila.longitud = 0;
}

bool esPilaVacia(Pila pila) {
    return pila.cima == nullptr;
}

void apilar(Pila &pila, int numero) {
    /*
     Forma de solución:
     Se inserta un nuevo nodo en la cima de la pila.
     */

    NodoPila *nuevo = new NodoPila;
    nuevo->numero = numero;
    nuevo->siguiente = pila.cima;

    pila.cima = nuevo;
    pila.longitud++;
}

int desapilar(Pila &pila) {
    /*
     Forma de solución:
     Se elimina el nodo de la cima y se retorna su valor.
     */

    if (esPilaVacia(pila)) {
        return -1;
    }

    NodoPila *sale = pila.cima;
    int numero = sale->numero;

    pila.cima = pila.cima->siguiente;
    pila.longitud--;

    delete sale;

    return numero;
}

int cima(Pila pila) {
    if (esPilaVacia(pila)) {
        return -1;
    }

    return pila.cima->numero;
}

void construir(SistemaPilas &sistema) {
    construir(sistema.principal);
    construir(sistema.minimos);
}

void nuevoapilar(SistemaPilas &sistema, int numero) {
    /*
     Forma de solución:
     Se apila el lote en la pila principal.
     En la pila extra se guarda el mínimo actual. Si el nuevo lote
     es menor o igual al mínimo actual, también se apila en minimos.
     */

    apilar(sistema.principal, numero);

    if (esPilaVacia(sistema.minimos) || numero <= cima(sistema.minimos)) {
        apilar(sistema.minimos, numero);
    }
}

int nuevodesapilar(SistemaPilas &sistema) {
    /*
     Forma de solución:
     Se desapila de la pila principal.
     Si el valor retirado coincide con la cima de la pila de mínimos,
     también se desapila de la pila extra para mantener actualizado
     el mínimo.
     */

    if (esPilaVacia(sistema.principal)) {
        return -1;
    }

    int eliminado = desapilar(sistema.principal);

    if (!esPilaVacia(sistema.minimos) && eliminado == cima(sistema.minimos)) {
        desapilar(sistema.minimos);
    }

    return eliminado;
}

int minimo(SistemaPilas sistema) {
    /*
     Forma de solución:
     El mínimo valor de la pila principal siempre está en la cima
     de la pila auxiliar de mínimos.
     */

    return cima(sistema.minimos);
}

int main() {
    SistemaPilas sistema;
    construir(sistema);

    nuevoapilar(sistema, 201809);
    nuevoapilar(sistema, 202010);
    nuevoapilar(sistema, 202109);
    nuevoapilar(sistema, 201510);
    nuevoapilar(sistema, 202409);

    cout << "Minimo: " << minimo(sistema) << endl;

    nuevodesapilar(sistema);
    nuevodesapilar(sistema);

    cout << "Minimo: " << minimo(sistema) << endl;

    return 0;
}