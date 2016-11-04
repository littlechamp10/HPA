#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int mct;
extern int i_2;
extern float s;
extern int mct2;
extern float alpmin;
extern float * restrict alp;
extern int i_1;
extern int ip;
extern int idx;
extern float * restrict r;
extern float * restrict a;
extern float rcmct;
extern int mh;
extern int ib;
extern float aip;
extern float aib;
extern float * restrict rc;

void loop()
{
#pragma scop

    for(mct = 2; mct <= i_2; ++mct)
    {
        s = 0.;
        mct2 = mct + 2;
        alpmin = alp[mct - 1];
        i_1 = mct;
        for(ip = 1; ip <= i_1; ++ip)
        {
            idx = mct2 - ip;
            s += r[idx - 1] * a[ip - 1];
        }
        rcmct =(-((double )s) / alpmin);
        mh = mct / 2 + 1;
        i_1 = mh;
        for(ip = 2; ip <= i_1; ++ip)
        {
            ib = mct2 - ip;
            aip = a[ip - 1];
            aib = a[ib - 1];
            a[ip - 1] = aip + rcmct * aib;
            a[ib - 1] = aib + rcmct * aip;
        }
        a[mct] = rcmct;
        alp[mct] = alpmin - alpmin * rcmct * rcmct;
        rc[mct - 1] = rcmct;
    }

#pragma endscop
}
