//
// Created by ANTONIO on 30/04/2026.
//

#ifndef PRACTICAIMPLEMENTACIONLISTA_FUNCIONESAUXILIARES_H
#define PRACTICAIMPLEMENTACIONLISTA_FUNCIONESAUXILIARES_H

void construirLista(struct Lista &listaInicio);
bool esListaVacia(struct Lista &listaTAD);
void insertarAlInicio(struct Lista &listaInicio,struct Elemento &elemento) ;
void imprimir(struct Lista &listaInicio);
void isertarAlFinal(struct Lista &listaFin,struct Elemento &elemento);
struct Nodo *obtenerUltimoNodo(struct Lista &listaFin) ;
void insertarEnOrden(struct Lista &listaOrdenada,struct Elemento &elemento);
void eliminaNodo(struct Lista &listaInicio,struct Elemento &elemento);

#endif //PRACTICAIMPLEMENTACIONLISTA_FUNCIONESAUXILIARES_H
