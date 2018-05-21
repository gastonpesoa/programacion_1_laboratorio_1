//
//  inputFunctions.h
//  practica_modelo_parcial_2
//
//  Created by Gaston Pesoa on 01/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __practica_modelo_parcial_2__inputFunctions__
#define __practica_modelo_parcial_2__inputFunctions__

int optionMenu(void);
int optionMenuModificar(void);

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

int esNumerico(char str[]);
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
void getStringNombre(char mensaje[], char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringAlfanumerico(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getStringLetrasNombre(char mensaje[], char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
int getValidFloat(char requestMessage[],char errorMessage[],float lowLimit, float hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);
void getValidStringAlfanumerico(char requestMessage[],char errorMessage[], char input[]);
void getValidStringNombre(char requestMessage[],char errorMessage[], char input[]);

void cleanStdin(void);
void clearScreen(void);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

#endif /* defined(__practica_modelo_parcial_2__inputFunctions__) */
