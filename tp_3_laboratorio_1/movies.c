//
//  movies.c
//  tp_3_laboratorio_1
//
//  Created by Gaston Pesoa on 29/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "movies.h"
#include "functions.h"
#include "inputFunctions.h"

/*void enterTitle(char title[]){
    fpurge(stdin);
    printf("\nIngrese el titulo: ");
    scanf("%50[^\n]", title);
}

int list_setTitleMovie(EMovie* movie, char movieTitle[]){
    
    int i;
    unsigned long titleLenght = strlen(movieTitle);
    
    if (titleLenght>1 && titleLenght<21) {
        for (i = 0; i < titleLenght; i++) {
            
            movieTitle[i] = tolower(movieTitle[i]);
        }
        movieTitle[0] = toupper(movieTitle[0]);
        strcpy(movie->titulo, movieTitle);
        return 0;
    }
    return 1;
}*/


void list_enterMovie(EMovie* movie){
    
    /*char titleAux[20];
    enterTitle(titleAux);
    if (list_setTitleMovie(movie, titleAux)) {
        printf("\nEl titulo debe tener como maximo 19 caracteres");
    }*/
    
    getValidStringTitle("Ingrese el titulo: ", movie->titulo);
    getValidStringGenero("Ingrese el genero: ", "\nEl genero debe estar compuesto por letras", movie->genero);
    movie->duracion = getValidInt("Ingrese la duracion en minutos: ", "\nLa duracion debe estar compuesta por numeros enteros", 1, 300);
    getValidStringDescription("Ingrese una descripcion: ", "\nLa descripcion debe estar compuesta solo por letras", movie->descripcion);
    movie->puntaje = getValidInt("Ingrese un puntaje: ", "\nEl puntaje debe ser numerico", 1, 10);
    getValidStringLink("Ingrese el link de imagen: ", movie->linkImagen);
}


void list_printMovie(EMovie* movie){
    
    printf("Titulo:\t%s \nGenero:\t%s \nDuracion:\t%d \nDescripcion:\t%s \nPuntaje:\t%d \nLink de imagen:\t%s",movie->titulo,movie->genero,movie->duracion,movie->descripcion,movie->puntaje,movie->linkImagen);
}


EMoviesList* list_initMoviesList(void){
    
    EMoviesList* moviesList = (EMoviesList*)malloc(sizeof(EMoviesList));
    
    moviesList->indice = 0;
    moviesList->listSize = 2;
    moviesList->movies = (EMovie**)malloc(sizeof(EMovie*)*moviesList->listSize);
    
    return moviesList;
}


void list_addMovie(EMoviesList* moviesList, EMovie* movie){
    
    EMovie** moviesAux;
    
    moviesList->movies[moviesList->indice] = movie;
    moviesList->indice++;
    
    if (moviesList->indice >= moviesList->listSize) {
        
        moviesList->listSize+=2;
        moviesAux = (EMovie**)realloc(moviesList->movies, sizeof(EMovie*)*moviesList->listSize);
        if (moviesAux == NULL) {
            
            printf("\nNo hay lugar en memoria\n");
            free(moviesAux);
        }
        else {
            moviesList->movies = moviesAux;
        }
    }
}


EMovie* list_newMovie(void){
    
    EMovie* movie = (EMovie*)malloc(sizeof(EMovie));
    return movie;
}


void list_removeMovie(EMoviesList* moviesList, int indexToDelete){
    
    int i;
    
    if (moviesList->indice != 0 && indexToDelete < moviesList->indice) {
        
        for (i=indexToDelete; i<(moviesList->indice-1); i++) {
            
            moviesList->movies[i] = moviesList->movies[i+1];
        }
        moviesList->indice--;
    }
}


int list_getSize(EMoviesList* moviesList){
    
    return moviesList->indice;
}


EMovie* list_get(EMoviesList* moviesList, int i){
    
    if (i < moviesList->indice) {
        
        return moviesList->movies[i];
    }
    return NULL;
}


void list_free(EMoviesList* moviesList){
    
    free(moviesList->movies);
}