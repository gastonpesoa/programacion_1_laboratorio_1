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



LogEntry* logEntry_new(void){

    LogEntry* returnAux = NULL;
    returnAux = (LogEntry*)malloc(sizeof(LogEntry));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}



int logEntry_setDate(LogEntry* pLogEntry, char* date, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(date, lowLimit, hiLimit)) {

        strcpy(pLogEntry->date,date);
        returnAux = 0;
    }

    return returnAux;
}



int logEntry_setTime(LogEntry* pLogEntry, char* time, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(time, lowLimit, hiLimit)) {

        strcpy(pLogEntry->time,time);
        returnAux = 0;
    }

    return returnAux;
}




int logEntry_setServiceId(LogEntry* pLogEntry, int serviceId, int lowLimit){

    int returnAux = -1;

    if(serviceId >= lowLimit){

        pLogEntry->serviceId = serviceId;
        returnAux = 0;
    }

    return returnAux;
}



int logEntry_setGravedad(LogEntry* pLogEntry, int gravedad, int lowLimit){

    int returnAux = -1;

    if(gravedad >= lowLimit){

        pLogEntry->gravedad = gravedad;
        returnAux = 0;
    }

    return returnAux;
}



int logEntry_setMsg(LogEntry* pLogEntry, char* msg, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(msg, lowLimit, hiLimit)) {

        strcpy(pLogEntry->msg,msg);
        returnAux = 0;
    }

    return returnAux;
}


char* logEntry_getDate(LogEntry* pLogEntry){

    return pLogEntry->date;
}


char* logEntry_getTime(LogEntry* pLogEntry){

    return pLogEntry->time;
}



int logEntry_getServiceId(LogEntry* pLogEntry){

    return pLogEntry->serviceId;
}



int logEntry_getGravedad(LogEntry* pLogEntry){

    return pLogEntry->gravedad;
}



char* logEntry_getMsg(LogEntry* pLogEntry){

    return pLogEntry->msg;
}



void logEntry_print(LogEntry* pLogEntry){

    printf("| Fecha: %10s | Hora: %5s | Service Id: %4d | Gravedad: %6d | Mensaje: %25s |\r\n",\
        pLogEntry->date,pLogEntry->time,pLogEntry->serviceId,pLogEntry->gravedad,pLogEntry->msg);
}



int logEntry_printArrayList(ArrayList* logEntrysList){

    int returnAux = -1;
    int i;
    int cont=1;

    if(!logEntrysList->isEmpty(logEntrysList)){
        for(i=0; i<logEntrysList->len(logEntrysList); i++){

            if(cont %250 == 0){

               system("pause");
            }
            cont++;

            //printf("%4d) ",i);
            logEntry_print(logEntrysList->get(logEntrysList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}


int logEntry_compareByGravedad(void* pLogEntryA,void* pLogEntryB){

    if(((LogEntry*)pLogEntryA)->gravedad > ((LogEntry*)pLogEntryB)->gravedad){

        return 1;
    }
    if(((LogEntry*)pLogEntryA)->gravedad < ((LogEntry*)pLogEntryB)->gravedad){

        return -1;
    }
    return 0;
}
