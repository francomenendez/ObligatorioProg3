#ifndef _LINEAS_H 
#define _LINEAS_H

#include "paradas.h"

typedef struct NodoLi{
    string alfanum;
    Paradas info;
    NodoLi * sig;
} NodoL;

typedef NodoL * Lineas;

void CrearLineas (Lineas &L);
void InsertarLineaNueva (Lineas &L, string codigo);
void InsertarParadaEnLinea (Lineas &L, string codigo, string ciudad);
boolean EsVaciaLineas (Lineas L);
boolean ExisteLinea (Lineas L, string codigo);
void DesplegarDatosdeLineas (Lineas L);
void DesplegarLinea (Lineas L, string codigo, Ciudades C);

void InsfrontLinea (Lineas &L, string codigo);
Paradas EncontrarLinea (Lineas L, string codigo);

#endif