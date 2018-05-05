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

void controller_test(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght);
void controller_altaProduct(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght);
void controller_bajaProduct(product productArray[], int arrayLenght, user userArray[], int arrayUserLenght);

char confirm(char confirmMensaje[]);

#endif /* defined(__practicaModeloParcial_1__controllerFunctions__) */
