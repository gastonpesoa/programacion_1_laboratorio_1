//
//  funcionesMenus.c
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



/** \brief
* Funcion para limpiar la pantalla de la consola
* \param void Sin parametros
* \return -
*
*/
void clearScreen(void){

    system("@cls||clear");
}

/** \brief
 * Funcion para mostrar el menu principal de opciones en consola y le pide la eleccion al usuario.
 * \param requestMessage Es el menu a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \return option Retorna el valor elegido por el usuario.
 *
 */
int optionMenu(char menuPrinsipalMensaje[], char menuPrinsipalMensajeError[], int lowLimit, int hiLimit){
    
    int option;
    
    option = getValidInt(menuPrinsipalMensaje, menuPrinsipalMensajeError, lowLimit, hiLimit);
    return option;
}