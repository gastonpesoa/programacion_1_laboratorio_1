#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Object.h"
#include "Song.h"
#include "Reproduction.h"
#include "Input.h"
#include "Files.h"


int file_listToBin(ArrayList *list, char *fileName){

	int returnAux = -1;
	int i, arrayLenght, qtyReturned;
    FILE *pFile;

    Reproduction* repAux;

	//Se abre en modo lectura
	//if((pFile = fopen(fileName,"r+b")) == NULL){
		//Si el modo anterior dio error el archivo no existe, por lo tanto se crea
        if((pFile = fopen(fileName,"w+b")) == NULL){
            printf("\r\nError al intentar abrir el archivo\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    //}

    arrayLenght = list->len(list);

    printf("\r\nSe va a escribir: \n");
    reproduction_printArrayList(list);

    for(i = 0; i < arrayLenght; i++){

        repAux = list->get(list,i);
        printf("\n%d escribiendo elemento\n",i);
        reproduction_print(repAux);

        //Me posiciono al final del archivo para agregar datos
    	//fseek(pFile,0L,SEEK_END);
        //Escribo los datos
        cleanStdin();
        qtyReturned = fwrite(repAux,sizeof(Reproduction),1,pFile);
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


int file_binToListRep(ArrayList* listRep, char *fileName){

    int returnAux = -1;
    int qtyReturned;
    
    FILE *pFile;

    if(listRep == NULL){
        printf("\r\nLa lista donde se desean almacenar los datos es incorrecta\r\n");
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
    //fseek(pFile,(long)(1)sizeof(song)),SEEK_SET);
    while(!feof(pFile)){
        //Creamos un nuevo objeto de manera dinamica para cargar los datos
        Reproduction* reproduccion = reproduction_new();

        //Leemos y cargamos los datos al objeto creado anteriormente
        cleanStdin();
        qtyReturned = fread(reproduccion,sizeof(Reproduction),1,pFile);
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
        if(listRep->add(listRep,reproduccion) == -1){
            printf("\r\nNo se pudo ingresar el nuevo usero, verifique espacio en memoria\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }

        reproduction_print(reproduccion);
    }
    printf("\r\nCargando archivo a la lista...\r\n");
    returnAux = 0;

    fclose(pFile);
    return returnAux;
}


int file_binToListSongs(ArrayList* listSongs, char *fileName){

	int returnAux = -1, flag = 0;
	int qtyReturned;
    char idStr[256],titleAux[256],artistAux[256];
    
    FILE *pFile;

    if(listSongs == NULL){
        printf("\r\nLa lista donde se desean almacenar los datos es incorrecta\r\n");
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
    //fseek(pFile,(long)(1)sizeof(song)),SEEK_SET);
    while(!feof(pFile)){
        //Creamos un nuevo objeto de manera dinamica para cargar los datos
        Song* song = song_new();

        if(flag == 0){

            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idStr,titleAux,artistAux);
            flag = 1;
            continue;
        }

        //Leemos y cargamos los datos al objeto creado anteriormente
        cleanStdin();
        qtyReturned = fread(song,sizeof(Song),1,pFile);
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
    	if(listSongs->add(listSongs,song) == -1){
            printf("\r\nNo se pudo ingresar el nuevo usero, verifique espacio en memoria\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }

        song_print(song);
    }
    printf("\r\nCargando archivo a la lista...\r\n");
    returnAux = 0;

    fclose(pFile);
	return returnAux;
}


int file_parseUsers(char* fileName, ArrayList* listaUsers){

    int returnAux = 0;
    int readItem;
    char idStr[256],nameAux[256],mailAux[256],sexAux[256],paisAux[256],passAux[256],ipStr[256];
    int idAux, flag = 0;
    FILE *pFile;

    if(listaUsers == NULL){
        printf("\r\nEspacio en memoria insuficiente\r\n");
        return returnAux;
    }

    pFile = fopen(fileName,"r");
    if (pFile == NULL) {

        printf("\r\nNo se pudo abrir el archivo\n");
        return returnAux;
    }

    while(!feof(pFile)){

        if(flag == 0){

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nameAux,mailAux,sexAux,paisAux,passAux,ipStr);
            flag = 1;
            continue;
        }

        cleanStdin();
        readItem = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nameAux,mailAux,sexAux,paisAux,passAux,ipStr);
        if(readItem == 7){

            idAux = atoi(idStr);

            User* user = user_new();

            user_setId(user,idAux,1);
            user_setName(user,nameAux,1,256);
            user_setMail(user,mailAux,1,256);
            user_setSex(user,sexAux,1,256);
            user_setPais(user,paisAux,1,256);
            user_setPassword(user,passAux,1,256);
            user_setIp(user,ipStr,1,256);

            if(listaUsers->add(listaUsers,user) == -1){
                printf("\r\nNo se pudo ingresar el nuevo emo, verifique espacio en memoria\r\n");
                return returnAux;
            }
            //user_print(user);
        }
        else {

            printf("\r\nNo se leyeron los datos correctamente\n");
            pause("\r\nEnter para salir: ");
            return returnAux;;
        }//if(readItem==4)
    }//while(!feof(pFile))

    printf("\r\nCargando archivo a la lista...\r\n");
    fclose(pFile);

    return 1; // OK
}


int file_parseSongs(char* fileName, ArrayList* listaSongs){

    int returnAux = 0;
    int readItem;
    char idStr[256],titleAux[256],artistAux[256];
    int idAux, flag = 0;
    FILE *pFile;

    if(listaSongs == NULL){
        printf("\r\nEspacio en memoria insuficiente\r\n");
        return returnAux;
    }

    pFile = fopen(fileName,"r");
    if (pFile == NULL) {

        printf("\r\nNo se pudo abrir el archivo\n");
        return returnAux;
    }

    while(!feof(pFile)){

        if(flag == 0){

            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idStr,titleAux,artistAux);
            flag = 1;
            continue;
        }

        cleanStdin();
        readItem = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idStr,titleAux,artistAux);
        if(readItem == 3){

            idAux = atoi(idStr);

            Song* song = song_new();

            song_setId(song,idAux,1);
            song_setTitle(song,titleAux,1,256);
            song_setArtist(song,artistAux,1,256);

            if(listaSongs->add(listaSongs,song) == -1){
                printf("\r\nNo se pudo ingresar el nuevo emo, verifique espacio en memoria\r\n");
                return returnAux;
            }
            //song_print(song);
        }
        else {

            printf("\r\nNo se leyeron los datos correctamente\n");
            pause("\r\nEnter para salir: ");
            return returnAux;;
        }//if(readItem==4)
    }//while(!feof(pFile))

    printf("\r\nCargando archivo a la lista...\r\n");
    fclose(pFile);

    return 1; // OK
}


