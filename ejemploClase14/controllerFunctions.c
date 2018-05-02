//
//  controllerFunctions.c
//  ejemploClase14
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
#include "adminFunctions.h"
#include "funcionesMenus.h"
#include "controllerFunctions.h"
#include "bookFunctions.h"
#include "authorsFunctions.h"
#include "booksAuthorsFunctions.h"
#include "funcionesInput.h"


/** \brief Carga datos de prueba tanto en el array de libros como en el de autores
 * \param void
 * \return void
 */
void controller_test(book bookArray[], int arrayBookLenght, author authorArray[], int arrayAuthorLenght){
    
    // Alta de datos para testing
    setBook(bookArray,1,1,"What you need before you can learn C",1,777);
    setBook(bookArray,2,2,"Using a Compiler",2,33);
    setBook(bookArray,3,3,"A Taste of C",3,98);
    setBook(bookArray,4,4,"Why Learn C",1,876);
    
    setAuthor(authorArray,1,1,"Brian","Kernighan");
    setAuthor(authorArray,2,2,"Dennis","Ritchie");
    setAuthor(authorArray,3,3,"Linus","Torvalds");
    setAuthor(authorArray,4,4,"Richard","Stallman");
};

/** \brief Pide al usuario los datos de un nuevo libro y luego lo agrega al array
 * \param book bookArray el array de libros donde se alamcenara el nuevo libro
 * \param length int Longitud del array
 * \return -
 *
 */
void controller_altaBook(book bookArray[], int arrayLenght){
    
    char titleAux[51];
    int authorIdAux;
    int codeAux;
    int stockAux;
    
    int freePlaceIndex;

    printf("\nALTA DE LIBRO\n\n");
    
    freePlaceIndex = findBookEmptyPlace(bookArray, BOOKS_MAX_QTY);
    
    if (freePlaceIndex == -1) {
        
        printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
        getChar("\n\nENTER (para continuar)");
    }
    else{
        
        codeAux = getValidInt("Ingrese el codigo del libro: ", "El codigo del libro debe ser numerico\n", 1, 15000);
        
        if (findBookByCode(bookArray, BOOKS_MAX_QTY, codeAux) != -1) {
            printf("\n\nEL CODIGO YA EXISTE!!!\n");
            getChar("\n\nENTER (para continuar)");
        }
        else{
            
            authorIdAux = getValidInt("Ingrese el ID del autor del libro: ", "El ID del autor debe ser numerico\n", 1, 500);
            stockAux = getValidInt("Ingrese la cantidad de libros: ", "La cantidad debe ser numerica\n", 1, 10000);
            getValidString("Ingrese el titulo: ", "El titulo debe estar compuesto solo por letras\n", titleAux);
            
            setBook(bookArray, freePlaceIndex, codeAux, titleAux, authorIdAux, stockAux);
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
void controller_bajaBook(book bookArray[], int arrayLenght){
    
    int codeAux;
    
    int foundIndex;
    char confirmar = 'n';
    
    printf("\nBAJA DE LIBRO\n\n");
    
    codeAux = getValidInt("Ingrese el codigo del libro a dar de baja: ", "El codigo del libro debe ser numerico\n", 1, 15000);
    foundIndex = findBookByCode(bookArray, BOOKS_MAX_QTY, codeAux);
    
    if (foundIndex == -1) {
        
        printf("\n\nNO SE ENCONTRO ESE CODIGO\n");
        getChar("\n\nENTER (para continuar)");
    }
    else {
        
        showBook(bookArray[foundIndex]);
        
        confirmar = confirm("\n\nSe esta por eliminar el libro seleccionado, confirma la baja? [s|n]: ");
        
        if (confirmar == 's') {
            
            bookArray[foundIndex].status = 0;
            printf("\nSE HA DADO DE BAJA AL LIBRO\n\n");
            getChar("\n\nENTER (para continuar)");
        }
        else {
            
            printf("\nNO SE HA REALIZADO LA BAJA DEL LIBRO\n\n");
            getChar("\n\nENTER (para continuar)");
        }
    }
}

/** \brief Pide al usuario el codigo del libro a ser modificado, despliega un menu de opciones de los campos disponibles y luego de confirmar los modifica
 * \param book bookArray el array de libros donde se buscara el libro a ser modificado
 * \param length int Longitud del array
 * \return -
 *
 */
void controller_modificarBook(book bookArray[], int arrayLenght){
    
    char titleAux[51];
    int authorIdAux;
    int codeAux;
    int stockAux;
    
    int foundIndex;
    int option;
    char confirmar = 'n';
    
    printf("\nMODIFICACION DE LIBRO\n\n");
    
    codeAux = getValidInt("Ingrese el codigo del libro a modificar: ", "El codigo del libro debe ser numerico\n", 1, 15000);
    foundIndex = findBookByCode(bookArray, BOOKS_MAX_QTY, codeAux);
    
    if (foundIndex == -1) {
        
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
    }
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
