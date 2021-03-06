
#include <stdio.h>


/** \brief
 * Funcion para mostrar las opciones del menu principal en consola y pedir el ingreso de la seleccion al usuario.
 * \return option Retorna el valor elegido por el usuario.
 */
int optionMainMenu(void);


/** \brief
 * Funcion para mostrar las opciones del menu modificar en consola y pedir el ingreso de la seleccion al usuario.
 * \return option Retorna el valor elegido por el usuario.
 */
int optionModifyMenu(void);

/** \brief
 * Soliita el ingreso de enter al ususario.
 * \param pauseMessage Es el mensaje a ser mostrado
 * \return -
 */
void pause(char *pauseMessage);


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


/** \brief Funcion que solicita un caracter 's' o 'n', valida que sea ingresado correctamente y devuelve el resultado
 * \param char confirmMessage[] el mensaje a ser mostrado
 * \return caracter 's' o 'n'
 */
char confirm(char confirmMessage[]);


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
 * \brief Verifica si el valor recibido contiene cualquier caracter, un '@' y por lo menos un punto
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene cualquier caracter, un '@' y por lo menos un punto.
 */
int esMail(char str[]);


/**
 * \brief Verifica si el valor recibido contiene un punto
 * \param str Array con la cadena a ser analizada
 * \return 1 un punto.
 */
int esArchivo(char str[]);


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
 * \brief Solicita un texto al usuario y lo devuelve (acepta letras, numeros y '@')
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras, numeros y '@'
 */
int getStringMail(char mensaje[],char input[]);


/**
 * \brief Solicita un texto al usuario y lo devuelve (No acepta \ / : * ? " < > |)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto no contiene \ / : * ? " < > | y contiene un punto
 */
int getStringArchivo(char mensaje[],char input[]);


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
 * \brief Solicita un string, valida que sea mail
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargara el texto ingresado
 * \return -
 */
void getValidStringMail(char requestMessage[],char errorMessage[], char input[]);


/**
 * \brief Solicita un string, valida que sea archivo
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargara el texto ingresado
 * \return -
 */
void getValidStringArchivo(char requestMessage[],char errorMessage[], char input[]);

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

