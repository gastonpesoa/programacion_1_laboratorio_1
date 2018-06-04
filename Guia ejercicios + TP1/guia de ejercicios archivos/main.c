//
//  main.c
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

int main(int argc, const char * argv[]) {
    
    EPerson *person = person_newPerson();
    char nameAux[20];
    int ageAux;
    
    askName(nameAux);
    while (!person_setName(person, nameAux, 3, 20)) {
        askName(nameAux);
    }
    
    ageAux = askAge();
    person_setAge(person,ageAux);
    
    printf("El nombre es: %s y la edad: %d\n",person->name,person->age);

    return 0;
}
