#ifndef _CIUDADES_H 
#define _CIUDADES_H

#include "stringdinamico.h"

const int N = 30;
typedef struct { 
    string arre[N];
    int tope;
    } Ciudades;

void CrearCiudades (Ciudades &C); 

boolean PerteneceCiudades (Ciudades C, string str); 

void InsertarCiudades (Ciudades &C, string str); 

boolean EsVaciaCiudades (Ciudades C); 

int Largo (Ciudades C);

void DesplegarCiudades (Ciudades C); 

void EliminarCiudades (Ciudades &C, int num); 

#endif