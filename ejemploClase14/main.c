//
//  main.c
//  ejemploClase14
//
//  Created by Gaston Pesoa on 01/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "library.h"
#include "funcionesInput.h"

void adminBooks(book bookArray[]);
void adminAuthors(author authorArray[]);

int main(void) {
    
    //array de libros
    book bookArray[MAX_QTY];
    setBookStatus(bookArray, MAX_QTY, 0);
    
    //array de autores
    author authorArray[MAX_QTY];
    setAuthorStatus(authorArray, MAX_QTY, 0);
    
    // Alta de datos para testing
    setBook(bookArray,1,1,"What you need before you can learn C",1,777);
    setBook(bookArray,2,2,"Using a Compiler",2,33);
    setBook(bookArray,3,3,"A Taste of C",3,98);
    setBook(bookArray,4,4,"Why Learn C",1,876);
    
    setAuthor(authorArray,1,1,"Brian","Kernighan");
    setAuthor(authorArray,2,2,"Dennis","Ritchie");
    setAuthor(authorArray,3,3,"Linus","Torvalds");
    setAuthor(authorArray,4,4,"Richard","Stallman");
    
    int option = 0;
    
    while (option != 4) {
        
        system("@cls||clear");
        printf("\n-------------- MENU PRINCIPAL --------------");
        option = getInt("\n1 - ABM LIBROS \n2 - ABM AUTORES \n3 - LISTAR LIBROS\n4 - SALIR\n\n\n");
        
        switch (option){
                
            case 1: // ABM LIBROS
                
                adminBooks(bookArray);
                break;
                
            case 2: // ABM AUTORES
                
                adminAuthors(authorArray);
                break;
                
            case 3: // LISTAR
                
                system("@cls||clear");
                showBookAuthorArray(bookArray, MAX_QTY, authorArray, MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;
           /* case 4:
                option = 4;
                break;*/
        }
    }
    
    return 0;
}

void adminBooks(book bookArray[]){
    
    //variables auxiliares
    char titleAux[51];
    int authorIdAux;
    int codeAux;
    int stockAux;
    
    int freePlaceIndex;
    int foundIndex;
    char confirmar = 'n';
    int option = 0;
    
    //Menu opciones
    while (option != 6) {
        
        system("@cls||clear");
        printf("\n------------  ABM LIBROS ------------");
        option = getInt("\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - REGRESAR\n\n\n");
        
        switch (option){
                
            case 1: // Alta de libro
                
                printf("\nALTA DE LIBRO\n\n");
                
                freePlaceIndex = findBookEmptyPlace(bookArray, MAX_QTY);
                
                if (freePlaceIndex == -1) {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                
                codeAux = getValidInt("Ingrese el codigo del libro: ", "El codigo del libro debe ser numerico\n", 1, 15000);
                
                if (findBookByCode(bookArray, MAX_QTY, codeAux) != -1) {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                
                authorIdAux = getValidInt("Ingrese el ID del autor del libro: ", "El ID del autor debe ser numerico\n", 1, 500);
                stockAux = getValidInt("Ingrese la cantidad de libros: ", "La cantidad debe ser numerica\n", 1, 10000);
                getValidString("Ingrese el titulo: ", "El titulo debe estar compuesto solo por letras\n", titleAux);
                setBook(bookArray, freePlaceIndex, codeAux, titleAux, authorIdAux, stockAux);
                printf("\nALTA REALIZADA CON EXITO!\n");
                break;
                
            case 2: // Baja de libro
                
                printf("\nBAJA DE LIBRO\n\n");
                
                codeAux = getValidInt("Ingrese el codigo del libro a dar de baja: ", "El codigo del libro debe ser numerico\n", 1, 15000);
                foundIndex = findBookByCode(bookArray, MAX_QTY, codeAux);
                
                if (foundIndex == -1) {
                    printf("\n\nNO SE ENCONTRO ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                else {
                    showBook(bookArray[foundIndex]);
                    
                    do {
                        printf("\n\nSe esta por eliminar el libro seleccionado, confirma la baja? [s|n]: ");
                        fpurge(stdin);
                        scanf("%c", &confirmar);
                        confirmar = tolower(confirmar);
                    } while (confirmar != 's' && confirmar != 'n');
                    
                    if (confirmar == 's') {
                        bookArray[foundIndex].status = 0;
                        printf("\nSE HA DADO DE BAJA AL LIBRO\n\n");
                        break;
                    }
                    else {
                        printf("\nNO SE HA REALIZADO LA BAJA DEL LIBRO\n\n");
                        break;
                    }
                }
                
            case 3: // Modificacion de libro
                
                printf("\nMODIFICACION DE LIBRO\n\n");
                
                codeAux = getValidInt("Ingrese el codigo del libro a modificar: ", "El codigo del libro debe ser numerico\n", 1, 15000);
                foundIndex = findBookByCode(bookArray, MAX_QTY, codeAux);
                
                if (foundIndex == -1) {
                    printf("\n\nNO SE ENCONTRO ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                
                showBook(bookArray[foundIndex]);
                
                authorIdAux = getValidInt("Ingrese el ID del autor del libro: ", "El ID del autor debe ser numerico\n", 1, 500);
                stockAux = getValidInt("Ingrese la cantidad de libros: ", "La cantidad debe ser numerica\n", 1, 10000);
                getValidString("Ingrese el titulo: ", "El titulo debe estar compuesto solo por letras\n", titleAux);
                setBook(bookArray, foundIndex, codeAux, titleAux, authorIdAux, stockAux);
                break;
                
            case 4: //Listar libros
                
                system("@cls||clear");
                showBookArray(bookArray, MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;
                
            case 5: // Ordenar lista de libros
                
                orderBookArrayByTitle(bookArray, MAX_QTY);
                getChar("\n\nOrdenados. ENTER (para continuar)");
                break;
                
            /*case 6:
                option = 6;
                break;*/
                
        }//switch (option)
        
    }//while (option != 6)
}//void adminBooks(book bookArray[])

void adminAuthors(author authorArray[]){
    
    //variables auxiliares
    char nameAux[51];
    char lastNameAux[51];
    int authorIdAux;
    
    int freePlaceIndex;
    int foundIndex;
    char confirmar = 'n';
    int option = 0;
    
    while (option != 4) {
        
        system("@cls||clear");
        printf("\n------------  ABM AUTORES ------------");
        option = getInt("\n1 - ALTA \n2 - BAJA \n3 - LISTAR\n4 - REGRESAR\n\n\n");
        
        switch(option){
                
            case 1:// Alta de autor
                
                freePlaceIndex = findAuthorEmptyPlace(authorArray, MAX_QTY);
                if (freePlaceIndex == -1) {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                
                authorIdAux = getValidInt("Ingrese el codigo del autor: ","El codigo del autor debe ser numerico\n", 1, 500);
                if (findAuthorById(authorArray, MAX_QTY, authorIdAux) != -1) {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                
                getValidString("Ingrese el nombre del autor: ","El nombre debe estar compuesto solo por letras\n", nameAux);
                getValidString("Ingrese el apellido del autor: ","El nombre debe estar compuesto solo por letras\n", lastNameAux);
                setAuthor(authorArray, freePlaceIndex, authorIdAux, nameAux, lastNameAux);
                printf("\nALTA REALIZADA CON EXITO!\n");
                break;
                
            case 2://Baja de autor
                
                authorIdAux = getValidInt("Ingrese el codigo del autor: ","El codigo del autor debe ser numerico\n", 1, 500);
                foundIndex = findAuthorById(authorArray, MAX_QTY, authorIdAux);
                
                if (foundIndex == -1) {
                    printf("\n\nNO SE ENCONTRO ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                else {
                    showAuthor(authorArray[foundIndex]);
                    
                    do {
                        printf("\n\nSe esta por eliminar el autor seleccionado, confirma la baja? [s|n]: ");
                        fpurge(stdin);
                        scanf("%c", &confirmar);
                        confirmar = tolower(confirmar);
                    } while (confirmar != 's' && confirmar != 'n');
                    
                    if (confirmar == 's') {
                        authorArray[foundIndex].status = 0;
                        printf("\nSE HA DADO DE BAJA AL AUTOR\n\n");
                        break;
                    }
                    else {
                        printf("\nNO SE HA REALIZADO LA BAJA DEL AUTOR\n\n");
                        break;
                    }
                }
                
            case 3:// Listar
                
                system("@cls||clear");
                showAuthorArray(authorArray, MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;
                
        }
    }
}


