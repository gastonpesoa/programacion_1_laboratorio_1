/*
//  main.c
//  ejercicio15
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//
    15. Escribir en y codificar en C un programa que muestre los múltiplos de 6 comprendidos entre 0 y 100 */

#include <stdio.h>

int main()
{
    int i;
    
    for (i = 0; i < 100; i++)
    {
        if(i % 6 == 0 && i != 0)
        {
            printf("Numero multiplo de 6: %d\n", i);
        }
    }
    
    return 0;
}/*int main()*/
