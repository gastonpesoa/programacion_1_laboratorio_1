//
//  functions.c
//  tp_3_laboratorio_1
//
//  Created by Gaston Pesoa on 27/05/18.
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


int guardarPelicula(EMovie* movie){
    
    FILE* ptrFile;
    
    ptrFile = fopen("bin.dat", "ab+");
    if (ptrFile==NULL) {
        
        printf("\nError abriendo el archivo\n");
        return 0;
    }
    
    fpurge(stdin);
    fwrite(movie, sizeof(EMovie), 1, ptrFile);
    printf("\nSe guardo la pelicula en el archivo\n");
    fclose(ptrFile);
    return 1;
}


int agregarPelicula(EMoviesList* moviesList, EMovie* movie){
    
    char confirmar = 's';
    
    clearScreen();
    printf("\n--------------------------------------------\
            \n|      *      ALTA DE PELICULA      *      |\
            \n--------------------------------------------\n\n");
    
    while (confirmar=='s') {
        
        list_enterMovie(movie);
        
        list_addMovie(moviesList, movie);
        
        if (!guardarPelicula(movie)) {
            printf("\nNo se pudo guardar la pelicula\n");
            return 0;
        }
        
        movie = list_newMovie();
        
        confirmar = confirm("Desea cargar otra pelicula? [s|n]: ");
    }
    free(movie);
    int i;
    
    for (i=0; i<list_getSize(moviesList); i++) {
        list_printMovie(list_get(moviesList, i));
    }
    
    return 1;
}

int mostrarListaDePeliculas(EMoviesList* moviesList, EMovie* movie){
    
    int i=0;
    //unsigned long cant;
    FILE* ptrFile;
    EMovie* movieAux = (EMovie*)malloc(sizeof(EMovie));
    
    ptrFile = fopen("bin.dat", "rb");
    
    if (ptrFile==NULL) {
        
        printf("\nError abriendo el archivo\n");
        return 0;
    }
    
    fpurge(stdin);
    rewind (ptrFile);
    while (fread(movieAux, sizeof(movie), 1, ptrFile)!=0) {
        printf("\nTitulo: %s \nGenero: %s \nDuracion: %d \nDescripcion: %s \nPuntaje: %d \
               \nLink imagen: %s",movieAux->titulo,movieAux->genero,movieAux->duracion,\
               movieAux->descripcion,movieAux->puntaje,movieAux->linkImagen);
        
        /*moviesList->movies[i]=movieAux;
        list_printMovie(list_get(moviesList, i));
        i++;*/
    }
    fclose(ptrFile);
    getchar();
    return 1;
    /*while(!feof(ptrFile)){
        
        fpurge(stdin);
        rewind (ptrFile);
        cant = fread(moviesList->movies,sizeof(movie),1,ptrFile);
        
        if(cant!=1){
            if(feof(ptrFile)){
                return 0;
            }
            else{
                printf("No leyo el ultimo registro");
                return 0;
            }
        }
        list_printMovie(list_get(moviesList, i));
    }
    fclose(ptrFile);
    getchar();
    return 1;*/
}


char confirm(char confirmMensaje[]){
    
    char confirmar = 'n';
    
    do {
        
        printf("%s", confirmMensaje);
        fpurge(stdin);
        scanf("%c", &confirmar);
        confirmar = tolower(confirmar);
        
    } while (confirmar != 's' && confirmar != 'n');
    
    return confirmar;
}