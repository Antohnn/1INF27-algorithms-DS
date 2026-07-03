//
// Created by ANTONIO on 2/07/2026.
//

#ifndef P2_LIBRITO_FUNCIONESARBOL_H
#define P2_LIBRITO_FUNCIONESARBOL_H
NodoArbol *crearNodo(const char *titulo, int relevancia);
void construirArbol(Arbol &arbol);
int buscarPrincipalBFS(NodoArbol *raiz) ;
void eliminarSubarbol(NodoArbol *&raiz, int &tamanio);
void removerParte(Arbol &arbol, NodoArbol *nodo, char lado);

#endif //P2_LIBRITO_FUNCIONESARBOL_H
