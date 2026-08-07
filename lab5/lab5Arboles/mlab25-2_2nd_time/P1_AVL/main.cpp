#include <iostream>

#include "Biblioteca/EstructurasArbol.h"
#include "Biblioteca/FuncionesArbol.h"

using namespace std;

int main() {

    Arbol arbol;
    arbol.raiz=nullptr;

    int arr[7]{72649318, 50823147, 81234567, 40987654, 65012345, 94561237, 30124598};

    cout<<"Insertando valores en el AVL: "<<endl;
    for(int i=0;i<7;i++) {
        cout<<"Insertar "<<arr[i]<<endl;
        insertarAVL(arbol.raiz,arr[i]);
    }
    cout<<"Recorrido inorden del AVL (clave y altura):"<<endl;
    enOrden(arbol.raiz);
    cout<<endl;


    return 0;
}
