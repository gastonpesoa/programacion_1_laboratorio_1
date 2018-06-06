#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Employee.h"
#include "input.h"
#include "parser.h"


int parserEmployee(FILE* ptrFile , ArrayList* pArrayListEmployee){
    
    int readItem;
    char idStr[256],name[256],lastName[256],isEmptyStr[256];
    int idAux, isEmptyAux=0;
    int flag = 0;
    
    ptrFile = fopen("../../../ejercicio_parser/data.csv","r");
    if (ptrFile==NULL) {
        
        printf("\nNo se pudo abrir el archivo\n");
        getChar("Enter para salir: ");
        exit(1);
    }
    
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
            
            if(strncmp(isEmptyStr,"true",4)==0){
                isEmptyAux = 1;
            }
            if(strncmp(isEmptyStr,"false",5)==0){
                isEmptyAux = 0;
            }
            
            employee_setIsEmpty(empleado,isEmptyAux);
            
            al_add(pArrayListEmployee,empleado);
            
            //employee_print(empleado);
        }
        else {
            
            printf("\nNo se leyeron los datos correctamente\n");
            getChar("Enter para salir: ");
            exit(1);
        }//if(readItem==4)
    }//while(!feof(ptrFile))
    
    printf("\nLista cargada con exito\n");
    getChar("Presione una tecla para continuar: ");
    
    fclose(ptrFile);
    return 0;
}
