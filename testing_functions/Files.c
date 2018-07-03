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

    strcat(textToWrite,"\n");
    textLenght = strlen(textToWrite);
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
    cleanStdin();
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


ArrayList *file_parserText(FILE *pFile, char *fileName){

    ArrayList *returnAux = NULL;
    int readItem;
    char idStr[256],nameAux[256],mailAux[256],ageStr[256];
    int idAux, ageAux;

    ArrayList *objectsListRead = al_newArrayList();
    if(objectsListRead == NULL){
        printf("\r\nEspacio en memoria insuficiente\r\n");
        pause("\r\nPresione enter para salir\r\n");
        return returnAux;
    }

    pFile = fopen(fileName,"r");
    if (pFile == NULL) {

        printf("\r\nNo se pudo abrir el archivo\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }

    while(!feof(pFile)){

        cleanStdin();
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

            if(al_add(objectsListRead,object) == -1){
                printf("\r\nNo se pudo ingresar el nuevo objecto, verifique espacio en memoria\r\n");
                pause("\r\nEnter para salir: ");
                return returnAux;
            }
        }
        else {

            printf("\r\nNo se leyeron los datos correctamente\n");
            pause("\r\nEnter para salir: ");
            return returnAux;;
        }//if(readItem==4)
    }//while(!feof(pFile))

    printf("\r\nCargando archivo a la lista...\r\n");
    returnAux = objectsListRead;

    fclose(pFile);
    return returnAux;
}


int file_listToText(FILE *pFile, ArrayList *objectsList, char *fileName){

    int returnAux = -1;
    int i, arrayLenght, idAux, ageAux;
    char *nameAux, *mailAux;

    Object *objectAux;

    if((pFile = fopen(fileName,"w+")) == NULL){
        printf("\r\nError al intentar abrir el archivo\r\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }
    
    arrayLenght = objectsList->len(objectsList);

    for(i = 0; i < arrayLenght; i++){

        objectAux = objectsList->get(objectsList,i);

        idAux = objectAux->id;
        nameAux = objectAux->name;
        mailAux = objectAux->mail;
        ageAux = objectAux->age;

        cleanStdin();
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
	//if((pFile = fopen(fileName,"r+b")) == NULL){
		//Si el modo anterior dio error el archivo no existe, por lo tanto se crea
        if((pFile = fopen(fileName,"w+b")) == NULL){
            printf("\r\nError al intentar abrir el archivo\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    //}

    arrayLenght = objectsList->len(objectsList);

    for(i = 0; i < arrayLenght; i++){

        objectAux = objectsList->get(objectsList,i);


        //Me posiciono al final del archivo para agregar datos
    	//fseek(pFile,0L,SEEK_END);
        //Escribo los datos
        cleanStdin();
        qtyReturned = fwrite(objectAux,sizeof(Object),1,pFile);
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


ArrayList *file_binToList(FILE *pFile, char *fileName){

	ArrayList *returnAux = NULL;
	int qtyReturned;

    ArrayList *objectsListBinRead = al_newArrayList();
    if(objectsListBinRead == NULL){
        printf("\r\nEspacio en memoria insuficiente\r\n");
        pause("\r\nPresione enter para salir\r\n");
        return returnAux;
    }

	pFile = fopen(fileName,"rb");
    if (pFile == NULL) {

        printf("\r\nNo se pudo abrir el archivo\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }

	//Me posiciono al comienzo del arch para empezar a leer
    rewind(pFile);

    while(!feof(pFile)){
        //Creamos un nuevo objeto de manera dinamica para cargar los datos
        Object* object = object_new();
        //Leemos y cargamos los datos al objeto creado anteriormente
        cleanStdin();
        qtyReturned = fread(object,sizeof(Object),1,pFile);
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
        //Agregamos el objeto cargado a la lista pasada como argumento
    	if(al_add(objectsListBinRead,object) == -1){
            printf("\r\nNo se pudo ingresar el nuevo objecto, verifique espacio en memoria\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    }
    printf("\r\nCargando archivo a la lista...\r\n");
    returnAux = objectsListBinRead;

    fclose(pFile);
	return returnAux;
}


int file_modifyInBin(FILE *pFile, ArrayList* objectsList, char *fileName){

	int returnAux = -1, flag = 0;
	int idAux, qtyReturned;
    char confirmaModif = 'n', confirmaIngreso = 's';

    //Se verifica que la lista no este vacio y se la muestra para poder seleccionar el Id del objeto a modificar
    if(object_printArrayList(objectsList) == -1){
        printf("\r\nAntes de ingresar esta opcion se debe cargar la lista y guardarla en el archivo\n");
        pause("\r\nPresione Enter para volver al menu principal: ");
        return returnAux;
    }
    //Se solicita el Id del objeto a modificar
    idAux = getValidInt("\r\nIngrese el Id del objeto a modificar: ","\r\nEl Id debe ser numerico\r\n",1,1000);
	//Se abre en modo lectura escritura
	if((pFile = fopen(fileName,"r+b")) == NULL){
		printf("\r\nError al intentar abrir el archivo, verifique que halla sido creado\r\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }

    while(flag == 0 && confirmaIngreso == 's'){
        //Me posiciono al comienzo del arch para empezar a leer
        rewind(pFile);
        //Se recorre el archivo mientras no se llegue al final del mismo
        while(!feof(pFile)){
            //Se crea un nuevo objeto de manera dinamica para cargar los datos y comparar con el Id a ingresar
            Object* object = object_new();
            //Leemos y cargamos los datos al objeto creado anteriormente
            cleanStdin();
            qtyReturned = fread(object,sizeof(Object),1,pFile);
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

            //Se compara Id ingresado con el del objeto leido
            if(object->id == idAux){

                flag = 1;

                printf("\r\nSe encontro\n");
                object_print(object);

                getValidString("\r\nIngrese el nuevo nombre: ","El nombre debe ser solo letras",object->name);
                getValidStringMail("Ingrese el nuevo mail: ","Mail invalido", object->mail);
                object->age = getValidInt("Ingrese la nueva edad: ","La edad debe ser numerica",1,150);

                confirmaModif = confirm("\r\nSe esta por realizar la modificacion, desea continuar? [s|n]: ");

                if(confirmaModif == 's'){

                    //Vuelvo una struct para atras para no mofificar otro objeto
                    fseek(pFile,(long)(-1)*sizeof(Object),SEEK_CUR);

                    //Escribo los datos
                    cleanStdin();
                    qtyReturned = fwrite(object,sizeof(Object),1,pFile);
                    if(qtyReturned != 1){
                        printf("\r\nError al intentar moficar el objeto en el archivo\r\n");
                        pause("\r\nPresione Enter para volver al menu principal: ");
                        return returnAux;
                    }
                    else {
                        printf("\r\nSe modifico el objeto del archivo con exito!!\r\n");
                        //Mostramos la persona agregada
                        object_print(object);
                        pause("\r\nPresione Enter para volver al menu principal: ");
                        returnAux = 0;
                        break;
                    }//if(qtyReturned != 1)
                }
                else {
                    printf("\r\nNo se realizo la modificacion");
                    pause("\r\nPresione Enter para volver al menu principal: ");
                    returnAux = 1;
                    break;
                }////if(confirmaModif == 's')
            }//if(object->id == idAux)
        }//while(!feof(pFile) && flag == 0 && confirmaIngreso == 's')

        if(flag == 0){

            printf("\r\nNo hay ningun objeto registrado con el Id ingresado\r\n");
            confirmaIngreso = confirm("\r\nPresione 's' para volver a ingresar el Id o 'n' para salir: [s|n] ");

            if(confirmaIngreso == 's'){
                idAux = getValidInt("\r\nReingrese el Id del objeto a modificar: ","\r\nEl Id debe ser numerico\r\n",1,1000);
            }
            else {
                returnAux = 1;
                break;
            }
        }//if(flag == 0)
    }//while(flag == 0 && confirmaIngreso == 's')

    fclose(pFile);
	return returnAux;
}


int file_modifyObjectFromBin(FILE *pFile, Object* pObject, char *fileName){

	int returnAux = -1;
	int qtyReturned;
    char confirmaModif = 'n';

	//Se abre en modo lectura escritura
	if((pFile = fopen(fileName,"r+b")) == NULL){

		printf("\r\nError al intentar abrir el archivo\r\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }

    //Me posiciono al comienzo del arch para empezar a leer
    cleanStdin();
    rewind(pFile);

    while(!feof(pFile)){

        Object* object = object_new();

        qtyReturned = fread(object,sizeof(Object),1,pFile);
        if(qtyReturned != 1){

            if(feof(pFile)){
            	break;
            }
            else {
                printf("\r\nError al intentar leer el archivo\r\n");
                pause("\r\nEnter para salir: ");
        		break;
            }
        }

    	if(object->id == pObject->id){

            object = pObject;

            confirmaModif = confirm("\r\nSe esta por realizar la modificacion, desea continuar? [s|n]: ");

            if(confirmaModif == 's'){

                //Vuelvo una struct para atras para no mofificar otro objeto
                fseek(pFile,(long)(-1)*sizeof(Object),SEEK_CUR);

                //Escribo los datos
                cleanStdin();
                qtyReturned = fwrite(object,sizeof(Object),1,pFile);
                if(qtyReturned != 1){
                    printf("\r\nError al intentar moficar el objeto en el archivo\r\n");
                    pause("\r\nEnter para salir: ");
                    break;
                }
                else {
                    printf("\r\nSe modifico el objeto del archivo con exito!!\r\n");
                    object_print(object);
                    returnAux = 0;
                    break;
                }
            }
            else {
                    printf("\r\nNo se realizo la modificacion");
                    pause("\r\nPresione Enter para volver al menu principal: ");
                    returnAux = 1;
                    break;
                }////if(confirmaModif == 's')
        }
    }

	fclose(pFile);
	return returnAux;
}


int file_logicRemove(FILE *pFile, Object* pObject, char *fileName){

    int returnAux = -1;
    int qtyReturned;
    char confirmaModif = 'n';

    //Se abre en modo lectura escritura
    if((pFile = fopen(fileName,"r+b")) == NULL){

        printf("\r\nError al intentar abrir el archivo\r\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }

    //Me posiciono al comienzo del arch para empezar a leer
    cleanStdin();
    rewind(pFile);

    while(!feof(pFile)){

        Object* object = object_new();

        qtyReturned = fread(object,sizeof(Object),1,pFile);
        if(qtyReturned != 1){

            if(feof(pFile)){
                break;
            }
            else {
                printf("\r\nError al intentar leer el archivo\r\n");
                pause("\r\nEnter para salir: ");
                break;
            }
        }

        if(object->id == pObject->id){

            object->status = OBJECT_INACTIVE;
            pObject->status = OBJECT_INACTIVE;

            confirmaModif = confirm("\r\nSe esta por realizar la baja del elemento seleccionado, desea continuar? [s|n]: ");

            if(confirmaModif == 's'){

                //Vuelvo una struct para atras para no mofificar otro objeto
                fseek(pFile,(long)(-1)*sizeof(Object),SEEK_CUR);

                //Escribo los datos
                cleanStdin();
                qtyReturned = fwrite(object,sizeof(Object),1,pFile);
                if(qtyReturned != 1){
                    printf("\r\nError al intentar moficar el objeto en el archivo\r\n");
                    pause("\r\nEnter para salir: ");
                    break;
                }
                else {
                    printf("\r\nSe dio de baja el objeto del archivo con exito!!\r\n");
                    object_print(object);
                    returnAux = 0;
                    break;
                }
            }
            else {
                    printf("\r\nNo se realizo la modificacion");
                    pause("\r\nPresione Enter para volver al menu principal: ");
                    returnAux = 1;
                    break;
                }////if(confirmaModif == 's')
        }
    }

    fclose(pFile);
    return returnAux;
}


/*int file_remove(FILE *pFile, Object* pObject, char *fileName){

}*/
