//
//  adminFunctions.c
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


//Menu opciones ABM, listar y ordenar libros
void adminBooks(book bookArray[]){
    
    int option = 0;
    
    //Menu opciones
    while (option != 6) {
        
        clearScreen();
        printf("\n------------  ABM LIBROS ------------");
        option = optionMenu("\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - REGRESAR\n\n\n", "\nSe debe elegir una opcion del 1 al 6", 1, 6);
        
        switch (option){
                
            case 1: // Alta de libro
                controller_altaBook(bookArray, MAX_QTY);
                break;
                
            case 2: // Baja de libro
                controller_bajaBook(bookArray, MAX_QTY);
                break;
                
            case 3: // Modificacion de libro
                controller_modificarBook(bookArray, MAX_QTY);
                break;
                
            case 4: //Listar libros
                clearScreen();
                showBookArray(bookArray, MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;
                
            case 5: // Ordenar lista de libros
                orderBookArrayByTitle(bookArray, MAX_QTY);
                getChar("\n\nOrdenados. ENTER (para continuar)");
                break;
        }//switch (option)
    }//while (option != 6)
}//void adminBooks(book bookArray[])


//Menu opciones ABM, listar y ordenar autores
void adminAuthors(author authorArray[]){
    
    //Menu de opciones
    int option = 0;
    
    while (option != 4) {
        
        clearScreen();
        printf("\n------------  ABM AUTORES ------------");
        option = optionMenu("\n1 - ALTA \n2 - BAJA \n3 - LISTAR\n4 - REGRESAR\n\n\n", "\nSe debe elegir una opcion del 1 al 4", 1, 4);
        
        switch(option){
                
            case 1:// Alta de autor
                controller_altaAuthor(authorArray, MAX_QTY);
                break;
                
            case 2://Baja de autor
                controller_bajaAuthor(authorArray, MAX_QTY);
                break;
                
            case 3:// Listar
                clearScreen();
                showAuthorArray(authorArray, MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;
        }
    }
}
