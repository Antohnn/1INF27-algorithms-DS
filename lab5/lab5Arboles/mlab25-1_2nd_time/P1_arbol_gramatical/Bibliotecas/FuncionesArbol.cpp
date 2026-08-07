//
// Created by ANTONIO on 3/07/2026.
//

#include <cstring>

#include "estructurasArbol.h"

#include <iostream>
using namespace std;
#include "FuncionesArbol.h"

NodoArbol *crearNodoArbol(ElementoArbol &elemento) {
    NodoArbol *nuevo=new NodoArbol();

    nuevo->dato=elemento;
    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;

    return nuevo;
}
Categoria determinarCategoria(char *palabra,const char **articulos,const char **sustantivos,const char **verbos) {
    int i=0;
    while (articulos[i]!=nullptr) {
        if (strcmp(palabra,articulos[i])==0) {
            return ARTICULO;
        }
        i++;
    }
    i=0;
    while (sustantivos[i]!=nullptr) {
        if (strcmp(palabra,sustantivos[i])==0) {
            return SUSTANTIVO;
        }
        i++;
    }
    i=0;
    while (verbos[i]!=nullptr) {
        if (strcmp(palabra,verbos[i])==0) {
            return VERBO;
        }
        i++;
    }
    return DESCONOCIDO;
}
void plantarArbol(NodoArbol *&nodo,NodoArbol *izquierda,ElementoArbol &elemento,NodoArbol *derecha) {
    nodo=crearNodoArbol(elemento);

    nodo->izquierda=izquierda;
    nodo->derecha=derecha;
}
void crearArbolGramatical(Arbol &arbol,const char **articulos,const char **sustantivos,const char **verbos) {
    //incializamos el arbol
    arbol.raiz=nullptr;
    arbol.cantidadPalabras=0;
    //realizamos la entrada de la oracion
    cout<<"Ingrese la oracion a insertar: "<<endl;
    cin.getline(arbol.oracion,300);

    //creamos una copia de la oracion para realizar la tokenizacion
    char copia[300];
    strcpy(copia,arbol.oracion);

    char palabra1[30]="";
    char palabra2[30]="";
    char palabra3[30]="";

    //tokenizamos con la cantidad palabras
    char *tkn=strtok(copia," ");
    while(tkn!=nullptr) {
        arbol.cantidadPalabras++;

        if (arbol.cantidadPalabras==1) {
            strcpy(palabra1,tkn);
        }else if (arbol.cantidadPalabras==2) {
            strcpy(palabra2,tkn);
        }else if (arbol.cantidadPalabras==3) {
            strcpy(palabra3,tkn);
        }

        tkn=strtok(nullptr," ");
    }

    NodoArbol *nodoArticulo=nullptr;
    NodoArbol *nodoSustantivo=nullptr;
    NodoArbol *nodoVerbo=nullptr;

    if (strlen(palabra1)>0) {
        ElementoArbol eleArticulo{};
        eleArticulo.categoria=determinarCategoria(palabra1,articulos,sustantivos,verbos);
        strcpy(eleArticulo.palabra,palabra1);

        plantarArbol(nodoArticulo,nullptr,eleArticulo,nullptr);
    }
    if (strlen(palabra2)>0) {
        ElementoArbol eleSustantivo{};
        eleSustantivo.categoria=determinarCategoria(palabra2,articulos,sustantivos,verbos);
        strcpy(eleSustantivo.palabra,palabra2);

        plantarArbol(nodoSustantivo,nullptr,eleSustantivo,nullptr);
    }
    if (strlen(palabra3)>0) {
        ElementoArbol eleVerbo{};
        eleVerbo.categoria=determinarCategoria(palabra3,articulos,sustantivos,verbos);
        strcpy(eleVerbo.palabra,palabra3);

        plantarArbol(nodoVerbo,nullptr,eleVerbo,nullptr);
    }

    NodoArbol *nodoSujeto=nullptr;
    NodoArbol *nodoPredicado=nullptr;
    NodoArbol *nodoOracion=nullptr;

    ElementoArbol eleSujeto{};
    eleSujeto.categoria=SUJETO;
    strcpy(eleSujeto.palabra,"");

    ElementoArbol elePredicado{};
    elePredicado.categoria=PREDICADO;
    strcpy(elePredicado.palabra,"");

    ElementoArbol eleOracion{};
    eleOracion.categoria=ORACION;
    strcpy(eleOracion.palabra,"");

    plantarArbol(nodoSujeto,nodoArticulo,eleSujeto,nodoSustantivo);
    plantarArbol(nodoPredicado,nodoVerbo,elePredicado,nullptr);
    plantarArbol(arbol.raiz,nodoSujeto,eleOracion,nodoPredicado);
}
bool validarArbolGramatical(Arbol &arbol) {
    if (arbol.cantidadPalabras>3) {
        cout<<"El arbol tiene mas de 3 palabras"<<endl;
        return false;
    }
    if (arbol.cantidadPalabras<3) {
        cout<<"El arbol tiene menos de 3 palabras"<<endl;
        return false;
    }

    return verificar(arbol.raiz,ORACION);
}
bool verificar(NodoArbol *nodo,Categoria cate) {

    if (nodo==nullptr) return false;


    if (nodo->dato.categoria!=cate) {
        mensajeDeError(cate);
        return false;
    }

    if (nodo->dato.categoria==ORACION) {
        return verificar(nodo->izquierda,SUJETO) and verificar(nodo->derecha,PREDICADO);
    }
    if (nodo->dato.categoria==SUJETO) {
        return verificar(nodo->izquierda,ARTICULO) and verificar(nodo->derecha,SUSTANTIVO);
    }
    if (nodo->dato.categoria==PREDICADO) {
        if (nodo->derecha!=nullptr) {
            cout<<"El predicado tiene un elemento adicional "<<endl;
            return false;
        }
        return verificar(nodo->izquierda,VERBO);
    }
    if (nodo->izquierda!=nullptr or nodo->derecha!=nullptr) {
        return false;
    }

    return true;
}
void mensajeDeError(Categoria cate) {
    if (cate==ORACION) {
        cout<<"Error: Oracion no valida"<<endl;
    }else if (cate==SUJETO) {
        cout<<"Error: Sujeto no valido"<<endl;
    }else if (cate==PREDICADO) {
        cout<<"Error: Predicado no valido"<<endl;
    }else if (cate==ARTICULO) {
        cout<<"Error: Articulo debe estar antes del sustantivo"<<endl;
    }
}
void preOrden(NodoArbol *raiz) {
    if (raiz==nullptr) return;

    imprimirCategoria(raiz->dato.categoria);
    if (strlen(raiz->dato.palabra)!=0) {
        cout<<raiz->dato.palabra<<endl;
    }
    preOrden(raiz->izquierda);
    preOrden(raiz->derecha);
}
void imprimirCategoria(Categoria categoria) {
    if (categoria==ORACION) {
        cout<<"ORACION"<<endl;
    }else if (categoria==SUJETO) {
        cout<<"_SUJETO"<<endl;
    }else if (categoria==ARTICULO) {
        cout<<"__ARTICULO"<<endl;
    }else if (categoria==SUSTANTIVO) {
        cout<<"__SUSTANTIVO"<<endl;
    }else if (categoria==PREDICADO) {
        cout<<"_PREDICADO"<<endl;
    }else if (categoria==VERBO) {
        cout<<"__VERBO"<<endl;
    }
}

