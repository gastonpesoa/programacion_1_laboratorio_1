#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Input.h"
#include "Parser.h"
#include "Functions.h"
#include "LogEntry.h"
#include "Service.h"

#define ARCH_1 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_final_5/log.txt"
#define ARCH_2 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_final_5/services.txt"
#define ARCH_3 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_final_5/warnings.txt"
#define ARCH_4 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_final_5/errors.txt"


int main(){

    //Definimos y creamos las listas
    ArrayList* logsEntryList = al_newArrayList();
    ArrayList* servicesList = al_newArrayList();
    if(logsEntryList == NULL || servicesList == NULL){
        printf("\nEspacio en memoria insuficiente\n");
        pause("\nPresione enter para salir\r\n");
        return 0;
    }

    //Se definen punteros a archivos del tipo FILE
    FILE *pLogFile = NULL;
    FILE *pServicesFile = NULL;
    FILE *pWarningsFile = NULL;
    FILE *pErrorsFile = NULL;
    
    //Se definen variables de tipo int y char
    int rtrnParserLogFile, rtrnParserServiceFile;

    int opcionMenuPrincipal = 0, optionList = 0;
    //char confirma = 'n';

    //Menu principal
    while(opcionMenuPrincipal != 5){

        clearScreen();
        opcionMenuPrincipal = optionMainMenu();

        switch(opcionMenuPrincipal){

            case 1://Cargar listas

                clearScreen();
                //Se verifica que las listas esten vacias antes de cargarlas
                if(logsEntryList->isEmpty(logsEntryList) && servicesList->isEmpty(servicesList)){

                    printf("\r\nCargando listas...\r\n");
                    rtrnParserLogFile = parser_LogsEntryListFile(pLogFile,logsEntryList,ARCH_1);
                    rtrnParserServiceFile = parser_ServicesListFile(pServicesFile,servicesList,ARCH_2);

                    if(rtrnParserLogFile == 0 && rtrnParserServiceFile == 0){
                        printf("\nListas cargadas con exito!\r\n");
                        pause("\nPresione enter para volver al menu principal\r\n");
                    }
                    else {
                        printf("Error leyando logEntryos\n");
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
                            logEntry_printArrayList(logsEntryList);
                            pause("\nPresione enter para volver\r\n");
                            break;

                        case 2://Lista dos
                            clearScreen();
                            printf("\r\nLista Dos\r\n");
                            service_printArrayList(servicesList);
                            pause("\nPresione enter para volver\r\n");
                            break;

                        case 3://Vuelve al menu principal
                            continue;
                    }
                }
                break;

            case 3://Procesar información

                clearScreen();
                printf("\n\n============================================\
                          \n|    *      PROCESAR INFORMACION    *      |\
                          \n============================================\n");

                if(!procesarInformacion(pWarningsFile,pErrorsFile,logsEntryList,servicesList,ARCH_3,ARCH_4)){
                    printf("\nDatos procesados con exito\n");
                    pause("");
                }
                pause("\nPresione enter para volver al menu principal\r");
                break;

            case 4://Mostrar estadisticas

                clearScreen();
                printf("\n\n============================================\
                          \n|            * ESTADISTICAS *              |\
                          \n============================================\n");


                mostrarEstadisticas(logsEntryList,servicesList);

                pause("\nPresione enter para volver al menu principal\r");
                break;

            case 5://Salir

                continue;

        }// switch(opcionMenuPrincipal)
    }//while(opcionMenuPrincipal != 6)

    //Se eliminan las listas de memoria y se cierra el programa
    logsEntryList->deleteArrayList(logsEntryList);
    servicesList->deleteArrayList(servicesList);

    return 0;
}
