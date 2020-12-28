#ifndef _KDM_MCUSDK_INCLUDE_
#define _KDM_MCUSDK_INCLUDE_

#include "McuSdkType.h"

#ifdef KDM_MCUSDK_EXPORTS
#define KDM_MCUSDK_API __declspec(dllexport)
#else
#define KDM_MCUSDK_API __declspec(dllimport)
#endif

#if defined (_MAC_IOS_) ||defined (_KDM_LINUX_) || defined (_ANDROID_)
#define STDCALL 
#define KDM_MCUSDK_API 
#else
#define STDCALL __stdcall
#endif

/**********************************************************************************
                                 KEDACOM
/**********************************************************************************

��ʹ�ýӿڵĹ�������Ҫע�⼸����
һ���豸ID����ID���豸ID��ָ�豸��ƽ̨�е�Ψһ�ı������У���ƽ̨�������ɣ��ͻ��˼�
SDKֻ��ȥʹ�ø��豸ID���в���������ID��ָƽ̨�����ʾ�ı������У��������ֲ�ͬ��ƽ̨

�����豸����ƵԴ�ͱ���ͨ������ƵԴ������Ƶ����Դ����һ��NVR�豸�Ͻӵ����ĸ�IPC����
����˵��NVR�豸���ĸ���ƵԴ�ֱ��Ӧ4��IPC������NVR�����а˸�����ͨ�����ֱ���Ա��
��ͬ��ʽ����������ÿ��IPC���Գ�1080P��720P�������������������������������ˣ����Կ�
��˵��NVR�豸��4����ƵԴ8������ͨ��

����Ŀǰ������Ȳ����У���ƵԴ��ֵ��ͨ����ֵͨ������ȵ�ֵ
/**********************************************************************************
**********************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif
    
     void*  Kdm_CreateMcuSdk();
     BOOL32 Kdm_Init(void *);
     BOOL32 Kdm_SubscriptDeviceStatus(void *pMcuHandle, TSUBSDEVS , ESubscriptInfo , OUT u32);


#ifdef __cplusplus
}
#endif



#endif
