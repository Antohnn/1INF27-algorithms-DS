#include <iostream>


#include "Bibliotecas/Arbol.h"
#include "Bibliotecas/FuncionesArbol.h"
using namespace std;

int main() {
    const char * articulos[]= {"el", "la", "los", "las", "un", nullptr};
    const char* sustantivos[] = {"gato", "perro", "casa", "mesa", "silla", nullptr};
    const char* verbos[] = {"come", "salta", "duerme", nullptr};

    //empezamos por crear las estructuras que nos serviran para armar el arbol
    Arbol arbol{};
    crearArbolGramatical(arbol,articulos,sustantivos,verbos);

    if (validarArbolGramatical(arbol.raiz,ORACION)) {
        cout<<"Arbol valido"<<endl;
    }else {
        cout<<"Arbol no valido"<<endl;
    }
    return 0;
}
