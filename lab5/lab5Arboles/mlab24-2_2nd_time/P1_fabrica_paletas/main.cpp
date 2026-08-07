#include <iostream>

#include "Bibliotecas/estructurasArbol.h"
#include "Bibliotecas/FuncionesArbol.h"

using namespace std;

int main() {

    int arr[4][7] {
        {100,103,100,101,100,99,100},
        {100,102,102,92,99,100,98},
        {100,100,102,100,100,101,100},
        {98,96,93,99,100,102,95}
    };

    //como nos piden armar un arbol equilibrado podemos usar divide y venceras con la matriz
    Arbol arbol;
    arbol.raiz=nullptr;
    insertar_dia_turno(arbol.raiz,arr,0,27);

    Arbol arbol2{};
    arbol2.raiz=nullptr;
    ElementoArbol datos[28];
    llenarArreglo(arr,datos);
    ordenarArreglo(datos);
    insertar_cantidad(arbol2.raiz,datos,0,27);
    enOrden(arbol2.raiz);

    return 0;
}
