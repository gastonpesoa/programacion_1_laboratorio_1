#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 3

typedef struct {
    char nombre[20];
    int nota;
}alumno;

void mostrarCadena(char* punteroCadena);
void ordenar(alumno *arrayPunterosAlumnos[3], int longitudArray);

int main(){

    int i,auxiliarNota;
    char auxiliarNombre[50];

    char cadena[5] = "hola";

    alumno auxiliarAlumno;
    alumno *punteroAlumno;

    alumno arrayAlumnos[CANTIDAD];
    alumno *arrayPunterosAlumnos[CANTIDAD];

    mostrarCadena(cadena);

    punteroAlumno = &auxiliarAlumno;

    strcpy(punteroAlumno->nombre, "Ernesto");
    punteroAlumno->nota = 10;

    printf("\n\nNombre: %s\nNota: %d\n\n", punteroAlumno->nombre, punteroAlumno->nota);

    for(i=0; i<CANTIDAD; i++){
        // Copiamos la posición de memoria de cada elemento
        arrayPunterosAlumnos[i] = &arrayAlumnos[i];
        printf("\nIngrese el nombre: ");
        scanf("%s",auxiliarNombre);
        strcpy(arrayAlumnos[i].nombre, auxiliarNombre); //FALTARIA VALIDAR
        printf("\nIngrese la Nota: ");
        scanf("%i",&auxiliarNota);
        arrayAlumnos[i].nota = auxiliarNota; //FALTA VALIDAR
    }

    printf("\n\n-MOSTRAMOS EL ARRAY SIN ORDENAR -\n");
    for(i=0; i<CANTIDAD; i++){
        printf("\n%s", arrayPunterosAlumnos[i]->nombre);
        printf("-%i",arrayPunterosAlumnos[i]->nota);
    }

    ordenar(arrayPunterosAlumnos , CANTIDAD);

    printf("\n\n-MOSTRAMOS EL ARRAY ORDENADO-\n");
    for(i=0; i<CANTIDAD; i++){
        printf("\n%s", arrayPunterosAlumnos[i]->nombre);
        printf("-%i",arrayPunterosAlumnos[i]->nota);
    }

    return 0;
}

void mostrarCadena(char *punteroCadena){

    while(*punteroCadena != '\0'){
        printf("%c",*punteroCadena);
        punteroCadena++;
    }
}

void ordenar(alumno *arrayPunterosAlumnos[], int longitudArray){
    alumno *punteroAuxiliarAlumno;
    int i,j;
    for(i = 0; i < longitudArray -1 ; i++){
        for(j = i+1; j < longitudArray ; j++){
            if(arrayPunterosAlumnos[i]->nota > arrayPunterosAlumnos[j]->nota){

                punteroAuxiliarAlumno = arrayPunterosAlumnos[i];
                arrayPunterosAlumnos[i] = arrayPunterosAlumnos[j];
                arrayPunterosAlumnos[j] = punteroAuxiliarAlumno;
            }
        }
    }
}
