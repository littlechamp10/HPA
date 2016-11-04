#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
struct fvec
{
    float *values;
    int length;
};

extern struct fvec* restrict fptr;
extern float scale;

void loop()
{
#pragma scop

    for(i = 0; i < fptr -> length; i++)
    {
        fptr -> values[i] /= scale;
    }

#pragma endscop
}
