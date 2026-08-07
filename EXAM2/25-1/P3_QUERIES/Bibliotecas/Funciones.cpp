//
// Created by ANTONIO on 9/07/2026.
//

#include "Funciones.h"

#include "BibliotecaArbolBinario/ArbolBinario.h"
#include "BibliotecaArbolBinario/NodoArbolBinario.h"
#include <string>
#include <sstream>
#include <iostream>

#include "BibliotecaArbolBinario/funcionesArbolBinario.h"

using namespace std;

void crearArbolSQL(ArbolBinario &arbol) {
    arbol.raiz=nullptr;
    arbol.cantidadPalabras=0;

    cout<<"INGRESE EL QUERIE QUE DESEE:"<<endl;
    getline(cin,arbol.oracion);

    string columna;
    string tabla;
    string condicion;

    extraerDatosSQL(arbol.oracion,columna,tabla,condicion);

    NodoArbolBinario *nodoColumna=nullptr;
    NodoArbolBinario *nodoTabla=nullptr;
    NodoArbolBinario *nodoCondicion=nullptr;

    if (!columna.empty() and noEsComando(columna)) {
        ElementoArbolBinario eleColumna{};
        eleColumna.palabra=columna;
        eleColumna.cate=COLUMNA;

        plantarNodoArbolBinario(nodoColumna,nullptr,eleColumna,nullptr);
    }
    if (!tabla.empty() and noEsComando(tabla)) {
        ElementoArbolBinario eleTabla{};
        eleTabla.palabra=tabla;
        eleTabla.cate=TABLA;

        plantarNodoArbolBinario(nodoTabla,nullptr,eleTabla,nullptr);
    }
    if (!condicion.empty() and noEsComando(condicion)) {
        ElementoArbolBinario eleCondicion{};
        eleCondicion.palabra=condicion;
        eleCondicion.cate=CONDICION;

        plantarNodoArbolBinario(nodoCondicion,nullptr,eleCondicion,nullptr);
    }

    NodoArbolBinario *nodoFrom=nullptr;
    NodoArbolBinario *nodoWhere=nullptr;

    ElementoArbolBinario eleWhere{};
    eleWhere.palabra="";
    eleWhere.cate=WHERE;

    ElementoArbolBinario eleFrom{};
    eleFrom.palabra="";
    eleFrom.cate=FROM;

    ElementoArbolBinario eleSelect{};
    eleSelect.palabra="";
    eleSelect.cate=SELECT;

    plantarNodoArbolBinario(nodoWhere,nodoCondicion,eleWhere,nullptr);
    plantarNodoArbolBinario(nodoFrom,nodoTabla,eleFrom,nodoWhere);
    plantarNodoArbolBinario(arbol.raiz,nodoColumna,eleSelect,nodoFrom);
}
void extraerDatosSQL(string &oracion,string &columna,string &tabla,string &condicion) {
    stringstream ss(oracion);
    string token;
    int zona=0;

    while (ss >> token) {
        if (token == "SELECT") {
            zona = 0;
        }
        else if (token == "FROM") {
            zona = 1;
        }
        else if (token == "WHERE") {
            zona = 2;
        }
        else {
            if (zona == 0) {
                if (columna.empty() && noEsComando(token)) {
                    columna = token;
                }
            }
            else if (zona == 1) {
                if (tabla.empty() && noEsComando(token)) {
                    tabla = token;
                }
            }
            else if (zona == 2) {
                condicion = token;
            }
        }
    }
}
bool noEsComando(string &palabra) {
    if (palabra=="SELECT") {
        return false;
    }else if (palabra=="FROM") {
        return false;
    }else if (palabra=="WHERE") {
        return false;
    }
    return true;
}
void enOrden(NodoArbolBinario *raiz) {
    if (raiz==nullptr) return;

    imprimirTitulo(raiz);
    if (!raiz->elemento.palabra.empty()) {
        cout<<raiz->elemento.palabra<<endl;
    }
    enOrden(raiz->izquierda);
    enOrden(raiz->derecha);
}
void imprimirTitulo(NodoArbolBinario *raiz) {
    if (raiz->elemento.cate==SELECT) {
        cout<<"SELECT";
    }else if (raiz->elemento.cate==COLUMNA) {
        cout<<"COLUMNA";
    }else if (raiz->elemento.cate==FROM) {
        cout<<"FROM";
    }else if (raiz->elemento.cate==TABLA) {
        cout<<"TABLA";
    }else if (raiz->elemento.cate==WHERE) {
        cout<<"WHERE";
    }else if (raiz->elemento.cate==CONDICION) {
        cout<<"CONDICION";
    }
    cout<<endl;
}
void validarSQL(ArbolBinario &arbol) {
    NodoArbolBinario *raiz = arbol.raiz;

    if (raiz == nullptr || raiz->elemento.cate != SELECT) {
        cout << "Consulta invalida." << endl;
        return;
    }

    NodoArbolBinario *nodoColumna = raiz->izquierda;

    if (nodoColumna == nullptr ||
        nodoColumna->elemento.cate != COLUMNA ||
        nodoColumna->elemento.palabra.empty()) {

        cout << "Error: Falta la columna" << endl;
        cout << "Consulta invalida." << endl;
        return;
        }

    NodoArbolBinario *nodoFrom = raiz->derecha;

    if (nodoFrom == nullptr || nodoFrom->elemento.cate != FROM) {
        cout << "Error: Falta clausula FROM." << endl;
        cout << "Consulta invalida." << endl;
        return;
    }

    NodoArbolBinario *nodoTabla = nodoFrom->izquierda;

    if (nodoTabla == nullptr ||
        nodoTabla->elemento.cate != TABLA ||
        nodoTabla->elemento.palabra.empty()) {

        cout << "Error: Falta clausula FROM." << endl;
        cout << "Consulta invalida." << endl;
        return;
        }

    NodoArbolBinario *nodoWhere = nodoFrom->derecha;

    if (nodoWhere == nullptr || nodoWhere->elemento.cate != WHERE) {
        cout << "Error: WHERE debe tener una condicion." << endl;
        cout << "Consulta invalida." << endl;
        return;
    }

    NodoArbolBinario *nodoCondicion = nodoWhere->izquierda;

    if (nodoCondicion == nullptr ||
        nodoCondicion->elemento.cate != CONDICION ||
        nodoCondicion->elemento.palabra.empty()) {

        cout << "Error: WHERE debe tener una condicion." << endl;
        cout << "Consulta invalida." << endl;
        return;
        }

    cout << "Consulta valida: Estructura SELECT correcta." << endl;
}