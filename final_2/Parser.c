#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Entrega.h"
#include "Input.h"
#include "Parser.h"


int parserEntregasListFile(FILE *pFile , ArrayList *entregasList, char *fileName){

    //Se definen variables auxiliares
    int returnAux = -1;
    int readItem;
    char idStr[52],productoAux[52],direccionAux[52],localidadAux[52],recibeAux[52];
    int idAux;
    int flag = 0;

    //Se verifica que la lista ingresada no sea NULL
    if(entregasList == NULL){
        //En caso de lista NULL se informa y se sale retornando valor de Error
        printf("\r\nError, lista nula\r\n");
        pause("\r\nPresione enter para volver\r\n");
        return returnAux;
    }
    //Se abre el archivo, pasado como parametro, para lectura de texto
    //y se asigna puntero al archivo devuelto, al puntero pFile pasado como paramentro
    pFile = fopen(fileName,"r");
    if (pFile==NULL) {
        //Si fopen devuelve NULL se informa y se sale de la funcion retornando valor de error
        pause("\nNo se pudo abrir el archivo\n\r\nEnter para volver: ");
        return returnAux;
    }
    //Mientras no se llegue al final del archivo lo sigo recorriendo
    while(!feof(pFile)){
        //La primer linea que se lea del archivo es la cabecera por lo que no la agrego a la lista
        if(flag == 0){
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,productoAux,direccionAux,localidadAux,recibeAux);
            flag = 1;
            continue;
        }
        //Se realiza la lectura de los datos
        cleanStdin();
        readItem = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,productoAux,direccionAux,localidadAux,recibeAux);
        if(readItem == 5){
            //Si se leyeron todos datos para los campos necesarios del archivo
            //se realiza la conversion de cadena a entero de los datos necesarios
            idAux = atoi(idStr);
            //Se crea una nueva struct
            Entrega* entrega = entrega_new();
            //Se setean los datos a la struct
            entrega_setId(entrega,idAux,1);
            entrega_setProduct(entrega,productoAux,1,52);
            entrega_setDireccion(entrega,direccionAux,1,52);
            entrega_setLocalidad(entrega,localidadAux,1,52);
            entrega_setRecibe(entrega,recibeAux,1,52);
            //Se agrega la struct a la lista
            if(entregasList->add(entregasList,entrega) == -1){
                //En caso de error se informa y se sale retornando valor de error
                printf("\r\nNo se pudo ingresar el nuevo entregao, verifique espacio en memoria\r\n");
                return returnAux;
            }
            //entrega_print(entrega);
            //Si se realizo el parser correctamente se asigna valor de retorno Ok
            returnAux = 0;
        }
        else {
            //Si no se leyeron los datos necesarios se informa error y se sale retornando valor de error
            printf("\r\nNo se leyeron los datos correctamente\n");
            pause("\r\nEnter para salir: ");
            return returnAux;;
        }//if(readItem==4)
    }//while(!feof(pFile))
    //Si se recorrio todo el archivo y se cargaron todos los datos
    //Se cierra el archivo y se retorna valor de Ok
    fclose(pFile);
    return returnAux;
}


/*
int entregasListToFile(FILE *pFile, ArrayList *entregasList, char *fileName){

    //Se definen variables auxiliares
    int returnAux = -1;
    int i, arrayLenght, idAux, stockAux;
    char *productoAux;

    Entrega *entregaAux;

    //Se verifica que la lista ingresada no sea NULL
    if(entregasList == NULL){
        //En caso de lista NULL se informa y se sale retornando valor de Error
        printf("\r\nError, lista nula\r\n");
        pause("\r\nPresione enter para volver\r\n");
        return returnAux;
    }
    //Se abre el archivo, pasado como parametro, para escribir texto
    //y se asigna puntero al archivo devuelto, al puntero pFile pasado como paramentro
    if((pFile = fopen(fileName,"w+")) == NULL){
        //Si fopen devuelve NULL se informa y se sale de la funcion retornando valor de error
        printf("\r\nError al intentar abrir el archivo\r\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }
    //Se escribe cabecera del archivo
    cleanStdin();
    fprintf(pFile, "entregao,descripcion,cantidad\n");
    //Se obtiene la longitud de la lista a recorrer
    arrayLenght = entregasList->len(entregasList);

    for(i = 0; i < arrayLenght; i++){
        //Obtengo el primer elemento de la lista
        entregaAux = entregasList->get(entregasList,i);
        //Asigno los campos del elemento a las variables auxiliares
        idAux = entregaAux->entregaId;
        productoAux = entregaAux->producto;
        stockAux = entregaAux->stock;
        //Se escriben los datos obtenidos en el archivo
        cleanStdin();
        if((fprintf(pFile, "%d,%s,%d\n", idAux, productoAux, stockAux)) < 0){
            //En caso de error al escribir los datos se informa y se sale retornando valor de Error
            printf("\r\nError al intentar escribir la objecta en el archivo\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    }
    //Si se recorrio toda la lista y se escribieron todos los datos
    //Se cierra el archivo y se sale retornando valor de Ok
    fclose(pFile);
    returnAux = 0;
    return returnAux;
}

*/

