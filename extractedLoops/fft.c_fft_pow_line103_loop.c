#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern long winlength;
typedef float real;
extern real * restrict temp;
extern float * restrict orig;

void loop()
{
#pragma scop

    for(i = 0; i < winlength; i++) temp[i] =((real )orig[i]);

#pragma endscop
}
