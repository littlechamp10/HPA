#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int n;
typedef float real;
extern real * restrict b;

void loop()
{
#pragma scop

    for(i = 3; i < n; i += 2) b[i] = -b[i];

#pragma endscop
}
