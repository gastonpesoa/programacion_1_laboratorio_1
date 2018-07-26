#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Artist.h"
#include "Input.h"



Artist* artist_new(void){

    Artist* returnAux = NULL;
    returnAux = (Artist*)malloc(sizeof(Artist));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}


int artist_setId(Artist* pArtist, int id, int lowLimit){

    int returnAux = -1;

    if(id >= lowLimit){

        pArtist->id = id;
        returnAux = 0;
    }

    return returnAux;
}


int artist_setName(Artist* pArtist, char* name, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(name, lowLimit, hiLimit)) {

        strcpy(pArtist->name,name);
        returnAux = 0;
    }

    return returnAux;
}


int artist_setQtySongs(Artist* pArtist, int qty, int lowLimit){

    int returnAux = -1;

    if(qty >= lowLimit){

        pArtist->qtySongs = qty;
        returnAux = 0;
    }

    return returnAux;
}


int artist_getId(Artist* pArtist){

    return pArtist->id;
}


char* artist_getName(Artist* pArtist){

    return pArtist->name;
}


int artist_getQtySongs(Artist* pArtist){

    return pArtist->qtySongs;
}


void artist_print(Artist* pArtist){

    printf("| Id: %4d | Nombre: %45s | Cantidad de canciones: %4d |\r\n"\
        ,pArtist->id,pArtist->name,pArtist->qtySongs);
}


int artist_printArrayList(ArrayList* artistsList){

    int returnAux = -1;
    int i;
    int cont = 1;

    if(!artistsList->isEmpty(artistsList)){
        for(i=0; i<artistsList->len(artistsList); i++){

            if(cont %250 == 0) {
               pause("\r\nPresione ENTER para continuar\r\n");
            }
            cont++;

            printf("%4d) ",i);
            artist_print(artistsList->get(artistsList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}

