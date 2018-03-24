/*
//  main.c
//  ejercicio6
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//  6. De 10 números ingresadas indicar cuantos son mayores a cero y cuantos son menores a cero    */

#include <stdio.h>

int main()
{
    int positivos = 0;
    int negativos = 0;
    int ceros = 0;
    int i;
    
    for (i = 0; i < 10; i++)
    {
        int numero;
        
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        
        if (numero > 0)
        {
            positivos++;
        }
        else
        {
            if (numero == 0)
            {
                ceros++;
            }
            else
            {
                negativos++;
            }
        }/*if (numero > 0)*/
    }/*for (i = 0; i < 10; i++)*/
    
    printf("La cantidad de positivos es: %d\nLa cantidad de negativos es: %d\nY la cantidad de ceros es: %d\n", positivos, negativos, ceros);
    return 0;
}
