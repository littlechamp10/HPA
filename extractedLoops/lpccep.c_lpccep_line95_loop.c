#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
struct fvec
{
    float *values;
    int length;
};

extern struct fvec* restrict outptr;
extern struct fvec* restrict outptrOLD;

void loop()
{
#pragma scop

    for(i = 0; i < outptr -> length; i++) outptrOLD -> values[i] = outptr -> values[i];

#pragma endscop
}
