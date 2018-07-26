#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Input.h"
#include "Parser.h"
#include "Functions.h"
#include "Product.h"

#define ARCH_1 ""
#define ARCH_2 ""


int main(){

    //Definimos y creamos las listas 
    ArrayList* listaUno = al_newArrayList();
    ArrayList* listaDos = al_newArrayList();
    if(listaUno == NULL || listaDos == NULL){
        printf("\nEspacio en memoria insuficiente\n");
        pause("\nPresione enter para salir\r\n");
        return 0;
    }

    //Se definen punteros a archivos del tipo FILE
    FILE *pFileUno = NULL;
    FILE *pFileDos = NULL;

    //Se definen variables auxiliares del tipo Product
    Product *productAux;

    //Se definen variables de tipo int y char
    int rtrnParserFileUno, rtrnParserFileDos;
    
    int opcionMenuPrincipal = 0, optionList = 0;
    char confirma = 'n';

    //Menu principal
    while(opcionMenuPrincipal != 6){

        clearScreen();
        opcionMenuPrincipal = optionMainMenu();

        switch(opcionMenuPrincipal){

            case 1://Cargar listas

                clearScreen();
                //Se verifica que las listas esten vacias antes de cargarlas
                if(listaUno->isEmpty(listaUno) && listaDos->isEmpty(listaDos)){

                    printf("\r\nCargando listas...\r\n");
                    rtrnParserFileUno = parserProductsListFile(pFileUno,listaUno,ARCH_1);
                    rtrnParserFileDos = parserProductsListFile(pFileDos,listaDos,ARCH_2);

                    if(rtrnParserFileUno == 0 && rtrnParserFileDos == 0){
                        printf("\nListas cargadas con exito!\r\n");
                        pause("\nPresione enter para volver al menu principal\r\n");
                    }
                    else {
                        printf("Error leyando productos\n");
                        pause("\nPresione enter para volver al menu principal\r\n");
                    }
                }
                else{
                    printf("\r\nLas listas de los depositos ya estan cargadas\n");
                    pause("\nPresione enter para volver al menu principal\r\n");
                }
                break;

            case 2://Mostrar listas

                optionList = 0;
                while(optionList != 3){

                    clearScreen();

                    optionList = optionListSelect();

                    switch(optionList){

                        case 1://Lista uno
                            clearScreen();
                            printf("\r\nLista Uno\r\n");
                            product_printArrayList(listaUno);
                            pause("\nPresione enter para volver\r\n");
                            break;

                        case 2://Lista dos
                            clearScreen();
                            printf("\r\nLista Dos\r\n");
                            product_printArrayList(listaDos);
                            pause("\nPresione enter para volver\r\n");
                            break;

                        case 3://Vuelve al menu principal
                            continue;
                    }
                }
                break;

            case 3://

                clearScreen();
                printf("\n\n============================================\
                          \n| *  * |\
                          \n============================================\n");

                
                pause("\nPresione enter para volver al menu principal\r");
                break;

            case 4://

                clearScreen();
                printf("\n\n=================================================\
                          \n| *  * |\
                          \n=================================================\n");

                
                pause("\r\nPresione enter para volver al menu principal\r\n");
                break;

            case 5://

                clearScreen();
                printf("\n\n=================================================\
                          \n|   *  *  |\
                          \n=================================================\n");

                
                pause("\r\nPresione enter para volver al menu principal\r\n");
                break;

            case 6://Salir

                continue;

        }// switch(opcionMenuPrincipal)
    }//while(opcionMenuPrincipal != 6)

    //Se eliminan las listas de memoria y se cierra el programa
    listaUno->deleteArrayList(listaUno);
    listaDos->deleteArrayList(listaDos);

    return 0;
}
