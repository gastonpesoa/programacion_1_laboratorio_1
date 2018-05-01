//
//  bookFunctions.h
//  ejemploClase14
//
//  Created by Gaston Pesoa on 01/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __ejemploClase14__bookFunctions__
#define __ejemploClase14__bookFunctions__

#include <stdio.h>
#include "types.h"

void setBookStatus(book bookArray[],int arrayLenght,int value);
int findBookEmptyPlace(book bookArray[],int arrayLenght);
int findBookByCode(book bookArray[],int arrayLenght,int code);
void setBook(book bookArray[],int freePlaceIndex, int codeAux,char titleAux[], int authorIdAux,int stockAux);
void showBookArray(book bookArray[],int arrayLenght);
void showBook(book book);
void orderBookArrayByTitle(book bookArray[],int arrayLenght);

#endif /* defined(__ejemploClase14__bookFunctions__) */
