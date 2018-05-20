//
//  productsFunctions.h
//  practica_modelo_parcial_2
//
//  Created by Gaston Pesoa on 01/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __practica_modelo_parcial_2__productsFunctions__
#define __practica_modelo_parcial_2__productsFunctions__

#include <stdio.h>
#include "types.h"

void setProductStatus(EProduct productsArray[],int productsArrayLenght,int value);
int findProductById(EProduct productsArray[],int productsArrayLenght,int productId);
int findProductEmptyPlace(EProduct productsArray[],int productsArrayLenght);

void setProduct(EProduct productsArray[],int freePlaceIndex,char nameAux[],int productIdAux,int provIdAux,float priceAux,int stockAux);

void altaProduct(EProduct productsArray[], int productsArrayLenght,EProv provsArray[],int provsArrayLenght);
void bajaProduct(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght);
void modificarProduct(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght);

void showProductsArray(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght);
void showProduct(EProduct productsArray,EProv provsArray[],int provsArrayLenght);

void listProductsArrayByPriceDescription(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght);
void listProductsByQuantity(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght);
void listProductosByAverage(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght);

#endif /* defined(__practica_modelo_parcial_2__productsFunctions__) */
