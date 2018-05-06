//
//  usersFunctions.h
//  practicaModeloParcial_1
//
//  Created by Gaston Pesoa on 02/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __practicaModeloParcial_1__usersFunctions__
#define __practicaModeloParcial_1__usersFunctions__

#include <stdio.h>

void setUserStatus(user userArray[],int arrayLenght,int value);
int findUserById(user userArray[],int arrayLenght,int id);
int findUserEmptyPlace(user userArray[],int arrayLenght);
void setUser(user userArray[], int freePlaceIndex, int userIdAux, char nameAux[], char passwordAux[]);
void showUserArray(user userArray[], int arrayUserLenght);
void showUserSaleArray(user userArray[],int arrayUserLenght, sale saleArray[], int arraySaleLenght);
void showUser(user userArray);

#endif /* defined(__practicaModeloParcial_1__usersFunctions__) */
