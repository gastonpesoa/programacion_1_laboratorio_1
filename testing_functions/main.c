

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Object.h"
#include "Files.h"
#include "Input.h"

#define ARCH_1 "/Volumes/Almacen/UTN/Programacion I/Practicas/testing_functions/testing_functions/bin.dat"
#define ARCH_2 "/Volumes/Almacen/UTN/Programacion I/Practicas/testing_functions/testing_functions/text.txt"
#define ARCH_3 "/Volumes/Almacen/UTN/Programacion I/Practicas/testing_functions/testing_functions/objects.csv"


int main(){

	//Se definen punteros a archivos del tipo FILE
	FILE *pBinFile = NULL;
    FILE *pTxtFile = NULL;

    char textToWrite[256];

    //Se crea una lista del tipo arrayList
    ArrayList *objectsList = al_newArrayList();
    if(objectsList == NULL){
		printf("\r\nEspacio en memoria insuficiente\r\n");
		pause("\r\nPresione enter para salir\r\n");
		return 0;
	}

	//Hardcodeo de objetos para testing
	object_testing(objectsList);

	int opcionMenuPrincipal = 0;
    int opcionMenuModificar = 0;

    //Menu principal
    while(opcionMenuPrincipal != 13){

        opcionMenuPrincipal = optionMainMenu();

        switch(opcionMenuPrincipal){

            case 1: //Altas

            	//Se solicitan, validan y setean los datos del objeto en la estructura Object
            	if(object_enter(objectsList,1,1000,1,51,1,51,1,150) == -1){

            		printf("\r\nNo se pudo ingresar el nuevo objeto, verifique espacio en memoria\r\n");
            		pause("\r\nPresione enter para volver al menu principal\r\n");
            	}

                break; //case 1: Altas

            case 2: //2 - Escribir en archivo .txt

                getStringSpace("\r\nIngrese el texto que desea imprimir en el archivo: ",textToWrite);
                if(!file_writeText(pTxtFile,ARCH_2,textToWrite)){
                	printf("\r\nSe imprimio el texto con exito\n");
                	pause("\r\nPresione enter para volver al menu principal\r\n");
                }

                break; // 2 - Escribir en archivo .txt

            case 3: //3 - Leer de archivo .txt



                break; // 3 - Leer de archivo .txt

            case 4: // 4 - Lista a .txt

                break; // 4 - Lista a .txt

            case 5: // 5 - Parser .txt

                break; // 5 - Parser .txt

            case 6: // 6 - Lista a .dat

                break; // 6 - Lista a .dat

            case 7: // 7 - .dat a Lista

                break; // 7 - .dat a Lista

            case 8: // 8 - Modificar en .dat

                break; // 8 - Modificar en .dat

            case 9: // 9 - Menu modificar

            	//Menu modificar
                while(opcionMenuModificar != 4){

            		opcionMenuModificar = optionModifyMenu();

            		switch(opcionMenuModificar){

            			case 1: // Modificar descripcion


            				break;
            			case 2: // Modificar importe
            				break;
            			case 3: // Modificar cantidad
            				break;
            			case 4: // Regresar
            				continue;
            		} // switch(opcionMenuModificar)
            	} // while(opcionMenuModificar != 4)

                break; // 9 - Menu modificar

            case 10: // 10 - Baja logica

                break; // 10 - Baja logica

            case 11: // 11 - Baja fisica

                break; // 11 - Baja fisica

            case 12: // 12 - Listar

                break;// 12 - Listar

            case 13: //Salir
                continue;
        }
    }


    return 0;
}
