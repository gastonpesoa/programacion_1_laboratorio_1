#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Input.h"
#include "Parser.h"
#include "Functions.h"
#include "LogEntry.h"
#include "Service.h"


Service* service_new(void){

    Service* returnAux = NULL;
    returnAux = (Service*)malloc(sizeof(Service));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}


int service_setId(Service* pService, int id, int lowLimit){

    int returnAux = -1;

    if(id >= lowLimit){

        pService->id = id;
        returnAux = 0;
    }

    return returnAux;
}


int service_setName(Service* pService, char* name, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(name, lowLimit, hiLimit)) {

        strcpy(pService->name,name);
        returnAux = 0;
    }

    return returnAux;
}


int service_setEmail(Service* pService, char* email, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(email, lowLimit, hiLimit)) {

        strcpy(pService->email,email);
        returnAux = 0;
    }

    return returnAux;
}



int service_getId(Service* pService){

    return pService->id;
}


char* service_getName(Service* pService){

    return pService->name;
}


char* service_getEmail(Service* pService){

    return pService->email;
}


void service_print(Service* pService){

    printf("| Id: %4d | Nombre: %15s | Email: %20s |\r\n"\
        ,pService->id,pService->name,pService->email);
}


int service_printArrayList(ArrayList* servicesList){

    int returnAux = -1;
    int i;

    if(!servicesList->isEmpty(servicesList)){
        for(i=0; i<servicesList->len(servicesList); i++){
            //printf("%4d) ",i);
            service_print(servicesList->get(servicesList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}


