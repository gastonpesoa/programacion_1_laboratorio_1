#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Entrega.h"
#include "Input.h"
#include "Parser.h"
#include "Functions.h"

int imprimirArchivoPorLocalidad(ArrayList* entregasList, char* localidad, FILE *pFile){

    int i, idAux, returnAux = -1;
    char productoAux[51], direccionAux[51], recibeAux[51], localidadAux[51];
    Entrega *entregaAux;

    for(i = 0; i < entregasList->len(entregasList); i++){

        entregaAux = entregasList->get(entregasList,i);

        strcpy(localidadAux,entrega_getLocalidad(entregaAux));
        idAux = entrega_getId(entregaAux);
        strcpy(direccionAux,entrega_getDireccion(entregaAux));
        strcpy(productoAux,entrega_getProduct(entregaAux));
        strcpy(recibeAux,entrega_getRecibe(entregaAux));

        if(!strcmp(localidadAux,localidad)){
            if((fprintf(pFile, "%d,%s,%s,%s,%s,\n", idAux, productoAux, direccionAux, localidadAux, recibeAux)<0)){
                pause("\nError al intentar escribir en el archivo\n\r\nEnter para volver: ");
                return returnAux;
            }
        }
    }
    return returnAux;
}

void getValidLocalidad(ArrayList* entregasList, ArrayList* localidadesList, char *msg, char *localidad){

    int i;
    char localidadAux[51];
    Entrega* entregaAux;

    printf("\n=============================================\n| Lista de localidades:        \n=============================================\n");

    do{
        entrega_printLocalidadesList(localidadesList);
        getValidStringAlfanumerico(msg,"\nLa localidad debe ser solo letras y numeros\n",localidad);
        capitalize(localidad);
        for(i = 0; i < entregasList->len(entregasList); i++){
            entregaAux = entregasList->get(entregasList,i);
            strcpy(localidadAux,entrega_getLocalidad(entregaAux));
            if(!strcmp(localidadAux,localidad)){
                break;
            }
        }
        if(strcmp(localidadAux,localidad) != 0){
            clearScreen();
            printf("No se encontro coincidencia con la localidad ingresasda, vuelva a intentar\n");
        }
    }while(strcmp(localidadAux,localidad) != 0);
}

int generarArchivoDeReparto(FILE *pFile, char *fileName, ArrayList* entregasList, ArrayList* localidadesList){

    char localidadUno[51], localidadDos[51], localidadTres[51];
    int returnAux = -1;

    getValidLocalidad(entregasList,localidadesList,"\nIngrese localidad uno: ",localidadUno);
    getValidLocalidad(entregasList,localidadesList,"\nIngrese localidad dos: ",localidadDos);
    getValidLocalidad(entregasList,localidadesList,"\nIngrese localidad tres: ",localidadTres);

    pFile = fopen(fileName,"w");
    if(pFile == NULL){
        pause("\nNo se pudo abrir el archivo\n\r\nEnter para volver: ");
    }
    else{
        fprintf(pFile, "id,producto,direccion,localidad,recibe\n");

        imprimirArchivoPorLocalidad(entregasList,localidadUno, pFile);
        imprimirArchivoPorLocalidad(entregasList,localidadDos, pFile);
        imprimirArchivoPorLocalidad(entregasList,localidadTres, pFile);

        returnAux = 0;
        fclose(pFile);
    }
    return returnAux;
}


