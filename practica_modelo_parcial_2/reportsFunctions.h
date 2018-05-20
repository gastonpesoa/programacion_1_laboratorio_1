//
//  reportsFunctions.h
//  practica_modelo_parcial_2
//
//  Created by Gaston Pesoa on 19/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __practica_modelo_parcial_2__reportsFunctions__
#define __practica_modelo_parcial_2__reportsFunctions__

#include <stdio.h>

float totalPrices(EProduct productsArray[], int productsArrayLenght);
float average(EProduct productsArray[], int productsArrayLenght);
void reports(EProduct productsArray[], int productsArrayLenght);

void showLibrosMayorMenorStock(EProduct productsArray[],int productsArrayLenght);

#endif /* defined(__practica_modelo_parcial_2__reportsFunctions__) */
