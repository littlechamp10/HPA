SRCS = $(wildcard *.c)

#LOOPCOLLECTIONDIR=/home/neftali/loop_collections
LOOPCOLLECTIONDIR=/Users/siddharthgupta/Desktop/UCI/Classes@UCI/2.1-Fall_2016/HPA/Project
HEADERFILEDIR=../input
TIMERDIR=$(LOOPCOLLECTIONDIR)/common
DUMMYDIR=$(LOOPCOLLECTIONDIR)/common
CC=icc
DUMMYSRC=$(DUMMYDIR)/dummy.c
DUMMYOBJ=$(DUMMYSRC:.c=.o)

STATICLIB=$(DUMMYDIR)/isolatedLoopUtility.a

CFLAGS=-O3 -g -std=c99 -I$(TIMERDIR) -I$(HEADERFILEDIR)
LDFLAGS=-lcrypto -lssl -lm

ifeq ($(CC), gcc)
    VECFLAGS = -ftree-vectorize 
    NOVECFLAGS = -fno-tree-vectorize
else ifeq ($(CC), icc)
    VECFLAGS = -xHost -vec-threshold100 -vec -qopt-report-phase=vec -qopt-report=5
    FVECFLAGS = -xHost -vec-threshold0 -vec 
    NOVECFLAGS = -no-vec
else ifeq ($(CC), clang)
    VECFLAGS = -fvectorize -fslp-vectorize -fslp-vectorize-aggressive 
    NOVECFLAGS = -fno-vectorize -fno-slp-vectorize
endif

all:

novec: $(DUMMYOBJ) $(patsubst %_main.c,%.novec,$(SRCS))

#vec: $(DUMMYOBJ) $(SRCS:.c=.vec)
vec: $(DUMMYOBJ) $(patsubst %_main.c,%.vec,$(SRCS))
fvec: $(DUMMYOBJ) $(patsubst %_main.c,%.fvec,$(SRCS))

#all: $(SRCS:.c=)

#.c:
# $(CC) $(CFLAGS) $< $(DUMMYDIR)/dummy.c $(STATICLIB) -o $@ $(LDFLAGS)

# %.novec: %_main.c %_loop.c
# 	$(CC) $(CFLAGS) $(NOVECFLAGS)  $^ $(DUMMYOBJ) $(STATICLIB) -o $@ $(LDFLAGS)

# %.vec: %_main.c %_loop.c
# 	$(CC) $(CFLAGS) $(VECFLAGS) $^ $(DUMMYOBJ) $(STATICLIB) -o $@ $(LDFLAGS)
# 	rm -f *main.optrpt
# %.fvec: %_main.c %_loop.c
# 	$(CC) $(CFLAGS) $(FVECFLAGS) $^ $(DUMMYOBJ) $(STATICLIB) -o $@ $(LDFLAGS)
# 	rm -f *main.optrpt

%.novec: %_main.c %_loop.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(NOVECFLAGS) $^ $(DUMMYOBJ) $(STATICLIB) -o $@ 

%.vec: %_main.c %_loop.c
	$(CC) $(LDFLAGS) $(CFLAGS) $(VECFLAGS) $^ $(DUMMYOBJ) $(STATICLIB) -o $@
	rm -f *main.optrpt
%.fvec: %_main.c %_loop.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(FVECFLAGS) $^ $(DUMMYOBJ) $(STATICLIB) -o $@
	rm -f *main.optrpt

clean:
	rm -f *.o *.novec *.vec *.optrpt *.fvec

