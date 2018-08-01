#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Entrega.h"
#include "Input.h"
#include "Parser.h"



Entrega* entrega_new(void){

    Entrega* returnAux = NULL;
    returnAux = (Entrega*)malloc(sizeof(Entrega));

    if(returnAux == NULL){
        printf("\r\nNo queda espacio en memoria\r\n");
        return returnAux;
    }
    return returnAux;
}



int entrega_setId(Entrega* pEntrega, int entregaId, int lowLimit){

    int returnAux = -1;

    if(entregaId >= lowLimit){

        pEntrega->entregaId = entregaId;
        returnAux = 0;
    }

    return returnAux;
}



int entrega_setProduct(Entrega* pEntrega, char* producto, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(producto, lowLimit, hiLimit)) {

        strcpy(pEntrega->producto,producto);
        returnAux = 0;
    }

    return returnAux;
}


int entrega_setDireccion(Entrega* pEntrega, char* direccion, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(direccion, lowLimit, hiLimit)) {

        strcpy(pEntrega->direccion,direccion);
        returnAux = 0;
    }

    return returnAux;
}


int entrega_setLocalidad(Entrega* pEntrega, char* localidad, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(localidad, lowLimit, hiLimit)) {

        strcpy(pEntrega->localidad,localidad);
        returnAux = 0;
    }

    return returnAux;
}


int entrega_setRecibe(Entrega* pEntrega, char* recibe, int lowLimit, int hiLimit){

    int returnAux = -1;

    if (validateStrLenght(recibe, lowLimit, hiLimit)) {

        strcpy(pEntrega->recibe,recibe);
        returnAux = 0;
    }

    return returnAux;
}



int entrega_getId(Entrega* pEntrega){

    return pEntrega->entregaId;
}



char* entrega_getProduct(Entrega* pEntrega){

    return pEntrega->producto;
}


char* entrega_getDireccion(Entrega* pEntrega){

    return pEntrega->direccion;
}

char* entrega_getLocalidad(Entrega* pEntrega){

    return pEntrega->localidad;
}


char* entrega_getRecibe(Entrega* pEntrega){

    return pEntrega->recibe;
}



void entrega_print(Entrega* pEntrega){

    printf("| Id: %4d | Producto: %20s | Direccion: %30s | Localidad: %20s | Recibe: %20s |\r\n",\
        pEntrega->entregaId,pEntrega->producto,pEntrega->direccion,pEntrega->localidad,pEntrega->recibe);
}

void entrega_printLocalidad(Entrega* pEntrega){

    printf("| Localidad: %20s |\r\n",pEntrega->localidad);
}


int entrega_printLocalidadesList(ArrayList* entregasList){

    int returnAux = -1;
    int i;
    int cont=1;

    if(!entregasList->isEmpty(entregasList)){
        for(i=0; i<entregasList->len(entregasList); i++){

            if(cont %250 == 0){

               system("pause");
            }
            cont++;

            //printf("%4d) ",i);
            entrega_printLocalidad(entregasList->get(entregasList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}

int entrega_printArrayList(ArrayList* entregasList){

    int returnAux = -1;
    int i;
    int cont=1;

    if(!entregasList->isEmpty(entregasList)){
        for(i=0; i<entregasList->len(entregasList); i++){

            if(cont %250 == 0){

               system("pause");
            }
            cont++;

            //printf("%4d) ",i);
            entrega_print(entregasList->get(entregasList,i));
        }
        returnAux = 0;
    }
    return returnAux;
}


int entrega_compareByLocalidad(void* pEntregaA,void* pEntregaB){

    if(strcmp(((Entrega*)pEntregaA)->localidad,((Entrega*)pEntregaB)->localidad) > 0){

        return 1;
    }
    if(strcmp(((Entrega*)pEntregaA)->localidad,((Entrega*)pEntregaB)->localidad) < 0){

        return -1;
    }
    return 0;
}

