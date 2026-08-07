#include <iostream>
using namespace std;

struct NodoPila {
    int indice;
    NodoPila *siguiente;
};

struct Pila {
    NodoPila *cima;
};

void construirPila(Pila &pila) {
    pila.cima = nullptr;
}

bool esPilaVacia(Pila pila) {
    return pila.cima == nullptr;
}

void apilar(Pila &pila, int indice) {
    NodoPila *nuevo = new NodoPila;
    nuevo->indice = indice;
    nuevo->siguiente = pila.cima;
    pila.cima = nuevo;
}

int desapilar(Pila &pila) {
    if (esPilaVacia(pila)) return -1;

    NodoPila *aux = pila.cima;
    int indice = aux->indice;

    pila.cima = pila.cima->siguiente;

    delete aux;

    return indice;
}

int verCima(Pila pila) {
    if (esPilaVacia(pila)) return -1;
    return pila.cima->indice;
}

int minimo(int a, int b) {
    if (a < b) return a;
    else return b;
}

int calcularSemillas(int arr[], int n) {
    /*
     Forma de solucion:
     Se recorre el arreglo una sola vez usando una pila auxiliar de indices.
     La pila mantiene barras pendientes de cerrar un recipiente.
     Cuando la barra actual es mayor que la barra en la cima, se desencadena
     el calculo del agua/semillas atrapadas usando una pared izquierda,
     una base y una pared derecha.
     Complejidad: O(n), porque cada indice entra y sale de la pila a lo mucho una vez.
    */

    Pila pila;
    construirPila(pila);

    int total = 0;

    for (int i = 0; i < n; i++) {

        while (!esPilaVacia(pila) && arr[i] > arr[verCima(pila)]) {
            int fondo = desapilar(pila);

            if (esPilaVacia(pila)) {
                break;
            }

            int izquierda = verCima(pila);

            int distancia = i - izquierda - 1;

            int alturaLimitante = minimo(arr[izquierda], arr[i]);

            int alturaSemillas = alturaLimitante - arr[fondo];

            total += distancia * alturaSemillas;
        }

        apilar(pila, i);
    }

    return total;
}

int main() {
    int arr[] = {3, 1, 5, 3, 1, 0, 4};
    int n = 7;

    int semillas = calcularSemillas(arr, n);

    cout << "Cantidad maxima de semillas: " << semillas << endl;

    return 0;
}
