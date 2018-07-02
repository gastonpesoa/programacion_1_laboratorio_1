#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Object.h"
#include "Input.h"


#define OBJECT_INACTIVE  0
#define OBJECT_ACTIVE  1


void object_testing(ArrayList* objectsList){

    //Hardcodeo de objetos para testing
    Object* object0 = object_newTest(1, "Uno", "uno@mail.com", 10);
    Object* object1 = object_newTest(2, "Dos", "dos@mail.com", 20);
    Object* object2 = object_newTest(3, "Tres", "tres@mail.com", 30);
    Object* object3 = object_newTest(4, "Cuatro", "cuatro@mail.com", 40);
    Object* object4 = object_newTest(5, "Cinco", "cinco@mail.com", 50);

    //Se cargan los objetos al arrayList
    if(objectsList->add(objectsList,object0)==-1){
        printf("\nNo se cargo el objeto");
    }
    if(objectsList->add(objectsList,object1)==-1){
        printf("\nNo se cargo el objeto");
    }
    if(objectsList->add(objectsList,object2)==-1){
        printf("\nNo se cargo el objeto");
    }
    if(objectsList->add(objectsList,object3)==-1){
        printf("\nNo se cargo el objeto");
    }
    if(objectsList->add(objectsList,object4)==-1){
        printf("\nNo se cargo el objeto");
    }
}


Object* object_newTest(int id, char* name,char* mail,int age){

    Object* returnAux = NULL;
    Object* pObject = (Object*)malloc(sizeof(Object));

    if(pObject != NULL){

        pObject->id = id;
        strcpy(pObject->name,name);
        strcpy(pObject->mail,mail);
        pObject->age = age;
        pObject->status = OBJECT_ACTIVE;
        returnAux = pObject;
    }

    return returnAux;
}


Object* object_new(void){

    Object* returnAux = NULL;
    returnAux = (Object*)malloc(sizeof(Object));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}


int object_enter(ArrayList* objectsList,int lowLimitId,int hiLimitId,\
    int lowLimitName,int hiLimitName,\
    int lowLimitMail,int hiLimitMail,int lowLimitAge,int hiLimitAge){

    int returnAux = -1;
    char* nameAux = NULL;
    char* mailAux = NULL;
    int ageAux;

    //Se crea una estructura Object de forma dinámica
    Object* pObject = object_new();
    //Se define nuevo Id para el objecto en funcion del size del arrayList
    int objectIdAux = objectsList->len(objectsList);

    if(object_setId(pObject, objectIdAux, lowLimitId, hiLimitId) == 0){

        object_askName(nameAux);
         while (object_setName(pObject, nameAux, lowLimitName, hiLimitName) == -1) {
            object_askName(nameAux);
        }

        object_askMail(mailAux);
         while (object_setMail(pObject, mailAux, lowLimitMail, hiLimitMail) == -1) {
            object_askMail(mailAux);
        }

        ageAux = object_askAge(lowLimitAge, hiLimitAge);
        object_setAge(pObject, ageAux,1,150);

        object_setStatus(pObject, OBJECT_ACTIVE);

        if(objectsList->add(objectsList, pObject) == -1){

            printf("\r\nNo se pudo ingresar el nuevo objecto, verifique espacio en memoria\r\n");
            pause("\r\nPresione enter para volver al menu principal\r\n");
            return returnAux;
        }

        returnAux = 0;
    }

    return returnAux;
}


void object_askName(char *input){

    getValidString("Ingrese el nombre del objeto: ", "El nombre debe ser solo letras", input);

    capitalize(input);
}


void object_askMail(char *input){

    getValidStringMail("Ingrese el mail del objeto: ","El mail debe contener un '@'", input);
}


int object_askAge(int lowLimit, int hiLimit){

    int ageAux;

    ageAux = getValidInt("Ingrese la edad: ", "La edad debe ser numerica", lowLimit, hiLimit);

    return ageAux;
}


int object_setId(Object* pObject, int id, int lowLimit, int hiLimit){

    int returnAux = -1;

    if(id >= lowLimit && id <= hiLimit){

        pObject->id = id;
        returnAux = 0;
    }

    return returnAux;
}


int object_setName(Object* pObject, char* name, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(name, lowLimit, hiLimit)) {

        strcpy(pObject->name,name);
        returnAux = 0;
    }

    return returnAux;
}


int object_setMail(Object* pObject, char* mail, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(mail, lowLimit, hiLimit)) {

        strcpy(pObject->mail,mail);
        returnAux = 0;
    }

    return returnAux;
}


int object_setAge(Object* pObject, int age, int lowLimit, int hiLimit){

    int returnAux = -1;

    if(age >= lowLimit && age <= hiLimit){

        pObject->age = age;
        returnAux = 0;
    }

    return returnAux;
}


void object_setStatus(Object* pObject, int status){

    pObject->status = status;
}


int object_getId(Object* pObject){

    return pObject->id;
}


char* object_getName(Object* pObject){

    return pObject->name;
}


char* object_getMail(Object* pObject){

    return pObject->mail;
}


int object_getAge(Object* pObject){

    return pObject->age;
}


int object_getStatus(Object* pObject){

    return pObject->status;
}


int object_compareByName(void* pObjectA,void* pObjectB){

    if(strcmp(((Object*)pObjectA)->name,((Object*)pObjectB)->name) > 0){

        return 1;
    }
    if(strcmp(((Object*)pObjectA)->name,((Object*)pObjectB)->name) < 0){

        return -1;
    }
    return 0;
}


int object_compareByMail(void* pObjectA,void* pObjectB){

    if(strcmp(((Object*)pObjectA)->mail,((Object*)pObjectB)->mail) > 0){

        return 1;
    }
    if(strcmp(((Object*)pObjectA)->mail,((Object*)pObjectB)->mail) < 0){

        return -1;
    }
    return 0;
}


int object_compareByAge(void* pObjectA,void* pObjectB){

    if(((Object*)pObjectA)->age > ((Object*)pObjectB)->age){

        return 1;
    }
    if(((Object*)pObjectA)->age < ((Object*)pObjectB)->age){

        return -1;
    }
    return 0;
}


void object_print(Object* pObject){

    printf("| Id: %4d | Nombre: %15s | Mail: %20s | Edad: %4d |\r\n"\
        ,pObject->id,pObject->name,pObject->mail,pObject->age);
}


int object_printArrayList(ArrayList* objectsList){

    int returnAux = -1;
    int i;

    if(!objectsList->isEmpty(objectsList)){
        for(i=0; i<objectsList->len(objectsList); i++){
            printf("%4d) ",i);
            object_print(objectsList->get(objectsList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}


void object_delete(Object* pObject){

    pObject->status = OBJECT_INACTIVE;
}


ArrayList* listDebugger(ArrayList* destList, ArrayList* blackList){

    ArrayList* returnAux = NULL;

    ArrayList* refinedList = al_newArrayList();
    if(refinedList == NULL){
        printf("\r\nEspacio en memoria insuficiente\r\n");
        pause("\r\nPresione enter para salir\r\n");
        return returnAux;
    }

    int i, j, destLenght, blackLenght, returnedValueCompare;

    Object *pObjectDestAux, *pObjectBlackAux;


    destLenght = destList->len(destList);
    blackLenght = blackList->len(blackList);

    for(i = 0; i < destLenght; i++){

        for(j = 0; j < blackLenght; j++){

            pObjectDestAux = destList->get(destList,i);
            pObjectBlackAux = blackList->get(blackList,j);

            returnedValueCompare = object_compareByMail(pObjectDestAux,pObjectBlackAux);

            if(!returnedValueCompare){

                destList->remove(destList,i);
                i = i - 1;
                destLenght = destList->len(destList);
                break;
            }
        }
    }

    refinedList = destList->clone(destList);
    return refinedList;
}

