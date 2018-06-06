#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "input.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee){

    ptrFile = fopen("data.csv","r");

    int readItem;
    char idStr[5],name[20],lastName[20],isEmptyStr[6];
    int idAux, isEmptyAux;
    int flag = 0;

    while(!feof(ptrFile)){
        if(ptrFile == NULL){
            printf("\nEl archivo no existe");
            exit(1);
        }
        if(flag == 0){
            fscanf(ptrFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,name,lastName,isEmptyStr);
            flag = 1;
                continue;
        }
        readItem = fscanf(ptrFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,name,lastName,isEmptyStr);
        if(readItem==4){
            Employee* empleado = employee_new();

            idAux = atoi(idStr);
            employee_setId(empleado,idAux);
            employee_setName(empleado,name);
            employee_setLastName(empleado,lastName);

            if(isEmptyStr=="true"){
                isEmptyAux = 1;
            }
            if(isEmptyStr=="false"){
                isEmptyAux = 0;
            }
            employee_setIsEmpty(empleado,isEmptyAux);

            al_add(pArrayListEmployee,empleado);
            printf("\nSe agreggo id: %d Nombre: %s Apellido: %s Es vacio: %d",empleado->id,empleado->name,empleado->lastName,empleado->isEmpty);
        }

    }

     fclose(ptrFile);
    return 0;
}
