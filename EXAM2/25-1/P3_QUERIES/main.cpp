#include <iostream>
#include <string>
#include <sstream>

#include "Bibliotecas/Funciones.h"
#include "Bibliotecas/BibliotecaArbolBinario/ArbolBinario.h"
#include "Bibliotecas/BibliotecaArbolBinario/enum.h"
#include "Bibliotecas/BibliotecaArbolBinario/funcionesArbolBinario.h"
using namespace std;



int main() {
    ArbolBinario arbol;

    crearArbolSQL(arbol);
    validarSQL(arbol);




    return 0;
}
