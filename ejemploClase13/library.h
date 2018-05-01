//
//  library.h
//  ejemploClase13
//
//  Created by Gaston Pesoa on 30/04/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __ejemploClase13__library__
#define __ejemploClase13__library__

#include <stdio.h>

typedef struct{
    char title[51];
    int code;
    int stock;
    int authorId;
    int status; /**< Active (1) or Inactive (0) */
}book;

void setStatus(book bookArray[], int arrayLenght, int value);
int findEmptyPlace(book bookArray[], int arrayLenght);
int findBookByCode(book bookArray[], int arrayLenght, int value);
void orderArrayByTitle(book bookArray[], int arrayLenght);
void setBook(book bookArray[],int freePlaceIndex, int codeAux,char titleAux[], int authorIdAux,int stockAux);
void showArray(book bookArray[], int arrayLenght);
void showBook(book book);

#endif /* defined(__ejemploClase13__library__) */
