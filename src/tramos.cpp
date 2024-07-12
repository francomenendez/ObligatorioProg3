#include "tramos.h"

void CrearTramos (Tramos &T) {
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            T[i][j]=0; 
}

boolean PerteneceArista(Tramos T, int v1, int v2){
    return (boolean) (T[v1][v2]==1);
}

//Precondición: la arista no pertenece al grafo.
void InsertarArista(Tramos &T, int v1, int v2){ 
    T[v1][v2] = 1; 
    if (v1 != v2) 
        T[v2][v1] = 1; 
}

//Precondición: el vértice pertenece al grafo.
int GradoVertice(Tramos T, int v){
    int grado=0;
    for(int i=0; i<N; i++){
        if(T[v][i]==1)
            grado++;
    }
    return grado;
}

void DFSTramo (Tramos T, int actual, int v2, boolean visitado[N]) { 
    visitado [actual] = TRUE; 
    int j=0;
    while (j<N && !visitado[v2]){ 
        if (T[actual][j] == 1) 
            if (!visitado[j]) 
                DFSTramo (T, j, v2, visitado); 
        j++;
    } 
} 

///////////

boolean ExisteSecuencia (Tramos T, int v1, int v2) {
    boolean existe=FALSE;
    boolean visitado[N];
    for (int i = 0; i < N; i++)
        visitado[i] = FALSE;
    DFSTramo (T, v1, v2, visitado);

    if (visitado[v2])
        existe=TRUE;
    
    return existe;
}

void RegistrarTramo (Tramos &T, int c1, int c2) {
    if (PerteneceArista(T, c1, c2))
        printf("\nYa existe un tramo entre las dos ciudades");
    else if ( c1>=N || c2>=N )
        printf("\nNo existe ciudad con dicho número, estas van de 1 a %d", N);
    else
        InsertarArista(T, c1, c2);
}