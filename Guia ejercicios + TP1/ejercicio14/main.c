/*
//  main.c
//  ejercicio14
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//
    14. Diseñar un programa que imprima y sume la serie de números 3,6,9,12,...,99. */

#include <stdio.h>

int main()
{
    int i;
    
    for (i = 0; i < 100; i += 3)
    {
        printf("Numero: %d\n", i);
    }
    
    return 0;
}/*int main()*/
