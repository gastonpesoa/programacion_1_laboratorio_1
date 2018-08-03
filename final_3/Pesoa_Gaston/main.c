#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayList.h"
#include "Llamada.h"
#include "Parser.h"

#define ARCH_1 ""
#define ARCH_2 "clientes.csv"


int main(){
    //Definimos y creamos las listas
    ArrayList* llamadasList = al_newArrayList();
    if(llamadasList == NULL){
        printf("\nEspacio en memoria insuficiente\n");
        pause("\nPresione enter para salir\r\n");
        return 0;
    }
    //Se definen punteros a archivos del tipo FILE
    FILE *pEntradaFile = NULL;
    FILE *pSalidaFile = NULL;
    //Se definen variables auxiliares de tipo int y char
    int rtrnParserFile;
    int opcionMenuPrincipal = 0;
    char fileName[256];
    //Menu principal
    while(opcionMenuPrincipal != 5){

        clearScreen();
        opcionMenuPrincipal = optionMainMenu();
        switch(opcionMenuPrincipal){

            case 1://Cargar listas
                clearScreen();
                //Se verifica que la lista este vacia antes de cargarla
                if(llamadasList->isEmpty(llamadasList)){
                    getValidStringArchivo("\nIngrese el nombre del archivo: ","\nEl nombre del archivo debe contener un solo punto y no debe contener los caracteres \\ / : * ? \" < > |",fileName);
                    printf("%s\n", fileName);
                    printf("\r\nCargando lista...\r\n");
                    rtrnParserFile = parserLlamadasListFile(pEntradaFile,llamadasList,fileName);
                    if(rtrnParserFile == 0){
                        pause("\nLista cargada con exito!\r\n\nPresione enter para volver al menu principal\r\n");
                    }
                    else {
                        pause("\nError leyando llamadas\n\nPresione enter para volver al menu principal\r\n");
                    }
                }
                else{
                    pause("\r\nLa lista de las llamadas ya estan cargadas\n\nPresione enter para volver al menu principal\r\n");
                }
                break;

            case 2://Mostrar lista
                clearScreen();
                printf("\n\n============================================\
                          \n|          *    MOSTRAR LISTA    *         |\
                          \n============================================\n");
                if(llamadasList->isEmpty(llamadasList)){
                    pause("\nCargue la lista antes de intentar mostrarla\nPresione enter para volver al menu principal\r\n");
                }
                else{
                    llamadasList->sort(llamadasList,llamada_compareById);
                    llamada_printArrayList(llamadasList);
                    pause("\nPresione enter para volver\r\n");
                }
                break;

            case 3://
                clearScreen();
                if(llamadasList->isEmpty(llamadasList)){
                    pause("\nCargue la lista antes de intentar mostrarla\nPresione enter para volver al menu principal\r\n");
                }else{
                    printf("\n\n============================================\
                          \n|         * ESTADISTICAS          *        |\
                          \n============================================\n");
                    imprimirEstadisticas(llamadasList);
                    pause("\nPresione enter para volver\r\n");
                }
                break;

            case 4://
                clearScreen();
                printf("\nGenerando archivo de clientes..");
                if(!llamadasListToFile(pSalidaFile,llamadasList,ARCH_2)){
                    printf("\nArchivo generado con exito");
                }

                pause("\nPresione enter para volver\r\n");
                break;

            case 5://
                continue;
        }// switch(opcionMenuPrincipal)
    }//while(opcionMenuPrincipal != 6)
    //Se eliminan las listas de memoria y se cierra el programa
    llamadasList->deleteArrayList(llamadasList);
    return 0;
}
