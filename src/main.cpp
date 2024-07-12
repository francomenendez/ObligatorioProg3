#include "lineas.h"
#include "tramos.h"

int main() {

    Lineas L;
    Tramos T;
    int c1, c2, ult, act;

    Ciudades C;
    string str1, strciudad;

    int num;
    boolean proceder=TRUE;

    CrearLineas(L);
    CrearCiudades(C);
    StrCrear(str1);

    while (proceder){
        printf("\n\nIngrese: \n1-registrar una ciudad \n2-desplegar las ciudades \n3-registrar un tramo entre dos ciudades \n4-verificar si existe una secuencia de tramos entre dos ciudades \n5-registrar una línea nueva \n6-desplegar los datos básicos de todas las líneas \n7-agregar una parada a una línea \n8-desplegar todas las paradas de una línea \n9-salir del programa \n");
        scanf("%d", &num);

        switch (num){
            case 1:
                    printf("\nIngrese la ciudad a registrar en el sistema: ");
                    cargarString(str1);
                    RegistrarCiudad(C, str1);
                    break;
            case 2: 
                    DesplegarCiudades(C);
                    break;
            case 3:  
                    printf("\nIngrese los numeros de las ciudades para registrar el tramo: ");
                    scanf("%d %d", &c1, &c2);
                    if (!EsLlenaCiudades(C))
                        printf("\n No se han registrado las %d ciudades", N);
                    else
                        RegistrarTramo (T, c1-1, c2-1);
                    break;
            case 4: 
                    printf("\nIngrese los numeros de las ciudades a verificar si hay una secuencia de tramos: ");
                    scanf("%d %d", &c1, &c2);
                    if (!EsLlenaCiudades(C))
                        printf("\n No se han registrado las %d ciudades", N);
                    else if ( (c1-1)>=N || (c2-1)>=N )
                            printf("\nNo existe ciudad con dicho número, estas van de 1 a %d", N);
                    else if (ExisteSecuencia (T, c1-1, c2-1))
                            printf("\nSi existe una secuencia entre las ciudades");
                        else
                            printf("\nNo hay secuencia entre las dos ciudades");
                    break;
            case 5: 
                    printf("\nIngrese el codigo alfanumerico de la linea que desea registrar en el sistema: ");
                    cargarString(str1);
                    if (!SoloAlfaNumerico(str1))
                        printf("\nEl codigo solo debe contener letras y números");
                    else if (ExisteLinea(L, str1))
                        printf("\nYa existe una línea con ese codigo");
                    else
                        InsertarLineaNueva(L, str1);
                    break;
                    
            case 6: 
                    if(EsVaciaLineas(L))
                        printf("\nNo hay lineas en el sistema.");
                    else
                        DesplegarDatosdeLineas(L);
                    break;
            case 7: 
                    printf("\nIngrese la línea en la que desea añadir una parada: ");
                    cargarString(str1);
                    if (!ExisteLinea(L, str1))
                        printf("\nLa línea no existe en el sistema");
                    else {
                        printf("\nIngrese el número de la ciudad que desea añadir a la línea: ");
                        scanf("%d", &act);
                        if (!EsLlenaCiudades(C))
                            printf("\n No se han registrado las %d ciudades", N);
                        else if ( (act-1)>= N) 
                            printf("\nNo existe ciudad con dicho número, estas van de 1 a %d", N);
                        else {
                            if (EsVaciaParadas(EncontrarLinea(L,str1))) {
                                DevolverCiudad(C, act, strciudad);
                                InsertarParadaEnLinea(L, str1, strciudad);
                            }
                            else {
                                UltimaParada(EncontrarLinea(L, str1), strciudad);
                                ult = DevolverNumCiudad(C, strciudad);
                                //act guarda la ciudad a ingresar y ult la ultima de la linea
                                if (!PerteneceArista(T, ult-1, act-1)) {
                                    printf("\nNo hay un tramo de recorrido entre ");
                                    DevolverCiudad(C, ult, strciudad);
                                    print(strciudad);
                                    printf("(última ciudad de la línea) y ");
                                    DevolverCiudad(C, act, strciudad);
                                    print(strciudad);
                                    printf("(ciudad ingresada).");
                                } else {
                                    DevolverCiudad(C, act, strciudad);
                                    InsertarParadaEnLinea(L, str1, strciudad);
                                }
                            }
                            
                        }   
                    }    
                    break;
            case 8: 
                    printf("\nIngrese la línea: ");
                    cargarString(str1);
                    if (!ExisteLinea(L, str1)) 
                        printf("\nLa linea ingresada no existe");
                    else if (EsVaciaParadas(EncontrarLinea(L,str1))) 
                        printf("\nLa línea ingresada no tiene paradas");
                    else 
                        DesplegarLinea (L, str1, C);
                    break;
            case 9: 
                    proceder=FALSE;
                    break;
        }
    } 
}