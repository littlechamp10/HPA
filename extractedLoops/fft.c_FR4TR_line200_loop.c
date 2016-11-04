#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int k;
extern int  L[16] ;

void loop()
{
#pragma scop

    for(k = 2; k < 16; k++)
    {
        switch(L[k - 1] - 2 < 0?- 1 :((L[k - 1] - 2 == 0?0 : 1)))
        {
        case - 1:
            L[k - 1] = 2;
        case 0:
        {
            L[k] = 2;
            break;
        }
        case 1:
            L[k] = L[k - 1] / 2;
        }
    }

#pragma endscop
}
