#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayList.h"
#include "Product.h"
#include "Parser.h"

#define ARCH_1 ""
#define ARCH_2 ""


int main(){
    //Definimos y creamos las listas
    ArrayList* productsList = al_newArrayList();
    ArrayList* localidadesList = al_newArrayList();
    if(productsList == NULL || localidadesList == NULL){
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
                if(productsList->isEmpty(productsList)){
                    getValidStringArchivo("\nIngrese el nombre del archivo: ","\nEl nombre del archivo debe contener un solo punto y no debe contener los caracteres \\ / : * ? \" < > |",fileName);
                    //printf("%s\n", fileName);
                    printf("\r\nCargando lista...\r\n");
                    rtrnParserFile = parserProductsListFile(pEntradaFile,productsList,fileName);
                    if(rtrnParserFile == 0){
                        pause("\nLista cargada con exito!\r\n\nPresione enter para volver al menu principal\r\n");
                    }
                    else {
                        pause("\nError leyando products\n\nPresione enter para volver al menu principal\r\n");
                    }
                }
                else{
                    pause("\r\nLa lista de las products ya estan cargadas\n\nPresione enter para volver al menu principal\r\n");
                }
                break;

            case 2://Mostrar lista
                clearScreen();
                printf("\n\n============================================\
                          \n|             *  *        |\
                          \n============================================\n");
                if(productsList->isEmpty(productsList)){
                    pause("\nCargue la lista antes de intentar mostrarla\nPresione enter para volver al menu principal\r\n");
                }
                else{
                    product_printArrayList(productsList);
                    pause("\nPresione enter para volver\r\n");
                }
                break;

            case 3://
                clearScreen();
                printf("\n\n============================================\
                          \n|         * *        |\
                          \n============================================\n");
                if(productsList->isEmpty(productsList)){
                    pause("\nCargue la lista antes de intentar listar las localidades\nPresione enter para volver al menu principal\r\n");
                }
                else{
                    localidadesList = productsList->removeDuplicates(productsList,product_compareByLocalidad);
                    product_printLocalidadesList(localidadesList);
                    pause("\nPresione enter para volver al menu principal\r");
                }
                break;

            case 4://
                clearScreen();
                printf("\n\n=================================================\
                          \n|         *  *        |\
                          \n=================================================\n");
                if(!generarArchivoDeReparto(pSalidaFile,ARCH_2,productsList,localidadesList)){
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
    productsList->deleteArrayList(productsList);
    localidadesList->deleteArrayList(localidadesList);
    return 0;
}
