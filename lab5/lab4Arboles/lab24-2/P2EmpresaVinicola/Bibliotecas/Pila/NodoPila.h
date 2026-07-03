//
// Created by ANTONIO on 1/07/2026.
//

#ifndef P2EMPRESAVINICOLA_NODOPILA_H
#define P2EMPRESAVINICOLA_NODOPILA_H
#include "ElementoPila.h"

struct NodoPila {
    ElementoPila elemento;
    NodoPila *siguiente;
};
#endif //P2EMPRESAVINICOLA_NODOPILA_H
