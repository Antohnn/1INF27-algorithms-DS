#include <iostream>
using namespace std;

struct NodoCola {
    double temperatura;
    NodoCola *siguiente;
};

struct ColaTemperaturas {
    NodoCola *inicio;
    NodoCola *fin;
    int cantidad;
    int k;
    double suma;
};

void construir(ColaTemperaturas &cola, int k) {
    cola.inicio = nullptr;
    cola.fin = nullptr;
    cola.cantidad = 0;
    cola.k = k;
    cola.suma = 0;
}

void agregarTemperatura(ColaTemperaturas &cola, double temperatura) {
    /*
     Forma de solución:
     Se usa una cola para guardar solo las últimas K temperaturas.
     Se mantiene una suma acumulada. Si la cola ya tiene K elementos,
     se elimina la temperatura más antigua y se resta de la suma.
    */

    if (cola.cantidad == cola.k) {
        NodoCola *sale = cola.inicio;
        cola.inicio = cola.inicio->siguiente;

        cola.suma -= sale->temperatura;
        delete sale;

        cola.cantidad--;

        if (cola.inicio == nullptr) {
            cola.fin = nullptr;
        }
    }

    NodoCola *nuevo = new NodoCola;
    nuevo->temperatura = temperatura;
    nuevo->siguiente = nullptr;

    if (cola.inicio == nullptr) {
        cola.inicio = nuevo;
        cola.fin = nuevo;
    } else {
        cola.fin->siguiente = nuevo;
        cola.fin = nuevo;
    }

    cola.suma += temperatura;
    cola.cantidad++;
}

double calcularPromedio(ColaTemperaturas cola) {
    /*
     Forma de solución:
     Como se mantiene la suma acumulada de las temperaturas almacenadas,
     el promedio se calcula directamente sin recorrer la cola.
    */

    if (cola.cantidad == 0) {
        return 0;
    }

    return cola.suma / cola.cantidad;
}

int main() {
    int k;
    double temperatura;

    cout << "Ingrese K: ";
    cin >> k;

    ColaTemperaturas cola;
    construir(cola, k);

    while (true) {
        cout << "Ingrese Temperatura: ";
        cin >> temperatura;

        if (temperatura == -1) {
            break;
        }

        agregarTemperatura(cola, temperatura);

        cout << "Promedio: " << calcularPromedio(cola) << endl;
    }

    cout << "FIN" << endl;

    return 0;
}
