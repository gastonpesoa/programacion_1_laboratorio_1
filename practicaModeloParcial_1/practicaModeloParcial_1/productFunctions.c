//
//  productFunctions.c
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
#include "inputFunctions.h"


/**
 * \brief Inicializa el status en un array de productos
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setProductStatus(product productArray[],int arrayLenght,int value)
{
    int i;
    for(i = 0; i < arrayLenght; i++)
    {
        productArray[i].status = value;
    }
}


/**
 * \brief Busca la primer ocurrencia de un producto mediante su id
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param id Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findProductById(product productArray[],int arrayLenght,int id)
{
    int i;
    for(i = 0; i < arrayLenght; i++)
    {
        if(productArray[i].productId == id && productArray[i].status == ACTIVE)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findProductEmptyPlace(product productArray[],int arrayLenght)
{
    int i;
    for(i = 0; i < arrayLenght; i++)
    {
        if(productArray[i].status == INACTIVE)
        {
            return i + 1;
        }
    }
    return -1;
}



/**
 * \brief Carga los valores del producto
 * \param productArray Es el array de productos
 * \param freePlaceIndex Indica la posicion a setear
 * \param productIdAux Id del producto
 * \param nameAux Nombre del producto
 * \param userIdAux Id del usuario
 * \param priceAux Precio del producto
 * \param stockIdAux Cantidad de ejemplaes disponibles
 * \param salesQtyAux Cantidad de ventas del producto
 * \return -
 *
 */
void setProduct(product productArray[], int freePlaceIndex, int productIdAux, char nameAux[], int userIdAux, float priceAux, int stockAux, int salesQtyAux)
{
    productArray[freePlaceIndex].productId = productIdAux;
    strcpy(productArray[freePlaceIndex].name ,nameAux);
    productArray[freePlaceIndex].userId = userIdAux;
    productArray[freePlaceIndex].price = priceAux;
    productArray[freePlaceIndex].stock = stockAux;
    productArray[freePlaceIndex].salesQty = salesQtyAux;
    productArray[freePlaceIndex].status = ACTIVE;
}


/**
 * \brief Muestra los productos activos por pantalla
 * \param productArray Es el array de productos
 * \param arrayLenght Indica la logitud del array
 * \return -
 */
void showProductArray(product productArray[], int arrayLenght)
{
    int i;
    
    clearScreen();
    printf("\n------------------------------\n|*  LISTA DE PUBLICACIONES  *|\n------------------------------\n");
    printf("\n-----------------------------------------------------------------------------------------------------");
    printf("\n|    ID   |                      NOMBRE              |  PRECIO | CANTIDAD VENDIDA | STOCK | USUARIO |");
    printf("\n-----------------------------------------------------------------------------------------------------");
    for(i=0;i < arrayLenght; i++)
    {
        if(productArray[i].status != INACTIVE)
        {
            printf("\n| %6d  | %-40s | %7.2f | %16d | %5d | %7d |", productArray[i].productId, productArray[i].name, productArray[i].price, productArray[i].salesQty, productArray[i].stock, productArray[i].userId);
        }
    }
    printf("\n-----------------------------------------------------------------------------------------------------");
}

/**
 * \brief Muestra el producto seleccionado por pantalla
 * \param productArray Es el array a mostrar
 * \return -
 */
void showProduct(product productArray){
    
    printf("\n| %6d  | %-40s | %7.2f | %16d | %5d | %7d |", productArray.productId, productArray.name, productArray.price, productArray.salesQty, productArray.stock, productArray.userId);
}


/** \brief Lista publicaciones del usuario con el ID ingresado
 * \param book bookArray El array de libros
 * \param bookArrayLenght Longitud del array
 * \param author authorArray El array de autores
 * \param authorArrayLenght Longitud del array
 * \return -
 *
 */
void showUserProducts(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght){
    
    int i, userIdAux, foundIndex;
    
    clearScreen();
    printf("\n----------------------------------------\
           \n|*  LISTA DE PUBLICACIONES DE USUARIO *|\
           \n----------------------------------------\n");
    
    userIdAux = getValidInt("\nIngrese el ID del usuario: ", "El ID del usuario debe ser numerico\n", 1, arrayUserLenght);
    foundIndex = findUserById(userArray, arrayUserLenght, userIdAux);
    if(foundIndex == -1){
        
        printf("\n\nNO SE ENCONTRO ESE CODIGO\n");
        getChar("\n\nENTER (para continuar)");
    }
    else{
        
        printf("\n-----------------------------------------------------------------------------------------------------");
        printf("\n|    ID   |                      NOMBRE              |  PRECIO | CANTIDAD VENDIDA | STOCK | USUARIO |");
        printf("\n-----------------------------------------------------------------------------------------------------");
        for(i = 0; i < arrayProductLenght; i++){
            if(productArray[i].status == ACTIVE && userIdAux == productArray[i].userId){
                showProduct(productArray[i]);
            }
        }
        printf("\n-----------------------------------------------------------------------------------------------------");
    }// if(foundIndex == -1)
}// void showAuthorBooks(book bookArray[],int bookArrayLenght, author authorArray[], int authorArrayLenght)


