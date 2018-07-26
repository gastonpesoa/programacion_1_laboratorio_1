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


int procesarInformacion(FILE* pWarningsFile, FILE* pErrorsFile, ArrayList* logsEntryList, ArrayList* servicesList, char* warningsFileName, char* errorsFileName){

    int i, j, returnAux = -1;
    int logsEntryListLenght, servicesListLenght;
    int gravedadAux, serviceIdAux, serviceIdInServiceList;
    char dateAux[12], timeAux[7], nameAux[34], msgAux[66], emailAux[66]; 
    
    LogEntry* logEntryAux;
    Service* serviceAux;

    //Se verifica que la lista ingresada no sea NULL
    if(logsEntryList == NULL || servicesList == NULL){
        //En caso de lista NULL se informa y se sale retornando valor de Error
        printf("\r\nError, lista nula\r\n");
        pause("\r\nPresione enter para volver\r\n");
        return returnAux;
    }
    //Se abre el archivo, pasado como parametro, para escribir de texto
    //y se asigna puntero al archivo devuelto, al puntero pFile pasado como paramentro
    pWarningsFile = fopen(warningsFileName,"w");
    pErrorsFile = fopen(errorsFileName, "w");
    if (pWarningsFile == NULL || pErrorsFile == NULL) {
        //Si fopen devuelve NULL se informa y se sale de la funcion retornando valor de error
        printf("\r\nNo se pudo abrir el archivo\n");
        pause("\r\nEnter para volver: ");
        return returnAux;
    }

    logsEntryListLenght = logsEntryList->len(logsEntryList);
    servicesListLenght = servicesList->len(servicesList);

    printf("\n\n==============================================\
              \n| FALLOS DE SERVICIOS CON GRAVEDAD > 3 y < 8 |\
              \n==============================================\n");

    for(i = 0; i < logsEntryListLenght; i++){

        logEntryAux = logsEntryList->get(logsEntryList,i);

        gravedadAux = logEntry_getGravedad(logEntryAux);
        serviceIdAux = logEntry_getServiceId(logEntryAux);
        strcpy(dateAux,logEntry_getDate(logEntryAux));
        strcpy(timeAux,logEntry_getTime(logEntryAux));
        strcpy(msgAux,logEntry_getMsg(logEntryAux));

        for(j = 0; j < servicesListLenght; j++){

            serviceAux = servicesList->get(servicesList,j);
            serviceIdInServiceList = service_getId(serviceAux);

            if(serviceIdAux == serviceIdInServiceList){
                
                strcpy(nameAux,service_getName(serviceAux));
                strcpy(emailAux,service_getEmail(serviceAux));
                break;
            }
        }//for(j = 0; j < servicesListLenght; j++){

        if(gravedadAux < 3){
            continue;
        }
        else{
            if(gravedadAux == 3){

                if(serviceIdAux != 45){

                    if(fprintf(pWarningsFile, "%s;%s;%s;%s;%s\n", dateAux, timeAux, nameAux, msgAux, emailAux)<0){
                        //En caso de error al escribir los datos se informa y se sale retornando valor de Error
                        printf("\r\nError al intentar escribir en el archivo de warnings\r\n");
                        pause("\r\nEnter para salir: ");
                        return returnAux;
                    }
                }
                else{
                    continue;
                }//if(serviceIdAux != 45){
            }//if(gravedadAux == 3){
            if(gravedadAux > 3 && gravedadAux < 8){

                printf("| Fecha: %10s | Hora: %5s | Nombre servicio: %15s | Mensaje de error: %15s | Gravedad: %3d |\n",\
                    dateAux,timeAux,nameAux,msgAux,gravedadAux);
            }
            else{
                if(fprintf(pErrorsFile, "%s;%s;%s;%s;%s\n", dateAux, timeAux, nameAux, msgAux, emailAux)<0){
                    //En caso de error al escribir los datos se informa y se sale retornando valor de Error
                    printf("\r\nError al intentar escribir en el archivo de errors\r\n");
                    pause("\r\nEnter para salir: ");
                    return returnAux;
                }
            }//if(gravedadAux > 3 && gravedadAux < 8){
        }//if(gravedadAux < 3){
    }//for(i = 0; i < logsEntryListLenght; i++){
    fclose(pWarningsFile);
    fclose(pErrorsFile);
    returnAux = 0;
    return returnAux;
}


void mostrarEstadisticas(ArrayList* logsEntryList, ArrayList* servicesList){
    
    int i, j;
    int logsEntryListLenght, servicesListLenght;
    int serviceIdAux;
    int fallosMaxQty = 0, cantFallosDeService;
    int gravedadAux; 
    int cantFallosGrvdMnrA3 = 0, cantFallosGrvdIgA3 = 0, cantFallosGrvdEntr4y7 = 0, cantFallosGrvdMyrA7 = 0;

    LogEntry* logEntryAux;
    Service* serviceAux, *serviceMaxCantFallos;

    logsEntryListLenght = logsEntryList->len(logsEntryList);
    servicesListLenght = servicesList->len(servicesList);

    for(i = 0; i < servicesListLenght; i++){

        cantFallosDeService = 0;
        
        serviceAux = servicesList->get(servicesList,i);
        serviceIdAux = service_getId(serviceAux);

        for(j = 0; j < logsEntryListLenght; j++){

            logEntryAux = logsEntryList->get(logsEntryList,j);
            gravedadAux = logEntry_getGravedad(logEntryAux);

            if(serviceIdAux == logEntry_getServiceId(logEntryAux)){

                cantFallosDeService++;
            }//if(serviceIdAux == logEntry_getServiceId(logEntryAux)){

            if(cantFallosDeService > fallosMaxQty){

                fallosMaxQty = cantFallosDeService;
                serviceMaxCantFallos = serviceAux;
            }//if(cantFallosDeService > fallosMaxQty){

        }//for(j = 0; j < logsEntryListLenght; j++){
    }//for(i = 0; i < servicesListLenght; i++){

    for(i = 0; i < logsEntryListLenght; i++){

        logEntryAux = logsEntryList->get(logsEntryList,i);
        gravedadAux = logEntry_getGravedad(logEntryAux);

        if(gravedadAux < 3){
            cantFallosGrvdMnrA3++;
        }
        else{
            if(gravedadAux == 3){
                cantFallosGrvdIgA3++;
            }
            if(gravedadAux > 3 && gravedadAux < 8){
                cantFallosGrvdEntr4y7++;
            }
            else{
                cantFallosGrvdMyrA7++;
            }
        }
    }

    printf("\nServicio con mayor cantidad de fallos: \n");
    service_print(serviceMaxCantFallos);

    printf("Cantidad de servicios con fallos de gravedad menor a 3: %d\
          \nCantidad de servicios con fallos de gravedad igual a 3: %d\
          \nCantidad de servicios con fallos de gravedad entre 4 y 7: %d\
          \nCantidad de servicios con fallos de gravedad mayor a 7: %d\n",\
        cantFallosGrvdMnrA3,cantFallosGrvdIgA3,cantFallosGrvdEntr4y7,cantFallosGrvdMyrA7);
    //return idServiceMaxCantFallos;
    return;
}

/*Service* getServiceById(ArrayList* servicesList, int serviceId){

    int i, servicesListLenght;
    Service *returnAux == NULL, *serviceAux;

    servicesListLenght = servicesList->len(servicesList);

    for(i = 0; i < servicesListLenght; i++){

        serviceAux = servicesList->get(servicesList,i);

        if(serviceId == service_getId(servicesList)){
            returnAux = serviceAux;
        }
    }

    return returnAux;
}*/


