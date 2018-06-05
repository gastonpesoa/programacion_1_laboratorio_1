//
//  functions.h
//  tp_3_laboratorio_1
//
//  Created by Gaston Pesoa on 27/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __tp_3_laboratorio_1__functions__
#define __tp_3_laboratorio_1__functions__

#include <stdio.h>



/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMoviesList* moviesList, EMovie* movie);

int mostrarListaDePeliculas(EMoviesList* moviesList, EMovie* movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);

/** Funcion que solicita un caracter 's' o 'n', valida que sea ingresado correctamente 
 *  y devuelve el resultado
 *  @param char confirmMensaje[] el mensaje a ser mostrado
 *  @return caracter 's' o 'n'
 */
char confirm(char confirmMensaje[]);

#endif /* defined(__tp_3_laboratorio_1__functions__) */
