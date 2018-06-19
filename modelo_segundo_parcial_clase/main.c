#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Person.h"
#include "Input.h"
#include "Parser.h"


#define ARCH_1 "destinatarios.csv"
#define ARCH_2 "black_list.csv"
#define ARCH_3 "depurada.csv"


int main(){

    FILE* pDestFile;
    FILE* pBLFile;

    ArrayList* destinatariosList = al_newArrayList();
    if(destinatariosList == NULL){
		printf("\r\nEspacio en memoria insuficiente\r\n");
		return 0;
	}

	ArrayList* blackList = al_newArrayList();
    if(blackList == NULL){
		printf("\r\nEspacio en memoria insuficiente\r\n");
		return 0;
	}

    int opcionMenuPrincipal = 0;
    int i;

    while(opcionMenuPrincipal != 5){

        opcionMenuPrincipal = optionMainMenu();

        switch(opcionMenuPrincipal){

            case 1: //Cargar destinatarios

                printf("\r\nLista destinatarios\r\n");
                if(parserPerson(pDestFile, destinatariosList, ARCH_1) == -1){
                    printf("\r\nError al cargar el archivo\r\n");
                    return 0;
                }

                break;

            case 2: //Cargar lista negra

                printf("\r\nLista negra\r\n");
                if(parserPerson(pBLFile, blackList, ARCH_2) == -1){
                    printf("\r\nError al cargar el archivo\r\n");
                    return 0;
                }

                break;

            case 3: //Depurar

                for(i = 0; i < blackList->len(blackList); i++){

                    if(destinatariosList->contains(destinatariosList, blackList->get(blackList,i)) == 1 ){
                        destinatariosList->remove();
                    }

                }

                break;

            case 4: //Listar

                break;

            case 5: //Salir
                continue;
        }
    }

    return 0;
}
