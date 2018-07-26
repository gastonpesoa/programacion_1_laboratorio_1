#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Product.h"
#include "Input.h"
#include "Parser.h"


int parserProductsListFile(FILE *pFile , ArrayList *productsList, char *fileName){

    int returnAux = -1;
    int readItem;
    char idStr[51],descriptionAux[51],stockStr[51];
    int idAux, stockAux;
    int flag = 0;

    if(productsList == NULL){
        printf("\r\nError, lista nula\r\n");
        pause("\r\nPresione enter para volver\r\n");
        return returnAux;
    }

    pFile = fopen(fileName,"r");
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
            product_setDescription(product,descriptionAux,1,51);
            product_setStock(product,stockAux,1);

            if(productsList->add(productsList,product) == -1){
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



int productsListToFile(FILE *pFile, ArrayList *productsList, char *fileName){

    int returnAux = -1;
    int i, arrayLenght, idAux, stockAux;
    char *descriptionAux;

    Product *productAux;

    if((pFile = fopen(fileName,"w+")) == NULL){
        printf("\r\nError al intentar abrir el archivo\r\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }
    cleanStdin();
    fprintf(pFile, "producto,descripcion,cantidad\n");

    arrayLenght = productsList->len(productsList);

    for(i = 0; i < arrayLenght; i++){

        productAux = productsList->get(productsList,i);

        idAux = productAux->productId;
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



