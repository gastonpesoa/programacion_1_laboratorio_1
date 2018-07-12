#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Reproduction.h"
#include "Input.h"


Reproduction* reproduction_new(void){

    Reproduction* returnAux = NULL;
    returnAux = (Reproduction*)malloc(sizeof(Reproduction));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}


int reproduction_setId(Reproduction* pReproduction, int id, int lowLimit){

    int returnAux = -1;

    if(id >= lowLimit){

        pReproduction->idReproduction = id;
        returnAux = 0;
    }

    return returnAux;
}


int reproduction_setIdUser(Reproduction* pReproduction, int idUser, int lowLimit){

    int returnAux = -1;

    if(idUser >= lowLimit){

        pReproduction->idUser = idUser;
        returnAux = 0;
    }

    return returnAux;
}


int reproduction_setIdSong(Reproduction* pReproduction, int idSong, int lowLimit){

    int returnAux = -1;

    if(idSong >= lowLimit){

        pReproduction->idSong = idSong;
        returnAux = 0;
    }

    return returnAux;
}


int reproduction_getId(Reproduction* pReproduction){

    return pReproduction->idReproduction;
}


int reproduction_getIdUser(Reproduction* pReproduction){

    return pReproduction->idUser;
}


int reproduction_getIdSong(Reproduction* pReproduction){

    return pReproduction->idSong;
}


void reproduction_print(Reproduction* pReproduction){

    printf("| Id: %4d | Id usuario: %6d | Id tema: %6d |\r\n"\
        ,pReproduction->idReproduction,pReproduction->idUser,pReproduction->idSong);
}


int reproduction_printArrayList(ArrayList* reproductionsList){

    int returnAux = -1;
    int i;
    int cont = 1;

    if(!reproductionsList->isEmpty(reproductionsList)){
        for(i=0; i<reproductionsList->len(reproductionsList); i++){

            if(cont %250 == 0) {
               pause("\r\nPresione ENTER para continuar\r\n");
            }
            cont++;

            printf("%4d) ",i);
            reproduction_print(reproductionsList->get(reproductionsList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}


Reproduction *reproduction_requestValidId(ArrayList* reproductionsList){

    Reproduction *returnAux = NULL;
    int idAux;
    int indexItem;
    char confirmaIngreso = 'n';
    Reproduction *reproductionAux = reproduction_new();

    idAux = getValidInt("\r\nIngrese el Id del objeto a dar de baja logica: ","\r\nEl Id debe ser numerico\r\n",1,1000);
    indexItem = idAux - 1;

    reproductionAux = reproductionsList->get(reproductionsList,indexItem);
    while(reproductionAux == NULL){

        printf("\r\nNo hay ningun objeto registrado con el Id ingresado\r\n");
        confirmaIngreso = confirm("\r\nPresione 's' para volver a ingresar el Id o 'n' para salir: [s|n] ");

        if(confirmaIngreso == 's'){
            idAux = getValidInt("\r\nReingrese el Id del objeto a modificar: ","\r\nEl Id debe ser numerico\r\n",1,1000);
            indexItem = idAux - 1;
            reproductionAux = reproductionsList->get(reproductionsList,indexItem);
        }
        else {
            return returnAux;
        }
    }

    return reproductionAux;
}


