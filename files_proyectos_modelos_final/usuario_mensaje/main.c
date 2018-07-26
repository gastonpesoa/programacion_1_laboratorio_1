#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Input.h"
#include "Parser.h"
#include "Functions.h"
#include "Usuario.h"
#include "Mensaje.h"

#define ARCH_1 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_final_4/mensajes.csv"
#define ARCH_2 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_final_4/usuarios.csv"
#define ARCH_3 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_final_4/feeds.csv"


int main(){

    //Definimos y creamos las listas
    ArrayList* mensajesList = al_newArrayList();
    ArrayList* usuariosList = al_newArrayList();
    if(mensajesList == NULL || usuariosList == NULL){
        printf("\nEspacio en memoria insuficiente\n");
        pause("\nPresione enter para salir\r\n");
        return 0;
    }

    //Se definen punteros a archivos del tipo FILE
    FILE *pMensajesFile = NULL;
    FILE *pUsuariosFile = NULL;
    FILE *pFeedFile = NULL;

    //Se definen variables de tipo int y char
    int rtrnParserMensajesFile, rtrnParserUsuariosFile;

    int opcionMenuPrincipal = 0, optionList = 0;
    //char confirma = 'n';

    //Menu principal
    while(opcionMenuPrincipal != 4){

        clearScreen();
        opcionMenuPrincipal = optionMainMenu();

        switch(opcionMenuPrincipal){

            case 1://Cargar listas

                clearScreen();
                //Se verifica que las listas esten vacias antes de cargarlas
                if(mensajesList->isEmpty(mensajesList) && usuariosList->isEmpty(usuariosList)){

                    printf("\r\nCargando listas...\r\n");
                    rtrnParserMensajesFile = parserMensajesListFile(pMensajesFile,mensajesList,ARCH_1);
                    rtrnParserUsuariosFile = parserUsuariosListFile(pUsuariosFile,usuariosList,ARCH_2);

                    if(rtrnParserMensajesFile == 0 && rtrnParserUsuariosFile == 0){
                        printf("\nListas cargadas con exito!\r\n");
                        pause("\nPresione enter para volver al menu principal\r\n");
                    }
                    else {
                        printf("Error leyando useros\n");
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
                            printf("\r\nLista de mensajes\r\n");
                            mensaje_printArrayList(mensajesList);
                            pause("\nPresione enter para volver\r\n");
                            break;

                        case 2://Lista dos
                            clearScreen();
                            printf("\r\nLista de usuarios\r\n");
                            user_printArrayList(usuariosList);
                            pause("\nPresione enter para volver\r\n");
                            break;

                        case 3://Vuelve al menu principal
                            continue;
                    }
                }
                break;

            case 3://

                clearScreen();
                printf("\nGenerando feed...\n");

                if(!feedToFile(pFeedFile,mensajesList,usuariosList,ARCH_3)){
                    printf("\nFeed generado con exito!\n");
                    pause("\nPresione enter para volver\r\n");
                }
                else{
                    printf("\nHubo un problema generando el feed\n");
                    pause("\nPresione enter para volver\r\n");
                }

                pause("\nPresione enter para volver al menu principal\r");
                break;

            case 4://Salir

                continue;

        }// switch(opcionMenuPrincipal)
    }//while(opcionMenuPrincipal != 6)

    //Se eliminan las listas de memoria y se cierra el programa
    mensajesList->deleteArrayList(mensajesList);
    usuariosList->deleteArrayList(usuariosList);

    return 0;
}
