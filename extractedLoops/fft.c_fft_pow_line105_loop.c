#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern long winlength;
extern int npoints;
typedef float real;
extern real * restrict temp;

void loop()
{
#pragma scop

    for(i = winlength; i < npoints; i++) temp[i] = 0.0;

#pragma endscop
}
