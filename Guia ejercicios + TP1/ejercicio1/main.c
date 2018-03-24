/*  main.c
//  ejercicio1
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.

 // 1. Ingresar 5 números y calcular su media */

#include <stdio.h>

int main()
{
    int i;
    int suma = 0;
    float promedio;
    
    for (i = 0; i < 5; i++)
    {
        int aux;
        
        printf("Ingrese un numero: ");
        scanf("%d",&aux);
        
        suma += aux;
    }
    promedio = (float)suma / i;
    printf("El promedio es: %.2f", promedio);
    return 0;
}
