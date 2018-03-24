/*
//  main.c
//  ejercicio7
//
//  Created by Gaston Pesoa on 24/03/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//
    7. Diseñar un programa que calcule la longitud de la circunferencia y el área del círculo de radio dado. */

#include <stdio.h>

int main()
{
    int radio;
    int longitud;
    int area;
    
    printf("Ingrese el radio del circulo: ");
    scanf("%d", &radio);
    
    longitud = 2 * radio * 3.14;
    area = radio * radio * 3.14;
    
    printf("La longitud de la circunferencia es: %d\nY el area de la misma es: %d\n", longitud, area);
    
    return 0;
}
