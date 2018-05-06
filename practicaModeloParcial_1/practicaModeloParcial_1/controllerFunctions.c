//
//  controllerFunctions.c
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



/** \brief Carga datos de prueba tanto en el array de productos, en el de usuarios como en el de ventas
 * \param productArray Es el array de productos
 * \param userArray Es el array de usuarios
 * \param saleArray Es el array de ventas
 * \return void
 */
void controller_test(product productArray[], user userArray[], sale saleArray[]){
    
    // Alta de datos para testing
    setProduct(productArray, 0, 1, "Televisor LED", 1, 5000.00, 23, 25);
    setProduct(productArray, 1, 2, "Mesa comedor", 2, 2500.00, 1, 3);
    setProduct(productArray, 2, 3, "Cocina ALBA", 3, 3460.50, 2, 0);
    setProduct(productArray, 3, 4, "Notebook DELL", 4, 8799.00, 10, 50);
    setProduct(productArray, 4, 5, "Vaso de vidrio", 1, 20.00, 1, 25);
    
    setUser(userArray, 0, 1, "robertexx", "ingreso1");
    setUser(userArray, 1, 2, "ventasPepe", "ingreso4");
    setUser(userArray, 2, 3, "dinamo", "ingreso3");
    setUser(userArray, 3, 4, "antionoCarlos", "ingreso4");
    
    setSale(saleArray, 0, 1, 9);
    setSale(saleArray, 1, 1, 6);
    setSale(saleArray, 2, 2, 4);
    setSale(saleArray, 3, 2, 8);
    setSale(saleArray, 4, 3, 3);
    setSale(saleArray, 5, 4, 7);
}


/** \brief Pide al usuario los datos de un nuevo usuario y luego lo agrega al array
 * \param userArray El array de usuarios donde se alamcenara el nuevo usuario
 * \param arrayUserLenght Longitud del array
 * \return -
 *
 */
void controller_altaUser(user userArray[], int arrayUserLenght){
    
    clearScreen();
    char nameAux[51];
    char passwordAux[51];
    
    int freePlaceIndex;
    
    printf("\n-----------------------\n|*  ALTA DE USUARIO  *|\n-----------------------\n");
    
    freePlaceIndex = findUserEmptyPlace(userArray, arrayUserLenght);
    if (freePlaceIndex == -1) {
        
        printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
        getChar("\n\nENTER (para continuar)");
    }
    else {
        
        getValidStringAlfanumerico("\nIngrese el nombre de usuario: ","El nombre debe estar compuesto solo por letras y numeros\n", nameAux);
        getValidStringAlfanumerico("\nIngrese password: ","El password debe estar compuesto solo por letras y numeros\n", passwordAux);
        
        setUser(userArray, freePlaceIndex, freePlaceIndex, nameAux, passwordAux);
        
        clearScreen();
        printf("\nALTA REALIZADA CON EXITO!\n");
        showUser(userArray[freePlaceIndex]);
        getChar("\n\nENTER (para continuar)");
        
    }// if (freePlaceIndex == -1)
}// void controller_altaUser(user userArray[], int arrayUserLenght)



/** \brief Pide al usuario el ID del ususario a ser dado de baja, luego de validar y confirmar lo da de baja junto con todas sus publicaciones
 * \param userArray El array de usuarios donde se buscara el usuario a eliminar
 * \param arrayUserLenght Longitud del array de usuarios
 * \param productArray El array de productos donde se buscaran las publicaciones del usuario a eliminar
 * \param arrayProductLenght Longitud del array de usuarios
 * \return -
 *
 */
void controller_bajaUser(user userArray[], int arrayUserLenght, product productArray[], int arrayProductLenght){
    
    int userIdAux;
    
    int foundIndex;
    char confirmar = 'n';
    int i;
    
    clearScreen();
    printf("\n-----------------------\n|*  BAJA DE USUARIO  *|\n-----------------------\n");
    
    userIdAux = getValidInt("\nIngrese el ID del usuario : ","El ID de usuario debe ser numerico\n", 1, arrayUserLenght);
    foundIndex = findUserById(userArray, arrayUserLenght, userIdAux);
    if (foundIndex == -1) {
        
        printf("\n\nNO SE ENCONTRO ESE ID\n");
        getChar("\n\nENTER (para continuar)");
    }
    else {
        
        // Se muestra el usuario a dar de baja
        showUser(userArray[foundIndex]);
        
        confirmar = confirm("\n\nSe esta por eliminar el usuario seleccionado, confirma la baja? [s|n]: ");
        if (confirmar == 's') {
            
            // Se eliminan las publicaciones del usuario
            for(i = 0; i < arrayProductLenght; i++){
                if(productArray[i].userId == userIdAux){
                    productArray[i].status = INACTIVE;
                }
            }// for(i = 0; i < arrayProductLenght; i++)
            
            // Se da de baja al usuario
            userArray[foundIndex].status = INACTIVE;
            printf("\nSE HA DADO DE BAJA AL USUARIO\n\n");
            getChar("\n\nENTER (para continuar)");
        }
        else {
            
            printf("\nNO SE HA REALIZADO LA BAJA DEL USUARIO\n\n");
            getChar("\n\nENTER (para continuar)");
            
        }//  if (confirmar == 's')
    }// if (foundIndex == -1)
}// void controller_bajaUser(user userArray[], int arrayLenght, product productArray[], int productArrayLenght)


/** \brief Pide al usuario el ID de usuario a ser modificado, despliega un menu de opciones con los campos disponibles y luego de confirmar los modifica
 * \param userArray El array de usuarios donde se buscara el usuario a ser modificado
 * \param arrayUserLenght Longitud del array de usuarios
 * \return -
 *
 */
void controller_modificarUser(user userArray[], int arrayUserLenght){
    
    int userIdAux;
    char nameAux[51];
    char passwordAux[51];
    
    int foundIndex;
    char confirmar = 'n';
    int option;
    
    char menuModificarUserMensaje[] =
                    "\n\n1 - MODIFICAR NOMBRE\
                    \n2 - MODIFICAR PASSWORD\
                    \n3 - REGRESAR\
                    \n\nIngrese una opcion: ";
    
    char menuModificarUserMensajeError[] = "\nSe debe elegir una opcion del 1 al 3";
    
    clearScreen();
    printf("\n-------------------------------\n|*  MODIFICACION DE USUARIO  *|\n-------------------------------\n");
    
    userIdAux = getValidInt("\nIngrese el ID de usuario a modificar: ", "El ID de usuario debe ser numerico\n", 1, 100);
    foundIndex = findUserById(userArray, arrayUserLenght, userIdAux);
    if (foundIndex == -1) {
        
        printf("\n\nEL USUARIO NO EXISTE!!!\n");
        getChar("\n\nENTER (para continuar)");
    }
    else {
        
        // Se muestra el ususario a modificar
        showUser(userArray[foundIndex]);
        
        strcpy(nameAux, userArray[foundIndex].name);
        strcpy(passwordAux, userArray[foundIndex].password);
        
        while(option != 3){
            
            //clearScreen();
            option = getValidInt(menuModificarUserMensaje, menuModificarUserMensajeError, 1, 3);
            
            switch(option){
                    
                case 1: // Modificacion del nombre de usuario
                    getValidStringAlfanumerico("\nIngrese el nombre de usuario: ","El nombre debe estar compuesto solo por letras y numeros\n", nameAux);
                    break;
                    
                case 2: // Modificacion del password de usuario
                    getValidStringAlfanumerico("\nIngrese password: ","El password debe estar compuesto solo por letras y numeros\n", passwordAux);
                    break;
                    
                case 3:
                    continue;
                    
            }// switch(option)
            
            confirmar = confirm("\nSe esta por modifcar la publicacion seleccionada, confirma la modificacion? [s|n]: ");
            if(confirmar == 's'){
                
                setUser(userArray, foundIndex, userIdAux, nameAux, passwordAux);
                printf("\nSE HAN MODIFICADO LOS DATOS DEL USUARIO\n\n");
                getChar("\n\nENTER (para continuar)");
            }
            else{
                
                printf("\nNO SE HA REALIZADO LA MODIFICACION DEL USUARIO\n\n");
                getChar("\n\nENTER (para continuar)");
                
            }// if(confirmar == 's')
        }// if (foundIndex == -1)
    }// void controller_modificarUser(user userArray[], int arrayUserLenght)
}


/** \brief Pide al usuario los datos de un nuevo producto y luego lo agrega al array
 * \param productArray el array de productos donde se alamcenara el nuevo producto
 * \param arrayProductLenght Longitud del array de productos
 * \param userArray el array de usuarios donde se buscara el ID del mismo para dar de alta el prodcto con este dato relacionado
 * \param arrayUserLenght Longitud del array de usuarios
 * \return -
 *
 */
void controller_altaProduct(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght){
    
    char nameAux[51];
    int userIdAux;
    float priceAux;
    int stockAux;
    
    int freePlaceIndex;
    int foundIndex;
    
    printf("\n-------------------------\n|*  PUBLICAR PRODUCTO  *|\n-------------------------\n");
    
    freePlaceIndex = findProductEmptyPlace(productArray, arrayProductLenght);
    if (freePlaceIndex == -1) {
        
        printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
        getChar("\n\nENTER (para continuar)");
    }
    else{
        
        userIdAux = getValidInt("\nIngrese el ID de usuario: ", "El ID deber ser numerico", 1, 100);
        foundIndex = findUserById(userArray, arrayUserLenght, userIdAux);
        if (foundIndex == -1) {
            
            printf("\n\nEL USUARIO NO EXISTE!!!\n");
            getChar("\n\nENTER (para continuar)");
        }
        else {
            
            getValidStringNombre("\nIngrese el nombre del producto: ", "El nombre debe estar compuesto solo por letras\n", nameAux);
            priceAux = getValidFloat("\nIngrese el precio del producto: ", "El precio del producto debe ser numerico\n", 1, 999999999999);
            stockAux = getValidInt("\nIngrese la cantidad de productos: ", "La cantidad debe ser numerica\n", 1, 10000);
            
            setProduct(productArray, freePlaceIndex, freePlaceIndex, nameAux, userIdAux, priceAux, stockAux, 0);
            
            clearScreen();
            printf("\nPUBLICACION REALIZADA CON EXITO!\n");
            printf("\n-----------------------------------------------------------------------------------------------------");
            printf("\n|    ID   |                      NOMBRE              |  PRECIO | CANTIDAD VENDIDA | STOCK | USUARIO |");
            printf("\n-----------------------------------------------------------------------------------------------------");
            showProduct(productArray[freePlaceIndex]);
            printf("\n-----------------------------------------------------------------------------------------------------");
            
            getChar("\n\nENTER (para continuar)");
            
        }// if (foundIndex == -1)
    }//if (freePlaceIndex == -1)
}//void controller_altaProduct(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght)


/** \brief Pide al usuario el ID de usuario y el codigo del producto a ser dado de baja, luego de validar y confirmar cancela la publicacion
 * \param productArray El array de productos donde se buscara la publicacion a eliminar
 * \param arrayProductLenght Longitud del array de usuarios
 * \param userArray El array de usuarios donde se buscara el usuario del que se desea eliminar su publicacion
 * \param arrayUserLenght Longitud del array de usuarios
 * \return -
 *
 */
void controller_bajaProduct(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght){
    
    int productIdAux;
    int userIdAux;
    
    int i;
    int foundIndex;
    char confirmar = 'n';
    
    printf("\n----------------------------\n|*  CANCELAR PUBLICACIÓN  *|\n----------------------------\n");
    
    userIdAux = getValidInt("\nIngrese el ID de usuario: ", "El ID de usuario debe ser numerico", 1, 100);
    if (findUserById(userArray, arrayUserLenght, userIdAux) == -1) {
        
        printf("\n\nEL USUARIO NO EXISTE!!!\n");
        getChar("\n\nENTER (para continuar)");
    }
    else {
        
        //Se listan los productos del usuario ingresado
        printf("\n-----------------------------------------------------------------------------------------------------");
        printf("\n|    ID   |                      NOMBRE              |  PRECIO | CANTIDAD VENDIDA | STOCK | USUARIO |");
        printf("\n-----------------------------------------------------------------------------------------------------");
        for (i = 0; i < arrayProductLenght; i++) {
            if (productArray[i].userId == userIdAux) {
                
                showProduct(productArray[i]);
            }
        }//for (i = 0; i < PRODUCTS_MAX_QTY; i++)
        printf("\n-----------------------------------------------------------------------------------------------------\n");
        
        productIdAux = getValidInt("\nIngrese el ID del producto a dar de baja: ", "El ID del producto debe ser numerico\n", 1, 1000);
        foundIndex = findProductById(productArray, arrayProductLenght, productIdAux);
        if (foundIndex == -1) {
            
            printf("\n\nNO SE ENCONTRO ESE ID\n");
            getChar("\n\nENTER (para continuar)");
        }
        else {
            
            //Se muestra el producto seleccionado
            printf("\n-----------------------------------------------------------------------------------------------------");
            printf("\n|    ID   |                      NOMBRE              |  PRECIO | CANTIDAD VENDIDA | STOCK | USUARIO |");
            printf("\n-----------------------------------------------------------------------------------------------------");
            showProduct(productArray[foundIndex]);
            printf("\n-----------------------------------------------------------------------------------------------------\n");
            
            confirmar = confirm("\n\nSe esta por eliminar el producto seleccionado, confirma la baja? [s|n]: ");
            if (confirmar == 's') {
                
                productArray[foundIndex].status = INACTIVE;
                printf("\nSE HA CANCELADO LA PUBLICACION\n\n");
                getChar("\n\nENTER (para continuar)");
            }
            else {
                
                printf("\nNO SE HA CANCELADO LA PUBLICACION\n\n");
                getChar("\n\nENTER (para continuar)");
                
            }// if (confirmar == 's')
        } //if (foundIndex == -1)
    }// if (findUserById(userArray, USERS_MAX_QTY, userIdAux) == -1)
}

/** \brief Pide al usuario el ID del producto a ser modificado, despliega un menu de opciones de los campos disponibles y luego de confirmar los modifica
 * \param productArray El array de productos donde se buscara la publicacion a modificar
 * \param arrayProductLenght Longitud del array de productos
 * \param userArray El array de usuarios donde se buscara el usuario del que se desea modificar su publicacion
 * \param arrayUserLenght Longitud del array de usuarios
 * \return -
 *
 */
void controller_modificarProduct(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght){
    
    int productIdAux;
    char nameAux[51];
    int userIdAux;
    float priceAux;
    int stockAux;
    int salesQtyAux;
    
    int i;
    int foundUserIndex;
    int foundProductIndex;
    char confirmar = 'n';
    int option = 0;
    char menuModificarProductMensaje[] =
                    "\n\n1 - MODIFICAR PRECIO\
                    \n2 - MODIFICAR STOCK\
                    \n3 - REGRESAR\
                    \n\nIngrese una opcion: ";
    
    char menuModificarProductMensajeError[] = "\nSe debe elegir una opcion del 1 al 3";
    
    printf("\n-----------------------------------\n|*  MODIFICACION DE PUBLICACION  *|\n-----------------------------------\n");
    
    userIdAux = getValidInt("\nIngrese el ID de usuario: ", "El ID de usuario debe ser numerico\n", 1, 100);
    foundUserIndex = findUserById(userArray, arrayUserLenght, userIdAux);
    if (foundUserIndex == -1) {
        
        printf("\n\nEL USUARIO NO EXISTE!!!\n");
        getChar("\n\nENTER (para continuar)");
    }
    else {
        
        //Se listan los productos del usuario ingresado
        printf("\n-----------------------------------------------------------------------------------------------------");
        printf("\n|    ID   |                      NOMBRE              |  PRECIO | CANTIDAD VENDIDA | STOCK | USUARIO |");
        printf("\n-----------------------------------------------------------------------------------------------------");
        for (i = 0; i < arrayProductLenght; i++) {
            if (productArray[i].userId == userIdAux) {
                
                showProduct(productArray[i]);
            }
        }//for (i = 0; i < PRODUCTS_MAX_QTY; i++)
        printf("\n-----------------------------------------------------------------------------------------------------\n");
        
        productIdAux = getValidInt("\nIngrese el ID del producto a modificar: ", "El ID del producto debe ser numerico\n", 1, 1000);
        foundProductIndex = findProductById(productArray, arrayProductLenght, productIdAux);
        if (foundProductIndex == -1) {
            
            printf("\n\nNO SE ENCONTRO ESE ID\n");
            getChar("\n\nENTER (para continuar)");
        }
        else {
            
            //Se muestra el producto seleccionado
            printf("\n-----------------------------------------------------------------------------------------------------");
            printf("\n|    ID   |                      NOMBRE              |  PRECIO | CANTIDAD VENDIDA | STOCK | USUARIO |");
            printf("\n-----------------------------------------------------------------------------------------------------");
            showProduct(productArray[foundProductIndex]);
            printf("\n-----------------------------------------------------------------------------------------------------");
            
            strcpy(nameAux, productArray[foundProductIndex].name);
            priceAux = productArray[foundProductIndex].price;
            stockAux = productArray[foundProductIndex].stock;
            salesQtyAux = productArray[foundProductIndex].salesQty;
            
            while(option != 3){
                
                //clearScreen();
                option = getValidInt(menuModificarProductMensaje, menuModificarProductMensajeError, 1, 3);
                
                switch(option){
                        
                    case 1: // Modificacion de precio
                        priceAux = getValidFloat("Ingrese el precio del producto: ", "El precio del producto debe ser numerico\n", 1, 999999999999);
                        break;
                        
                    case 2: // Modificacion de stock
                        stockAux = getValidInt("Ingrese la cantidad de productos: ", "La cantidad debe ser numerica\n", 1, 10000);
                        break;
                    
                    case 3:
                        continue;
                        
                }// switch(option)
            
                confirmar = confirm("\n\nSe esta por modifcar la publicacion seleccionada, confirma la modificacion? [s|n]: ");
            
                if (confirmar == 's') {
                
                    setProduct(productArray, foundProductIndex, productIdAux, nameAux, userIdAux, priceAux, stockAux, salesQtyAux);
                    printf("\nSE HA MODIFICADO LA PUBLICACION\n\n");
                    getChar("\n\nENTER (para continuar)");
                }
                else {
                
                    printf("\nNO SE HA MODIFICADO LA PUBLICACION\n\n");
                    getChar("\n\nENTER (para continuar)");
                }// if (confirmar == 's')
            }// while(option != 3)
        }// if (foundIndex == -1)
    }//
}


/** \brief Lista las publicaciones disponibles y solicita el ID del producto que se desea comprar, 
 * \en el caso que haya stock se realizará la compra y se ingresará una calificación para el vendedor
 * \param productArray El array de productos donde se buscara el ID del producto que se dessea comprar
 * \param arrayProductLenght Longitud del array de productos
 * \param userArray El array de usuarios donde se buscara el usuario a ser calificado
 * \param arrayUserLenght Longitud del array de usuarios
 * \param saleArray El array de ventas donde se almacenara el usuario y su calificacion
 * \param arraySaleLenght Longitud del array de ventas
 * \return -
 *
 */
void controller_buyProduct(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght, sale saleArray[], int arraySaleLenght){
    
    int freePlaceIndex, productIdAux, foundIndex, qualificationAux, userIdAux;
    char confirmar = 'n';
    
    clearScreen();
    printf("\n--------------------");
    printf("\n| COMPRAR PRODUCTO |");
    printf("\n--------------------\n");
    
    // Se listan los productos disponibles
    showProductArray(productArray, arrayProductLenght);
    
    freePlaceIndex = findSaleEmptyPlace(saleArray, arraySaleLenght);
    if (freePlaceIndex == -1) {
        
        printf("\n\nSISTEMA NO DISPONIBLE!!!\n");
        getChar("\n\nENTER (para continuar)");
    }
    else {
        
        productIdAux = getValidInt("\n\nIngrese el ID del producto que desea comprar: ", "El ID debe ser numerico\n", 1, arrayProductLenght);
        foundIndex = findProductById(productArray, arrayProductLenght, productIdAux);
        if (foundIndex == -1) {
            
            printf("\n\nEL PRODUCTO NO EXISTE!!!\n");
            getChar("\n\nENTER (para continuar)");
        }
        else {
            if (productArray[foundIndex].stock == 0) {
                
                printf("\n\nEL PRODUCTO SELECCIONADO NO TIENE STOCK DISPONIBLE!!!\n");
                getChar("\n\nENTER (para continuar)");
            }
            else {
                
                // Se muestra el producto seleccionado
                printf("\n-----------------------------------------------------------------------------------------------------");
                printf("\n|    ID   |                      NOMBRE              |  PRECIO | CANTIDAD VENDIDA | STOCK | USUARIO |");
                printf("\n-----------------------------------------------------------------------------------------------------");
                showProduct(productArray[foundIndex]);
                printf("\n-----------------------------------------------------------------------------------------------------");
                
                confirmar = confirm("\n\nEsta por comprar la publicacion seleccionada, confirma la compra? [s|n]: ");
                if(confirmar == 's'){
                    
                    // Se descuenta un producto del stock
                    productArray[foundIndex].stock = productArray[foundIndex].stock - 1;
                    
                    //Se solicita calificacion
                    printf("\n\nFELICITACIONES!!! COMPRA REALIZADA!!!\n");
                    qualificationAux = getValidInt("Ingrese una calificacion para el vendedor [Entre 1 y 10]: ", "La calificacion debe ser numerica\n", 1, 10);
                    
                    //Se asigna la calificacion al array de ventas
                    userIdAux = productArray[foundIndex].userId;
                    setSale(saleArray, freePlaceIndex, userIdAux, qualificationAux);
                }
                else{
                    
                    printf("\nNO SE HA REALIZADO LA COMPRA\n\n");
                    getChar("\n\nENTER (para continuar)");
                    
                }// if(confirmar == 's')
            }
        }// if (foundIndex == -1)
    }// if (freePlaceIndex == -1)
}// void controller_buyProduct(product productArray[], int arrayProductLenght)




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
