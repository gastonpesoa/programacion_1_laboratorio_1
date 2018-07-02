#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Object.h"
#include "Input.h"
#include "Files.h"


int file_writeText(FILE *pFile, char *fileName, char *textToWrite){

	int returnAux = -1;
	int textLenght;
    int qtyReturned;

    //Se abre en modo lectura
    if((pFile = fopen(fileName,"r+")) == NULL){
    	//Si el modo anterior dio error el archivo no existe, por lo tanto se crea
        if((pFile = fopen(fileName,"w+")) == NULL){
            printf("\r\nError al intentar abrir el archivo\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    }

    textLenght = strlen(textToWrite);
    //printf("\r\nEstoy en la funcion y me pasaste: %s lenght: %d\n",textToWrite,textLenght);

    //Me posiciono al final del archivo para agregar datos
    fseek(pFile,0L,SEEK_END);

    //Escribo los datos
    //fprintf(pFile, "%s\n", textToWrite);
    cleanStdin();
    qtyReturned = fwrite(textToWrite,sizeof(char),textLenght,pFile);
    if(qtyReturned != textLenght){

        printf("\r\nError al intentar escribir el texto en el archivo\r\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }
    else {

        returnAux = 0;
    }
    returnAux = 0;
    return returnAux;
}


int file_readText(FILE *pFile, char *fileName, char *readText){

	int returnAux = -1;
	long int textLenght;
	int qtyReturned;

	pFile = fopen(fileName,"r");
    if (pFile==NULL) {

        printf("\r\nNo se pudo abrir el archivo\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }

    //Me posiciono al final del archivo para obtener su longitud
    fseek(pFile,0L,SEEK_END);

    //Obtengo la longitud del archivo
    textLenght = ftell(pFile);

    //Me posiciono al comienzo del archivo para empezar a leer
    rewind(pFile);

    //Leo el texto
    qtyReturned = fread(readText,sizeof(char),textLenght,pFile);
    if(qtyReturned != textLenght){

        if(feof(pFile)){
            printf("\r\nSe llego al final del archivo\r\n");
            returnAux = 0;
        }
        else{
            printf("\r\nError al intentar leer el archivo\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    }

    returnAux = 0;
    fclose(pFile);

    return returnAux;
}


int file_parserText(FILE *pFile, ArrayList *objectsList, char *fileName){

    int returnAux = -1;
    int readItem;
    char idStr[256],nameAux[256],mailAux[256],ageStr[256];
    int idAux, ageAux;

    pFile = fopen(fileName,"r");
    if (pFile==NULL) {

        printf("\r\nNo se pudo abrir el archivo\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }

    while(!feof(pFile)){

        if(pFile == NULL){

            printf("\r\nEl archivo no existe");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }

        readItem = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nameAux,mailAux,ageStr);
        if(readItem == 4){

            idAux = atoi(idStr);
            ageAux = atoi(ageStr);

            Object* object = object_new();

            object_setId(object,idAux,1,1000);
            object_setName(object,nameAux,1,256);
            object_setMail(object,mailAux,1,256);
            object_setAge(object,ageAux,1,150);
            object_setStatus(object,OBJECT_ACTIVE);

            if(al_add(objectsList,object) == -1){
                printf("\r\nNo se pudo ingresar el nuevo objecto, verifique espacio en memoria\r\n");
                pause("\r\nEnter para salir: ");
                return returnAux;
            }

            returnAux = 0;
        }
        else {

            printf("\r\nNo se leyeron los datos correctamente\n");
            pause("\r\nEnter para salir: ");
            return returnAux;;
        }//if(readItem==4)
    }//while(!feof(pFile))

    fclose(pFile);
    return returnAux;
}


int file_listToText(FILE *pFile, ArrayList *objectsList, char *fileName){

    int returnAux = -1;
    int i, arrayLenght, idAux, ageAux;
    char *nameAux, *mailAux;

    Object *objectAux;

    //Se abre en modo lectura
    if((pFile = fopen(fileName,"r+")) == NULL){
    	//Si el modo anterior dio error el archivo no existe, por lo tanto se crea
        if((pFile = fopen(fileName,"w+")) == NULL){
            printf("\r\nError al intentar abrir el archivo\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    }

    arrayLenght = objectsList->len(objectsList);

    for(i = 0; i < arrayLenght; i++){

        objectAux = objectsList->get(objectsList,i);

        idAux = objectAux->id;
        nameAux = objectAux->name;
        mailAux = objectAux->mail;
        ageAux = objectAux->age;

        //Me posiciono al final del archivo para agregar datos
    	fseek(pFile,0L,SEEK_END);

        if((fprintf(pFile, "%d,%s,%s,%d\n", idAux, nameAux, mailAux, ageAux)) < 0){
            printf("\r\nError al intentar escribir la objecta en el archivo\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    }

    fclose(pFile);
    returnAux = 0;
    return returnAux;
}


int file_listToBin(FILE *pFile, ArrayList *objectsList, char *fileName){

	int returnAux = -1;
	int i, arrayLenght, qtyReturned;

    Object *objectAux;

	//Se abre en modo lectura
	if((pFile = fopen(fileName,"r+b")) == NULL){
		//Si el modo anterior dio error el archivo no existe, por lo tanto se crea
        if((pFile = fopen(fileName,"w+b")) == NULL){
            printf("\r\nError al intentar abrir el archivo\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    }

    arrayLenght = objectsList->len(objectsList);

    for(i = 0; i < arrayLenght; i++){

        objectAux = objectsList->get(objectsList,i);

        //Me posiciono al final del archivo para agregar datos
    	fseek(pFile,0L,SEEK_END);

        qtyReturned = fwrite(objectAux,sizeof(objectAux),1,pFile);
        if(qtyReturned != 1){
            printf("\r\nError al intentar escribir la persona en el archivo\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    }

    fclose(pFile);
    returnAux = 0;
	return returnAux;
}


int file_binToList(FILE *pFile, ArrayList *objectsList, char *fileName){

	int returnAux = -1;
	int qtyReturned;

	Object* object = object_new();

	pFile = fopen(fileName,"rb");
    if (pFile==NULL) {

        printf("\r\nNo se pudo abrir el archivo\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }

	//Me posiciono al comienzo del arch para empezar a leer
    rewind(pFile);

    while(!feof(pFile)){

        qtyReturned = fread(object,sizeof(object),1,pFile);
        if(qtyReturned != 1){

            if(feof(pFile)){
            	break;
            }
            else {
                printf("\r\nError al intentar leer el archivo\r\n");
                pause("\r\nEnter para salir: ");
        		return returnAux;
            }
        }

    	if(al_add(objectsList,object) == -1){
            printf("\r\nNo se pudo ingresar el nuevo objecto, verifique espacio en memoria\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    }

    fclose(pFile);
    returnAux = 0;
	return returnAux;
}


int file_modifyInBin(FILE *pFile, ArrayList* objectsList, char *fileName){

	int returnAux = -1;
	int idAux, qtyReturned;
	Object* object = object_new();

    if(object_printArrayList(objectsList) == -1){
        printf("\r\nAntes de ingresar esta opcion se debe cargar la lista\n");
        pause("\r\nPresione Enter para volver al menu principal: ");
        return returnAux;
    }

	idAux = getValidInt("\r\nIngrese el Id del objeto a modificar: ","\r\nEl Id debe ser numerico\r\n",1,1000);

	//Se abre en modo lectura escritura
	if((pFile = fopen(fileName,"r+b")) == NULL){

		printf("\r\nError al intentar abrir el archivo\r\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }

    while(!feof(pFile)){

        qtyReturned = fread(object,sizeof(object),1,pFile);
        if(qtyReturned != 1){

            if(feof(pFile)){
            	break;
            }
            else {
                printf("\r\nError al intentar leer el archivo\r\n");
                pause("\r\nPresione Enter para volver al menu principal: ");
        		return returnAux;
            }
        }

    	if(object->id == idAux){

            printf("\r\nSe encontro: \r\n| Id: %4d | Nombre: %12s | Mail: %20s | Edad: %3d |",object->id,object->name,object->mail,object->age);

            getValidString("Ingrese el nuevo nombre: ","El nombre debe ser solo letras",object->name);
            getValidStringMail("Ingrese el nuevo mail: ","El mail debe contener un '@'", object->mail);
            object->age = getValidInt("Ingrese la nueva edad: ","La edad debe ser numerica",1,150);

            //Vuelvo una struct para atras para no mofificar otro objeto
            fseek(pFile,(long)(-1)*sizeof(object),SEEK_CUR);

            //Escribo los datos
            cleanStdin();
            qtyReturned = fwrite(object,sizeof(object),1,pFile);
            if(qtyReturned != 1){
                printf("\r\nError al intentar moficar el objeto en el archivo\r\n");
                pause("\r\nPresione Enter para volver al menu principal: ");
        		return returnAux;
            }
            else {
                printf("\r\nSe modifico el objeto del archivo con exito!!\r\n");
            }
            //Mostramos la persona agregada
            printf("\r\nSe modifico: \r\n| Id: %4d | Nombre: %12s | Mail: %20s | Edad: %3d |",object->id,object->name,object->mail,object->age);
        }
        else{
            printf("\r\nNo hay ningun objeto registrado con el Id ingresado\r\n");
            pause("\r\nPresione Enter para volver al menu principal: ");
            return returnAux;
        }
    }

    fclose(pFile);
    returnAux = 0;
	return returnAux;
}


int file_modifyObjectFromBin(FILE *pFile, Object* pObject, char *fileName){

	int returnAux = -1;
	int qtyReturned;
	Object* object = object_new();

	//Se abre en modo lectura escritura
	if((pFile = fopen(fileName,"r+b")) == NULL){

		printf("\r\nError al intentar abrir el archivo\r\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }

    while(!feof(pFile)){

        qtyReturned = fread(object,sizeof(object),1,pFile);
        if(qtyReturned != 1){

            if(feof(pFile)){
            	break;
            }
            else {
                printf("\r\nError al intentar leer el archivo\r\n");
                pause("\r\nEnter para salir: ");
        		return returnAux;
            }
        }

    	if(object->id == pObject->id){

            //Vuelvo una struct para atras para no mofificar otro objeto
            fseek(pFile,(long)(-1)*sizeof(object),SEEK_CUR);

            //Escribo los datos
            cleanStdin();
            qtyReturned = fwrite(object,sizeof(object),1,pFile);
            if(qtyReturned != 1){
                printf("\r\nError al intentar moficar el objeto en el archivo\r\n");
                pause("\r\nEnter para salir: ");
        		return returnAux;
            }
            else {
                printf("\r\nSe modifico el objeto del archivo con exito!!\r\n");
            }
        }
    }

	fclose(pFile);
    returnAux = 0;
	return returnAux;
}
