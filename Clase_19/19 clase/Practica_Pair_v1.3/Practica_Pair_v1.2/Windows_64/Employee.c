#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "input.h"



int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    return 0;
}


void employee_print(Employee* this){

}


Employee* employee_new(void){

    Employee* returnAux = NULL;

    returnAux = (Employee*)malloc(sizeof(Employee));
    if(returnAux == NULL){
        printf("\nNo queda espacio en memoria");
        exit(1);
    }

    return returnAux;
}

void employee_delete(Employee* this){


}

int employee_setId(Employee* this, int id){

    this->id = id;
    return 0;
}

int employee_setName(Employee* this, char* name){

    this->name = name;
    return 0;
}

int employee_setLastName(Employee* this, char* lastName){

    this->lastName = lastName;
    return 0;
}

int employee_setIsEmpty(Employee* this, int isEmpty){

    this->isEmpty = isEmpty;
    return 0;
}

int employee_getId(Employee* this)
{

    return 0;

}


