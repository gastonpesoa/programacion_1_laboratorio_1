#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Input.h"
#include "Parser.h"
#include "Functions.h"
#include "Usuario.h"
#include "Mensaje.h"


int parserUsuariosListFile(FILE *pFile , ArrayList *usersList, char *fileName){

    //Se definen variables auxiliares
    int returnAux = -1;
    int readItem;
    char idStr[256],nickAux[256],followersStr[256];
    int idAux, followersAux;
    int flag = 0;

    //Se verifica que la lista ingresada no sea NULL
    if(usersList == NULL){
        //En caso de lista NULL se informa y se sale retornando valor de Error
        printf("\r\nError, lista nula\r\n");
        pause("\r\nPresione enter para volver\r\n");
        return returnAux;
    }
    //Se abre el archivo, pasado como parametro, para lectura de texto
    //y se asigna puntero al archivo devuelto, al puntero pFile pasado como paramentro
    pFile = fopen(fileName,"r");
    if (pFile==NULL) {
        //Si fopen devuelve NULL se informa y se sale de la funcion retornando valor de error
        printf("\r\nNo se pudo abrir el archivo\n");
        pause("\r\nEnter para volver: ");
        return returnAux;
    }
    //Mientras no se llegue al final del archivo lo sigo recorriendo
    while(!feof(pFile)){
        //La primer linea que se lea del archivo es la cabecera por lo que no la agrego a la lista
        if(flag == 0){
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idStr,nickAux,followersStr);
            flag = 1;
            continue;
        }
        //Se realiza la lectura de los datos
        cleanStdin();
        readItem = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idStr,nickAux,followersStr);
        if(readItem == 3){
            //Si se leyeron todos datos para los campos necesarios del archivo
            //se realiza la conversion de cadena a entero de los datos necesarios
            idAux = atoi(idStr);
            followersAux = atoi(followersStr);
            //Se crea una nueva struct
            Usuario* user = user_new();
            //Se setean los datos a la struct
            user_setId(user,idAux,0);
            user_setNick(user,nickAux,1,256);
            user_setFollowers(user,followersAux,0);
            //Se agrega la struct a la lista
            if(usersList->add(usersList,user) == -1){
                //En caso de error se informa y se sale retornando valor de error
                printf("\r\nNo se pudo ingresar el nuevo usero, verifique espacio en memoria\r\n");
                return returnAux;
            }
            //user_print(user);
            //Si se realizo el parser correctamente se asigna valor de retorno Ok
            returnAux = 0;
        }
        else {
            //Si no se leyeron los datos necesarios se informa error y se sale retornando valor de error
            printf("\r\nNo se leyeron los datos correctamente\n");
            pause("\r\nEnter para salir: ");
            return returnAux;;
        }//if(readItem==4)
    }//while(!feof(pFile))
    //Si se recorrio todo el archivo y se cargaron todos los datos
    //Se cierra el archivo y se retorna valor de Ok
    fclose(pFile);
    return returnAux;
}


int parserMensajesListFile(FILE *pFile , ArrayList *mensajesList, char *fileName){

    //Se definen variables auxiliares
    int returnAux = -1;
    int readItem;
    char mensajeIdStr[256],userIdStr[256],followersStr[256],mensajeAux[9999];
    int mensajeIdAux, userIdAux, followersAux;
    int flag = 0;

    //Se verifica que la lista ingresada no sea NULL
    if(mensajesList == NULL){
        //En caso de lista NULL se informa y se sale retornando valor de Error
        printf("\r\nError, lista nula\r\n");
        pause("\r\nPresione enter para volver\r\n");
        return returnAux;
    }
    //Se abre el archivo, pasado como parametro, para lectura de texto
    //y se asigna puntero al archivo devuelto, al puntero pFile pasado como paramentro
    pFile = fopen(fileName,"r");
    if (pFile==NULL) {
        //Si fopen devuelve NULL se informa y se sale de la funcion retornando valor de error
        printf("\r\nNo se pudo abrir el archivo\n");
        pause("\r\nEnter para volver: ");
        return returnAux;
    }
    //Mientras no se llegue al final del archivo lo sigo recorriendo
    while(!feof(pFile)){
        //La primer linea que se lea del archivo es la cabecera por lo que no la agrego a la lista
        if(flag == 0){
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",mensajeIdStr,userIdStr,followersStr,mensajeAux);
            flag = 1;
            continue;
        }
        //Se realiza la lectura de los datos
        cleanStdin();
        readItem = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",mensajeIdStr,userIdStr,followersStr,mensajeAux);
        if(readItem == 4){
            //Si se leyeron todos datos para los campos necesarios del archivo
            //se realiza la conversion de cadena a entero de los datos necesarios
            mensajeIdAux = atoi(mensajeIdStr);
            userIdAux = atoi(userIdStr);
            followersAux = atoi(followersStr);
            //Se crea una nueva struct
            Mensaje* mensaje = mensaje_new();
            //Se setean los datos a la struct
            mensaje_setMensajeId(mensaje,mensajeIdAux,0);
            mensaje_setUserId(mensaje,userIdAux,0);
            mensaje_setFollowers(mensaje,followersAux,0);
            mensaje_setMensaje(mensaje,mensajeAux,1,9999);
            //Se agrega la struct a la lista
            if(mensajesList->add(mensajesList,mensaje) == -1){
                //En caso de error se informa y se sale retornando valor de error
                printf("\r\nNo se pudo ingresar el nuevo usero, verifique espacio en memoria\r\n");
                return returnAux;
            }
            //user_print(mensaje);
            //Si se realizo el parser correctamente se asigna valor de retorno Ok
            returnAux = 0;
        }
        else {
            //Si no se leyeron los datos necesarios se informa error y se sale retornando valor de error
            printf("\r\nNo se leyeron los datos correctamente\n");
            pause("\r\nEnter para salir: ");
            return returnAux;;
        }//if(readItem==4)
    }//while(!feof(pFile))
    //Si se recorrio todo el archivo y se cargaron todos los datos
    //Se cierra el archivo y se retorna valor de Ok
    fclose(pFile);
    return returnAux;
}

