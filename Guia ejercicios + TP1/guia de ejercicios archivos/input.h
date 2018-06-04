//
//  input.h
//  guia de ejercicios archivos
//
//  Created by Gaston Pesoa on 03/06/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __guia_de_ejercicios_archivos__input__
#define __guia_de_ejercicios_archivos__input__

#include <stdio.h>

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 */
void cleanStdin(void);

/** \brief Funcion para limpiar la pantalla de la consola
 * \param void Sin parametros
 * \return -
 */
void clearScreen(void);


/**
 * \brief Solicita un numero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 */
int getInt(char mensaje[]);

/**
 * \brief Solicita un numero flotante al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 */
float getFloat(char mensaje[]);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 */
char getChar(char mensaje[]);

/**
 * \brief Verifica si el valor recibido es numerico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 */
int esNumerico(char str[]);

/**
 * \brief Verifica si el valor recibido es numerico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 */
int esNumericoFlotante(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 */
int esSoloLetras(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras y numeros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y numeros, y 0 si no lo es
 */
int esAlfaNumerico(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo numeros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 */
int esTelefono(char str[]);


/**
* \brief Solicita un texto al usuario y lo devuelve
* \param mensaje Es el mensaje a ser mostrado
* \param input Array donde se cargara el texto ingresado
* \return void
*/
void getString(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve (acpeta espacios)
 * \param mensaje es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return void
 */
void getStringSpace(char mensaje[], char input[]);

/**
 * \brief Solicita un texto numerico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo numeros
 */
int getStringNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un texto numerico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar· el texto ingresado
 * \return 1 si el texto contiene solo n˙meros
 */
int getStringNumerosFlotantes(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve (acepta letras y numeros)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras y numeros
 */
int getStringAlfanumerico(char mensaje[],char input[]);


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param hiLimit Es el limite superior aceptado
 * \return El numero ingresado por el usuario
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \return El numero ingresado por el usuario
 */
int getValidFloat(char requestMessage[],char errorMessage[],float lowLimit, float hiLimit);

/**
 * \brief Solicita un string y valida que sean solo letras
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargara el texto ingresado
 * \return -
 */
void getValidString(char requestMessage[],char errorMessage[], char input[]);

/**
 * \brief Solicita un string, valida que sea alfanumerico
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargara el texto ingresado
 * \return -
 */
void getValidStringAlfanumerico(char requestMessage[],char errorMessage[], char input[]);

/**
 * \brief Convierte string a formato capitalizado
 * \param input Array donde se cargara el texto ingresado
 * \return -
 */
void capitalize(char input[]);

/**
 * \brief Convierte la primer palabra del string a formato capitalizado
 * \param input Array donde se cargara el texto ingresado
 * \return -
 */
void capitalizeFirstWord(char input[]);

/**
 * \brief Valida la longitud del string ingresado
 * \param input Es el string a ser validado
 * \param lowLimit Es el limite inferior aceptado
 * \param hiLimit Es el limite superior aceptado
 * \return 0 si no cumple la condicion, 1 si cumple
 */
int validateStrLenght(char input[],int lowLimit,int hiLimit);

#endif /* defined(__guia_de_ejercicios_archivos__input__) */
