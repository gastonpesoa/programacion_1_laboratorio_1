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
#include "controllerFunctions.h"
#include "inputFunctions.h"




/** \brief Carga datos de prueba tanto en el array de productos como en el de usuarios
 * \param void
 * \return void
 */
void controller_test(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght){
    
    // Alta de datos para testing
    setProduct(productArray, 1, 1, "Televisor LED", 1, 23, 5000.00, 25);
    setProduct(productArray, 2, 2, "Mesa comedor", 2, 1, 2500.00, 3);
    setProduct(productArray, 3, 3, "Cocina ALBA", 3, 2, 3460.50, 0);
    setProduct(productArray, 4, 4, "Notebook DELL", 4, 10, 8799.00, 50);
    
    setUser(userArray, 1, 1, "robertexx", "ingreso1", 7);
    setUser(userArray, 2, 2, "ventasPepe", "ingreso4", 5);
    setUser(userArray, 3, 3, "dinamo", "ingreso3", 9);
    setUser(userArray, 1, 4, "antionoCarlos", "ingreso4", 4);
}

/** \brief Pide al usuario los datos de un nuevo producto y luego lo agrega al array
 * \param productArray el array de productos donde se alamcenara el nuevo producto
 * \param length int Longitud del array
 * \return -
 *
 */
void controller_altaProduct(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght){
    
    int productIdAux;
    char nameAux[51];
    int userIdAux;
    float priceAux;
    int stockAux;
    
    int freePlaceIndex;
    
    printf("\nPUBLICAR PRODUCTO\n\n");
    
    freePlaceIndex = findProductEmptyPlace(productArray, arrayProductLenght);
    
    if (freePlaceIndex == -1) {
        
        printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
        getChar("\n\nENTER (para continuar)");
    }
    else{
        
        userIdAux = getValidInt("Ingrese el ID de usuario: ", "El ID deber ser numerico", 1, 100);
        
        if (findUserById(userArray, USERS_MAX_QTY, userIdAux) == -1) {
            
            printf("\n\nEL USUARIO NO EXISTE!!!\n");
            getChar("\n\nENTER (para continuar)");
        }
        else {
            
            productIdAux = getValidInt("Ingrese el ID del producto: ", "El ID del producto debe ser numerico\n", 1, 1000);
            
            if (findProductById(productArray, PRODUCTS_MAX_QTY, productIdAux) != -1) {
                printf("\n\nEL ID YA EXISTE!!!\n");
                getChar("\n\nENTER (para continuar)");
            }
            else{
                
                getValidString("Ingrese el nombre: ", "El nombre debe estar compuesto solo por letras\n", nameAux);
                priceAux = getValidFloat("Ingrese el precio del producto: ", "El precio del producto debe ser numerico\n", 1, 999999999999);
                stockAux = getValidInt("Ingrese la cantidad de productos: ", "La cantidad debe ser numerica\n", 1, 10000);
                
                setProduct(productArray, freePlaceIndex, productIdAux, nameAux, userIdAux, stockAux, priceAux, 0);
                printf("\nPUBLICACION REALIZADA CON EXITO!\n");
                getChar("\n\nENTER (para continuar)");
                
            }//if (findProductById(productArray, PRODUCTS_MAX_QTY, productIdAux) != -1)
        }//if (findUserById(userArray, USERS_MAX_QTY, userIdSearchAux) == -1)
    }//if (freePlaceIndex == -1)
}//void controller_altaProduct(product productArray[], int arrayProductLenght, user userArray[], int arrayUserLenght)


/** \brief Pide al usuario el codigo del libro a ser dado de baja
 * \param book bookArray el array de libros donde se buscara el libro a eliminar
 * \param length int Longitud del array
 * \return -
 *
 */
void controller_bajaProduct(product productArray[], int arrayLenght, user userArray[], int arrayUserLenght){
    
    int productIdAux;
    int userIdAux;
    
    int i;
    int foundIndex;
    char confirmar = 'n';
    
    printf("\nCANCELAR PUBLICACIÓN\n\n");
    
    userIdAux = getValidInt("Ingrese el ID de usuario: ", "El ID de usuario debe ser numerico", 1, 100);
    
    if (findUserById(userArray, USERS_MAX_QTY, userIdAux) == -1) {
        
        printf("\n\nEL USUARIO NO EXISTE!!!\n");
        getChar("\n\nENTER (para continuar)");
    }
    else {
        
        for (i = 0; i < PRODUCTS_MAX_QTY; i++) {
            if (productArray[i].userId == userIdAux) {
                showProduct(productArray[i]);
            }
        }//for (i = 0; i < PRODUCTS_MAX_QTY; i++)
        
        productIdAux = getValidInt("Ingrese el ID del producto a dar de baja: ", "El ID del producto debe ser numerico\n", 1, 1000);

        foundIndex = findProductById(productArray, PRODUCTS_MAX_QTY, productIdAux);
        
        if (foundIndex == -1) {
            
            printf("\n\nNO SE ENCONTRO ESE ID\n");
            getChar("\n\nENTER (para continuar)");
        }
        else {
            
            showProduct(productArray[foundIndex]);
            
            confirmar = confirm("\n\nSe esta por eliminar el producto seleccionado, confirma la baja? [s|n]: ");
            
            if (confirmar == 's') {
                
                productArray[foundIndex].status = 0;
                printf("\nSE HA CANCELADO LA PUBLICACION\n\n");
                getChar("\n\nENTER (para continuar)");
            }
            else {
                
                printf("\nNO SE HA CANCELADO LA PUBLICACION\n\n");
                getChar("\n\nENTER (para continuar)");
            }
        }
    }//if (findUserById(userArray, USERS_MAX_QTY, userIdAux) == -1)
}

/** \brief Pide al usuario el ID del producto a ser modificado, despliega un menu de opciones de los campos disponibles y luego de confirmar los modifica
 * \param book bookArray el array de libros donde se buscara el libro a ser modificado
 * \param length int Longitud del array
 * \return -
 *
 */
void controller_modificarUser(product productArray[], int arrayLenght, user userArray[], int arrayUserLenght){
    
    int productIdAux;
    int userIdAux;
    float priceAux;
    int stockAux;
    
    int i;
    int foundIndex;
    char confirmar = 'n';
    int option;
    
    printf("\nMODIFICACION DE PUBLICACION\n\n");
    
    userIdAux = getValidInt("Ingrese el ID de usuario: ", "El ID de usuario debe ser numerico\n", 1, 100);
    if (findUserById(userArray, USERS_MAX_QTY, userIdAux) == -1) {
        
        printf("\n\nEL USUARIO NO EXISTE!!!\n");
        getChar("\n\nENTER (para continuar)");
    }
    else {
        
        for (i = 0; i < PRODUCTS_MAX_QTY; i++) {
            if (productArray[i].userId == userIdAux) {
                showProduct(productArray[i]);
            }
        }//for (i = 0; i < PRODUCTS_MAX_QTY; i++)
        
        productIdAux = getValidInt("Ingrese el ID del producto a dar de baja: ", "El ID del producto debe ser numerico\n", 1, 1000);
        
        foundIndex = findProductById(productArray, PRODUCTS_MAX_QTY, productIdAux);
        
        if (foundIndex == -1) {
            
            printf("\n\nNO SE ENCONTRO ESE ID\n");
            getChar("\n\nENTER (para continuar)");
        }
        else {
            
            showProduct(productArray[foundIndex]);
            
            confirmar = confirm("\n\nSe esta por eliminar el producto seleccionado, confirma la baja? [s|n]: ");
            
            if (confirmar == 's') {
                
                productArray[foundIndex].status = 0;
                printf("\nSE HA CANCELADO LA PUBLICACION\n\n");
                getChar("\n\nENTER (para continuar)");
            }	
            else {
                
                printf("\nNO SE HA CANCELADO LA PUBLICACION\n\n");
                getChar("\n\nENTER (para continuar)");
            }
        }
    }//if (findUserById(userArray, USERS_MAX_QTY, userIdAux) == -1)
    
    /*if (foundIndex == -1) {
        
        printf("\n\nNO SE ENCONTRO ESE CODIGO\n");
        getChar("\n\nENTER (para continuar)");
    }
    else{
        
        showBook(bookArray[foundIndex]);
        
        authorIdAux = bookArray[foundIndex].authorId;
        stockAux = bookArray[foundIndex].stock;
        strcpy(titleAux, bookArray[foundIndex].title);
        
        option = optionMenu("\n\n1 - MODIFICAR ID DEL AUTOR \n2 - MODIFICAR CANTIDAD DE LIBROS \n3 - MODIFICAR TITULO\n4 - REGRESAR\n\n\n", "\nSe debe elegir una opcion del 1 al 4", 1, 4);
        
        switch (option){
                
            case 1:// Modificacion de ID de autor
                authorIdAux = getValidInt("Ingrese el ID del autor del libro: ", "El ID del autor debe ser numerico\n", 1, 500);
                break;
                
            case 2:// Modificacion de stock
                stockAux = getValidInt("Ingrese la cantidad de libros: ", "La cantidad debe ser numerica\n", 1, 10000);
                break;
                
            case 3:// Modificacion del titulo
                getValidString("Ingrese el titulo: ", "El titulo debe estar compuesto solo por letras\n", titleAux);
                break;
        }
        
        confirmar = confirm("\n\nSe esta por modificar el libro seleccionado, confirma la modificacion? [s|n]: ");
        if (confirmar == 's') {
            
            setBook(bookArray, foundIndex, codeAux, titleAux, authorIdAux, stockAux);
            printf("\nSE HAN MODIFICADO LOS DATOS DEL LIBRO\n\n");
            getChar("\n\nENTER (para continuar)");
        }
        else {
            
            printf("\nNO SE HA REALIZADO LA MODIFICACION DEL LIBRO\n\n");
            getChar("\n\nENTER (para continuar)");
        }
    }*/
}

/** \brief Pide al usuario los datos de un nuevo autor y luego lo agrega al array
 * \param bauthor authorArray el array de autores donde se alamcenara el nuevo autor
 * \param length int Longitud del array
 * \return -
 *
 */
void controller_altaAuthor(author authorArray[], int arrayLenght){
    
    char nameAux[51];
    char lastNameAux[51];
    int authorIdAux;
    
    int freePlaceIndex;
    
    freePlaceIndex = findAuthorEmptyPlace(authorArray, AUTHORS_MAX_QTY);
    if (freePlaceIndex == -1) {
        printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
        getChar("\n\nENTER (para continuar)");
    }
    else {
        authorIdAux = getValidInt("Ingrese el codigo del autor: ","El codigo del autor debe ser numerico\n", 1, 500);
        if (findAuthorById(authorArray, AUTHORS_MAX_QTY, authorIdAux) != -1) {
            printf("\n\nEL CODIGO YA EXISTE!!!\n");
            getChar("\n\nENTER (para continuar)");
        }
        else {
            getValidString("Ingrese el nombre del autor: ","El nombre debe estar compuesto solo por letras\n", nameAux);
            getValidString("Ingrese el apellido del autor: ","El nombre debe estar compuesto solo por letras\n", lastNameAux);
            
            setAuthor(authorArray, freePlaceIndex, authorIdAux, nameAux, lastNameAux);
            printf("\nALTA REALIZADA CON EXITO!\n");
            getChar("\n\nENTER (para continuar)");
        }
    }
}


/** \brief Pide al usuario el codigo del libro a ser dado de baja
 * \param book bookArray el array de libros donde se buscara el libro a eliminar
 * \param length int Longitud del array
 * \return -
 *
 */
void controller_bajaAuthor(author authorArray[], int arrayLenght){
    
    int authorIdAux;
    
    int foundIndex;
    char confirmar = 'n';
    
    authorIdAux = getValidInt("Ingrese el codigo del autor: ","El codigo del autor debe ser numerico\n", 1, 500);
    foundIndex = findAuthorById(authorArray, AUTHORS_MAX_QTY, authorIdAux);
    
    if (foundIndex == -1) {
        
        printf("\n\nNO SE ENCONTRO ESE CODIGO\n");
        getChar("\n\nENTER (para continuar)");
    }
    else {
        
        showAuthor(authorArray[foundIndex]);
        
        confirmar = confirm("\n\nSe esta por eliminar el autor seleccionado, confirma la baja? [s|n]: ");
        if (confirmar == 's') {
            
            authorArray[foundIndex].status = 0;
            printf("\nSE HA DADO DE BAJA AL AUTOR\n\n");
            getChar("\n\nENTER (para continuar)");
        }
        else {
            
            printf("\nNO SE HA REALIZADO LA BAJA DEL AUTOR\n\n");
            getChar("\n\nENTER (para continuar)");
        }
    }
}

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
