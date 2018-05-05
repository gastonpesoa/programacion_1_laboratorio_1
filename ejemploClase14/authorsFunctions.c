//
//  authorsFunctions.c
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
 * \brief Inicializa el status en un array de autores
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setAuthorStatus(author authorArray[],int arrayLenght,int value)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        authorArray[i].status = value;
    }
}

/**
 * \brief Busca la primer ocurrencia de un autor mediante su codigo
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param authorIdAux Es el id que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findAuthorById(author authorArray[], int arrayLenght, int authorIdAux)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(authorArray[i].authorId == authorIdAux && authorArray[i].status == 1)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Carga los valores del autor
 * \param authorArray Es el array de autores
 * \param freePlaceIndex Indica la posicion a setear
 * \param authorIdAux Id del autor
 * \param nameAux Nombre del autor
 * \param lastNameAux Apellido del autor
 * \return -
 *
 */
void setAuthor(author authorArray[],int freePlaceIndex, int authorIdAux,char nameAux[],char lastNameAux[])
{

    authorArray[freePlaceIndex].authorId = authorIdAux;
    strcpy(authorArray[freePlaceIndex].name,nameAux);
    strcpy(authorArray[freePlaceIndex].lastName,lastNameAux);
    authorArray[freePlaceIndex].status = 1;

}


/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findAuthorEmptyPlace(author authorArray[],int arrayLenght)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(authorArray[i].status == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Muestra los autores activos por pantalla
 * \param authorArray Es el array de autores
 * \param arrayLenght Indica la logitud del array
 * \return -
 */
void showAuthorArray(author authorArray[],int arrayLenght)
{
    int i;
    printf("\n| CODIGO  |      NOMBRE      |    APELLIDO     ");
    for(i=0;i < arrayLenght; i++)
    {
        if(authorArray[i].status != 0)
        {
            printf("\n| %6d  | %-15s  | %-15s",authorArray[i].authorId,authorArray[i].name,authorArray[i].lastName);
        }
    }

}

/**
 * \brief Muestra el autor seleccionado por pantalla
 * \param autor Es el array a mostrar
 * \return -
 */
void showAuthor(author author){

    printf("\n| %6d  | %-15s  | %-15s",author.authorId,author.name,author.lastName);
}
