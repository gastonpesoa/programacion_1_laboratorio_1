//
//  main.c
//  ejercicio10
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//
//  10. Escribir en C un programa que muestre los números impares entre 0 y 100 y que imprima cuantos impares hay

#include <stdio.h>

int main()
{
    int impares = 0;
    int i;
    
    for (i = 0; i < 100; i++)
    {
        if (i % 2 != 0 && i != 0)
        {
            printf("Numero impar: %d\n", i);
            impares++;
        }
    }
    printf("Cantidad de impares: %d\n", impares);
    
    return 0;
}/*int main()*/
