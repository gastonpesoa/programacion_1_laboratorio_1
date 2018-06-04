//
//  person.c
//  guia de ejercicios archivos
//
//  Created by Gaston Pesoa on 03/06/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "person.h"
#include "input.h"

EPerson *person_newPerson(void){
    
    EPerson* person = (EPerson*)malloc(sizeof(EPerson));
    return person;
}


void askName(char input[]){
    
    getValidString("Ingrese el nombre: ", "El nombre debe ser solo letras", input);
    capitalize(input);
}


int askAge(void){
    
    int ageAux;
    
    ageAux = getValidInt("Ingrese la edad: ", "La edad debe ser numerica", 0, 100);
    return ageAux;
}


int person_setName(EPerson *ptrPerson, char nameAux[],int lowLimit,int hiLimit) {
    
    if (!validateStrLenght(nameAux, lowLimit, hiLimit)) {
        return 0;
    }
    
    strcpy(ptrPerson->name,nameAux);
    return 1;
}

void person_setAge(EPerson *ptrPerson, int ageAux){
    
    ptrPerson->age = ageAux;
}

