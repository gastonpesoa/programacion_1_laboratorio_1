#include <stdio.h>
#include <stdlib.h>

int main()
{
    int boleta;
    int empleado;
    int importe;
    float importeVendedor1 = 0;
    float importeVendedor2 = 0;
    float importeVendedor3 = 0;
    float importeFinal1;
    float importeFinal2;
    float importeFinal3;
    int respuesta = 1;

    do {
        printf("\nIngrese el importe de la boleta: ");
        scanf("%d", &importe);

        do {
            printf("\nIngrese el numero del vendedor: ");
            scanf("%d", &empleado);
        } while (empleado < 1 || empleado > 3);

        switch(empleado)
        {
            case 1 :
                importeVendedor1 += importe;
                break;
            case 2 :
                importeVendedor2 += importe;
                break;
            case 3 :
                importeVendedor3 += importe;
                break;
        }

        printf("\n\n¿Desea ingresar otra boleta? 1 para continuar/0 para parar? ");
        scanf("%d", &respuesta);

    } while (respuesta != 0);

    importeFinal1 = (float)importeVendedor1 * 1.05;
    importeFinal2 = (float)importeVendedor2 * 1.05;
    importeFinal3 = (float)importeVendedor3 * 1.05;

    printf("\nEl vendedor 1 gano: %.2f", importeFinal1);
    printf("\nEl vendedor 2 gano: %.2f", importeFinal2);
    printf("\nEl vendedor 3 gano: %.2f", importeFinal3);

    return 0;
}
