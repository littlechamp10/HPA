#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int j;
extern int n;
extern int k;
typedef float real;
extern real t;
extern real * restrict b;
extern int kl;

void loop()
{
#pragma scop

    for(j = 4; j <= n; j += 2)
    {
        if(k - j > 0)
        {
            t = b[j - 1];
            b[j - 1] = b[k - 1];
            b[k - 1] = t;
        }
        k -= 2;
        if(k - kl <= 0)
        {
            k = 2 * j;
            kl = j;
        }
    }

#pragma endscop
}
