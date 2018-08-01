#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayList.h"
#include "Entrega.h"
#include "Parser.h"


#define ARCH_1 "/Volumes/Almacen/UTN/Programacion I/Practicas/final_2/DATA_FINAL_V3.csv"
#define ARCH_2 "/Volumes/Almacen/UTN/Programacion I/Practicas/final_2/entregas.csv"


int main(){
    //Definimos y creamos las listas
    ArrayList* entregasList = al_newArrayList();
    ArrayList* localidadesList = al_newArrayList();
    if(entregasList == NULL || localidadesList == NULL){
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
    //Menu principal
    while(opcionMenuPrincipal != 5){

        clearScreen();
        opcionMenuPrincipal = optionMainMenu();
        switch(opcionMenuPrincipal){

            case 1://Cargar listas
                clearScreen();
                //Se verifica que la lista este vacia antes de cargarla
                if(entregasList->isEmpty(entregasList)){
                    //getValidStringArchivo("\nIngrese el nombre del archivo: ","\nEl nombre del archivo debe contener un solo punto y no debe contener los caracteres \\ / : * ? \" < > |",fileName);
                    //printf("%s\n", fileName);
                    printf("\r\nCargando lista...\r\n");
                    rtrnParserFile = parserEntregasListFile(pEntradaFile,entregasList,ARCH_1);
                    if(rtrnParserFile == 0){
                        pause("\nLista cargada con exito!\r\n\nPresione enter para volver al menu principal\r\n");
                    }
                    else {
                        pause("\nError leyando entregas\n\nPresione enter para volver al menu principal\r\n");
                    }
                }
                else{
                    pause("\r\nLa lista de las entregas ya estan cargadas\n\nPresione enter para volver al menu principal\r\n");
                }
                break;

            case 2://Mostrar lista
                clearScreen();
                printf("\n\n============================================\
                          \n|             * LISTA DE ENTREGAS *        |\
                          \n============================================\n");
                if(entregasList->isEmpty(entregasList)){
                    pause("\nCargue la lista antes de intentar mostrarla\nPresione enter para volver al menu principal\r\n");
                }
                else{
                    entrega_printArrayList(entregasList);
                    pause("\nPresione enter para volver\r\n");
                }
                break;

            case 3://
                clearScreen();
                printf("\n\n============================================\
                          \n|         * LISTA DE  LOCALIDADES *        |\
                          \n============================================\n");
                if(entregasList->isEmpty(entregasList)){
                    pause("\nCargue la lista antes de intentar listar las localidades\nPresione enter para volver al menu principal\r\n");
                }
                else{
                    localidadesList = entregasList->removeDuplicates(entregasList,entrega_compareByLocalidad);
                    entrega_printLocalidadesList(localidadesList);
                    pause("\nPresione enter para volver al menu principal\r");
                }
                break;

            case 4://
                clearScreen();
                printf("\n\n=================================================\
                          \n|         * GENERAR ARCHIVO DE REPARTO *        |\
                          \n=================================================\n");
                if(!generarArchivoDeReparto(pSalidaFile,ARCH_2,entregasList,localidadesList)){
                    pause("\nArchivo generado con exito!\nPresione enter para volver al menu principal\r\n");
                }
                else{
                    pause("\nError generado archivo\nPresione enter para volver al menu principal\r\n");
                }
                break;

            case 5://
                continue;
        }// switch(opcionMenuPrincipal)
    }//while(opcionMenuPrincipal != 6)
    //Se eliminan las listas de memoria y se cierra el programa
    entregasList->deleteArrayList(entregasList);
    localidadesList->deleteArrayList(localidadesList);
    return 0;
}
