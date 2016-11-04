#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int j;
extern float output;
struct fvec
{
    float *values;
    int length;
};

extern struct fvec* restrict filter;
struct fmat
{
    float **values;
    int nrows;
    int ncols;
};

extern struct fmat* restrict buffer;
extern int Crband;

void loop()
{
#pragma scop

    for(j = 1; j < 30; j++) output += filter -> values[j] * buffer -> values[Crband][j - 1];

#pragma endscop
}
