#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int time;
struct fvec
{
    float *values;
    int length;
};

extern struct fvec* restrict filter;
extern float sum;

void loop()
{
#pragma scop

    for(i = 1; i < time; i++) filter -> values[i] /= sum;

#pragma endscop
}
