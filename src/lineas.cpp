#include "lineas.h"

void CrearLineas (Lineas &L){
    L = NULL;
}

void InsertarLineaNueva (Lineas &L, string codigo){
        if(EsVaciaLineas(L) || strmen(codigo, L->alfanum)) {
            InsfrontLinea(L,codigo);
        } else {
            Lineas aux = L;
            boolean insertar=FALSE;
            while (aux!=NULL && !insertar) {
                if (aux->sig==NULL || strmen(codigo,aux->sig->alfanum)) {
                    InsfrontLinea(aux->sig, codigo);
                    insertar=TRUE;
                } else
                    aux= aux->sig;
            }
        }
}

void InsertarParadaEnLinea (Lineas &L, string codigo, string ciudad){
        Lineas aux = L;
        boolean encontre=FALSE;
        while(aux!=NULL && !encontre)
            if(streq(aux->alfanum, codigo)) {
                InsertarParada(aux->info, ciudad);
                encontre=TRUE;
            }
            else 
                aux=aux->sig;
}

boolean EsVaciaLineas (Lineas L){
    return (boolean) (L==NULL);
}

boolean ExisteLinea (Lineas L, string codigo){
    boolean existe = FALSE;

    while(L != NULL && !existe){
        if(streq(L->alfanum, codigo))
            existe = TRUE;
        else
            L = L->sig;
    }
    return existe;
}

void DesplegarDatosdeLineas (Lineas L){
    while(L!=NULL) {
        printf("\nLínea ");
        print(L->alfanum);
        printf(": contiene %d paradas.", LargoParadas(L->info));
        L=L->sig;
    }
}

void DesplegarLinea (Lineas L, string codigo, Ciudades C){
    boolean encontre = FALSE;
    while(L != NULL && !encontre){
        if(streq(L->alfanum, codigo)) {
            encontre = TRUE;
            printf("\nLínea ");
            print(L -> alfanum);
            printf(": ");
            DesplegarParadas(L->info, C);
        } else
            L = L->sig;
    }
}

void InsfrontLinea (Lineas &L, string codigo) {
    Lineas nuevo = new NodoL;
    CrearParadas(nuevo->info);
    StrCrear(nuevo->alfanum);
    strcopDinamico(nuevo->alfanum, codigo);
    nuevo -> sig = L;
    L = nuevo;
}

Paradas EncontrarLinea (Lineas L, string codigo) {
    Paradas parada;
    boolean encontre=FALSE;
    while (L!=NULL && !encontre) {
        if(streq(L->alfanum, codigo)) {
            encontre=TRUE;
            parada = L->info;
        } else
            L=L->sig;
    }
    return parada;
}