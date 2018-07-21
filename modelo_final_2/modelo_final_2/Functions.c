#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Product.h"
#include "Input.h"
#include "Parser.h"
#include "Functions.h"


int getValidDesposit(void){

    int depositOrigen;
    int depositDestino;

    do{
        depositOrigen = getValidInt("\nIngrese el numero del deposito origen [1|2]: ","\nLa opcion debe ser numerica\n",1,2);
        depositDestino = getValidInt("\nIngrese el numero del deposito destino [1|2]: ","\nLa opcion debe ser numerica\n",1,2);

        if(depositOrigen == depositDestino){
            clearScreen();
            printf("\nDeben ingresarse numeros de deposito origen y destino distintos\n");
        }
    }while(depositOrigen == depositDestino);
    return depositOrigen;
}


Product* getValidProduct(ArrayList* depositList){

    int depositListLenght, productIdAux, i;
    Product *productAux;

    depositListLenght = depositList->len(depositList);
    
    do{
        //Se listan los productos del deposito 
        product_printArrayList(depositList);
        productIdAux = getValidInt("\nIngrese el codigo del producto: ","\nEl codigo debe ser numerico\n",LOW_LIMIT,HI_LIMIT);
        //Se recorre la lista del deposito buscando coincidencia
        for(i = 0; i < depositListLenght; i++){
            productAux = depositList->get(depositList,i);
            //Si lo encuentro salgo del for
            if(productAux->productId == productIdAux){
                break;
            }
        }
        //Si se recorrio toda la lista y no hubo coincidencia se informa y se vuelve a solicitar el codigo
        if(productAux->productId != productIdAux){
            clearScreen();
            printf("\r\nNo se encontro ningun producto con el codigo ingresado, vuelva a intentar\n");
        }
    }while(productAux->productId != productIdAux);

    return productAux;
}


void moveProductToDeposit(ArrayList* depositOriginList, ArrayList* depositDestinoList, Product* productToMove){

    int indexOfProductToMove;
    Product *productAux;

    //Obtengo la posicion en el array del producto seleccionado
    indexOfProductToMove = depositOriginList->indexOf(depositOriginList,productToMove);
    //Se obtiene el producto y se elimina del deposito Uno
    productAux = depositOriginList->pop(depositOriginList,indexOfProductToMove);
    //Se agrega el producto a la lista Dos
    depositDestinoList->add(depositDestinoList,productAux);
}


void discountProductStock(int stockAux, int qtyToDiscount, Product *productToModifyStock){

    stockAux = stockAux - qtyToDiscount;
    product_setStock(productToModifyStock,stockAux,1); 
}


void addProductStock(int stockAux, int qtyToAdd, Product *productToModifyStock){

    stockAux = stockAux + qtyToAdd;
    product_setStock(productToModifyStock,stockAux,1); 
}






