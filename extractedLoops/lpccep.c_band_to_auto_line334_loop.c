#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int n_auto;
extern double tmp;
extern double ** restrict wcosptr;
struct fvec
{
    float *values;
    int length;
};

extern struct fvec* restrict bandptr;
extern int j;
extern int n_freq;
extern struct fvec* restrict autoptr;

void loop()
{
#pragma scop

    for(i = 0; i < n_auto; i++)
    {
        tmp = wcosptr[i][0] *((double )bandptr -> values[0]);
        for(j = 1; j < n_freq; j++) tmp += wcosptr[i][j] *((double )bandptr -> values[j]);
        autoptr -> values[i] =((float )(tmp /((double )(2.0 *(n_freq - 1)))));
    }

#pragma endscop
}
