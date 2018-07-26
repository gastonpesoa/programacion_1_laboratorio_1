#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Input.h"
#include "Parser.h"
#include "Functions.h"
#include "Usuario.h"
#include "Mensaje.h"



Usuario* user_new(void){

    Usuario* returnAux = NULL;
    returnAux = (Usuario*)malloc(sizeof(Usuario));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}



int user_setId(Usuario* pUsuario, int userId, int lowLimit){

    int returnAux = -1;

    if(userId >= lowLimit){

        pUsuario->userId = userId;
        returnAux = 0;
    }

    return returnAux;
}



int user_setNick(Usuario* pUsuario, char* nick, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(nick, lowLimit, hiLimit)) {

        strcpy(pUsuario->nick,nick);
        returnAux = 0;
    }

    return returnAux;
}



int user_setFollowers(Usuario* pUsuario, int followers, int lowLimit){

    int returnAux = -1;

    if(followers >= lowLimit){

        pUsuario->followers = followers;
        returnAux = 0;
    }

    return returnAux;
}



int user_getId(Usuario* pUsuario){

    return pUsuario->userId;
}



char* user_getNick(Usuario* pUsuario){

    return pUsuario->nick;
}



int user_getFollowers(Usuario* pUsuario){

    return pUsuario->followers;
}



void user_print(Usuario* pUsuario){

    printf("| Id Usuario: %4d | Nick: %20s | Followers: %8d |\r\n",\
        pUsuario->userId,pUsuario->nick,pUsuario->followers);
}



int user_printArrayList(ArrayList* usersList){

    int returnAux = -1;
    int i;
    int cont=1;

    if(!usersList->isEmpty(usersList)){
        for(i=0; i<usersList->len(usersList); i++){

            if(cont %250 == 0){

               system("pause");
            }
            cont++;

            //printf("%4d) ",i);
            user_print(usersList->get(usersList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}


int user_compareByFollowers(void* pUserA,void* pUserB){

    if(((Usuario*)pUserA)->followers > ((Usuario*)pUserB)->followers){

        return 1;
    }
    if(((Usuario*)pUserA)->followers < ((Usuario*)pUserB)->followers){

        return -1;
    }
    return 0;
}

