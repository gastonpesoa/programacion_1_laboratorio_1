//
//  main.c
//  ejercicio13
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//
//  13. Hacer el programa que imprima los números del 100 al 0 en orden decreciente

#include <stdio.h>

int main()
{
    int i;
    
    for (i = 100; i >= 0; i--)
    {
        printf("Numero: %d\n", i);
    }
    
    return 0;
}/*int main()*/
