#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


int compareEmployee(void* pEmployeeA,void* pEmployeeB){

    if(((Employee*)pEmployeeA)->salary > ((Employee*)pEmployeeB)->salary){

        return 1;
    }
    if(((Employee*)pEmployeeA)->salary < ((Employee*)pEmployeeB)->salary){

        return -1;
    }
    return 0;
}


void printEmployee(Employee* p){

    printf("| Id: %4d | Nombre: %10s | Apellido: %10s | Salario: %8.2f | Sector: %2d |\r\n",p->id,p->name,p->lastName,p->salary,p->sector);
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector){

    Employee* returnAux = NULL;
    Employee* pEmployee = (void*)malloc(sizeof(Employee));

    if(pEmployee != NULL){

        pEmployee->id = id;
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->lastName,lastName);
        pEmployee->salary = salary;
        pEmployee->sector = sector;
        pEmployee->isEmpty = 0;
        returnAux = pEmployee;
    }

    return returnAux;
}

