#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, *b, *c, x, vec[5], *ptr, i;

    a = 15;
    x = a;
    b = &a;
    c = &a;
    ptr = vec;

    printf("a: %d\nb: %d\nc: %d\nx: %d\n", a, *b, *c, x);

    *b = 13;

    printf("a: %d\nb: %d\nc: %d\nx: %d\n", a, *b, *c, x);

    for(i = 0; i < 5; i++){
        //vec[i] = (i + 2);
        *(ptr + i) = (i + 2);
    }

    for(i = 0; i < 5; i++){
        //printf("%d", vec[i]);
        printf("Valor del index %d: %d\n", i, *(ptr + i));
    }
    return 0;
}
