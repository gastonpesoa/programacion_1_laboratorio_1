//
//  main.c
//  ejercicio9
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//
//  9. Escribir un programa que realice lea por teclado 20 caracteres. Luego de la lectura indicar cuantas "a" se ingresaron, cuantas "e, i, o, u"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int contador_a = 0;
    int contador_e = 0;
    int contador_i = 0;
    int contador_o = 0;
    int contador_u = 0;
    
    for (i = 0; i < 5; i++)
    {
        char caracter;
        printf("Escriba un caracter: ");
        scanf(" %c", &caracter);
        
        switch(caracter)
        {
            case 'a':
                contador_a++;
                break;
            case 'e':
                contador_e++;
                break;
            case 'i':
                contador_i++;
                break;
            case 'o':
                contador_o++;
                break;
            case 'u':
                contador_u++;
                break;
        }
    }
    printf("\nCantidad a: %d\n", contador_a);
    printf("Cantidad e: %d\n", contador_e);
    printf("Cantidad i: %d\n", contador_i);
    printf("Cantidad o: %d\n", contador_o);
    printf("Cantidad u: %d\n", contador_u);
    
    return 0;
}