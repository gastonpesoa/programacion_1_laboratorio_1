//
//  main.c
//  ejercicio11
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//
//  11. Hacer el programa que imprima los números pares entre el 1 y el 100

#include <stdio.h>

int main()
{
    int pares = 0;
    int i;
    
    for (i = 0; i < 100; i++)
    {
        if (i % 2 == 0 && i != 0)
        {
            printf("Numero par: %d\n", i);
            pares++;
        }
    }
    
    return 0;
}/*int main()*/
