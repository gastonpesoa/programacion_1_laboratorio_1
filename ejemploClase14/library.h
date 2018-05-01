//
//  library.h
//  ejemploClase14
//
//  Created by Gaston Pesoa on 01/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __ejemploClase14__library__
#define __ejemploClase14__library__

#define MAX_QTY 200

typedef struct{
    char title[51];
    int code;
    int stock;
    int authorId;
    int status; /**< Active (1) or Inactive (0) */
}book;

typedef struct{
    char name[51];
    char lastName[51];
    int authorId;
    int status; /**< Active (1) or Inactive (0)  */
}author;

void setBookStatus(book bookArray[],int arrayLenght,int value);
int findBookEmptyPlace(book bookArray[],int arrayLenght);
int findBookByCode(book bookArray[],int arrayLenght,int code);
void setBook(book bookArray[],int freePlaceIndex, int codeAux,char titleAux[], int authorIdAux,int stockAux);
void showBookArray(book bookArray[],int arrayLenght);
void showBook(book book);
void orderBookArrayByTitle(book bookArray[],int arrayLenght);

void setAuthorStatus(author authorArray[],int arrayLenght,int value);
int findAuthorEmptyPlace(author authorArray[],int arrayLenght);
int findAuthorById(author authorArray[],int arrayLenght,int authorIdAux);
void setAuthor(author authorArray[],int freePlaceIndex, int authorIdAux,char nameAux[],char lastNameAux[]);
void showAuthorArray(author authorArray[],int arrayLenght);
void showAuthor(author author);

void showBookAuthorArray(book bookArray[],int arrayLenght,author authorArray[],int authorArrayLenght);

#endif /* defined(__ejemploClase14__library__) */
