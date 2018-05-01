//
//  authorsFunctions.h
//  ejemploClase14
//
//  Created by Gaston Pesoa on 01/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __ejemploClase14__authorsFunctions__
#define __ejemploClase14__authorsFunctions__

#include <stdio.h>
#include "types.h"

void setAuthorStatus(author authorArray[],int arrayLenght,int value);
int findAuthorEmptyPlace(author authorArray[],int arrayLenght);
int findAuthorById(author authorArray[],int arrayLenght,int authorIdAux);
void setAuthor(author authorArray[],int freePlaceIndex, int authorIdAux,char nameAux[],char lastNameAux[]);
void showAuthorArray(author authorArray[],int arrayLenght);
void showAuthor(author author);

#endif /* defined(__ejemploClase14__authorsFunctions__) */
