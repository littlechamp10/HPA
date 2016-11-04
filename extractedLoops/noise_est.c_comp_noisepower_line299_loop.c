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
extern float mmax;
extern int mmax_index;
extern int j;
extern int histo_step_framesize;
struct fmat
{
    float **values;
    int nrows;
    int ncols;
};

extern struct fmat* restrict buffer;
extern float average1;

void loop()
{
#pragma scop

    for(i = pptr -> first_good; i < lastfilt; i++)
    {
        mmax = 0;
        mmax_index = 0;
        for(j = 0; j < histo_step_framesize; j++)
        {
            if(buffer -> values[i][j] > mmax)
            {
                mmax = buffer -> values[i][j];
                mmax_index = j;
            }
        }
        average1 = 0.0;
        for(j = 0; j < histo_step_framesize; j++)
        {
            if(j != mmax_index) average1 += buffer -> values[i][j];
        }
        average1 /=((float )(histo_step_framesize - 1));
        buffer -> values[i][mmax_index] = average1;
        for(j = histo_step_framesize; j < 30; j++) buffer -> values[i][j] = average1;
    }

#pragma endscop
}
