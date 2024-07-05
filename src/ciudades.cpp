#include "ciudades.h"

void CrearCiudades (Ciudades &C){
    C.tope = 0;
} 

boolean PerteneceCiudades (Ciudades C, string str){
    boolean pertenece = FALSE;

    int i=0;
    while (i<C.tope && !pertenece) {
        if (streq(str, C.arre[i]))
            pertenece = TRUE;
        else
            i++;
    }
    return (pertenece);
}

void InsertarCiudades (Ciudades &C, string str){
    
}

boolean EsVaciaCiudades (Ciudades C){

}

int Largo (Ciudades C){

}

void DesplegarCiudades (Ciudades C){

}

void EliminarCiudades (Ciudades &C, int num){

}