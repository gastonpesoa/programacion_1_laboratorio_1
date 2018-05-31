#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct S_Persona{
    int edad;
    char nombre[20];
}Persona;

void preguntarNombre(Persona*);
int preguntarEdad(void);
char preguntarSalir(void);

int main()
{
    int size = 10;
    int index=0;
    Persona** lista = (Persona**)malloc(sizeof(Persona *)*size);
    Persona** listaAux;

    do {
        Persona* persona = (Persona*)malloc(sizeof(Persona));

        preguntarNombre(persona->nombre);
        persona->edad = preguntarEdad();
        lista[index] = persona;

        if(index>=size){
            // incrementamos el tamaño del array
            size+=10;
            listaAux = realloc(lista,sizeof(Persona*)*size);
            if(listaAux==NULL){
                printf("\nNo hay lugar en memoria\n");
                free(listaAux);
            }
            else{
                lista = listaAux;
            }
        }

    }while(preguntarSalir()!='S');

    return 0;
}

void preguntarNombre(char nombre[]){

    char nombreAux[50];

    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%s",nombreAux);
    strcpy(nombre,nombreAux);
}


int preguntarEdad(void);
char preguntarSalir(void);
