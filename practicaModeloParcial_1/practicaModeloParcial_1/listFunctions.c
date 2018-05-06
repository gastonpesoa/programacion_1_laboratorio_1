//
//  listFunctions.c
//  practicaModeloParcial_1
//
//  Created by Gaston Pesoa on 06/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "types.h"
#include "productFunctions.h"
#include "usersFunctions.h"
#include "salesFunctions.h"
#include "controllerFunctions.h"
#include "listFunctions.h"
#include "inputFunctions.h"



/** \brief Lista publicaciones del usuario con el ID ingresado
 * \param book bookArray El array de libros
 * \param bookArrayLenght Longitud del array
 * \param author authorArray El array de autores
 * \param authorArrayLenght Longitud del array
 * \return -
 *
 */
void showUserProducts(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght){
    
    int i, userIdAux, foundIndex;
    
    clearScreen();
    printf("\n----------------------------------------\
           \n|*  LISTA DE PUBLICACIONES DE USUARIO *|\
           \n----------------------------------------\n");
    
    userIdAux = getValidInt("\nIngrese el ID del usuario: ", "El ID del usuario debe ser numerico\n", 1, arrayUserLenght);
    foundIndex = findUserById(userArray, arrayUserLenght, userIdAux);
    if(foundIndex == -1){
        
        printf("\n\nNO SE ENCONTRO ESE CODIGO\n");
        getChar("\n\nENTER (para continuar)");
    }
    else{
        
        printf("\n-----------------------------------------------------------------------------------------------------");
        printf("\n|    ID   |                      NOMBRE              |  PRECIO | CANTIDAD VENDIDA | STOCK | USUARIO |");
        printf("\n-----------------------------------------------------------------------------------------------------");
        for(i = 0; i < arrayProductLenght; i++){
            if(productArray[i].status == ACTIVE && userIdAux == productArray[i].userId){
                showProduct(productArray[i]);
            }
        }
        printf("\n-----------------------------------------------------------------------------------------------------");
    }// if(foundIndex == -1)
}// void showAuthorBooks(book bookArray[],int bookArrayLenght, author authorArray[], int authorArrayLenght)


/**
 * \brief Lista los usuarios activos con la calificación promedio de cada uno
 * \param userArray Es el array de usuarios
 * \param arrayUserLenght Indica la logitud del array
 * \return -
 *
 */
void showUserSaleArray(user userArray[],int arrayUserLenght, sale saleArray[], int arraySaleLenght)
{
    int i;
    float qualificationAverageAux;
    
    printf("\n------------------------------------------------------------------------------");
    printf("\n|    ID   |                      NOMBRE              | CALIFICACION PROMEDIO |");
    printf("\n------------------------------------------------------------------------------");
    for(i = 0; i < arrayUserLenght; i++) {
        if(userArray[i].status != INACTIVE) {
            
            qualificationAverageAux = qualificationAverage(saleArray, arraySaleLenght, userArray[i].userId);
            
            printf("\n| %6d  | %-40s | %21.2f |", userArray[i].userId, userArray[i].name, qualificationAverageAux);
            
        }// if(saleArray[i].status != INACTIVE)
    }// for(i = 0; i < arraySaleLenght; i++)
    printf("\n------------------------------------------------------------------------------");
}// void showUserArray(user userArray[],int arrayUserLenght, sale saleArray[], int arraySaleLenght)


/**
 * \brief Lista los usuarios activos con la calificación promedio de cada uno
 * \param userArray Es el array de usuarios
 * \param arrayUserLenght Indica la logitud del array
 * \return -
 *
 */
void showSaleUserArray(user userArray[],int arrayUserLenght, sale saleArray[], int arraySaleLenght)
{
    int i;
    char nameAux[51];
    int userIdAux;
    float qualificationAverageAux;
    
    printf("\n|    ID   |                      NOMBRE              | CALIFICACION PROMEDIO |");
    for(i = 0; i < arraySaleLenght; i++)
    {
        if(saleArray[i].status != INACTIVE)
        {
            
            userIdAux = findUserById(userArray, arrayUserLenght, saleArray[i].userId);
            strcpy(nameAux, userArray[userIdAux].name);
            
            qualificationAverageAux = qualificationAverage(saleArray, arraySaleLenght, userIdAux);
            
            printf("\n| %6d  | %-40s | %21.2f |", saleArray[i].userId, nameAux, qualificationAverageAux);
            
        }// if(saleArray[i].status != INACTIVE)
    }// for(i = 0; i < arraySaleLenght; i++)
}// void showUserArray(user userArray[],int arrayUserLenght, sale saleArray[], int arraySaleLenght)