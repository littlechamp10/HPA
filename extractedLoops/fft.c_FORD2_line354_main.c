#include <fft.c_FORD2_line354_1.ptrderefout.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>
#include <openssl/md5.h>
#include <fft.c_FORD2_line354_1.h>
#include <common.h>
#include <timer.h>

extern void* getCycleArray(unsigned long long heapSize, int iterations);
extern void* deleteCycleArray(void *cycleArray);
extern uint64_t findMedian(uint64_t *cycleArray, int size);
extern void standardDeviation(uint64_t *cycleArray, int size, uint64_t *mean, uint64_t *stdv);
extern void* mallocMemoryChunk(char* fileName, void* startAddr, void* endAddr, unsigned  long long size);
extern void resetHeapData(void* startAddr, void* endAddr, unsigned  long long size);
extern void deleteMemoryMapping(void* oldBrk, void *addr, unsigned long long length, int iterations);
extern void* saveCurrentStackToHeap(void* curSP, void* preBottom, long long*);
extern void* loadBenchStackToCurrentStack(char *stackDataFile, void* benchStackPtr, unsigned long long size);
extern void* getSavedAddress(void *heapAddr);
extern void restoreCurrentStack(void* heapAddr, unsigned long long size);

extern void loop();
extern void* dummy(int num, ...);

int j1;
int l1;
int j2;
int l2;
int j3;
int l3;
int j4;
int l4;
int j5;
int l5;
int j6;
int l6;
int j7;
int l7;
int j8;
int l8;
int j9;
int l9;
int j10;
int l10;
int j11;
int l11;
int j12;
int l12;
int j13;
int l13;
int j14;
int l14;
int ji;
int l15;
int ij1;
int ij;
int ji1;
typedef float real;
real t;
real * restrict b;

int main(int argc, char** argv)
{
    int inputIndices[10];
    FILE* pFile_;
    int iterations = 1;
    uint64_t *cycleArray;
    void *oldBrk;

    static char* inputDataFileName[] = {"fft.c_FORD2_line354_1.ptrderefout.hd", "fft.c_FORD2_line354_1.ptrderefout.st", "fft.c_FORD2_line354_1.ptrderefout.gl"};
    static char heapDataFile[256] = {0};
    static char stackDataFile[256] = {0};
    static char globalDataFile[256] = {0};
    static uint64_t tsc_start = 0, tsc_end, loop_cycles = 0;
    static uint64_t min_tsc_cycles = LLONG_MAX, max_tsc_cycles = 0;
    static uint64_t mean_tsc_cycles = 0, median_tsc_cycles, stdv_tsc_cycles;

    if (argc < 3)
    {
        printf("Usage: %s path_to_data_files iterations\n", argv[0]);
        exit(1);
    }

    sprintf (heapDataFile, "%s/%s", argv[1], inputDataFileName[0]);
    sprintf (stackDataFile, "%s/%s", argv[1], inputDataFileName[1]);
    sprintf (globalDataFile, "%s/%s", argv[1], inputDataFileName[2]);

    iterations = atoi(argv[2]);

    for (int it = 0; it < iterations; it++)
    {
        b = (real *) b_;

        memcpy(&ij, &ij_, sizeof(ij_));
        memcpy(&l15, &l15_, sizeof(l15_));
        memcpy(&l14, &l14_, sizeof(l14_));
        memcpy(&l13, &l13_, sizeof(l13_));
        memcpy(&l12, &l12_, sizeof(l12_));
        memcpy(&l11, &l11_, sizeof(l11_));
        memcpy(&l10, &l10_, sizeof(l10_));
        memcpy(&l9, &l9_, sizeof(l9_));
        memcpy(&l8, &l8_, sizeof(l8_));
        memcpy(&l7, &l7_, sizeof(l7_));
        memcpy(&l6, &l6_, sizeof(l6_));
        memcpy(&l5, &l5_, sizeof(l5_));
        memcpy(&l4, &l4_, sizeof(l4_));
        memcpy(&l3, &l3_, sizeof(l3_));
        memcpy(&l2, &l2_, sizeof(l2_));
        memcpy(&l1, &l1_, sizeof(l1_));

        if (heapChunkSize > 0)
        {
            if (it < 1)
                oldBrk = mallocMemoryChunk(heapDataFile, minimumHeapAddress, maximumHeapAddress, heapChunkSize);
            else
                resetHeapData(minimumHeapAddress, maximumHeapAddress, heapChunkSize);
        }

        if (it < 1)
            cycleArray = getCycleArray(heapChunkSize, iterations);

        static long long stack_length = 0;
        register void* rsp __asm__ ("sp");
        register void *preRSP = rsp;
        void *storedTo;
        if (stackChunkSize > 0)
        {
            rsp = (void *) benStackPtrAddress;
            storedTo = saveCurrentStackToHeap(preRSP, stackBottomAddress, &stack_length);
            char* buffer = loadBenchStackToCurrentStack(stackDataFile, benStackPtrAddress, stackChunkSize);
            memcpy(rsp, buffer, stackChunkSize);
        }

        tsc_start = rdtsc();

        loop();

        tsc_end = rdtsc();

        loop_cycles = tsc_end - tsc_start;
        cycleArray[it] = loop_cycles;

        if (loop_cycles < min_tsc_cycles)
            min_tsc_cycles = loop_cycles;

        if (loop_cycles > max_tsc_cycles)
            max_tsc_cycles = loop_cycles;

        if (stackChunkSize > 0)
        {
            rsp = preRSP;
            if (stack_length > 0)
            {
                void *storeSpValAddr = getSavedAddress(storedTo);
                memcpy(rsp, storeSpValAddr, stack_length);
                restoreCurrentStack(storedTo, stack_length);
            }
        }

    }

    standardDeviation(cycleArray, iterations, &mean_tsc_cycles, &stdv_tsc_cycles);
    median_tsc_cycles = findMedian(cycleArray, iterations);

    if (heapChunkSize > 0)
        deleteMemoryMapping(oldBrk, maximumHeapAddress, heapChunkSize, iterations);
    else
        deleteCycleArray(cycleArray);

    printf("\n");
    printf("t: %f\n", t);
    printf("ji1: %d\n", ji1);
    printf("ij: %d\n", ij);
    printf("ij1: %d\n", ij1);
    printf("ji: %d\n", ji);
    printf("j14: %d\n", j14);
    printf("j13: %d\n", j13);
    printf("j12: %d\n", j12);
    printf("j11: %d\n", j11);
    printf("j10: %d\n", j10);
    printf("j9: %d\n", j9);
    printf("j8: %d\n", j8);
    printf("j7: %d\n", j7);
    printf("j6: %d\n", j6);
    printf("j5: %d\n", j5);
    printf("j4: %d\n", j4);
    printf("j3: %d\n", j3);
    printf("j2: %d\n", j2);
    printf("j1: %d\n", j1);

    void* ptrCheckSumVal = dummy(1, b);
    printf("The checksum of the addresses of pointer variables is: %p \n", ptrCheckSumVal);

    printf("Simulation time (cycles) stats:\n min\tmax\tmean\tmedian\tstdv\n");
    printf("%"PRIu64"\t%"PRIu64"\t%"PRIu64"\t%"PRIu64"\t%"PRIu64"\t\n", min_tsc_cycles, max_tsc_cycles, mean_tsc_cycles, median_tsc_cycles, stdv_tsc_cycles);

    return 0;
}
