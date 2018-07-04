#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"
#include "Input.h"


int generarArchivoSueldos(char* fileName,ArrayList* listaEmpleados);

int main()
{
    int opcionMenuPrincipal = 0;
    // Definir lista de empleados
    ArrayList* listaEmpleados;

    // Crear lista empledos
    //...
    listaEmpleados = al_newArrayList();

     while(opcionMenuPrincipal != 5){

        clearScreen();
        opcionMenuPrincipal = optionMainMenu();

        switch(opcionMenuPrincipal){

            case 1: //Leer empleados de archivo data.csv
                    clearScreen();
                    if(parser_parseEmpleados("data.csv",listaEmpleados)==1){
                    printf("\r\nLista cargada con exito\r\n");
                    pause("\r\nPresione enter para volver al menu principal\r\n");
                }
                else {
                    printf("Error leyando empleados\n");
                    pause("\r\nPresione enter para volver al menu principal\r\n");
                }

                break;

            case 2: //Calcular sueldo
                clearScreen();
                printf("Calculando sueldos de empleados\n");
                listaEmpleados->map(listaEmpleados,em_calcularSueldo);
                printf("\r\nSueldo calculado\n");
                pause("\r\nPresione enter para volver al menu principal\r\n");

                break;

            case 3: //Generar archivo de salida
                clearScreen();
                if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==1)
                {
                    printf("Archivo generado correctamente\n");
                    pause("\r\nPresione enter para volver al menu principal\r\n");
                }
                else{
                    printf("Error generando archivo\n");
                    pause("\r\nPresione enter para volver al menu principal\r\n");
                }

                break;

            case 4: //Mostrar lista
                clearScreen();
                em_printArrayList(listaEmpleados);
                pause("\r\nPresione enter para volver al menu principal\r\n");

                break;

            case 5: //Salir

                continue;
        }// switch(opcionMenuPrincipal)

     }//while(opcionMenuPrincipal != 5)

    return 0;
}

int generarArchivoSueldos(char* fileName,ArrayList* listaEmpleados)
{
    int returnAux = 0;
    int i, arrayLenght, idAux, hsAux, sueldoAux;
    char *nameAux;
    FILE* pFile;

    Empleado *empAux;

    if((pFile = fopen(fileName,"w+")) == NULL){
        printf("\r\nError al intentar abrir el archivo\r\n");
        pause("\r\nEnter para salir: ");
        return returnAux;
    }

    arrayLenght = listaEmpleados->len(listaEmpleados);

    for(i = 0; i < arrayLenght; i++){

        empAux = listaEmpleados->get(listaEmpleados,i);

        idAux = em_getId(empAux);
        nameAux = em_getName(empAux);
        hsAux = em_getHs(empAux);
        sueldoAux = em_getSueldo(empAux);

        cleanStdin();
        if((fprintf(pFile, "%d,%s,%d,%d\n", idAux, nameAux, hsAux, sueldoAux)) < 0){
            printf("\r\nError al intentar escribir la objecta en el archivo\r\n");
            pause("\r\nEnter para salir: ");
            return returnAux;
        }
    }

    fclose(pFile);
    return 1;
}
