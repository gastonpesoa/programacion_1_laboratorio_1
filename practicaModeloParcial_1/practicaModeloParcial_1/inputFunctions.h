//
//  inputFunctions.h
//  practicaModeloParcial_1
//
//  Created by Gaston Pesoa on 02/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __practicaModeloParcial_1__inputFunctions__
#define __practicaModeloParcial_1__inputFunctions__

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char str[]);
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
void getStringNombre(char mensaje[], char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringLetrasNombre(char mensaje[], char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
int getValidFloat(char requestMessage[],char errorMessage[],float lowLimit, float hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);

void cleanStdin(void);
void clearScreen(void);

#endif /* defined(__practicaModeloParcial_1__inputFunctions__) */
