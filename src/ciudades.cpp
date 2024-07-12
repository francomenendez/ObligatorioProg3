#include "ciudades.h"

void CrearCiudades (Ciudades &C){
    C.tope = 0;
    for(int i=0; i<N; i++) {
        StrCrear(C.arre[i]);
    }
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
    strcopDinamico(C.arre[C.tope], str); 
    C.tope++;
}

boolean EsVaciaCiudades (Ciudades C){
    return (boolean) (C.tope==0);
}

boolean EsLlenaCiudades (Ciudades C){
    return (boolean) (C.tope==N);
}

int LargoCiudades (Ciudades C){
    return (C.tope);
}

void DevolverCiudad (Ciudades C, int num, string &str){
    StrCrear(str);
    strcopDinamico(str, C.arre[num-1]);
}

int DevolverNumCiudad (Ciudades C, string str) {
    boolean encontre=FALSE;
    int i=0, num;
    while (i<C.tope && !encontre) {
        if (streq(C.arre[i],str)) {
            num = i+1;
            encontre=TRUE;
        } else
            i++;
    }
    return num;
}

////////////////////////////////////////////////////

void RegistrarCiudad (Ciudades &C, string str) {
    if ( EsLlenaCiudades(C) )
        printf("\nYa se registró el máximo de ciudades disponibles.");
    else if ( PerteneceCiudades(C, str) )
            printf("\nLa ciudad ingresada ya existe en el sistema");
        else
            InsertarCiudades (C, str);
}

void DesplegarCiudades (Ciudades C){
    for(int i=0; i<C.tope; i++) {
        printf("\nCiudad %d: ", i+1);
        print(C.arre[i]);
    }
}