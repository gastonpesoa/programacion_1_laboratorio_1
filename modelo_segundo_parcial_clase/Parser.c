#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Person.h"
#include "Input.h"
#include "Parser.h"


int parserPerson(FILE* pFile , ArrayList* personsList, char* archivo){

    int returnAux = -1;
    int readItem;
    char nameAux[256],mailAux[256];

    pFile = fopen(archivo,"r");
    if (pFile==NULL) {

        printf("\r\nNo se pudo abrir el archivo\n");
        getChar("\r\nEnter para salir: ");
        return returnAux;
    }

    while(!feof(pFile)){

        if(pFile == NULL){

            printf("\r\nEl archivo no existe");
            getChar("\r\nEnter para salir: ");
            return returnAux;
        }

        readItem = fscanf(pFile,"%[^,],%[^\n]\n",nameAux,mailAux);
        if(readItem==2){

            Person* person = person_new();

            person_setName(person,nameAux,1,256);
            person_setMail(person,mailAux,1,256);

            if(al_add(personsList,person) == -1){
                printf("\r\nNo se pudo ingresar el nuevo producto, verifique espacio en memoria\r\n");
                return returnAux;
            }

            returnAux = 0;
        }
        else {

            printf("\r\nNo se leyeron los datos correctamente\n");
            getChar("\r\nEnter para salir: ");
            return returnAux;;
        }//if(readItem==4)
    }//while(!feof(pFile))

    fclose(pFile);
    return returnAux;
}
