//
// Created by ANTONIO on 1/07/2026.
//

#ifndef P2_SKYNERD_NODOPILA_H
#define P2_SKYNERD_NODOPILA_H
#include "ElementoPila.h"

struct NodoPila {
    ElementoPila elemento;
    bool valido;
    NodoPila *siguiente;
};

#endif //P2_SKYNERD_NODOPILA_H
