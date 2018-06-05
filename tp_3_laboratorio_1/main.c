//
//  main.c
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



int main()
{
    EMovie* movie;
    EMoviesList* moviesList;
    
    char seguir='s';
    int opcion=0;
    
    moviesList = list_initMoviesList();

    movie = list_newMovie();
    
    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");
        
        scanf("%d",&opcion);
        
        switch(opcion)
        {
            case 1:
                
                if (!agregarPelicula(moviesList,movie)) {
                    printf("\nNo se pudo agregar la pelicula\n");
                }
                else{
                    printf("\nPelicula cargada con exito\n");
                }
                break;
            case 2:
                break;
            case 3:
                mostrarListaDePeliculas(moviesList, movie);
                /*if (!mostrarListaDePeliculas(moviesList, movie)) {
                    printf("\nNo se pudo agregar la pelicula\n");
                }
                else{
                    getchar();
                }*/
                break;
            case 4:
                seguir = 'n';
                break;
        }
    }
    
    return 0;
}

