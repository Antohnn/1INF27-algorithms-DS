#include <iostream>

#include "Bibliotecas/estructurasArbol.h"
#include "Bibliotecas/FuncionesArbol.h"

using namespace std;

int main() {
    const char * articulos[]={"el", "la", "los", "las", "un", nullptr};
    const char* sustantivos[] = {"gato", "perro", "casa", "mesa", "silla", nullptr};
    const char* verbos[] = {"come", "salta", "duerme", nullptr};

    Arbol arbol;
    arbol.raiz=nullptr;

    crearArbolGramatical(arbol,articulos,sustantivos,verbos);

    if (validarArbolGramatical(arbol)) {
        cout<<"El arbol es valido"<<endl;
        preOrden(arbol.raiz);
    }else {
        cout<<"El arbol no es valido"<<endl;
        cout<<arbol.oracion<<endl;
    }

    return 0;
}
