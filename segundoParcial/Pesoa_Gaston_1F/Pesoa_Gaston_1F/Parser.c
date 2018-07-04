#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Empleado.h"
#include "Input.h"

int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    int returnAux = 0;
    int readItem;
    char idStr[256],nameAux[256],hsStr[256];
    int idAux, hsAux, flag = 0;
    FILE *pFile;

    if(listaEmpleados == NULL){
        printf("\r\nEspacio en memoria insuficiente\r\n");
        return returnAux;
    }

    pFile = fopen(fileName,"r");
    if (pFile == NULL) {

        printf("\r\nNo se pudo abrir el archivo\n");
        return returnAux;
    }

    while(!feof(pFile)){

        if(flag == 0){

            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idStr,nameAux,hsStr);
            flag = 1;
            continue;
        }

        cleanStdin();
        readItem = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idStr,nameAux,hsStr);
        if(readItem == 3){

            idAux = atoi(idStr);
            hsAux = atoi(hsStr);

            Empleado* em = em_new();

            em_setId(em,idAux,1);
            em_setName(em,nameAux,1,256);
            em_setHs(em,hsAux,1);

            if(al_add(listaEmpleados,em) == -1){
                printf("\r\nNo se pudo ingresar el nuevo emo, verifique espacio en memoria\r\n");
                return returnAux;
            }
        }
        else {

            printf("\r\nNo se leyeron los datos correctamente\n");
            pause("\r\nEnter para salir: ");
            return returnAux;;
        }//if(readItem==4)
    }//while(!feof(pFile))

    printf("\r\nCargando archivo a la lista...\r\n");
    fclose(pFile);

    return 1; // OK
}

