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


int feedToFile(FILE *pFile,ArrayList *mensajesList, ArrayList *usersList,char *fileName){

    //Se definen variables auxiliares
    int i, j, mensajesListLenght, usersListLenght, returnAux = -1;
    int mensajeIdAux, followersMensajeAux, userIdAux, userIdInMensajesList, followersUserAux;
    char mensajeCampoAux[9999], nickAux[51];
    Mensaje *mensajeAux;
    Usuario *userAux;

    //Se verifica que las listas ingresadas no sean NULL
    if(mensajesList == NULL || usersList == NULL){
        //En caso de lista NULL se informa y se sale retornando valor de Error
        printf("\r\nError, lista nula\r\n");
        pause("\r\nPresione enter para volver\r\n");
        return returnAux;
    }

    if((pFile = fopen(fileName,"w")) == NULL){
        printf("\nError abriendo el archivo\n");
        pause("\r\nEnter para volver: ");
    }
    
    //Se escribe cabecera del archivo
    cleanStdin();
    fprintf(pFile,"id_mensaje,mensaje,followers_mensaje,id_usuario,nick,followers_usuario\n");

    usersList->sort(usersList,user_compareByFollowers,0);
    mensajesList->sort(mensajesList,mensaje_compareByFollowers,1);
        
    usersListLenght = usersList->len(usersList);
    mensajesListLenght = mensajesList->len(mensajesList);

    for(i = 0; i < usersListLenght; i++){

        userAux = usersList->get(usersList,i);
        userIdAux  = user_getId(userAux);

        for(j = 0; j < mensajesListLenght; j++){

            mensajeAux = mensajesList->get(mensajesList,j);
            userIdInMensajesList = mensaje_getUserId(mensajeAux);

            if(userIdAux == userIdInMensajesList){
                
                mensajeIdAux = mensaje_getMensajeId(mensajeAux);
                strcpy(mensajeCampoAux,mensaje_getMensaje(mensajeAux));
                followersMensajeAux = mensaje_getFollowers(mensajeAux);
                strcpy(nickAux,user_getNick(userAux));
                followersUserAux = user_getFollowers(userAux);

                cleanStdin();
                if((fprintf(pFile,"%d,%s,%d,%d,%s,%d\n",mensajeIdAux,mensajeCampoAux,followersMensajeAux,userIdAux,nickAux,followersUserAux))<0){
                    //En caso de error al escribir los datos se informa y se sale retornando valor de Error
                    printf("\r\nError al intentar escribir la objecta en el archivo\r\n");
                    pause("\r\nEnter para salir: ");
                    return returnAux;
                }
            }
        }
    }
    //Si se recorrio toda la lista y se escribieron todos los datos
    //Se cierra el archivo y se sale retornando valor de Ok
    fclose(pFile);
    returnAux = 0;
    return returnAux;
}

