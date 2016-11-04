#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int nrows;
struct fmat
{
    float **values;
    int nrows;
    int ncols;
};

extern struct fmat* restrict mptr;
extern int ncols;

void loop()
{
#pragma scop

    for(i = 1; i < nrows; ++i)
    {
        mptr -> values[i] = mptr -> values[0] + i * ncols;
    }

#pragma endscop
}
