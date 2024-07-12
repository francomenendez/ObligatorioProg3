#ifndef _PARADAS_H 
#define _PARADAS_H

#include "ciudades.h"

typedef struct nodoL { 
    int num;
    string ciudad;
    nodoL * sig;
} Nodo;

typedef struct { 
    Nodo * prim;
    Nodo * ult;
} Paradas;

void CrearParadas (Paradas &P);
void InsertarParada (Paradas &P, string s);
boolean EsVaciaParadas (Paradas P);
int LargoParadas (Paradas P);
void UltimaParada (Paradas P, string &str);
void DesplegarParadas (Paradas P, Ciudades C);

#endif