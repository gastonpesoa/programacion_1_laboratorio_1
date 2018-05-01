//
//  controllerFunctions.h
//  ejemploClase14
//
//  Created by Gaston Pesoa on 01/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __ejemploClase14__controllerFunctions__
#define __ejemploClase14__controllerFunctions__

#include <stdio.h>

void controller_altaBook(book bookArray[], int arrayLenght);
void controller_bajaBook(book bookArray[], int arrayLenght);
void controller_modificarBook(book bookArray[], int arrayLenght);

void controller_altaAuthor(author authorArray[], int arrayLenght);
void controller_bajaAuthor(author authorArray[], int arrayLenght);
void controller_modificarAuthor(author authorArray[], int arrayLenght);

char confirm(char confirmMensaje[]);

#endif /* defined(__ejemploClase14__controllerFunctions__) */
