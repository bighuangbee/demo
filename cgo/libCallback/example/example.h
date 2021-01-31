#ifndef API_H
#define API_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*IntCallback)(void *, int);

void SetIntCallback(IntCallback cb, void *data);

void DoIntCallback(int value);

#ifdef __cplusplus
}
#endif
#endif