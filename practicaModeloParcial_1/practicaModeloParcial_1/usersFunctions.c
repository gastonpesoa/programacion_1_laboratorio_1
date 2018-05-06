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
#include "salesFunctions.h"
#include "controllerFunctions.h"
#include "listFunctions.h"
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
    for(i = 0; i < arrayLenght; i++)
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
int findUserById(user userArray[],int arrayLenght, int id)
{
    int i;
    for(i = 0; i < arrayLenght; i++)
    {
        if(userArray[i].userId == id && userArray[i].status == ACTIVE)
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
    for(i = 0; i < arrayLenght; i++)
    {
        if(userArray[i].status == INACTIVE)
        {
            return i + 1;
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
 * \return -
 *
 */
void setUser(user userArray[], int freePlaceIndex, int userIdAux, char nameAux[], char passwordAux[])
{
    userArray[freePlaceIndex].userId = userIdAux;
    strcpy(userArray[freePlaceIndex].name, nameAux);
    strcpy(userArray[freePlaceIndex].password, passwordAux);
    userArray[freePlaceIndex].status = ACTIVE;
}


/**
 * \brief Lista los usuarios registrados
 * \param userArray Es el array de ususarios
 * \param arrayUserLenght Longitud del array de ususarios
 * \return -
 *
 */
void showUserArray(user userArray[], int arrayUserLenght){
    int i;
    
    for (i = 0; i < arrayUserLenght; i++) {
        if (userArray[i].status != INACTIVE) {
            
            printf("\nUserId: %d | Nombre de usuario: %s | Password: %s | Estado: %d", userArray[i].userId, userArray[i].name, userArray[i].password, userArray[i].status);
            printf("\n");
        }
    }
}


/**
 * \brief Muestra el usuario seleccionado por pantalla
 * \param userArray Es el array a mostrar
 * \return -
 */
void showUser(user userArray){
    
    printf("\n---------------------------------------------------");
    printf("\n|    ID  |            NOMBRE DE USUARIO           |");
    printf("\n---------------------------------------------------");
    printf("\n| %6d |  %-37s |", userArray.userId, userArray.name);
    printf("\n---------------------------------------------------");
}
