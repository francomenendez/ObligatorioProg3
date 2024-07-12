#include "paradas.h"

void CrearParadas (Paradas &P) {
    P.prim = NULL;
    P.ult = NULL;
}

void InsertarParada (Paradas &P, string str){
    Nodo * nuevo = new Nodo; 
    nuevo->num = LargoParadas(P) + 1;
    StrCrear(nuevo->ciudad);
    strcopDinamico(nuevo->ciudad, str);
    nuevo -> sig = NULL;

    if (P.ult == NULL){
        P.ult = nuevo;
        P.prim = nuevo; 
    } 
    else {
        P.ult -> sig = nuevo;
        P.ult = nuevo;
    }
}

boolean EsVaciaParadas (Paradas P) { 
    return (boolean) (P.prim==NULL && P.ult==NULL);
} 

int LargoParadas (Paradas P) {
    int largo=0;
    if (!EsVaciaParadas(P)) {
        while (P.prim!=NULL) {
            largo++;
            P.prim = P.prim->sig;
        }
    }
    return largo;
}

void UltimaParada (Paradas P, string &str){
    StrCrear(str);
    strcopDinamico(str, P.ult->ciudad);
}

void DesplegarParadas (Paradas P, Ciudades C){
    while (P.prim!=NULL) {
        printf("\nParada %d : ", P.prim->num);
        printf("ciudad n° %d - ", DevolverNumCiudad(C, P.prim->ciudad));
        print(P.prim->ciudad);
        P.prim = P.prim->sig;
    }
}
