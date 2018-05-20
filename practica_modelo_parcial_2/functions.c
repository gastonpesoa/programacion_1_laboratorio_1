//
//  functions.c
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
#include "functions.h"
#include "reportsFunctions.h"
#include "inputFunctions.h"


/** \brief
 * Funcion para mostrar las opciones del menu principal en consola y pedir el ingreso de la seleccion al usuario.
 * \return option Retorna el valor elegido por el usuario.
 *
 */
int optionMenu(){
    
    int option = 0;
    
    char menuPrinsipalMensaje[] =
    "\n\n1 - ALTA DE PRODUCTO\
    \n2 - MODIFICAR PRODUCTO\
    \n3 - BAJA DE PRODUCTO\
    \n4 - INFORMES\
    \n5 - LISTAS\
    \n6 - SALIR\
    \n\nIngrese una opcion: ";
    
    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 6";
    
    option = getValidInt(menuPrinsipalMensaje, menuPrinsipalMensajeError, 1, 6);
    return option;
}

/** \brief
 * Funcion para mostrar las opciones del menu modificar en consola y pedir el ingreso de la seleccion al usuario.
 * \return option Retorna el valor elegido por el usuario.
 *
 */
int optionMenuModificar(){
    
    int option = 0;
    
    char menuModificarProductMensaje[] =
    "\n\n1 - MODIFICAR DESCRIPCION\
    \n2 - MODIFICAR PRECIO\
    \n3 - MODIFICAR STOCK\
    \n4 - REGRESAR\
    \n\nIngrese una opcion: ";
    
    char menuModificarProductMensajeError[] = "\nSe debe elegir una opcion del 1 al 4";
    
    option = getValidInt(menuModificarProductMensaje, menuModificarProductMensajeError, 1, 4);
    return option;
}

/** \brief Carga datos de prueba tanto en el array de productos como en el de proveedores
 * \param productsArray El array de productos
 * \param productsArrayLenght Longitud del array
 * \param provsArray provsArray El array de proveedores
 * \param provsArrayLenght Longitud del array
 * \return void
 */
void testProductsProvs(EProduct productsArray[],int productsArrayLenght,EProv provsArray[],int provsArrayLenght){
    
    // Alta de datos para testing
    setProduct(productsArray, 0, "Gaseosa Cola", 1, 1, 50.00, 25);
    setProduct(productsArray, 1, "Chupetines Luck", 2, 2, 12.00, 300);
    setProduct(productsArray, 2, "Alfajores Jorge", 3, 3, 23.00, 0);
    setProduct(productsArray, 3, "Caramelos Lipo", 4, 4, 8.00, 50);
    setProduct(productsArray, 4, "Cerveza Aguila", 5, 1, 25.00, 2500);
    
    setProv(provsArray, 0, 1, "Proveedor1");
    setProv(provsArray, 1, 2, "Proveedor2");
    setProv(provsArray, 2, 3, "Proveedor3");
    setProv(provsArray, 3, 4, "Proveedor4");
};

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

/** \brief
 * Funcion para limpiar la pantalla de la consola
 * \param void Sin parametros
 * \return -
 *
 */
void clearScreen(void){
    
    system("@cls||clear");
}


