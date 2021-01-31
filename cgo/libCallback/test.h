#ifndef __TEST_H__
#define __TEST_H__
#ifdef __cplusplus
extern "C"{
#endif


typedef struct info{
    void* a;
    int  size;
}CInfo;

typedef int(*callbackFuncProto) (CInfo* n, char *roomId);

int setcallback(callbackFuncProto s);

void call();

void clean();

#ifdef __cplusplus
}
#endif
#endif