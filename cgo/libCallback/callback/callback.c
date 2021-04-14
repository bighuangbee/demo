#include "callback.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

callbackFuncProto callback;
CInfo info;

int setcallback(callbackFuncProto foo){
    callback = foo;
    info.a = malloc(3);
    info.size = 3;
    char t[3] = "c";
    memcpy(info.a, t, 3);
    return 1;
}

void caller(){
    int r = callback(&info, (char *)" call from C func");
    printf("---%d", r);
}

void freeObject(){
    free(info.a);
}