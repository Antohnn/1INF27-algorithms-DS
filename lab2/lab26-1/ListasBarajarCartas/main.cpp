#include <iostream>

#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/FuncionesAuxiliares.h"

using namespace std;

int main() {
    Baraja baraja;

    construir(baraja);

    crear_baraja(baraja);

    imprimirCar('=',25);
    cout<<"BARAJA ORIGINAL"<<endl;
    imprimirCar('=',25);
    imprimir(baraja);

    barajar(baraja);
    imprimirCar('=',25);
    cout<<"BARAJADO"<<endl;
    imprimirCar('=',25);
    imprimir(baraja);

    destruir(baraja);
    imprimirCar('=',25);
    cout<<"LIBERAR MEMORIA"<<endl;
    imprimirCar('=',25);

    if (esListaVacia(baraja)) {
        cout<<"BARAJA VACIA"<<endl;
    }

    return 0;
}
