#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Input.h"
#include "Parser.h"
#include "Functions.h"
#include "Mensaje.h"
#include "Mensaje.h"


#define PRODUCT_INACTIVE  0
#define PRODUCT_ACTIVE  1


Mensaje* mensaje_new(void){

    Mensaje* returnAux = NULL;
    returnAux = (Mensaje*)malloc(sizeof(Mensaje));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}


int mensaje_setMensajeId(Mensaje* pMensaje, int mensajeId, int lowLimit){

    int returnAux = -1;

    if(mensajeId >= lowLimit){

        pMensaje->mensajeId = mensajeId;
        returnAux = 0;
    }

    return returnAux;
}


int mensaje_setUserId(Mensaje* pMensaje, int userId, int lowLimit){

    int returnAux = -1;

    if(userId >= lowLimit){

        pMensaje->userId = userId;
        returnAux = 0;
    }

    return returnAux;
}



int mensaje_setMensaje(Mensaje* pMensaje, char* mensaje, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(mensaje, lowLimit, hiLimit)) {

        strcpy(pMensaje->mensaje,mensaje);
        returnAux = 0;
    }

    return returnAux;
}


int mensaje_setFollowers(Mensaje* pMensaje, int followers, int lowLimit){

    int returnAux = -1;

    if(followers >= lowLimit){

        pMensaje->followers = followers;
        returnAux = 0;
    }

    return returnAux;
}


int mensaje_getMensajeId(Mensaje* pMensaje){

    return pMensaje->mensajeId;
}


int mensaje_getUserId(Mensaje* pMensaje){

    return pMensaje->mensajeId;
}


char* mensaje_getMensaje(Mensaje* pMensaje){

    return pMensaje->mensaje;
}


int mensaje_getFollowers(Mensaje* pMensaje){

    return pMensaje->followers;
}


void mensaje_print(Mensaje* pMensaje){

    printf("\n| Id Mensaje: %4d | Id Usuario: %4d | Folowers: %8d | Mensaje: %1000s |\r\n",\
        pMensaje->mensajeId,pMensaje->userId,pMensaje->followers,pMensaje->mensaje);
}



int mensaje_printArrayList(ArrayList* mensajesList){

    int returnAux = -1;
    int i;
    int cont=1;

    if(!mensajesList->isEmpty(mensajesList)){
        for(i=0; i<mensajesList->len(mensajesList); i++){

            if(cont %250 == 0){

               system("pause");
            }
            cont++;

            //printf("%4d) ",i);
            mensaje_print(mensajesList->get(mensajesList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}


int mensaje_compareByFollowers(void* pMensajeA,void* pMensajeB){

    if(((Mensaje*)pMensajeA)->followers > ((Mensaje*)pMensajeB)->followers){

        return 1;
    }
    if(((Mensaje*)pMensajeA)->followers < ((Mensaje*)pMensajeB)->followers){

        return -1;
    }
    return 0;
}

