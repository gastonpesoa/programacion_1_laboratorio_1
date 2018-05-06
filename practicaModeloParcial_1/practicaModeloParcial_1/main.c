//
//  main.c
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
#include "listFunctions.h"
#include "inputFunctions.h"



int main(void) {
    
    // Array de usuarios
    user userArray[USERS_MAX_QTY];
    setUserStatus(userArray, USERS_MAX_QTY, INACTIVE);
    
    // Array de productod
    product productArray[PRODUCTS_MAX_QTY];
    setProductStatus(productArray, PRODUCTS_MAX_QTY, INACTIVE);
    
    //Array de ventas
    sale saleArray[SALES_MAX_QTY];
    setSaleStatus(saleArray, SALES_MAX_QTY, INACTIVE);
    
    //HardCode con datos para test
    controller_test(productArray, userArray, saleArray);
    
    //Menu de opciones
    char menuPrinsipalMensaje[] =
                "\n\n1 - ALTA DE USUARIO\
                \n2 - MODIFICAR DATOS DE USUARIO\
                \n3 - BAJA DE USUARIO\
                \n4 - PUBLICAR PRODUCTO\
                \n5 - MODIFICAR PUBLICACION\
                \n6 - CANCELAR PUBLICACION\
                \n7 - COMPRAR PRODUCTO\
                \n8 - LISTAR PUBLICACIONES DE USUARIO\
                \n9 - LISTAR PUBLICACIONES\
                \n10 - LISTAR USUARIOS\
                \n11 - SALIR\
                \n\nIngrese una opcion: ";
    
    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 11";
    
    int option = 0;
    
    while (option != 11) {
        //clearScreen();
        printf("\n\n--------------------------------------------\n|*             MENU PRINCIPAL             *|\n--------------------------------------------");
        
        option = getValidInt(menuPrinsipalMensaje, menuPrinsipalMensajeError, 1, 11);
        
        switch (option){
                
            case 1: // ALTA DE USUARIO
                controller_altaUser(userArray, USERS_MAX_QTY);
                break;
                
            case 2: // MODIFICAR DATOS DE USUARIO
                controller_modificarUser(userArray, USERS_MAX_QTY);
                break;
                
            case 3: // BAJA DE USUARIO
                controller_bajaUser(userArray, USERS_MAX_QTY, productArray, PRODUCTS_MAX_QTY);
                break;
                
            case 4: //  PUBLICAR PRODUCTO
                controller_altaProduct(productArray, PRODUCTS_MAX_QTY, userArray, USERS_MAX_QTY);
                break;
                
            case 5: // MODIFICAR PUBLICACION
                controller_modificarProduct(productArray, PRODUCTS_MAX_QTY, userArray, USERS_MAX_QTY);
                break;
                
            case 6: // CANCELAR PUBLICACION
                controller_bajaProduct(productArray, PRODUCTS_MAX_QTY, userArray, USERS_MAX_QTY);
                break;
                
            case 7: // COMPRAR PRODUCTO
                controller_buyProduct(productArray, PRODUCTS_MAX_QTY, userArray, USERS_MAX_QTY, saleArray, SALES_MAX_QTY);
                break;
                
            case 8: // LISTAR PUBLICACIONES DE USUARIO
                showUserProducts(productArray, PRODUCTS_MAX_QTY, userArray, USERS_MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;
            
            case 9: // LISTAR PUBLICACIONES
                showProductArray(productArray, PRODUCTS_MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;
                
            case 10: // LISTAR USUARIOS
                showUserSaleArray(userArray, USERS_MAX_QTY, saleArray, SALES_MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;
            
        }//switch (option)
    }//while (option != 4)
    
    return 0;
}//int main(void)





