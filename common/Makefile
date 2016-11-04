SRCS = $(wildcard *.c)
ORIG_LOOP = $(wildcard *.0.c)
ORIG_MAIN = $(addprefix ../, $(ORIG_LOOP:_loop.c.0.c=_main.c))
LOOPCOLLECTIONDIR=~/loop_collections
TIMERDIR = $(LOOPCOLLECTIONDIR)/common
LIBDIR = $(LOOPCOLLECTIONDIR)/common
CC = icc
STATICLIB = $(LIBDIR)/isolatedLoopUtility.a $(LIBDIR)/dummy.o

CFLAGS = -O3 -std=c99 -I$(TIMERDIR) -I$(HEADERFILEDIR) -I/usr/local/include -I/usr/include/x86_64-linux-gnu
LDFLAGS = -lcrypto -lssl -lm

ifeq ($(CCFAMILY), gcc)
    VECFLAGS = -ftree-vectorize -ffast-math -funsafe-loop-optimizations -ftree-loop-if-convert-stores -march=native -mtune=native
    NOVECFLAGS = -fno-tree-vectorize -ffast-math -funsafe-loop-optimizations -march=native -mtune=native
    ASMFLAGS = -S -fverbose-asm
else ifeq ($(CCFAMILY), icc)
    VECFLAGS = -xHost -vec -restrict -qopt-report=1 -qopt-report-phase=vec # -ipo
    NOVECFLAGS = -no-vec -restrict # -ipo
    ASMFLAGS = -S -fsource-asm
else ifeq ($(CCFAMILY), clang)
    VECFLAGS = -fvectorize -fslp-vectorize -fslp-vectorize-aggressive
    NOVECFLAGS = -fno-vectorize -fno-slp-vectorize
endif

VECFLAGS += $(VECTWEAK)

all: vec novec

novec: $(SRCS:.c=.novec)

vec: $(SRCS:.c=.vec)

asm: $(SRCS:.c=.s)

%.s: %.c
	$(CC) $(ASMFLAGS) $(VECFLAGS)  $^

%.novec: %.c main.o
	$(CC) $(CFLAGS) $(NOVECFLAGS)  $^ $(STATICLIB) -o $@ $(LDFLAGS)

%.vec: %.c main.o
	$(CC) $(CFLAGS) $(VECFLAGS)  $^ $(STATICLIB) -o $@ $(LDFLAGS)

main.o: $(ORIG_MAIN)
	$(CC) $(CFLAGS) $(VECFLAGS) $< -c -o $@

clean:
	-rm -f *.o *.novec *.vec

