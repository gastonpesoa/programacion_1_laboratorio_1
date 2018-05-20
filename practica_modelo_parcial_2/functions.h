//
//  functions.h
//  practica_modelo_parcial_2
//
//  Created by Gaston Pesoa on 01/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __practica_modelo_parcial_2__functions__
#define __practica_modelo_parcial_2__functions__

#include <stdio.h>

int optionMenu();
int optionMenuModificar();

void testProductsProvs(EProduct productsArray[], int productsArrayLenght, EProv provsArray[], int provsArrayLenght);

char confirm(char confirmMensaje[]);

void clearScreen(void);

#endif /* defined(__practica_modelo_parcial_2__functions__) */
