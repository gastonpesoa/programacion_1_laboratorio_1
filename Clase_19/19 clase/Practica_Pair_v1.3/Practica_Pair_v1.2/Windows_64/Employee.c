#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Employee.h"
#include "input.h"
#include "parser.h"



void askName(char *input){
    
    getValidString("Ingrese el nombre: ", "El nombre debe ser solo letras", input);
    capitalize(input);
}


void askLastName(char *input){
    
    getValidString("Ingrese el apellido: ", "El apellido debe ser solo letras", input);
    capitalize(input);
}


int employee_compare(void* pEmployeeA,void* pEmployeeB){
    
    return 0;
}


void employee_print(Employee* this){
    
    printf("\nEmpleado | Id: %4d | Nombre: %15s | Apellido: %15s | Es vacio: %2d",this->id,this->name,this->lastName,this->isEmpty);
}


void employee_printAll(Employee* this,ArrayList* lista){
    
    int i;
    for (i=0; i<al_len(lista); i++) {
        this = al_get(lista, i);
        employee_print(this);
    }
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
    
    if(id < 1){
        return 1;
    }
    this->id = id;
    return 0;
}


int employee_setName(Employee* this, char* name){
    
    if (!validateStrLenght(name, 1, 51)) {
        return 1;
    }
    strcpy(this->name,name);
    return 0;
}

int employee_setLastName(Employee* this, char* lastName){
    
    if (!validateStrLenght(lastName, 1, 51)) {
        return 1;
    }
    strcpy(this->lastName,lastName);
    return 0;
}

int employee_setIsEmpty(Employee* this, int isEmpty){
    
    if(isEmpty < 0 || isEmpty > 1){
        return 1;
    }
    this->isEmpty = isEmpty;
    return 0;
}


int employee_getId(Employee* this){
    
    return this->id;
}


char *employee_getName(Employee* this){
    
    return this->name;
}


char *employee_getLastName(Employee* this){
    
    return this->lastName;
}


int employee_getIsEmpty(Employee* this){
    
    return this->isEmpty;
}
