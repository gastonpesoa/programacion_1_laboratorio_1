#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

#define ARCH "/Volumes/Almacen/UTN/Programacion I/Practicas/practica_archivos/archivos_texto_escrituraLectura/archivos_texto_escrituraLectura/texto.txt"

int main(){

    FILE *pFile;
    char textToWrite[256];
    char textRead[256];
    long int textLenght;
    int qtyReturned;

    if((pFile = fopen(ARCH,"r+")) == NULL){
        if((pFile = fopen(ARCH,"w+")) == NULL){
            printf("\r\nError al intentar abrir el archivo\r\n");
        }
        printf("\r\nEl archivo no existe por lo tanto se crea\r\n");
    }
    else {
        printf("\r\nEl archivo existe por lo tanto no se crea\r\n");
    }

    getValidString("\r\nIngrese el texo que desea escribir en el archivo: ","\r\nEl texto debe ser solo letras\r\n",textToWrite);
    textLenght = strlen(textToWrite);

    //Me posiciono al final del archivo para agregar datos
    fseek(pFile,0L,SEEK_END);
    //fprintf(pFile,"\r\nEsto es lo que se ingreso: %s\r\n",textToWrite);
    cleanStdin();
    qtyReturned = fwrite(textToWrite,sizeof(char),textLenght,pFile);
    if(qtyReturned != textLenght){
        printf("\r\nError al intentar escribir el texto en el archivo\r\n");
    }
    else {
        printf("\r\nSe escribio el texto en el archivo con exito!!\r\n");
    }

    //Obtengo la nueva longitud del archivo
    textLenght = ftell(pFile);
    //Me posiciono al comienzo del arch para empezar a leer
    rewind(pFile);
    while(!feof(pFile)){
        qtyReturned = fread(textRead,sizeof(char),textLenght,pFile);
        if(qtyReturned != textLenght){
            if(feof(pFile)){
                printf("\r\nSe llego al final del archivo\r\n");
                break;
            }
            else{
                printf("\r\nError al intentar leer el archivo\r\n");
            }
            printf("\r\nSe lee del archivo: %s\r\n",textRead);
        }
    }
    printf("\r\nSe lee del archivo: %s\r\n",textRead);
    fclose(pFile);

    return 0;
}
