/*  main.c
//  ejercicio5
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
 
//  5. Escribir el programa necesario para calcular y mostrar el cuadrado de un número. El número debe ser mayor que cero, en caso de error que aparezca el mensaje "ERROR, el número debe ser mayor que cero"    */

#include <stdio.h>

int main()
{
    int numero;
    int potenciaCuadrado;
    
    printf("Ingrese el numero a calcular el cuadrado: ");
    scanf("%d", &numero);
    
    while (numero < 0)
    {
        printf("ERROR, el número debe ser mayor que cero\nIngrese nuevamente el numero a calcular el cuadrado: ");
        scanf("%d", &numero);
    }
    
    potenciaCuadrado = numero * numero;
    printf("El nuemero al cuadrado es: %d\n", potenciaCuadrado);
    return 0;
}
