#include <iostream>
#include "Bibliotecas/estructuras.h"
#include "Bibliotecas/FuncionesArboles.h"

using namespace std;
int main() {
    Arbol arbol_paquetes;
    Arbol arbol_sistema;
    Arbol arbol_resultado;

    arbol_paquetes.raiz = nullptr;
    arbol_sistema.raiz = nullptr;
    arbol_resultado.raiz = nullptr;

    insertarABB(arbol_paquetes.raiz, 5);
    insertarABB(arbol_paquetes.raiz, 3);
    insertarABB(arbol_paquetes.raiz, 9);

    construirArbolSistema(arbol_sistema);

    arbol_resultado.raiz = aplicar_arbol(arbol_paquetes.raiz,
                                         arbol_sistema.raiz);

    cout << "Arbol resultado en orden: ";
    imprimirEnOrden(arbol_resultado.raiz);
    cout << endl;

    bool hayAnomalia = determinar_anomalia(arbol_resultado.raiz);

    if (hayAnomalia) {
        cout << "Anomalia detectada" << endl;
    } else {
        cout << "Sin eventos sospechosos" << endl;
    }

    return 0;
}