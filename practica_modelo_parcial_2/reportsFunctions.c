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
#include "functions.h"
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
                contadorProductosStockMayorADiez++;
            } else {
                contadorProductosStockMenorADiez++;
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

/** \brief Informa los proveedores con mas productos registrados
 * \param product productsArray El array de productos
 * \param productsArrayLenght Longitud del array
 * \param provsArray provsArray El array de proveedores
 * \param provsArrayLenght Longitud del array
 * \return -
 *
 */
void showLibrosMayorMenorStock(EProduct productsArray[],int productsArrayLenght){
    
    int i, min = 0, max = 0, flag = 0;
    int productIdMaxStock = 0, productIdMinStock = 0;
    int foundIndexMin, foundIndexMax;
    
    for (i = 0; i < productsArrayLenght; i++) {
        
        if (productsArray[i].status != 0) {
            
            if (flag == 0) {
                
                min = productsArray[i].stock;
                max = productsArray[i].stock;
                productIdMaxStock = productsArray[i].productId;
                productIdMinStock = productsArray[i].productId;
                flag = 1;
            }
            else {
                
                if (productsArray[i].stock > max) {
                    
                    max = productsArray[i].stock;
                    productIdMaxStock = productsArray[i].productId;
                }
                if (productsArray[i].stock < min) {
                    
                    min = productsArray[i].stock;
                    productIdMinStock = productsArray[i].productId;
                }
            }//if (flag == 0)
        }//if (productsArray[i].status != 0)
    }//for (i = 0; i < productsArrayLenght; i++)
    
    foundIndexMax = findProductById(productsArray, PRODUCTS_MAX_QTY, productIdMaxStock);
    foundIndexMin = findProductById(productsArray, PRODUCTS_MAX_QTY, productIdMinStock);
    
    printf("\n**************** PRODUCTO CON MAS STOCK ******************\n");
    //showProduct(productsArray[foundIndexMax]);
    printf("\n\n**************** PRODUCTO CON MENOS STOCK ******************\n");
    //showProduct(productsArray[foundIndexMin]);
    
}//void showLibroConMayorStock(product productsArray[],int productsArrayLenght)

