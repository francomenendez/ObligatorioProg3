#ifndef _CONJUNTOLINEAS_H 
#define _CONJUNTOLINEAS_H

#include "lineas.h"

typedef struct nodoL { 
    LPPF info;
    nodoL * sig;
} Nodo;

typedef Nodo * ConjuntoLineas;

#endif