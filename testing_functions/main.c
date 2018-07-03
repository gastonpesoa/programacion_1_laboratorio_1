

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
#define ARCH_3 "/Volumes/Almacen/UTN/Programacion I/Practicas/testing_functions/testing_functions/listToText.txt"
#define ARCH_4 "/Volumes/Almacen/UTN/Programacion I/Practicas/testing_functions/testing_functions/objects.csv"


int main(){

	//Se definen punteros a archivos del tipo FILE
	FILE *pBinFile = NULL;
    FILE *pTxtFile = NULL;
    FILE *pListToTxtFile = NULL;

    char textToWrite[256];
    char textRead[256];
    char confirmaIngreso = 'n';

    int idAux;

    Object *objectAux;

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

            	if(!file_readText(pTxtFile, ARCH_2, textRead)){
            		printf("\r\nSe leyo del texto: %s\n", textRead);
                	pause("\r\nPresione enter para volver al menu principal\r\n");
            	}

                break; // 3 - Leer de archivo .txt

            case 4: // 4 - Lista a .txt

            	if(!file_listToText(pListToTxtFile, objectsList, ARCH_3)){
            		printf("\r\nSe escribio la lista en el archivo de texto\n");
                	pause("\r\nPresione enter para volver al menu principal\r\n");
            	}

                break; // 4 - Lista a .txt

            case 5: // 5 - Parser .txt

            	free(objectsList);
            	objectsList = file_parserText(pListToTxtFile, ARCH_3);
            	if(objectsList == NULL){
            		break;
            	}
            	else {
            		printf("\r\nSe cargo: \n");
            		object_printArrayList(objectsList);
                	pause("\r\nPresione enter para volver al menu principal\r\n");
            	}

            	break; // 5 - Parser .txt

            case 6: // 6 - Lista a .dat

            	if(!file_listToBin(pBinFile, objectsList, ARCH_1)){
            		printf("\r\nSe escribio la lista en el archivo binario\n");
                	pause("\r\nPresione enter para volver al menu principal\r\n");
            	}

                break; // 6 - Lista a .dat

            case 7: // 7 - .dat a Lista

            	free(objectsList);
            	objectsList = file_binToList(pBinFile, ARCH_1);
            	if(objectsList == NULL){
            		break;
            	}
            	else {
            		printf("\r\nSe cargo: \n");
            		object_printArrayList(objectsList);
                	pause("\r\nPresione enter para volver al menu principal\r\n");
            	}

                break; // 7 - .dat a Lista

            case 8: // 8 - Modificar en .dat

            	if(!file_modifyInBin(pBinFile, objectsList, ARCH_1)){
            		//file_binToList(pBinFile, objectsListBinRead, ARCH_1);
            		printf("\r\nLista modificada:\n");
            	}

                break; // 8 - Modificar en .dat

            case 9: // 9 - Menu modificar

            	printf("\r\nModificar\n");
            	object_printArrayList(objectsList);
            	//Se solicita el Id del objeto a modificar
    			idAux = getValidInt("\r\nIngrese el Id del objeto a modificar: ","\r\nEl Id debe ser numerico\r\n",1,1000);

    			objectAux = objectsList->get(objectsList,idAux-1);
    			while(objectAux == NULL){

    				printf("\r\nNo hay ningun objeto registrado con el Id ingresado\r\n");
    				confirmaIngreso = confirm("\r\nPresione 's' para volver a ingresar el Id o 'n' para salir: [s|n] ");

		            if(confirmaIngreso == 's'){
		                idAux = getValidInt("\r\nReingrese el Id del objeto a modificar: ","\r\nEl Id debe ser numerico\r\n",1,1000);
		            	objectAux = objectsList->get(objectsList,idAux-1);
		            }
		            else {
		                break;
		            }
    			}

    			printf("\r\nSe encontro\n");
    			object_print(objectAux);
            	//Menu modificar
                while(opcionMenuModificar != 4){

            		opcionMenuModificar = optionModifyMenu();

            		switch(opcionMenuModificar){

            			case 1: // Modificar nombre
            				getValidString("\r\nIngrese el nuevo nombre: ","El nombre debe ser solo letras",objectAux->name);
                            object_print(objectAux);
            				break;
            			case 2: // Modificar mail
            				getValidStringMail("Ingrese el nuevo mail: ","Mail invalido", objectAux->mail);
            				break;
            			case 3: // Modificar edad
            				objectAux->age = getValidInt("Ingrese la nueva edad: ","La edad debe ser numerica",1,150);
            				break;
            			case 4: // Confirmar y modificar archivo
            				if(!file_modifyObjectFromBin(pBinFile, objectAux, ARCH_1)){
			            		printf("\r\nObjeto modificado del archivo\n");
			            	}
            				break;
            			case 5: // Regresar
            				continue;
            		} // switch(opcionMenuModificar)
            	} // while(opcionMenuModificar != 4)

                break; // 9 - Menu modificar

            case 10: // 10 - Baja logica

            	printf("\r\nBaja logica\n");
            	object_printArrayList(objectsList);

            	free(objectAux);
                objectAux = object_requestValidId(objectsList);

                if(objectAux != NULL){
                    printf("\r\nSe encontro: \n");
                    object_print(objectAux);
                }
                else {
                    break;
                }

    			if(!file_logicRemove(pBinFile, objectAux, ARCH_1)){
            		printf("\r\nObjeto dado de baja logica del archivo\n");
            		pause("\r\nPresione enter para volver al menu principal\r\n");
            	}	

                break; // 10 - Baja logica

            case 11: // 11 - Baja fisica

            	printf("\r\nBaja fisica\n");
            	object_printArrayList(objectsList);
            	//Se solicita el Id del objeto a modificar
    			idAux = getValidInt("\r\nIngrese el Id del objeto a dar de baja: ","\r\nEl Id debe ser numerico\r\n",1,1000);

    			objectAux = objectsList->get(objectsList,idAux-1);
    			while(objectAux == NULL){

    				printf("\r\nNo hay ningun objeto registrado con el Id ingresado\r\n");
    				confirmaIngreso = confirm("\r\nPresione 's' para volver a ingresar el Id o 'n' para salir: [s|n] ");

		            if(confirmaIngreso == 's'){
		                idAux = getValidInt("\r\nReingrese el Id del objeto a modificar: ","\r\nEl Id debe ser numerico\r\n",1,1000);
		            	objectAux = objectsList->get(objectsList,idAux-1);
		            }
		            else {
		                break;
		            }
    			}

    			if(!objectsList->remove(objectsList,idAux-1)){
    				printf("\r\nSe removio el objeto de la lista\n");
    			}
    			object_printArrayList(objectsList);
    			pause("\r\nPresione enter para volver al menu principal\r\n");

                break; // 11 - Baja fisica

            case 12: // 12 - Listar

            	free(objectsList);
            	objectsList = file_binToList(pBinFile,ARCH_1);
            	if(objectsList == NULL){
            		break;
            	}
            	else {
            		if(!objectsList->sort(objectsList,object_compareByName,1)){
            			printf("\r\nLista ordenada por nombre: \r\n");
            			object_printArrayList(objectsList);
                		pause("\r\nPresione enter para volver al menu principal\r\n");
            		}
            		else {
            			printf("\r\nError en el odenamiento, verifique que se halla cargado la lista\n");
            			pause("\r\nPresione enter para volver al menu principal\r\n");
            		}
            	}

                break;// 12 - Listar

            case 13: //Salir
                continue;
        }
    }

    free(objectAux);
    free(objectsList);
    
    return 0;
}
