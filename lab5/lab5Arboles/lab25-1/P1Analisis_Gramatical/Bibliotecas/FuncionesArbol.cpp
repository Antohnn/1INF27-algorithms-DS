//
// Created by ANTONIO on 30/06/2026.
//

#include <cstring>
#include <iostream>

#include "Arbol.h"
#include "NodoArbol.h"

using namespace std;
#include "FuncionesArbol.h"

NodoArbol *crearNodoArbol(ElementoArbol &elemento) {
    NodoArbol *nuevo=new NodoArbol();
    nuevo->elemento=elemento;
    nuevo->izquierda=nullptr;
    nuevo->derecha=nullptr;
    return nuevo;
}
void plantarArbol(NodoArbol *&raiz,NodoArbol *izquierda,ElementoArbol &elemento,NodoArbol *derecha) {
    raiz=crearNodoArbol(elemento);
    raiz->izquierda=izquierda;
    raiz->derecha=derecha;
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

void crearArbolGramatical(Arbol &arbol,const char **articulos,const char **sustantivos,const char **verbos) {
    arbol.raiz=nullptr;
    arbol.cantidadPalabras=0;
    cout<<"Ingrese la horacion a analizar: "<<endl;
    cin.getline(arbol.oracion,300);

    //realizamos la tokenizacion de la oracion para analizar las palabras

    char copia[300];
    strcpy(copia,arbol.oracion);
    char *token=strtok(copia," ");

    char palabra1[40]="";
    char palabra2[40]="";
    char palabra3[40]="";

    while(token!=nullptr) {
        arbol.cantidadPalabras++;
        if (arbol.cantidadPalabras==1) {
            strcpy(palabra1,token);
        }
        if (arbol.cantidadPalabras==2) {
            strcpy(palabra2,token);
        }
        if (arbol.cantidadPalabras==3) {
            strcpy(palabra3,token);
        }
        token=strtok(nullptr," ");
    }

    NodoArbol *articulo=nullptr;
    NodoArbol *sustantivo=nullptr;
    NodoArbol *verbo=nullptr;


    if (strlen(palabra1)>0) {
        ElementoArbol eArticulo{};
        eArticulo.categoria=determinarCategoria(palabra1,articulos,sustantivos,verbos);
        strcpy(eArticulo.palabra,palabra1);
        plantarArbol(articulo,nullptr,eArticulo,nullptr);
    }

    if (strlen(palabra2)>0) {
        ElementoArbol eSustantivo{};
        eSustantivo.categoria=determinarCategoria(palabra2,articulos,sustantivos,verbos);
        strcpy(eSustantivo.palabra,palabra2);
        plantarArbol(sustantivo,nullptr,eSustantivo,nullptr);
    }

    if (strlen(palabra3)>0) {
        ElementoArbol eVerbos{};
        eVerbos.categoria=determinarCategoria(palabra3,articulos,sustantivos,verbos);
        strcpy(eVerbos.palabra,palabra3);
        plantarArbol(verbo,nullptr,eVerbos,nullptr);
    }


    NodoArbol *sujeto=nullptr;
    ElementoArbol eSujeto{};
    eSujeto.categoria=SUJETO;
    strcpy( eSujeto.palabra,"");

    NodoArbol *predicado=nullptr;
    ElementoArbol ePredicado{};
    ePredicado.categoria=PREDICADO;
    strcpy( ePredicado.palabra,"");

    ElementoArbol eOracion{};
    eOracion.categoria=ORACION;
    strcpy( eOracion.palabra,"");

    plantarArbol(sujeto,articulo,eSujeto,sustantivo);
    plantarArbol(predicado,verbo,ePredicado,nullptr);
    plantarArbol(arbol.raiz,sujeto,eOracion,predicado);
}
void mostrarError(Categoria esperada) {
    if (esperada==ARTICULO) {
        cout<<"Error: Articulo debe estar antes del sustantivo"<<endl;
    }else if (esperada==SUSTANTIVO) {
        cout<<"Error: Sustantivo debe estar antes del articulo"<<endl;
    }else if (esperada==VERBO) {
        cout<<"Error: Predicado debe contener verbo"<<endl;
    }else if (esperada==SUJETO) {
        cout<<"Error : La oracion debe tener sujeto"<<endl;
    }else if (esperada==PREDICADO) {
        cout<<"Error : La oracion debe tener predicado"<<endl;
    }else if (esperada==ORACION) {
        cout<<"Error : La raiz debe ser ORACION"<<endl;
    }
}
bool validarArbolGramatical(NodoArbol *nodo,Categoria esperada) {
    if (nodo==nullptr) {
        cout<<"El arbol sintactico no esta completo"<<endl;
        return false;
    }
    if (nodo->elemento.categoria==DESCONOCIDO) {
        cout<<"Error: palabra no reconocida: "<<nodo->elemento.palabra<<endl;
        return false;
    }
    if (nodo->elemento.categoria!=esperada) {
        mostrarError(esperada);
        return false;
    }

    if (nodo->elemento.categoria==ORACION) {
        return validarArbolGramatical(nodo->izquierda,SUJETO) and validarArbolGramatical(nodo->derecha,PREDICADO);
    }

    if (nodo->elemento.categoria==SUJETO) {
        return validarArbolGramatical(nodo->izquierda,ARTICULO) and validarArbolGramatical(nodo->derecha,SUSTANTIVO);
    }

    if (nodo->elemento.categoria==PREDICADO) {
        if (nodo->derecha!=nullptr) {
            cout<<"Error el predicado tiene elementos adicionales "<<endl;
            return false;
        }
        return validarArbolGramatical(nodo->izquierda,VERBO);
    }
    //si es articulo, verbo o sustantivo no tiene que tener hijos
    if (nodo->izquierda!=nullptr or nodo->derecha!=nullptr) {
        cout<<"Error: una palabra terminal no debe tener hijos"<<endl;
        return false;
    }
    if (strlen(nodo->elemento.palabra)==0 or strcmp(nodo->elemento.palabra," ")==0) {
        cout<<"Error: Nodo terminal sin palabra "<<endl;
        return false;
    }

    return true;
}


