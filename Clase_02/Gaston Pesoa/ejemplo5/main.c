#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    do
    {
        printf("Ingrese el primer numero: ");
        scanf("%d",&i);
        printf("Ingrese el segundo numero: ");
        scanf("%d",&j);
    } while (i<j);

    return 0;
}
