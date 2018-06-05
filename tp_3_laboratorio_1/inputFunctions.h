//
//  inputFunctions.h
//  tp_3_laboratorio_1
//
//  Created by Gaston Pesoa on 27/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __tp_3_laboratorio_1__inputFunctions__
#define __tp_3_laboratorio_1__inputFunctions__

#include <stdio.h>

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void);

/** \brief
 * Funcion para limpiar la pantalla de la consola
 * \param void Sin parametros
 * \return -
 *
 */
void clearScreen(void);



/** \brief
 * Funcion para mostrar las opciones del menu principal en consola y pedir el ingreso de la seleccion al usuario.
 * \return option Retorna el valor elegido por el usuario.
 *
 */
int optionMainMenu(void);

/** \brief
 * Funcion para mostrar las opciones del menu modificar en consola y pedir el ingreso de la seleccion al usuario.
 * \return option Retorna el valor elegido por el usuario.
 *
 */
int optionModifyMenu(void);



/**
 * \brief Solicita un numero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 *
 */
int getInt(char mensaje[]);



/**
 * \brief Verifica si el valor recibido es numerico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 *
 */
int esNumerico(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);

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
 *
 */
void getStringSpace(char mensaje[], char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Solicita un titulo al usuario y valida que sean como maximo 20 caracteres
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
void getValidStringTitle(char mensaje[],char input[]);

/**
 * \brief Solicita un texto numerico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo numeros
 */
int getStringNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \return El numero ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

/**
 * \brief Solicita una descripcion para la pelicula, valida que sean solo letras 
 * \y como maximo 50 caracteres
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar· el texto ingresado
 * \return -
 *
 */
void getValidStringDescription(char requestMessage[],char errorMessage[], char input[]);

/**
 * \brief Solicita un genero para la pelicula, valida que sean solo letras
 * \y como maximo 20 caracteres
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar· el texto ingresado
 * \return -
 *
 */
void getValidStringGenero(char requestMessage[],char errorMessage[], char input[]);

/**
 * \brief Solicita un link para la pelicula y valida que sean como maximo 50 caracteres
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar· el texto ingresado
 * \return -
 *
 */
void getValidStringLink(char mensaje[], char input[]);

#endif /* defined(__tp_3_laboratorio_1__inputFunctions__) */
