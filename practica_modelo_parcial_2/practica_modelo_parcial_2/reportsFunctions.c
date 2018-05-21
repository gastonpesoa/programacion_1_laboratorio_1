//
//  reportsFunctions.c
//  practica_modelo_parcial_2
//
//  Created by Gaston Pesoa on 19/05/18.
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
#include "reportsFunctions.h"
#include "inputFunctions.h"


/** \brief Calcula el total de la suma de todos los precios de los productos activos
 * \param product productsArray El array de productos
 * \param productsArrayLenght Longitud del array
 * \return -
 *
 */
float totalPrices(EProduct productsArray[], int productsArrayLenght){
    
    int i;
    float totalPrices = 0;
    
    for(i = 0; i < productsArrayLenght; i++){
        if(productsArray[i].status == ACTIVE){
            
            totalPrices = totalPrices + productsArray[i].price;

        }//if(productsArray[i].status == ACTIVE)
    }//for(i = 0; i < productsArrayLenght; i++)
    
    return totalPrices;
}// float totalPrices(EProduct productsArray[], int productsArrayLenght)

/** \brief Calcula el promedio de todos los precios de los productos activos
 * \param product productsArray El array de productos
 * \param productsArrayLenght Longitud del array
 * \return -
 *
 */
float average(EProduct productsArray[], int productsArrayLenght){
    
    int i;
    int contadorProductos = 0;
    float totalImportes;
    float promedio;
    
    for(i = 0; i < productsArrayLenght; i++){
        if(productsArray[i].status == ACTIVE){
            contadorProductos++;
        }
    }
    totalImportes = totalPrices(productsArray, productsArrayLenght);
    promedio = totalImportes / contadorProductos;
    return promedio;
}

/** \brief Informe del total y promedio de los importes 
 * \Cuantos productos superan esos promedios
 * \Cuantos productos no superan esos promedios
 * \Cantidad de productos cuyo stock es menor o igual a 10
 * \Cantidad de productos cuyo stock es mayor a 10
 * \param product productsArray El array de productos
 * \param productsArrayLenght Longitud del array
 * \return -
 *
 */
void reports(EProduct productsArray[], int productsArrayLenght){
    
    int i;
    float totalImportes;
    float promedio;
    int contadorProductosPrecioMayorAlPromedio = 0;
    int contadorProductosPrecioMenorAlPromedio = 0;
    int contadorProductosStockMenorADiez = 0;
    int contadorProductosStockMayorADiez = 0;
    
    totalImportes = totalPrices(productsArray, productsArrayLenght);
    promedio = average(productsArray, productsArrayLenght);
    
    for(i = 0; i < productsArrayLenght; i++){
        if(productsArray[i].status == ACTIVE){
            
            if(productsArray[i].price > promedio){
                contadorProductosPrecioMayorAlPromedio++;
            }
            
            if(productsArray[i].price < promedio){
                contadorProductosPrecioMenorAlPromedio++;
            }
            
            if(productsArray[i].stock <= 10){
                contadorProductosStockMenorADiez++;
            } else {
                contadorProductosStockMayorADiez++;
            }
        }//if(productsArray[i].status == ACTIVE)
    }//for(i = 0; i < productsArrayLenght; i++)
    
    clearScreen();
    printf("\n------------------------------------------------------------------\
            \n|                         *  INFORMES  *                         |\
            \n------------------------------------------------------------------\
            \n| Total de importes                                  |      %.2f |\
            \n------------------------------------------------------------------\
            \n| Promedio de los importes                           |      %.2f |\
            \n------------------------------------------------------------------\
            \n| Cantidad de productos que superan el promedio      |        %d |\
            \n------------------------------------------------------------------\
            \n| Cantidad de productos que no superan el promedio   |        %d |\
            \n------------------------------------------------------------------\
            \n| Cantidad de productos con stock menor o igual a 10 |        %d |\
            \n------------------------------------------------------------------\
            \n| Cantidad de productos con stock mayor a 10         |        %d |\
            \n------------------------------------------------------------------\n",\
            totalImportes, promedio,\
            contadorProductosPrecioMayorAlPromedio, contadorProductosPrecioMenorAlPromedio,\
            contadorProductosStockMenorADiez, contadorProductosStockMayorADiez);
    getChar("\n\nENTER (para continuar)");
    
}// void totalPromedioImportes(product productsArray[], int productsArrayLenght)

