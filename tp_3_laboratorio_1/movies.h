//
//  movies.h
//  tp_3_laboratorio_1
//
//  Created by Gaston Pesoa on 29/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __tp_3_laboratorio_1__movies__
#define __tp_3_laboratorio_1__movies__

#include <stdio.h>

typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[200];
}EMovie;

typedef struct{
    int indice;
    int listSize;
    EMovie** movies;
} EMoviesList;


/** \brief Pide al usuario los datos de una pelicula y los almacena en la struct
 * \param EMovie* movie puntero a tipo EMovie donde se guardaran los datos
 * \return -
 */
void list_enterMovie(EMovie* movie);

/** \brief Imprime los datos de una pelicula
 * \param EMovie* movie puntero a tipo EMovie donde se guardaran los datos
 * \return void
 */
void list_printMovie(EMovie* movie);

/** \brief Inicializa el array de estructuras Movie
 * \return puntero a tipo EMoviesList
 */
EMoviesList* list_initMoviesList(void);

/** \brief Agrega una referencia a una struct EMovie al array
 *  \param EMoviesList* moviesList: Puntero a estructura EMoviesList
 *  \param EMovie* movie: Puntero a estructura EMovie
 *  \return void
 */
void list_addMovie(EMoviesList* moviesList, EMovie* movie);

/** \brief Crea una estructura del tipo EMovie en forma dinámica
 * \return Devuelve un puntero a la estructura creada
 */
EMovie* list_newMovie(void);

/** \brief Elimina un item del array
 * \param EMoviesList* moviesList: Puntero a estructura EMoviesList
 * \param indexToDelete: indice a borrar
 * \return void
 */
void list_removeMovie(EMoviesList* moviesList, int indexToDelete);

/** \brief Devuelve la cantidad de items en el array
 * \param EMoviesList* moviesList: Puntero a estructura EMoviesList
 * \return Cantidad de items en el array
 */
int list_getSize(EMoviesList* moviesList);

/** \brief Devuelve un item del array
 * \param EMoviesList* moviesList: Puntero a estructura EMoviesList
 * \param i: indice a obtener
 * \return Puntero a estructura EMovie que se encuentra en esa posición del array, o NULL.
 */
EMovie* list_get(EMoviesList* moviesList, int i);

#endif /* defined(__tp_3_laboratorio_1__movies__) */
