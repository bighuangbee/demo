#include "callback.h"
#include <stdlib.h>
#include <string.h>

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

void call(){
    callback(&info, (char *)"room id, send by C func...");
}

void freeObject(){
    free(info.a);
}