//
//  provsFunctions.c
//  practica_modelo_parcial_2
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
#include "productsFunctions.h"
#include "provsFunctions.h"
#include "functions.h"
#include "reportsFunctions.h"
#include "inputFunctions.h"


/**
 * \brief Inicializa el status en un array de proveedores
 * \param provsArray Es el array en el cual buscar
 * \param provsArrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setProvsStatus(EProv provsArray[],int provsArrayLenght,int value){
    
    int i;
    for(i=0;i < provsArrayLenght; i++){
        provsArray[i].status = value;
    }
}

/**
 * \brief Busca la primer ocurrencia de un proveedor mediante su Id
 * \param provsArray Es el array en el cual buscar
 * \param provsArrayLenght Indica la logitud del array
 * \param provIdAux Es el id que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findProvById(EProv provsArray[], int provsArrayLenght, int provIdAux){
    
    int i;
    for(i=0;i < provsArrayLenght; i++){
        if(provsArray[i].provId == provIdAux && provsArray[i].status == 1){
            return i;
        }
    }
    return -1;
}

/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param provsArray Es el array en el cual buscar
 * \param provsArrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findProvEmptyPlace(EProv provsArray[],int provsArrayLenght){
    
    int i;
    for(i=0;i < provsArrayLenght; i++){
        if(provsArray[i].status == 0){
            return i;
        }
    }
    return -1;
}

/**
 * \brief Carga los valores del proveedor
 * \param provsArray Es el array de proveedores
 * \param freePlaceIndex Indica la posicion a setear
 * \param provIdAux Id del proveedor
 * \param nameAux Nombre del proveedor
 * \return -
 *
 */
void setProv(EProv provsArray[],int freePlaceIndex, int provIdAux,char nameAux[]){
    
    provsArray[freePlaceIndex].provId = provIdAux;
    strcpy(provsArray[freePlaceIndex].name,nameAux);
    provsArray[freePlaceIndex].status = 1;
}

/**
 * \brief Muestra los proveedores activos por pantalla
 * \param provsArray Es el array de proveedores
 * \param provsArrayLenght Indica la logitud del array
 * \return -
 */
void showProvsArray(EProv provsArray[],int provsArrayLenght){
    
    int i;
    
    printf("\n------------------\n|*  LISTA DE PROVEEDORES  *|\n---------------------\n\
           \n---------------------------------------------\
           \n|    ID  |            DESCRIPCION           |\
           \n---------------------------------------------");
    
    for(i=0;i < provsArrayLenght; i++){
        if(provsArray[i].status != 0){
            printf("\n| %6d  | %-15s  |",provsArray[i].provId,provsArray[i].name);
        }
    }
}

/**
 * \brief Muestra el proveedor seleccionado por pantalla
 * \param proveedor Es el array a mostrar
 * \return -
 */
void showProv(EProv provsArray){
    printf("\n| ID  |      DESCRIPCION      |");
    printf("\n| %6d  | %-15s  |",provsArray.provId,provsArray.name);
}

/**
 * \brief Lista los proveedores cuya cantidad de productos es menor o igual a 10
 * \param provsArray Es el array de proveedores el cual se listara
 * \param provsArrayLenght Indica la logitud del array proveedores
 * \param productsArray Es el array de productos
 * \param productsArrayLenght Indica la logitud del array
 * \return -
 *
 */
void listProvByQuantity(EProv provsArray[],int provsArrayLenght,EProduct productsArray[],int productsArrayLenght){
    
    int i;
    int contadorProductsProvs[4];
    
    for (i=0; i<4; i++) {
        contadorProductsProvs[i] = 0;
    }
    
    for(i = 0; i < provsArrayLenght; i++){
        if (productsArray[i].status == ACTIVE) {
            if(productsArray[i].provId == 1){
                contadorProductsProvs[0]++;
            }
            if(productsArray[i].provId == 2){
                contadorProductsProvs[1]++;
            }
            if(productsArray[i].provId == 3){
                contadorProductsProvs[2]++;
            }
            if(productsArray[i].provId == 4){
                contadorProductsProvs[3]++;
            }
        }// if (productsArray[i].status == ACTIVE)
    }// for(i = 0; i < provsArrayLenght; i++)
    
    for (i=0; i<4; i++) {
        if (contadorProductsProvs[i] <= 10) {
            showProv(provsArray[i]);
        }
    }
}// void listProvByQuantity(EProv provsArray[],int provsArrayLenght,EProduct productsArray[],int productsArrayLenght)



