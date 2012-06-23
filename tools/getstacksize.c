#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <gc.h>

#define BLOCKSIZE 4096

void sig_handl(int sig);

static volatile int *p;
static volatile int s;
int main(int argc, char **argv) {
    int base;

    GC_INIT();
    s = 0;
    p = &base;
    signal(SIGSEGV, sig_handl);
    while (1) {
	*p = 0;
	s ++;
	p --;
    }
}

void sig_handl(int sig) {
    printf("%d\n", s * sizeof(int));
    exit(0);
}
