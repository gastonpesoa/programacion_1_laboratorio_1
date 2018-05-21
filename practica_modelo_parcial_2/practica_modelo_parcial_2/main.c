//
//  main.c
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


int main(void) {
    
    //array de productos
    EProduct productsArray[PRODUCTS_MAX_QTY];
    setProductStatus(productsArray, PRODUCTS_MAX_QTY, 0);
    
    //array de proveedores
    EProv provsArray[PROVS_MAX_QTY];
    setProvsStatus(provsArray, PROVS_MAX_QTY, 0);
    
    //HardCode con datos para test
    testProductsProvs(productsArray, PRODUCTS_MAX_QTY, provsArray, PROVS_MAX_QTY);
    
    //Menu de opciones
    int option = 0;
    
    while (option != 6) {
        
        printf("\n\n--------------------------------------------\
                  \n|*             MENU PRINCIPAL             *|\
                  \n--------------------------------------------");
        
        option = optionMenu();
        
        switch (option){
                
            case 1: // ALTA DE PRODUCTO
                altaProduct(productsArray, PRODUCTS_MAX_QTY, provsArray, PROVS_MAX_QTY);
                break;
                
            case 2: // MODIFICAR PRODUCTO
                modificarProduct(productsArray, PRODUCTS_MAX_QTY, provsArray, PROVS_MAX_QTY);
                break;
                
            case 3: // BAJA PRODUCTO
                bajaProduct(productsArray, PRODUCTS_MAX_QTY, provsArray, PROVS_MAX_QTY);
                break;
                
            case 4: //  INFORMES
                reports(productsArray, PRODUCTS_MAX_QTY);
                break;
                
            case 5: // LISTAS
                listProductsArrayByPriceDescription(productsArray, PRODUCTS_MAX_QTY, provsArray, PROVS_MAX_QTY);
                listProductsByQuantity(productsArray, PRODUCTS_MAX_QTY, provsArray, PROVS_MAX_QTY);
                listProductosByAverage(productsArray, PRODUCTS_MAX_QTY, provsArray, PROVS_MAX_QTY);
                listProvByQuantity(provsArray, PROVS_MAX_QTY, productsArray, PRODUCTS_MAX_QTY);
                listProductsByProvs(productsArray, PRODUCTS_MAX_QTY, provsArray, PROVS_MAX_QTY);
                listProvMaxMinQtyProducts(productsArray, PRODUCTS_MAX_QTY, provsArray, PROVS_MAX_QTY);
                showProvExpCheapPrice(productsArray, PRODUCTS_MAX_QTY, provsArray, PROVS_MAX_QTY);
                break;
                
            case 6:
                continue;
                
        }//switch (option)
    }//while (option != 6)
    
    return 0;
}//int main(void)



