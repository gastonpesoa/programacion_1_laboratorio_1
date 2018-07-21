#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Product.h"
#include "Input.h"
#include "Parser.h"
#include "Functions.h"


#define ARCH_1 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_final_2/modelo_final_2/dep0.csv"
#define ARCH_2 "/Volumes/Almacen/UTN/Programacion I/Practicas/modelo_final_2/modelo_final_2/dep1.csv"


int main(){

    //Definimos y creamos lista de depositos
    ArrayList* depositUnoList = al_newArrayList();
    ArrayList* depositDosList = al_newArrayList();
    if(depositUnoList == NULL || depositDosList == NULL){
        printf("\nEspacio en memoria insuficiente\n");
        pause("\nPresione enter para salir\r\n");
        return 0;
    }

    //Se definen punteros a archivos del tipo FILE
    FILE *pDepositUnoFile = NULL;
    FILE *pDepositDosFile = NULL;

    //Se definen variables auxiliares del tipo Product
    Product *productToMove, *productToModifyStock;

    //Se definen variables de tipo int y char
    int rtrnParserFileUno, rtrnParserFileDos;
    int depositOrigen;
    int stockAux, qtyToDiscount, qtyToAdd;

    int opcionMenuPrincipal = 0, optionDeposit = 0;
    char confirma = 'n';

    //Menu principal
    while(opcionMenuPrincipal != 6){

        clearScreen();
        opcionMenuPrincipal = optionMainMenu();

        switch(opcionMenuPrincipal){

            case 1://Cargar lista de depositos

                clearScreen();

                //Se verifica que las listas esten vacias antes de cargarlas
                if(depositUnoList->isEmpty(depositUnoList) && depositDosList->isEmpty(depositDosList)){

                    printf("\r\nCargando listas...\r\n");
                    rtrnParserFileUno = parserProductsListFile(pDepositUnoFile,depositUnoList,ARCH_1);
                    rtrnParserFileDos = parserProductsListFile(pDepositDosFile,depositDosList,ARCH_2);

                    if(rtrnParserFileUno == 0 && rtrnParserFileDos == 0){
                        printf("\nListas cargadas con exito!\r\n");
                        pause("\nPresione enter para volver al menu principal\r\n");
                    }
                    else {
                        printf("Error leyando productos\n");
                        pause("\nPresione enter para volver al menu principal\r\n");
                    }
                }
                else{
                    printf("\r\nLas listas de los depositos ya estan cargadas\n");
                    pause("\nPresione enter para volver al menu principal\r\n");
                }
                break;

            case 2://Listar productos de depositos

                optionDeposit = 0;
                while(optionDeposit != 3){

                    clearScreen();

                    optionDeposit = optionDepositSelect();

                    switch(optionDeposit){

                        case 1://Lista deposito uno
                            clearScreen();
                            printf("\r\nDeposito Uno\r\n");
                            product_printArrayList(depositUnoList);
                            pause("\nPresione enter para volver\r\n");
                            break;

                        case 2://Lista deposito dos
                            clearScreen();
                            printf("\r\nDeposito Dos\r\n");
                            product_printArrayList(depositDosList);
                            pause("\nPresione enter para volver\r\n");
                            break;

                        case 3://Vuelve al menu principal
                            continue;
                    }
                }
                break;

            case 3://Mover productos a deposito

                clearScreen();
                printf("\n\n============================================\
                          \n| *      MOVER PRODUCTOS A DEPOSITO      * |\
                          \n============================================");

                //Se solicitan y validan numeros de deposito origen y destino
                depositOrigen = getValidDesposit();

                if(depositOrigen == 1){//Deposito Uno

                    //Se solicita y valida el codigo del producto a mover
                    productToMove = getValidProduct(depositUnoList);
                    clearScreen();
                    //Se muestra el producto seleccionado
                    printf("\nSe selecciono el producto: \n");
                    product_print(productToMove);
                    //Se solicita confirmar el traslado del producto
                    confirma = confirm("\r\nSe esta por mover el producto seleccionado al deposito dos, confirma el traslado? [s|n]: ");
                    if(confirma == 's'){
                        //Se elimina el producto del deposito origen y se lo agrega al deposito destino
                        moveProductToDeposit(depositUnoList,depositDosList,productToMove);
                        //Se escriben las modificaciones en los archivos
                        productsListToFile(pDepositUnoFile,depositUnoList,ARCH_1);
                        productsListToFile(pDepositDosFile,depositDosList,ARCH_2);
                        clearScreen();
                        printf("\r\nSe movio el producto con exito y se modificaron los archivos correspondientes\n");
                        pause("");
                    }
                    else{
                        clearScreen();
                        printf("\r\nNo se movio el producto\n");
                        pause("");
                    }
                }
                else {//Si el deposito origen es el Dos
                    //Se solicita y valida el codigo del producto a mover
                    productToMove = getValidProduct(depositDosList);
                    clearScreen();
                    //Se muestra el producto seleccionado
                    printf("\nSe selecciono el producto: \n");
                    product_print(productToMove);
                    //Se solicita confirmar el traslado del producto
                    confirma = confirm("\r\nSe esta por mover el producto seleccionado al deposito uno, confirma el traslado? [s|n]: ");
                    if(confirma == 's'){
                        //Se elimina el producto del deposito origen y se lo agrega al deposito destino
                        moveProductToDeposit(depositDosList,depositUnoList,productToMove);
                        //Se escriben las modificaciones en los archivos
                        productsListToFile(pDepositUnoFile,depositUnoList,ARCH_1);
                        productsListToFile(pDepositDosFile,depositDosList,ARCH_2);
                        clearScreen();
                        printf("\r\nSe movio el producto con exito y se modificaron los archivos correspondientes\n");
                        pause("");
                    }
                    else{
                        clearScreen();
                        printf("\r\nNo se movio el producto\n");
                        pause("");
                    }
                }
                pause("\nPresione enter para volver al menu principal\r");
                break;

            case 4://Descontar productos de deposito

                clearScreen();
                printf("\n\n=================================================\
                          \n| *      DESCONTAR PRODUCTOS DE DEPOSITO      * |\
                          \n=================================================");

                optionDeposit = getValidInt("\nIngrese el numero del deposito que contiene el producto a descontar stock: ","\nLa opcion debe ser numerica\n",1,2);

                if(optionDeposit == 1){//Deposito Uno

                    //Se solicita y valida el codigo del producto a descontar stock
                    productToModifyStock = getValidProduct(depositUnoList);
                    clearScreen();
                    //Se muestra el producto seleccionado
                    printf("\nSe selecciono el producto: \n");
                    product_print(productToModifyStock);
                    //Se obtiene el stock del producto y se solicita la cantidad a descontar
                    stockAux = product_getStock(productToModifyStock);
                    qtyToDiscount = getValidInt("\r\nIngrese la cantidad de producto a descontar: ","\r\nLa cantidad debe ser numerica\r\n",1,stockAux);
                    //Se solicita confirmar el descuento del stock del producto
                    confirma = confirm("\r\nSe esta por descontar la cantidad ingresada del producto seleccionado, confirma el decuento? [s|n]: ");
                    if(confirma == 's'){
                        //Se descuenta la cantidad ingresada al stock del producto y se modifica el archivo
                        discountProductStock(stockAux, qtyToDiscount, productToModifyStock);
                        clearScreen();
                        productsListToFile(pDepositUnoFile,depositUnoList,ARCH_1);
                        printf("\r\nSe desconto la cantidad ingresada del producto con exito y se modifico el archivo correspondientes\n");
                        product_print(productToModifyStock);
                        pause("");
                    }
                    else{
                        clearScreen();
                        printf("\r\nNo se desconto el producto\n");
                        pause("");
                    }
                }
                else{//Deposito Dos

                    //Se solicita y valida el codigo del producto a descontar stock
                    productToModifyStock = getValidProduct(depositDosList);
                    clearScreen();
                    //Se muestra el producto seleccionado
                    printf("\nSe selecciono el producto: \n");
                    product_print(productToModifyStock);
                    //Se obtiene el stock del producto y se solicita la cantidad a descontar
                    stockAux = product_getStock(productToModifyStock);
                    qtyToDiscount = getValidInt("\r\nIngrese la cantidad de producto a descontar: ","\r\nLa cantidad debe ser numerica\r\n",1,stockAux);
                    //Se solicita confirmar el descuento del stock del producto
                    confirma = confirm("\r\nSe esta por descontar la cantidad ingresada del producto seleccionado, confirma el decuento? [s|n]: ");
                    if(confirma == 's'){
                        //Se descuenta la cantidad ingresada al stock del producto y se modifica el archivo
                        discountProductStock(stockAux, qtyToDiscount, productToModifyStock);
                        productsListToFile(pDepositDosFile,depositDosList,ARCH_2);
                        clearScreen();
                        printf("\r\nSe desconto la cantidad ingresada del producto con exito y se modifico el archivo correspondientes\n");
                        product_print(productToModifyStock);
                        pause("");
                    }
                    else{
                        clearScreen();
                        printf("\r\nNo se desconto el producto\n");
                        pause("");
                    }
                }
                pause("\r\nPresione enter para volver al menu principal\r\n");
                break;

            case 5://Agregar productos a deposito

                clearScreen();
                printf("\n\n=================================================\
                          \n|   *      AGREGAR PRODUCTOS A DEPOSITO      *  |\
                          \n=================================================");
                
                optionDeposit = getValidInt("\nIngrese el numero del deposito que contiene el producto a agregar stock: ","\nLa opcion debe ser numerica\n",1,2);

                if(optionDeposit == 1){//Deposito Uno

                    //Se solicita y valida el codigo del producto a agregar stock
                    productToModifyStock = getValidProduct(depositUnoList);
                    clearScreen();
                    //Se muestra el producto seleccionado
                    printf("\nSe selecciono el producto: \n");
                    product_print(productToModifyStock);
                    //Se obtiene el stock del producto y se solicita la cantidad a agregar
                    stockAux = product_getStock(productToModifyStock);
                    qtyToAdd = getValidInt("\r\nIngrese la cantidad de producto a agregar: ","\r\nLa cantidad debe ser numerica\r\n",1,99999999999999);
                    //Se solicita confirmar el aumento del stock del producto
                    confirma = confirm("\r\nSe esta por agregar la cantidad ingresada del producto seleccionado, confirma el aumento? [s|n]: ");
                    if(confirma == 's'){
                        //Se agrega la cantidad ingresada al stock del producto y se modifica el archivo
                        addProductStock(stockAux,qtyToAdd,productToModifyStock);
                        productsListToFile(pDepositUnoFile,depositUnoList,ARCH_1);
                        clearScreen();
                        printf("\r\nSe agrego la cantidad ingresada del producto con exito y se modifico el archivo correspondientes\n");
                        product_print(productToModifyStock);
                        pause("");
                    }
                    else{
                        clearScreen();
                        printf("\r\nNo se agrego el producto\n");
                        pause("");
                    }
                }
                else{//Deposito Dos

                    //Se solicita y valida el codigo del producto a agregar stock
                    productToModifyStock = getValidProduct(depositDosList);
                    clearScreen();
                    //Se muestra el producto seleccionado
                    printf("\nSe selecciono el producto: \n");
                    product_print(productToModifyStock);
                    //Se obtiene el stock del producto y se solicita la cantidad a agregar
                    stockAux = product_getStock(productToModifyStock);
                    qtyToAdd = getValidInt("\r\nIngrese la cantidad de producto a agregar: ","\r\nLa cantidad debe ser numerica\r\n",1,9999999999999999);
                    //Se solicita confirmar el aumento del stock del producto
                    confirma = confirm("\r\nSe esta por agregar la cantidad ingresada del producto seleccionado, confirma el aumento? [s|n]: ");
                    if(confirma == 's'){
                        //Se agrega la cantidad ingresada al stock del producto y se modifica el archivo
                        addProductStock(stockAux,qtyToAdd,productToModifyStock);
                        productsListToFile(pDepositDosFile,depositDosList,ARCH_2);
                        clearScreen();
                        printf("\r\nSe agrego la cantidad ingresada del producto con exito y se modifico el archivo correspondientes\n");
                        product_print(productToModifyStock);
                        pause("");
                    }
                    else{
                        clearScreen();
                        printf("\r\nNo se agrego el producto\n");
                        pause("");
                    }
                }
                pause("\r\nPresione enter para volver al menu principal\r\n");
                break;

            case 6://Salir

                continue;

        }// switch(opcionMenuPrincipal)
    }//while(opcionMenuPrincipal != 6)

    //Se eliminan las listas de memoria y se cierra el programa
    depositUnoList->deleteArrayList(depositUnoList);
    depositDosList->deleteArrayList(depositDosList);

    return 0;
}
