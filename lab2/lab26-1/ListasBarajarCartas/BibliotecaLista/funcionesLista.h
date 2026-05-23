//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal 

#ifndef LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H
#define LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H

void construir(struct Baraja & listaTAD);
bool esListaVacia(const struct Baraja & listaTAD);
void insertarAlInicio(struct Baraja & listaTAD, const struct ElementoBaraja & elemento);
void insertarAlFinal(struct Baraja & listaTAD, const struct ElementoBaraja & elemento);
struct NodoBaraja * obtenerUltimoNodo(const struct Baraja & listaTAD);
void insertarEnOrden(struct Baraja & listaTAD, const struct ElementoBaraja & elemento);
struct NodoBaraja * obtenerNodoAnterior(const struct Baraja & lista, const struct ElementoBaraja & elemento);
void eliminaNodo(struct Baraja & listaTAD, const struct ElementoBaraja & elemento);
void destruir(struct Baraja & listaTAD) ;
void imprimir(const struct Baraja & listaTAD);

#endif //LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H