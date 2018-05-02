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
 *
 */
void showBookAuthorArray(book bookArray[],int bookArrayLenght,author authorArray[],int authorArrayLenght)
{
    int i;
    char auxAuthor[51];
    int authorIdAux;
    
    printf("\n| CODIGO  |                    TITULO            |     AUTOR       | STOCK |");
    for(i=0;i < bookArrayLenght; i++)
    {
        if(bookArray[i].status != 0)
        {
            authorIdAux = findAuthorById(authorArray, authorArrayLenght, bookArray[i].authorId);
            if(authorIdAux != -1)
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


/** \brief Informa los autores con mas libros registrados
 * \param book bookArray El array de libros
 * \param bookArrayLenght Longitud del array
 * \param author authorArray El array de autores
 * \param authorArrayLenght Longitud del array
 * \return -
 *
 */
void showLibrosMayorMenorStock(book bookArray[],int bookArrayLenght){
    
    int i, min = 0, max = 0, flag = 0;
    int codeMaxStock = 0, codeMinStock = 0;
    int foundIndexMin, foundIndexMax;
    
    for (i = 0; i < bookArrayLenght; i++) {
        
        if (bookArray[i].status != 0) {
            
            if (flag == 0) {
                
                min = bookArray[i].stock;
                max = bookArray[i].stock;
                codeMaxStock = bookArray[i].code;
                codeMinStock = bookArray[i].code;
                flag = 1;
            }
            else {
                
                if (bookArray[i].stock > max) {
                    
                    max = bookArray[i].stock;
                    codeMaxStock = bookArray[i].code;
                }
                if (bookArray[i].stock < min) {
                    
                    min = bookArray[i].stock;
                    codeMinStock = bookArray[i].code;
                }
            }//if (flag == 0)
        }//if (bookArray[i].status != 0)
    }//for (i = 0; i < bookArrayLenght; i++)
        
    foundIndexMax = findBookByCode(bookArray, BOOKS_MAX_QTY, codeMaxStock);
    foundIndexMin = findBookByCode(bookArray, BOOKS_MAX_QTY, codeMinStock);
    
    printf("\n**************** LIBRO CON MAS STOCK ******************\n");
    showBook(bookArray[foundIndexMax]);
    printf("\n\n**************** LIBRO CON MENOS STOCK ******************\n");
    showBook(bookArray[foundIndexMin]);
    
}//void showLibroConMayorStock(book bookArray[],int bookArrayLenght)