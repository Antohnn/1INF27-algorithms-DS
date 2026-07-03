//
// Created by ANTONIO on 2/07/2026.
//

#ifndef P1_ANOMALIAS_FUNCIONESARBOLES_H
#define P1_ANOMALIAS_FUNCIONESARBOLES_H
NodoArbol *crearNodo(int dato);
void insertarABB(NodoArbol *&raiz, int dato);
void construirArbolSistema(Arbol &arbol);
int contarNodos(NodoArbol *raiz);
int contarHojas(NodoArbol *raiz);
NodoArbol *aplicar_arbol(NodoArbol *paquetes, NodoArbol *sistema);
bool esABB(NodoArbol *raiz, int minimo, int maximo);
int sumarNodos(NodoArbol *raiz);
bool determinar_anomalia(NodoArbol *resultado);
void imprimirEnOrden(NodoArbol *raiz) ;
#endif //P1_ANOMALIAS_FUNCIONESARBOLES_H
