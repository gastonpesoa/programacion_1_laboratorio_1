//
//  controllerFunctions.h
//  practicaModeloParcial_1
//
//  Created by Gaston Pesoa on 02/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __practicaModeloParcial_1__controllerFunctions__
#define __practicaModeloParcial_1__controllerFunctions__

#include <stdio.h>

void controller_test(product productArray[], user userArray[], sale saleArray[]);

void controller_altaProduct(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght);
void controller_bajaProduct(product productArray[], int arrayLenght, user userArray[], int arrayUserLenght);
void controller_modificarProduct(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght);

void controller_altaUser(user userArray[], int arrayUserLenght);
void controller_bajaUser(user userArray[], int arrayLenght, product productArray[], int productArrayLenght);
void controller_modificarUser(user userArray[], int arrayUserLenght);

void controller_buyProduct(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght, sale saleArray[], int arraySaleLenght);

char confirm(char confirmMensaje[]);

#endif /* defined(__practicaModeloParcial_1__controllerFunctions__) */

