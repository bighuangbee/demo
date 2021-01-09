#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long int A; // 64bit int
    long long int B; // 64bit int
} S;

extern void gostruct(S *struct_s) {
    printf("{-------A: %lld, B: %lld}\n", struct_s->A, struct_s->B);
}