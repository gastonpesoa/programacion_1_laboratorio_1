
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"


/** \brief
 * Funcion para mostrar las opciones del menu principal en consola y pedir el ingreso de la seleccion al usuario.
 * \return option Retorna el valor elegido por el usuario.
 *
 */
int optionMainMenu(void){

    int option = 0;

    char menuPrinsipalMensaje[] =
             "\n\n============================================\
                \n| ADMINISTRACION DE PRODUCT DE MERCADERIA  |\
                \n============================================\
                \n============================================\
                \n|       *      MENU PRINCIPAL      *       |\
                \n============================================\
                \n| 1 - Cargar archivo                       |\
                \n| 2 - Imprimir products                    |\
                \n| 3 - Imprimir localidades                 |\
                \n| 4 - Generar archivo de reparto           |\
                \n| 5 - Salir                                |\
                \n============================================\
                \n| Ingrese una opcion:                      |\
                \n============================================\n";

    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 5";

    option = getValidInt(menuPrinsipalMensaje, menuPrinsipalMensajeError, 1, 5);

    return option;
}


/** \brief
 * Funcion para mostrar las opciones de las listas a mostrar en consola y pedir el ingreso de la seleccion al usuario.
 * \return option Retorna el valor elegido por el usuario.
 *
 */
int optionListSelect(void){

    int option = 0;

    char menuPrinsipalMensaje[] =
             "\n\n============================================\
                \n|           *      LISTAR      *           |\
                \n============================================\
                \n| 1 - Lista uno                            |\
                \n| 2 - Listar dos                           |\
                \n| 3 - Volver                               |\
                \n============================================\
                \n| Ingrese una opcion:                      |\
                \n============================================\n";

    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 3";

    option = getValidInt(menuPrinsipalMensaje, menuPrinsipalMensajeError, 1, 3);

    return option;
}


/** \brief
 * Funcion para mostrar las opciones del menu modificar en consola y pedir el ingreso de la seleccion al usuario.
 * \return option Retorna el valor elegido por el usuario.
 *
 */
int optionModifyMenu(void){

    int option = 0;

    char menuModificarProductMensaje[] =
             "\n\n============================================\
                \n|       *      MENU MODIFICAR      *       |\
                \n============================================\
                \n| 1 - Modificar descripcion                |\
                \n| 2 - Modificar importe                    |\
                \n| 3 - Modificar cantidad                   |\
                \n| 4 - Regresar                             |\
                \n============================================\
                \n| Ingrese una opcion:                      |\
                \n============================================\n";

    char menuModificarProductMensajeError[] = "\nSe debe elegir una opcion del 1 al 4";

    option = getValidInt(menuModificarProductMensaje, menuModificarProductMensajeError, 1, 4);
    return option;
}



/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 */
void cleanStdin(void){

    setbuf(stdin,NULL);
}


/** \brief Funcion para limpiar la pantalla de la consola
 * \param void Sin parametros
 * \return -
 */
void clearScreen(void){

    system("@cls||clear");
}


/** \brief Funcion para pausar la ejecucion del programa hasta que el usuario ingresa Enter
 * \param pauseMessage Es el mensaje a ser mostrado
 * \return -
 */
void pause(char *pauseMessage){

    cleanStdin();
    getChar(pauseMessage);
}


/** \brief Funcion que solicita un caracter 's' o 'n', valida que sea ingresado correctamente y devuelve el resultado
 * \param char confirmMessage[] el mensaje a ser mostrado
 * \return caracter 's' o 'n'
 */
char confirm(char confirmMessage[]){

    char confirmar = 'n';

    do{
        printf("%s",confirmMessage);
        cleanStdin();
        scanf("%c",&confirmar);
        confirmar = tolower(confirmar);
    } while(confirmar != 's' && confirmar != 'n');
    return confirmar;
}


/**
 * \brief Solicita un numero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 */
int getInt(char mensaje[]){

    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un numero flotante al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 */
float getFloat(char mensaje[]){

    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 */
char getChar(char mensaje[]){

    char auxiliar;
    printf("%s",mensaje);
    cleanStdin();
    scanf("%c",&auxiliar);
    return auxiliar;
}


/**
 * \brief Verifica si el valor recibido es numerico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
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
 * \brief Verifica si el valor recibido es numerico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
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
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
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
 * \brief Verifica si el valor recibido contiene un punto
 * \param str Array con la cadena a ser analizada
 * \return 1 un punto.
 */
int esArchivo(char str[]){

    int i = 0;
    int contadorDePuntos = 0; // debe tener un punto

    while(str[i] != '\0'){

        if((str[i] == '\\') || (str[i] == '/') || (str[i] == ':') || (str[i] == '*') ||\
           (str[i] == '?') || (str[i] == '\"') || (str[i] == '<') || (str[i] == '>') ||\
           (str[i] == '|')){
            return 0;
        }
        if(str[i] == '.'){
            contadorDePuntos++;
        }
        i++;
    }
    if (contadorDePuntos == 1){
        return 1;
    }
    return 0;
}


/**
 * \brief Verifica si el valor recibido contiene cualquier caracter, un '@' y por lo menos un punto
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene cualquier caracter, un '@' y por lo menos un punto.
 */
int esMail(char str[]){

    int i=0;
    int contadorArroba=0;
    int contadorPuntos=0;
    while(str[i] != '\0'){

        if(str[i] == '@'){
            contadorArroba++;
        }
        if(str[i] == '.'){
            contadorPuntos++;
        }
        i++;
    }
    if(contadorArroba==1 && contadorPuntos!=0){ // debe tener un arroba y por lo menos un punto
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

    cleanStdin();
    printf("%s",mensaje);
    scanf ("%s", input);
}


/**
 * \brief Solicita un texto al usuario y lo devuelve (acpeta espacios)
 * \param mensaje es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return void
 */
void getStringSpace(char mensaje[], char input[]){

    cleanStdin();
    printf("%s", mensaje);
    scanf("%[^\n]", input);
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
 * \brief Solicita un texto numerico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar· el texto ingresado
 * \return 1 si el texto contiene solo n˙meros
 */
int getStringNumerosFlotantes(char mensaje[],char input[]){

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
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]){

    char aux[256];
    getStringSpace(mensaje,aux);
    if(esSoloLetras(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve (acepta letras y numeros)
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
 * \brief Solicita un texto al usuario y lo devuelve (No acepta \ / : * ? " < > |)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto no contiene \ / : * ? " < > | y contiene un punto
 */
int getStringArchivo(char mensaje[],char input[]){

    char aux[256];
    getString(mensaje,aux);
    if(esArchivo(aux) && validateStrLenght(aux,1,256)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve (acepta letras, numeros y '@')
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras, numeros y '@'
 */
int getStringMail(char mensaje[],char input[]){

    char aux[256];
    getString(mensaje,aux);
    if(esMail(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param hiLimit Es el limite superior aceptado
 * \return El numero ingresado por el usuario
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit){

    char auxStr[256];
    int auxInt;
    while(1){

        if (!getStringNumeros(requestMessage,auxStr)){
            printf ("\n%s\n",errorMessage);
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit){
            printf ("\nEl numero ingresado debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
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
 */
int getValidFloat(char requestMessage[],char errorMessage[],float lowLimit, float hiLimit){

    char auxStr[256];
    float auxInt;

    while(1){
        if (!getStringNumerosFlotantes(requestMessage,auxStr)){
            printf ("\n%s\n",errorMessage);
            continue;
        }
        auxInt = atof(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit){
            printf ("\nEl numero debe ser mayor a %f y menor a %f\n",lowLimit,hiLimit);
            continue;
        }
        return auxInt;
    }
}


/**
 * \brief Solicita un string y valida que sean solo letras
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargara el texto ingresado
 * \return -
 */
void getValidString(char requestMessage[],char errorMessage[], char input[]){

    while(1){
        if (!getStringLetras(requestMessage,input)){
            printf ("\n%s\n",errorMessage);
            continue;
        }
        break;
    }
}


/**
 * \brief Solicita un string, valida que sea alfanumerico
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargara el texto ingresado
 * \return -
 */
void getValidStringAlfanumerico(char requestMessage[],char errorMessage[], char input[]){

    while(1){
        if (!getStringAlfanumerico(requestMessage,input)){
            printf ("\n%s\n",errorMessage);
            continue;
        }
        break;
    }
}


/**
 * \brief Solicita un string, valida que sea archivo
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargara el texto ingresado
 * \return -
 */
void getValidStringArchivo(char requestMessage[],char errorMessage[], char input[]){

    //char str[256] = "\"";
    while(1){
        if (!getStringArchivo(requestMessage,input)){
            printf ("\n%s\n",errorMessage);
            continue;
        }
        //strcat(input,"\"");
        //strcpy(input,strcat(str,input));
        break;
    }
}


/**
 * \brief Solicita un string, valida que sea mail
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargara el texto ingresado
 * \return -
 */
void getValidStringMail(char requestMessage[],char errorMessage[], char input[]){

    while(1){
        if (!getStringMail(requestMessage,input)){
            printf ("\n%s\n",errorMessage);
            continue;
        }
        break;
    }
}


/**
 * \brief Convierte string a formato capitalizado
 * \param input Array donde se cargara el texto ingresado
 * \return -
 */
void capitalize(char input[]){

    unsigned long inputLenght;
    int i;

    inputLenght = strlen(input);

    for (i = 0; i < inputLenght; i++) {
        input[i] = tolower(input[i]);
    }
    input[0] = toupper(input[0]);
    for (i = 0; i < inputLenght; i++) {
        if (input[i] == ' ') {
            input[i + 1] = toupper(input[i + 1]);
        }
    }
}


/**
 * \brief Convierte la primer palabra del string a formato capitalizado
 * \param input Array donde se cargara el texto ingresado
 * \return -
 */
void capitalizeFirstWord(char input[]){

    unsigned long inputLenght;
    int i;

    inputLenght = strlen(input);

    for (i = 0; i < inputLenght; i++) {
        input[i] = tolower(input[i]);
    }
    input[0] = toupper(input[0]);
}


/**
 * \brief Valida la longitud del string ingresado
 * \param input Es el string a ser validado
 * \param lowLimit Es el limite inferior aceptado
 * \param hiLimit Es el limite superior aceptado
 * \return 0 si no cumple la condicion, 1 si cumple
 */
int validateStrLenght(char input[],int lowLimit,int hiLimit){

    unsigned long inputLenght;

    inputLenght = strlen(input);
    if(inputLenght < lowLimit || inputLenght > hiLimit){

        printf ("\nEl texto ingresado debe tener como minimo %d y como maximo %d caracteres\n",lowLimit,hiLimit);
        return 0;
    }
    return 1;
}




