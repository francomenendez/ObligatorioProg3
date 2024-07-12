#ifndef _TRAMOS_H 
#define _TRAMOS_H

#include "ciudades.h"

//N viene dado en el módulo ciudades
typedef int Tramos[N][N];

void CrearTramos (Tramos &T);

boolean PerteneceArista(Tramos T, int v1, int v2);

//Precondición: la arista no pertenece al grafo.
void InsertarArista(Tramos &T, int v1, int v2);

//Precondición: el vértice pertenece al grafo.
int GradoVertice(Tramos T, int v);

void DFSTramo (Tramos T, int actual, int v2, boolean visitado[N]);

///////////

boolean ExisteSecuencia (Tramos T, int v1, int v2);

//registra tramo entre dos ciudades.
void RegistrarTramo (Tramos &T, int c1, int c2);

#endif