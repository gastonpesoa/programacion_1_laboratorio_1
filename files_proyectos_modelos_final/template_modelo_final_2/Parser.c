#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayList.h"
#include "Product.h"
#include "Parser.h"


/** \brief Open a file for reading, analyze it, load structs with the data readed and
 * \add the new element to a list
 * \param pFile (FILE*) Pointer to file
 * \param productsList (ArrayList*) Pointer to arrayList
 * \param fileName (char*) Name of the file to be read
 * \return (int) Return (-1) if Error [can't open file, doesn't exists, can't added to the list or read file]
 *                      -(0) if ok
 */
int parserProductsListFile(FILE *pFile , ArrayList *productsList, char *fileName){

    //Se definen variables auxiliares
    int returnAux = -1;
    int readItem;
    char idStr[52],descripcionAux[52],direccionAux[52],localidadAux[52],recibeAux[52];
    int idAux;
    int flag = 0;

    //Se verifica que la lista ingresada no sea NULL
    if(productsList == NULL){
        //En caso de lista NULL se informa y se sale retornando valor de Error
        printf("\r\nError, lista nula\r\n");
        pause("\r\nPresione enter para volver\r\n");
        return returnAux;
    }
    //Se abre el archivo, pasado como parametro, para lectura de texto
    //y se asigna puntero al archivo devuelto, al puntero pFile pasado como paramentro
    pFile = fopen(fileName,"r");
    if (pFile==NULL) {
        //Si fopen devuelve NULL se informa y se sale de la funcion retornando valor de error
        pause("\nNo se pudo abrir el archivo\n\r\nEnter para volver: ");
        return returnAux;
    }
    //Mientras no se llegue al final del archivo lo sigo recorriendo
    while(!feof(pFile)){
        //La primer linea que se lea del archivo es la cabecera por lo que no la agrego a la lista
        if(flag == 0){
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,descripcionAux,direccionAux,localidadAux,recibeAux);
            flag = 1;
            continue;
        }
        //Se realiza la lectura de los datos
        cleanStdin();
        readItem = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,descripcionAux,direccionAux,localidadAux,recibeAux);
        if(readItem == 5){
            //Si se leyeron todos datos para los campos necesarios del archivo
            //se realiza la conversion de cadena a entero de los datos necesarios
            idAux = atoi(idStr);
            //Se crea una nueva struct
            Product* product = product_new();
            //Se setean los datos a la struct
            product_setId(product,idAux,1);
            product_setDescripcion(product,descripcionAux,1,52);
            product_setDireccion(product,direccionAux,1,52);
            product_setLocalidad(product,localidadAux,1,52);
            product_setRecibe(product,recibeAux,1,52);
            //Se agrega la struct a la lista
            if(productsList->add(productsList,product) == -1){
                //En caso de error se informa y se sale retornando valor de error
                printf("\r\nNo se pudo ingresar el nuevo producto, verifique espacio en memoria\r\n");
                return returnAux;
            }
            //product_print(product);
            //Si se realizo el parser correctamente se asigna valor de retorno Ok
            returnAux = 0;
        }
        else {
            //Si no se leyeron los datos necesarios se informa error y se sale retornando valor de error
            printf("\r\nNo se leyeron los datos correctamente\n");
            pause("\r\nEnter para salir: ");
            return returnAux;;
        }//if(readItem==4)
    }//while(!feof(pFile))
    //Si se recorrio todo el archivo y se cargaron todos los datos
    //Se cierra el archivo y se retorna valor de Ok
    fclose(pFile);
    return returnAux;
}


/** \brief Open a text file for writing and write the products list passed as argument in it
 * \param pFile (FILE*) Pointer to file
 * \param productsList (ArrayList*) Pointer to arrayList
 * \param fileName (char*) Name of the file to be written
 * \return int Return (-1) if Error [can't open file or write it] 
 * \                - (0) if Ok
 */
int productsListToFile(FILE *pFile, ArrayList *productsList, char *fileName){
    
    //Se definen variables auxiliares
    int returnAux = -1;
    int i, idAux, stockAux;
    char *descriptionAux;

    Product *productAux;

    //Se verifica que la lista ingresada no sea NULL
    if(productsList == NULL){
        //En caso de lista NULL se informa y se sale retornando valor de Error
        printf("\r\nError, lista nula\r\n");
        pause("\r\nPresione enter para volver\r\n");
        return returnAux;
    }
    //Se abre el archivo, pasado como parametro, para escribir texto
    //y se asigna puntero al archivo devuelto, al puntero pFile pasado como paramentro
    if((pFile = fopen(fileName,"w+")) == NULL){
        //Si fopen devuelve NULL se informa y se sale de la funcion retornando valor de error
        printf("\r\nError al intentar abrir el archivo\r\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }
    //Se escribe cabecera del archivo
    cleanStdin();
    fprintf(pFile, "producto,descripcion,cantidad\n");

    for(i = 0; i < productsList->len(productsList); i++){
        //Obtengo el primer elemento de la lista
        productAux = productsList->get(productsList,i);
        //Asigno los campos del elemento a las variables auxiliares
        idAux = product_getId(productAux); 
        strcpy(descriptionAux,product_getDescripcion(productAux));
        stockAux = product_getStock(productAux);
        //Se escriben los datos obtenidos en el archivo
        cleanStdin();
        if((fprintf(pFile, "%d,%s,%d\n", idAux, descriptionAux, stockAux)) < 0){
            //En caso de error al escribir los datos se informa y se sale retornando valor de Error
            printf("\r\nError al intentar escribir la objecta en el archivo\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    }
    //Si se recorrio toda la lista y se escribieron todos los datos 
    //Se cierra el archivo y se sale retornando valor de Ok
    fclose(pFile);
    returnAux = 0;
    return returnAux;
}


/** \brief Write in the file passes as argument the products with the localidad passed as argument
 * \param productsList (ArrayList*) Pointer to arrayList
 * \param localidad (char*) Localidades of the products to be writed
 * \param pFile (FILE*) Pointer to file
 * \return (int) Return (-1) if Error [can't open, write the file or doesn't exists]
 *                      -(0) if ok
 */
int imprimirArchivoPorLocalidad(ArrayList* productsList, char* localidad, FILE *pFile){

    int i, idAux, returnAux = -1;
    char descripcionAux[51], direccionAux[51], recibeAux[51], localidadAux[51];
    Product *productAux;

    for(i = 0; i < productsList->len(productsList); i++){

        productAux = productsList->get(productsList,i);

        strcpy(localidadAux,product_getLocalidad(productAux));
        idAux = product_getId(productAux);
        strcpy(direccionAux,product_getDireccion(productAux));
        strcpy(descripcionAux,product_getDescripcion(productAux));
        strcpy(recibeAux,product_getRecibe(productAux));

        if(!strcmp(localidadAux,localidad)){
            if((fprintf(pFile, "%d,%s,%s,%s,%s,\n", idAux, descripcionAux, direccionAux, localidadAux, recibeAux)<0)){
                pause("\nError al intentar escribir en el archivo\n\r\nEnter para volver: ");
                return returnAux;
            }
        }
    }
    returnAux = 0;
    return returnAux;
}


/** \brief Request the localidades of the elements to be write and write the products with this localidades in the file passes as argument
 * \param pFile (FILE*) Pointer to file
 * \param fileName (char*) Name of the file to be written
 * \param productsList (ArrayList*) Pointer to arrayList
 * \param localidadesList (ArrayList*) Pointer to arrayList of localidades
 * \return int Return (-1) if Error [can't open file or write it]
 * \                - (0) if Ok
 */
int generarArchivoDeReparto(FILE *pFile, char *fileName, ArrayList* productsList, ArrayList* localidadesList){

    char localidadUno[51], localidadDos[51], localidadTres[51];
    int returnAux = -1;

    getValidLocalidad(productsList,localidadesList,"\nIngrese localidad uno: ",localidadUno);
    getValidLocalidad(productsList,localidadesList,"\nIngrese localidad dos: ",localidadDos);
    getValidLocalidad(productsList,localidadesList,"\nIngrese localidad tres: ",localidadTres);

    pFile = fopen(fileName,"w");
    if(pFile == NULL){
        pause("\nNo se pudo abrir el archivo\n\r\nEnter para volver: ");
    }
    else{
        fprintf(pFile, "id,producto,direccion,localidad,recibe\n");

        imprimirArchivoPorLocalidad(productsList,localidadUno, pFile);
        imprimirArchivoPorLocalidad(productsList,localidadDos, pFile);
        imprimirArchivoPorLocalidad(productsList,localidadTres, pFile);

        returnAux = 0;
        fclose(pFile);
    }
    return returnAux;
}

