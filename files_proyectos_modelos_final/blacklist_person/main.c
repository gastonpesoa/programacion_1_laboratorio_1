#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Person.h"
#include "Input.h"
#include "Parser.h"


#define ARCH_1 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_segundo_parcial_clase/modelo_segundo_parcial_clase/destinatarios.csv"
#define ARCH_2 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_segundo_parcial_clase/modelo_segundo_parcial_clase/black_list.csv"
#define ARCH_3 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_segundo_parcial_clase/modelo_segundo_parcial_clase/depurada.csv"


int main(){

    FILE* pDestFile = NULL;
    FILE* pBLFile = NULL;
    FILE* pDepFile = NULL;

    int opcionMenuPrincipal = 0;

    ArrayList* destinatariosList = al_newArrayList();
    if(destinatariosList == NULL){
		printf("\r\nEspacio en memoria insuficiente\r\n");
		return 0;
	}

	ArrayList* blackList = al_newArrayList();
    if(blackList == NULL){
		printf("\r\nEspacio en memoria insuficiente\r\n");
		return 0;
	}

    while(opcionMenuPrincipal != 5){

        opcionMenuPrincipal = optionMainMenu();

        switch(opcionMenuPrincipal){

            case 1: //Cargar destinatarios

                printf("\r\nCargando Lista destinatarios\r\n");

                if(parserPerson(pDestFile, destinatariosList, ARCH_1) == -1){

                    printf("\r\nError al cargar el archivo\r\n");
                    return 0;
                }
                else {
                    printf("\r\nLista destinatarios cargada con exito\r\n");
                    pause("\n\rPresione enter para continuar: ");
                }

                break;

            case 2: //Cargar lista negra

                printf("\r\nCargando Lista negra\r\n");

                if(parserPerson(pBLFile, blackList, ARCH_2) == -1){

                    printf("\r\nError al cargar el archivo\r\n");
                    return 0;
                }
                else {
                    printf("\r\nLista negra cargada con exito\r\n");
                    pause("\n\rPresione enter para continuar: ");
                }

                break;

            case 3: //Depurar

                printf("\r\nDepurando lista...\r\n");

                ArrayList* depuradaList = listDebugger(destinatariosList, blackList);
                if(depuradaList == NULL){
                    printf("\r\nError al intentar depurar la lista\r\n");
                    return 0;
                }

                printf("\r\nLista depurada con exito\r\n");
                pause("\n\rPresione enter para continuar: ");

                break;

            case 4: //Listar

                printf("\r\nLista depurada\r\n\r\n");

                person_printArrayList(depuradaList);

                printf("\r\nEscribiendo lista en archivo...\r\n");

                if(!person_toText(pDepFile, depuradaList, ARCH_3)){

                    printf("\r\nLista cargada en archivo con exito\r\n");
                }
                else {
                    printf("\r\nError al escribir el archivo\r\n");
                    return 0;
                }

                pause("\n\rPresione enter para continuar: ");

                break;

            case 5: //Salir

                continue;
        }
    }

    return 0;
}

