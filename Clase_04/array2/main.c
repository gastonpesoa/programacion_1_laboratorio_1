#include <stdio.h>
#include <ctype.h>

#define CANT 5

void main(void){
    int v[CANT], estado[CANT], i, contador=0;
    char seguir;

    for(i=0;i<CANT;i++)
        estado[i]=0; // inicializamos vector

    do{
        if(contador < CANT){
            for(i=0; i<CANT; i++){
                if(estado[i] == 0){
                    printf("Ingrese valor a cargar en el vector");
                    scanf("%d",&v[i]);

                    estado[i]=1;
                    contador++;
                    break;
                }
            }
        }
        else{
            printf("No hay espacio suficiente...");
        }


        printf("Desea ingresar otro dato S/N?");
        setbuf(stdin, NULL);
        scanf("%c",&seguir);
        seguir=tolower(seguir);
    }while(seguir == 's');

    if(contador > 0){
        for(i=0; i<CANT; i++){
            if(estado[i] == 1){
                printf("\n%d", v[i]);
            }
        }
    }
    else{
        printf("No existen datos cargados...");
    }

}
