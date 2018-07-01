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
        pause("\r\nEnter para salir: ");
        return returnAux;
    }

    while(!feof(pFile)){

        if(pFile == NULL){

            printf("\r\nEl archivo no existe");
            pause("\r\nEnter para salir: ");
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
            pause("\r\nEnter para salir: ");
            return returnAux;;
        }//if(readItem==4)
    }//while(!feof(pFile))

    fclose(pFile);
    return returnAux;
}


int person_toText(FILE* pFile, ArrayList* personsList, char *fileName){

    int returnAux = -1;
    int i, arrayLenght;
    char *nameAux;
    char *mailAux;

    Person *personAux;

    pFile = fopen(fileName, "w");
    if(pFile == NULL){
         printf("\r\nError al intentar abrir el archivo\r\n");
         pause("\r\nEnter para salir: ");
         return returnAux;
    }

    arrayLenght = personsList->len(personsList);

    for(i = 0; i < arrayLenght; i++){

        personAux = personsList->get(personsList,i);
        nameAux = personAux->name;
        mailAux = personAux->mail;

        if((fprintf(pFile, "%s,%s\n", nameAux, mailAux)) < 0){
            printf("\r\nError al intentar escribir la persona en el archivo\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    }

    fclose(pFile);
    returnAux = 0;
    return returnAux;
}


