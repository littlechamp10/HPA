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
extern float sum;
extern int lastfilt;
extern int j;
extern float average;
extern int i_call;
struct fmat
{
    float **values;
    int nrows;
    int ncols;
};

extern struct fmat* restrict all_trajec;

void loop()
{
#pragma scop

    for((i = pptr -> first_good , sum = 0.0); i < lastfilt; i++)
    {
        for((j = 0 , average = 0.0); j < i_call; j++)
        {
            average += all_trajec -> values[i][j];
        }
        average /= i_call;
        sum += average * average;
    }

#pragma endscop
}
