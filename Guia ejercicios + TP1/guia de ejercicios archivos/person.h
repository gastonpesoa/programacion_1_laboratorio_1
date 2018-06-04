//
//  person.h
//  guia de ejercicios archivos
//
//  Created by Gaston Pesoa on 03/06/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __guia_de_ejercicios_archivos__person__
#define __guia_de_ejercicios_archivos__person__

#include <stdio.h>

#define ACTIVE 1
#define INACTIVE 0

typedef struct{
    char name[10];
    char surname[10];
    int age;
    int personId;
    int status;
} EPerson;

EPerson *person_newPerson(void);

void askName(char input[]);
int askAge(void);

int person_setName(EPerson *ptrPerson, char nameAux[],int hiLimit,int lowLimit);
void person_setAge(EPerson *ptrPerson, int ageAux);

#endif /* defined(__guia_de_ejercicios_archivos__person__) */
