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
#include <time.h>
#include "types.h"
#include "adminFunctions.h"
#include "funcionesMenus.h"
#include "controllerFunctions.h"
#include "bookFunctions.h"
#include "authorsFunctions.h"
#include "booksAuthorsFunctions.h"
#include "funcionesInput.h"



int main(void) {
    
    //array de libros
    book bookArray[BOOKS_MAX_QTY];
    setBookStatus(bookArray, BOOKS_MAX_QTY, 0);
    
    //array de autores
    author authorArray[AUTHORS_MAX_QTY];
    setAuthorStatus(authorArray, AUTHORS_MAX_QTY, 0);
    
    //HardCode con datos para test
    controller_test(bookArray, BOOKS_MAX_QTY, authorArray, AUTHORS_MAX_QTY);
    
    //Menu de opciones
    int option = 0;
    
    while (option != 4) {
        
        printf("\n-------------- MENU PRINCIPAL --------------");
        option = optionMenu("\n1 - ABM LIBROS \n2 - ABM AUTORES \n3 - LISTAR LIBROS\n4 - SALIR\n\n\n", "\nSe debe elegir una opcion del 1 al 4", 1, 4);
        
        switch (option){
                
            case 1: // ABM LIBROS
                adminBooks(bookArray);
                break;
                
            case 2: // ABM AUTORES
                adminAuthors(authorArray);
                break;
                
            case 3: // LISTAR
                clearScreen();
                showBookAuthorArray(bookArray, BOOKS_MAX_QTY, authorArray, AUTHORS_MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;
        }//switch (option)
    }//while (option != 4)
    
    return 0;
}//int main(void) 




