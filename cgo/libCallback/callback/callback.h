#ifndef __TEST_H__
#define __TEST_H__
#ifdef __cplusplus
extern "C"{
#endif


typedef struct info{
    void* a;
    int  size;
}CInfo;

//C函数指针，函数原型一致
typedef int(*callbackFuncProto) (CInfo* n, char *roomId);

//接收C的函数指针，用于被C回调
int setcallback(callbackFuncProto s);

//回调函数触发器
void caller();

void freeObject();

#ifdef __cplusplus
}
#endif
#endif