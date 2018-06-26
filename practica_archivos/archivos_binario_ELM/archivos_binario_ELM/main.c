#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

#define ARCH "/Volumes/Almacen/UTN/Programacion I/Practicas/practica_archivos/archivos_binario_ELM/archivos_binario_ELM/bin.dat"

typedef struct{
    char name[51];
    int age;
    int legajo;
}EPerson;

int main(){

    FILE *pFile;
    EPerson person;
    char seguir = 's';
    int i = 0, qtyReturned, legajoAux;

    if((pFile = fopen(ARCH,"r+b")) == NULL){
        if((pFile = fopen(ARCH,"w+b")) == NULL){
            printf("\r\nError al intentar abrir el archivo\r\n");
        }
        printf("\r\nEl archivo no existe por lo tanto se crea\r\n");
    }
    else {
        printf("\r\nEl archivo existe por lo tanto no se crea\r\n");
    }

    while(seguir == 's'){
        i++;
        getValidString("\r\nIngrese el nombre: ","\r\nEl nombre debe ser solo letras\r\n",person.name);
        person.age = getValidInt("\r\nIngrese la edad: ","\r\nLa edad debe ser numerica\r\n",1,100);
        person.legajo = i;

        //Me posiciono al final del archivo para agregar datos
        fseek(pFile,0L,SEEK_END);

        //Escribo los datos
        cleanStdin();
        qtyReturned = fwrite(&person,sizeof(person),1,pFile);
        if(qtyReturned != 1){
            printf("\r\nError al intentar escribir la persona en el archivo\r\n");
        }
        else {
            printf("\r\nSe escribio la persona archivo con exito!!\r\n");
        }

        //Mostramos la persona agregada
        printf("\r\nSe agrego: \r\n| Nombre: %12s | Edad: %3d | Legajo: %2d |",person.name,person.age,person.legajo);

        //Preguntamos si se desea seguir
        seguir = confirm("\r\nDesea agregar otra persona?: [s|n]");
    }// while(seguir == 's')

    legajoAux = getValidInt("\r\nIngrese el legajo de la persona a modificar: ","\r\nEl legajo debe ser numeric0\r\n",1,100);

    //Me posiciono al comienzo del arch para empezar a leer
    rewind(pFile);
    while(!feof(pFile)){
        qtyReturned = fread(&person,sizeof(person),1,pFile);
        if(qtyReturned != 1){
            if(feof(pFile)){
                printf("\r\nSe llego al final del archivo\r\n");
                break;
            }
            else {
                printf("\r\nError al intentar leer el archivo\r\n");
            }
        }
        if(person.legajo == legajoAux){

             printf("\r\nSe encontro: \r\n| Nombre: %12s | Edad: %3d | Legajo: %2d |",person.name,person.age,person.legajo);

            getValidString("\r\nIngrese el nombre: ","\r\nEl nombre debe ser solo letras\r\n",person.name);
            person.age = getValidInt("\r\nIngrese la edad: ","\r\nLa edad debe ser numerica\r\n",1,100);

            //Vuelvo una struct para atras para no mofificar otra persona
            fseek(pFile,(long)(-1)*sizeof(person),SEEK_CUR);

            //Escribo los datos
            cleanStdin();
            qtyReturned = fwrite(&person,sizeof(person),1,pFile);
            if(qtyReturned != 1){
                printf("\r\nError al intentar moficar la persona en el archivo\r\n");
            }
            else {
                printf("\r\nSe modifico la persona archivo con exito!!\r\n");
            }
            //Mostramos la persona agregada
            printf("\r\nSe agrego: \r\n| Nombre: %12s | Edad: %3d | Legajo: %2d |",person.name,person.age,person.legajo);
        }
    }

    //Me posiciono al comienzo del arch para empezar a leer
    rewind(pFile);
    while(!feof(pFile)){
        qtyReturned = fread(&person,sizeof(person),1,pFile);
        if(qtyReturned != 1){
            if(feof(pFile)){
                printf("\r\nSe llego al final del archivo\r\n");
                break;
            }
            else {
                printf("\r\nError al intentar leer el archivo\r\n");
            }
        }
        //Mostramos la persona agregada
        printf("\r\nSe agrego: \r\n| Nombre: %12s | Edad: %3d | Legajo: %2d |",person.name,person.age,person.legajo);
    }

    fclose(pFile);
    return 0;
}
