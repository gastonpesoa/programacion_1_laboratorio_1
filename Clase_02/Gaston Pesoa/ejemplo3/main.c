#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int resultado;

    printf("Ingrese un nuemero: ");
    scanf("%d",&i);
    resultado = (i * (i + 1))/2;
    printf("El resultado es: %d", resultado);

    return 0;
}
