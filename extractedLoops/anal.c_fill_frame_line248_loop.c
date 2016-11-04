#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
struct fvec
{
    float *values;
    int length;
};

extern struct fvec* restrict outbufptr;
extern struct fvec* restrict window;
extern struct fvec* restrict inbufptr;

void loop()
{
#pragma scop

    for(i = 0; i < outbufptr -> length; i++)
    {
        outbufptr -> values[i] = window -> values[i] * inbufptr -> values[i];
    }

#pragma endscop
}
