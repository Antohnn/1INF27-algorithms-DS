#include <iostream>
using namespace std;

struct Pedido {
    int codigo;
    int cantidad;
    char prioridad;
};

struct Nodo {
    Pedido pedido;
    Nodo *siguiente;
};

struct Lista {
    Nodo *inicio;
    int longitud;
};

void construir(Lista &lista) {
    lista.inicio = nullptr;
    lista.longitud = 0;
}

void insertarAlFinal(Lista &lista, Pedido pedido) {
    Nodo *nuevo = new Nodo;
    nuevo->pedido = pedido;
    nuevo->siguiente = nullptr;

    if (lista.inicio == nullptr) {
        lista.inicio = nuevo;
    } else {
        Nodo *rec = lista.inicio;
        while (rec->siguiente != nullptr) {
            rec = rec->siguiente;
        }
        rec->siguiente = nuevo;
    }

    lista.longitud++;
}

void agregarNodoAlFinal(Nodo *&ini, Nodo *&fin, Nodo *nodo) {
    nodo->siguiente = nullptr;

    if (ini == nullptr) {
        ini = nodo;
        fin = nodo;
    } else {
        fin->siguiente = nodo;
        fin = nodo;
    }
}

void agregarCadenaAlFinal(Nodo *&ini, Nodo *&fin, Nodo *iniCadena, Nodo *finCadena) {
    if (iniCadena == nullptr) return;

    if (ini == nullptr) {
        ini = iniCadena;
        fin = finCadena;
    } else {
        fin->siguiente = iniCadena;
        fin = finCadena;
    }
}

void unirListas(Lista &lista,
                Nodo *iniA, Nodo *finA,
                Nodo *iniGrupo, Nodo *finGrupo,
                Nodo *iniAislado, Nodo *finAislado) {
    /*
     Forma de solución:
     Se unen las tres zonas ya formadas usando los mismos nodos:
     primero A, luego grupos B/C, finalmente aislados.
    */

    Nodo *nuevoInicio = nullptr;
    Nodo *nuevoFin = nullptr;

    agregarCadenaAlFinal(nuevoInicio, nuevoFin, iniA, finA);
    agregarCadenaAlFinal(nuevoInicio, nuevoFin, iniGrupo, finGrupo);
    agregarCadenaAlFinal(nuevoInicio, nuevoFin, iniAislado, finAislado);

    lista.inicio = nuevoInicio;
}

void reordenarLista(Lista &lista) {
    /*
     Forma de solución:
     Se recorre la lista original una sola vez.
     Los nodos A se mandan a la primera zona.
     Las secuencias consecutivas B o C de tamaño 2 o más se mandan a la segunda zona.
     Los B o C aislados se mandan a la zona final.
     No se crean nodos nuevos, solo se desconectan y reconectan punteros.
    */

    Nodo *iniA = nullptr, *finA = nullptr;
    Nodo *iniGrupo = nullptr, *finGrupo = nullptr;
    Nodo *iniAislado = nullptr, *finAislado = nullptr;

    Nodo *actual = lista.inicio;

    while (actual != nullptr) {
        if (actual->pedido.prioridad == 'A') {
            Nodo *siguiente = actual->siguiente;
            actual->siguiente = nullptr;

            agregarNodoAlFinal(iniA, finA, actual);

            actual = siguiente;
        } else {
            char tipo = actual->pedido.prioridad;

            Nodo *iniRun = actual;
            Nodo *finRun = actual;
            int contador = 1;

            Nodo *siguiente = actual->siguiente;

            while (siguiente != nullptr && siguiente->pedido.prioridad == tipo) {
                finRun = siguiente;
                siguiente = siguiente->siguiente;
                contador++;
            }

            finRun->siguiente = nullptr;

            if (contador >= 2) {
                agregarCadenaAlFinal(iniGrupo, finGrupo, iniRun, finRun);
            } else {
                agregarCadenaAlFinal(iniAislado, finAislado, iniRun, finRun);
            }

            actual = siguiente;
        }
    }

    unirListas(lista, iniA, finA, iniGrupo, finGrupo, iniAislado, finAislado);
}

void imprimir(Lista lista) {
    Nodo *rec = lista.inicio;

    cout << "Codigo\tCantidad\tPrioridad" << endl;

    while (rec != nullptr) {
        cout << rec->pedido.codigo << "\t"
             << rec->pedido.cantidad << "\t\t"
             << rec->pedido.prioridad << endl;

        rec = rec->siguiente;
    }
}

int main() {
    Lista lista;
    construir(lista);

    insertarAlFinal(lista, {1, 10, 'B'});
    insertarAlFinal(lista, {2, 20, 'A'});
    insertarAlFinal(lista, {3, 15, 'B'});
    insertarAlFinal(lista, {4, 12, 'B'});
    insertarAlFinal(lista, {5, 5, 'C'});
    insertarAlFinal(lista, {6, 6, 'A'});
    insertarAlFinal(lista, {7, 8, 'C'});
    insertarAlFinal(lista, {8, 4, 'C'});
    insertarAlFinal(lista, {9, 2, 'B'});

    cout << "Lista original:" << endl;
    imprimir(lista);

    reordenarLista(lista);

    cout << endl << "Lista reorganizada:" << endl;
    imprimir(lista);

    return 0;
}
