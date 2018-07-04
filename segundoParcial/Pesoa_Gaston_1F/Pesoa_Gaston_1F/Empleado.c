#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Input.h"

void em_calcularSueldo(void* p)
{
    int hsAux = em_getHs(((Empleado*)p));
    int sueldo;

    if(hsAux <= 176){
        sueldo = hsAux*180;
    }
    else {
        if(hsAux > 176 && hsAux <= 208){
            sueldo = hsAux*270;
        }
        if(hsAux > 208){
            sueldo = hsAux*360;
        }
    }
    em_setSueldo(((Empleado*)p),sueldo,1);
}

Empleado* em_new(void){

    Empleado* returnAux = NULL;
    returnAux = (Empleado*)malloc(sizeof(Empleado));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}

int em_setId(Empleado* pEmpleado, int id, int lowLimit){

    int returnAux = -1;

    if(id >= lowLimit){

        pEmpleado->id = id;
        returnAux = 0;
    }

    return returnAux;
}


int em_setName(Empleado* pEmpleado, char* name, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(name, lowLimit, hiLimit)) {

        strcpy(pEmpleado->nombre,name);
        returnAux = 0;
    }

    return returnAux;
}


int em_setHs(Empleado* pEmpleado, int horasTrabajadas, int lowLimit){

    int returnAux = -1;

    if(horasTrabajadas >= lowLimit){

        pEmpleado->horasTrabajadas = horasTrabajadas;
        returnAux = 0;
    }

    return returnAux;
}

int em_setSueldo(Empleado* pEmpleado, int sueldo, int lowLimit){

    int returnAux = -1;

    if(sueldo >= lowLimit){

        pEmpleado->sueldo = sueldo;
        returnAux = 0;
    }

    return returnAux;
}


int em_getId(Empleado* pEmpleado){

    return pEmpleado->id;
}


char* em_getName(Empleado* pEmpleado){

    return pEmpleado->nombre;
}


int em_getHs(Empleado* pEmpleado){

    return pEmpleado->horasTrabajadas;
}


int em_getSueldo(Empleado* pEmpleado){

    return pEmpleado->sueldo;
}


void em_print(Empleado* pEmpleado){

    printf("| Id: %4d | Nombre: %15s | Hs: %7d | Sueldo: %7d |\r\n"\
        ,pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas,pEmpleado->sueldo);
}


int em_printArrayList(ArrayList* empList){

    int returnAux = -1;
    int i;
    int cont=1;

    if(!empList->isEmpty(empList)){
        for(i=0; i<empList->len(empList); i++){

            if(cont %250 == 0)
            {
               system("pause");
            }
            cont++;

            printf("%4d) ",i);
            em_print(empList->get(empList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}
