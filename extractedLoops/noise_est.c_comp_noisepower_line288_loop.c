#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;

extern struct param
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
}* restrict pptr;
extern int lastfilt;
struct fmat
{
    float **values;
    int nrows;
    int ncols;
};

extern struct fmat* restrict buffer;
extern int histo_step_framesize;
extern int i_call;
extern struct fmat* restrict all_trajec;
extern int t;
extern struct fmat* restrict histo_values;
struct svec
{
    short *values;
    int length;
};

extern struct svec* restrict histo_index;

void loop()
{
#pragma scop

    for(i = pptr -> first_good; i < lastfilt; i++)
    {
        buffer -> values[i][histo_step_framesize - i_call] = all_trajec -> values[i][t];
        histo_values -> values[i][t] = all_trajec -> values[i][t];
        histo_index -> values[i]++;
    }

#pragma endscop
}
