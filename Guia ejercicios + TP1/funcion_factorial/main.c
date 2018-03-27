#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int resultado = 1;
    int i;

    printf("Ingrese un numero a calcular el factorial: ");
    scanf("%d", &numero);

    for(i = numero; i > 0; i--)
    {
        resultado *= i;
    }

    printf("El factorial de %d es %d", numero, resultado);

    return 0;
}
