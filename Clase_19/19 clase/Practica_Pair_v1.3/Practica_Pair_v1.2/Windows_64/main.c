#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "input.h"


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


    int option = 0;
    //Employee* empleado = employee_new();
    ArrayList* lista = al_newArrayList();

     while(option != 7)
    {
        printf("\n--------------------------------------------\
                  \n|*             MENU PRINCIPAL             *|\
                  \n--------------------------------------------");

        option = optionMenu();

        switch(option)
        {
            case 1:

                parserEmployee(ptrFile,lista);
                break;
            case 2:
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:
                continue;
        }
    }

    return 0;
}
