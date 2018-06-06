#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Employee.h"
#include "input.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main(){
    
    FILE *ptrFile;
    
    
    int option = 0, i, j;
    Employee* empleado = employee_new();
    ArrayList* lista = al_newArrayList();
    
    while(option != 7)
    {
        printf("\n\n--------------------------------------------\
               \n|*             MENU PRINCIPAL             *|\
               \n--------------------------------------------");
        
        option = optionMenu();
        
        switch(option)
        {
            case 1: //Parse del archivo data.csv
                parserEmployee(ptrFile,lista);
                break;
                
            case 2: //Listar Empleados
                if (lista->size < 1) {
                    printf("\nPor favor, cargue el archivo con la opcion '1' antes de utilizar esta funcion.");
                    getChar("\nPresione una tecla para volver al menu: ");
                }
                else {
                    employee_printAll(empleado, lista);
                    getChar("\n\nPresione una tecla para volver al menu: ");
                }
                break;
                
            case 3: //Ordenar por nombre
                
                for (i = 0; i < al_len(lista)-1; i++) {
                    for (j = i+1; j < al_len(lista); j++) {
                        /*if (strcmp(empleado[i]->name, empleado[j]->name)<0) {
                            <#statements#>
                        }*/
                    }
                }
                break;
            case 4: //Agregar un elemento
                
                break;
                
            case 5: //Elimina un elemento
                
                break;
                
            case 6: //Listar Empleados (Desde/Hasta)
                
                break;
                
            case 7: //Salir
                continue;
        }
    }

    return 0;
}
