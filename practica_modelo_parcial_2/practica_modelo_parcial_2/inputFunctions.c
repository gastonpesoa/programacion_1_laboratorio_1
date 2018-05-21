//
//  inputFunctions.c
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
#include "reportsFunctions.h"
#include "inputFunctions.h"


/** \brief
 * Funcion para mostrar las opciones del menu principal en consola y pedir el ingreso de la seleccion al usuario.
 * \return option Retorna el valor elegido por el usuario.
 *
 */
int optionMenu(void){
    
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
int optionMenuModificar(void){
    
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

/**
 * \brief Solicita un numero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 *
 */
float getFloat(char mensaje[]){
    
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un numero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 *
 */
int getInt(char mensaje[]){
    
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[]){
    
    char auxiliar;
    printf("%s",mensaje);
    cleanStdin();
    scanf("%c",&auxiliar);
    return auxiliar;
}

/**
 * \brief Verifica si el valor recibido es numerico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[]){
    
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0'){
        
        if (str[i] == '.' && cantidadPuntos == 0){
            
            cantidadPuntos++;
            i++;
            continue;
            
        }
        if(str[i] < '0' || str[i] > '9'){
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido es numerico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 *
 */

int esNumerico(char str[]){
    
    int i=0;
    while(str[i] != '\0'){
        
        if(str[i] < '0' || str[i] > '9'){
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]){
    
    int i=0;
    while(str[i] != '\0'){
        
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y numeros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y numeros, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]){
    
    int i=0;
    while(str[i] != '\0'){
        
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9')){
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo numeros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[]){
    
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0'){
        
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9')){
            return 0;
        }
        if(str[i] == '-'){
            contadorGuiones++;
        }
        i++;
    }
    if(contadorGuiones==1){ // debe tener un guion
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]){
    
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve (acpeta espacios)
 * \param mensaje es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return void
 *
 */

void getStringNombre(char mensaje[], char input[]){
    
    fpurge(stdin);
    printf("%s", mensaje);
    scanf("%50[^\n]", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras
 */

int getStringLetras(char mensaje[],char input[]){
    
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras y numeros
 */
int getStringAlfanumerico(char mensaje[],char input[]){
    
    char aux[256];
    getString(mensaje,aux);
    if(esAlfaNumerico(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numerico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo numeros
 */
int getStringNumeros(char mensaje[],char input[]){
    
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numÈrico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar· el texto ingresado
 * \return 1 si el texto contiene solo n˙meros
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve con el primer caracter de cada palabra en mayusculas
 * \y lo demas en minusculas
 * \param mensaje es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras
 *
 */

int getStringLetrasNombre(char mensaje[], char input[]){
    
    char auxiliar[256];
    int i;
    unsigned long auxiliarLenght;
    
    getStringNombre(mensaje, auxiliar);
    if(esSoloLetras(auxiliar)){
        
        auxiliarLenght = strlen(auxiliar);
        for (i = 0; i < auxiliarLenght; i++) {
            auxiliar[i] = tolower(auxiliar[i]);
        }
        auxiliar[0] = toupper(auxiliar[0]);
        for (i = 0; i < auxiliarLenght; i++) {
            if (auxiliar[i] == ' ') {
                auxiliar[i + 1] = toupper(auxiliar[i + 1]);
            }
        }
        strcpy(input, auxiliar);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \return El numero ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit){
    
    char auxStr[256];
    int auxInt;
    while(1){
        
        if (!getStringNumeros(requestMessage,auxStr)){
            printf ("%s\n",errorMessage);
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit){
            printf ("\nEl numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxInt;
    }
}

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \return El numero ingresado por el usuario
 *
 */
int getValidFloat(char requestMessage[],char errorMessage[],float lowLimit, float hiLimit){
    
    char auxStr[256];
    float auxInt;
    
    while(1){
        if (!getStringNumerosFlotantes(requestMessage,auxStr)){
            printf ("%s\n",errorMessage);
            continue;
        }
        auxInt = atof(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit){
            printf ("El numero del debe ser mayor a %f y menor a %f\n",lowLimit,hiLimit);
            continue;
        }
        return auxInt;
    }
}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar· el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[]){
    
    while(1){
        if (!getStringLetras(requestMessage,input)){
            printf ("%s\n",errorMessage);
            continue;
        }
        //cleanStdin();
        break;
    }
}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar· el texto ingresado
 * \return -
 *
 */
void getValidStringAlfanumerico(char requestMessage[],char errorMessage[], char input[]){
    
    while(1){
        if (!getStringAlfanumerico(requestMessage,input)){
            printf ("%s\n",errorMessage);
            continue;
        }
        //cleanStdin();
        break;
    }
}

/**
 * \brief Solicita un string, valida que sean letras y como maximo 50 caracteres
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar· el texto ingresado
 * \return -
 *
 */
void getValidStringNombre(char requestMessage[],char errorMessage[], char input[]){
    
    int nameLenght;
    
    while(1){
        if (!getStringLetrasNombre(requestMessage, input)){
            printf ("%s\n",errorMessage);
            continue;
        }
        
        nameLenght = strlen(input);
        if(nameLenght > 50){
            
            printf ("\nLa descripcion del producto debe tener como maximo 50 caracteres\n");
            continue;
        }
        break;
    }
}

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void){
    //setbuf(stdin,NULL);
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
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

/**
 * \brief Genera un numero aleatorio
 * \param desde Numero aleatorio minimo
 * \param hasta Numero aleatorio maximo
 * \param iniciar Indica si se trata del primer n˙mero solicitado 1 indica que si
 * \return retorna el numero aleatorio generado
 *
 */

char getNumeroAleatorio(int desde , int hasta, int iniciar){
    
    if(iniciar)
        srand(time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}
