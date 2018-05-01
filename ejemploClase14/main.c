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
                showBookAuthorArray(bookArray, MAX_QTY, authorArray, MAX_QTY);
                getChar("\n\nENTER (para continuar)");
                break;
        }//switch (option)
    }//while (option != 4)
    
    return 0;
}//int main(void) 




