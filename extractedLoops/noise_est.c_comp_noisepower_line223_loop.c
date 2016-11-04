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
struct fvec
{
    float *values;
    int length;
};

extern struct fvec* restrict max;
struct svec
{
    short *values;
    int length;
};

extern struct svec* restrict new_max;
extern struct svec* restrict new_max_index;
extern struct fvec* restrict noise_level_lt;
extern struct svec* restrict histo_index;
extern int j;
extern int histo_length;
struct fmat
{
    float **values;
    int nrows;
    int ncols;
};

extern struct fmat* restrict all_trajec;
extern struct fmat* restrict histo_values;

void loop()
{
#pragma scop

    for(i = 0; i < pptr -> nfilts; i++)
    {
        max -> values[i] = 0;
        new_max -> values[i] = 0;
        new_max_index -> values[i] = 0;
        noise_level_lt -> values[i] = 0;
        histo_index -> values[i] =(- 1);
        for(j = 0; j < histo_length; j++)
        {
            all_trajec -> values[i][j] = 0;
            histo_values -> values[i][j] = 0;
        }
    }

#pragma endscop
}
