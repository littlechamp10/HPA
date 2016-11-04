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

extern struct fvec* restrict inbufptr;

void loop()
{
#pragma scop

    for(i = pptr -> steppts; i < pptr -> winpts; i++)
    {
        inbufptr -> values[i - pptr -> steppts] = inbufptr -> values[i];
    }

#pragma endscop
}
