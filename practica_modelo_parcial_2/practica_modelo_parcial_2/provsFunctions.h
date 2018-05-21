//
//  provsFunctions.h
//  practica_modelo_parcial_2
//
//  Created by Gaston Pesoa on 01/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __practica_modelo_parcial_2__provsFunctions__
#define __practica_modelo_parcial_2__provsFunctions__

#include "types.h"

void setProvsStatus(EProv provsArray[],int provsArrayLenght,int value);
int findProvById(EProv provsArray[], int provsArrayLenght, int provIdAux);
int findProvEmptyPlace(EProv provsArray[],int provsArrayLenght);

void setProv(EProv provsArray[],int freePlaceIndex, int provIdAux,char nameAux[]);

void showProvsArray(EProv provsArray[],int provsArrayLenght);
void showProv(EProv provsArray);

void listProvByQuantity(EProv provsArray[],int provsArrayLenght,EProduct productsArray[],int productsArrayLenght);
void listProductsByProvs(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght);
void listProvMaxMinQtyProducts(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght);
void showProvExpCheapPrice(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght);

#endif /* defined(__practica_modelo_parcial_2__provsFunctions__) */
