/*
//  main.c
//  ejercicio16
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//
    16. Hacer el programa que nos permita introducir un número por teclado y nos informe si es positivo o negativo    */

#include <stdio.h>

int main()
{
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    /*printf("Se ingreso el numero: %d\n", numero);*/
    
    if (numero > 0)
    {
        printf("El numero es positivo");
    }
    else
    {
        if (numero < 0)
        {
            printf("El numero es negativo");
        }
        else
        {
            printf("El numero es cero");
        }
    }
    
    return 0;
}/*int main()*/
