#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int j1;
extern int l1;
extern int j2;
extern int l2;
extern int j3;
extern int l3;
extern int j4;
extern int l4;
extern int j5;
extern int l5;
extern int j6;
extern int l6;
extern int j7;
extern int l7;
extern int j8;
extern int l8;
extern int j9;
extern int l9;
extern int j10;
extern int l10;
extern int j11;
extern int l11;
extern int j12;
extern int l12;
extern int j13;
extern int l13;
extern int j14;
extern int l14;
extern int ji;
extern int l15;
extern int ij1;
extern int ij;
extern int ji1;
typedef float real;
extern real t;
extern real * restrict b;

void loop()
{
#pragma scop

    for(j1 = 2; j1 <= l1; j1 += 2) for(j2 = j1; j2 <= l2; j2 += l1) for(j3 = j2; j3 <= l3; j3 += l2) for(j4 = j3; j4 <= l4; j4 += l3) for(j5 = j4; j5 <= l5; j5 += l4) for(j6 = j5; j6 <= l6; j6 += l5) for(j7 = j6; j7 <= l7; j7 += l6) for(j8 = j7; j8 <= l8; j8 += l7) for(j9 = j8; j9 <= l9; j9 += l8) for(j10 = j9; j10 <= l10; j10 += l9) for(j11 = j10; j11 <= l11; j11 += l10) for(j12 = j11; j12 <= l12; j12 += l11) for(j13 = j12; j13 <= l13; j13 += l12) for(j14 = j13; j14 <= l14; j14 += l13) for(ji = j14; ji <= l15; ji += l14)
                                                            {
                                                                ij1 = ij - 1;
                                                                ji1 = ji - 1;
                                                                if(ij - ji < 0)
                                                                {
                                                                    t = b[ij1 - 1];
                                                                    b[ij1 - 1] = b[ji1 - 1];
                                                                    b[ji1 - 1] = t;
                                                                    t = b[ij1];
                                                                    b[ij1] = b[ji1];
                                                                    b[ji1] = t;
                                                                }
                                                                ij += 2;
                                                            }

#pragma endscop
}
