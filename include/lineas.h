#ifndef _LINEAS_H 
#define _LINEAS_H

#include <stdio.h>

typedef struct nodoL { 
    ciudad info;
    nodoL * sig;
} Nodo;

typedef struct { 
    Nodo * prim;
    Nodo * ult;
} LPPF;


#endif