//
//  library.c
//  ejemploClase14
//
//  Created by Gaston Pesoa on 01/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "types.h"
#include "adminFunctions.h"
#include "funcionesMenus.h"
#include "controllerFunctions.h"
#include "bookFunctions.h"
#include "authorsFunctions.h"
#include "booksAuthorsFunctions.h"
#include "funcionesInput.h"



/**
 * \brief Muestra los libros activos por pantalla indicando el apellido del Autor
 * \param bookArray Es el array de libros
 * \param arrayLenght Indica la logitud del array libros
 * \param authorArray Es el array de autores
 * \param arrayLenght Indica la logitud del array autores
 * \return -
 */
void showBookAuthorArray(book bookArray[],int arrayLenght,author authorArray[],int authorArrayLenght)
{
    int i;
    char auxAuthor[51];
    int authorIdAux;
    printf("\n| CODIGO  |                    TITULO            |     AUTOR       | STOCK |");
    for(i=0;i < arrayLenght; i++)
    {
        if(bookArray[i].status != 0)
        {
            authorIdAux = findAuthorById(authorArray,authorArrayLenght,bookArray[i].authorId);
            if( authorIdAux != -1)
            {
                strcpy(auxAuthor,authorArray[authorIdAux].lastName);
            }
            else
            {
                sprintf(auxAuthor, "? (Id:%d)", bookArray[i].authorId);
            }
            printf("\n| %6d  | %-36s | %15s | %5d |",bookArray[i].code,bookArray[i].title,auxAuthor,bookArray[i].stock);
        }
    }
    
}