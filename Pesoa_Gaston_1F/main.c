#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Product.h"
#include "Input.h"
#include "Parser.h"


#define ARCH_1 "dep0.csv"
#define ARCH_2 "dep1.csv"


int main(){

    // Definimos y creamos lista de empleados
    ArrayList* depUnoList = al_newArrayList();
    ArrayList* depDosList = al_newArrayList();

    //Se definen punteros a archivos del tipo FILE
    FILE *pTxtFile = NULL;
    FILE *pDepToTxtFile = NULL;
    FILE *pTxtFileDos = NULL;
    FILE *pDepToTxtFileDos = NULL;

    Product *productAux, *productToMove;

    int depNumOrigin, depNumDest, idProductAux;
    int depListLenght;
    int optionDep;

    int opcionMenuPrincipal = 0;

    while(opcionMenuPrincipal != 6){

        clearScreen();
        opcionMenuPrincipal = optionMainMenu();

        switch(opcionMenuPrincipal){

            case 1: //Cargar deposito
                clearScreen();

                printf("\r\nCargando listas...\r\n");

                if(parserDep(pTxtFile,depUnoList,ARCH_1) == 0 && parserDep(pTxtFileDos,depDosList,ARCH_2) == 0){
	                printf("\nListas cargadas con exito!\r\n");
	                pause("\nPresione enter para volver al menu principal\r\n");
	            }
                else {
                    printf("Error leyando productos\n");
                    pause("\nPresione enter para volver al menu principal\r\n");
                }

                break;

            case 2: //Listar productos de deposito


                while(optionDep != 3){

                    clearScreen();

                    optionDep = optionDepSelect();

                    switch(optionDep){
                        case 1:
                            clearScreen();
                            printf("\r\nDeposito Uno\r\n");
                            product_printArrayList(depUnoList);
                            pause("\nPresione enter para volver\r\n");
                            break;
                        case 2:
                            clearScreen();
                            printf("\r\nDeposito Dos\r\n");
                            product_printArrayList(depDosList);
                            pause("\nPresione enter para volver\r\n");
                            break;
                        case 3:
                            continue;
                    }
                }

                break;

            case 3: //Mover productos a deposito
                clearScreen();
                /*printf("\n\n============================================\
                       \n| *      MOVER PRODUCTOS A DEPOSITO      * |\
                       \n============================================\");*/

                do{
                    depNumOrigin = getValidInt("\nIngrese el numero del deposito origen [1|2]: ","\nLa opcion debe ser numerica\n",1,2);
                    depNumDest = getValidInt("\nIngrese el numero del deposito destino [1|2]: ","\nLa opcion debe ser numerica\n",1,2);

                    if(depNumOrigin == depNumDest){
                        printf("\nDeben ingresarse numeros de deposito origen y destino distintos\n");
                    }
                }while(depNumOrigin == depNumDest);

                depListLenght = depDosList->len(depDosList);

                if(depNumOrigin == 1){
                    product_printArrayList(depUnoList);
                }
                else {
                    product_printArrayList(depDosList);
                }

                if(depNumOrigin == 1){

                    idProductAux = getValidInt("\nIngrese el codigo del producto a mover: ","\nEl codigo debe ser numerico\n",1,5);

                    for(i = 0; i < depUnoList->len(depUnoList); i++){

                        productToMove = depUnoList->get(depUnoList,i);
                        if(productToMove->idProduct == idProductAux){
                            break;
                        }
                    }

                    printf("\nProducto seleccionado: \n");
                    product_print(productToMove);

                    productAux = depUnoList->pop(depUnoList,productAux->idProduct);
                    depDosList->add(depDosList,productAux);

                    depToText(pDepToTxtFile,depUnoList,ARCH_1);

                    printf("\nDep uno\n");
                    product_printArrayList(depUnoList);
                    printf("\nDep uno\n");
                    product_printArrayList(depDosList);
                    pause("\nPresione enter para volver\r\n");
                }
                else {
                    productToMove = depDosList->get(depDosList,idProductAux);

                    printf("\nProducto seleccionado: \n");
                    product_print(productToMove);

                    productAux = depDosList->pop(depDosList,idProductAux);
                    depUnoList->add(depUnoList,productAux);

                    //depToText(pDepToTxtFileDos,depDosList,ARCH_2);

                    printf("\nDep uno");
                    product_printArrayList(depUnoList);
                    printf("\nDep uno");
                    product_printArrayList(depDosList);
                    pause("\nPresione enter para volver\r\n");
                }

                break;

            case 4: //Mostrar lista
                clearScreen();
                /*em_printArrayList(listaEmpleados);
                pause("\r\nPresione enter para volver al menu principal\r\n");*/

                break;

            case 5: //Salir

                continue;
        }// switch(opcionMenuPrincipal)

     }//while(opcionMenuPrincipal != 6)
    return 0;
}
