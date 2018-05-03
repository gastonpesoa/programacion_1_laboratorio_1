//
//  usersFunctions.c
//  practicaModeloParcial_1
//
//  Created by Gaston Pesoa on 02/05/18.
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
#include "controllerFunctions.h"
#include "inputFunctions.h"



/**
 * \brief Inicializa el status en un array de usuarios
 * \param userArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setUserStatus(user userArray[],int arrayLenght,int value)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        userArray[i].status = value;
    }
}



/**
 * \brief Busca la primer ocurrencia de un usuario mediante su id
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param id Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findUserById(user userArray[],int arrayLenght,int id)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(userArray[i].userId == id && userArray[i].status == 1)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param userArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findUserEmptyPlace(user userArray[],int arrayLenght)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(userArray[i].status == 0)
        {
            return i;
        }
    }
    return -1;
}



/**
 * \brief Carga los valores del usuario
 * \param userArray Es el array de usuarios
 * \param freePlaceIndex Indica la posicion a setear
 * \param userIdAux Id del usuario
 * \param nameAux Nombre del usuario
 * \param passwordAux Password del usuario
 * \param qualificationPromAux Calificacion promedio del usuario
 * \return -
 *
 */
void setUser(user userArray[],int freePlaceIndex, int userIdAux, char nameAux[], char passwordAux[], int qualificationPromAux)
{
    userArray[freePlaceIndex].userId = userIdAux;
    strcpy(userArray[freePlaceIndex].name, nameAux);
    strcpy(userArray[freePlaceIndex].password, passwordAux);
    userArray[freePlaceIndex].qualificationProm = qualificationPromAux;
    userArray[freePlaceIndex].status = 1;
}


/**
 * \brief Muestra los usuarios activos por pantalla
 * \param userArray Es el array de usuarios
 * \param arrayLenght Indica la logitud del array
 * \return -
 */
void showUserArray(user userArray[],int arrayLenght)
{
    int i;
    printf("\n|    ID    |                      NOMBRE              | CALIFICACION PROMEDIO |");
    for(i=0;i < arrayLenght; i++)
    {
        if(userArray[i].status != 0)
        {
            printf("\n| %6d  | %-40s | %5d |", userArray[i].userId, userArray[i].name, userArray[i].qualificationProm);
        }
    }
    
}

/**
 * \brief Muestra el producto seleccionado por pantalla
 * \param userArray Es el array a mostrar
 * \return -
 */
void showUser(user userArray){
    printf("\n|    ID    |                      NOMBRE              | CALIFICACION PROMEDIO |");
    printf("\n| %6d  | %-40s | %5d |", userArray.userId, userArray.name, userArray.qualificationProm);
}