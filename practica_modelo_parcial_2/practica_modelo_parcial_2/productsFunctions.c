//
//  productsFunctions.c
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
#include "reportsFunctions.h"
#include "inputFunctions.h"


/** \brief Carga datos de prueba tanto en el array de productos como en el de proveedores
 * \param productsArray El array de productos
 * \param productsArrayLenght Longitud del array
 * \param provsArray provsArray El array de proveedores
 * \param provsArrayLenght Longitud del array
 * \return void
 */
void testProductsProvs(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght){
    
    // Alta de datos para testing
    setProduct(productsArray, 0, "Gaseosa Cola", 1, 1, 50.00, 25);
    setProduct(productsArray, 1, "Chupetines Luck", 2, 2, 12.00, 300);
    setProduct(productsArray, 2, "Alfajores Jorge", 3, 3, 23.00, 0);
    setProduct(productsArray, 3, "Caramelos Lipo", 4, 4, 8.00, 50);
    setProduct(productsArray, 4, "Cerveza Aguila", 5, 1, 25.00, 2500);
    
    setProv(provsArray, 0, 1, "Proveedor_1");
    setProv(provsArray, 1, 2, "Proveedor_2");
    setProv(provsArray, 2, 3, "Proveedor_3");
    setProv(provsArray, 3, 4, "Proveedor_4");
};

/**
 * \brief Inicializa el status en un array de productos
 * \param productsArray Es el array en el cual buscar
 * \param productsArrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setProductStatus(EProduct productsArray[],int productsArrayLenght,int value){
    
    int i;
    for(i=0; i < productsArrayLenght; i++){
        productsArray[i].status = value;
    }
}

/**
 * \brief Busca la primer ocurrencia de un producto mediante su Id
 * \param productsArray Es el array en el cual buscar
 * \param productsArrayLenght Indica la logitud del array
 * \param productId Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findProductById(EProduct productsArray[],int productsArrayLenght,int productId){
    
    int i;
    for(i=0;i < productsArrayLenght; i++){
        if(productsArray[i].productId == productId && productsArray[i].status == ACTIVE){
            return i;
        }
    }
    return -1;
}

/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param productsArray Es el array en el cual buscar
 * \param productsArrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findProductEmptyPlace(EProduct productsArray[],int productsArrayLenght){
    
    int i;
    for(i=0;i < productsArrayLenght; i++){
        if(productsArray[i].status == INACTIVE){
            return i;
        }
    }
    return -1;
}

/**
 * \brief Carga los valores del producto
 * \param productsArray Es el array de productos
 * \param freePlaceIndex Indica la posicion a setear
 * \param nameAux Descripcion del producto
 * \param productIdAux Id del producto
 * \param provIdAux Id del proveedor
 * \param priceAux precio del producto
 * \param stockIdAux Cantidad de productos disponibles
 * \return -
 *
 */
void setProduct(EProduct productsArray[],int freePlaceIndex,char nameAux[],int productIdAux,int provIdAux,float priceAux,int stockAux){
    
    strcpy(productsArray[freePlaceIndex].name,nameAux);
    productsArray[freePlaceIndex].productId = productIdAux;
    productsArray[freePlaceIndex].provId = provIdAux;
    productsArray[freePlaceIndex].price = priceAux;
    productsArray[freePlaceIndex].stock = stockAux;
    productsArray[freePlaceIndex].status = ACTIVE;
}

/** \brief Pide al usuario los datos de un nuevo producto y luego lo agrega al array
 * \param productsArray el array de productos donde se alamcenara el nuevo producto
 * \param productsArrayLenght Longitud del array
 * \param provsArray Es el array de proveedores
 * \param provsArrayLenght Indica la logitud del array
 * \return -
 *
 */
void altaProduct(EProduct productsArray[], int productsArrayLenght,EProv provsArray[],int provsArrayLenght){
    
    char nameAux[51];
    int provIdAux;
    float priceAux;
    int stockAux;
    int productIdAux;
    
    int freePlaceIndex;
    
    printf("\n---------------------------------------------\
            \n|           *  ALTA DE PRODUCTO  *          |\
            \n---------------------------------------------\n\n");
    
    freePlaceIndex = findProductEmptyPlace(productsArray, productsArrayLenght);
    if (freePlaceIndex == -1) {
        
        printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
        getChar("\n\nENTER (para continuar)");
    }
    else{
        printf("\n---------------------------------------------\
                \n|       *  LISTA DE PROVEEDORES  *          |\
                \n---------------------------------------------\
                \n|    ID  |            DESCRIPCION           |\
                \n---------------------------------------------");
        showProvsArray(provsArray, provsArrayLenght);
        printf("\n---------------------------------------------\n");
        
        provIdAux = getValidInt("\nIngrese el ID de proveedor: ", "El ID deber ser numerico", 1, provsArrayLenght);
        getValidStringNombre("\nIngrese la descripcion del producto: ", "La descripcion debe estar compuesta solo por letras\n", nameAux);
        priceAux = getValidFloat("\nIngrese el precio del producto: ", "El precio del producto debe ser numerico\n", 1, 9999999999);
        stockAux = getValidInt("\nIngrese la cantidad de productos: ", "La cantidad debe ser numerica\n", 1, 10000);
        productIdAux = freePlaceIndex+1;
        
        setProduct(productsArray, freePlaceIndex, nameAux, productIdAux, provIdAux, priceAux, stockAux);
        
        clearScreen();
        printf("\nALTA REALIZADA CON EXITO!\n");
        printf("\n-----------------------------------------------------------------------------------------");
        printf("\n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |");
        printf("\n-----------------------------------------------------------------------------------------");
        showProduct(productsArray[freePlaceIndex], provsArray, provsArrayLenght);
        printf("\n-----------------------------------------------------------------------------------------");
        getChar("\n\nENTER (para continuar)");
        
    }//if (freePlaceIndex == -1)
}

/** \brief Pide al usuario el Id del producto a ser dado de baja
 * \param productsArray el array de productos donde se buscara el producto a eliminar
 * \param productsArrayLenght Longitud del array
 * \param provsArray Es el array de proveedores
 * \param provsArrayLenght Indica la logitud del array
 * \return -
 *
 */
void bajaProduct(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght){
    
    int productIdAux;
    int foundProductIndex;
    char confirmar = 'n';
    
    printf("\n----------------------------\n|*  BAJA DE PRODUCTO  *|\n----------------------------\n");
    printf("\n-----------------------------------\n|*  MODIFICACION DE PRODUCTO  *|\n-----------------------------------\n");
    printf("\n----------------------------------------------------------------------------------------");
    printf("\n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |");
    printf("\n----------------------------------------------------------------------------------------");
    showProductsArray(productsArray, productsArrayLenght, provsArray, provsArrayLenght);
    printf("\n-----------------------------------------------------------------------------------------\n");
    productIdAux = getValidInt("\nIngrese el ID del producto a dar de baja: ", "El ID del producto debe ser numerico\n", 1, 1000);
    foundProductIndex = findProductById(productsArray, productsArrayLenght, productIdAux);
    if (foundProductIndex == -1) {
        
        printf("\n\nNO SE ENCONTRO ESE ID\n");
        getChar("\n\nENTER (para continuar)");
    }
    else {
        
        //Se muestra el producto seleccionado
        printf("\n----------------------------------------------------------------------------------------");
        printf("\n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |");
        printf("\n----------------------------------------------------------------------------------------");
        showProduct(productsArray[foundProductIndex], provsArray, provsArrayLenght);
        printf("\n-----------------------------------------------------------------------------------------\n");
        
        confirmar = confirm("\n\nSe esta por eliminar el producto seleccionado, confirma la baja? [s|n]: ");
        if (confirmar == 's') {
            
            productsArray[foundProductIndex].status = INACTIVE;
            printf("\nSE HA CANCELADO LA PUBLICACION\n\n");
            getChar("\n\nENTER (para continuar)");
        }
        else {
            
            printf("\nNO SE HA CANCELADO LA PUBLICACION\n\n");
            getChar("\n\nENTER (para continuar)");
        }// if (confirmar == 's')
    } //if (foundIndex == -1)
}

/** \brief Pide al usuario el Id del producto a ser modificado, despliega un menu de opciones de los campos disponibles y luego de confirmar los modifica
 * \param product productsArray el array de productos donde se buscara el producto a ser modificado
 * \param length int Longitud del array
 * \param provsArray Es el array de proveedores
 * \param provsArrayLenght Indica la logitud del array
 * \return -
 *
 */
void modificarProduct(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght){
    
    int productIdAux;
    char nameAux[51];
    int provIdAux;
    float priceAux;
    int stockAux;
    
    int foundProductIndex;
    char confirmar = 'n';
    int option = 0;
    
    printf("\n-----------------------------------\n|*  MODIFICACION DE PRODUCTO  *|\n-----------------------------------\n");
    printf("\n----------------------------------------------------------------------------------------");
    printf("\n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |");
    printf("\n----------------------------------------------------------------------------------------");
    showProductsArray(productsArray, productsArrayLenght, provsArray, provsArrayLenght);
    printf("\n-----------------------------------------------------------------------------------------\n");
    productIdAux = getValidInt("\nIngrese el ID del producto a modificar: ", "El ID del producto debe ser numerico\n", 1, productsArrayLenght);
    foundProductIndex = findProductById(productsArray, productsArrayLenght, productIdAux);
    if (foundProductIndex == -1) {
        
        printf("\n\nNO SE ENCONTRO ESE ID\n");
        getChar("\n\nENTER (para continuar)");
    }
    else {
        
        //Se muestra el producto seleccionado
        printf("\n---------------------------------------------------------------------------------------");
        printf("\n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |");
        printf("\n----------------------------------------------------------------------------------------");
        showProduct(productsArray[foundProductIndex],provsArray,provsArrayLenght);
        printf("\n-----------------------------------------------------------------------------------------");
        
        strcpy(nameAux, productsArray[foundProductIndex].name);
        priceAux = productsArray[foundProductIndex].price;
        stockAux = productsArray[foundProductIndex].stock;
        provIdAux = productsArray[foundProductIndex].provId;
        
        while(option != 4){
            
            //clearScreen();
            option = optionMenuModificar();
            
            switch(option){
                    
                case 1: // Modificacion de descripcion
                    getValidStringNombre("\nIngrese la descripcion del producto: ", "La descripcion debe estar compuesta solo por letras\n", nameAux);
                    break;
                    
                case 2: // Modificacion de precio
                    priceAux = getValidFloat("Ingrese el precio del producto: ", "El precio del producto debe ser numerico\n", 1, 999999999999);
                    break;
                    
                case 3: // Modificacion de stock
                    stockAux = getValidInt("Ingrese la cantidad de productos: ", "La cantidad debe ser numerica\n", 1, 10000);
                    break;
                    
                case 4:
                    continue;
            }// switch(option)
            
            confirmar = confirm("\n\nSe esta por modifcar el producto seleccionada, confirma la modificacion? [s|n]: ");
            
            if (confirmar == 's') {
                
                setProduct(productsArray, foundProductIndex, nameAux, foundProductIndex, provIdAux, priceAux, stockAux);
                
                clearScreen();
                printf("\nSE HA MODIFICADO LA PUBLICACION\n\n");
                printf("\n-----------------------------------------------------------------------------------------");
                printf("\n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |");
                printf("\n-----------------------------------------------------------------------------------------");
                showProduct(productsArray[foundProductIndex], provsArray, provsArrayLenght);
                printf("\n-----------------------------------------------------------------------------------------");
                getChar("\n\nENTER (para continuar)");
                getChar("\n\nENTER (para continuar)");
            }
            else {
                
                printf("\nNO SE HA MODIFICADO LA PUBLICACION\n\n");
                getChar("\n\nENTER (para continuar)");
            }// if (confirmar == 's')
        }// while(option != 3)
    }//
}

/**
 * \brief Muestra los productos activos por pantalla
 * \param productsArray Es el array de productos
 * \param productsArrayLenght Indica la logitud del array
 * \param provsArray Es el array de proveedores
 * \param provsArrayLenght Indica la logitud del array proveedores
 * \return -
 */
void showProductsArray(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght){
    
    int i, provIdAux;
    char provNameAux[51];
    
    for (i=0; i < productsArrayLenght; i++) {
        if (productsArray[i].status != INACTIVE){
            provIdAux = findProvById(provsArray,provsArrayLenght,productsArray[i].provId);
            if (provIdAux != -1) {
                strcpy(provNameAux,provsArray[provIdAux].name);
            }
            else {
                sprintf(provNameAux, "? (Id:%d)",productsArray[i].provId);
            }
            printf("\n| %6d  | %-40s | %5.2f | %5d | %-40s |",productsArray[i].productId,productsArray[i].name,productsArray[i].price,productsArray[i].stock,provNameAux);
            
        }// if (productsArray[i].status != 0)
    }// for (i=0; i < productsArrayLenght; i++)
}// void showProductsArray(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght)

/**
 * \brief Muestra el producto seleccionado por pantalla
 * \param productsArray Es el array a mostrar
 * \param productsArrayLenght Indica la logitud del array
 * \param provsArray Es el array de proveedores
 * \param provsArrayLenght Indica la logitud del array proveedores
 * \return -
 */
void showProduct(EProduct productsArray,EProv provsArray[],int provsArrayLenght){
    
    int provIdAux;
    char provNameAux[51];
    
    provIdAux = findProvById(provsArray,provsArrayLenght,productsArray.provId);
    if (provIdAux != -1) {
        strcpy(provNameAux,provsArray[provIdAux].name);
    }
    else {
        sprintf(provNameAux, "? (Id:%d)",productsArray.provId);
    }
    printf("\n| %6d  | %-45s | %5.2f | %5d | %-40s |",productsArray.productId,productsArray.name,productsArray.price,productsArray.stock,provNameAux);
}

/**
 * \brief Ordena y lista el array de productos por importe (descendentemente) y por descripcion (ascendentemente)
 * \param productsArray Es el array el cual se ordenara y listara
 * \param productsArrayLenght Indica la logitud del array
 * \param provsArray Es el array de proveedores
 * \param provsArrayLenght Indica la logitud del array proveedores
 * \return -
 *
 */
void listProductsArrayByPriceDescription(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght){
    
    EProduct productAux;
    int i, j;
    
    for(i=0; i < productsArrayLenght-1; i++){
        
        if(productsArray[i].status == INACTIVE){
            continue;
        }
        for(j=i+1; j < productsArrayLenght; j++){
            
            if(productsArray[j].status == INACTIVE){
                continue;
            }
            if(productsArray[i].price < productsArray[j].price){
                
                productAux = productsArray[j];
                productsArray[j] = productsArray[i];
                productsArray[i] = productAux;
            }
            else if(productsArray[i].price == productsArray[j].price)
            {
                if(strcmp(productsArray[i].name, productsArray[j].name) > 0)
                {
                    productAux = productsArray[j];
                    productsArray[j] = productsArray[i];
                    productsArray[i] = productAux;
                    
                }//if(bookArray[i].code > bookArray[j].code)
            }//(strcmp(bookArray[j].title,bookArray[i].title) == 0)
        }//for(j=i+1; j < productsArrayLenght; j++)
    }//for(i=0; i < productsArrayLenght - 1; i++)
    
    clearScreen();
    printf("\n-----------------------------------------------------------------------------------------\
            \n|                   * PRODUCTOS ORDENADODOS POR IMPORTE Y DESCRIPCION *                 |\
            \n-----------------------------------------------------------------------------------------\
            \n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |\
            \n-----------------------------------------------------------------------------------------");
    showProductsArray(productsArray, productsArrayLenght, provsArray, provsArrayLenght);
    printf("\n-----------------------------------------------------------------------------------------");
    
}// void listProductsArrayByPriceDescription(EProduct productsArray[],int productsArrayLenght)

/**
 * \brief Lista los productos por cantidad por, menores o iguales a 10 o mayores a 10
 * \param productsArray Es el array el cual se listara
 * \param productsArrayLenght Indica la logitud del array
 * \param provsArray Es el array de proveedores
 * \param provsArrayLenght Indica la logitud del array proveedores
 * \return -
 *
 */
void listProductsByQuantity(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght){
    
    int i;
    
    printf("\n-----------------------------------------------------------------------------------------\
            \n|                       * PRODUCTOS CON STOCK MENOR O IGUAL A 10 *                      |\
            \n-----------------------------------------------------------------------------------------\
            \n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |\
            \n-----------------------------------------------------------------------------------------");
           
    for(i = 0; i < productsArrayLenght; i++){
        if(productsArray[i].status == ACTIVE){
            if(productsArray[i].stock <= 10){
                showProduct(productsArray[i],provsArray, provsArrayLenght);
            }
        }
    }
    
    printf("\n-----------------------------------------------------------------------------------------\
            \n|                          * PRODUCTOS CON STOCK MAYOR A 10 *                           |\
            \n-----------------------------------------------------------------------------------------\
            \n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |\
            \n-----------------------------------------------------------------------------------------");
    
    for(i = 0; i < productsArrayLenght; i++){
        if(productsArray[i].status == ACTIVE){
            if(productsArray[i].stock > 10){
                showProduct(productsArray[i],provsArray, provsArrayLenght);
            }
        }
    }
    printf("\n-----------------------------------------------------------------------------------------");
}// void listProductsByQuantity(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght)

/**
 * \brief Lista los productos por los que superan y por los que no superan el promedio de los importes
 * \param productsArray Es el array el cual se listara
 * \param productsArrayLenght Indica la logitud del array
 * \param provsArray Es el array de proveedores
 * \param provsArrayLenght Indica la logitud del array proveedores
 * \return -
 *
 */
void listProductosByAverage(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght){
    
    int i;
    float totalImportes;
    float promedio;
    
    totalImportes = totalPrices(productsArray, productsArrayLenght);
    promedio = average(productsArray, productsArrayLenght);
    
    printf("\n-----------------------------------------------------------------------------------------\
            \n|               * PRODUCTOS QUE SUPERAN EL PROMEDIO DE LOS IMPORTES *                   |\
            \n-----------------------------------------------------------------------------------------\
            \n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |\
            \n-----------------------------------------------------------------------------------------");
    
    for(i = 0; i < productsArrayLenght; i++){
        if(productsArray[i].status == ACTIVE){
            
            if(productsArray[i].price > promedio){
                showProduct(productsArray[i],provsArray, provsArrayLenght);
            }
        }
    }
    
    printf("\n-----------------------------------------------------------------------------------------\
            \n|               * PRODUCTOS QUE NO SUPERAN EL PROMEDIO DE LOS IMPORTES *                |\
            \n-----------------------------------------------------------------------------------------\
            \n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |\
            \n-----------------------------------------------------------------------------------------");
    
    for(i = 0; i < productsArrayLenght; i++){
        if(productsArray[i].status == ACTIVE){
            
            if(productsArray[i].price < promedio){
                showProduct(productsArray[i],provsArray, provsArrayLenght);
            }
        }
    }
    printf("\n-----------------------------------------------------------------------------------------");
}// void listProductosByAverage(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght)

/** \brief Funcion que solicita un caracter 's' o 'n', valida que sea ingresado correctamente y devuelve el resultado
 * \param char confirmMensaje[] el mensaje a ser mostrado
 * \return caracter 's' o 'n'
 *
 */
char confirm(char confirmMensaje[]){
    
    char confirmar = 'n';
    
    do {
        
        printf("%s", confirmMensaje);
        cleanStdin();
        scanf("%c", &confirmar);
        confirmar = tolower(confirmar);
        
    } while (confirmar != 's' && confirmar != 'n');
    
    return confirmar;
}
