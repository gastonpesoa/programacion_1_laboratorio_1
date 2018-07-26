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


int parser_LogsEntryListFile(FILE *pFile , ArrayList *logEntrysList, char *fileName){

    //Se definen variables auxiliares
    int returnAux = -1;
    int readItem;
    char dateAux[12], timeAux[12], serviceIdStr[12], gravedadStr[12], msgAux[65];
    int serviceIdAux, gravedadAux;

    //Se verifica que la lista ingresada no sea NULL
    if(logEntrysList == NULL){
        //En caso de lista NULL se informa y se sale retornando valor de Error
        printf("\r\nError, lista nula\r\n");
        pause("\r\nPresione enter para volver\r\n");
        return returnAux;
    }
    //Se abre el archivo, pasado como parametro, para lectura de texto
    //y se asigna puntero al archivo devuelto, al puntero pFile pasado como paramentro
    pFile = fopen(fileName,"r");
    if (pFile==NULL) {
        //Si fopen devuelve NULL se informa y se sale de la funcion retornando valor de error
        printf("\r\nNo se pudo abrir el archivo\n");
        pause("\r\nEnter para volver: ");
        return returnAux;
    }
    //Mientras no se llegue al final del archivo lo sigo recorriendo
    while(!feof(pFile)){
        
        //Se realiza la lectura de los datos
        cleanStdin();
        readItem = fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",dateAux,timeAux,serviceIdStr,gravedadStr,msgAux);
        if(readItem == 5){
            //Si se leyeron todos datos para los campos necesarios del archivo
            //se realiza la conversion de cadena a entero de los datos necesarios
            serviceIdAux = atoi(serviceIdStr);
            gravedadAux = atoi(gravedadStr);
            //Se crea una nueva struct
            LogEntry* logEntry = logEntry_new();
            //Se setean los datos a la struct
            logEntry_setDate(logEntry,dateAux,1,12);
            logEntry_setTime(logEntry,timeAux,1,12);
            logEntry_setServiceId(logEntry,serviceIdAux,0);
            logEntry_setGravedad(logEntry,gravedadAux,0);
            logEntry_setMsg(logEntry,msgAux,1,66);
            //Se agrega la struct a la lista
            if(logEntrysList->add(logEntrysList,logEntry) == -1){
                //En caso de error se informa y se sale retornando valor de error
                printf("\r\nNo se pudo ingresar el nuevo logEntryo, verifique espacio en memoria\r\n");
                return returnAux;
            }
            //logEntry_print(logEntry);
            //Si se realizo el parser correctamente se asigna valor de retorno Ok
            returnAux = 0;
        }
        else {
            //Si no se leyeron los datos necesarios se informa error y se sale retornando valor de error
            printf("\r\nNo se leyeron los datos correctamente\n");
            pause("\r\nEnter para salir: ");
            return returnAux;;
        }//if(readItem==4)
    }//while(!feof(pFile))
    //Si se recorrio todo el archivo y se cargaron todos los datos
    //Se cierra el archivo y se retorna valor de Ok
    fclose(pFile);
    return returnAux;
}


int parser_ServicesListFile(FILE *pFile , ArrayList *servicesList, char *fileName){

    //Se definen variables auxiliares
    int returnAux = -1;
    int readItem;
    char idStr[12], nameAux[34], emailAux[66];
    int idAux;

    //Se verifica que la lista ingresada no sea NULL
    if(servicesList == NULL){
        //En caso de lista NULL se informa y se sale retornando valor de Error
        printf("\r\nError, lista nula\r\n");
        pause("\r\nPresione enter para volver\r\n");
        return returnAux;
    }
    //Se abre el archivo, pasado como parametro, para lectura de texto
    //y se asigna puntero al archivo devuelto, al puntero pFile pasado como paramentro
    pFile = fopen(fileName,"r");
    if (pFile==NULL) {
        //Si fopen devuelve NULL se informa y se sale de la funcion retornando valor de error
        printf("\r\nNo se pudo abrir el archivo\n");
        pause("\r\nEnter para volver: ");
        return returnAux;
    }
    //Mientras no se llegue al final del archivo lo sigo recorriendo
    while(!feof(pFile)){
        
        //Se realiza la lectura de los datos
        cleanStdin();
        readItem = fscanf(pFile,"%[^;];%[^;];%[^\n]\n",idStr,nameAux,emailAux);
        if(readItem == 3){
            //Si se leyeron todos datos para los campos necesarios del archivo
            //se realiza la conversion de cadena a entero de los datos necesarios
            idAux = atoi(idStr);
            //Se crea una nueva struct
            Service* serviceAux = service_new();
            //Se setean los datos a la struct
            service_setId(serviceAux,idAux,0);
            service_setName(serviceAux,nameAux,1,34);
            service_setEmail(serviceAux,emailAux,1,66);
            //Se agrega la struct a la lista
            if(servicesList->add(servicesList,serviceAux) == -1){
                //En caso de error se informa y se sale retornando valor de error
                printf("\r\nNo se pudo ingresar el nuevo logEntryo, verifique espacio en memoria\r\n");
                return returnAux;
            }
            //logEntry_print(logEntry);
            //Si se realizo el parser correctamente se asigna valor de retorno Ok
            returnAux = 0;
        }
        else {
            //Si no se leyeron los datos necesarios se informa error y se sale retornando valor de error
            printf("\r\nNo se leyeron los datos correctamente\n");
            pause("\r\nEnter para salir: ");
            return returnAux;;
        }//if(readItem==4)
    }//while(!feof(pFile))
    //Si se recorrio todo el archivo y se cargaron todos los datos
    //Se cierra el archivo y se retorna valor de Ok
    fclose(pFile);
    return returnAux;
}


/*int logEntrysListToFile(FILE *pFile, ArrayList *logEntrysList, char *fileName){

    //Se definen variables auxiliares
    int returnAux = -1;
    int i, arrayLenght, idAux, gravedadAux;
    char *msgAux;

    LogEntry *logEntryAux;

    //Se verifica que la lista ingresada no sea NULL
    if(logEntrysList == NULL){
        //En caso de lista NULL se informa y se sale retornando valor de Error
        printf("\r\nError, lista nula\r\n");
        pause("\r\nPresione enter para volver\r\n");
        return returnAux;
    }
    //Se abre el archivo, pasado como parametro, para escribir texto
    //y se asigna puntero al archivo devuelto, al puntero pFile pasado como paramentro
    if((pFile = fopen(fileName,"w+")) == NULL){
        //Si fopen devuelve NULL se informa y se sale de la funcion retornando valor de error
        printf("\r\nError al intentar abrir el archivo\r\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }
    //Se escribe cabecera del archivo
    cleanStdin();
    fprintf(pFile, "logEntryo,descripcion,cantidad\n");
    //Se obtiene la longitud de la lista a recorrer
    arrayLenght = logEntrysList->len(logEntrysList);

    for(i = 0; i < arrayLenght; i++){
        //Obtengo el primer elemento de la lista
        logEntryAux = logEntrysList->get(logEntrysList,i);
        //Asigno los campos del elemento a las variables auxiliares
        idAux = logEntryAux->serviceId;
        msgAux = logEntryAux->msg;
        gravedadAux = logEntryAux->gravedad;
        //Se escriben los datos obtenidos en el archivo
        cleanStdin();
        if((fprintf(pFile, "%d,%s,%d\n", idAux, msgAux, gravedadAux)) < 0){
            //En caso de error al escribir los datos se informa y se sale retornando valor de Error
            printf("\r\nError al intentar escribir la servicea en el archivo\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    }
    //Si se recorrio toda la lista y se escribieron todos los datos
    //Se cierra el archivo y se sale retornando valor de Ok
    fclose(pFile);
    returnAux = 0;
    return returnAux;
}*/



