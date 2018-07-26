#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Product.h"
#include "Input.h"
#include "Parser.h"


#define PRODUCT_INACTIVE  0
#define PRODUCT_ACTIVE  1


Product* product_new(void){

    Product* returnAux = NULL;
    returnAux = (Product*)malloc(sizeof(Product));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}


int product_setId(Product* pProduct, int productId, int lowLimit){

    int returnAux = -1;

    if(productId >= lowLimit){

        pProduct->productId = productId;
        returnAux = 0;
    }

    return returnAux;
}



int product_setDescription(Product* pProduct, char* description, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(description, lowLimit, hiLimit)) {

        strcpy(pProduct->description,description);
        returnAux = 0;
    }

    return returnAux;
}


int product_setStock(Product* pProduct, int stock, int lowLimit){

    int returnAux = -1;

    if(stock >= lowLimit){

        pProduct->stock = stock;
        returnAux = 0;
    }

    return returnAux;
}


int product_getId(Product* pProduct){

    return pProduct->productId;
}


char* product_getDescription(Product* pProduct){

    return pProduct->description;
}


int product_getStock(Product* pProduct){

    return pProduct->stock;
}


void product_print(Product* pProduct){

    printf("| Codigo: %4d | Descripcion: %20s | Stock: %6d |\r\n",\
        pProduct->productId,pProduct->description,pProduct->stock);
}



int product_printArrayList(ArrayList* productsList){

    int returnAux = -1;
    int i;
    int cont=1;

    if(!productsList->isEmpty(productsList)){
        for(i=0; i<productsList->len(productsList); i++){

            if(cont %250 == 0){

               system("pause");
            }
            cont++;

            //printf("%4d) ",i);
            product_print(productsList->get(productsList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}

