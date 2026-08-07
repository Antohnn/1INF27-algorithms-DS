#include <iostream>

#include "Bibliotecas/estructurasArbol.h"
#include "Bibliotecas/FuncionesArbol.h"

using namespace std;

int main() {
    //viendo el problemita detectamos una busqueda tipo dfs para ello utilizaremos pilas
    Arbol arbol;
    arbol.raiz=nullptr;

    insertarEnArbol(arbol.raiz,'N',100);
    insertarEnArbol(arbol.raiz,'N',50);
    insertarEnArbol(arbol.raiz,'N',75);
    insertarEnArbol(arbol.raiz,'N',25);
    insertarEnArbol(arbol.raiz,'N',150);
    insertarEnArbol(arbol.raiz,'N',175);
    insertarEnArbol(arbol.raiz,'N',200);
    insertarEnArbol(arbol.raiz,'S',125);
    insertarEnArbol(arbol.raiz,'N',140);
    insertarEnArbol(arbol.raiz,'N',110);
    insertarEnArbol(arbol.raiz,'N',130);
    insertarEnArbol(arbol.raiz,'N',115);
    insertarEnArbol(arbol.raiz,'N',105);

    // enOrden(arbol.raiz);

    //una vez localizado skynerd procedemos a eliminar sus nodos de defensa osea los hijos
    NodoArbol *skynerd=buscarSkyNerd(arbol.raiz);
    cout<<endl;

    eliminarHijosSkyNerd(skynerd);


    return 0;
}
