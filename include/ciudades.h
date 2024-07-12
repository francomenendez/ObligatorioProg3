#ifndef _CIUDADES_H 
#define _CIUDADES_H

#include "stringdinamico.h"

const int N=5;
typedef struct { 
    string arre[N];
    int tope;
    } Ciudades;

void CrearCiudades (Ciudades &C); 

boolean PerteneceCiudades (Ciudades C, string str); 

void InsertarCiudades (Ciudades &C, string str); 

boolean EsVaciaCiudades (Ciudades C); 

boolean EsLlenaCiudades (Ciudades C);

int LargoCiudades (Ciudades C); 

void DevolverCiudad (Ciudades C, int num, string &str);

int DevolverNumCiudad (Ciudades C, string str);

///////////

void RegistrarCiudad (Ciudades &C, string str);

void DesplegarCiudades (Ciudades C);

#endif