#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Object.h"
#include "Input.h"



User* user_new(void){

    User* returnAux = NULL;
    returnAux = (User*)malloc(sizeof(User));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}


void user_askName(char *input){

    getValidString("Ingrese el nombre del objeto: ", "El nombre debe ser solo letras", input);

    capitalize(input);
}


void user_askPassword(char *input){

    getValidString("Ingrese el nombre del objeto: ", "El nombre debe ser solo letras", input);

    capitalize(input);
}


int user_setId(User* pUser, int id, int lowLimit){

    int returnAux = -1;

    if(id >= lowLimit){

        pUser->id = id;
        returnAux = 0;
    }

    return returnAux;
}


int user_setName(User* pUser, char* name, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(name, lowLimit, hiLimit)) {

        strcpy(pUser->name,name);
        returnAux = 0;
    }

    return returnAux;
}


int user_setMail(User* pUser, char* mail, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(mail, lowLimit, hiLimit)) {

        strcpy(pUser->mail,mail);
        returnAux = 0;
    }

    return returnAux;
}


int user_setSex(User* pUser, char* sexo, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(sexo, lowLimit, hiLimit)) {

        strcpy(pUser->sexo,sexo);
        returnAux = 0;
    }

    return returnAux;
}


int user_setPais(User* pUser, char* pais, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(pais, lowLimit, hiLimit)) {

        strcpy(pUser->pais,pais);
        returnAux = 0;
    }

    return returnAux;
}


int user_setPassword(User* pUser, char* password, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(password, lowLimit, hiLimit)) {

        strcpy(pUser->password,password);
        returnAux = 0;
    }

    return returnAux;
}


int user_setIp(User* pUser, char* ip, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(ip, lowLimit, hiLimit)) {

        strcpy(pUser->ip,ip);
        returnAux = 0;
    }

    return returnAux;
}


int user_getId(User* pUser){

    return pUser->id;
}


char* user_getName(User* pUser){

    return pUser->name;
}


char* user_getMail(User* pUser){

    return pUser->mail;
}


char* user_getSex(User* pUser){

    return pUser->sexo;
}


char* user_getPais(User* pUser){

    return pUser->pais;
}


char* user_getPassword(User* pUser){

    return pUser->password;
}


char* user_getIp(User* pUser){

    return pUser->ip;
}


int user_compareByName(void* pUserA,void* pUserB){

    if(strcmp(((User*)pUserA)->name,((User*)pUserB)->name) > 0){

        return 1;
    }
    if(strcmp(((User*)pUserA)->name,((User*)pUserB)->name) < 0){

        return -1;
    }
    return 0;
}


int user_compareByPaisName(void* pUserA,void* pUserB){

    if(strcmp(((User*)pUserA)->pais,((User*)pUserB)->pais) > 0){

        return 1;
    }
    if(strcmp(((User*)pUserA)->pais,((User*)pUserB)->pais) < 0){

        return -1;
    }
    else {

        if(strcmp(((User*)pUserA)->name,((User*)pUserB)->name) > 0){

            return 1;
        }
        if(strcmp(((User*)pUserA)->name,((User*)pUserB)->name) < 0){

            return -1;
        }
        return 0;
    }
}


void user_print(User* pUser){

    printf("| Id: %4d | Nombre: %15s | Mail: %40s | Sexo: %6s | Pais: %4s | Password: %40s | Ip: %10s \r\n"\
        ,pUser->id,pUser->name,pUser->mail,pUser->sexo,pUser->pais,pUser->password,pUser->ip);
}


int user_printArrayList(ArrayList* usersList){

    int returnAux = -1;
    int i;
    int cont = 1;

    if(!usersList->isEmpty(usersList)){
        for(i=0; i<usersList->len(usersList); i++){

            if(cont %250 == 0) {
               pause("\r\nPresione ENTER para continuar\r\n");
            }
            cont++;

            printf("%4d) ",i);
            user_print(usersList->get(usersList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}


User *user_requestValidId(ArrayList* usersList){

    User *returnAux = NULL;
    int idAux;
    int indexItem;
    char confirmaIngreso = 'n';
    User *userAux = user_new();

    idAux = getValidInt("\r\nIngrese el Id del objeto a dar de baja logica: ","\r\nEl Id debe ser numerico\r\n",1,1000);
    indexItem = idAux - 1;

    userAux = usersList->get(usersList,indexItem);
    while(userAux == NULL){

        printf("\r\nNo hay ningun objeto registrado con el Id ingresado\r\n");
        confirmaIngreso = confirm("\r\nPresione 's' para volver a ingresar el Id o 'n' para salir: [s|n] ");

        if(confirmaIngreso == 's'){
            idAux = getValidInt("\r\nReingrese el Id del objeto a modificar: ","\r\nEl Id debe ser numerico\r\n",1,1000);
            indexItem = idAux - 1;
            userAux = usersList->get(usersList,indexItem);
        }
        else {
            return returnAux;
        }
    }

    return userAux;
}


