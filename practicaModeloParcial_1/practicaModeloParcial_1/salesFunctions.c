//
//  salesFunctions.c
//  practicaModeloParcial_1
//
//  Created by Gaston Pesoa on 05/05/18.
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
#include "inputFunctions.h"


/**
 * \brief Inicializa el status en un array de ventas
 * \param saleArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setSaleStatus(sale saleArray[], int arrayLenght, int value)
{
    int i;
    for(i = 0;i < arrayLenght; i++)
    {
        saleArray[i].status = value;
    }
}



/**
 * \brief Busca la primer ocurrencia de una venta mediante su id
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param id Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *

int findProductById(product productArray[],int arrayLenght,int id)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(productArray[i].productId == id && productArray[i].status == ACTIVE)
        {
            return i;
        }
    }
    return -1;
}
 */

/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param saleArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findSaleEmptyPlace(sale saleArray[], int arrayLenght)
{
    int i;
    for(i = 0; i < arrayLenght; i++)
    {
        if(saleArray[i].status == INACTIVE)
        {
            return i + 1;
        }
    }
    return -1;
}



/**
 * \brief Carga los valores de ventas
 * \param saleArray Es el array de ventas
 * \param freePlaceIndex Indica la posicion a setear
 * \param userIdAux Id del usuario
 * \param qualificationPromAux Calificacion promedio de la venta
 * \return -
 *
 */
void setSale(sale saleArray[], int freePlaceIndex, int userIdAux, int qualificationAux)
{
    saleArray[freePlaceIndex].userId = userIdAux;
    saleArray[freePlaceIndex].qualification = qualificationAux;
    saleArray[freePlaceIndex].status = ACTIVE;
}


/**
 * \brief Lista las ventas cargadas
 * \param saleArray Es el array de ventas
 * \param arraySaleLenght Longitud del array de ventas
 * \return -
 *
 */
void showSaleArray(sale saleArray[], int arraySaleLenght){
    int i;
    
    for (i = 0; i < arraySaleLenght; i++) {
        if (saleArray[i].status != INACTIVE) {
            printf("userId: %d | calificacion: %d ", saleArray[i].userId, saleArray[i].qualification);
            printf("\n");
        }
    }
}


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



/**
 * \brief Lista los usuarios activos con la calificación promedio de cada uno
 * \param userArray Es el array de usuarios
 * \param arrayUserLenght Indica la logitud del array
 * \return -
 *
 */
float qualificationAverage(sale saleArray[], int arraySaleLenght, int userIdAux){
   
    int i;
    float average;
    int accumSale = 0, qualificationSum = 0;
    
    
    for (i = 0; i < arraySaleLenght; i++) {
        if (saleArray[i].status != INACTIVE) {
            if (saleArray[i].userId == userIdAux) {
                accumSale++;
                qualificationSum = qualificationSum + saleArray[i].qualification;
            }
        }
    }
    
    average = (float)qualificationSum / accumSale;
    
    return average;
}


