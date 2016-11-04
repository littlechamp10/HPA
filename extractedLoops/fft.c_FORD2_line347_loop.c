#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int k;
extern int m;
extern int  l[16] ;

void loop()
{
#pragma scop

    for(k = m; k <= 14; k++) l[k + 1] = 2;

#pragma endscop
}
