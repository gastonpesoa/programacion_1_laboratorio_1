#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Product.h"
#include "Input.h"
#include "Parser.h"


int optionMainMenu(void){

    int option = 0;

    char menuPrinsipalMensaje[] =
             "\n\n============================================\
                \n| ADMINISTRACION DE MERCADERIA DE DEPOSITOS|\
                \n============================================\
                \n============================================\
                \n|       *      MENU PRINCIPAL      *       |\
                \n============================================\
                \n| 1 - Cargar depositos                     |\
                \n| 2 - Listar productos de deposito         |\
                \n| 3 - Mover productos a deposito           |\
                \n| 4 - Descontar productos de deposito      |\
                \n| 5 - Agregar productos a deposito         |\
                \n| 6 - Salir                                |\
                \n============================================\
                \n| Ingrese una opcion:                      |\
                \n============================================\n";

    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 6";

    option = getValidInt(menuPrinsipalMensaje, menuPrinsipalMensajeError, 1, 6);

    return option;
}


int optionDepSelect(void){

    int option = 0;

    char menuPrinsipalMensaje[] =
             "\n\n============================================\
                \n|      *      LISTAR DEPOSITOS      *      |\
                \n============================================\
                \n| 1 - Listar deposito uno                  |\
                \n| 2 - Listar deposito dos                  |\
                \n| 3 - Salir                                |\
                \n============================================\
                \n| Ingrese una opcion:                      |\
                \n============================================\n";

    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 3";

    option = getValidInt(menuPrinsipalMensaje, menuPrinsipalMensajeError, 1, 3);

    return option;
}


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


void cleanStdin(void){

    setbuf(stdin,NULL);
}


void clearScreen(void){

    system("@cls||clear");
}


void pause(char *pauseMessage){

    getChar(pauseMessage);
}


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


int getInt(char mensaje[]){

    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


float getFloat(char mensaje[]){

    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


char getChar(char mensaje[]){

    char auxiliar;
    printf("%s",mensaje);
    cleanStdin();
    scanf("%c",&auxiliar);
    return auxiliar;
}


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


void getString(char mensaje[],char input[]){

    cleanStdin();
    printf("%s",mensaje);
    scanf ("%s", input);
}


void getStringSpace(char mensaje[], char input[]){

    cleanStdin();
    printf("%s", mensaje);
    scanf("%[^\n]", input);
}


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


int getStringLetras(char mensaje[],char input[]){

    char aux[256];
    getStringSpace(mensaje,aux);
    if(esSoloLetras(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int getStringAlfanumerico(char mensaje[],char input[]){

    char aux[256];
    getString(mensaje,aux);
    if(esAlfaNumerico(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


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


void getValidString(char requestMessage[],char errorMessage[], char input[]){

    while(1){
        if (!getStringLetras(requestMessage,input)){
            printf ("\n%s\n",errorMessage);
            continue;
        }
        break;
    }
}


void getValidStringAlfanumerico(char requestMessage[],char errorMessage[], char input[]){

    while(1){
        if (!getStringAlfanumerico(requestMessage,input)){
            printf ("\n%s\n",errorMessage);
            continue;
        }
        break;
    }
}

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

void capitalizeFirstWord(char input[]){

    unsigned long inputLenght;
    int i;

    inputLenght = strlen(input);

    for (i = 0; i < inputLenght; i++) {
        input[i] = tolower(input[i]);
    }
    input[0] = toupper(input[0]);
}

int validateStrLenght(char input[],int lowLimit,int hiLimit){

    unsigned long inputLenght;

    inputLenght = strlen(input);
    if(inputLenght < lowLimit || inputLenght > hiLimit){

        printf ("\nEl texto ingresado debe tener como minimo %d y como maximo %d caracteres\n",lowLimit,hiLimit);
        return 0;
    }
    return 1;
}


