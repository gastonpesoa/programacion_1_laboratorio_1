#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayList.h"
#include "Llamada.h"
#include "Parser.h"


/** \brief Open a file for reading, analyze it, load structs with the data readed and
 * add the new element to a list
 * \param pFile (FILE*) Pointer to file
 * \param llamadasList (ArrayList*) Pointer to arrayList
 * \param fileName (char*) Name of the file to be read
 * \return (int) Return (-1) if Error [can't open file, doesn't exists, can't added to the list or read file]
 *                      -(0) if ok
 */
int parserLlamadasListFile(FILE *pFile , ArrayList *llamadasList, char *fileName){

    //Se definen variables auxiliares
    int returnAux = -1;
    int readItem;
    char idStr[256],nombreClienteAux[256],mailAux[256],dniStr[256],productoAux[256],observacionesAux[256];
    int idAux, dniAux;
    int flag = 0;

    //Se verifica que la lista ingresada no sea NULL
    if(llamadasList == NULL){
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
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreClienteAux,mailAux,dniStr,productoAux,observacionesAux);
            flag = 1;
            continue;
        }
        //Se realiza la lectura de los datos
        cleanStdin();
        readItem = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreClienteAux,mailAux,dniStr,productoAux,observacionesAux);
        if(readItem == 6){
            //Si se leyeron todos datos para los campos necesarios del archivo
            //se realiza la conversion de cadena a entero de los datos necesarios
            idAux = atoi(idStr);
            dniAux = atoi(dniStr);
            //Se crea una nueva struct
            Llamada* llamada = llamada_new();
            //Se setean los datos a la struct
            llamada_setId(llamada,idAux,1);
            llamada_setNombreCliente(llamada,nombreClienteAux,1,256);
            llamada_setMail(llamada,mailAux,1,256);
            llamada_setDni(llamada,dniAux,1);
            llamada_setProducto(llamada,productoAux,1,256);
            llamada_setObservaciones(llamada,observacionesAux,1,512);
            //Se agrega la struct a la lista
            if(llamadasList->add(llamadasList,llamada) == -1){
                //En caso de error se informa y se sale retornando valor de error
                printf("\r\nNo se pudo ingresar el nuevo llamadao, verifique espacio en memoria\r\n");
                return returnAux;
            }
            //llamada_print(llamada);
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


/** \brief Open a text file for writing and write the llamadas list passed as argument in it
 * \param pFile (FILE*) Pointer to file
 * \param llamadasList (ArrayList*) Pointer to arrayList
 * \param fileName (char*) Name of the file to be written
 * \return int Return (-1) if Error [can't open file or write it]
 * \                - (0) if Ok
 */
int llamadasListToFile(FILE *pFile, ArrayList *llamadasList, char *fileName){

    //Se definen variables auxiliares
    int returnAux = -1;
    char nombreClienteAux[52],mailAux[52];
    int dniAux, i;

    ArrayList* clientesList = al_newArrayList();

    clientesList = llamadasList->removeDuplicates(llamadasList,llamada_compareByDni);

    Llamada *llamadaAux;

    //Se verifica que la lista ingresada no sea NULL
    if(llamadasList == NULL){
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
    fprintf(pFile, "DNI,nombre,email\n");

    for(i = 0; i < clientesList->len(clientesList); i++){
        //Obtengo el primer elemento de la lista
        llamadaAux = clientesList->get(clientesList,i);
        //Asigno los campos del elemento a las variables auxiliares
        dniAux = llamada_getDni(llamadaAux);
        strcpy(nombreClienteAux,llamada_getNombreCliente(llamadaAux));
        strcpy(mailAux,llamada_getMail(llamadaAux));
        //Se escriben los datos obtenidos en el archivo
        cleanStdin();
        if((fprintf(pFile, "%d,%s,%s\n", dniAux, nombreClienteAux, mailAux)) < 0){
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

