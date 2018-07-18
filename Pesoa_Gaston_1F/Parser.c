#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Product.h"
#include "Input.h"
#include "Parser.h"


int parserDep(FILE* pFile , ArrayList* depList, char* archivo){

    int returnAux = -1;
    int readItem;
    char idStr[256],descriptionAux[256],stockStr[256];
    int idAux, stockAux;
    int flag = 0;

    if(depList == NULL){
        printf("\r\nError, lista nula\r\n");
        pause("\r\nPresione enter para volver\r\n");
        return returnAux;
    }

    pFile = fopen(archivo,"r");
    if (pFile==NULL) {

        printf("\r\nNo se pudo abrir el archivo\n");
        pause("\r\nEnter para volver: ");
        return returnAux;
    }

    while(!feof(pFile)){

        if(flag == 0){

            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idStr,descriptionAux,stockStr);
            flag = 1;
            continue;
        }
        cleanStdin();
        readItem = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idStr,descriptionAux,stockStr);
        if(readItem == 3){

            idAux = atoi(idStr);
            stockAux = atoi(stockStr);

            Product* product = product_new();
            product_setId(product,idAux,1);
            product_setDescription(product,descriptionAux,1,256);
            product_setStock(product,stockAux,1);

            if(depList->add(depList,product) == -1){
                printf("\r\nNo se pudo ingresar el nuevo producto, verifique espacio en memoria\r\n");
                return returnAux;
            }

            //product_print(product);

            returnAux = 0;
        }
        else {

            printf("\r\nNo se leyeron los datos correctamente\n");
            pause("\r\nEnter para salir: ");
            return returnAux;;
        }//if(readItem==4)
    }//while(!feof(pFile))

    fclose(pFile);
    return returnAux;
}



int depToText(FILE *pFile, ArrayList *depList, char *fileName){

    int returnAux = -1;
    int i, arrayLenght, idAux, stockAux;
    char *descriptionAux;

    Product *productAux;

    if((pFile = fopen(fileName,"w+")) == NULL){
        printf("\r\nError al intentar abrir el archivo\r\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }

    arrayLenght = depList->len(depList);

    for(i = 0; i < arrayLenght; i++){

        productAux = depList->get(depList,i);

        idAux = productAux->idProduct;
        descriptionAux = productAux->description;
        stockAux = productAux->stock;

        cleanStdin();
        if((fprintf(pFile, "%d,%s,%d\n", idAux, descriptionAux, stockAux)) < 0){
            printf("\r\nError al intentar escribir la objecta en el archivo\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    }

    fclose(pFile);
    returnAux = 0;
    return returnAux;
}



