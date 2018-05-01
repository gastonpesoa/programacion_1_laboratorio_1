//
//  main.c
//  ejemploClase13
//
//  Created by Gaston Pesoa on 30/04/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "library.h"
#include "funcionesInput.h"

#define MAX_QTY 10

int main(void) {
    
    //array de libros
    book bookArray[MAX_QTY];
    
    //variables auxiliares
    char titleAux[51];
    int authorIdAux;
    int codeAux;
    int stockAux;
    
    int freePlaceIndex;
    int foundIndex;
    char confirmar;
    int option = 0;
    
    //Inicializo status libre
    setStatus(bookArray, MAX_QTY, 0);
    
    // Alta de datos para testing
    setBook(bookArray,1,1,"What you need before you can learn",1,777);
    setBook(bookArray,2,2,"Using a Compiler",2,33);
    setBook(bookArray,3,3,"A Taste of C",3,98);
    setBook(bookArray,4,4,"Why Learn C",1,876);
    
    //Menu opciones
    while (option != 6) {
        
        option = getInt("\n\n\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - SALIR\n\n\n");
        
        switch (option){
                
            case 1: // Alta de libro
                
                printf("\nALTA DE LIBROS\n\n");
                
                freePlaceIndex = findEmptyPlace(bookArray, MAX_QTY);
                
                if (freePlaceIndex == -1) {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    break;
                }
                
                codeAux = getValidInt("Ingrese el codigo del libro: ", "El codigo del libro debe ser numerico\n", 1, 15000);
                
                if (findBookByCode(bookArray, MAX_QTY, codeAux) != -1) {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    break;
                }
                
                authorIdAux = getValidInt("Ingrese el ID del autor del libro: ", "El ID del autor debe ser numerico\n", 1, 500);
                stockAux = getValidInt("Ingrese la cantidad de libros: ", "La cantidad debe ser numerica\n", 1, 10000);
                getValidString("Ingrese el titulo: ", "El titulo debe estar compuesto solo por letras\n", titleAux);
                setBook(bookArray, freePlaceIndex, codeAux, titleAux, authorIdAux, stockAux);
                
                printf("\nALTA REALIZADA CON EXITO!\n");
                
                break;
            
            case 2: // Baja de libro
                
                printf("\nBAJA DE LIBROS\n\n");
                
                codeAux = getValidInt("Ingrese el codigo del libro a dar de baja: ", "El codigo del libro debe ser numerico\n", 1, 15000);
                foundIndex = findBookByCode(bookArray, MAX_QTY, codeAux);
                
                if (foundIndex == -1) {
                    printf("\n\nNO SE ENCONTRO ESE CODIGO\n");
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
                        printf("\nSE HA DADO DE BAJA AL LIBRO DADO DE BAJA\n\n");
                        break;
                    }
                    else {
                        printf("\nNO SE HA REALIZADO LA BAJA DEL LIBRO\n\n");
                        break;
                    }
                }
                
            case 3: // Modificacion de libro
                
                codeAux = getValidInt("Ingrese el codigo del libro a modificar: ", "El codigo del libro debe ser numerico\n", 1, 15000);
                foundIndex = findBookByCode(bookArray, MAX_QTY, codeAux);
                
                if (foundIndex == -1) {
                    printf("\n\nNO SE ENCONTRO ESE CODIGO\n");
                    break;
                }
                
                authorIdAux = getValidInt("Ingrese el ID del autor del libro: ", "El ID del autor debe ser numerico\n", 1, 500);
                stockAux = getValidInt("Ingrese la cantidad de libros: ", "La cantidad debe ser numerica\n", 1, 10000);
                getValidString("Ingrese el titulo: ", "El titulo debe estar compuesto solo por letras\n", titleAux);
                setBook(bookArray, foundIndex, codeAux, titleAux, authorIdAux, stockAux);
                break;
                
            case 4: //Listar libros
                
                showArray(bookArray, MAX_QTY);
                break;
                
            case 5: // Ordenar lista de libros
                
                orderArrayByTitle(bookArray, MAX_QTY);
                break;
                
            case 6:
                option = 6;
                break;
                
        }//switch (option)
        
    }//while (option != 6)
    
    
    return 0;
}//int main(void)
