#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
struct param
{
    float winsize;
    int winpts;
    float stepsize;
    int steppts;
    int padInput;
    int sampfreq;
    int nframes;
    float nyqbar;
    int nfilts;
    int first_good;
    int trapezoidal;
    float winco;
    float polepos;
    int order;
    int nout;
    int gainflag;
    float lift;
    int lrasta;
    int jrasta;
    int cJah;
    char *mapcoef_fname;
    int crbout;
    int comcrbout;
    float rfrac;
    float jah;
    char *infname;
    char *num_fname;
    char *denom_fname;
    char *outfname;
    int ascin;
    int ascout;
    int espsin;
    int espsout;
    int matin;
    int matout;
    int spherein;
    int abbotIO;
    int inswapbytes;
    int outswapbytes;
    int debug;
    int smallmask;
    int online;
    int HPfilter;
    int history;
    char *hist_fname;
    int deltawindow;
    int deltaorder;
};

extern struct param* restrict pptr;
struct fvec
{
    float *values;
    int length;
};

extern struct fvec* restrict sptr;
extern int start;
extern short  buf[512] ;

void loop()
{
#pragma scop

    for(i = 0; i < 512; i++)
    {
        if(pptr -> inswapbytes ==(1 == 1))
        {
            sptr -> values[start + i] =((float )((short )((sizeof(short ) == 2?(buf[i] & 0x0ff) << 8 | buf[i] >> 8 & 0x0ff :(buf[i] & 0x0ff) << 24 |(buf[i] & 0x0ff << 8) << 8 |(buf[i] & 0x0ff << 16) >> 8 | buf[i] >> 24 & 0x0ff))));
        }
        else
        {
            sptr -> values[start + i] =((float )buf[i]);
        }
    }

#pragma endscop
}
