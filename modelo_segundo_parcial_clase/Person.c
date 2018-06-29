#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Person.h"
#include "Input.h"
#include "Parser.h"


#define PRODUCT_INACTIVE  0
#define PRODUCT_ACTIVE  1



Person* person_new(void){

    Person* returnAux = NULL;
    returnAux = (Person*)malloc(sizeof(Person));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}


int person_setName(Person* pPerson, char* name, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(name, lowLimit, hiLimit)) {

        strcpy(pPerson->name,name);
        returnAux = 0;
    }

    return returnAux;
}


int person_setMail(Person* pPerson, char* mail, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(mail, lowLimit, hiLimit)) {

        strcpy(pPerson->mail,mail);
        returnAux = 0;
    }

    return returnAux;
}


char* person_getName(Person* pPerson){

    return pPerson->name;
}


char* person_getMail(Person* pPerson){

    return pPerson->mail;
}


int person_compareByName(void* pPersonA,void* pPersonB){

    if(strcmp(((Person*)pPersonA)->name,((Person*)pPersonB)->name) > 0){

        return 1;
    }
    if(strcmp(((Person*)pPersonA)->name,((Person*)pPersonB)->name) < 0){

        return -1;
    }
    return 0;
}


int person_compareByMail(void* pPersonA,void* pPersonB){

    if(strcmp(((Person*)pPersonA)->mail,((Person*)pPersonB)->mail) > 0){

        return 1;
    }
    if(strcmp(((Person*)pPersonA)->mail,((Person*)pPersonB)->mail) < 0){

        return -1;
    }
    return 0;
}


void person_print(Person* pPerson){

    printf("| Nombre: %15s | Mail: %15s \r\n",pPerson->name,pPerson->mail);
}


void person_printAll(Person* pPerson,ArrayList* personsList){

    int i;
    for (i=0; i<al_len(personsList); i++) {
        pPerson = al_get(personsList, i);
        person_print(pPerson);
    }
}

int person_printArrayList(ArrayList* personsList){

    int returnAux = -1;
    int i;

    if(!personsList->isEmpty(personsList)){
        for(i=0; i<personsList->len(personsList); i++){
            printf("%4d) ",i);
            person_print(personsList->get(personsList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}
