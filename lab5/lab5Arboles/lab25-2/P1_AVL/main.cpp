#include <iostream>

#include "Bibliotecas/FuncionesArbol.h"
using namespace std;

int main() {
    int arrDNIs[7]{72649318, 50823147, 81234567, 40987654, 65012345, 94561237, 30124598};

    NodoArbol *raiz = nullptr;

    cout << "Insertando valores en el AVL:" << endl;

    for (int i = 0; i < 7; i++) {
        ElementoArbol elemento{};
        crearElemento(elemento, arrDNIs[i]);

        cout << "Insertar " << arrDNIs[i] << endl;
        raiz = insertarAVL(raiz, elemento);
    }

    cout << "Recorrido inorden del AVL:" << endl;
    enOrden(raiz);

    return 0;
}
