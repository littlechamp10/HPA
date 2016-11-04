#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int npoints2;
extern int j;
extern int k;
extern float * restrict power;
typedef float real;
extern real * restrict temp;

void loop()
{
#pragma scop

    for(i = 1; i < npoints2; i++)
    {
        j = 2 * i;
        k = 2 * i + 1;
        power[i] = temp[j] * temp[j] + temp[k] * temp[k];
    }

#pragma endscop
}
