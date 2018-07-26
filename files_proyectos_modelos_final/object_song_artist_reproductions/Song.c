#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Song.h"
#include "Input.h"



Song* song_new(void){

    Song* returnAux = NULL;
    returnAux = (Song*)malloc(sizeof(Song));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}


void song_askName(char *input){

    getValidString("Ingrese el nombre del objeto: ", "El nombre debe ser solo letras", input);

    capitalize(input);
}


int song_setId(Song* pSong, int id, int lowLimit){

    int returnAux = -1;

    if(id >= lowLimit){

        pSong->id = id;
        returnAux = 0;
    }

    return returnAux;
}


int song_setTitle(Song* pSong, char* title, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(title, lowLimit, hiLimit)) {

        strcpy(pSong->title,title);
        returnAux = 0;
    }

    return returnAux;
}


int song_setArtist(Song* pSong, char* artist, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(artist, lowLimit, hiLimit)) {

        strcpy(pSong->artist,artist);
        returnAux = 0;
    }

    return returnAux;
}


int song_getId(Song* pSong){

    return pSong->id;
}


char* song_getTitle(Song* pSong){

    return pSong->title;
}


char* song_getArtist(Song* pSong){

    return pSong->artist;
}


int song_compareByArtist(void* pSongA,void* pSongB){

    if(strcmp(((Song*)pSongA)->artist,((Song*)pSongB)->artist) > 0){

        return 1;
    }
    if(strcmp(((Song*)pSongA)->artist,((Song*)pSongB)->artist) < 0){

        return -1;
    }
    return 0; 
}


int song_compareByArtistTitle(void* pSongA,void* pSongB){

    if(strcmp(((Song*)pSongA)->artist,((Song*)pSongB)->artist) > 0){

        return 1;
    }
    if(strcmp(((Song*)pSongA)->artist,((Song*)pSongB)->artist) < 0){

        return -1;
    }
    else {

        if(strcmp(((Song*)pSongA)->title,((Song*)pSongB)->title) > 0){

            return 1;
        }
        if(strcmp(((Song*)pSongA)->title,((Song*)pSongB)->title) < 0){

            return -1;
        }
        return 0;
    }
}


void song_print(Song* pSong){

    printf("| Id: %4d | Titulo: %45s | Autor: %30s |\r\n"\
        ,pSong->id,pSong->title,pSong->artist);
}


int song_printArrayList(ArrayList* songsList){

    int returnAux = -1;
    int i;
    int cont = 1;

    if(!songsList->isEmpty(songsList)){
        for(i=0; i<songsList->len(songsList); i++){

            if(cont %250 == 0) {
               pause("\r\nPresione ENTER para continuar\r\n");
            }
            cont++;

            printf("%4d) ",i);
            song_print(songsList->get(songsList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}


Song *song_requestValidId(ArrayList* songsList){

    Song *returnAux = NULL;
    int idAux;
    int indexItem;
    char confirmaIngreso = 'n';
    Song *songAux = song_new();

    idAux = getValidInt("\r\nIngrese el Id del objeto a dar de baja logica: ","\r\nEl Id debe ser numerico\r\n",1,1000);
    indexItem = idAux - 1;

    songAux = songsList->get(songsList,indexItem);
    while(songAux == NULL){

        printf("\r\nNo hay ningun objeto registrado con el Id ingresado\r\n");
        confirmaIngreso = confirm("\r\nPresione 's' para volver a ingresar el Id o 'n' para salir: [s|n] ");

        if(confirmaIngreso == 's'){
            idAux = getValidInt("\r\nReingrese el Id del objeto a modificar: ","\r\nEl Id debe ser numerico\r\n",1,1000);
            indexItem = idAux - 1;
            songAux = songsList->get(songsList,indexItem);
        }
        else {
            return returnAux;
        }
    }

    return songAux;
}

