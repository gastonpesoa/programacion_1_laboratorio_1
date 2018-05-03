//
//  productFunctions.h
//  practicaModeloParcial_1
//
//  Created by Gaston Pesoa on 02/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __practicaModeloParcial_1__productFunctions__
#define __practicaModeloParcial_1__productFunctions__

#include <stdio.h>

void setProductStatus(product productArray[],int arrayLenght,int value);
int findProductById(product productArray[],int arrayLenght,int id);
int findProductEmptyPlace(product productArray[],int arrayLenght);
void setProduct(product productArray[],int freePlaceIndex, int productIdAux, char nameAux[], int userIdAux,int stockAux, float priceAux, int salesQtyAux);
void showProductArray(product productArray[],int arrayLenght);
void showProduct(product productArray);

#endif /* defined(__practicaModeloParcial_1__productFunctions__) */
