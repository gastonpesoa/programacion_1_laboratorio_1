#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayList.h"
#include "Entrega.h"
#include "Parser.h"


/** \brief Open a file for reading, analyze it, load structs with the data readed and
 * \add the new element to a list
 * \param pFile (FILE*) Pointer to file
 * \param entregasList (ArrayList*) Pointer to arrayList
 * \param fileName (char*) Name of the file to be read
 * \return (int) Return (-1) if Error [can't open file, doesn't exists, can't added to the list or read file]
 *                      -(0) if ok
 */
int parserEntregasListFile(FILE *pFile , ArrayList *entregasList, char *fileName){

    //Se definen variables auxiliares
    int returnAux = -1;
    int readItem;
    char idStr[52],productoAux[52],direccionAux[52],localidadAux[52],recibeAux[52];
    int idAux;
    int flag = 0;

    //Se verifica que la lista ingresada no sea NULL
    if(entregasList == NULL){
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
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,productoAux,direccionAux,localidadAux,recibeAux);
            flag = 1;
            continue;
        }
        //Se realiza la lectura de los datos
        cleanStdin();
        readItem = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,productoAux,direccionAux,localidadAux,recibeAux);
        if(readItem == 5){
            //Si se leyeron todos datos para los campos necesarios del archivo
            //se realiza la conversion de cadena a entero de los datos necesarios
            idAux = atoi(idStr);
            //Se crea una nueva struct
            Entrega* entrega = entrega_new();
            //Se setean los datos a la struct
            entrega_setId(entrega,idAux,1);
            entrega_setProduct(entrega,productoAux,1,52);
            entrega_setDireccion(entrega,direccionAux,1,52);
            entrega_setLocalidad(entrega,localidadAux,1,52);
            entrega_setRecibe(entrega,recibeAux,1,52);
            //Se agrega la struct a la lista
            if(entregasList->add(entregasList,entrega) == -1){
                //En caso de error se informa y se sale retornando valor de error
                printf("\r\nNo se pudo ingresar el nuevo entregao, verifique espacio en memoria\r\n");
                return returnAux;
            }
            //entrega_print(entrega);
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


/** \brief Write in the file passes as argument the entregas with the localidad passed as argument
 * \param entregasList (ArrayList*) Pointer to arrayList
 * \param localidad (char*) Localidades of the entregas to be writed
 * \param pFile (FILE*) Pointer to file
 * \return (int) Return (-1) if Error [can't open, write the file or doesn't exists]
 *                      -(0) if ok
 */
int imprimirArchivoPorLocalidad(ArrayList* entregasList, char* localidad, FILE *pFile){

    int i, idAux, returnAux = -1;
    char productoAux[51], direccionAux[51], recibeAux[51], localidadAux[51];
    Entrega *entregaAux;

    for(i = 0; i < entregasList->len(entregasList); i++){

        entregaAux = entregasList->get(entregasList,i);

        strcpy(localidadAux,entrega_getLocalidad(entregaAux));
        idAux = entrega_getId(entregaAux);
        strcpy(direccionAux,entrega_getDireccion(entregaAux));
        strcpy(productoAux,entrega_getProduct(entregaAux));
        strcpy(recibeAux,entrega_getRecibe(entregaAux));

        if(!strcmp(localidadAux,localidad)){
            if((fprintf(pFile, "%d,%s,%s,%s,%s,\n", idAux, productoAux, direccionAux, localidadAux, recibeAux)<0)){
                pause("\nError al intentar escribir en el archivo\n\r\nEnter para volver: ");
                return returnAux;
            }
        }
    }
    returnAux = 0;
    return returnAux;
}


/** \brief Request the localidades of the elements to be write and write the entregas with this localidades in the file passes as argument
 * \param pFile (FILE*) Pointer to file
 * \param fileName (char*) Name of the file to be written
 * \param entregasList (ArrayList*) Pointer to arrayList
 * \param localidadesList (ArrayList*) Pointer to arrayList of localidades
 * \return int Return (-1) if Error [can't open file or write it]
 * \                - (0) if Ok
 */
int generarArchivoDeReparto(FILE *pFile, char *fileName, ArrayList* entregasList, ArrayList* localidadesList){

    char localidadUno[51], localidadDos[51], localidadTres[51];
    int returnAux = -1;

    getValidLocalidad(entregasList,localidadesList,"\nIngrese localidad uno: ",localidadUno);
    getValidLocalidad(entregasList,localidadesList,"\nIngrese localidad dos: ",localidadDos);
    getValidLocalidad(entregasList,localidadesList,"\nIngrese localidad tres: ",localidadTres);

    pFile = fopen(fileName,"w");
    if(pFile == NULL){
        pause("\nNo se pudo abrir el archivo\n\r\nEnter para volver: ");
    }
    else{
        fprintf(pFile, "id,producto,direccion,localidad,recibe\n");

        imprimirArchivoPorLocalidad(entregasList,localidadUno, pFile);
        imprimirArchivoPorLocalidad(entregasList,localidadDos, pFile);
        imprimirArchivoPorLocalidad(entregasList,localidadTres, pFile);

        returnAux = 0;
        fclose(pFile);
    }
    return returnAux;
}
