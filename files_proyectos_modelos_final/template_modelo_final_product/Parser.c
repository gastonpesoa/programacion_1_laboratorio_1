#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Product.h"
#include "Input.h"
#include "Parser.h"


int parserProductsListFile(FILE *pFile , ArrayList *productsList, char *fileName){

    //Se definen variables auxiliares
    int returnAux = -1;
    int readItem;
    char idStr[51],descriptionAux[51],stockStr[51];
    int idAux, stockAux;
    int flag = 0;

    //Se verifica que la lista ingresada no sea NULL
    if(productsList == NULL){
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
        printf("\r\nNo se pudo abrir el archivo\n");
        pause("\r\nEnter para volver: ");
        return returnAux;
    }
    //Mientras no se llegue al final del archivo lo sigo recorriendo
    while(!feof(pFile)){
        //La primer linea que se lea del archivo es la cabecera por lo que no la agrego a la lista
        if(flag == 0){
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idStr,descriptionAux,stockStr);
            flag = 1;
            continue;
        }
        //Se realiza la lectura de los datos 
        cleanStdin();
        readItem = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idStr,descriptionAux,stockStr);
        if(readItem == 3){
            //Si se leyeron todos datos para los campos necesarios del archivo
            //se realiza la conversion de cadena a entero de los datos necesarios
            idAux = atoi(idStr);
            stockAux = atoi(stockStr);
            //Se crea una nueva struct
            Product* product = product_new();
            //Se setean los datos a la struct
            product_setId(product,idAux,1);
            product_setDescription(product,descriptionAux,1,51);
            product_setStock(product,stockAux,1);
            //Se agrega la struct a la lista
            if(productsList->add(productsList,product) == -1){
                //En caso de error se informa y se sale retornando valor de error
                printf("\r\nNo se pudo ingresar el nuevo producto, verifique espacio en memoria\r\n");
                return returnAux;
            }
            //product_print(product);
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



int productsListToFile(FILE *pFile, ArrayList *productsList, char *fileName){
    
    //Se definen variables auxiliares
    int returnAux = -1;
    int i, arrayLenght, idAux, stockAux;
    char *descriptionAux;

    Product *productAux;

    //Se verifica que la lista ingresada no sea NULL
    if(productsList == NULL){
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
    fprintf(pFile, "producto,descripcion,cantidad\n");
    //Se obtiene la longitud de la lista a recorrer
    arrayLenght = productsList->len(productsList);

    for(i = 0; i < arrayLenght; i++){
        //Obtengo el primer elemento de la lista
        productAux = productsList->get(productsList,i);
        //Asigno los campos del elemento a las variables auxiliares
        idAux = productAux->productId;
        descriptionAux = productAux->description;
        stockAux = productAux->stock;
        //Se escriben los datos obtenidos en el archivo
        cleanStdin();
        if((fprintf(pFile, "%d,%s,%d\n", idAux, descriptionAux, stockAux)) < 0){
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



