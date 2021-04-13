#ifndef __TEST_H__
#define __TEST_H__
#ifdef __cplusplus
extern "C"{
#endif


typedef struct info{
    void* a;
    int  size;
}CInfo;

//可被C调用的函数
typedef int(*callbackFuncProto) (CInfo* n, char *roomId);

int setcallback(callbackFuncProto s);

void call();

void freeObject();

#ifdef __cplusplus
}
#endif
#endif