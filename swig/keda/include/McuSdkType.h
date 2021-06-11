//
//  McuSdkType.h
//  McuSdk
//
//  Created by dqw on 14-5-16.
//  Copyright (c) 2014ƒÍ ___kedacom___. All rights reserved.
//

#ifndef McuSdk_McuSdkType_h
#define McuSdk_McuSdkType_h

#include "kdvtype.h"
#include <string.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define MAX_TCP_PLAY_NUM			16
#define MAX_ALL_PLAY_NUM			128
#define MAX_UDP_PLAY_NUM			(MAX_ALL_PLAY_NUM - MAX_TCP_PLAY_NUM - 1)
#define RECORD_DOWDLOAD_PLAYID		MAX_TCP_PLAY_NUM
#define MAX_1_0_ALL_PLAY_NUM			64 //1.0ƽ̨���ʵʱ���·��Ϊ64���������ᵼ��ƽ̨vtdu��������Ϣ

#define MAX_WATCH_ON_NUM 8
#define ADDR_STR_LEN 64
#define MAX_ID_LEN 128
#define MAX_NAME_LEN 256
#define MAX_SHOT_NAME_LEN 64

#define MAX_VID_SRC_NUM 128
#define MAX_VID_CHN_NUM 256
#define MAX_SM_STR_LEN 256
#define MAX_URL_LEN 256
#define MAX_DESC_LEN 128
#define MAX_DEV_DIR	256

#define MAX_ADDR_LEN 128
#define MAX_LOCAL_IP_NUM 10

#define MAX_REQ_DEV_SUBS_NUM 20
#define MAX_LOG_QUERY_NUM 25
#define LEN_KDM_NO         32 
#define MAXNUM_SRCPU_POLL    64  //��ѯ������������


#define INVALID_TASK_ID 0
#define INVALID_STREAM_INDEX (u32)0xFFFF
#define INVALID_CODEC_INDEX (u32)0xFFFF

#define MAX_STREAM_URL_NUM 20

#define MAX_DISPLAY_CONTENT_LEN 128
    
#define MAX_SUPPORT_VIDEO_TYPE_NUM 8
#define MAX_SUPPORT_VIDEO_TYPE_NUM_V2 16

#define MAX_TRANSCHAN_DATA_LEN 512
#define MAX_TRANSCHAN_DATA_LEN_V2 (8*1024)
#define MAX_TRANSCHAN_MSGTYPEGB_LEN 64

#define STREAM_URL_SELECT_INDEX_INVAILED 65535	//�Ƿ���url ���к�

#define MAX_PWD 32
#define MAX_SCH_LEN 32
#define MAX_DECODE_CHN_NUM 64

#define MAXLEN_FILEPATH 128
#define MAXLEN_FILENAME 128
#define MAXLEN_ALIAS 64
#define MAXLEN_DEVICE_MANUFACTURER 32

#define MAX_Process_NUM 128

#define MAX_GROUP_DEEPTH 10	// �����豸�����.

#define MAX_MULTIVIEW_DEVICE_TREE_NUM 128	//������ͼ�豸��������(ƽ̨Ŀǰ���ֵ��5)

#define MAX_OSD_LINE_NUM 5  //osd��ĸ�������

#define MAX_GENERAL_ARRAY_NUM  64 // һ�������Ĵ�С
#define MAX_TIME_LIST_NUM 128
#define MAX_PARTITION_NUM 16
// ���������������������� +by lzx@2015-11-12.
#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef INOUT
#define INOUT
#endif

/*ý�����Ͷ���*/

#define   MEDIA_TYPE_NULL                   (u8)255  /*ý������Ϊ��*/
    
/*��Ƶ*/
#define   MEDIA_TYPE_OPUS                 (u8)117  //OPUS����ֵ
#define   MEDIA_TYPE_AACLD                (u8)103
#define   MEDIA_TYPE_AACLC_PCM			  (u8)104
#define   MEDIA_TYPE_MP2                  (u8)14
#define   MEDIA_TYPE_AACLC_32K            (u8)108
#define   MEDIA_TYPE_AACLC_48K            (u8)109

#define   MEDIA_TYPE_MP3                    (u8)99  /*mp3 mode 0-4*/
#define   MEDIA_TYPE_G7221C                 (u8)98  /*G722.1.C Siren14*/
#define   MEDIA_TYPE_PCMA                   (u8)8   /*G.711 Alaw  mode 5*/
#define   MEDIA_TYPE_PCMU                   (u8)0   /*G.711 ulaw  mode 6*/
#define   MEDIA_TYPE_G721                   (u8)2   /*G.721*/
#define   MEDIA_TYPE_G722                   (u8)9   /*G.722*/
#define   MEDIA_TYPE_G7231                  (u8)4   /*G.7231*/
#define   MEDIA_TYPE_ADPCM                  (u8)5   /*DVI4 ADPCM*/
#define   MEDIA_TYPE_G728                   (u8)15  /*G.728*/
#define   MEDIA_TYPE_G729                   (u8)18  /*G.729*/
#define   MEDIA_TYPE_G7221                  (u8)13  /*G.7221*/
#define   MEDIA_TYPE_AACLC                  (u8)102
#define   MEDIA_TYPE_AMR                    (u8)105

/*��Ƶ*/
#define   MEDIA_TYPE_PS                      (u8)96  /*ps��*/
#define   MEDIA_TYPE_MP4                    (u8)97  /*MPEG-4*/
#define   MEDIA_TYPE_H261                   (u8)31  /*H.261*/
#define   MEDIA_TYPE_H262                   (u8)33  /*H.262 (MPEG-2)*/
#define   MEDIA_TYPE_MJPEG                  (u8)26  
#define   MEDIA_TYPE_H263                   (u8)34  /*H.263*/
#define   MEDIA_TYPE_H263PLUS               (u8)101 /*H.263+*/
#define   MEDIA_TYPE_H264                   (u8)106 /*H.264*/
#define	  MEDIA_TYPE_FEC				    (u8)107 /* fec custom define */
#define   MEDIA_TYPE_MPEG2                  (u8)95
#define   MEDIA_TYPE_H265					(u8)111 /*H.265*/ 

enum McuErrorCode
{
    RTN_OK 														=0,		//����SDK�ṹ�ɹ�										

	//add by xql 20140916 for startplay error
	MCU_PLAYER_ERR_MVC_CONNECT_MVS_FAILED						=10120,//MVC����MVSʱTCP��·����ʧ��
	MCU_PLAYER_ERR_MEDIANET_CREATE_FAILED                       =16004,//����medianet����ʧ�ܣ�16004���󣬿����Ƕ˿ڱ�ռ�û���֡�ص�������        

	MODUAL_INVALID 												=60001, // ��Чģ��
    TASK_INVALID 												=60002, // ��Ч����
    TASK_CREATE_ERROR 											=60003, // ��������ʧ��
    INPUT_ERROR 												=60004, // �������
    GET_DATA_ERROR 												=60005, // ��ȡ���ݴ���
    NET_ERROR													=60006, // �������
    SNAPSHOT_ERROR 												=60007, //
    DGROUP_ROOT_INFO_ERROR 										=60008,//��½ʱ��ȡ��ƽ̨����Ϣ����
	NOT_IMPLEMENT												=60009,//�ӿ�δʵ�ֻ�֧��
	MCU_ERRCODE_LOGIN_ERR_FIRST_DOMAIN_ERR						=60010,//��½������һ������ʧ��
	MCU_ERRCODE_LOGIN_ERR_SECOND_DOMAIN_ERR 					=60011,//��½�����ڶ�������ʧ��
	MCU_ERRCODE_LOGIN_ERR_PLAT_DOMAIN_ERR						=60012,//��½����ƽ̨������ʧ��
	NTP_NETWORK_ERROR											=60013,//�������
	GET_DEVICES_INFO_TIME_OUT									=60014,//��ȡ�豸��Ϣ��ʱ
	DEVICE_NOT_ONLINE											=60015,//�豸������
	DEVICE_TO_GBDEVICE_FAILED									=60016,//�豸idת����idʧ��
	DEVICE_STREAM_URL_EMPTY										=60017,//mss���ص�����urlΪ��
	PLAY_ID_NOT_EXIST										    =60018,//����ID������
	MCUSDK_ERROR_MODULE_NOT_INIT                                =60019,//ģ��δ��ʼ��
	UNSUPPORT_VIDEO_TYPE                                        =60020,//����¼����Ƶ���Ͳ�֧��

	LOCAL_RECORD_FILE_TOO_SHORT = 60038,//����¼���ļ�̫С����ֹͣ����¼���ʱ����ܻ᷵�����������

	//TCP��Ƶ���Ŵ�����(SDK Ԥ��100��������61000 - 61099)
    MCU_PLAYER_ERR_STREAM_GET_IDLE_STREAM 						=61000,//����ģ��������ʧ��
	MCU_PLAYER_ERR_DECODER_GET_IDLE_DECODER						=61001,//����ģ��������ʧ��
	MCU_PLAYER_ERR_DECODER_CREATE								=61002,//����������ʧ��
    MCU_PLAYER_ERR_DECODER_START_PLAY_STREAM					=61003,//��������ģ��ʧ��
    MCU_PLAYER_ERR_DECODER_START_PLAY_WND						=61004,//��ʾģ���ʼ��ʧ��
	MCU_PLAYER_ERR_CONVERT_GB_DEVICED_ID						=61005,//devicedIDת����IDʧ��
	MCU_PLAYER_ERR_G900_INIT_FAIL								=61006,//G900ģ���ʼ��ʧ��
	MCU_PLAYER_ERR_FROM_G900_GET_URL							=61007,//��G900��ȡURLʧ��
	MCU_PLAYER_ERR_G900_START_REQ_FAIL							=61008,//g900ģ�鷢���������ʧ��
	MCU_PLAYER_ERR_DEVICES_OFFLINE								=61009,//�豸������
	MCU_PLAYER_ERR_G900_URL_NOT_SUPPORT_ALL						=61010,//g900���ص�url�ֱ��ʲ�֧��
	MUC_PLAYER_ERR_NO_KEY_FRAME_COME							=61011,//�����ؼ���û�й���
	
	MCU_PLAYER_ERR_CONNECT_MVC_FAIL 							=61020,//mvc����mvsʧ��
	MCU_PLAYER_ERR_CONNECT_MVC_TIMEOUT							=61021,//mvc����mvs��ʱ
	MCU_PLAYER_ERR_DISCONNECT_MVC_NTF							=61022,//�յ�mvs����֪ͨ
	
    MCU_PLAYER_ERR_G900_ERR_FAIL 								=61091,//G900����
    MCU_PLAYER_ERR_G900_ERR_UNINIT 								=61092,//G900δ��ʼ��
    MCU_PLAYER_ERR_G900_ERR_UNCONNECT 							=61093,//δ����G900
    MCU_PLAYER_ERR_G900_ERR_PARAM 								=61094,//G900 ��������
    MCU_PLAYER_ERR_G900_ERR_INVALID_PLAYEID						=61095,//G900 playid��Ч	
    MCU_PLAYER_ERR_G900_TIMEOUT									=61096,//G900 ����ʱ

	//UDP��Ƶ���Ŵ�����(SDK Ԥ��100��������61100 - 61199)
	MCU_PLAYER_ERR_UDP_DVC_NOT_ONLIE							=61100, //udp����������ʽ�豸������
	MCU_PLAYER_ERR_UDP_CHN_NOT_ONLIE							=61101,	//UDP����������ʽʱ��ƵԴ��Ӧ��ͨ��ȫ������
	MCU_PLAYER_ERR_UDP_GET_CHNINFO_ERR							=61102, //udp����������ʽ��sdk�ڻ�ȡͨ����Ϣ����
	MCU_PLAYER_ERR_UDP_SETUP_STREAM_ERR_CONNECT_PLAT			=61103,	//udp������������rtp��rtcp�˿�����ƽ̨����
	MCU_PLAYER_ERR_UDP_SETUP_STREAM_ERR_RSP_ERR					=61104,	//udp������������rtp��rtcp�˿�ƽ̨���ؽ������
	MCU_PLAYER_ERR_UDP_SETUP_STREAM_ERR_KEY_FRAME_CONNECT_PLAT	=61105,	//udp����������ƽ̨����ؼ�֡����ƽ̨����
	MCU_PLAYER_ERR_UDP_SETUP_STREAM_ERR_KEY_FRAME_RSP_ERR		=61106,	//udp����������ƽ̨����ؼ�֡ƽ̨���ؽ������
	MCU_PLAYER_ERR_UDP_Get_IDLE_DECODER							=61107, //UDP�����������������еĴ���ģ��ʧ��
	MCU_PLAYER_ERR_UDP_INIT_KDV_MEDIA_RCV_ERR					=61108,	//UDP����������ʼ��medianet����ģ��ʧ��
	MCU_PLAYER_ERR_UDP_START_KDV_MEDIA_RCV_ERR					=61109,	//UDP��������medianet��ʼ��������ʧ��
	MCU_PLAYER_ERR_UDP_START_KDV_VIDEO_PROBE_ERR				=61110,	//UDP��������Video��NATʧ��
	MCU_PLAYER_ERR_UDP_START_KDV_AUDIO_PROBE_ERR				=61111, //UDP��������Audio��NATʧ��

	//¼�񲥷ź�������ش�����(SDK Ԥ��100 ��������61200-61299)
	MCU_RECORD_QUERY_RECORD_THREAD_NOT_NULL						=61200,//��ѯ¼���ļ��߳��Ѵ���
	MCU_ERRCODE_QUERY_RECORD_TASKID_NOT_EXITS 					=61201,//��ѯƽ̨¼���taskID������
	MCU_ERRCODE_QUERY_RECORD_MANAGER_NULL						=61202,//��ѯƽ̨¼��ʱ���ݹ���ģ��ΪNULL
	MCU_ERRCODE_QUERY_RECORD_MANAGER_GET_DATA_NULL 				=61203,//��ѯƽ̨¼��ʱ���ݹ���ģ���ȡ����ΪNULL
	MCU_ERRCODE_QUERY_RECORD_QUERY_REQ_FAILED 					=61204,//��ѯƽ̨¼����ִ���
	MCU_ERRCODE_QUERY_RECORD_QUERY_RSP_FAILED 					=61205,//��ѯƽ̨¼�񷵻ؽ�����ִ���
    MCU_ERRCODE_QUERY_RECORD_QUERY_NUM_ZERO 					=61206,//��ƽ̨20��ȡ��¼���ļ�����Ϊ0
    MCU_ERRCODE_RECORD_SEEK_TIME_OUT_RANG 						=61207,//vcr����ʱseektimeʱ����ļ�
    MCU_ERRCODE_RECORD_STOP_PLAY_NTF							=61208,//¼��ط�ֹ֪ͣͨ
    MCU_ERRCODE_RECORD_TYPE_WRONG								=61209,//¼�����Ͳ�������
    MCU_ERRCODE_RECORD_GET_DEV_CHN_WRONG 						=61210,//¼��ط�ʱ��ѯ�豸��Ϣ����
    MCU_ERRCODE_RECORD_GET_TIME_RANGE 							=61211,//¼��ط�ʱ��ȡ¼��ʼ����ʱ�����
    MCU_ERRCODE_VCR_RECORD_TYPE_ERR								=61212,//¼��ط�vcr����ʱ¼�����Ͳ���
    MCU_ERRCODE_VCR_GET_PU_RECORD_MANAGER_ERR					=61213,//��ȡǰ��¼�������ʵ������
    MCU_ERRCODE_VCR_GET_CENTER_RECORD_MANAGER_ERR				=61214,//��ȡƽ̨¼�����ʵ������
    MCU_ERRCODE_QUERY_RECORD_NO_PERMISSION 			        	=61215,//�û�û�в�ѯ�Ͳ���¼���Ȩ��
	MCU_ERRCODE_QUERY_RECORDLIST_UNSUPPORT                      =61216,//ǰ���豸��֧�ֲ�ѯ¼������

    MCU_RECORD_DOWNLOAD_ERR_CREATE_KEDAPLAYER_ERR 				=61250,//¼�����ش���kedaplayer����
    MCU_RECORD_DOWNLOAD_ERR_PLATFORM_CONNECT_FAIL 				=61251,//¼����������ƽ̨����
    MCU_RECORD_DOWNLOAD_ERR_PLATFORM_DIRCRIPTION_NULL 			=61252,//¼�����������ļ�Ϊ��
	MCU_RECORD_DOWNLOAD_ERR_LOCAL_DISK_FULL						=61253,//���ش��̿տռ�����
	MCU_RECORD_DOWNLOAD_ERR_LOCAL_FULL_NAME_NULL 				=61254,//���ر����ļ���Ϊ��
	MCU_RECORD_DOWNLOAD_ERR_DOWNLOAD_ERR						=61255,//¼�������������
	MCU_RECORD_DOWNLOAD_ERR_LAST_RECORD_FILE_STOP_FAIL          =61256,//¼��������һ���ļ�ֹͣʧ��
	MCU_RECORD_DOWNLOAD_ERR_NEXT_RECORD_FILE_START_FAIL         =61257,//¼��������һ���ļ���ʼʧ��
	MCU_RECORD_DOWNLOAD_ERR_RECORD_TYPE_CONFLICT                =61258,//¼�����ص�¼��������Ԥ���ز�ѯʱ��һ��

	MCU_RECORD_DOWNLOAD_ERR_RPCTRL_FAILED                       = 61259,//RPCTRL����ʱ��ͨ�ô�����
	MCU_ERRCODE_WATERMARK_RECORD_FAILED                         = 61260,//ˮӡ¼��ʧ��   

	//����ǽ����ش�����(��Ԥ������Ѳ��SDK Ԥ��100��������61300 - 61399)
	MCU_TVWALL_ERR_CONNECT_PLAT_ERR								=61300,//����ǽ����ƽ̨����
	MCU_TVWALL_ERR_GET_TV_WALL_MANAGER_ERR						=61301,//����ǽ�͵���ǽԤ����ȡ����ǽ������ʵ������
	MCU_TVWALL_ERR_GET_TV_WALL_SINGAL_ERR						=61302,//��ȡ��������ǽ��Ϣ����
	MCU_TVWALL_ERR_GET_TVWALL_DECODER_BIND_SIZE_ERR				=61303,//��ȡ����ǽ�Ľ������󶨵ĸ�������
	MCU_TVWALL_ERR_DECODER_SIZE_LESS_THAN_ID					=61304,//ID���ڽ������İ󶨸���
	MCU_TVWALL_ERR_GET_DECODER_STYLE_ERR						=61305,//��ȡ���������������
	MCU_TVWALL_ERR_VIDEO_MANAGER_INSTANCE_NULL					=61306,//¼��ط���ǽ��¼��������ʵ��Ϊ��
	MCU_TVWALL_ERR_GET_PLAT_VIDEO_INFO_ERR						=61307,//��ȡƽ̨¼�����Ϣʧ��
	MCU_TVWALL_ERR_GET_PU_VIDEO_INFO_ERR						=61308,//��ȡǰ��¼�����Ϣʧ��
	MCU_TVWALL_ERR_DECODER_BIND_NOT_FIND_ERR					=61309,//¼��ط���ǽ�������İ�ʧ��
	MCU_TVWALL_ERR_TO_TVWALL_RECORDTYPE_ERR						=61310,//¼��ط�¼�����ʹ���
	MCU_TAWALL_SCHEME_ERR_GET_SINGAL_SCHEME_ERR					=61311,//����ǽԤ���л�ȡ����Ԥ����Ϣʧ��

    //�����豸������(SDKԤ��100 �������� 61400 - 61499)
	MCU_SERACH_DVC_THREAD_EXITS 								=61400,//�����豸�߳��Ѵ���
	MCU_SERACH_DVC_NO_DEVICES 									=61401,//�������豸

	//��Ƶ������ش�����(SDK Ԥ��100  �������� 61500 - 61599)
    MCU_CALL_PU_GET_LOCAL_IP_ERR								=61500,//��Ƶ����ʱ��ȡ�ͻ��˱���ip����
    MCU_CALL_PU_GET_PLAT_RSP_ERR								=61502,//��Ƶ����ʱ����ƽ̨��ȡrsp����
    MCU_CALL_PU_RECV_IP_SIZE_ZERO								=61503,//��Ƶ����ʱƽ̨���ص�size��С����
    MCU_CALL_PU_GET_PLAT_IP_PORT_ERR							=61504,//��Ƶ����ʱ����ƽ̨��ȡ�˿ڴ���
	MCU_CALL_PU_DEVICE_AUDDEC_CHN_IS_ZERO						=61505,//�豸��֧����Ƶ����
	MCU_CALL_PU_CREATE_AUDIO_CAPTURE_FAILED                     =61506,//������Ƶ�ɼ�ʧ�ܣ���ȷ����˷����

	//URL���Ŵ�����(SDKԤ��100 �������� 61600 - 61699)
	MCU_URL_PLAY_PLUGIN_NOT_EXIST								=61600,//url���Ų����ӿڲ�����	
	MCU_URL_PLAY_URL_INVALID									=61601,//url���ŵ�url�����Ƿ�
	MCU_URL_PLAY_CREATE_PLAY_HANDLE_FAILED						=61602,//url���Ŵ������ž��ʧ��
	MCU_URL_PLAY_FAILED											=61603,//url����ʧ��
	MCU_URL_PLAY_GENERATE_PLAY_ID_FAILED						=61604,//url�������ɲ���ID
	MCU_URL_PLAY_ID_NOT_EXIST									=61605,//url����ID������
	MCU_URL_PLAY_TYPE_INVALID									=61606,//url���ŵ����ͷǷ�
	MCU_URL_PLAY_HANDLE_INVALID									=61607,//url���ŵľ���Ƿ�
	MCU_URL_PLAY_CONTROL_FAILED									=61608,//url����ʧ��
	MCU_URL_PLAY_UNIPLAY_PLUGIN_NOT_EXIST                       =61609,//uniplay������������
	MCU_URL_PLAY_START_LOCAL_RECORD_FAILED                      =61610,//��������¼��ʧ��
	MCU_URL_PLAY_STOP_LOCAL_RECORD_FAILED                       =61611,//ֹͣ����¼��ʧ��
	
	//SOAP��ش�����(SDKԤ��100�������� 64000-64099)
	
 	MCU_SDK_ERRCODE_SOAP_OK										=64000,
 	MCU_SDK_ERRCODE_SOAP_CLI_FAULT								=64001,
 	MCU_SDK_ERRCODE_SOAP_SVR_FAULT								=64002,
 	MCU_SDK_ERRCODE_SOAP_TAG_MISMATCH							=64003,
 	MCU_SDK_ERRCODE_SOAP_TYPE									=64004,
 	MCU_SDK_ERRCODE_SOAP_SYNTAX_ERROR							=64005,
 	MCU_SDK_ERRCODE_SOAP_NO_TAG									=64006,
 	MCU_SDK_ERRCODE_SOAP_IOB									=64007,
 	MCU_SDK_ERRCODE_SOAP_MUSTUNDERSTAND							=64008,
 	MCU_SDK_ERRCODE_SOAP_NAMESPACE								=64009,
 	MCU_SDK_ERRCODE_SOAP_USER_ERROR								=64010,
 	MCU_SDK_ERRCODE_SOAP_FATAL_ERROR							=64011,
 	MCU_SDK_ERRCODE_SOAP_FAULT									=64012,
 	MCU_SDK_ERRCODE_SOAP_NO_METHOD								=64013,
 	MCU_SDK_ERRCODE_SOAP_NO_DATA								=64014,
 	MCU_SDK_ERRCODE_SOAP_GET_METHOD								=64015,
 	MCU_SDK_ERRCODE_SOAP_PUT_METHOD								=64016,
 	MCU_SDK_ERRCODE_SOAP_DEL_METHOD								=64017,	/* deprecated */
 	MCU_SDK_ERRCODE_SOAP_HEAD_METHOD							=64018,	/* deprecated */
 	MCU_SDK_ERRCODE_SOAP_HTTP_METHOD							=64019,
 	MCU_SDK_ERRCODE_SOAP_EOM									=64020,
 	MCU_SDK_ERRCODE_SOAP_MOE									=64021,
 	MCU_SDK_ERRCODE_SOAP_HDR									=64022,
 	MCU_SDK_ERRCODE_SOAP_NULL									=64023,
 	MCU_SDK_ERRCODE_SOAP_DUPLICATE_ID							=64024,
 	MCU_SDK_ERRCODE_SOAP_MISSING_ID								=64025,
 	MCU_SDK_ERRCODE_SOAP_HREF									=64026,
 	MCU_SDK_ERRCODE_SOAP_UDP_ERROR								=64027,
 	MCU_SDK_ERRCODE_SOAP_TCP_ERROR								=64028,
 	MCU_SDK_ERRCODE_SOAP_HTTP_ERROR								=64029,
 	MCU_SDK_ERRCODE_SOAP_SSL_ERROR								=64030,
 	MCU_SDK_ERRCODE_SOAP_ZLIB_ERROR								=64031,
 	MCU_SDK_ERRCODE_SOAP_DIME_ERROR								=64032,
 	MCU_SDK_ERRCODE_SOAP_DIME_HREF								=64033,
 	MCU_SDK_ERRCODE_SOAP_DIME_MISMATCH							=64034,
 	MCU_SDK_ERRCODE_SOAP_DIME_END								=64035,
 	MCU_SDK_ERRCODE_SOAP_MIME_ERROR								=64036,
 	MCU_SDK_ERRCODE_SOAP_MIME_HREF								=64037,
 	MCU_SDK_ERRCODE_SOAP_MIME_END								=64038,
 	MCU_SDK_ERRCODE_SOAP_VERSIONMISMATCH						=64039,
 	MCU_SDK_ERRCODE_SOAP_PLUGIN_ERROR							=64040,
 	MCU_SDK_ERRCODE_SOAP_DATAENCODINGUNKNOWN					=64041,
 	MCU_SDK_ERRCODE_SOAP_REQUIRED								=64042,
 	MCU_SDK_ERRCODE_SOAP_PROHIBITED								=64043,
 	MCU_SDK_ERRCODE_SOAP_OCCURS									=64044,
 	MCU_SDK_ERRCODE_SOAP_LENGTH									=64045,
 	MCU_SDK_ERRCODE_SOAP_FD_EXCEEDED							=64046,
	MCU_SDK_ERRCODE_SOAP_RECV_TIME_OUT							=64050,		//SOAP RECV MESSAGE TIME OUT
	
	//change password
	MCU_SDK_CHANGEPWD_ERR_NULL									=65000,
	MCU_SDK_CHANGEPWD_ERR_EQUAL									=65001,

	// ��ȡcivilcode
	MCU_SDK_GB_ERR_PARAM_NULL									=65010,	// ����Ϊ0.

	MCU_SDK_LOG_ERR_VERSION_CLASH                               =65011,//����־V2�ӿ�ǰʹ�����ϵ���־�ӿڣ�ע���ϲ㲻�ɻ�����־�ӿ�
	MCU_SDK_LOG_ERR_START                                       =65012,//������־ʧ��
	MCU_SDK_LOG_ERR_FILEOPEN                                    =65013,//����־ʧ��
	
	//other
	OCX_INIT_ERR 												=66000,//��ʼ������
	OCX_WAIT_REC_OVERTIME										=66001,//¼���ѯ�ȴ�������־��ʱ
	OCX_UNINIT_ERR												=66002,//����ʼ������
};

enum EDecoderMod
{
	emDecoderModUnable = 0,   //��ʹ��SDK�ڲ�������
	emBaseDec = 1,            //ʹ��SDK�ڲ�������ʾ
};
	
enum EStreamMod
{
	emStreamModUnable = 0,
	emPlat1 = 1,
	emPlat2 = 2,
	emG900 = 3,
};
	
enum EBussinessMod
{
	emBussinessModUnable = 0,
	emPlat1BS = 1,
	emPlat2BS = 2,
};

enum eLogLevel
{
	emLevNull = 0,       //���κδ�ӡ   
	emLevError = 1,      //���󼶱�
	emLevWarn = 2,       //���漶��
	emLevCritical = 4,   //�ؼ�����
	emLevInfo = 8,       //��ͨ����
	emLevDebug = 16,     //���Լ���
	emLevAll = 255,      //���м���
};

enum EWatchTYPE
{
	emWatchInVailed = 0,
	emWatchTask = 1,
	emWatchPrePos =2,
};

//��ȡ�豸���豸�������Ϣ����Ϣ����
enum EDevGroupExtraInfoType
{
	emExGrpNull = 0,
	emExGrpDescrition = 1,		//���������Ϣ								�ַ���
	emExGrpHasDevice = 2,	//�����Ƿ����豸�������ݹ���¼��豸�飩	bool
};
enum EDeviceExtraInfoType
{
	emExDevNull=0,
	emExDevIsGB = 1,		//�豸�Ƿ�Ϊ�����豸�ı��		bool
	emExDevModel = 2,	//pmc����ʱ����豸�ͺ�					�ַ���
	emExDevName = 3,	//��ȡ�豸����										�ַ���
	emExDevDomainID = 4,//�豸������ID									�ַ���
	emExDevManufactor = 5,//�豸����										�ַ���
	emExDevOnline = 6,	//�豸�Ƿ�����										bool
	emExDevVideoSrcNum = 7,	//��ƵԴ����							��ֵ
	emExDevType=8,			 // �豸���� DeviceInfo::eDeviceType			��ֵ
	emExDevCap=9,			 //�豸���� DeviceInfo::eDeviceCap				��ֵ	
	emExDevVSInGroup=10,	//�豸��ָ�����µ���ƵԴ�б�		�ַ���	������"1,3,5" ��������ʽ�ṩ��ÿһλ��ֵ��ʾ��ƵԴID��
	emExDevGroup=11,		//�豸�����飨���ֻ���ƽ̨1.0��2.0ƽֻ̨����ƵԴ���и���ĸ��

    emExDevPriPURecStart=12, // ǰ��¼����Ȩ��     bool true �и�Ȩ��  false û�и�Ȩ��
    emExDevPriPURecPlay=13, //ǰ��¼��ط�Ȩ��
    emExDevPriPURecDownload=14, //ǰ��¼������Ȩ��
    emExDevPriPUConfig=15, //ǰ�˲�������Ȩ��
    emExDevPriPUAlarmConfig=16, //  ǰ�˲�������Ȩ��
	emExDevIP=17,           //�豸ip��ַ
	emExDevDecodeChnNum=18,	//�豸�Ľ���ͨ������ ��ֵ��
	emExDevVideoOutputChnNum = 19,	//�豸����Ƶ���ͨ������ ��ֵ��
	emExDevKdmNo=20,        //�豸��kdmNo
};
enum EVideoSrcExtraInfoType
{
	emExVsNull=0,
	emExVsPtzPrivilage = 1,		//��ȡָ����ƵԴ��PTZȨ��ֵ��0��ʾû��Ȩ�ޣ�ֵԽ���ʾȨ��Խ��					int
	emExVsName = 2,						//��ƵԴ����					�ַ���
	emExVsValid = 3,						//��ƵԴ�Ƿ�����			bool
	emExVsOnline = 4,						//��ƵԴ�Ƿ�����			bool
	emExVsChns = 5,						//��ƵԴ������ͨ����	�ַ���				������"1,3,5" ��������ʽ�ṩ����1��ͨ����ʾ����ͨ����������ʾ����ͨ��������У�
	emExVsValidAndOnline = 6,		//ͬʱ��ȡemExVsValid��emExVsOnline		bool[2] ����Ӧ���� int rslt[2] ָ�봫�ݷ���ֵrslt[0]ΪemExVsValid,rslt[1]ΪemExVsOnline
    emExVsPtzCtrlLevel = 7,  // �ƾ����Ƽ���   int  ���ؿ��Ƽ���
    emExVsPriPuAudioCtrl = 8,  // ǰ����������Ȩ��  bool true �и�Ȩ�ޣ� false û�и�Ȩ��
    emExVsPriPuSavePreset = 9, // Ԥ��λ����Ȩ��
    emExVsPriPuPtzLock = 10, //��̨����Ȩ��
	emExVsGroupRelation = 11, //��ƵԴ������ķ�����Ϣ���ַ���
};

enum ECurrUserInfoType
{
    em_PriUserInvalid,		// �û�Ȩ��ö�ٵ���ʼ. Ȩ����intֵ  ����1������Ȩ�ޣ�0����û��Ȩ��
    em_PriUserBegin,
    em_PriUserCMSRecStart = em_PriUserBegin,	// ƽ̨¼��.
    em_PriUserCMSRecPlay,				                   // ƽ̨¼�񲥷�.
    em_PriUserCMSRecDel,				                   // ƽ̨¼��ɾ��.
    em_PriUserCMSRecDownload,			              // ƽ̨¼������.
    em_PriUserLocalRec,				                         // ����¼��.

    em_PriUserCMSRecPlayOtherDomain,	         // ����¼�񲥷�.
    em_PriUserPUCall,					                    // ǰ�˺���.
    em_PriUserAlarmLog,				                    // �澯��־����

	em_UserPwdExpireEnable,		//�Ƿ��������û�������Ч�� bool
	em_UserPwdValidTime,			//�û�������Ч�ڵ�λ��
	em_UserPwdExpireTimeLeft,			//�û�������Ч�ڻ�ʣ��ʱ�䵥λ��
	em_UserLockTimeLeft,				//��Ϊ��������û���������ʣ���ʱ�䵥λ��
	em_UserWaterMarkEnable,		//�Ƿ�������ˮӡ

    // ��������
    em_UserId = 100,  // string  ��ȡ�û���uuid    �ַ�������    
    em_UserIdNoDomainName,  // string  ��ȡ�û���uuid    �ַ�������
};


//Kdm_SetDecodeMode ���õ�ǰ����ģʽ
enum EDecodeMode
{
	emSoftDecode=0,	//���
	emHardDecode=1,	//Ӳ�⣨Ӳ�����ʧ�ܻ��Զ��л�����⣩
};

//����״̬
enum ERSDiskState
{
	emDiskStateInvalid = 0,
	emDiskStateOnline = 1,
	emDiskStateOffline = 2,
	emDiskStateUnknow= 3
};
//����״̬
enum ERSPartState
{
	emPartStateInvalid = 0,
	emPartStateOffline = 1,
	emPartStateUnformatted = 2,
	emPartStateFormatted = 3,
};

//ˮӡ�����С�ȼ�
enum EWarterMarkFontSizeLevel 
{
	emWarterMarkFontSizeInvalid = 0, 
	emWarterMarkFontSizeSmall = 1, 
	emWarterMarkFontSizeNormal = 2, 
	emWarterMarkFontSizeLarge = 3 
};

#ifndef KDM_PARAM
#define KDM_PARAM void *
#endif
// ��Ϊ�Զ�����������Ͷ���
/*
#ifndef KDM_PARAM
#if defined(_WIN64) || defined(WIN64) ||defined (__LP64__) || defined (__64BIT__) || defined (_LP64) || (__WORDSIZE == 64)
#define KDM_PARAM void *
#else
#define KDM_PARAM u32
#endif
#endif
*/
typedef std::vector<std::string> StringList;

// set string null, pStr: string pointer dwStrLen: string len( the length not include end '\0' )
inline void SetStringNull(s8 *pStr, u32 dwStrLen)
{
	for (u32 nNoIdx = 0; nNoIdx <= dwStrLen; nNoIdx++) {
        pStr[nNoIdx] = '\0';
    }
}

inline void StringCopy(char *pStrDst, char *pStrSrc, u32 dwStrLen)
{
    if( pStrDst == NULL || pStrSrc == NULL )
    {
        return;
    }
    for (u32 nNoIdx = 0; nNoIdx < dwStrLen; nNoIdx++) {
        pStrDst[nNoIdx] = pStrSrc[nNoIdx];
    }
}

#pragma pack(1)

/* KDMNO define */
struct KDMNO
{
    KDMNO( void );
    void SetNull();
    bool IsNull() const;
    void operator = ( const KDMNO &tObj );
    bool operator == ( const KDMNO &tObj ) const;
	bool operator != ( const KDMNO &tObj ) const;
    bool operator < ( const KDMNO &tObj ) const;
    
    char szID[MAX_ID_LEN+1];
};

inline void KDMNO::SetNull()
{
	SetStringNull(szID, MAX_ID_LEN);
}

inline KDMNO::KDMNO( void )
{
	SetNull();
}

inline bool KDMNO::IsNull() const
{
	for (int nNoIdx = 0; nNoIdx <= MAX_ID_LEN; nNoIdx++) {
        if( szID[nNoIdx] != '\0' )
        {
            return false;
        }
    }
	return true;
}

inline void KDMNO::operator = ( const KDMNO &tObj )
{
    for (int nNoIdx = 0; nNoIdx <= MAX_ID_LEN; nNoIdx++) {
        szID[nNoIdx] = tObj.szID[nNoIdx];
    }
}

inline bool KDMNO::operator == ( const KDMNO &tObj ) const
{
    for (int nNoIdx = 0; nNoIdx <= MAX_ID_LEN; nNoIdx++) {
        if( szID[nNoIdx] != tObj.szID[nNoIdx] )
        {
            return false;
        }
    }
    
    return true;
}

inline bool KDMNO::operator != ( const KDMNO &tObj ) const
{
    for (int nNoIdx = 0; nNoIdx <= MAX_ID_LEN; nNoIdx++) {
        if( szID[nNoIdx] != tObj.szID[nNoIdx] )
        {
            return true;
        }
    }
    
    return false;
}

inline bool KDMNO::operator < ( const KDMNO &tObj ) const
{
    return ( strcmp(szID, tObj.szID) > 0 );
}

/* bussiness define */
// define id
typedef KDMNO GroupID;
typedef KDMNO DeviceID;
typedef KDMNO DomainID;
typedef KDMNO DeviceKDMNO;
typedef KDMNO DeviceChnName;
typedef KDMNO BatchOpParam;

enum EStreamFlowPattern
{
	emStreamFile=0,						//���ŵ�Դ���ļ�
	emStreamPatenTCP = emStreamFile,
	emStreamPatenUDP = 1,
	emStreamPatenPIC = 2,
	emStreamMultiCast = 3,
	emStreamHiUDP=4,
	emStreamRTSP=5,
	emStreamHiTCP = 6,
};

// subscript type
enum ESubscriptInfo
{
    emOnline = 0x01,
    emAlarm = 0x02,
    emVidChn = 0x04,	
    emGPSInfo = 0x08,    
    emTvWallState =0x100, // ����ǽ״̬��Ҫ��������
	emRecStatus = 0x200,
	emDeviceServiceStatus = emRecStatus,
	emRecvTransData = 0x400,
	emRecvTransDataGB = 0x800, // ����͸������״̬��Ҫ��������
	emDevState = emOnline | emAlarm | emVidChn | emRecStatus,
	emAllSub = emDevState | emGPSInfo | emRecvTransData,
};

enum EAudioEncType
{
	emInvailed = 0,
	emg711 = 1,
	enaaclc = 2,
	emadpcm = 3,
};

//¼��ģʽ
enum ERecMode
{	
	emNormal=1,			// ������ͨ¼��.
	emVideoOnly,		// ֻ¼��Ƶ.
	emKeyFrameOnly,	// ֻ¼�ؼ�֡.
};


typedef struct tagMcusdkAudioEncodParam
{
    tagMcusdkAudioEncodParam()
    {
        byEncType = MEDIA_TYPE_ADPCM;
        byChn = 1;
        dwSampleRate = 8000;
        byBitsPerSample = 16;
    }
    u8 byEncType; // ����ֻ֧�� MEDIA_TYPE_AACLC, MEDIA_TYPE_ADPCM, 
                       //  MEDIA_TYPE_PCMA, MEDIA_TYPE_PCMU, MEDIA_TYPE_OPUS
    u8  byChn;  // adpcm pcma pcmu ֻ֧�ֵ�ͨ�� ������ʽ֧�ֵ�˫ͨ�� 1 mono 2 stereo  ��˫����
    u32  dwSampleRate;  // pcma, pcmu, adpcm, ֻ֧�� 8000 ; 
                                     //aaclc ֧�� 16000, 32000, 48000  ; opus ֧�� 8, 12, 16, 24,48 K
    u8 byBitsPerSample;  // ��ʱֻ֧��16bits
} McusdkAudioEncodParam;

//���������ǲ���
enum emCoverPolicy
{
	emSDK_RS_COVERPOLICY_INVALID = 0,
	emSDK_RS_COVERPOLICY_STOPRECORD = 1,          /*ͨ���ռ���ͣ¼��*/
	emSDK_RS_COVERPOLICY_COVERALL= 2,            /*ͨ���ռ�����������¼��*/
	emSDK_RS_COVERPOLICY_COVERNORMAL = 3,         /*ͨ���ռ���������ͨ¼��*/
	emSDK_RS_COVERPOLICY_UNKNOWN = 4,
};
typedef struct tagMcusdkRCSSysParam
{
    emCoverPolicy temRCSSParam;
    BOOL32 maxLockedRecordDiskSpaceCapacitySupported;
    s32 maxLockedRecordDiskSpaceCapacity;
    tagMcusdkRCSSysParam()
    {
        temRCSSParam = emSDK_RS_COVERPOLICY_INVALID;
        maxLockedRecordDiskSpaceCapacitySupported = FALSE;
        maxLockedRecordDiskSpaceCapacity = 0;
    }
} McusdkRCSSysParam;

//��ѯ�豸����url������
enum emUrlType
{
	URL_TYPE_OSP=0,	//���ظ�ʽ����osp://blabla��tcp�������ŵ�ַ������kedacom˽��Э��Ĳ���url
	URL_TYPE_RTSP,	//����rtsp��ַ
	URL_TYPE_RTMP,	//����rtmp��ַ
	URL_TYPE_HTML5,	//����html5��ַ
	URL_TYPE_CHANNEL,//����Mcusdk�ڲ�֧�ֵ�������UDP����url
	URL_TYPE_TCP,	//����Mcusdk�ڲ�֧�ֵ�mediaswitch tcp����url tcp://blablabla
	URL_TYPE_NUM
};

// device group infomation struct
typedef struct DeviceGroupInfo
{
    DeviceGroupInfo()
    {
        SetStringNull(szGroupName, MAX_NAME_LEN+1);
        bHasDevice = 0;
	 groupID.SetNull();
	 parentID.SetNull();
    }
    void Copy(const DeviceGroupInfo &tObj);
    void operator = ( const DeviceGroupInfo &tObj );
    GroupID groupID; // group id, from plat
    GroupID parentID; // parent group id, from plat
    char szGroupName[MAX_NAME_LEN+1]; // group name, from plat
    bool bHasDevice; // is the group has device, from plat
} GROUPINFO;

inline void DeviceGroupInfo::operator = ( const DeviceGroupInfo &tObj )
{
    Copy(tObj);
}

inline void DeviceGroupInfo::Copy(const DeviceGroupInfo &tObj)
{
    groupID = tObj.groupID;
    parentID = tObj.parentID;
    StringCopy((char*)szGroupName, (char*)tObj.szGroupName, sizeof(szGroupName));
    bHasDevice = tObj.bHasDevice;
}

// device information
// device source
typedef struct VideoSrcInfo
{
    VideoSrcInfo()
    {
        nSn = 0;
        SetStringNull(szSrcName, sizeof(szSrcName));
        nPtzLevel = 0;
	 	bFitCondition = FALSE;	
	  	bChanIsOnline = 0X0000;
    }
    void operator = ( const VideoSrcInfo &tObj );
    int nSn; // Video Source id(No.)
    char szSrcName[MAX_NAME_LEN+1]; // video source alias
    int nPtzLevel; // video source ptz level
    BOOL32	bFitCondition;// when search Fit ,show
    BOOL32     bChanIsOnline;
    void 	SetReChnNameBySDK()
    {
		bChanIsOnline = 1;
    }
    void SetRcChnNameByPlatform()
    {
		bChanIsOnline = 0;
    }

    BOOL32 ChnReNamebyPlatform()
    {
		if((bChanIsOnline&0x0001)==1)
		{
			return FALSE;
		}
		else
		{
			return TRUE;
		}
    }
    	
} VIDSRC;

inline void VideoSrcInfo::operator = ( const VideoSrcInfo &tObj )
{
    nSn = tObj.nSn;
    nPtzLevel = tObj.nPtzLevel;
    //StringCopy((char*)szSrcName, (char*)tObj.szSrcName, sizeof(szSrcName));
	StringCopy((char*)szSrcName, (char*)tObj.szSrcName, MAX_NAME_LEN);
}

typedef struct DeviceInfo //nDevCap����emCapNull���ͣ���nDevCapΪemCapNullʱ����ͨ��nDevType��ȡ�豸���͡�NVR,SVR����ƵԴ��nDevCap���ٸ���ֵΪemDome��
{
    enum eDeviceCap // device capability
    {		
        emBullet=0, //ǹ��ipc
		emDome,     //���ipc
		emCapNull,  
	};
	enum eDeviceType // device type
    {
        emTypeUnknown = 0,
        emTypeEncoder,
        emTypeDecoder,
        emTypeCodecer,
        emTypeTVWall,
        emTypeNVR,
        emTypeSVR,
        emAlarmHost,
    };
    DeviceInfo()
    {
        nSn = 0;
        nDevSrcNum = 0;
        nEncoderChnNum = 0;
        //SetStringNull(szDevSrcAlias, MAX_NAME_LEN);
		SetStringNull(szDevSrcAlias, sizeof(szDevSrcAlias));
        nDevType = emTypeUnknown;
        nDevCap = emCapNull;
        nCallType = 0;
	 	bDvcIsOnline = FALSE;
        SetStringNull(szManufacturer, MAX_NAME_LEN);
	  	szParentGroupID.SetNull();
	  	deviceID.SetNull();
	  	domainID.SetNull();
    }
    void operator = ( const DeviceInfo &tObj );
    int nSn; // device sn, create by mcusdk (nouse in this version)
    DeviceID deviceID; // device id, from plat
    DomainID domainID; // domain id, from plat
    u16 nDevSrcNum; // device video source number
    u16 nEncoderChnNum; // device encoder channel number
    char szDevSrcAlias[MAX_NAME_LEN+1]; // device alias
    u16 nDevType; // device type
    u16 nDevCap; // device capability
    u16 nCallType; // device call type
    VIDSRC aDevSrcChn[MAX_VID_SRC_NUM]; // device video source infomation
    char szManufacturer[MAX_NAME_LEN+1]; // device manufacturer

    //
    BOOL32 bDvcIsOnline;
    GroupID szParentGroupID;
} DEVICEINFO;

typedef struct DevGPSInfo
{
	DevGPSInfo()
	{
		revTime = 0;
		longitude = 0;
		latitude = 0;
		marLongitude = 0;
		marLatitude = 0;
		speed = 0;
		deviceID.SetNull();
	}
	u32 revTime;
	DeviceID deviceID; 
	double longitude;	
	double latitude;	
	double marLongitude;	
	double marLatitude;	
	double speed;	 
	
}DeviceGPSInfo;

typedef struct DevGPSInfo_V2
{
	DevGPSInfo_V2()
	{
		revTime = 0;
		longitude = 0;
		latitude = 0;
		marLongitude = 0;
		marLatitude = 0;
		speed = 0;
		height = 0;
		angle = 0;
		reserve1 = 0;
		reserve2 = 0;
		deviceID.SetNull();
	}
	u32 revTime;
	DeviceID deviceID; 
	double longitude;	
	double latitude;	
	double marLongitude;	
	double marLatitude;	
	double speed;
	double height;
	double angle;
	double reserve1;
	double reserve2;
}DeviceGPSInfo_V2;

typedef struct tagDevLatiLongTude
{
	tagDevLatiLongTude()
	{
		longitude = 0;
		latitude = 0;
		DevSrcId = 0;
		DevChnId = 0;
	}
	DeviceID deviceID; 
	int DevSrcId;
	int DevChnId;
	double longitude;	
	double latitude;	
}TDevLatiLongTude;
    
typedef struct tagDeviceSrcStatus
{
    tagDeviceSrcStatus()
    {
        bEnable = FALSE;
        bOnline = FALSE;
    }
    BOOL32 bEnable;
    BOOL32 bOnline;
} DEVSRC_ST;

typedef struct SearchDvcRspInfo
{
	SearchDvcRspInfo()
	{
		m_DvcInfoType = 0;
        SetStringNull(m_DevDirectory, MAX_DEV_DIR);
	}

	short 		m_DvcInfoType; 	//1:gruoup,2:devices
	GroupID 	m_ParentID;
	char		m_DevDirectory[MAX_DEV_DIR];
	
	DEVICEINFO m_DevInfo;
	GROUPINFO  m_GroupInfo;
	
}StSearchDvcRspInfo;

typedef struct SearchDvcReqInfo
{
	SearchDvcReqInfo()
	{
		m_PBReceiveChnNum = 0;
		m_PBwServerPort = 0;
        SetStringNull(m_PBsearchDvcName, MAX_NAME_LEN);
        SetStringNull(m_PBFeatureCode, MAX_NAME_LEN);
        SetStringNull(m_PBszServerIp, MAX_URL_LEN);
		m_SearchResLimit = 0;
		m_pThis = NULL;
	}
	char       m_PBsearchDvcName[MAX_NAME_LEN];
	char   	   m_PBFeatureCode[MAX_NAME_LEN];
	char       m_PBszServerIp[MAX_URL_LEN];// connect stream server ip(no use now)
	int 	   m_PBReceiveChnNum;	
	int        m_PBwServerPort;				 // connect stream server port(no use now)
	int 	   m_SearchResLimit;
	void*	   m_pThis;

}StSearchDvcReqInfo;

typedef struct SearchDvcRsp
{
	u32  		m_TotalSearchChannelNum;
	u32			m_HasGiveChannelNum;
	u32			m_CurrentGiveDvcNum;
	std::vector <SearchDvcRspInfo> m_vctSearchDvcRspList;
}StSearchDvcRsp;


inline void DeviceInfo::operator = ( const DeviceInfo &tObj )
{
    nSn = tObj.nSn;
    deviceID = tObj.deviceID;
    szParentGroupID = tObj.szParentGroupID;
    domainID = tObj.domainID;
    nDevSrcNum = tObj.nDevSrcNum;
    nEncoderChnNum = tObj.nEncoderChnNum;
    //StringCopy( (char*)szDevSrcAlias, (char*)tObj.szDevSrcAlias, sizeof(szDevSrcAlias) );
	StringCopy( (char*)szDevSrcAlias, (char*)tObj.szDevSrcAlias, MAX_NAME_LEN );
    nDevType = tObj.nDevType;
    nDevCap = tObj.nDevCap;
    nCallType = tObj.nCallType;
    for( int nSrcNum = 0; nSrcNum < MAX_VID_SRC_NUM; nSrcNum++ )
    {
        aDevSrcChn[nSrcNum] = tObj.aDevSrcChn[nSrcNum];
    }
    StringCopy( (char*)szManufacturer, (char*)tObj.szManufacturer, sizeof(szManufacturer) );
}


// device channel
#define INVALID_SRC_INDEX (0xFFFF)
#define INVALID_CHN_INDEX (0x00FF)
enum eChnType
{
    emMaster = 0,
    emSlaver = 1,
    emThird = 2,
    emFourth = 3,
};

// the struct used for function param in usual
typedef struct Device_Chn
{
    Device_Chn()
    {
        nSrc = INVALID_SRC_INDEX;
        nChn = INVALID_CHN_INDEX;
    }
    u16 GetSourceID()
    {
        return nSrc;
    }
    eChnType GetChannelType()
    {
        switch( (u32)nChn>>16 )
        {
            case (u32)emMaster:
                return emMaster;
            case (u32)emSlaver:
                return emSlaver;
            case (u32)emThird:
                return emThird;
            case (u32)emFourth:
                return emFourth;
        }
        return emMaster;
    }
    void SetSourceID(u16 wSrcId)
    {
        nSrc = wSrcId;
    }
    void SetIsSlaverChn(BOOL32 bSlaver)
    {
        if( bSlaver )
        {
            nChn |= (((u32)emSlaver)<<16);
        }
        else
        {
            nChn |= (((u32)emMaster)<<16);
        }
    }
    void operator = ( const Device_Chn &tObj );
    DomainID domainID; // device domain id
    DeviceID deviceID; // device id
    u16 nSrc; // video source No.
    u16 nChn; // encoder channel No.
} DEVCHN;

inline void Device_Chn::operator = ( const Device_Chn &tObj )
{
    domainID = tObj.domainID;
    deviceID = tObj.deviceID;
    nSrc = tObj.nSrc;
    nChn = tObj.nChn;
}

//�豸/�豸ͨ����Ӧ������ID��һ��ӳ����
typedef struct tagDeviceID2GBIDItem
{
	DEVCHN devChn;
	DeviceID gbId;
}DeviceID2GBIDItem;

// device status notify, use in callback function
enum eStatusType
{
    emDevOnline = 0,
    emDevAlarm = 1,
    emDevConfig = 2,
    emDevGpsInfo = 3,
	emDevRecStatus = 4,
	emDevTransDataNtf = 5, // �յ�͸�����ݻ���֪ͨ��Ӧ��ͨ��Kdm_GetTransData�ӿڻ�ȡ͸�����ݣ�����Ҫ�豸ID
	emTvWallNewNtf=10,
	emTvWallDelNtf = 11,
	emTvWallModNtf = 12,
    emTvWallStaChgNtf = 13,
	emDeviceAddNtf = 14,				//�豸����֪ͨ��
	emDeviceDelNtf = 15,				//�豸����֪ͨ��
	emDeviceModNtf = 16,				//�豸�޸�֪ͨ��
	emGroupAddDev = 17,				//�豸��������豸��ע�����2.0ƽ̨�����ʵ��Ϊ������������ƵԴ֪ͨ��
	emGroupDelDev = 18,				//�豸����ɾ���豸����ƽ̨1.0ʱ�ſ��ã�2.0ƽ̨��ֻ�����������ƵԴ�ĸ��
    emDevChnNameChange = 19,  // �豸��ƵԴ�����޸�
	emDevTransDataNtfGB = 20, // �����豸͸�����ݻ���֪ͨ���յ���ͨ��Kdm_GetTransDataForGB�ӿڻ�ȡ͸������
	emDevAudioCallStatus = 21,
};
    
enum eAlarmType
{
    emAlarmTypeInvalid = 0, //��Ч�ĸ澯����.
    emAlarmMove = 1,        //�ƶ����
    emAlarmInput = 2,       //�澯����
    emAlarmDiskfull = 3,    //������
    emAlarmVideoLost = 4,   //��ƵԴ��ʧ
    //���¿�ʼ������澯ӵ�и������ݣ���Ҫ���澯�ṹ��תΪ DeviceStatusAlarmEx ����Ҫ�ϲ��Լ�ת��һ�¡�
    emAlarmIntelligent = 5,	//���ܸ澯
    emAlarmVideo = 6,       //������Ѳ�澯
	//�������µĸ澯.
	emAlarmExceptionEvent = 7,		//�쳣�¼���Ϣ
	emAlarmDefocus = 8,				//�齹���
	emAlarmSceneChange = 9,			//�����任
	emAlarmRegionInvasion = 10,		//��������
	emAlarmRegionLeaving = 11,			//�����뿪
	emAlarmObjectTaken = 12,			//��Ʒ��ȡ
	emAlarmObjectLeft = 13,			//��Ʒ����
	emAlarmPeopleGather = 14,			//��Ա�ۼ�
	emAlarmCorgon = 15,				//������
	emAlarmAudioAbnormal = 16,			//�����쳣
	emAlarmLumaChange = 17,			//���ȱ仯
	//R4B1֧�ֹ���2016�������Ͳ����
	emAlarmAntiDismantle = 18,			//�豸���𱨾�
	emAlarmHighTemperature = 19,		//�豸���±���
	emAlarmLowTemperature = 20,		//�豸���±���
	emAlarmPersonVideo = 21,           //�˹���Ƶ
	emAlarmSportGoalCheck = 22,        //�˶�Ŀ����
	emAlarmTripwireCheck = 23,         //���߼��
	emAlarmHoverCheck = 24,             //  �ǻ���ⱨ��
	emAlarmTrafficStatisticsCheck = 25, //  ����ͳ�Ʊ���
	emAlarmDensityCheck = 26,           //�ܶȼ��
	emAlarmVideoException = 27,         //��Ƶ�쳣
	emAlarmMoveFast = 28,               //�����ƶ�
	emAlarmDiskFault = 29,              //�洢�豸���̹��ϱ���
	emAlarmFanFault = 30,              // �洢�豸���ȹ��ϱ���
	emAlarmGPSOverSpeed = 31,           //gps ����
	emAlarmSIMDataTrafficExceeded = 32,        //sim ������������
};

enum eStreamUrlType
{
	emInvailedUrlType = 0,
	emUrlTypeTCPFlow = 1,
	emUrlTypeUDPFlow = 2,
	emUrlTypePICFlow = 3,
	emUrlTypeHiTCPFlow=4,
};
    
enum eAlarmStatus
{
    emAlarmOccur = 1,
    emAlarmResume = 2,
};

typedef struct DeviceStatus
{
    DeviceStatus()
    {
        memset(this, 0x00, sizeof(DeviceStatus));
    }
    eStatusType m_emStatusType; // device status type
    union
    {
        struct {
            u32 m_dwAlarmType; // alarm type eAlarmType
            u8 m_byAlarmStatus; // alarm status: Occur, resume eAlarmStatus
            u32 m_dwTime; // alarm Occur or Resume time
            u16 m_wAlarmChn; // alarm channel
        } m_AlarmParam; // alarm info
        BOOL32 m_bOnline; // device online: 1 offline: 0
		u16 m_dwSrcID; // only use when notify emDevChnNameChange
    };
} DEVSTATUS;

//�� DeviceStatus �� �澯���� m_dwAlarmType Ϊ emAlarmIntelligent ʱ��֪ͨ�ṹ��
typedef struct DeviceStatusAlarmEx
{
	DeviceStatusAlarmEx()
	{
		memset(this, 0x00, sizeof(DeviceStatusAlarmEx));
	}
	eStatusType m_emStatusType; // device status type
	union
	{
		struct
		{
			u32 m_dwAlarmType; // alarm type eAlarmType
			u8 m_byAlarmStatus; // alarm status: Occur, resume eAlarmStatus
			u32 m_dwTime; // alarm Occur or Resume time
			u16 m_wAlarmChn; // alarm channel
		} m_AlarmParam; // alarm info
		BOOL32 m_bOnline; // device online: 1 offline: 0
		u16 m_dwSrcID; // only use when notify emDevChnNameChange
	};
	int m_extDataSize;	//�澯�������ݳ���
	unsigned char m_extAlarmData[64];	//�澯��������
} DEVSTATUSALRAMEX;

// subscript device array
typedef struct tagSubsDevices
{
    tagSubsDevices()
    {
        m_bySubsDevNum = 0;
        memset( m_vctDevID, 0x00, MAX_REQ_DEV_SUBS_NUM*sizeof(DeviceID) );
    }
    BOOL32 AddDevice(DeviceID tDevice)
    {
        if( m_bySubsDevNum < MAX_REQ_DEV_SUBS_NUM )
        {
            m_vctDevID[m_bySubsDevNum++] = tDevice;
            return true;
        }
        return false;
    }
    DeviceID GetDevice(u8 byIndex)
    {
        if( byIndex >= MAX_REQ_DEV_SUBS_NUM )
        {
            return DeviceID();
        }
        return m_vctDevID[byIndex];
    }
    u8 m_bySubsDevNum; // subscript device number
    DeviceID m_vctDevID[MAX_REQ_DEV_SUBS_NUM]; // subscript device id
} TSUBSDEVS;

// device status callback, (after subscript device, mcusdk will send status on application by this function)
typedef int ( *DevStatus_Callback)(DeviceID devID, DeviceStatus *pDevStatus, void * lUserData);

//modified by yuhengyue 2014.9.17
//PTZ���������ǰ���豸����֧�֣���Ҫ�Ӿ����豸����ȷ���Ƿ�֧��
enum ePtzCmd
{
    emMoveLeft = 0,						//����
	emMoveRight = 1,						//����
    emMoveUp = 2,							//����
    emMoveDown = 3,					//����
	emMoveLeftUp = 4,					//����
	emMoveLeftDown = 5,				//����
	emMoveRightUp = 6,				//����
	emMoveRightDown = 7,			//����
    emMoveStop = 8,						//ֹͣ�ƶ�
    emZoomIn = 9,							//��Ұ����
    emZoomOut = 10,						//��Ұ��Զ
    emZoomStop = 11,					//��Ұ����ֹͣ
    emHome = 12,							//��λ
	emAutoScanStart = 128,  // 128	//��ʼ�Զ�Ѳ��
	emAutoScanStop = 129,	   // 129	//ֹͣ�Զ�Ѳ��
	emZoonAreaWhole = 209,  // 209  //�ֲ���С  ƽ̨1.0
	emFocusFar,		        // 210	//�������Զ
	emFocusNear,			// 211	//���������
	emFocusAuto,			// 212	//�Զ�����
	emFocusStop,			// 213	//����ֹͣ
	emPresetSave,	    	// 214	//����ͷԤ��
	emPresetCall,			// 215	//������ͷԤ��
	emCameraReset,	    // 216	// ��ʼ������ͷ
	emBrightUp,			    // 217	//�������
	emBrightDown,			// 218	//�������
	emBrightStop,			// 219	//ֹͣ����
	emCommandNew,			// 220	//������
	emCommandAppend,		// 221	//��������
	emGotoPoint,			// 222	//���Ķ�λ
	emZoomArea,			    // 223	//�ֲ��Ŵ�
	emAlecPanSpeed,	        // 224	//������ˮƽ�ƶ��ٶ���������
	emAlecTiltSpeed,	    // 225	//�����˴�ֱ�ƶ��ٶ���������
	emSonySetBright,	    // 226	//sony���ȵ�����������
	emMatrixSwitch,		    // 227	//�л���Ƶ
	emMatrixVideoMix4,		// 228	//����ϳ�2��2
	emMatrixVideoMix9,		// 229	//����ϳ�3��3
	emMatrixVideoMix16,	    // 230	//����ϳ�4��4
	emMatrixVideoMixPP,	    // 231	//����ϳɻ��л�
	emZoomAreaStop,		    // 232  //ȡ���ֲ��Ŵ�  ƽ̨2.0
	////�˵�//////////////////////////////////////////////////////////////////////	
	emMenuUp,				// 233	//�˵���
	emMenuDown,			// 234	//�˵���
	emMenuLeft,			    // 235	//�˵���
	emMenuRight,			// 236	//�˵���
	emMenuShow,			// 237	//�˵���ʾ
	emMenuHide,			// 238	//�˵�����
	emMenuEnter,			// 239	//�˵�ȷ��
	emMenuCancel,		// 240	//�˵�ȡ��
	emPresetDel,			// 241	//ɾ������ͷԤ��
	////�����л�//////////////////////////////////////////////////////////////////////
	emMatrixSwitchASC,	    // 242	//�����л�
	emMatrixSwitchESC,	    // 243	//�����л�
	emMatrixHoldImage=244,	 // 244	//ͼ�񱣳�	
	emStartWiper = 360,			//360	//��ʼ��ˢ��m_wPtzRange ����Ϊ��ˢ�ٶȣ�ֵΪ0-15��������������
	emStopWiper,					//361	//ֹͣ��ˢ
	emLightOn,						//362   //�����ƹ�
	emLightOff,						 //363   //�رյƹ�
	emStartExt1,					 //364   //��չ����һ�������ǿ�����ˮ��
	emStopExt1,					//365   //�ر���ˮ��չ����һ
	emStartExt2,					 //366   //��չ���ܶ��������ǿ�����˪��
	emStopExt2,					//367   //�رճ�˪��չ���ܶ�	
	emLock = 368,				//368	//�ƽ���Ȩ��
};

// ptz command info
typedef struct tagPtzCmd
{
    tagPtzCmd()
    {
        m_emPtzCmd = 0;
        m_byLevel = 0;
        m_dwHoldTimer = 0;
        m_wPtzRange = 0;
    }
    int m_emPtzCmd; // ptz command
    u16 m_wPtzRange; // ptz range
    u8 m_byLevel; // device source ptz level (option)
    u32 m_dwHoldTimer; // ptz hold time (option)
} PTZCMD;

typedef struct tagPtzAuthority
{
	tagPtzAuthority()
	{
		m_wPtzRange = 0;
		m_byLevel = 0;
		m_dwHoldTimer = 0;
	}
	u16 m_wPtzRange;//ptz ranger
    u8 m_byLevel; // device source ptz level (option)
    u32 m_dwHoldTimer; // ptz hold time (option)
}TPTZAUTHORITY;

// pu point move
typedef struct tagPointMoveCmd
{
    tagPointMoveCmd()
    {
        m_wPosX = 0;
        m_wPosY = 0;
        m_wScreenWidth = 0;
        m_wScreenHeight = 0;
    }
    u16 m_wPosX; // position x coordinate in screen
    u16 m_wPosY; // position y coordinate in screen
    u16 m_wScreenWidth; // screen width
    u16 m_wScreenHeight; // screen height
} POINTMOVE;

typedef struct tagDrawWnd
{
	union
	{
		struct
		{
		    void *setHardDec;
			void *surfaceView;
		}tAndroidWnd;
		struct
		{
			int channel;
			int windowwidth;
			int windowheight;
		}tIosWnd;
	};
}TDrawWnd,*PTDrawWnd;

/* stream define */
// play start trans mode
enum eTransMode
{
    Trans_UNKNOW,
    Trans_UDP,
    Trans_TCP,
    Trans_KWTP,
};

// play media type
enum eMediaType
{
    Media_UNKNOW,
    Media_VIDEO,
    Media_AUDIO,
    Media_ALL,
};

// play snapshot type
enum EPictureType
{
    emBmp32 = 0,
    emJpeg_100 = 1,
    emJpeg_70 = 2,
    emJpeg_50 = 3,
    emJpeg_30 = 4,
    emJpeg_10 = 5,
    emBmp24 = 6,
};

// play local record type
enum ELocalRecType
{
    emMp4 = 0,
    em3gp = 1,
    emAsf = 2,
};

enum ePlayVideoType
{   
	emInvailedVideoPlay =-1,
	emRecordVideoPlay = 0,
	emRealVideoPlay = 1,
	emRecordVideoDownLoad = 2,
	emRecordPlayBySETime = 3,
};

enum eRecordType
{   
	emInvailedRecord = 0,
	emPlatFormRecord = 1,
	emIpcRecord = 2,
	emLocalRecord = 4,
};

enum emRecordEventType
{
	emRecordEventInvalid= 0,
	emRecordEventAll = 1,
	emRecordEventAlarm = 2,
	emRecordEventHandle = 3,
	emRecordEventPlan = 4,
	emRecordEventUnknow = 5
};

enum	emWaterMarkMode
{
	emWMModeRender = 0x00000001,  //����ʱ��ˮӡ
	emWMModeSnap = 0x00000002,		//ץ��ʱ��ˮӡ
	emWMModeRecord = 0x00000004,  //����¼��ʱ��ˮӡ
	emWMModeDownload = 0x00000008,  //����ˮӡ��ʵ��ȫ�֣�
};

// stream parameter
typedef struct Stream_Param
{
    Stream_Param()
    {
        SetStringNull(m_szServerIp, MAX_URL_LEN);
        SetStringNull(m_szManufactor, MAX_NAME_LEN);
        m_wServerPort   = 0;
        m_wScreenWidth  = 0;
        m_wScreenHeight = 0;
		m_pDrawWnd = NULL;
        m_wHighDefinition = FALSE;
        m_playTime  = 0;
        m_startTime =0;
        m_endTime   =0;
        m_emVideoType  = emInvailedVideoPlay;
        m_byRecordType = emInvailedRecord;
        m_dwDownloadStartTime = 0;
        m_dwDownloadEndTime   = 0;
        m_dwDownloadFirstPlayTime = 0;
		
    }
	s8  m_szServerIp[MAX_URL_LEN+1]; /*�ڲ�ʹ�ã��ⲿ���踳ֵ*/
	u16 m_wServerPort;				 //����ֱ��ʹ��TCP��url���ŷ�ʽʱ��Ĭ����6700������Ƿ�6700�˿ڣ��贫���½mvs�Ķ˿ڣ�
    u16 m_wScreenWidth;				 /*�ڲ�ʹ�ã��ⲿ���踳ֵ*/
    u16 m_wScreenHeight;			 /*�ڲ�ʹ�ã��ⲿ���踳ֵ*/
    void* m_pDrawWnd; //���ھ��
    s8    m_szManufactor[MAX_NAME_LEN+1]; //�豸������
    BOOL32 m_wHighDefinition;//ʵʱ�����������
	ePlayVideoType	m_emVideoType;//�������
    u32	m_startTime;                /*�ڲ�ʹ�ã��ⲿ���踳ֵ*/
    u32	m_endTime;                  /*�ڲ�ʹ�ã��ⲿ���踳ֵ*/
    u32 m_playTime;                 /*�ڲ�ʹ�ã��ⲿ���踳ֵ*/
	eRecordType	m_byRecordType;//¼��ط�����
    u32 m_dwDownloadStartTime;      /*�ڲ�ʹ�ã��ⲿ���踳ֵ*/
    u32 m_dwDownloadEndTime;        /*�ڲ�ʹ�ã��ⲿ���踳ֵ*/
    u32 m_dwDownloadFirstPlayTime;  /*�ڲ�ʹ�ã��ⲿ���踳ֵ*/
} SPARAM;

// stream parameter
typedef struct Stream_Param_Inside
{
	Stream_Param_Inside()
	{
		SetStringNull(m_szServerIp, MAX_URL_LEN);
		SetStringNull(m_szManufactor, MAX_NAME_LEN);
		SetStringNull(m_szMediatype, MAX_NAME_LEN);
		m_wServerPort   = 0;
		m_wScreenWidth  = 0;
		m_wScreenHeight = 0;
		m_wHighDefinition = FALSE;
		m_playTime  = 0;
		m_startTime =0;
		m_endTime   =0;
		m_emVideoType  = emInvailedVideoPlay;
		m_byRecordType = emInvailedRecord;
		m_dwDownloadStartTime = 0;
		m_dwDownloadEndTime   = 0;
		m_dwDownloadFirstPlayTime = 0;
		m_bUrlplayRecordDownload = FALSE;
		m_downloadSpeed = 0;
		m_bPuDirectTrans = FALSE; //����PUֱ�����迴PUֱ������;��UDP��ʽ��Ч
		m_bVtduDirectTrans = FALSE;//�����豸������VTDUֱ������ȷ�ϼ���ƽ̨���绷����ʹ�ã����������������;��UDP��ʽ��Ч
		m_pDrawWnd = NULL;
		m_emTransMode = emStreamPatenUDP;
	}
	s8  m_szServerIp[MAX_URL_LEN+1]; 
	u16 m_wServerPort;				 
	u16 m_wScreenWidth;				 
	u16 m_wScreenHeight;			 
	void* m_pDrawWnd;
	s8    m_szManufactor[MAX_NAME_LEN+1];
	char m_szMediatype[MAX_NAME_LEN + 1];
	BOOL32 m_wHighDefinition;
	ePlayVideoType	m_emVideoType;
	u32	m_startTime;                
	u32	m_endTime;                 
	u32 m_playTime;                 
	eRecordType	m_byRecordType;
	u32 m_dwDownloadStartTime;     
	u32 m_dwDownloadEndTime;       
	u32 m_dwDownloadFirstPlayTime; 
	BOOL32 m_bUrlplayRecordDownload;//�Ƿ���urlplaysdk¼�����صı��
	int m_downloadSpeed;//�����ٶ�ҲҪ����
	//�� RecordplayParam �����������������
	BOOL32 m_bPuDirectTrans; //����PUֱ�����迴PUֱ������;��UDP��ʽ��Ч
	BOOL32 m_bVtduDirectTrans;//�����豸������VTDUֱ������ȷ�ϼ���ƽ̨���绷����ʹ�ã����������������;��UDP��ʽ��Ч
	EStreamFlowPattern m_emTransMode;

} SPARAM_Inside;//����SPARAM_Inside���ڲ�ʹ�ã���ֹ�޸�SPARAMӰ�쵽�ⲿ�ӿ�

// realplay parameter
typedef struct tagRealplay_Param
{
	tagRealplay_Param()
	{
		SetStringNull(m_szManufactor, MAX_NAME_LEN);
		m_wHighDefinition = FALSE;
		m_pDrawWnd = NULL;
		m_bPuDirectTrans = FALSE;
		m_bVtduDirectTrans = FALSE;
		m_dwReserved1 = 0;
		m_dwReserved2 = 0;
	}
	void* m_pDrawWnd; //���ھ��
	s8    m_szManufactor[MAX_NAME_LEN+1]; //�豸����
	BOOL32 m_wHighDefinition; //�����������
	BOOL32 m_bPuDirectTrans; //����PUֱ�����迴PUֱ������;��UDP��ʽ��Ч
	BOOL32 m_bVtduDirectTrans;//�����豸������VTDUֱ������ȷ�ϼ���ƽ̨���绷����ʹ�ã����������������;��UDP��ʽ��Ч
	u32 m_dwReserved1;		//�����ֶ�
	u32 m_dwReserved2;		//�����ֶ�
} RealplayParam;

// recordplay parameter
typedef struct tagRecordplay_Param
{
	tagRecordplay_Param()
	{
		SetStringNull(m_szManufactor, MAX_NAME_LEN);
		m_wHighDefinition = FALSE;
		m_pDrawWnd = NULL;
		m_byRecordType = emInvailedRecord;
		m_emVideoType  = emInvailedVideoPlay;
		m_bPuDirectTrans = FALSE;
		m_bVtduDirectTrans = FALSE;
		m_dwReserved1 = 0;
		m_dwReserved2 = 0;
	}
	void* m_pDrawWnd; //���ھ��
	s8    m_szManufactor[MAX_NAME_LEN+1]; //�豸����
	BOOL32 m_wHighDefinition; //����Ч
	eRecordType	m_byRecordType;//¼��ط�����
	ePlayVideoType	m_emVideoType;//�������
	BOOL32 m_bPuDirectTrans; //����Ч
	BOOL32 m_bVtduDirectTrans;//����Ч
	u32 m_dwReserved1;		//�����ֶ�
	u32 m_dwReserved2;		//�����ֶ�
} RecordplayParam;

// rpctrl parameter
typedef struct tagRpctrl_Param
{
	tagRpctrl_Param()
	{
		m_bPuDirectTrans = FALSE;
		m_bVtduDirectTrans = FALSE;
		m_dwReserved1 = 0;
		m_dwReserved2 = 0;
	}
	BOOL32 m_bPuDirectTrans; //����PUֱ�����迴PUֱ������;��UDP��ʽ��Ч
	BOOL32 m_bVtduDirectTrans;//�����豸������VTDUֱ������ȷ�ϼ���ƽ̨���绷����ʹ�ã����������������;��UDP��ʽ��Ч
	u32 m_dwReserved1;		//�����ֶ�
	u32 m_dwReserved2;		//�����ֶ�
} RpctrlParam;

//recv stream type
enum eRecvStreamType
{
    VIDEO_STREAM_TYPE = 1, // video type
    AUDIO_STREAM_TYPE = 2, // audio type
};

typedef struct tagFrameHdr_SDK
{
    u8     m_byMediaType;
    u8    *m_pData;
	u32		m_dwPreBufSize;
    u32    m_dwDataSize;
    u8     m_byFrameRate;
    u32    m_dwFrameID;
    u32    m_dwTimeStamp;
    u32    m_dwSSRC;
    union
    {
        struct{
			BOOL32    m_bKeyFrame;
			u16       m_wVideoWidth;
			u16       m_wVideoHeight;
		}m_tVideoParam;
        u8    m_byAudioMode;
    };
}FRAMEHDR_SDK,*PFRAMEHDR_SDK;

/*typedef struct tagFrameYUV
{
    u8 *m_pData; // YUV data
    u32 m_dwDataSize; // YUV data length
    u32 m_dwWidth; // image width
    u32 m_dwHeight; // image height
    u32 m_dwTimeStamp; // frame time stamp
} PFRAMEYUV;*/

//��tagFrameYUV�ṹ����uniplay��KDFrameInfo�ṹ����ȫ��ͬ��
typedef struct tagFrameYUV
{
	u8*					pbyRawBuf;
	unsigned int		dwRawlen;
	unsigned int		dwMediaType;			//��������(KD_FRAME_TYPE)
	unsigned int		dwSubMediaType;			//KD_DATA_TYPE(��Ƶ��Ч)
	unsigned int		dwFrameIndex;			//֡���
	u64					dwNetTimeStamp;			//���ʱ�����RTP�ڲ�ʱ�����
	u64					dwMediaTimeStamp;		//����ʱ�������Ƶ����ʱ�䣩
	unsigned int		dwMediaEncode;			//��kdvdef.h �ڲ��������FRAME_DATA_FORMAT���涨��
	union FRAME
	{
		struct VideoFrame
		{
			unsigned short		dwFrameRate;
			unsigned short		dwWidth;     //�����
			unsigned short		dwHeight;    //�����
			unsigned short		strike[3];
		}tVideo;
		
		struct AudioFrame
		{
			unsigned short		wChannels;   //������
			unsigned short		wBitWidth;   //λ��
			unsigned short		dwSampleRate; //������
		}tAudio;
	}u;
	unsigned short		wBitRate;			//�����ʣ���λΪ1028�ֽ�
	unsigned short		wReverse[3];
}FRAMEYUV_SDK,*PFRAMEYUV_SDK;

typedef enum	__MCUSKD_FRAME_DATA_FORMAT
{
	MCUSKD_FRAME_DATA_PCM = 0,
	MCUSKD_FRAME_DATA_YV12 = 100,
	MCUSKD_FRAME_DATA_RGB24,
	MCUSKD_FRAME_DATA_RGBA32,
	MCUSKD_FRAME_DATA_ABGR,
	MCUSKD_FRAME_DATA_ARGB4444,
	MCUSKD_FRAME_DATA_RGB565,
	MCUSKD_FRAME_DATA_ARGB1555,
	MCUSKD_FRAME_DATA_BGRA,
	MCUSKD_FRAME_DATA_YUY2,
	MCUSKD_FRAME_DATA_UYVY,
	MCUSKD_FRAME_DATA_NV21,
	MCUSKD_FRAME_DATA_NV12,
	MCUSKD_FRAME_DATA_I420,
	MCUSKD_FRAME_DATA_END
}MCUSDK_FRAME_DATA_FORMAT;

typedef struct tagMCUSDK_KDRECT
{
	long    left;
	long    top;
	long    right;
	long    bottom;
} MCUSDK_KDRECT;

typedef struct tagMCUSDK_RSParam
{
    u16  m_wFirstTimeSpan;      ///<��һ���ش�����
    u16  m_wSecondTimeSpan;     ///<�ڶ����ش�����
    u16  m_wThirdTimeSpan;      ///<�������ش�����
    u16  m_wRejectTimeSpan;     ///<���ڶ�����ʱ����
} MCUSDK_TRSParam;

// stream url infomation (from stream server)
typedef struct Stream_UrlInfo
{
    Stream_UrlInfo()
    {
        SetStringNull(m_szUrl, MAX_URL_LEN+1);
        SetStringNull(m_szDesc, MAX_DESC_LEN+1);
	 	SetStringNull(m_manuFactory, MAX_DESC_LEN+1);
        SetStringNull(m_reserve, MAX_DESC_LEN+1);
	 	m_dwWidth = 0;
	 	m_dwHeight = 0;
		m_UrlType = emInvailedUrlType;
    }
	s8	   m_szUrl[MAX_URL_LEN+1]; 		  // stream url
	u32    m_dwWidth; 					  // stream width
	u32    m_dwHeight; 					  // stream height
	s8	   m_szDesc[MAX_DESC_LEN+1]; 	  // stream description
    s8     m_manuFactory[MAX_DESC_LEN+1]; // ManuFactory
    s8     m_reserve[MAX_DESC_LEN+1];	  // Reserve����½mvs�Ķ˿ڣ�Ĭ����6700������Ƿ�6700�˿ڣ�ʹ��url���ŷ�ʽʱ���轫�ö˿ڴ��벥�Žӿ�
    eStreamUrlType	   m_UrlType;				 	  // Url������ 0:���Ϸ��ķ�ʽ;1:TCP��ʽ,��MVS��ȡ����;2:UDP��ʽ����ƽ̨��ȡ��Ƶ����;3:ͼƬ��
} URLINFO;

typedef struct App_Version_Url
{
	App_Version_Url()
	{
        SetStringNull(m_appVersion, MAX_URL_LEN+1);
        SetStringNull(m_appUpdateUrl, MAX_URL_LEN+1);
	}
	s8 m_appVersion[MAX_URL_LEN+1];
	s8 m_appUpdateUrl[MAX_URL_LEN+1];
}APPVERSIONURL;


// stream url list
typedef struct Stream_UrlList
{
    Stream_UrlList()
    {
        m_byUrlNum = 0;
    }
    u8 m_byUrlNum; // url number
    URLINFO m_aStreamUrl[MAX_STREAM_URL_NUM]; // stream url info
} URLLIST;

// stream callback dwPlayId: stream play id(from StartRealPlay) pFrmHdr: stream data dwContext: user data
typedef void(*Stream_Callback)(u32 dwPlayID, PFRAMEHDR_SDK pFrmHdr, void * dwContext);

// stream YUV callback dwPlayID: stream play id(from StartRealPlay) pFrmYuv: YUV data dwContext: user data
typedef void(*StreamYuv_Callback)(u32 dwPlayID, PFRAMEYUV_SDK pFrmYuv, void * dwContext);

// select streasm url callback
typedef int(*SelectStreamUrl_Callback) (const URLLIST *pUrlList, void * lUserData);


/* �ûص��������������嶼ֱ�Ӹ��ƺ�͸����uniplay
pAddDrawDC ��һ���ṹ��
win�£�
typedef struct
{
void *hdc;
void *hwnd;
void *rendertype;//��Ⱦ���ͣ�D3Dֱ����ʾ��D3D��ʾ��DDRAW��ʾ��DRAWDIB��ʾ��
}DrawDC;
��win�� pAddDrawDCֻ�Ǹ�ָ��
*/

//ÿ֡�����Ļص�
typedef void(*McusdkDraw_Callback)(u32 dwPlayID, void *pAddDrawDC, void * dwContext);
//¼��ϲ����Ȼص��ӿ�
typedef void (*Mcusdk_Combine_CallBack)(int nFileIndex, int dwCur, int dwTotal, void *dwContext);

// stream callback
typedef struct SDKCallbackMedia
{
    SDKCallbackMedia()
    {
        m_pSDKFrameCB = NULL;
        m_pSDKYUVCB = NULL;
        m_pSDKUrlCB = NULL;
        m_dwSDKUserData = 0;
    }
    Stream_Callback m_pSDKFrameCB; // stream frame callback
    StreamYuv_Callback m_pSDKYUVCB; // stream yuv data callback,after decode
    SelectStreamUrl_Callback m_pSDKUrlCB; // select stream url callback,for chose an accord url in application
    u32 m_dwSDKUserData; // user data
} CB_SDKMEDIA;

// stream callback V2
typedef struct SDKCallbackMedia_V2
{
	SDKCallbackMedia_V2()
	{
		m_pSDKFrameCB = NULL;
		m_pSDKYUVCB = NULL;
		m_pSDKUrlCB = NULL;
		m_dwSDKUserData = NULL;
	}
	Stream_Callback m_pSDKFrameCB; // stream frame callback
	StreamYuv_Callback m_pSDKYUVCB; // stream yuv data callback,after decode
	SelectStreamUrl_Callback m_pSDKUrlCB; // select stream url callback,for chose an accord url in application
	KDM_PARAM m_dwSDKUserData; // user data
} CB_SDKMEDIA_V2;

// stream callback (use in mcu sdk)
typedef struct StreamCallback
{
    StreamCallback()
    {
        m_pStreamFrameCB = NULL;
        m_pH264StreamCbFunc = NULL;
        m_pStreamDecodeCB = NULL;
        m_pStreamUrlCB = NULL;
        m_ptStreamSDK = NULL;
        m_dStreamUserData = 0;
    }
    void *m_pStreamFrameCB;//sdk layer H264 CallBack
    void *m_pH264StreamCbFunc;//application layer H264 CallBack
    void *m_pStreamDecodeCB;
    void *m_pStreamUrlCB;
    void *m_ptStreamSDK;
    KDM_PARAM   m_dStreamUserData;//�ڲ��õģ�����
} CB_STREAM;

/* error info(error to application) */
// work type(mcusdk work)
enum eWorkType
{
	emUnknown = 0,
	emLogin = 1,
	emLogout =2,
	emGetGroup=3, 
	emGetDevic=4,
	emStartStream=5, // �������󲥷���Ϣ�ص� m_dwWorkID(dwPlayID)��mvc���ɵģ�Ҫת������sdk���Ǹ�����ID�ϱ����ϲ���� m_dwErrorCode = 0; m_dwReserve1 = CS_MSG_START_PLAY_SUCCESS;
	emRecvKeyFrame=6, // ��һ���ؼ�֡�������Ϣ�ص�
	emStopStream=7,
	emPtz=8, 
	emSubscript=9,
	emLocalRec=10,
	emSnapshot=11, // ץ���Ƿ�ɹ�����Ϣ�ص�
	emSearchRec=12, // ��ѯ¼�����ϱ�
	emStartPlayRec=13,	//¼�񲥷Ž���֪ͨ
	emStopPlayRec=14,
	emVcrCtrl=15, // �յ�ʱ�ж���tEvent.m_dwErrorCode = MCU_ERRCODE_RECORD_STOP_PLAY_NTF; ��ʾֹͣ���ź����������֪ͨ
	emHeartbeatError=16, // ��ƽ̨������֪ͨ���������ղ��������豸״̬����Ҫ���µ�¼�������豸
	emSearchDvc=17, // �����������¼���־(Kdm_SearchDvcReq)
	emRecordDownLoad=18,
	emRecordDownLoadPace=19,
	emSyncTime = 20, // EventInfo�����������������64λUTCʱ�䣬m_dwReserve1Ϊ��32λ��m_dwReserve2Ϊ��32λ��һ��ֻ�õ���32λ��Kdm_SetTimeSyncServer��
	emDecStyleChanged = 21,// EventInfo��m_dwReserve1Ϊ�����仯�Ľ��������ָ�루culib����ǽ�Ͻ���������л�֪ͨ,ƽ̨1.0��أ�
	emChangePassWord = 22, // ��������ʧ��ʱ�Ĵ����¼�֪ͨ��1.0ƽ̨��	
	emSearchResult=23,	//����ͼ�豸������������ص�, m_dwReserve1��ʾ�ɹ���ʧ�ܵ�bool����,true��ʾ�������,false��ʾ�����˴���, m_dwWorkID��ʾtaskId
	emMVCPlayDisconnected=24,	//MVC��ĳһ·���Ŷ������¼�֪ͨ��m_dwWorkID ��ʾ����ID,errorcode=MCU_PLAYER_ERR_DEVICES_OFFLINE��������������	
	emDoubleAudioChannel=25,	//��˫·��Ƶ��ʱ�򣬻�������֪ͨ��m_dwWorkID ��ʾ����ID��m_dwReserve1��ʾ��һ·����ƵID,m_dwReserve2��ʾ�ڶ�·����ƵID
	emReEncodeBufferFull=26,	//uniplay�ر��뻺������Ҳ���Ǳ����������㣩m_dwWorkID ��ʾ����ID��errorcode��������������0
	emStartPlayFailed=27,	//ͨ�õĲ���ʧ�ܵ�֪ͨ��m_dwWorkID ��ʾ����ID��errorcode�����������ĺ�����ʱ����
	emWaterMarkRecordFailed=28,   //ˮӡ����¼���ˮӡ¼�����ع����е�ʧ�ܣ��ϲ��յ�֪ͨ����ֹͣˮӡ¼�����
	emSenderStreamFailed=29,	//��������ʧ�� m_dwWorkID ��ʾ����ID��errorcode�����������ĺ�����ʱ����
 
};

//ƽ̨�������ͣ�ĳЩ�ӿ���Ҫƽ̨֧�������������ʹ�ã�
enum eCapType
{
	emCapTypeUnknow=0,
	emCapTypeMultiViewDeviceTreeSearch,	//�Ƿ�֧�ֶ���ͼ�豸������������ȻҲ����ϵͳĬ������������
	emCapTypeNum,
};

// event infomation
typedef struct tagEventInfo
{
    tagEventInfo()
    {
        m_dwErrorCode = 0;
        m_emWork = emUnknown;
        m_dwWorkID = 0;
        m_dwReserve1 = 0;
        m_dwReserve2 = 0;
    }
    u32 m_dwErrorCode; // error code
    eWorkType m_emWork; // work
    u32 m_dwWorkID; // work id: playid/taskid...
    u32 m_dwReserve1;
    u32 m_dwReserve2;
} EVENTINFO;

// error callback, (mcusdk will call this fucntion when error occur)
typedef int(*McuSdkEvent_Callback)(EVENTINFO *pEventInfo, void * lUserData);

//�����ص��ĺ���ԭ��
typedef void (*PMCUSDK_GETAUDIOPOWER)(u16 byAudioPower, void* pvContext);


//Time Period
typedef struct tagTimePeriod
{
    tagTimePeriod()
    {
        m_dwStartTime = 0;
        m_dwEndTime = 0;
    }
    u32 m_dwStartTime;
    u32 m_dwEndTime;
} TPeriod;

typedef struct tagRecordInfo
{
    tagRecordInfo()
    {
        memset(m_dwRecID,0,sizeof(m_dwRecID));
        memset(m_recordDomainName,0,sizeof(m_recordDomainName));
        m_eRecType = emInvailedRecord;
    }
    TPeriod m_tRecPeriod;// ¼���ܵ�ʱ���
    char 	m_dwRecID[MAX_DEV_DIR+1];// ¼���ʶ(Token)
    char    m_recordDomainName[MAX_DEV_DIR+1];// ¼����������
    DEVCHN 	m_tDevChn;// ¼��ı�����ͨ��
    eRecordType m_eRecType;
} TRecordInfo;

typedef struct tagRecordInfo_V2
{
	tagRecordInfo_V2()
	{
		memset(m_dwRecID, 0, sizeof(m_dwRecID));
		memset(m_recordDomainName, 0, sizeof(m_recordDomainName));
		m_eRecType = emInvailedRecord;
		m_recEvent = emRecordEventUnknow;
	}
	TPeriod m_tRecPeriod;
	char 	m_dwRecID[MAX_DEV_DIR + 1];
	char    m_recordDomainName[MAX_DEV_DIR + 1];
	DEVCHN 	m_tDevChn;
	eRecordType m_eRecType;
	emRecordEventType m_recEvent;
} TRecordInfo_V2;

typedef struct tagRecordDownloadInfo
{
	tagRecordDownloadInfo()
	{
		m_pFileFullName = NULL;
		m_emFileType = emMp4;
		m_byRecordType = emInvailedRecord;
		m_dwReserve1 = 0;
		m_dwReserve2 = (u32)-1;
	}
	TPeriod m_tRecPeriod;
	char* m_pFileFullName;//������·�����ļ������׺
	ELocalRecType m_emFileType;
	eRecordType	m_byRecordType;
	u32 m_dwReserve1;//��Ϊ0ʱ�������صı���
    u32 m_dwReserve2;//��λ���룬����SDK�ڲ�����������ʱ��ʱ������ʱ�䣬������Ĭ�ϳ�ʱ10000���룬����Ϊ0ʱ������SDK�ڲ���ʱ����
}TRecordDownloadInfo;

typedef struct tagRecordDownloadInfo_V2
{
	tagRecordDownloadInfo_V2()
	{
		m_emFileType = emMp4;
		m_byRecordType = emInvailedRecord;
		memset(m_pFileFullName,0,sizeof(m_pFileFullName));
		m_dwReserve1 = 0;
		m_dwReserve2 = (u32)-1;
	}
	TPeriod m_tRecPeriod;
	char m_pFileFullName[MAX_SM_STR_LEN+1];//������·�����ļ������׺
	ELocalRecType m_emFileType;
	eRecordType	m_byRecordType;
	u32 m_dwReserve1;//��Ϊ0ʱ�������صı���
    u32 m_dwReserve2;//��λ���룬����SDK�ڲ�����������ʱ��ʱ������ʱ�䣬������Ĭ�ϳ�ʱ10000���룬����Ϊ0ʱ������SDK�ڲ���ʱ����
}TRecordDownloadInfo_V2;

typedef struct tagRecordPlayInfo
{
	tagRecordPlayInfo()
	{
		m_byRecordType = emInvailedRecord;
		m_pDrawWnd = NULL;
		m_dwReserve1 = 0;
		m_dwReserve2 = 0;
	}
	TPeriod m_tRecPeriod;
	eRecordType	m_byRecordType;
	void* m_pDrawWnd;
    s8    m_szManufactor[MAX_NAME_LEN+1]; // device manufactor
	u32 m_dwReserve1;
    u32 m_dwReserve2;
}TRecordPlayInfo;

#ifdef __cplusplus
}
#endif /* __cplusplus */


// ��Ļ״̬
enum emOSDState
{
	OSDStateInvalid,	// 0 ��Чֵ
	OSDStateDisable,	// 1 ����
	OSDStateText,		// 2 �ı�ģʽ����Ļ.
};

typedef struct tagVidOSD
{
	emOSDState state;//״̬
	int left;//������Ļ��߾� 1-200;
	int top;//������Ļ�ϱ߾� 1-200;
	u32 color;//��Ļ��ɫ		
	char title[MAX_DISPLAY_CONTENT_LEN + 1]; //��Ļ���ݣ�UTF8����	
}TVidOSD;
enum RecordPlayCtrlType
{
    CTRL_Invailed = -1,
    CTRL_PLAY = 0,
    CTRL_PAUSE = 1,
    CTRL_SEEK = 2,
    CTRL_SCALE = 3,
	CTRL_SINGLE_FRAME = 4,
    CTRL_FORCE_KEYFRAME = 5,
    CTRL_FORCE_ALLFRAME = 6,
	CTRL_KEYSEEK = 7,/*��λ���ؼ�֡. */
	CTRL_AUTO_KEYFRAME = 8,/*�Զ�ģʽ���Ƿ��֡��NRUȷ�����ͱ���ȫ֡���߱���ֻ�Źؼ�֡*/

	CTRL_BACKWARD_PLAY = 9,/*¼���л��ɵ���*/
	CTRL_FORWARD_PLAY = 10,/*¼��ӵ����л������ţ���Ҫ���ô�VCR������ CTRL_PLAY*/
};

typedef struct tagRecordPlayCtrlInfo
{
	tagRecordPlayCtrlInfo()
	{	
		m_byCtrlType =(RecordPlayCtrlType)-1;
		m_dwRange = 0;
		m_dwPlayId = (unsigned int)(-1);
	}
	
	char m_byCtrlType; //ȡֵ��Χ��RecordPlayCtrlType
	int m_dwRange; //play��seekʱΪ������ʼʱ��, scaleʱΪ��������ֵΪ���١���ֵΪ���٣�,����δָ���˲��������VCR���ƣ�����Դ�ֵ
	unsigned int m_dwPlayId; //dwplayID
}TREPCTLINFO;

typedef struct tagRecordPlayCtrlInfo_V2
{
	tagRecordPlayCtrlInfo_V2()
	{	
		m_byCtrlType =(RecordPlayCtrlType)-1;
		m_dwRange = 0;
		m_dwPlayId = (unsigned int)(-1);
		m_bQuickDecode = TRUE;
		m_dwRelease1 = 0;
		m_dwRelease2 = 0;
	}

	char m_byCtrlType; //ȡֵ��Χ��RecordPlayCtrlType
	int m_dwRange; //play��seekʱΪ������ʼʱ��, scaleʱΪ��������ֵΪ���١���ֵΪ���٣�,����δָ���˲��������VCR���ƣ�����Դ�ֵ
	unsigned int m_dwPlayId; //dwplayID
	BOOL32 m_bQuickDecode; //�Ƿ��ڿ��ʱ���ÿ�⣬����uniplayδ�����⻺����ֵ��ʹ����ⷽʽ���ʱ��Ч
	u32 m_dwRelease1;
	u32 m_dwRelease2;
}TREPCTLINFO_V2;

typedef struct tagEncoderParam
{
    tagEncoderParam()
    {
        memset(this, 0, sizeof(tagEncoderParam));
    }
    u8 m_byVideoFormat;
    u32 m_dwVideoResolution;
    u8 m_byFrameRate;
    u8 m_byQuality;
    u32 m_dwBitRate;
    u16 m_wInterval;
    u8 m_byBrightness;
    u8 m_byContrast;
    u8 m_bySaturation;
    u16 m_wSharpness;
} TEncoderParam;

typedef struct tagEncoderParam_V2
{
	tagEncoderParam_V2()
	{
		memset(this, 0, sizeof(tagEncoderParam_V2));
	}
	u8 m_byVideoFormat;
	u32 m_dwVideoResolutionType;
	u32 m_dwVideoResolutionWidth;
	u32 m_dwVideoResolutionHeight;
	u8 m_byFrameRate;
	u8 m_byQuality;
	u32 m_dwBitRate;
	u16 m_wInterval;
	u8 m_byBrightness;
	u8 m_byContrast;
	u8 m_bySaturation;
	u16 m_wSharpness;
} TEncoderParam_V2;
enum eVideoFormat
{
    em_VF_VideoInvalid = 0,
    em_VF_SN4 = 1,
    em_VF_MPEG4,
    em_VF_H261,
    em_VF_H263,
    em_VF_H264,
	em_VF_H265,
	em_VF_SVAC, 
	em_VF_MJPEG,
};

enum eVideoResolution
{
    em_VR_ResInvalid = 0,
    em_VR_Auto = 0x0001,
    em_VR_Qcif = 0x0002,
    em_VR_Cif = 0x0004,
    em_VR_2Cif = 0x0008,
    em_VR_4Cif = 0x0010,
    em_VR_QQcif = 0x0020,
    em_VR_QVGA = 0x0040,
    em_VR_VGA = 0x0080,
    em_VR_720P = 0x0100,
    em_VR_1080P = 0x0200,
    em_VR_QXGA = 0x0400,
	em_VR_UXGA = 0x0800,
	em_VR_QuadVGA = 0x1000,
};

enum eVideoQuality
{
    em_VP_Invalid = 0,
    em_VP_Quality = 1,
    em_VP_Speed = 2,
};

typedef struct tagSupportResolution
{
    tagSupportResolution()
    {
        m_byVideoFormat = em_VF_VideoInvalid;
        m_dwSupportResolution = em_VR_ResInvalid;
    }
    void SetSupportResolution(u32 dwSupportResolution)
    {
        m_dwSupportResolution = dwSupportResolution;
    }
    void AppendSupportResolution(u32 dwSupportResolution)
    {
        m_dwSupportResolution |= dwSupportResolution;
    }
    u32 GetSupportResolution()
    {
        return m_dwSupportResolution;
    }
    BOOL32 IsSupportResolution(eVideoResolution emVidRes)
    {
        return m_dwSupportResolution & emVidRes;
    }
    void SetVideoMode(eVideoFormat emVideoFormat)
    {
        m_byVideoFormat = emVideoFormat;
    }
    void SetVideoMode(u8 byVideoFormat)
    {
        m_byVideoFormat = byVideoFormat;
    }
    eVideoFormat GetVideoFormat()
    {
        eVideoFormat emRtnFormat = em_VF_VideoInvalid;
        switch( m_byVideoFormat )
        {
            case 1:
                emRtnFormat = em_VF_SN4;
                break;
            case 2:
                emRtnFormat = em_VF_MPEG4;
                break;
            case 3:
                emRtnFormat = em_VF_H261;
                break;
            case 4:
                emRtnFormat = em_VF_H263;
                break;
            case 5:
                emRtnFormat = em_VF_H264;
                break;
        }
        return emRtnFormat;
    }
    u8 m_byVideoFormat;
    u32 m_dwSupportResolution;
} TSupportResolution;

typedef struct tagSupportResolution_V2
{
	tagSupportResolution_V2()
	{
		m_byVideoFormat = em_VF_VideoInvalid;
		m_dwSupportResolutionType = em_VR_ResInvalid;
	}
	void SetSupportResolution(u32 dwSupportResolution)
	{
		m_dwSupportResolutionType = dwSupportResolution;
	}
	void AppendSupportResolution(u32 dwSupportResolution)
	{
		m_dwSupportResolutionType |= dwSupportResolution;
	}
	u32 GetSupportResolution()
	{
		return m_dwSupportResolutionType;
	}
	BOOL32 IsSupportResolution(eVideoResolution emVidRes)
	{
		return m_dwSupportResolutionType & emVidRes;
	}
	void SetVideoMode(eVideoFormat emVideoFormat)
	{
		m_byVideoFormat = emVideoFormat;
	}
	void SetVideoMode(u8 byVideoFormat)
	{
		m_byVideoFormat = byVideoFormat;
	}
	eVideoFormat GetVideoFormat()
	{
		eVideoFormat emRtnFormat = em_VF_VideoInvalid;
		switch( m_byVideoFormat )
		{
		case 1:
			emRtnFormat = em_VF_SN4;
			break;
		case 2:
			emRtnFormat = em_VF_MPEG4;
			break;
		case 3:
			emRtnFormat = em_VF_H261;
			break;
		case 4:
			emRtnFormat = em_VF_H263;
			break;
		case 5:
			emRtnFormat = em_VF_H264;
			break;
		}
		return emRtnFormat;
	}
	u8 m_byVideoFormat;
	u32 m_dwSupportResolutionType;
	u32 m_dwSupportResolutionWidth;
	u32 m_dwSupportResolutionHeight;
} TSupportResolution_V2;
typedef struct tagEncoderParamTotal
{
    tagEncoderParamTotal()
    {
        
    }
    BOOL32 IsSupportVideoFormat(eVideoFormat emVidFormat)
    {
        for( u8 byIdx = 0; byIdx < MAX_SUPPORT_VIDEO_TYPE_NUM; byIdx++ )
        {
            if( m_atSpResolution[byIdx].GetVideoFormat() == em_VF_VideoInvalid )
            {
                return FALSE;
            }
            if( m_atSpResolution[byIdx].GetVideoFormat() == emVidFormat )
            {
                return TRUE;
            }
        }
        return FALSE;
    }
    void SetSupportVideoResolution(eVideoFormat emVidFormat, u32 dwSPResolution)
    {
        for( u8 byIdx = 0; byIdx < MAX_SUPPORT_VIDEO_TYPE_NUM; byIdx++ )
        {
            if( m_atSpResolution[byIdx].GetVideoFormat() == em_VF_VideoInvalid ||
                m_atSpResolution[byIdx].GetVideoFormat() == emVidFormat )
            {
                m_atSpResolution[byIdx].SetVideoMode(emVidFormat);
                m_atSpResolution[byIdx].SetSupportResolution(dwSPResolution);
                break;
            }
        }
    }
    void AppendSupportVideoResolution(u8 byVidFormat, u32 dwSPResolution)
    {
        for( u8 byIdx = 0; byIdx < MAX_SUPPORT_VIDEO_TYPE_NUM; byIdx++ )
        {
            if( m_atSpResolution[byIdx].GetVideoFormat() == em_VF_VideoInvalid ||
               m_atSpResolution[byIdx].GetVideoFormat() == byVidFormat )
            {
                m_atSpResolution[byIdx].SetVideoMode(byVidFormat);
                m_atSpResolution[byIdx].AppendSupportResolution(dwSPResolution);
                break;
            }
        }
    }
    TEncoderParam m_tEncoderParam;
    TSupportResolution m_atSpResolution[MAX_SUPPORT_VIDEO_TYPE_NUM];
} TEncoderParamTotal;
typedef struct tagEncoderParamTotal_V2
{
	tagEncoderParamTotal_V2()
	{
		m_atSpResolutionSize = 0;
	}
	BOOL32 IsSupportVideoFormat(eVideoFormat emVidFormat)
	{
		for( u8 byIdx = 0; byIdx < MAX_SUPPORT_VIDEO_TYPE_NUM; byIdx++ )
		{
			if( m_atSpResolution[byIdx].GetVideoFormat() == em_VF_VideoInvalid )
			{
				return FALSE;
			}
			if( m_atSpResolution[byIdx].GetVideoFormat() == emVidFormat )
			{
				return TRUE;
			}
		}
		return FALSE;
	}
	void SetSupportVideoResolution(eVideoFormat emVidFormat, u32 dwSPResolution)
	{
		for( u8 byIdx = 0; byIdx < MAX_SUPPORT_VIDEO_TYPE_NUM; byIdx++ )
		{
			if( m_atSpResolution[byIdx].GetVideoFormat() == em_VF_VideoInvalid ||
				m_atSpResolution[byIdx].GetVideoFormat() == emVidFormat )
			{
				m_atSpResolution[byIdx].SetVideoMode(emVidFormat);
				m_atSpResolution[byIdx].SetSupportResolution(dwSPResolution);
				break;
			}
		}
	}
	void AppendSupportVideoResolution(u8 byVidFormat, u32 dwSPResolution)
	{
		for( u8 byIdx = 0; byIdx < MAX_SUPPORT_VIDEO_TYPE_NUM; byIdx++ )
		{
			if( m_atSpResolution[byIdx].GetVideoFormat() == em_VF_VideoInvalid ||
				m_atSpResolution[byIdx].GetVideoFormat() == byVidFormat )
			{
				m_atSpResolution[byIdx].SetVideoMode(byVidFormat);
				m_atSpResolution[byIdx].AppendSupportResolution(dwSPResolution);
				break;
			}
		}
	}
	TEncoderParam_V2 m_tEncoderParam;
	u32 m_atSpResolutionSize;
	TSupportResolution_V2 m_atSpResolution[MAX_SUPPORT_VIDEO_TYPE_NUM_V2];
} TEncoderParamTotal_V2;

typedef struct TagPlayExtInfo
{
	TagPlayExtInfo()
	{
		LocalVidRtpPort = 0;
		LocalVidRtcpPort = 0;
		LocalAudRtpPort = 0;
		LocalAudRtcpPort = 0;
		memset(LocalStreamIP,0,sizeof(LocalStreamIP));
		RemoteVidRtpPort = 0;
		RemoteVidRtcpPort = 0;
		RemoteAudRtpPort = 0;
		RemoteAudRtcpPort = 0;
		memset(RemoteStreamIP,0,sizeof(RemoteStreamIP));
		memset(mediaStreamType,0,sizeof(mediaStreamType));
		memset(manufacture, 0, sizeof(manufacture));
	};
	u16 LocalVidRtpPort;
	u16 LocalVidRtcpPort;
	u16 LocalAudRtpPort;
	u16 LocalAudRtcpPort;
	char LocalStreamIP[MAX_ID_LEN];
	u16 RemoteVidRtpPort;
	u16 RemoteVidRtcpPort;
	u16 RemoteAudRtpPort;
	u16 RemoteAudRtcpPort;
	char RemoteStreamIP[MAX_ID_LEN];
	char mediaStreamType[MAX_ID_LEN];
	char manufacture[MAX_NAME_LEN];
}PlayExtInfo;

typedef struct tagPlyIngChnAudVidInfo
{
	tagPlyIngChnAudVidInfo()
	{
        //SetStringNull(VideoType, MAX_SM_STR_LEN+1);
        //SetStringNull(AudioType, MAX_SM_STR_LEN+1);
		memset(VideoType,0,sizeof(VideoType));
		memset(AudioType,0,sizeof(AudioType));
		VideoSmpRate = 0;
		AudioSmpRate = 0;
		AudioChnlNum = 0;
	};
	s8	   VideoType[MAX_SM_STR_LEN+1];
	u32	   VideoSmpRate;
	s8	   AudioType[MAX_SM_STR_LEN+1];
	u32    AudioSmpRate;
	u32    AudioChnlNum;

}TTPlyingChnAVInfo;

typedef enum eTransType
{
	emTransChnCOMPort = 0, // �豸COM��͸������
	emTransChnCameraTaskConfig = 1, // �����������������
	emTransChnExtData = 2, // ͸�����ݣ�֧������Ӧ��֪ͨ��̬ģ��
	emTransChnUserDef = 3, // ͸�����ݣ��û��Զ���͸����������,��ǰ���������ģ��֧�ֽ��ղ�����
}TransChnType;

typedef struct tagTransData
{
    tagTransData()
    {
		memset(m_byTransBuffer,0,sizeof(m_byTransBuffer));
        m_wTransBufferLen = 0;
        m_byAppType = 0;
    }
    u8 m_byTransBuffer[MAX_TRANSCHAN_DATA_LEN+1];
    u16 m_wTransBufferLen;
    s8 m_byAppType;
} TTransChnData;

typedef struct tagTransData_V2
{
    tagTransData_V2()
    {
		memset(m_byTransBuffer,0,sizeof(m_byTransBuffer));
        m_wTransBufferLen = 0;
        m_byAppType = 0;
		m_TransChnType = emTransChnCOMPort;
    }
    u8 m_byTransBuffer[MAX_TRANSCHAN_DATA_LEN+1];
    u16 m_wTransBufferLen;
	u16 m_byAppType; // ͸��ͨ����Ϣ����
	TransChnType m_TransChnType; // ͸��ͨ������
} TTransChnData_V2;

typedef struct tagTransData_V3
{
	tagTransData_V3()
	{
		m_pTransBuffer = NULL;
		m_wTransBufferLen = 0;
		m_byAppType = 0;
		m_TransChnType = emTransChnCOMPort;
	}
	u8 *m_pTransBuffer; // ͸��ͨ������
	u16 m_wTransBufferLen; // ͸��ͨ�����ݴ�С�����ֵ��8KB
	u16 m_byAppType; // ͸��ͨ����Ϣ����
	TransChnType m_TransChnType; // ͸��ͨ������
} TTransChnData_V3;

typedef struct tagTransDataRsp
{
	tagTransDataRsp()
	{
		m_pTransBuffer = NULL;
		m_wTransBufferLen = 0;
		m_byAppType = 0;
		memset(m_szUserName, 0, sizeof(m_szUserName));
		m_nPtzLevel = 0;
		m_dwBeginTime = 0;
		m_dwEndTime = 0;
		m_bHasNotify = FALSE;
		m_nErrorCode = 0;
		memset(m_szErrorDesc, 0, sizeof(m_szErrorDesc));
	}
	u8 *m_pTransBuffer; // ͸��ͨ��Ӧ�����ݣ���С����Ϊ8KB���ڴ����ϲ�Ӧ��ά����
	u16 m_wTransBufferLen; // ͸��ͨ��Ӧ�����ݴ�С
	u16 m_byAppType; // ͸��ͨ����Ϣ����
	char m_szUserName[MAX_NAME_LEN + 1];
	int m_nPtzLevel;
	u32 m_dwBeginTime;
	u32 m_dwEndTime;
	BOOL32 m_bHasNotify;
	int m_nErrorCode;
	char m_szErrorDesc[MAX_DESC_LEN + 1];
} TTransChnDataRsp;

typedef struct tagTransDataGB
{
	tagTransDataGB()
	{
		m_pTransBuffer = NULL;
		m_wTransBufferLen = 0;
		m_pMsgTypeGB = NULL;
		m_wMsgTypeGBLen = 0;
		m_byAppType = 0;
	}
	u8 *m_pTransBuffer; // ͸��ͨ������
	u16 m_wTransBufferLen; // ͸��ͨ�����ݴ�С�����ֵ��MAX_TRANSCHAN_DATA_LEN_V2
	u8 *m_pMsgTypeGB; // ͸��ͨ��ʵ��Я�����������ͣ�����ֵ����ǰ�˹����豸Э��ȷ��
	u16 m_wMsgTypeGBLen; // ͸��ͨ��ʵ��Я�����������ͳ��ȣ����ΪMAX_TRANSCHAN_MSGTYPEGB_LEN
	u16 m_byAppType; // ͸��ͨ����Ϣ����
	BOOL32 m_bEnd; // �Ƿ������һ��֪ͨ
} TTransChnDataGB;

typedef struct tagTransDataRspGB
{
	tagTransDataRspGB()
	{
		m_pTransBuffer = NULL;
		m_wTransBufferLen = 0;
		m_pMsgTypeGB = NULL;
		m_wMsgTypeGBLen = 0;
		m_byAppType = 0;
		memset(m_szUserName, 0, sizeof(m_szUserName));
		m_nPtzLevel = 0;
		m_dwBeginTime = 0;
		m_dwEndTime = 0;
		m_bHasNotify = FALSE;
		m_nErrorCode = 0;
		memset(m_szErrorDesc, 0, sizeof(m_szErrorDesc));
	}
	u8 *m_pTransBuffer; // ͸��ͨ��Ӧ�����ݣ��ڴ����ϲ�Ӧ��ά����
	u16 m_wTransBufferLen; // ͸��ͨ��Ӧ�����ݴ�С�����ΪMAX_TRANSCHAN_DATA_LEN_V2
	u8 *m_pMsgTypeGB; // ͸��ͨ��ʵ��Я�����������ͣ�����ֵ����ǰ�˹����豸Э��ȷ��
	u16 m_wMsgTypeGBLen; // ͸��ͨ��ʵ��Я�����������ͳ��ȣ����ΪMAX_TRANSCHAN_MSGTYPEGB_LEN
	u16 m_byAppType; // ͸��ͨ����Ϣ����
	char m_szUserName[MAX_NAME_LEN + 1];//����PTZ���û����������ɹ�ֵΪ�գ�
	int m_nPtzLevel;//����PTZ���û�ptz���Ƶȼ��������ɹ�Ϊ�գ�
	u32 m_dwBeginTime;//������ʼʱ��
	u32 m_dwEndTime;//�Զ�����ʱ��
	BOOL32 m_bHasNotify;// �Ƿ���emDevTransDataNtfGB֪ͨ
	int m_nErrorCode;
	char m_szErrorDesc[MAX_DESC_LEN + 1];// PTZ����ԭ����ɵ�ʧ��
} TTransChnDataRspGB;

//tvWall Start 
typedef struct tagTvWallCommonData
{
	tagTvWallCommonData()
	{
        //SetStringNull(m_TvWallID, MAX_DESC_LEN+1);
		memset(m_TvWallID,0,sizeof(m_TvWallID));
		m_tvId = 0;
		m_tvDivId = 0;
	}
	char 			m_TvWallID[MAX_DESC_LEN+1];	// ����ǽId.
	int 			m_tvId;						// ���ӻ�Id.
	int 			m_tvDivId;					// ���ӻ��ֻ���Id.
}TTvWallCommonData;

typedef struct tagTvWallPlayData
{
	tagTvWallPlayData()
	{
		m_ChnID = 0;
	}
	TTvWallCommonData	m_TvWallComData;
	DeviceID 			m_devURI;				// ������/IPC ����ƵԴ�豸��Ψһ��ʶ
	int 				m_ChnID;				// ������/IPC ����ƵԴͨ�� 

}TTvWallPlayData;

typedef struct tagTvDivNumData
{
	tagTvDivNumData()
	{
        //SetStringNull(m_TvWallID, MAX_DESC_LEN+1);
		memset(m_TvWallID,0,sizeof(m_TvWallID));
		m_tvId = 0;
		m_tvDivTotal = 0;
	}
	char 			m_TvWallID[MAX_DESC_LEN+1];	// ����ǽId.
	int 			m_tvId;						// ���ӻ�Id.
	int 			m_tvDivTotal;				// ���ӻ�������emETVWallDivStyle
}TTvDivNumData;

typedef struct tagTvWallTotal
{
	tagTvWallTotal()
	{
		tvWallTotal = 0;
		tvWallDecoderBindTotal = 0;
	}
	int tvWallTotal;
	int tvWallDecoderBindTotal;

}TTvWallTotal;

typedef struct tagCTVDecoderBind
{
	tagCTVDecoderBind()
	{
		m_tvId = 0;
		m_decoderOutputId = 0;
		m_tvDivNum = 0;
	}
	int m_tvId;		         // �������
	int m_tvDivNum;			 //���ӻ�������
	DeviceID m_decoderId;	 // �������豸id.
	int m_decoderOutputId;	// �����������Id. 

}TTVDecoderBind;


typedef struct tagTvWallInfo
{
	tagTvWallInfo()
	{
		memset(m_TvWallID,0,sizeof(m_TvWallID));
		memset(m_name,0,sizeof(m_name));
		m_tvNum = 0;
		m_tvwallStyle = 0;
		memset(m_tvwallCustomStyleData,0,sizeof(m_tvwallCustomStyleData));
		memset(m_desc,0,sizeof(m_desc));
		m_createTime = 0;
		memset(m_tClientID,0,sizeof(m_tClientID));
		m_tvDecoderBindArrayRealSize = 0;
		m_tvDecoderBindArray =  NULL;
	}
	char 			m_TvWallID[MAX_DESC_LEN+1];				// ����ǽId.
	DomainID 		m_domainId; 							// ����ǽ��������
	char 			m_name[MAX_DESC_LEN+1];    				// ����ǽ����
	int 			m_tvNum;								// ���ӻ���Ŀ
	int 			m_tvwallStyle;							// ����ǽ���, ��ʹ��ö�٣���ΪTAS�����ľ�������ݣ�����ʱ����������ʱTASҲҪ����
	char 			m_tvwallCustomStyleData[MAX_DESC_LEN*10+1];// ����ǽ�Զ���������
	char 			m_desc[MAX_DESC_LEN+1];                 // ����ǽ����
	int 			m_createTime;		        			// ��������,time_t��vc6.0��ռ��4���ֽڣ�����vsϵ����ռ��8���ֽڣ��ʸ�Ϊint��
	char			m_tClientID[ADDR_STR_LEN+1];			//�ͻ�ID;
	int				m_tvDecoderBindArrayRealSize;
	TTVDecoderBind* m_tvDecoderBindArray; 					// ������������󶨹�ϵ
}TTvWallInfoData;

enum emETVWallDivStyle
{
	emSDK_TVDIV_Invalid = 0, 
	emSDK_TVDIV_1 = 1, 
	emSDK_TVDIV_2 = 2, 
	emSDK_TVDIV_3 = 3, 
	emSDK_TVDIV_4 = 4, 
	emSDK_TVDIV_6 = 6, 
	emSDK_TVDIV_8 = 8, 
	emSDK_TVDIV_9 = 9, 
	emSDK_TVDIV_16 = 16,
	emSDK_TVDIV_25 = 25,
	emSDK_TVDIV_36 = 36,
};

typedef struct tagTPuChn
{
	tagTPuChn()
	{
		m_byEdcChnId = 0;
		m_byVidChnId = 0;
		m_dwSessIDOrRpChn = 0;
		memset(m_achNO,0,sizeof(m_achNO));
	}

    u8  m_byEdcChnId;        //������ͨ����;
    u8  m_byVidChnId;        //��ƵԴ��;
    unsigned int m_dwSessIDOrRpChn;   //�ỰID��¼����ͨ��
	char m_achNO[LEN_KDM_NO+1];
}TTPuChn;

typedef struct tagDevChannel
{
	tagDevChannel()
	{
		channelId = 0;
	}
    DeviceID deviceId;     //�豸��Ψһ��ʶ pu uuid@domain
    int    channelId;      //ͨ���п����Ǳ���ͨ�����п�������ƵԴ�����п����Ƿ���ͨ��, Ҫ����Э�����Ӧ�ó����ж�
}TDevChannel;

// ��Ѳ״̬
enum emEPollStatus_NTF
{
    emSDK_PollStatusInvalid = 0,	// ��Чֵ.
    emSDK_PollStarted = 1,	// ��Ѳ�Ѿ���ʼ.
    emSDK_PollStoped = 2,	// ��Ѳ�Ѿ�ֹͣ.
    emSDK_PollPaused = 3,	// ��Ѳ��ͣ.
};

// ����ǽ�Ĳ���ģʽ.
enum emETVWallPlayMode_NTF
{
    emSDK_TVWallPlayModeInvalid = 0,	// ��Чֵ.
    emSDK_TVPlayModeLiveStream = 1,
    emSDK_TVPlayModePlatformRecord = 2,
    emSDK_TVPlayModePuRecord = 3,
};

// ����ǽ��һ������ϳ��Ӵ��ڵ�״̬.
typedef struct tagTVWallTVDivStateNtf
{
    tagTVWallTVDivStateNtf()
    {
        divId = 0;
        divPlayMode = emSDK_TVWallPlayModeInvalid;
        memset(recordPlaySession,0,sizeof(recordPlaySession));
        pollState = emSDK_PollStatusInvalid;
        errorCode = -1;
    }
    int divId;	// ����ϳ��Ӵ���(ͨ��)Id.

    enum emETVWallPlayMode_NTF divPlayMode;	// ����ǽ�ֻ���Ĳ���ģʽ. ( ʵʱ���, ƽ̨¼��, ǰ��¼�� ).
    char recordPlaySession [MAX_DESC_LEN+1];	// ¼�񲥷ŵ�Session.
    TRecordInfo recordPlayDuration;	// ��ǰ���ŵ�¼��ʱ���.

    enum emEPollStatus_NTF pollState;	// ������Ѳ��״̬.	

    TDevChannel encoderChn;	// ��ǰ����ı�����ͨ��.
    int errorCode;		// ��ǰ���������ֵĴ���, ������.
}TTVWallTVDivStateNtf;


// ������Ѳ��һ��
typedef struct tagTvWallWindowPollStep
{
	tagTvWallWindowPollStep()
	{
		duration = 0;
	}
	TDevChannel		encoderChn;	// ������/IPC ����ƵԴͨ��.
	int 		duration;					// ����ƵԴ����������ʱ��.
}TTvWallSchemeTvDivPollStep;

// �����ϵĵ����Ӵ���(����ϳ�)��Ԥ��.
typedef struct tagTTvWallSchemeTvDiv
{
	tagTTvWallSchemeTvDiv()
	{
		divId = -1;
		tvWallSchTvDivPollStepArrayRealSize = 0;
		tvWallSchTvDivPollStepArray = NULL;
	}
	int divId;	// ������ͨ��id.
	TTvWallSchemeTvDivPollStep* tvWallSchTvDivPollStepArray;	// ��Ѳ�ĸ�������. ���ֻ��һ����Ѳ, ������ͨ���.
	int tvWallSchTvDivPollStepArrayRealSize;
}TTvWallSchemeTvDiv;

// �������ӵ�Ԥ��.
typedef struct tagTvWallTVSchemeTv
{
	tagTvWallTVSchemeTv()
	{
		tvId = -1;
		divStyle = emSDK_TVDIV_Invalid;
		tvWallScheTvDivArray = NULL;
		tvWallScheTvDivArrRealSize = 0;
	}
	int tvId;					// ����Id
	DeviceID 					m_decoderId;// �������豸id.
	enum emETVWallDivStyle divStyle;	// ���ڵĻ���ϳɷֻ�����.	
	TTvWallSchemeTvDiv* tvWallScheTvDivArray;	// ���ӵĻ���ϳɵ�С����.	
	int 			  tvWallScheTvDivArrRealSize;
}TTvWallSchemeTv;


// ����ǽ��Ԥ��.
typedef struct  tagTvWallScheme
{
	tagTvWallScheme()
	{
		memset(schemeName,0,sizeof(schemeName));
		memset(tvWallId,0,sizeof(tvWallId));
		schemeSN = 0;
		memset(m_tClientID,0,sizeof(m_tClientID));
		tvSchemeTvArray = NULL;
		tvSchemeTvArrayRealSize = 0;
	}
	u32  	schemeSN;						//Ԥ�����(����Ԥ��ʱ��������)
	char	m_tClientID[ADDR_STR_LEN+1];	//�ͻ�ID;
	u8		byOwnerType;					//��������
	char 	schemeName[MAX_DESC_LEN+1];	// Ԥ������.
	char 	tvWallId[MAX_DESC_LEN+1];	// Ԥ����������ǽId.
	
	TTvWallSchemeTv*  tvSchemeTvArray;	// ����ǽ�����е��ӵ�Ԥ���б�.	
	int     tvSchemeTvArrayRealSize;
}TTvWallScheme;

typedef struct tagTvWallSchemeTotal
{
	tagTvWallSchemeTotal()
	{
		tvWallSchemeMaxSize = 0;
		tvWallSchemeTvMaxSize= 0;
		tvWallSchemeTvDivMaxSize = 0;
		tvWallSchemeTvDivPollStepMaxSize = 0;
	}
	int tvWallSchemeMaxSize;
	int tvWallSchemeTvMaxSize;
	int tvWallSchemeTvDivMaxSize;
	int tvWallSchemeTvDivPollStepMaxSize;

}TTvWallSchemeTotal;
//tvWall End


//SchemePollStep Start
// 2.0 ֻҪֻ��Ҫ��д����ǽID
// 1.0 ֻ��Ҫ��д������ͨ��
typedef struct tagSchemePollStepReq
{
	tagSchemePollStepReq()
	{
		memset(m_tvWallId,0,sizeof(m_tvWallId));
		m_dwTvWallProjId = 0;
		m_byTvId = 0;
		m_byDivisionId = 0;
	}

	char 		m_tvWallId[MAX_DESC_LEN+1];	// Ԥ����������ǽId.
    u32 		m_dwTvWallProjId; //����ǽԤ�����;
    u8 			m_byTvId; //���ӻ���;
    u8 			m_byDivisionId;//�����(���㿪ʼ)
    TTPuChn 	m_tPuChn; //������ͨ��;
}TSchPollStepReq;


// 2.0 ֻ��Ҫ��дԤ������Ԥ������ʱ��
// 1.0 ֻ��Ҫ��дԴ���������䱣��ʱ��
typedef struct  tagTVWallSchemePollStep
{
	tagTVWallSchemePollStep()
	{
		memset(tvWallSchemeName, 0, sizeof(tvWallSchemeName));
		duration = 0;

		m_byPollFlag = 0;
		m_wPollSrcIndex = 0;
		m_wPollSrcNum = 0;
		m_dwTime = 0;
	}
	// 2.0
	char tvWallSchemeName[MAX_DESC_LEN + 1];	// Ԥ��������
	int duration;					// Ԥ���л�ǰ�ı���ʱ������.

	// 1.0
	u8 m_byPollFlag; //��ѯ��־λ;
	u16 m_wPollSrcIndex; //������ѯ������;
	u16 m_wPollSrcNum; //��ѯԴ�ı�������Ŀ;
	u32 m_dwTime;  // Դ�������鱣��ʱ��
	TTPuChn m_atEncPu; //��ѯ��Դ��������;
	TTPuChn m_tLookPu;//��ǰ����ѡ����PU,�豸��Ϊ�ձ�ʾѡ����Ч
}TTvWallSchemePollStep;

typedef struct  tagTVWallSchemePollStepTotal
{
	tagTVWallSchemePollStepTotal()
	{
		memset(mTvWallPollSteps, 0, sizeof(mTvWallPollSteps));
		tvWallSchNum = 0;
		m_wPollSrcNum = 0;
	}

	TTvWallSchemePollStep mTvWallPollSteps[MAXNUM_SRCPU_POLL];
	u16 tvWallSchNum; // 2.0 Ԥ����Ŀ
	u16 m_wPollSrcNum; // 1.0 ǰ�˱�������Ŀ
}TTvWallSchemePollStepTotal;
enum emETVWallSCHEPOLLSTEPCMD
{
	emSDK_TVWSSCMD_INVALID = 0,
	emSDK_TVWSSCMD_CONFIG = 1,		// ����
	emSDK_TVWSSCMD_START = 2,       // ��ʼ*/
	emSDK_TVWSSCMD_STOP = 3,        // ֹͣ*/ 
	emSDK_TVWSSCMD_PAUSE = 4,       // ��ͣ*/
	emSDK_TVWSSCMD_RESUME = 5,      // �ָ�*/
	emSDK_TVWSSCMD_SEEK = 6,        // ʱ�䶨λ*/
	emSDK_TVWSSCMD_FASTPLAY = 7,    // ��� ������*/		
	emSDK_TVWSSCMD_SLOWPLAY = 8,    // ���� ������ */
	emSDK_TVWSSCMD_ONEFRAME = 9,    // ��֡����*/
	emSDK_TVWSSCMD_KEYFRAME = 10,    // ֻ�Źؼ�֡*/
	emSDK_TVWSSCMD_REVERSEPLAY = 11,	/*����*/
	emSDK_TVWSSCMD_FORWARDPLAY = 12,	/*����*/
	emSDK_TVWSSCMD_KEYSEEK = 13,		/*��λ���ؼ�֡. */
	emSDK_TVWSSCMD_UNKNOWN = 14,          
};
//SchemePollStep End

//��״̬
enum EDomainStatus
{
	emDomainStatusInvalid = 0, // ��Чֵ.
	emDomainOnline = 1,        // ����.
	emDomainOffline = 2,       // ����.
};

//˽������Ϣ
typedef struct tagCDomainInfo
{
	tagCDomainInfo()
	{
		memset(m_domainName,0,sizeof(m_domainName));
	}
	DomainID m_domainId;
	char m_domainName[MAX_DESC_LEN+1];
	DomainID m_parentDomainId;
	
}TDomainInfo;

//����������Ϣ
typedef struct tagCChildrenGBDomainInfo
{
	tagCChildrenGBDomainInfo()
	{
		memset(m_domainName,0,sizeof(m_domainName));
	}
	DomainID m_gbDomainId; //������ID
	char m_domainName[MAX_DESC_LEN+1]; //����
	EDomainStatus m_status; //��״̬EDomainStatus	
}TChildrenGBDomainInfo;

typedef struct tagCNruInfo
{
	tagCNruInfo()
	{
		memset(m_nruId,0,sizeof(m_nruId));
		memset(m_devName,0,sizeof(m_devName));
		memset(m_devType,0,sizeof(m_devType));
		memset(m_manuFactory,0,sizeof(m_manuFactory));
		memset(m_ifName,0,sizeof(m_ifName));
		memset(m_ipAddr,0,sizeof(m_ipAddr));
		memset(m_netMask,0,sizeof(m_netMask));
		memset(m_gateway,0,sizeof(m_gateway));
		memset(m_RMSAddr,0,sizeof(m_RMSAddr));
		m_maxBandWidthKb = 0;
		m_online = FALSE;
		m_used = FALSE;
	}
	char m_nruId[MAX_DESC_LEN+1];         // nru id��
	char m_devName[MAX_DESC_LEN+1];       // �豸��
	char m_devType[MAX_NAME_LEN+1];       // �豸����:VS200,KDM2801E��
	char m_manuFactory[MAX_DESC_LEN+1];   // �豸����

	char m_ifName[MAX_DESC_LEN+1];        // ������.
	char m_ipAddr[ADDR_STR_LEN+1];        // IP��ַ.
	char m_netMask[ADDR_STR_LEN+1];       // ��������.
	char m_gateway[ADDR_STR_LEN+1];       // ����.

	char m_RMSAddr[ADDR_STR_LEN+1];       // ע��RMS��������ַ.
	int m_maxBandWidthKb;       // NRU��������ݴ���, ��λ Kb/S.
	bool m_online;              // �Ƿ�����.
	bool m_used;                // �Ƿ�����.
}TCNruInfo;

typedef struct tagUserData
{
	tagUserData()
	{
		memset(dataKey,0,sizeof(dataKey));
		memset(dataValue,0,sizeof(dataValue));
		dataType = 0;
		dataFragNo = 0;
		dataAllFragNum = 0;
	}
	char dataKey[MAX_NAME_LEN+1];
	int  dataType;
	int  dataFragNo;
	int  dataAllFragNum;
	char dataValue[MAX_NAME_LEN+1];
}TUserData;

typedef struct tagStreamTransLocal
{
	tagStreamTransLocal()
	{
		STLocalVideoRtpPort = 0;
		STLocalVideoRtcpPort = 0;
		STLocalAudioRtpPort = 0;
		STLocalAudioRtcpPort = 0;
		memset(&STLocalIP,0,sizeof(STLocalIP));
	}
	
	u16 STLocalVideoRtpPort;
	u16 STLocalVideoRtcpPort;
	u16 STLocalAudioRtpPort;
	u16 STLocalAudioRtcpPort;
	char STLocalIP[ADDR_STR_LEN+1];
}TStreamTransLocal;

typedef struct tagStreamTransRemote
{
	tagStreamTransRemote()
	{
		STRemoteVideoRtpPort = 0;
		STRemoteVideoRtcpPort = 0;
		STRemoteAudioRtpPort = 0;
		STRemoteAudioRtcpPort = 0;
		STRemoteNatPort = 0;
		memset(STRemoteIP,0,sizeof(STRemoteIP));
		memset(STRemoteNatIP,0,sizeof(STRemoteNatIP));
		memset(RemoteStreamType,0,sizeof(RemoteStreamType));
		nVideoSampleRate = 0;
		nAudioSampleRate = 0;
	}
	u16 STRemoteVideoRtpPort;
	u16 STRemoteVideoRtcpPort;
	u16 STRemoteAudioRtpPort;
	u16 STRemoteAudioRtcpPort;
	char STRemoteIP[ADDR_STR_LEN+1];
	char STRemoteNatIP[ADDR_STR_LEN+1];
	char RemoteStreamType[MAX_ID_LEN+1];
	int STRemoteNatPort;
	int nVideoSampleRate;//��Ƶ������
	int nAudioSampleRate;//��Ƶ������
	u16 wLocalStartPort;//������ʼ�˿ڣ���ƽ̨1.0�����ڼ��㱾��VideoRtp���ն˿�(wLocalStartPort+4*playid),VideoRtcp��AudioRtp��AudioRtcp�����1
}TStreamTransRemote;

typedef struct tagWatchTask
{
	tagWatchTask()
	{
		m_byWatchTaskEnable = 0;
		m_byWatchTaskMinutes =0;
		for(int Idx=0;Idx< MAX_WATCH_ON_NUM;Idx ++)
		{
			m_byWatchTaskIntervals[Idx] = 0;
		}
	}

	u8	  m_byWatchTaskEnable;                     // ptz �������Ƿ�������ʱ��������0�����á�
	u8	  m_byWatchTaskMinutes;                        // ptz �����󼸷���������ʱ����
	u8	  m_byWatchTaskIntervals[MAX_WATCH_ON_NUM];    // ���ö�ʱ����ʱ��
	TPTZAUTHORITY m_PtzAuthority;
}TWatchTask;

typedef struct tagWatchPrPos
{
	tagWatchPrPos()
	{
		m_byPrePosEnable = 0;
		m_byPrePosTime =0;
		m_byPrePos =0;
	}
	u8    m_byPrePosEnable;                      // ֹͣptz����������Ԥ��λʹ�ܣ���0�����á�
	u8    m_byPrePosTime;                        // ֹͣptz�����󼸷��Ӻ�����Ԥ��λ
	u8    m_byPrePos;                            // ���뼸��Ԥ��
	TPTZAUTHORITY m_PtzAuthority;
}TWatchPrePos;

enum AudioEncodeType
{
	AUDIO_TYPE_PCMA = 0x00000001,
	AUDIO_TYPE_PCMU = 0x00000002,
	AUDIO_TYPE_GSM = 0x00000004,
	AUDIO_TYPE_G729 = 0x00000008,
	AUDIO_TYPE_ADPCM = 0x00000010,
	AUDIO_TYPE_G7221C = 0x00000020,
	AUDIO_TYPE_G722 = 0x00000040,
	AUDIO_TYPE_AACLC = 0x00000080,
};

typedef struct tagAudioParams
{
public:
	u32 m_dwSupportedAudioType;//֧�ֵ�����ѹ����ʽ��ֻ����;
	u32 m_dwAudioType;		//��Ƶ���ݸ�ʽ; 
	u8 m_byVolume;			//���� 0-25;
	u8 m_byAECState;		//��������״̬ DISABLE-��Ч��ENABLE-��Ч;
	u32 m_dwSmpRate;        //������ 
	u8 m_bySmpBits;         //����λ�� 
	u8 m_byChannle;         //���� 
	u32 m_dwSamplePerF;     //ÿ֡������
	u32 m_dwReserved;		//�����ֶ�

	//�Ƿ�֧��ĳ����Ƶ����
	BOOL32 IsAudioTypeSupported(u32 dwAudioType) const
	{
		return m_dwSupportedAudioType & dwAudioType;
	}
	//������Ƶ����֧��
	void SetAudioTypeSupport(u32 dwAudioType)
	{
		m_dwSupportedAudioType = m_dwSupportedAudioType | dwAudioType;
	}
	//��ȡ��Ƶ���ݸ�ʽ
	u32 GetAudioType() const
	{
		return m_dwAudioType;
	}
	//������Ƶ���ݸ�ʽ
	void SetAudioType(u32 dwAudioType)
	{
		m_dwAudioType = dwAudioType;
	}

	//��ȡ���� 0-25
	u8 GetVolume() const
	{
		return m_byVolume;
	}
	//�������� 0-25
	void SetVolume(u8 byVolume)
	{
		m_byVolume = byVolume;
	}

	//��ȡ��������״̬ DISABLE-��Ч��ENABLE-��Ч
	BOOL32 IsAECState() const
	{
		return m_byAECState;
	}
	//���û�������״̬ DISABLE-��Ч��ENABLE-��Ч
	void SetIsAECState(BOOL32 bAECState)
	{
		m_byAECState = bAECState;
	}
	//��ȡ�����ʣ���λΪbps
	u32 GetSmpRate()
	{
		return m_dwSmpRate;
	}
	//���ò�����
	void SetSmpRate(u32 dwSmpRate)
	{
		m_dwSmpRate = dwSmpRate;
	}
	//��ȡ����λ����8λ��16λ��32λ��
	u8 GetSmpBits()
	{
		return m_bySmpBits;
	}
	//���ò���λ��
	void SetSmpBits(u8 bySmpBits)
	{
		m_bySmpBits = bySmpBits;
	}
	//��ȡ��˫������1-��������2-˫����
	u8 GetChannel()
	{
		return m_byChannle;
	}
	//���õ�˫����
	void SetChannel(u8 byChannel)
	{
		m_byChannle = byChannel;
	}
	//��ȡÿ֡������
	u32 GetSamples()
	{
		return m_dwSamplePerF;
	}
	//����ÿ֡������
	void SetSamples(u32 dwSamples)
	{
		m_dwSamplePerF = dwSamples;
	}
}TAudioParams;

// ������ѡ��״̬
typedef struct tagDecodeWatchStatus
{
	TTPuChn m_tDecChn;		// ������ID
	TTPuChn m_tSrcPuChn[MAX_DECODE_CHN_NUM];		// ѡ���ı�����ͨ��
}TDecodeWatchStatus;

// ¼�����
typedef struct tagRecordParam
{
	//ע��! ¼������ֻ����ǿ��ɾ��¼��Ĳ�����,�Ż�ʹ�õ� TRecAlarmType��ƽʱ�Ĳ�ѯ�Ȳ�������� EmRecType
	DEVCHN m_DevChn;
	enum TRecAlarmType { e_IsALarm, e_NoIsAlarm, e_CanForceDel }; // �澯���Ǹ澯����ǿ��ɾ����־λ
	enum { REC_UNLOCK, REC_LOCKED };
	u32 m_dwVodID; //¼��ID;
	char m_ClientID[MAX_ID_LEN + 1]; //�ͻ�ID;
	u8 m_byRecType; //�澯���ǷǸ澯;
	u32 m_StartTime; //��ʼ�ͽ���ʱ��;
	u32 m_EndTime;
	char m_NruID[MAX_ID_LEN + 1]; //¼�������ID;
	char m_szFilePath[MAXLEN_FILEPATH + 1]; //¼��·��;
	char m_szFileName[MAXLEN_FILENAME + 1 - 4]; //¼����;����¼������ʽ��cmu������֯,�ҳ��Ƚ�Ϊ�̶�,�������൱һ���ֿռ�δ��ʹ��
	//��ȡ���4λ���ڴ���Զ���������
	u32 m_dwUnlockTime; //�Զ���������(��m_byBitType��3��bit��Чʱ���ֶβ�������)
	char m_szFileAlias[MAXLEN_ALIAS + 1]; //¼�����; 
	u8 m_byIsHasAudio;		//�Ƿ�ʹ����Ƶ
	u8 m_byIsGBRecord;		//�Ƿ��ǹ��곧�̵�¼��
	u8 m_byIsHasAutoUnlockTime;		//�Ƿ�����Զ���������
	u8 m_byVidEncFmt; //MPEG4, H264(kdvdef.h)
	u8 m_byAudioEncFmt;
	u32 m_dwRecSize; //¼���С����λK��
	TTPuChn m_tPuChn; //ǰ��;
	s8 m_szManuFac[MAXLEN_DEVICE_MANUFACTURER + 1]; //�豸������
	u8 m_byRecTypeEx;  //¼������  -- Del��̬�غ�ֵ
}TRecordParamInfo;

typedef struct tagOperRecordParam
{
	tagOperRecordParam(){
		m_byOperType = OPER_TYPE_NULL;
		m_dwReason = 0;  
		m_dwReseve1 = 0;
		m_wLockDays = 0;
		m_wLockPointType = LOCK_FROM_NOW;
	}

	enum { OPER_TYPE_NULL, OPER_TYPE_GET, OPER_TYPE_LOCK, OPER_TYPE_UNLOCK };
	enum { LOCK_FROM_NOW, LOCK_FROM_STARTTIME };
	u8 m_byOperType; //�������ͣ�See enum 
	u32 m_dwReason;  //ԭ��
	u32 m_dwReseve1; //�����ֶ�1
	u16 m_wLockDays; //��Ҫ����������,0��ʾ��������
	u16 m_wLockPointType;  //������Ч����ʼ��,�ӵ�ǰʱ��(LOCK_FROM_NOW),��¼�񱣴�ʱ��(LOCK_FROM_STARTTIME)
}TOperRecordParam;

// �豸¼��״̬ö��
enum TRecStat
{
	emRecInvalid = 0,
	emRecIdel = 1,
	emRecOk = 2,
	emRecTry = 3,
	emRecStopping = 4,
};

enum TRecPlatPuStat
{
	emRecPlatPuInvalid = 0, // ����¼��
	emRecPlat = 1, // ��ƽ̨¼��
	emRecPu = 2, // ��ǰ��¼��
	emRecPlatPu = 3, // ƽ̨ǰ�˶���¼��
};


//�������ӿڷ��ص�ITEM��Ľ������ö��
enum emSearchResultType
{
	emSearchResultDeviceGroup = 1,
	emSearchResultDevice,
	emSearchResultVideosrc,
};

// �豸¼��״̬��Ϣ
typedef struct tagDevRecordInfo
{
	tagDevRecordInfo()
	{
		m_emDevRecStat = emRecPlatPuInvalid;
		memset(m_emPlatRecStat, 0, sizeof(m_emDevRecStat));
		memset(m_emPuRecStat, 0, sizeof(m_emDevRecStat));
	}

	DeviceID m_tDevID;

	TRecPlatPuStat m_emDevRecStat; // �Ƿ����ǰ�˻�ƽ̨¼��
	TRecStat m_emPlatRecStat[MAX_VID_CHN_NUM]; // ����ͨ��ƽ̨¼��״̬
	TRecStat m_emPuRecStat[MAX_VID_CHN_NUM]; // ����ͨ��ǰ��¼��״̬, ǰ��¼��ֻ��Idel��Ok״̬
}TDevRecordStatus;

typedef struct tagAudioCallSrc
{
	tagAudioCallSrc()
	{
		m_nDecodeChn = 0;
	}

	int m_nDecodeChn;
	TDevChannel m_tDevChannel;
}TAudioCallSrc;


typedef struct tagAudioCallStatus
{
	tagAudioCallStatus()
	{
		memset(m_atAudioCallSrc, 0 ,sizeof(m_atAudioCallSrc));
	}

	DeviceID m_tDevID;
	int nNum;
	TAudioCallSrc m_atAudioCallSrc[MAX_VID_CHN_NUM];

}TAudioCallStatus;


typedef struct tagDevChnIdName
{
	tagDevChnIdName()
	{
		m_DevChnId = 0;
		memset(m_DevChnName.szID,0,sizeof(m_DevChnName.szID));
	}
	int m_DevChnId;
	DeviceChnName m_DevChnName;

}TDevChnIdName;

typedef struct tagDevAllChnIdName
{
	tagDevAllChnIdName()
	{
		m_DevChnTotal = 0;
	}
	TDevChnIdName m_tDevChnName[MAX_VID_CHN_NUM];
	int m_DevChnTotal;

}TDevAllChnIdName;

//�������ͽ��յĵ�ַ��Ϣ
typedef struct tagTMediaAddrInfo
{
	tagTMediaAddrInfo()
	{
		memset(m_chIP, 0, sizeof(m_chIP));
		m_nRtpPort = 0;
		m_nRtcpPort;
	}
	char m_chIP[MAX_ADDR_LEN+1];
	int m_nRtpPort;
	int m_nRtcpPort;
}TMediaAddrInfo;
//������������������ƽ̨���ص������Լ�����������������Ҫ����Ϣ
typedef struct tagTPuCallInfo
{
	//��Ƶ���з��Ͷ˵ĵ�ַ��Ϣ
	TMediaAddrInfo m_localAddr;
	//����˽��������ĵ�ַ��Ϣ
	TMediaAddrInfo m_platAddr;
	//�����NAT������˵�NAT��Ϣ
	TMediaAddrInfo m_platNATAddr;
}TPuCallInfo;


typedef struct VoiceCallNatEx
{
	VoiceCallNatEx()
	{
		memset(m_cuSessionID,0,sizeof(m_cuSessionID));
		memset(m_chLocalIP,0,sizeof(m_chLocalIP));
		memset(m_chPlatIP,0,sizeof(m_chPlatIP));
		memset(m_chPlatNatIP,0,sizeof(m_chPlatNatIP));
		m_platRtpPort = 0;
		m_platRtcpPort = 0;
		m_PlatNatPort = 0;
		m_playID = 0;
		m_chReserverd = 0;
		m_localRtpPort = 0;
		m_localRtcpPort = 0;
	}

	char m_cuSessionID[ADDR_STR_LEN + 1];
	char m_chLocalIP[MAX_ADDR_LEN];
	char m_chPlatIP[MAX_ADDR_LEN];
	char m_chPlatNatIP[MAX_ADDR_LEN];
	
	int  m_platRtpPort;
	int  m_platRtcpPort;
	int  m_localRtpPort;
	int  m_localRtcpPort;
	int  m_PlatNatPort;
	int	 m_playID;
	char m_chReserverd;//����
}tagVoiceCallNatEx,*pTagVoiceCallNatEx;

// �������.
typedef struct tagDeviceGroupPathItem
{
	GroupID id;						// ���ID.
	char szName[MAX_NAME_LEN + 1];	// �������.
}TDeviceGroupPathItem;
typedef struct tagTSearchResultItem
{
	int type;		// ����, ����μ� emSearchResultType, �豸��/�豸/��ƵԴ
	KDMNO id;		// id

	int vsId;		// ��ƵԴid. ���Ϊ�豸��/�豸ʱ������.
	char szDevSrcAlias[MAX_NAME_LEN + 1]; // // ����

	int groupDeepth;										// �ϼ������Ŀ.
	tagDeviceGroupPathItem devGroupPath[MAX_GROUP_DEEPTH];	// �ϼ���.

	BOOL32 online;

	u16 nDevType; // device type
	u16 nDevCap; // device capability

	DomainID szDomainId;
	char szManufacturer[MAXLEN_DEVICE_MANUFACTURER+1];

}TSearchResultItem;

//����ͼ�豸����Ϣ
typedef struct tagDeviceTree
{
	char id[MAX_NAME_LEN+1];	//�豸��ID
	char name[MAX_NAME_LEN+1];//�豸����
	char version[MAX_NAME_LEN+1];//�豸�������ݰ汾��
	char rootid[MAX_ID_LEN+1];	//���ĸ���id
}DeviceTree;
//����豸����Ϣ�б�
typedef struct tagMultiViewDeviceTreeList
{
	DeviceTree trees[MAX_MULTIVIEW_DEVICE_TREE_NUM];
	int num;
}MultiViewDeviceTreeList;


enum emMcusdkTreeViewType
{
    emMcusdkTreeViewType_System = 0, //ϵͳ������ͼ�����û�����
    emMcusdkTreeViewType_User, //�û�������ͼ���û���ռ ���ղؼ�
};

typedef struct tagDeviceTree_V2
{
    char id[MAX_NAME_LEN+1];	//�豸��ID
    char name[MAX_NAME_LEN+1];//�豸����
    char version[MAX_NAME_LEN+1];//�豸�������ݰ汾��
    char rootid[MAX_ID_LEN+1];	//���ĸ���id
    int nType; //   emMcusdkTreeViewType
    int nReversed; //
}DeviceTree_V2;
//����豸����Ϣ�б�
typedef struct tagMultiViewDeviceTreeList_V2
{
    DeviceTree_V2 trees[MAX_MULTIVIEW_DEVICE_TREE_NUM];
    int num;
}MultiViewDeviceTreeList_V2;

typedef struct tagMcusdkVersionInfo
{
	char sdkver[MAX_NAME_LEN + 1];	//Mcusdk����Ķ����ư汾��
	char cmsver[MAX_NAME_LEN + 1];	//ƽ̨�İ汾��
	char cuver[MAX_NAME_LEN+1];		//ƽ̨�ϵĿͻ���cu�İ汾��
	char cuupdateurl[MAX_URL_LEN+1];	//ƽ̨�ϵĿͻ���cu������·��
}McusdkVersionInfo;

typedef struct tagSessionInfo
{
	char username[MAX_NAME_LEN + 1];
	char password[MAX_NAME_LEN + 1];
	char serveraddr[MAX_URL_LEN + 1];
	char clienttype[MAX_NAME_LEN + 1];
	char session[MAX_ID_LEN + 1];
	char cmsver[MAX_NAME_LEN + 1];
	char cuver[MAX_NAME_LEN + 1];	
	char cuupdateurl[MAX_URL_LEN + 1];
	char serverDataVersion[MAX_ID_LEN+1];
	char stunaddr[MAX_URL_LEN + 1];
}SessionInfo;

//����GPS��Ϣ�ص�����ԭ������
typedef void(*PMCUSDK_GPS_CALLBACK)(u32 /*nPlayId*/, void * /*pGpsData*/, u32 /*nDataLen*/, void * /*pUserData*/);

/*������ͳ����Ϣ*/
typedef struct tagMcusdkDecStatis
{
	unsigned int		dwVideoFrameRate;	/*��Ƶ����֡��*/
	unsigned int		dwVideoBitRate;   	/*��Ƶ��������*/
	unsigned int		dwAudioBitRate;   	/*������������*/
	unsigned int		dwVideoRecvFrame;	/*�յ�����Ƶ֡��*/
	unsigned int		dwAudioRecvFrame;	/*�յ�������֡��*/
	unsigned int		dwVideoLoseFrame;	/*��ʧ����Ƶ֡��*/
	unsigned int		dwAudioLoseFrame;	/*��ʧ������֡��*/
	unsigned int		dwVideoLoseRatio;	//��Ƶ��ʧ��,��λ��% 	
	unsigned int		dwAudioLoseRatio;	//��Ƶ��ʧ��,��λ��% 	
	unsigned int		dwPackError;		/*��֡��*/
	unsigned int		dwIndexLose;		/*��Ŷ�֡*/
	unsigned int		dwVideoSizeLose; 	/*��С��֡*/
	unsigned int		dwVideoFullLose; 	/*����֡*/
	unsigned int		dwAudioSizeLose; 	/*��С��֡*/
	unsigned int		dwAudioFullLose; 	/*����֡*/
	unsigned int		dwAvrVideoBitRate;   /*1��������Ƶ����ƽ������*/
	unsigned int	  	dwAvrAudioBitRate;   /*1��������������ƽ������*/
	bool                bVidCompellingIFrm;  /*��Ƶǿ������I֡*/
	unsigned int		dwDecdWidth;		/*�����Ŀ�*/
	unsigned int		dwDecdHeight;   	/*�����ĸ�*/
	unsigned int        dwCodecType;        /*��������,soft:0;hw:1;yuvcb:2;*/
	unsigned int        dwDrawMode;         /*��ͼ��ʽ,d3d:0;ddraw:1;drawdib:2;direct:3*/
}DecStatis;


//��ƽ̨2.0���ݵ�PTZ��������, ���� Kdm_PtzControl �ӿ�, ֧�ֶ��PTZ����.
enum EMcusdkPtzCmd
{
	McusdkPtzCmdInvalid = 0,			// 0	// �ղ���.
	McusdkPtzNull = McusdkPtzCmdInvalid,
	McusdkPtzCommandDefineBegin = 1,
	// ��1.0�ﶨ��һ��.
	McusdkPtzMoveUp = McusdkPtzCommandDefineBegin,			// 1	//�����ƶ�
	McusdkPtzMoveDown,	    	// 2	//�����ƶ�
	McusdkPtzMoveLeft,			// 3	//�����ƶ�
	McusdkPtzMoveRight,			// 4	//�����ƶ�
	McusdkPtzMoveHome,			// 5	//�ع�
	McusdkPtzMoveStop,			// 6	//ֹͣ�ƶ�
	McusdkPtzZoomIn,				// 7	//��������ͷ
	McusdkPtzZoomOut,				// 8	//��Զ����ͷ
	McusdkPtzZoomStop,			// 9	//��Ұ����ֹͣ
	McusdkPtzFocusFar,		    // 10	//�������Զ
	McusdkPtzFocusNear,			// 11	//���������
	McusdkPtzFocusAuto,			// 12	//�Զ�����
	McusdkPtzFocusStop,			// 13	//����ֹͣ
	McusdkPtzPresetSave,	    	// 14	//����ͷԤ��
	McusdkPtzPresetCall,			// 15	//������ͷԤ��
	McusdkPtzCameraReset,		 // 16	// ��ʼ������ͷ ??
	//PtzChangeVideoSrc,		// 16	// �л���ƵԴ(����ͷ)
	McusdkPtzBrightUp,			// 17	//�������
	McusdkPtzBrightDown,			// 18	//�������
	McusdkPtzBrightStop,			// 19	//ֹͣ����
	McusdkPtzCommandNew,			// 20	//������	  ������??	 1.0��û���õ�.
	McusdkPtzCommandAppend,		// 21	//�������� ������?? 1.0��û���õ�.
	McusdkPtzGotoPoint,			// 22	//���Ķ�λ
	McusdkPtzZoomArea,			// 23	//�ֲ��Ŵ�

	McusdkPtzAlecPanSpeed,	// 24	//������ˮƽ�ƶ��ٶ�����������ڲ�ʹ�ã� û�õ�??
	McusdkPtzAlecTiltSpeed,	// 25	//�����˴�ֱ�ƶ��ٶ�����������ڲ�ʹ�ã� û�õ�??
	McusdkPtzSonySetBright,	// 26	//sony���ȵ�����������ڲ�ʹ�ã�		û�õ�??

	McusdkPtzMatrixSwitch,		// 27	//�л���Ƶ
	McusdkPtzMatrixVideoMix4,		// 28	//����ϳ�2��2
	McusdkPtzMatrixVideoMix9,		// 29	//����ϳ�3��3
	McusdkPtzMatrixVideoMix16,	// 30	//����ϳ�4��4
	McusdkPtzMatrixVideoMixPP,	// 31	//����ϳɻ��л�

	McusdkPtzZoomAreaStop,		// 32    // ȡ���ֲ��Ŵ� 

	////�˵�//////////////////////////////////////////////////////////////////////	
	McusdkPtzMenuUp,				// 33	//�˵���
	McusdkPtzMenuDown,			// 34	//�˵���
	McusdkPtzMenuLeft,			// 35	//�˵���
	McusdkPtzMenuRight,			// 36	//�˵���

	McusdkPtzMenuShow,			// 37	//�˵���ʾ
	McusdkPtzMenuHide,			// 38	//�˵�����

	McusdkPtzMenuEnter,			// 39	//�˵�ȷ��
	McusdkPtzMenuCancel,		    // 40	//�˵�ȡ��

	McusdkPtzPresetDel,			// 41	//ɾ������ͷԤ�� (û�õ�?)
	////�����л�//////////////////////////////////////////////////////////////////////
	McusdkPtzMatrixSwitchASC,	// 42	//�����л�
	McusdkPtzMatrixSwitchESC,	// 43	//�����л�
	McusdkPtzMatrixHoldImage,	// 44	//ͼ�񱣳�

	McusdkPtzMoveLeftUp,		//(u8)45		//�������ƶ�
	McusdkPtzMoveLeftDown,	//(u8)46		//�������ƶ�
	McusdkPtzMoveRightUp,		//(u8)47		//�������ƶ�
	McusdkPtzMoveRightDown,	//(u8)48		//�������ƶ�

	////Ѳ��//////////////////////////////////////////////////////////////////////	
	McusdkPtzAutoScanStart = 128,  // 128	//��ʼ�Զ�Ѳ��
	McusdkPtzAutoScanStop,       // 129	//ֹͣ�Զ�Ѳ��	
	McusdkPtzPresetScanStart,		// 130	//��ʼѲ��(Ԥ��λ��Ѳ?)
	McusdkPtzPresetScanStop,     // 131	//ֹͣѲ��(Ԥ��λ��Ѳ?)
	McusdkPtzScanSpeedSet,		//(u8)132	//ˮƽɨ���ٶȣ�Ӱ���Զ�ɨ���ٶȣ�bySpeed(1-40s)	

	// ��ˢ
	McusdkPtzStartWiper = 160,		//(u8)160	//��ʼ��ˢ����һ������Ϊ��ˢ�ٶȣ�ֵΪ0-15��������������
	McusdkPtzStopWiper,			//(u8)161	//ֹͣ��ˢ

	//+ by maonanjing@2014-11-04
	McusdkPtzLightOn,            //(u8)162   //�����ƹ�
	McusdkPtzLightOff,           //(u8)163   //�رյƹ� 
	McusdkPtzStartExt1,           //(u8)164   //��չ����һ�������ǿ�����ˮ��
	McusdkPtzStopExt1,           //(u8)165   //�ر���ˮ��չ����һ
	McusdkPtzStartExt2,          //(u8)166   //��չ���ܶ��������ǿ�����˪��
	McusdkPtzStopExt2,			//(u8)167   //�رճ�˪��չ���ܶ�

	//+ by maonanjing@2016-04-06
	McusdkPtzLock,				//(u8)168	//�ƽ���Ȩ��

	McusdkPtzCommandDefineEnd,			// Ptz��������.
};

//ƽ̨2.0PTZ���Ƶ�����������Ϣ
typedef struct tagMcusdkPtzLockInfo
{
	char errorDesc[MAX_DESC_LEN+1];	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
	char userName[MAX_NAME_LEN+1];	/* required element of type xsd:string */
	int ptzLevel;	/* required element of type xsd:int */
	u32 beginTime;	/* required element of type xsd:dateTime */
	u32 endTime;	/* required element of type xsd:dateTime */
}McusdkPtzLockInfo;

typedef struct tagMcusdkAlarmlogReq
{
    tagMcusdkAlarmlogReq()
    {
        memset(deviceId, 0, sizeof(deviceId));
        memset(alarmName, 0, sizeof(alarmName));
        memset(deviceDomainName, 0, sizeof(deviceDomainName));        
        alarmChannelId = -1;
        timeBegin = 0;
        timeEnd = 0;
        alarmType = emAlarmTypeInvalid;        
    }        
    char deviceId[MAX_ID_LEN+1];
    int alarmChannelId;
    char  alarmName[MAX_NAME_LEN+1];
    char  deviceDomainName[MAX_NAME_LEN+1];
    u64 timeBegin;
    u64 timeEnd;
    int alarmType; // eAlarmType    
}McusdkAlarmlogReq;

typedef struct tagMcusdkAlarmLogItem
{
    char logId[MAX_ID_LEN+1];
    char deviceId[MAX_ID_LEN+1];
    int alarmChannelId;
    char deviceDomainName[MAX_NAME_LEN+1];
    char deviceName[MAX_NAME_LEN+1];
    char deviceAlias[MAX_NAME_LEN+1];
    int alarmType;    // eAlarmType
    int alarmStatus;  //eAlarmStatus
    u64 occurTime;
    u64 resumeTime;
    char alarmName[MAX_NAME_LEN+1];
    char description[MAX_NAME_LEN+1];
}McusdkAlarmLogItem;



enum EmMcusdkRecordEventType 
{
    emRS_RECTYPE_INVALID = 0,
    emRS_RECTYPE_ALL = 1,  // ȫ��
    emRS_RECTYPE_ALARM = 2, // �澯
    emRS_RECTYPE_HANDLE = 3, //�ֶ�
    emRS_RECTYPE_PLAN = 4,     //�ƻ�
    emRS_RECTYPE_UNKNOWN = 5,
};

typedef struct tagMcusdkSubRecordItem
{
    EmMcusdkRecordEventType recordtype;
    u64 qwstarttime;
    u64 qwendtime;
}McusdkSubRecordItem;

typedef struct tagMcusdkLockRecordItem
{
    TRecordInfo tRecordInfo; //ƽ̨¼��
    BOOL32 locked; // ¼���Ƿ�����
    u32 lockExpireTime; // ¼��������ʧЧʱ��

    int nsubrecordnums;//��¼������(�ݲ�֧��)
    McusdkSubRecordItem aSubRecordItem[MAX_REQ_DEV_SUBS_NUM];// ��¼������¼���еĲ�ͬ��¼��ε����ͣ�(�ݲ�֧��)
    
}McusdkLockRecordItem;

typedef struct tagMcusdkLockRecord
{
    int nLockNums;//��Ҫ�����������¼������
    tagMcusdkLockRecordItem aLockItem[MAX_REQ_DEV_SUBS_NUM];//��Ҫ�����������¼��
}McusdkLockRecord;

typedef struct tagMcusdkQueryLockedRecord
{
    DEVCHN devChn;   // ����¼��ļ�ص�. �����豸ID����Ϊ��, ��ʾ������������¼��. 
    BOOL32 enableTimeRange;// �Ƿ�ʹ��ʱ��β���. �����õĻ���������ʱ��ε�����¼��.
    TPeriod timeRange;// ����ʱ��Ρ�
    u32 maxResultNum;//���ص��������
    tagMcusdkQueryLockedRecord()
    {
        enableTimeRange = FALSE;
        maxResultNum = MAX_REQ_DEV_SUBS_NUM; // do not change
    }
}McusdkQueryLockedRecord;

typedef struct tagMcusdkQryLockedRecResult
{
    BOOL32 hasMoreResult;//�г������������¼���¼δ����.
    McusdkLockRecord tQryLockRecresult;//���
    tagMcusdkQryLockedRecResult()
    {
        hasMoreResult = FALSE;
    }
}McusdkQryLockedRecResult;

enum EmMcusdkBatchOpType
{
    emOpStartPlatRecord,	// ��ʼƽ̨¼��
    emOpStopPlatRecord,	// ֹͣƽ̨¼��
    emOpStartPuRecord,	// ��ʼǰ��¼��
    emOpStopPuRecrod,		// ֹͣǰ��¼��
    emOpStartWiper,		// ��ʼ��ˢ
    emOpStopWiper,		// ֹͣ��ˢ
    emOpStopPuCall,		// ֹͣ��������, ����1:�û����е�PlayId 
    emOpLoadPresetPos,	// ǰ������Ԥ��λ ����1: Ԥ��λID.
    emOpLockRecord,	//  ����ƽ̨¼��. ����1: ¼����ʼʱ��. ����2: ¼�����ʱ��. ʱ���ʽ��Ϊ��׼ʱ���ַ���
};

typedef struct tagMcusdkBatchOperation
{
    GroupID treeId; // ��ID, Ϊ����ΪϵͳĬ���豸��
    GroupID groupId;// ��ID
    BOOL32 bRecursive;// �Ƿ���¼��������ݹ����
    EmMcusdkBatchOpType operationType;// ��������
    u32 dwParamNum;//�����б�����
    BatchOpParam strParamList[MAX_REQ_DEV_SUBS_NUM];// �����б�, ���ݲ������Ͳ�ͬ,��Ҫ��ͬ�Ĳ���.
    tagMcusdkBatchOperation()
    {
        bRecursive = FALSE;
        dwParamNum = 0;
    }
}McusdkBatchOperation;


//PTZ��������
typedef struct tagMcusdkPTZLockReq
{
	tagMcusdkPTZLockReq()
	{
		memset(password, 0, sizeof(password));
	};
	DEVCHN devChn;
	TPeriod timeRange;
	char password[MAX_NAME_LEN+1];
}McusdkPTZLockReq;

//PTZ�����ظ�
typedef struct tagMcusdkPTZLockRsp
{
	tagMcusdkPTZLockRsp()
	{
		memset(username, 0, sizeof(username));
		ptzLevel = 0;		
		errorCode = 0;
	};
	char username[MAX_NAME_LEN + 1];
	int ptzLevel;	
	TPeriod timeRange;	
	int errorCode;//ƽ̨���صĴ�����
}McusdkPTZLockRsp;

//PTZ��������
typedef struct tagMcusdkPTZUnLockReq
{
	tagMcusdkPTZUnLockReq()
	{
		memset(password, 0, sizeof(password));
	};
	DEVCHN devChn;	
	char password[MAX_NAME_LEN + 1];
}McusdkPTZUnLockReq;

//PTZ�����ظ�
typedef struct tagMcusdkPTZUnLockRsp
{
	tagMcusdkPTZUnLockRsp()
	{
		memset(username, 0, sizeof(username));
	};
	char username[MAX_NAME_LEN + 1];
	int ptzLevel;
	TPeriod timeRange;
}McusdkPTZUnLockRsp;

typedef struct tagMcusdkAlarmSource
{
    char szAlarmDeviceId[MAX_ID_LEN+1];
    int nAlarmInputChnId;
    int nAlarmType;
}McusdkAlarmSource;


#define  ALARMLINK_ACTION_PLATFORMRECORD   0x01 //ƽ̨¼��
#define  ALARMLINK_ACTION_PLAYONTV                0x02 // ��ǽ
#define  ALARMLINK_ACTION_READSECOND           0x04 // ����
#define  ALARMLINK_ACTION_IOOUTPUT                0x08 // io�˿����
#define  ALARMLINK_ACTION_CAMERAPREPOS       0x10 // ����ͷԤ��λ���� 

typedef struct tagMcusdkAlarmLinkAction
{
    u32 dwActionType; // ���ָ澯�������� ���л�Ľ�� ALARMLINK_ACTION_....
    char szDeviceId[MAX_ID_LEN+1]; // �������豸id
    int nSrcId; //��ƵԴ
    int ncamPrePos; // ����ͷԤ��λ
    char szTvWallId[MAX_ID_LEN+1];
    int nTvId;
    int nTvDivId;
    int nAlarmIOOutputChnId;
}McusdkAlarmLinkAction;

typedef struct tagMcusdkAlarmLinkTimeDuration
{
    int nMinute;
    int nHour;
    int nDay;
    int nMonth;
    int nWday;
    int nTimeZone;
    int nDuration;
}McusdkAlarmLinkTimeDuration;

typedef struct tagMcusdkAlarmLinkConfig
{
    BOOL32 bEnabled;
    int nActionNums;
    McusdkAlarmLinkAction aActionList[MAX_GENERAL_ARRAY_NUM];
    // �澯����ʱ����б�
    int nDurationNum;
    McusdkAlarmLinkTimeDuration aDurationList[MAX_GENERAL_ARRAY_NUM];
}McusdkAlarmLinkConfig;

typedef struct tagMcusdkAlarmType
{
    int nAlarmType;
    char szAlarmName[MAX_NAME_LEN+1];
}McusdkAlarmType;

typedef struct tagMcusdkAlarmTypesInfo
{
    int nNum;
    McusdkAlarmType aAlarmTypeList[MAX_GENERAL_ARRAY_NUM];
}McusdkAlarmTypesInfo;

//Ԥ��λ����
typedef struct tagMcusdkPresetName
{
	int nPresetId;
	char szName[MAX_NAME_LEN + 1];
}McusdkPresetName;

//ǰ��¼��ƻ�����
typedef struct tagMcusdkRecordPlan
{
	ERecMode recMode;	//¼��ģʽ
	int nPrerecordDuration;	//Ԥ¼ʱ������λ�룩��0��ʾ��Ԥ¼
	int nRecordDurationAfterAlarm;	// �澯�ָ���ƽ̨¼��ʱ��, ��λ��.
	
	BOOL32 bSupportChangeStreamType;       // ֧���л�¼����������
	int nRecStreamType;                  // ¼���������͡�0-������1-����1��2-����2��3-����3

	BOOL32 bSupportSetRecDuration; //�Ƿ�֧������¼��洢ʱ��	
	BOOL32 bRecDurationEnabled; //��ǰ�Ƿ�����¼��洢ʱ������
	int nRecStorageDuration; //¼��洢ʱ����>=1�죩��0-ϵͳĬ��

	int nTimeListNum;//���������������Ч���ַ�����
	char planedRecordCronTimeList[MAX_TIME_LIST_NUM][MAX_DESC_LEN+1];
}McusdkRecordPlan;


// ������Ϣ��
typedef struct tagMcusdkPartitionInfo
{
	int diskId;				// ��������Id.
	int partitionId;		// ����Id.
	char partName[MAX_NAME_LEN+1];	// ������.
	int totalSize;			// �ܿռ�, ��λ MB
	int freeSize;			// ���пռ�, ��λ MB.
	ERSPartState partState;	// ����״̬.
	char partType[MAX_SHOT_NAME_LEN+1];	// ������ʽ( vbfs, ext3 )
	int abnNum;				// �쳣����.
	char mountPath[MAX_URL_LEN+1];	// ����·��.
	int start;				// ��ʼ��λ��.
	int end;				// ������λ��
	int recordNum;			// ¼����.
}McusdkPartitionInfo;


//������Ϣ
typedef struct tagMcusdkDIskInfo
{
	int diskId;				// ����Id.
	char diskName[MAX_NAME_LEN+1];	// ������.
	int diskSize;			// ����. ��λMB.
	int diskAbnNum;			// �쳣����.
	ERSDiskState diskState;	// ����״̬.
	char diskSource[MAX_DESC_LEN+1];	// ��Դ.
	int cylinders;			// ������.
	int heads;				// ��ͷ��.
	int sectors;			// ������Ŀ
	int partitionNum;//����ķ�������
	McusdkPartitionInfo partitionList[MAX_PARTITION_NUM];	// �����б�.
}McusdkDIskInfo;

//��ȡ��������Ϣ����ṹ��
typedef struct tagMcusdkGetDeviceBindReq
{
	char *nruId;	// NRU��UUID
	char *diskMountPath;	// ������mount·����
	int beginIndex;	// ��ʼ���.
	int num;			// ��������Ҫ������.
}McusdkGetDeviceBindReq;

//֧��ʱ������ʱ��ͬ��¼���ҳͬ����ѯ����ṹ��
typedef struct tagMcusdkQueryRecordReq
{
	DEVCHN devChn;	
	TPeriod timeRange;
	eRecordType recType;
	emRecordEventType recEvent;
	char *domainName;	
}McusdkQueryRecordReq;

//����ˮӡ����,ֱ�����ø�������Ⱦģ���
typedef struct tagMcusdkWaterMark
{	
	emWaterMarkMode    eWMMode;	 //ѡ�����ˮӡģʽ�������� ������ һ������
	BOOL32             bEnable;				//�Ƿ���ˮӡ;Ĭ�Ϲرգ�TRUE����
	unsigned int        uiARGB;				//������ɫ��͸����0xAARRGGBB
	unsigned int        uiFontSize;			//�����С[16,2000]
	unsigned int        uiFontRotate;		//��ת�Ƕȡ�0~360��
	unsigned int        uiLayerMode;		//1��ƽ�̣����ơ��������ξ���ƽ�̣������������֡�����̫���������ضϡ�
	char *strText;      //utf8�������ݣ�����uniplay�����ƣ�ʵ��ֻ�ܴ������60����ĸ��30�����֣������Ļᱻ�ض�
	char *pstrFontPath; //utf8�ֿ�·�������ΪNULL���ڲ���ѡ��һ��Ĭ�ϵ��ֿ�
	unsigned int uiWinWidth;   //ˮӡ���ڿ��
	unsigned int uiWinHeight;  //ˮӡ���ڿ��
	BOOL32         bAutoAdjustFont;//�Ƿ���ݴ����Զ����������С ��֤ˮӡ�Ų�һ��
	u32 m_dwReserve1;//�����ֶ�1
	u32 m_dwReserve2;//�����ֶ�2
}McusdkWaterMark;

//�û���ˮӡ��������ƽ̨��ȡ���û�ˮӡ����
typedef struct tagMcusdkUserWaterMark
{	
	BOOL32              bEnable;										//�Ƿ�������ˮӡ
	EWarterMarkFontSizeLevel       uiFontSizeLevel;			//�����С�ȼ�
	unsigned int        uiARGB;				//������ɫ��͸����0xAARRGGBB	
	unsigned int        uiFontRotate;		//��ת�Ƕȡ�0~360��
	unsigned int        uiLayerMode;		//1��ƽ�̣����ơ��������ξ���ƽ�̣������������֡�����̫���������ضϡ�
	char szFontPath[MAX_URL_LEN + 1];	//�ֿ��ļ�����·��
}McusdkUserWaterMark;


typedef struct   tagSetupDownloadRecordRsp
{
	int nPort;
	char serverIp[MAX_URL_LEN + 1];
	char recordFilePath[MAX_URL_LEN+1];
	char recordFileName[MAX_NAME_LEN+1];
}SetupDownloadRecordRsp;


//��ȫģʽ��������
typedef struct tagMcusdkSafeModeInfo
{
	char pemFile[260];//utf8��ʾ���ļ��� .pem �ļ�	
	char keyFile[260];//utf8��ʾ���ļ�����.crt �ļ�
	char keyPwd[MAX_PWD];//keyFile���ļ���ȡ��������
}McusdkSafeModeInfo;

#pragma pack()
#endif
