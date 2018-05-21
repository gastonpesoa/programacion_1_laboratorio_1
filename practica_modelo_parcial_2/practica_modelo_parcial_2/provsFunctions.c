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
    
    for(i=0;i < provsArrayLenght; i++){
        if(provsArray[i].status != 0){
            printf("\n| %4d   |           %-18s     |",provsArray[i].provId,provsArray[i].name);
        }
    }
}

/**
 * \brief Muestra el proveedor seleccionado por pantalla
 * \param proveedor Es el array a mostrar
 * \return -
 */
void showProv(EProv provsArray){
    
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
    
    printf("\n--------------------------------------------------------------\
            \n|* PROVEEDORES CON CANTIDAD DE PRODUCTOS MENOR O IGUAL A 10 *|\
            \n--------------------------------------------------------------\
            \n|    ID  |                      DESCRIPCION                  |\
            \n--------------------------------------------------------------");
    for (i=0; i<4; i++) {
        if (contadorProductsProvs[i] <= 10) {
            showProv(provsArray[i]);
        }
    }
    printf("\n--------------------------------------------------------------");
}// void listProvByQuantity(EProv provsArray[],int provsArrayLenght,EProduct productsArray[],int productsArrayLenght)

/**
 * \brief Lista los productos provistos por cada proveedor
 * \param productsArray Es el array el cual se listara
 * \param productsArrayLenght Indica la logitud del array
 * \param provsArray Es el array de proveedores
 * \param provsArrayLenght Indica la logitud del array proveedores
 * \return -
 *
 */
void listProductsByProvs(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght){
    
    int i;
    
    printf("\n-----------------------------------------------------------------------------------------\
           \n|                       * PRODUCTOS PROVISTOS POR EL PROVEEDOR 1 *                      |\
           \n-----------------------------------------------------------------------------------------\
           \n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |\
           \n-----------------------------------------------------------------------------------------");
    for (i=0; i<productsArrayLenght; i++) {
        if (productsArray[i].status != INACTIVE && productsArray[i].provId == 1) {
            showProduct(productsArray[i], provsArray, provsArrayLenght);
        }
    }
    printf("\n-----------------------------------------------------------------------------------------");
    
    printf("\n-----------------------------------------------------------------------------------------\
           \n|                       * PRODUCTOS PROVISTOS POR EL PROVEEDOR 2 *                      |\
           \n-----------------------------------------------------------------------------------------\
           \n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |\
           \n-----------------------------------------------------------------------------------------");
    for (i=0; i<productsArrayLenght; i++) {
        if (productsArray[i].status != INACTIVE && productsArray[i].provId == 2) {
            showProduct(productsArray[i], provsArray, provsArrayLenght);
        }
    }
    printf("\n-----------------------------------------------------------------------------------------");
    
    printf("\n-----------------------------------------------------------------------------------------\
           \n|                       * PRODUCTOS PROVISTOS POR EL PROVEEDOR 3 *                      |\
           \n-----------------------------------------------------------------------------------------\
           \n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |\
           \n-----------------------------------------------------------------------------------------");
    for (i=0; i<productsArrayLenght; i++) {
        if (productsArray[i].status != INACTIVE && productsArray[i].provId == 3) {
            showProduct(productsArray[i], provsArray, provsArrayLenght);
        }
    }
    printf("\n-----------------------------------------------------------------------------------------");
    
    printf("\n-----------------------------------------------------------------------------------------\
           \n|                       * PRODUCTOS PROVISTOS POR EL PROVEEDOR 4 *                      |\
           \n-----------------------------------------------------------------------------------------\
           \n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |\
           \n-----------------------------------------------------------------------------------------");
    for (i=0; i<productsArrayLenght; i++) {
        if (productsArray[i].status != INACTIVE && productsArray[i].provId == 4) {
            showProduct(productsArray[i], provsArray, provsArrayLenght);
        }
    }
    printf("\n-----------------------------------------------------------------------------------------");
}

/**
 * \brief Muestra el proveedor que provee mas productos, el que provee menos productos 
 * \y lista sus productos respectivamente
 * \param productsArray Es el array de productos
 * \param productsArrayLenght Indica la logitud del array
 * \param provsArray Es el array de proveedores
 * \param provsArrayLenght Indica la logitud del array proveedores
 * \return -
 *
 */
void listProvMaxMinQtyProducts(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght){
    
    int i, min=0, max=0, flag=0;
    int provIdMaxQtyProducts=0, provIdMinQtyProducts=0;
    int qtyProductsProvs[4];
    
    //Inicializo array de contadores
    for (i=0; i<4; i++) {
        qtyProductsProvs[i]=0;
    }//for (i=0; i<4; i++)
    
    //Cuento la cantidad de productos de cada proveedor
    for (i=0; i<productsArrayLenght; i++) {
        if (productsArray[i].status != INACTIVE && productsArray[i].provId == 1) {
            qtyProductsProvs[0]++;
        }
        if (productsArray[i].status != INACTIVE && productsArray[i].provId == 2) {
            qtyProductsProvs[1]++;
        }
        if (productsArray[i].status != INACTIVE && productsArray[i].provId == 3) {
            qtyProductsProvs[2]++;
        }
        if (productsArray[i].status != INACTIVE && productsArray[i].provId == 4) {
            qtyProductsProvs[3]++;
        }
    }//for (i=0; i<productsArrayLenght; i++)
    
    //Encuentro el proveedor que provee mas productos y el que provee menos
    for (i=0; i<4; i++) {
        if (flag==0) {
            min = qtyProductsProvs[i];
            max = qtyProductsProvs[i];
            provIdMaxQtyProducts = i+1;
            provIdMinQtyProducts = i+1;
            flag=1;
        }
        else{
            if (qtyProductsProvs[i]>max) {
                max = qtyProductsProvs[i];
                provIdMaxQtyProducts = i+1;
            }
            if (qtyProductsProvs[i]<min) {
                min = qtyProductsProvs[i];
                provIdMinQtyProducts = i+1;
            }
        }//if (flag==0)
    }//for (i=0; i<4; i++)
    
    //Imprimo los productos del proveedor que provee mas y del que provee menos productos
    printf("\n-----------------------------------------------------------------------------------------\
            \n|             * PROVEEDOR QUE PROVEE MAS PRODUCTOS: PROVEEDOR %d *                      |\
            \n-----------------------------------------------------------------------------------------\
            \n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |\
            \n-----------------------------------------------------------------------------------------"\
            ,provIdMaxQtyProducts);
    
    for (i=0; i<productsArrayLenght; i++) {
        if (productsArray[i].status != INACTIVE && productsArray[i].provId == provIdMaxQtyProducts) {
            showProduct(productsArray[i], provsArray, provsArrayLenght);
        }
    }
    printf("\n-----------------------------------------------------------------------------------------");
    
    printf("\n-----------------------------------------------------------------------------------------\
            \n|             * PROVEEDOR QUE PROVEE MENOS PRODUCTOS: PROVEEDOR %d *                    |\
            \n-----------------------------------------------------------------------------------------\
            \n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |\
            \n-----------------------------------------------------------------------------------------"\
           ,provIdMinQtyProducts);
    
    for (i=0; i<productsArrayLenght; i++) {
        if (productsArray[i].status != INACTIVE && productsArray[i].provId == provIdMinQtyProducts) {
            showProduct(productsArray[i], provsArray, provsArrayLenght);
        }
    }
    printf("\n-----------------------------------------------------------------------------------------");
}//void listProvMaxMinQtyProducts(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght)

/**
 * \brief Muestra el proveedor que provee el producto mas caro, el proveedor que provee el mas barato
 * \y muestra esos productos
 * \param productsArray Es el array de productos
 * \param productsArrayLenght Indica la logitud del array
 * \param provsArray Es el array de proveedores
 * \param provsArrayLenght Indica la logitud del array proveedores
 * \return -
 *
 */
void showProvExpCheapPrice(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght){
    
    int i, flag=0;
    float min=0, max=0;
    int productIdExpPrice=0,productIdCheapPrice=0,provIdExpPrice=0,provIdCheapPrice=0;
    
    for (i=0; i<productsArrayLenght; i++) {
        if (productsArray[i].status != INACTIVE) {
            if (flag==0) {
                
                min = productsArray[i].price;
                max = productsArray[i].price;
                productIdCheapPrice = productsArray[i].productId;
                productIdExpPrice = productsArray[i].productId;
                provIdCheapPrice = productsArray[i].provId;
                provIdExpPrice = productsArray[i].provId;
                flag=1;
            }
            else{
                if (productsArray[i].price>max) {
                    
                    max = productsArray[i].price;
                    productIdExpPrice = productsArray[i].productId;
                    provIdExpPrice = productsArray[i].provId;
                }
                if (productsArray[i].price<min) {
                    min = productsArray[i].price;
                    productIdCheapPrice = productsArray[i].productId;
                    provIdCheapPrice = productsArray[i].provId;
                }
            }//if (flag==0)
        }//if (productsArray[i].status != INACTIVE)
    }// for (i=0; i<productsArrayLenght; i++)
    
    //Imprimo el proveedor que provee el producto mas caro y el que provee el mas barato mostrando ese producto
    printf("\n-----------------------------------------------------------------------------------------\
            \n|         * PROVEEDOR QUE PROVEE EL PRODUCTO MAS CARO: PROVEEDOR %d *                   |\
            \n-----------------------------------------------------------------------------------------\
            \n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |\
            \n-----------------------------------------------------------------------------------------"\
           ,provIdExpPrice);
    
    for (i=0; i<productsArrayLenght; i++) {
        if (productsArray[i].status != INACTIVE && productsArray[i].productId == productIdExpPrice) {
            showProduct(productsArray[i], provsArray, provsArrayLenght);
        }
    }
    printf("\n-----------------------------------------------------------------------------------------");
    
    printf("\n-----------------------------------------------------------------------------------------\
            \n|          * PROVEEDOR QUE PROVEE EL PRODUCTO MAS BARATO: PROVEEDOR %d *                |\
            \n-----------------------------------------------------------------------------------------\
            \n|    ID   |                      DESCRIPCION              |  PRECIO | STOCK | PROVEEDOR |\
            \n-----------------------------------------------------------------------------------------"\
           ,provIdCheapPrice);
    
    for (i=0; i<productsArrayLenght; i++) {
        if (productsArray[i].status != INACTIVE && productsArray[i].productId == productIdCheapPrice) {
            showProduct(productsArray[i], provsArray, provsArrayLenght);
        }
    }
    printf("\n-----------------------------------------------------------------------------------------");
}//void showProvExpCheapPrice(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght)



