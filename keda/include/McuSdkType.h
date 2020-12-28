//
//  McuSdkType.h
//  McuSdk
//
//  Created by dqw on 14-5-16.
//  Copyright (c) 2014茠脥 ___kedacom___. All rights reserved.
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
#define MAX_1_0_ALL_PLAY_NUM			64 //1.0平台最大实时浏览路数为64，超过，会导致平台vtdu不返会消息

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
#define MAXNUM_SRCPU_POLL    64  //轮询最大编码器数量


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

#define STREAM_URL_SELECT_INDEX_INVAILED 65535	//非法的url 序列号

#define MAX_PWD 32
#define MAX_SCH_LEN 32
#define MAX_DECODE_CHN_NUM 64

#define MAXLEN_FILEPATH 128
#define MAXLEN_FILENAME 128
#define MAXLEN_ALIAS 64
#define MAXLEN_DEVICE_MANUFACTURER 32

#define MAX_Process_NUM 128

#define MAX_GROUP_DEEPTH 10	// 最大的设备组深度.

#define MAX_MULTIVIEW_DEVICE_TREE_NUM 128	//最大多视图设备树的数量(平台目前最大值是5)

#define MAX_OSD_LINE_NUM 5  //osd字母最大行数

#define MAX_GENERAL_ARRAY_NUM  64 // 一般的数组的大小
#define MAX_TIME_LIST_NUM 128
#define MAX_PARTITION_NUM 16
// 描述参数的输入和输出属性 +by lzx@2015-11-12.
#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef INOUT
#define INOUT
#endif

/*媒体类型定义*/

#define   MEDIA_TYPE_NULL                   (u8)255  /*媒体类型为空*/
    
/*音频*/
#define   MEDIA_TYPE_OPUS                 (u8)117  //OPUS传输值
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

/*视频*/
#define   MEDIA_TYPE_PS                      (u8)96  /*ps流*/
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
    RTN_OK 														=0,		//调用SDK结构成功										

	//add by xql 20140916 for startplay error
	MCU_PLAYER_ERR_MVC_CONNECT_MVS_FAILED						=10120,//MVC连接MVS时TCP链路建链失败
	MCU_PLAYER_ERR_MEDIANET_CREATE_FAILED                       =16004,//创建medianet接收失败，16004错误，可能是端口被占用或者帧回调被阻塞        

	MODUAL_INVALID 												=60001, // 无效模块
    TASK_INVALID 												=60002, // 无效任务
    TASK_CREATE_ERROR 											=60003, // 创建任务失败
    INPUT_ERROR 												=60004, // 输入错误
    GET_DATA_ERROR 												=60005, // 获取数据错误
    NET_ERROR													=60006, // 网络错误
    SNAPSHOT_ERROR 												=60007, //
    DGROUP_ROOT_INFO_ERROR 										=60008,//登陆时获取根平台的信息错误
	NOT_IMPLEMENT												=60009,//接口未实现或不支持
	MCU_ERRCODE_LOGIN_ERR_FIRST_DOMAIN_ERR						=60010,//登陆解析第一级域名失败
	MCU_ERRCODE_LOGIN_ERR_SECOND_DOMAIN_ERR 					=60011,//登陆解析第二级域名失败
	MCU_ERRCODE_LOGIN_ERR_PLAT_DOMAIN_ERR						=60012,//登陆解析平台的域名失败
	NTP_NETWORK_ERROR											=60013,//网络错误
	GET_DEVICES_INFO_TIME_OUT									=60014,//获取设备信息超时
	DEVICE_NOT_ONLINE											=60015,//设备不在线
	DEVICE_TO_GBDEVICE_FAILED									=60016,//设备id转国标id失败
	DEVICE_STREAM_URL_EMPTY										=60017,//mss返回的码流url为空
	PLAY_ID_NOT_EXIST										    =60018,//播放ID不存在
	MCUSDK_ERROR_MODULE_NOT_INIT                                =60019,//模块未初始化
	UNSUPPORT_VIDEO_TYPE                                        =60020,//本地录像视频类型不支持

	LOCAL_RECORD_FILE_TOO_SHORT = 60038,//本地录像文件太小，在停止本地录像的时候可能会返回这个错误码

	//TCP视频播放错误码(SDK 预留100个错误码61000 - 61099)
    MCU_PLAYER_ERR_STREAM_GET_IDLE_STREAM 						=61000,//传输模块分配空闲失败
	MCU_PLAYER_ERR_DECODER_GET_IDLE_DECODER						=61001,//解码模块分配空闲失败
	MCU_PLAYER_ERR_DECODER_CREATE								=61002,//解码器创建失败
    MCU_PLAYER_ERR_DECODER_START_PLAY_STREAM					=61003,//启动解码模块失败
    MCU_PLAYER_ERR_DECODER_START_PLAY_WND						=61004,//显示模块初始化失败
	MCU_PLAYER_ERR_CONVERT_GB_DEVICED_ID						=61005,//devicedID转国标ID失败
	MCU_PLAYER_ERR_G900_INIT_FAIL								=61006,//G900模块初始化失败
	MCU_PLAYER_ERR_FROM_G900_GET_URL							=61007,//从G900获取URL失败
	MCU_PLAYER_ERR_G900_START_REQ_FAIL							=61008,//g900模块发送浏览请求失败
	MCU_PLAYER_ERR_DEVICES_OFFLINE								=61009,//设备不在线
	MCU_PLAYER_ERR_G900_URL_NOT_SUPPORT_ALL						=61010,//g900返回的url分辨率不支持
	MUC_PLAYER_ERR_NO_KEY_FRAME_COME							=61011,//码流关键桢没有过来
	
	MCU_PLAYER_ERR_CONNECT_MVC_FAIL 							=61020,//mvc连接mvs失败
	MCU_PLAYER_ERR_CONNECT_MVC_TIMEOUT							=61021,//mvc连接mvs超时
	MCU_PLAYER_ERR_DISCONNECT_MVC_NTF							=61022,//收到mvs断链通知
	
    MCU_PLAYER_ERR_G900_ERR_FAIL 								=61091,//G900错误
    MCU_PLAYER_ERR_G900_ERR_UNINIT 								=61092,//G900未初始化
    MCU_PLAYER_ERR_G900_ERR_UNCONNECT 							=61093,//未连接G900
    MCU_PLAYER_ERR_G900_ERR_PARAM 								=61094,//G900 参数错误
    MCU_PLAYER_ERR_G900_ERR_INVALID_PLAYEID						=61095,//G900 playid无效	
    MCU_PLAYER_ERR_G900_TIMEOUT									=61096,//G900 请求超时

	//UDP视频播放错误码(SDK 预留100个错误码61100 - 61199)
	MCU_PLAYER_ERR_UDP_DVC_NOT_ONLIE							=61100, //udp请求码流方式设备不在线
	MCU_PLAYER_ERR_UDP_CHN_NOT_ONLIE							=61101,	//UDP请求码流方式时视频源对应的通道全不在线
	MCU_PLAYER_ERR_UDP_GET_CHNINFO_ERR							=61102, //udp请求码流方式从sdk内获取通道信息错误
	MCU_PLAYER_ERR_UDP_SETUP_STREAM_ERR_CONNECT_PLAT			=61103,	//udp请求码流请求rtp和rtcp端口连接平台错误
	MCU_PLAYER_ERR_UDP_SETUP_STREAM_ERR_RSP_ERR					=61104,	//udp请求码流请求rtp和rtcp端口平台返回结果错误
	MCU_PLAYER_ERR_UDP_SETUP_STREAM_ERR_KEY_FRAME_CONNECT_PLAT	=61105,	//udp请求码流向平台请求关键帧连接平台错误
	MCU_PLAYER_ERR_UDP_SETUP_STREAM_ERR_KEY_FRAME_RSP_ERR		=61106,	//udp请求码流向平台请求关键帧平台返回结果错误
	MCU_PLAYER_ERR_UDP_Get_IDLE_DECODER							=61107, //UDP请求码流请求分配空闲的传输模块失败
	MCU_PLAYER_ERR_UDP_INIT_KDV_MEDIA_RCV_ERR					=61108,	//UDP请求码流初始化medianet接收模块失败
	MCU_PLAYER_ERR_UDP_START_KDV_MEDIA_RCV_ERR					=61109,	//UDP请求码流medianet开始接收码流失败
	MCU_PLAYER_ERR_UDP_START_KDV_VIDEO_PROBE_ERR				=61110,	//UDP请求码流Video穿NAT失败
	MCU_PLAYER_ERR_UDP_START_KDV_AUDIO_PROBE_ERR				=61111, //UDP请求码流Audio穿NAT失败

	//录像播放和下载相关错误码(SDK 预留100 个错误码61200-61299)
	MCU_RECORD_QUERY_RECORD_THREAD_NOT_NULL						=61200,//查询录像文件线程已存在
	MCU_ERRCODE_QUERY_RECORD_TASKID_NOT_EXITS 					=61201,//查询平台录像的taskID不存在
	MCU_ERRCODE_QUERY_RECORD_MANAGER_NULL						=61202,//查询平台录像时数据管理模块为NULL
	MCU_ERRCODE_QUERY_RECORD_MANAGER_GET_DATA_NULL 				=61203,//查询平台录像时数据管理模块获取数据为NULL
	MCU_ERRCODE_QUERY_RECORD_QUERY_REQ_FAILED 					=61204,//查询平台录像出现错误
	MCU_ERRCODE_QUERY_RECORD_QUERY_RSP_FAILED 					=61205,//查询平台录像返回结果出现错误
    MCU_ERRCODE_QUERY_RECORD_QUERY_NUM_ZERO 					=61206,//从平台20获取的录像文件个数为0
    MCU_ERRCODE_RECORD_SEEK_TIME_OUT_RANG 						=61207,//vcr操作时seektime时间跨文件
    MCU_ERRCODE_RECORD_STOP_PLAY_NTF							=61208,//录像回放停止通知
    MCU_ERRCODE_RECORD_TYPE_WRONG								=61209,//录像类型参数错误
    MCU_ERRCODE_RECORD_GET_DEV_CHN_WRONG 						=61210,//录像回放时查询设备信息错误
    MCU_ERRCODE_RECORD_GET_TIME_RANGE 							=61211,//录像回放时获取录像开始结束时间错误
    MCU_ERRCODE_VCR_RECORD_TYPE_ERR								=61212,//录像回放vcr操作时录像类型不对
    MCU_ERRCODE_VCR_GET_PU_RECORD_MANAGER_ERR					=61213,//获取前端录像管理类实例错误
    MCU_ERRCODE_VCR_GET_CENTER_RECORD_MANAGER_ERR				=61214,//获取平台录像管理实例错误
    MCU_ERRCODE_QUERY_RECORD_NO_PERMISSION 			        	=61215,//用户没有查询和播放录像的权限
	MCU_ERRCODE_QUERY_RECORDLIST_UNSUPPORT                      =61216,//前端设备不支持查询录像日历

    MCU_RECORD_DOWNLOAD_ERR_CREATE_KEDAPLAYER_ERR 				=61250,//录像下载创建kedaplayer错误
    MCU_RECORD_DOWNLOAD_ERR_PLATFORM_CONNECT_FAIL 				=61251,//录像下载连接平台出错
    MCU_RECORD_DOWNLOAD_ERR_PLATFORM_DIRCRIPTION_NULL 			=61252,//录像下载描述文件为空
	MCU_RECORD_DOWNLOAD_ERR_LOCAL_DISK_FULL						=61253,//本地磁盘空空间已满
	MCU_RECORD_DOWNLOAD_ERR_LOCAL_FULL_NAME_NULL 				=61254,//本地保存文件名为空
	MCU_RECORD_DOWNLOAD_ERR_DOWNLOAD_ERR						=61255,//录像下载网络错误
	MCU_RECORD_DOWNLOAD_ERR_LAST_RECORD_FILE_STOP_FAIL          =61256,//录像下载上一段文件停止失败
	MCU_RECORD_DOWNLOAD_ERR_NEXT_RECORD_FILE_START_FAIL         =61257,//录像下载下一段文件开始失败
	MCU_RECORD_DOWNLOAD_ERR_RECORD_TYPE_CONFLICT                =61258,//录像下载的录像类型与预加载查询时不一致

	MCU_RECORD_DOWNLOAD_ERR_RPCTRL_FAILED                       = 61259,//RPCTRL下载时的通用错误码
	MCU_ERRCODE_WATERMARK_RECORD_FAILED                         = 61260,//水印录像失败   

	//电视墙的相关错误码(含预案和轮巡，SDK 预留100个错误码61300 - 61399)
	MCU_TVWALL_ERR_CONNECT_PLAT_ERR								=61300,//电视墙连接平台错误
	MCU_TVWALL_ERR_GET_TV_WALL_MANAGER_ERR						=61301,//电视墙和电视墙预案获取电视墙管理类实例错误
	MCU_TVWALL_ERR_GET_TV_WALL_SINGAL_ERR						=61302,//获取单个电视墙信息错误
	MCU_TVWALL_ERR_GET_TVWALL_DECODER_BIND_SIZE_ERR				=61303,//获取电视墙的解码器绑定的个数出错
	MCU_TVWALL_ERR_DECODER_SIZE_LESS_THAN_ID					=61304,//ID大于解码器的绑定个数
	MCU_TVWALL_ERR_GET_DECODER_STYLE_ERR						=61305,//获取解码器解码风格出错
	MCU_TVWALL_ERR_VIDEO_MANAGER_INSTANCE_NULL					=61306,//录像回放上墙的录像管理类的实例为空
	MCU_TVWALL_ERR_GET_PLAT_VIDEO_INFO_ERR						=61307,//获取平台录像的信息失败
	MCU_TVWALL_ERR_GET_PU_VIDEO_INFO_ERR						=61308,//获取前端录像的信息失败
	MCU_TVWALL_ERR_DECODER_BIND_NOT_FIND_ERR					=61309,//录像回放上墙解码器的绑定失败
	MCU_TVWALL_ERR_TO_TVWALL_RECORDTYPE_ERR						=61310,//录像回放录像类型错误
	MCU_TAWALL_SCHEME_ERR_GET_SINGAL_SCHEME_ERR					=61311,//电视墙预案中获取单个预案信息失败

    //搜索设备错误码(SDK预留100 个错误码 61400 - 61499)
	MCU_SERACH_DVC_THREAD_EXITS 								=61400,//搜索设备线程已存在
	MCU_SERACH_DVC_NO_DEVICES 									=61401,//搜索无设备

	//音频呼叫相关错误码(SDK 预留100  个错误码 61500 - 61599)
    MCU_CALL_PU_GET_LOCAL_IP_ERR								=61500,//音频呼叫时获取客户端本地ip错误
    MCU_CALL_PU_GET_PLAT_RSP_ERR								=61502,//音频呼叫时连接平台获取rsp错误
    MCU_CALL_PU_RECV_IP_SIZE_ZERO								=61503,//音频呼叫时平台返回的size大小出错
    MCU_CALL_PU_GET_PLAT_IP_PORT_ERR							=61504,//音频呼叫时连接平台获取端口错误
	MCU_CALL_PU_DEVICE_AUDDEC_CHN_IS_ZERO						=61505,//设备不支持音频呼叫
	MCU_CALL_PU_CREATE_AUDIO_CAPTURE_FAILED                     =61506,//创建音频采集失败，请确认麦克风插入

	//URL播放错误码(SDK预留100 个错误码 61600 - 61699)
	MCU_URL_PLAY_PLUGIN_NOT_EXIST								=61600,//url播放插件或接口不存在	
	MCU_URL_PLAY_URL_INVALID									=61601,//url播放的url参数非法
	MCU_URL_PLAY_CREATE_PLAY_HANDLE_FAILED						=61602,//url播放创建播放句柄失败
	MCU_URL_PLAY_FAILED											=61603,//url播放失败
	MCU_URL_PLAY_GENERATE_PLAY_ID_FAILED						=61604,//url播放生成播放ID
	MCU_URL_PLAY_ID_NOT_EXIST									=61605,//url播放ID不存在
	MCU_URL_PLAY_TYPE_INVALID									=61606,//url播放的类型非法
	MCU_URL_PLAY_HANDLE_INVALID									=61607,//url播放的句柄非法
	MCU_URL_PLAY_CONTROL_FAILED									=61608,//url控制失败
	MCU_URL_PLAY_UNIPLAY_PLUGIN_NOT_EXIST                       =61609,//uniplay解码插件不存在
	MCU_URL_PLAY_START_LOCAL_RECORD_FAILED                      =61610,//开启本地录像失败
	MCU_URL_PLAY_STOP_LOCAL_RECORD_FAILED                       =61611,//停止本地录像失败
	
	//SOAP相关错误码(SDK预留100个错误码 64000-64099)
	
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

	// 获取civilcode
	MCU_SDK_GB_ERR_PARAM_NULL									=65010,	// 参数为0.

	MCU_SDK_LOG_ERR_VERSION_CLASH                               =65011,//在日志V2接口前使用了老的日志接口，注意上层不可混用日志接口
	MCU_SDK_LOG_ERR_START                                       =65012,//启动日志失败
	MCU_SDK_LOG_ERR_FILEOPEN                                    =65013,//打开日志失败
	
	//other
	OCX_INIT_ERR 												=66000,//初始化错误
	OCX_WAIT_REC_OVERTIME										=66001,//录像查询等待结束标志超时
	OCX_UNINIT_ERR												=66002,//反初始化错误
};

enum EDecoderMod
{
	emDecoderModUnable = 0,   //不使用SDK内部解码器
	emBaseDec = 1,            //使用SDK内部解码显示
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
	emLevNull = 0,       //无任何打印   
	emLevError = 1,      //错误级别
	emLevWarn = 2,       //警告级别
	emLevCritical = 4,   //关键级别
	emLevInfo = 8,       //普通级别
	emLevDebug = 16,     //调试级别
	emLevAll = 255,      //所有级别
};

enum EWatchTYPE
{
	emWatchInVailed = 0,
	emWatchTask = 1,
	emWatchPrePos =2,
};

//获取设备或设备组额外信息的信息类型
enum EDevGroupExtraInfoType
{
	emExGrpNull = 0,
	emExGrpDescrition = 1,		//组的描述信息								字符串
	emExGrpHasDevice = 2,	//组下是否有设备（包括递归的下级设备组）	bool
};
enum EDeviceExtraInfoType
{
	emExDevNull=0,
	emExDevIsGB = 1,		//设备是否为国标设备的标记		bool
	emExDevModel = 2,	//pmc入网时填的设备型号					字符串
	emExDevName = 3,	//获取设备别名										字符串
	emExDevDomainID = 4,//设备所在域ID									字符串
	emExDevManufactor = 5,//设备厂商										字符串
	emExDevOnline = 6,	//设备是否在线										bool
	emExDevVideoSrcNum = 7,	//视频源总数							数值
	emExDevType=8,			 // 设备类型 DeviceInfo::eDeviceType			数值
	emExDevCap=9,			 //设备能力 DeviceInfo::eDeviceCap				数值	
	emExDevVSInGroup=10,	//设备在指定组下的视频源列表		字符串	将会以"1,3,5" 这样的形式提供，每一位数值表示视频源ID。
	emExDevGroup=11,		//设备所在组（这个只针对平台1.0，2.0平台只有视频源才有父组的概念）

    emExDevPriPURecStart=12, // 前端录像开启权限     bool true 有该权限  false 没有该权限
    emExDevPriPURecPlay=13, //前端录像回放权限
    emExDevPriPURecDownload=14, //前端录像下载权限
    emExDevPriPUConfig=15, //前端参数配置权限
    emExDevPriPUAlarmConfig=16, //  前端布防撤防权限
	emExDevIP=17,           //设备ip地址
	emExDevDecodeChnNum=18,	//设备的解码通道数， 数值型
	emExDevVideoOutputChnNum = 19,	//设备的视频输出通道数， 数值型
	emExDevKdmNo=20,        //设备的kdmNo
};
enum EVideoSrcExtraInfoType
{
	emExVsNull=0,
	emExVsPtzPrivilage = 1,		//获取指定视频源的PTZ权限值，0表示没有权限，值越大表示权限越高					int
	emExVsName = 2,						//视频源别名					字符串
	emExVsValid = 3,						//视频源是否启用			bool
	emExVsOnline = 4,						//视频源是否在线			bool
	emExVsChns = 5,						//视频源包含的通道号	字符串				将会以"1,3,5" 这样的形式提供。第1个通道表示主流通道，其他表示辅流通道（如果有）
	emExVsValidAndOnline = 6,		//同时获取emExVsValid和emExVsOnline		bool[2] 参数应该以 int rslt[2] 指针传递返回值rslt[0]为emExVsValid,rslt[1]为emExVsOnline
    emExVsPtzCtrlLevel = 7,  // 云镜控制级别   int  返回控制级别
    emExVsPriPuAudioCtrl = 8,  // 前端声音开启权限  bool true 有该权限， false 没有该权限
    emExVsPriPuSavePreset = 9, // 预置位配置权限
    emExVsPriPuPtzLock = 10, //云台锁定权限
	emExVsGroupRelation = 11, //视频源所划归的分组信息，字符串
};

enum ECurrUserInfoType
{
    em_PriUserInvalid,		// 用户权限枚举的起始. 权限是int值  返回1代表有权限，0代表没有权限
    em_PriUserBegin,
    em_PriUserCMSRecStart = em_PriUserBegin,	// 平台录像.
    em_PriUserCMSRecPlay,				                   // 平台录像播放.
    em_PriUserCMSRecDel,				                   // 平台录像删除.
    em_PriUserCMSRecDownload,			              // 平台录像下载.
    em_PriUserLocalRec,				                         // 本地录像.

    em_PriUserCMSRecPlayOtherDomain,	         // 跨域录像播放.
    em_PriUserPUCall,					                    // 前端呼叫.
    em_PriUserAlarmLog,				                    // 告警日志管理

	em_UserPwdExpireEnable,		//是否启用了用户密码有效期 bool
	em_UserPwdValidTime,			//用户密码有效期单位天
	em_UserPwdExpireTimeLeft,			//用户密码有效期还剩余时间单位秒
	em_UserLockTimeLeft,				//因为密码错误用户被锁定还剩余的时间单位秒
	em_UserWaterMarkEnable,		//是否启用了水印

    // 其他类型
    em_UserId = 100,  // string  获取用户的uuid    字符串类型    
    em_UserIdNoDomainName,  // string  获取用户的uuid    字符串类型
};


//Kdm_SetDecodeMode 设置当前解码模式
enum EDecodeMode
{
	emSoftDecode=0,	//软解
	emHardDecode=1,	//硬解（硬解如果失败会自动切换成软解）
};

//磁盘状态
enum ERSDiskState
{
	emDiskStateInvalid = 0,
	emDiskStateOnline = 1,
	emDiskStateOffline = 2,
	emDiskStateUnknow= 3
};
//分区状态
enum ERSPartState
{
	emPartStateInvalid = 0,
	emPartStateOffline = 1,
	emPartStateUnformatted = 2,
	emPartStateFormatted = 3,
};

//水印字体大小等级
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
// 作为自定义参数的类型定义
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
	emStreamFile=0,						//播放的源是文件
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
    emTvWallState =0x100, // 电视墙状态需要单独订阅
	emRecStatus = 0x200,
	emDeviceServiceStatus = emRecStatus,
	emRecvTransData = 0x400,
	emRecvTransDataGB = 0x800, // 国标透明数据状态需要单独订阅
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

//录像模式
enum ERecMode
{	
	emNormal=1,			// 正常普通录像.
	emVideoOnly,		// 只录视频.
	emKeyFrameOnly,	// 只录关键帧.
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
    u8 byEncType; // 现在只支持 MEDIA_TYPE_AACLC, MEDIA_TYPE_ADPCM, 
                       //  MEDIA_TYPE_PCMA, MEDIA_TYPE_PCMU, MEDIA_TYPE_OPUS
    u8  byChn;  // adpcm pcma pcmu 只支持单通道 其他格式支持单双通道 1 mono 2 stereo  单双声道
    u32  dwSampleRate;  // pcma, pcmu, adpcm, 只支持 8000 ; 
                                     //aaclc 支持 16000, 32000, 48000  ; opus 支持 8, 12, 16, 24,48 K
    u8 byBitsPerSample;  // 暂时只支持16bits
} McusdkAudioEncodParam;

//磁盘满覆盖策略
enum emCoverPolicy
{
	emSDK_RS_COVERPOLICY_INVALID = 0,
	emSDK_RS_COVERPOLICY_STOPRECORD = 1,          /*通道空间满停录像*/
	emSDK_RS_COVERPOLICY_COVERALL= 2,            /*通道空间满覆盖所有录像*/
	emSDK_RS_COVERPOLICY_COVERNORMAL = 3,         /*通道空间满覆盖普通录像*/
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

//查询设备码流url的类型
enum emUrlType
{
	URL_TYPE_OSP=0,	//返回格式类似osp://blabla的tcp码流播放地址，这是kedacom私有协议的播放url
	URL_TYPE_RTSP,	//返回rtsp地址
	URL_TYPE_RTMP,	//返回rtmp地址
	URL_TYPE_HTML5,	//返回html5地址
	URL_TYPE_CHANNEL,//返回Mcusdk内部支持的主辅流UDP码流url
	URL_TYPE_TCP,	//返回Mcusdk内部支持的mediaswitch tcp码流url tcp://blablabla
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

typedef struct DeviceInfo //nDevCap增加emCapNull类型，当nDevCap为emCapNull时，再通过nDevType获取设备类型。NVR,SVR下视频源的nDevCap不再赋初值为emDome。
{
    enum eDeviceCap // device capability
    {		
        emBullet=0, //枪机ipc
		emDome,     //球机ipc
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

//设备/设备通道对应到国标ID的一个映射项
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
	emDevTransDataNtf = 5, // 收到透明数据回显通知后，应该通过Kdm_GetTransData接口获取透明数据，不需要设备ID
	emTvWallNewNtf=10,
	emTvWallDelNtf = 11,
	emTvWallModNtf = 12,
    emTvWallStaChgNtf = 13,
	emDeviceAddNtf = 14,				//设备入网通知，
	emDeviceDelNtf = 15,				//设备退网通知，
	emDeviceModNtf = 16,				//设备修改通知，
	emGroupAddDev = 17,				//设备组下添加设备（注意对于2.0平台，因此实际为分组下增加视频源通知）
	emGroupDelDev = 18,				//设备组下删除设备（仅平台1.0时才可用，2.0平台，只有组下添加视频源的概念）
    emDevChnNameChange = 19,  // 设备视频源别名修改
	emDevTransDataNtfGB = 20, // 国标设备透明数据回显通知，收到后通过Kdm_GetTransDataForGB接口获取透明数据
	emDevAudioCallStatus = 21,
};
    
enum eAlarmType
{
    emAlarmTypeInvalid = 0, //无效的告警类型.
    emAlarmMove = 1,        //移动侦测
    emAlarmInput = 2,       //告警输入
    emAlarmDiskfull = 3,    //磁盘满
    emAlarmVideoLost = 4,   //视频源丢失
    //以下开始，如果告警拥有附加数据，需要将告警结构体转为 DeviceStatusAlarmEx ，需要上层自己转换一下。
    emAlarmIntelligent = 5,	//智能告警
    emAlarmVideo = 6,       //视质轮巡告警
	//以下是新的告警.
	emAlarmExceptionEvent = 7,		//异常事件消息
	emAlarmDefocus = 8,				//虚焦检测
	emAlarmSceneChange = 9,			//场景变换
	emAlarmRegionInvasion = 10,		//区域入侵
	emAlarmRegionLeaving = 11,			//区域离开
	emAlarmObjectTaken = 12,			//物品拿取
	emAlarmObjectLeft = 13,			//物品遗留
	emAlarmPeopleGather = 14,			//人员聚集
	emAlarmCorgon = 15,				//警戒线
	emAlarmAudioAbnormal = 16,			//声音异常
	emAlarmLumaChange = 17,			//亮度变化
	//R4B1支持国标2016报警类型补充的
	emAlarmAntiDismantle = 18,			//设备防拆报警
	emAlarmHighTemperature = 19,		//设备高温报警
	emAlarmLowTemperature = 20,		//设备低温报警
	emAlarmPersonVideo = 21,           //人工视频
	emAlarmSportGoalCheck = 22,        //运动目标检测
	emAlarmTripwireCheck = 23,         //绊线监测
	emAlarmHoverCheck = 24,             //  徘徊检测报警
	emAlarmTrafficStatisticsCheck = 25, //  流量统计报警
	emAlarmDensityCheck = 26,           //密度检测
	emAlarmVideoException = 27,         //视频异常
	emAlarmMoveFast = 28,               //快速移动
	emAlarmDiskFault = 29,              //存储设备磁盘故障报警
	emAlarmFanFault = 30,              // 存储设备风扇故障报警
	emAlarmGPSOverSpeed = 31,           //gps 超速
	emAlarmSIMDataTrafficExceeded = 32,        //sim 数据流量超标
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

//当 DeviceStatus 的 告警类型 m_dwAlarmType 为 emAlarmIntelligent 时的通知结构体
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
	int m_extDataSize;	//告警额外数据长度
	unsigned char m_extAlarmData[64];	//告警额外数据
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
//PTZ命令不是所有前端设备都会支持，需要视具体设备才能确认是否支持
enum ePtzCmd
{
    emMoveLeft = 0,						//向左
	emMoveRight = 1,						//向右
    emMoveUp = 2,							//向上
    emMoveDown = 3,					//向下
	emMoveLeftUp = 4,					//左上
	emMoveLeftDown = 5,				//左下
	emMoveRightUp = 6,				//右上
	emMoveRightDown = 7,			//右下
    emMoveStop = 8,						//停止移动
    emZoomIn = 9,							//视野拉近
    emZoomOut = 10,						//视野拉远
    emZoomStop = 11,					//视野缩放停止
    emHome = 12,							//归位
	emAutoScanStart = 128,  // 128	//开始自动巡航
	emAutoScanStop = 129,	   // 129	//停止自动巡航
	emZoonAreaWhole = 209,  // 209  //局部缩小  平台1.0
	emFocusFar,		        // 210	//将焦距调远
	emFocusNear,			// 211	//将焦距调近
	emFocusAuto,			// 212	//自动调焦
	emFocusStop,			// 213	//调焦停止
	emPresetSave,	    	// 214	//摄象头预存
	emPresetCall,			// 215	//调摄象头预存
	emCameraReset,	    // 216	// 初始化摄像头
	emBrightUp,			    // 217	//画面调亮
	emBrightDown,			// 218	//画面调暗
	emBrightStop,			// 219	//停止调亮
	emCommandNew,			// 220	//新命令
	emCommandAppend,		// 221	//附加命令
	emGotoPoint,			// 222	//中心定位
	emZoomArea,			    // 223	//局部放大
	emAlecPanSpeed,	        // 224	//艾立克水平移动速度设置命令
	emAlecTiltSpeed,	    // 225	//艾立克垂直移动速度设置命令
	emSonySetBright,	    // 226	//sony亮度调节启动命令
	emMatrixSwitch,		    // 227	//切换视频
	emMatrixVideoMix4,		// 228	//画面合成2×2
	emMatrixVideoMix9,		// 229	//画面合成3×3
	emMatrixVideoMix16,	    // 230	//画面合成4×4
	emMatrixVideoMixPP,	    // 231	//画面合成画中画
	emZoomAreaStop,		    // 232  //取消局部放大  平台2.0
	////菜单//////////////////////////////////////////////////////////////////////	
	emMenuUp,				// 233	//菜单上
	emMenuDown,			// 234	//菜单下
	emMenuLeft,			    // 235	//菜单左
	emMenuRight,			// 236	//菜单右
	emMenuShow,			// 237	//菜单显示
	emMenuHide,			// 238	//菜单隐藏
	emMenuEnter,			// 239	//菜单确定
	emMenuCancel,		// 240	//菜单取消
	emPresetDel,			// 241	//删除摄象头预存
	////矩阵切换//////////////////////////////////////////////////////////////////////
	emMatrixSwitchASC,	    // 242	//正向切换
	emMatrixSwitchESC,	    // 243	//反向切换
	emMatrixHoldImage=244,	 // 244	//图像保持	
	emStartWiper = 360,			//360	//开始雨刷，m_wPtzRange 参数为雨刷速度，值为0-15，其他参数置零
	emStopWiper,					//361	//停止雨刷
	emLightOn,						//362   //开启灯光
	emLightOff,						 //363   //关闭灯光
	emStartExt1,					 //364   //扩展功能一（可能是开启喷水）
	emStopExt1,					//365   //关闭喷水扩展功能一
	emStartExt2,					 //366   //扩展功能二（可能是开启除霜）
	emStopExt2,					//367   //关闭除霜扩展功能二	
	emLock = 368,				//368	//云解锁权限
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
	emWMModeRender = 0x00000001,  //播放时加水印
	emWMModeSnap = 0x00000002,		//抓拍时加水印
	emWMModeRecord = 0x00000004,  //本地录像时加水印
	emWMModeDownload = 0x00000008,  //下载水印（实例全局）
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
	s8  m_szServerIp[MAX_URL_LEN+1]; /*内部使用，外部无需赋值*/
	u16 m_wServerPort;				 //仅在直接使用TCP的url播放方式时，默认是6700，如果是非6700端口，需传入登陆mvs的端口；
    u16 m_wScreenWidth;				 /*内部使用，外部无需赋值*/
    u16 m_wScreenHeight;			 /*内部使用，外部无需赋值*/
    void* m_pDrawWnd; //窗口句柄
    s8    m_szManufactor[MAX_NAME_LEN+1]; //设备厂商名
    BOOL32 m_wHighDefinition;//实时浏览清晰流畅
	ePlayVideoType	m_emVideoType;//浏览类型
    u32	m_startTime;                /*内部使用，外部无需赋值*/
    u32	m_endTime;                  /*内部使用，外部无需赋值*/
    u32 m_playTime;                 /*内部使用，外部无需赋值*/
	eRecordType	m_byRecordType;//录像回放类型
    u32 m_dwDownloadStartTime;      /*内部使用，外部无需赋值*/
    u32 m_dwDownloadEndTime;        /*内部使用，外部无需赋值*/
    u32 m_dwDownloadFirstPlayTime;  /*内部使用，外部无需赋值*/
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
		m_bPuDirectTrans = FALSE; //设置PU直传，需看PU直传能力;仅UDP方式有效
		m_bVtduDirectTrans = FALSE;//设置设备所在域VTDU直传，需确认级联平台网络环境再使用，正常情况请勿设置;仅UDP方式有效
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
	BOOL32 m_bUrlplayRecordDownload;//是否是urlplaysdk录像下载的标记
	int m_downloadSpeed;//下载速度也要保存
	//从 RecordplayParam 里带出来的两个参数
	BOOL32 m_bPuDirectTrans; //设置PU直传，需看PU直传能力;仅UDP方式有效
	BOOL32 m_bVtduDirectTrans;//设置设备所在域VTDU直传，需确认级联平台网络环境再使用，正常情况请勿设置;仅UDP方式有效
	EStreamFlowPattern m_emTransMode;

} SPARAM_Inside;//增加SPARAM_Inside在内部使用，防止修改SPARAM影响到外部接口

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
	void* m_pDrawWnd; //窗口句柄
	s8    m_szManufactor[MAX_NAME_LEN+1]; //设备厂商
	BOOL32 m_wHighDefinition; //浏览清晰流畅
	BOOL32 m_bPuDirectTrans; //设置PU直传，需看PU直传能力;仅UDP方式有效
	BOOL32 m_bVtduDirectTrans;//设置设备所在域VTDU直传，需确认级联平台网络环境再使用，正常情况请勿设置;仅UDP方式有效
	u32 m_dwReserved1;		//保留字段
	u32 m_dwReserved2;		//保留字段
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
	void* m_pDrawWnd; //窗口句柄
	s8    m_szManufactor[MAX_NAME_LEN+1]; //设备厂商
	BOOL32 m_wHighDefinition; //暂无效
	eRecordType	m_byRecordType;//录像回放类型
	ePlayVideoType	m_emVideoType;//浏览类型
	BOOL32 m_bPuDirectTrans; //暂无效
	BOOL32 m_bVtduDirectTrans;//暂无效
	u32 m_dwReserved1;		//保留字段
	u32 m_dwReserved2;		//保留字段
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
	BOOL32 m_bPuDirectTrans; //设置PU直传，需看PU直传能力;仅UDP方式有效
	BOOL32 m_bVtduDirectTrans;//设置设备所在域VTDU直传，需确认级联平台网络环境再使用，正常情况请勿设置;仅UDP方式有效
	u32 m_dwReserved1;		//保留字段
	u32 m_dwReserved2;		//保留字段
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

//该tagFrameYUV结构体与uniplay里KDFrameInfo结构体完全相同！
typedef struct tagFrameYUV
{
	u8*					pbyRawBuf;
	unsigned int		dwRawlen;
	unsigned int		dwMediaType;			//数据类型(KD_FRAME_TYPE)
	unsigned int		dwSubMediaType;			//KD_DATA_TYPE(视频有效)
	unsigned int		dwFrameIndex;			//帧序号
	u64					dwNetTimeStamp;			//相对时间戳（RTP内部时间戳）
	u64					dwMediaTimeStamp;		//绝对时间戳（视频上面时间）
	unsigned int		dwMediaEncode;			//在kdvdef.h 内部定义或者FRAME_DATA_FORMAT里面定义
	union FRAME
	{
		struct VideoFrame
		{
			unsigned short		dwFrameRate;
			unsigned short		dwWidth;     //画面宽
			unsigned short		dwHeight;    //画面高
			unsigned short		strike[3];
		}tVideo;
		
		struct AudioFrame
		{
			unsigned short		wChannels;   //声道数
			unsigned short		wBitWidth;   //位宽
			unsigned short		dwSampleRate; //采样率
		}tAudio;
	}u;
	unsigned short		wBitRate;			//比特率，单位为1028字节
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
    u16  m_wFirstTimeSpan;      ///<第一个重传检测点
    u16  m_wSecondTimeSpan;     ///<第二个重传检测点
    u16  m_wThirdTimeSpan;      ///<第三个重传检测点
    u16  m_wRejectTimeSpan;     ///<过期丢弃的时间跨度
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
    s8     m_reserve[MAX_DESC_LEN+1];	  // Reserve，登陆mvs的端口，默认是6700，如果是非6700端口，使用url播放方式时，需将该端口传入播放接口
    eStreamUrlType	   m_UrlType;				 	  // Url的类型 0:不合法的方式;1:TCP方式,从MVS获取码流;2:UDP方式，从平台获取视频码流;3:图片流
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


/* 该回调函数的声明定义都直接复制和透传给uniplay
pAddDrawDC 是一个结构体
win下：
typedef struct
{
void *hdc;
void *hwnd;
void *rendertype;//渲染类型，D3D直接显示，D3D显示，DDRAW显示，DRAWDIB显示。
}DrawDC;
非win下 pAddDrawDC只是个指针
*/

//每帧画完后的回调
typedef void(*McusdkDraw_Callback)(u32 dwPlayID, void *pAddDrawDC, void * dwContext);
//录像合并进度回调接口
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
    KDM_PARAM   m_dStreamUserData;//内部用的，随便改
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
	emStartStream=5, // 码流请求播放信息回调 m_dwWorkID(dwPlayID)是mvc生成的，要转成我们sdk的那个播放ID上报给上层才行 m_dwErrorCode = 0; m_dwReserve1 = CS_MSG_START_PLAY_SUCCESS;
	emRecvKeyFrame=6, // 第一个关键帧到达的信息回调
	emStopStream=7,
	emPtz=8, 
	emSubscript=9,
	emLocalRec=10,
	emSnapshot=11, // 抓拍是否成功的信息回调
	emSearchRec=12, // 查询录像结果上报
	emStartPlayRec=13,	//录像播放进度通知
	emStopPlayRec=14,
	emVcrCtrl=15, // 收到时判断下tEvent.m_dwErrorCode = MCU_ERRCODE_RECORD_STOP_PLAY_NTF; 表示停止播放后的码流结束通知
	emHeartbeatError=16, // 与平台断链的通知，断链后将收不到所有设备状态，需要重新登录并订阅设备
	emSearchDvc=17, // 搜索结束的事件标志(Kdm_SearchDvcReq)
	emRecordDownLoad=18,
	emRecordDownLoadPace=19,
	emSyncTime = 20, // EventInfo的两个保留参数组成64位UTC时间，m_dwReserve1为低32位，m_dwReserve2为高32位，一般只用到低32位（Kdm_SetTimeSyncServer）
	emDecStyleChanged = 21,// EventInfo的m_dwReserve1为发生变化的解码器风格指针（culib电视墙上解码器风格切换通知,平台1.0相关）
	emChangePassWord = 22, // 更改密码失败时的错误事件通知（1.0平台）	
	emSearchResult=23,	//多视图设备树的搜索结果回调, m_dwReserve1表示成功或失败的bool类型,true表示搜索完成,false表示发生了错误, m_dwWorkID表示taskId
	emMVCPlayDisconnected=24,	//MVC的某一路播放断链了事件通知，m_dwWorkID 表示播放ID,errorcode=MCU_PLAYER_ERR_DEVICES_OFFLINE，其他参数保留	
	emDoubleAudioChannel=25,	//有双路音频的时候，会给出这个通知，m_dwWorkID 表示播放ID，m_dwReserve1表示第一路的音频ID,m_dwReserve2表示第二路的音频ID
	emReEncodeBufferFull=26,	//uniplay重编码缓存满（也就是编码能力不足）m_dwWorkID 表示播放ID，errorcode及其他参数保留0
	emStartPlayFailed=27,	//通用的播放失败的通知，m_dwWorkID 表示播放ID，errorcode及其他参数的含义暂时保留
	emWaterMarkRecordFailed=28,   //水印本地录像和水印录像下载过程中的失败，上层收到通知后需停止水印录像操作
	emSenderStreamFailed=29,	//码流发送失败 m_dwWorkID 表示播放ID，errorcode及其他参数的含义暂时保留
 
};

//平台能力类型（某些接口需要平台支持这个能力才能使用）
enum eCapType
{
	emCapTypeUnknow=0,
	emCapTypeMultiViewDeviceTreeSearch,	//是否支持多视图设备树的搜索（当然也适用系统默认树的搜索）
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

//语音回调的函数原型
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
    TPeriod m_tRecPeriod;// 录像总的时间段
    char 	m_dwRecID[MAX_DEV_DIR+1];// 录像标识(Token)
    char    m_recordDomainName[MAX_DEV_DIR+1];// 录像所在域名
    DEVCHN 	m_tDevChn;// 录像的编码器通道
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
	char* m_pFileFullName;//带完整路径的文件名与后缀
	ELocalRecType m_emFileType;
	eRecordType	m_byRecordType;
	u32 m_dwReserve1;//不为0时用作下载的倍速
    u32 m_dwReserve2;//单位毫秒，设置SDK内部下载无码流时超时结束的时间，不设置默认超时10000毫秒，设置为0时不开启SDK内部超时结束
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
	char m_pFileFullName[MAX_SM_STR_LEN+1];//带完整路径的文件名与后缀
	ELocalRecType m_emFileType;
	eRecordType	m_byRecordType;
	u32 m_dwReserve1;//不为0时用作下载的倍速
    u32 m_dwReserve2;//单位毫秒，设置SDK内部下载无码流时超时结束的时间，不设置默认超时10000毫秒，设置为0时不开启SDK内部超时结束
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


// 字幕状态
enum emOSDState
{
	OSDStateInvalid,	// 0 无效值
	OSDStateDisable,	// 1 禁用
	OSDStateText,		// 2 文本模式的字幕.
};

typedef struct tagVidOSD
{
	emOSDState state;//状态
	int left;//编码字幕左边距 1-200;
	int top;//编码字幕上边距 1-200;
	u32 color;//字幕颜色		
	char title[MAX_DISPLAY_CONTENT_LEN + 1]; //字幕内容，UTF8编码	
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
	CTRL_KEYSEEK = 7,/*定位到关键帧. */
	CTRL_AUTO_KEYFRAME = 8,/*自动模式，是否抽帧由NRU确定：低倍速全帧，高倍速只放关键帧*/

	CTRL_BACKWARD_PLAY = 9,/*录像切换成倒放*/
	CTRL_FORWARD_PLAY = 10,/*录像从倒放切换成正放，需要调用此VCR不能用 CTRL_PLAY*/
};

typedef struct tagRecordPlayCtrlInfo
{
	tagRecordPlayCtrlInfo()
	{	
		m_byCtrlType =(RecordPlayCtrlType)-1;
		m_dwRange = 0;
		m_dwPlayId = (unsigned int)(-1);
	}
	
	char m_byCtrlType; //取值范围：RecordPlayCtrlType
	int m_dwRange; //play和seek时为播放起始时间, scale时为倍数（负值为慢速、正值为快速）,其他未指明此参数含义的VCR控制，则忽略此值
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

	char m_byCtrlType; //取值范围：RecordPlayCtrlType
	int m_dwRange; //play和seek时为播放起始时间, scale时为倍数（负值为慢速、正值为快速）,其他未指明此参数含义的VCR控制，则忽略此值
	unsigned int m_dwPlayId; //dwplayID
	BOOL32 m_bQuickDecode; //是否在快放时启用快解，仅在uniplay未到达快解缓存阈值且使用软解方式快放时生效
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
	emTransChnCOMPort = 0, // 设备COM口透明数据
	emTransChnCameraTaskConfig = 1, // 摄像机任务配置数据
	emTransChnExtData = 2, // 透明数据，支持请求应答通知三态模型
	emTransChnUserDef = 3, // 透明数据，用户自定义透明数据类型,当前仅国标接入模块支持接收并处理
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
	u16 m_byAppType; // 透明通道消息类型
	TransChnType m_TransChnType; // 透明通道类型
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
	u8 *m_pTransBuffer; // 透明通道数据
	u16 m_wTransBufferLen; // 透明通道数据大小，最大值是8KB
	u16 m_byAppType; // 透明通道消息类型
	TransChnType m_TransChnType; // 透明通道类型
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
	u8 *m_pTransBuffer; // 透明通道应答数据，大小至少为8KB。内存由上层应用维护。
	u16 m_wTransBufferLen; // 透明通道应答数据大小
	u16 m_byAppType; // 透明通道消息类型
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
	u8 *m_pTransBuffer; // 透明通道数据
	u16 m_wTransBufferLen; // 透明通道数据大小，最大值是MAX_TRANSCHAN_DATA_LEN_V2
	u8 *m_pMsgTypeGB; // 透明通道实际携带的数据类型，具体值需与前端国标设备协商确定
	u16 m_wMsgTypeGBLen; // 透明通道实际携带的数据类型长度，最大为MAX_TRANSCHAN_MSGTYPEGB_LEN
	u16 m_byAppType; // 透明通道消息类型
	BOOL32 m_bEnd; // 是否是最后一条通知
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
	u8 *m_pTransBuffer; // 透明通道应答数据，内存由上层应用维护。
	u16 m_wTransBufferLen; // 透明通道应答数据大小，最大为MAX_TRANSCHAN_DATA_LEN_V2
	u8 *m_pMsgTypeGB; // 透明通道实际携带的数据类型，具体值需与前端国标设备协商确定
	u16 m_wMsgTypeGBLen; // 透明通道实际携带的数据类型长度，最大为MAX_TRANSCHAN_MSGTYPEGB_LEN
	u16 m_byAppType; // 透明通道消息类型
	char m_szUserName[MAX_NAME_LEN + 1];//锁定PTZ的用户名（锁定成功值为空）
	int m_nPtzLevel;//锁定PTZ的用户ptz控制等级（锁定成功为空）
	u32 m_dwBeginTime;//锁定开始时间
	u32 m_dwEndTime;//自动解锁时间
	BOOL32 m_bHasNotify;// 是否有emDevTransDataNtfGB通知
	int m_nErrorCode;
	char m_szErrorDesc[MAX_DESC_LEN + 1];// PTZ锁定原因造成的失败
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
	char 			m_TvWallID[MAX_DESC_LEN+1];	// 电视墙Id.
	int 			m_tvId;						// 电视机Id.
	int 			m_tvDivId;					// 电视机分画面Id.
}TTvWallCommonData;

typedef struct tagTvWallPlayData
{
	tagTvWallPlayData()
	{
		m_ChnID = 0;
	}
	TTvWallCommonData	m_TvWallComData;
	DeviceID 			m_devURI;				// 编码器/IPC 等视频源设备的唯一标识
	int 				m_ChnID;				// 编码器/IPC 等视频源通道 

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
	char 			m_TvWallID[MAX_DESC_LEN+1];	// 电视墙Id.
	int 			m_tvId;						// 电视机Id.
	int 			m_tvDivTotal;				// 电视机画面数emETVWallDivStyle
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
	int m_tvId;		         // 电视序号
	int m_tvDivNum;			 //电视机画面数
	DeviceID m_decoderId;	 // 解码器设备id.
	int m_decoderOutputId;	// 解码器的输出Id. 

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
	char 			m_TvWallID[MAX_DESC_LEN+1];				// 电视墙Id.
	DomainID 		m_domainId; 							// 电视墙所属域编号
	char 			m_name[MAX_DESC_LEN+1];    				// 电视墙名称
	int 			m_tvNum;								// 电视机数目
	int 			m_tvwallStyle;							// 电视墙风格, 不使用枚举，因为TAS不关心具体的内容，否则到时风格类型添加时TAS也要改了
	char 			m_tvwallCustomStyleData[MAX_DESC_LEN*10+1];// 电视墙自定义风格数据
	char 			m_desc[MAX_DESC_LEN+1];                 // 电视墙描述
	int 			m_createTime;		        			// 入网日期,time_t在vc6.0中占有4个字节，而在vs系列中占用8个字节，故改为int型
	char			m_tClientID[ADDR_STR_LEN+1];			//客户ID;
	int				m_tvDecoderBindArrayRealSize;
	TTVDecoderBind* m_tvDecoderBindArray; 					// 电视与解码器绑定关系
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

    u8  m_byEdcChnId;        //编解码的通道号;
    u8  m_byVidChnId;        //视频源号;
    unsigned int m_dwSessIDOrRpChn;   //会话ID或录放像通道
	char m_achNO[LEN_KDM_NO+1];
}TTPuChn;

typedef struct tagDevChannel
{
	tagDevChannel()
	{
		channelId = 0;
	}
    DeviceID deviceId;     //设备的唯一标识 pu uuid@domain
    int    channelId;      //通道有可能是编码通道，有可能是视频源，还有可能是放像通道, 要根据协议具体应用场景判断
}TDevChannel;

// 轮巡状态
enum emEPollStatus_NTF
{
    emSDK_PollStatusInvalid = 0,	// 无效值.
    emSDK_PollStarted = 1,	// 轮巡已经开始.
    emSDK_PollStoped = 2,	// 轮巡已经停止.
    emSDK_PollPaused = 3,	// 轮巡暂停.
};

// 电视墙的播放模式.
enum emETVWallPlayMode_NTF
{
    emSDK_TVWallPlayModeInvalid = 0,	// 无效值.
    emSDK_TVPlayModeLiveStream = 1,
    emSDK_TVPlayModePlatformRecord = 2,
    emSDK_TVPlayModePuRecord = 3,
};

// 电视墙的一个画面合成子窗口的状态.
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
    int divId;	// 画面合成子窗口(通道)Id.

    enum emETVWallPlayMode_NTF divPlayMode;	// 电视墙分画面的播放模式. ( 实时浏览, 平台录像, 前端录像 ).
    char recordPlaySession [MAX_DESC_LEN+1];	// 录像播放的Session.
    TRecordInfo recordPlayDuration;	// 当前播放的录像时间段.

    enum emEPollStatus_NTF pollState;	// 窗口轮巡的状态.	

    TDevChannel encoderChn;	// 当前浏览的编码器通道.
    int errorCode;		// 当前浏览请求出现的错误, 错误码.
}TTVWallTVDivStateNtf;


// 窗口轮巡的一步
typedef struct tagTvWallWindowPollStep
{
	tagTvWallWindowPollStep()
	{
		duration = 0;
	}
	TDevChannel		encoderChn;	// 编码器/IPC 等视频源通道.
	int 		duration;					// 该视频源的码流持续时间.
}TTvWallSchemeTvDivPollStep;

// 电视上的单个子窗口(画面合成)的预案.
typedef struct tagTTvWallSchemeTvDiv
{
	tagTTvWallSchemeTvDiv()
	{
		divId = -1;
		tvWallSchTvDivPollStepArrayRealSize = 0;
		tvWallSchTvDivPollStepArray = NULL;
	}
	int divId;	// 解码器通道id.
	TTvWallSchemeTvDivPollStep* tvWallSchTvDivPollStepArray;	// 轮巡的各个步骤. 如果只有一个轮巡, 则是普通浏览.
	int tvWallSchTvDivPollStepArrayRealSize;
}TTvWallSchemeTvDiv;

// 单个电视的预案.
typedef struct tagTvWallTVSchemeTv
{
	tagTvWallTVSchemeTv()
	{
		tvId = -1;
		divStyle = emSDK_TVDIV_Invalid;
		tvWallScheTvDivArray = NULL;
		tvWallScheTvDivArrRealSize = 0;
	}
	int tvId;					// 电视Id
	DeviceID 					m_decoderId;// 解码器设备id.
	enum emETVWallDivStyle divStyle;	// 窗口的画面合成分画面风格.	
	TTvWallSchemeTvDiv* tvWallScheTvDivArray;	// 电视的画面合成的小窗口.	
	int 			  tvWallScheTvDivArrRealSize;
}TTvWallSchemeTv;


// 电视墙的预案.
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
	u32  	schemeSN;						//预案编号(创建预案时无需填入)
	char	m_tClientID[ADDR_STR_LEN+1];	//客户ID;
	u8		byOwnerType;					//所属类型
	char 	schemeName[MAX_DESC_LEN+1];	// 预案名称.
	char 	tvWallId[MAX_DESC_LEN+1];	// 预案所属电视墙Id.
	
	TTvWallSchemeTv*  tvSchemeTvArray;	// 电视墙上所有电视的预案列表.	
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
// 2.0 只要只需要填写电视墙ID
// 1.0 只需要填写解码器通道
typedef struct tagSchemePollStepReq
{
	tagSchemePollStepReq()
	{
		memset(m_tvWallId,0,sizeof(m_tvWallId));
		m_dwTvWallProjId = 0;
		m_byTvId = 0;
		m_byDivisionId = 0;
	}

	char 		m_tvWallId[MAX_DESC_LEN+1];	// 预案所属电视墙Id.
    u32 		m_dwTvWallProjId; //电视墙预案编号;
    u8 			m_byTvId; //电视机号;
    u8 			m_byDivisionId;//画面号(从零开始)
    TTPuChn 	m_tPuChn; //解码器通道;
}TSchPollStepReq;


// 2.0 只需要填写预案名和预案保持时间
// 1.0 只需要填写源编码器及其保持时间
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
	char tvWallSchemeName[MAX_DESC_LEN + 1];	// 预案名数组
	int duration;					// 预案切换前的保持时间数组.

	// 1.0
	u8 m_byPollFlag; //轮询标志位;
	u16 m_wPollSrcIndex; //正在轮询的索引;
	u16 m_wPollSrcNum; //轮询源的编码器数目;
	u32 m_dwTime;  // 源编码器组保持时间
	TTPuChn m_atEncPu; //轮询的源编码器组;
	TTPuChn m_tLookPu;//当前正在选看的PU,设备号为空表示选看无效
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
	u16 tvWallSchNum; // 2.0 预案数目
	u16 m_wPollSrcNum; // 1.0 前端编码器数目
}TTvWallSchemePollStepTotal;
enum emETVWallSCHEPOLLSTEPCMD
{
	emSDK_TVWSSCMD_INVALID = 0,
	emSDK_TVWSSCMD_CONFIG = 1,		// 配置
	emSDK_TVWSSCMD_START = 2,       // 开始*/
	emSDK_TVWSSCMD_STOP = 3,        // 停止*/ 
	emSDK_TVWSSCMD_PAUSE = 4,       // 暂停*/
	emSDK_TVWSSCMD_RESUME = 5,      // 恢复*/
	emSDK_TVWSSCMD_SEEK = 6,        // 时间定位*/
	emSDK_TVWSSCMD_FASTPLAY = 7,    // 快放 参数？*/		
	emSDK_TVWSSCMD_SLOWPLAY = 8,    // 慢放 参数？ */
	emSDK_TVWSSCMD_ONEFRAME = 9,    // 单帧播放*/
	emSDK_TVWSSCMD_KEYFRAME = 10,    // 只放关键帧*/
	emSDK_TVWSSCMD_REVERSEPLAY = 11,	/*倒放*/
	emSDK_TVWSSCMD_FORWARDPLAY = 12,	/*正放*/
	emSDK_TVWSSCMD_KEYSEEK = 13,		/*定位到关键帧. */
	emSDK_TVWSSCMD_UNKNOWN = 14,          
};
//SchemePollStep End

//域状态
enum EDomainStatus
{
	emDomainStatusInvalid = 0, // 无效值.
	emDomainOnline = 1,        // 在线.
	emDomainOffline = 2,       // 离线.
};

//私有域信息
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

//国标子域信息
typedef struct tagCChildrenGBDomainInfo
{
	tagCChildrenGBDomainInfo()
	{
		memset(m_domainName,0,sizeof(m_domainName));
	}
	DomainID m_gbDomainId; //国标域ID
	char m_domainName[MAX_DESC_LEN+1]; //域名
	EDomainStatus m_status; //域状态EDomainStatus	
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
	char m_nruId[MAX_DESC_LEN+1];         // nru id。
	char m_devName[MAX_DESC_LEN+1];       // 设备名
	char m_devType[MAX_NAME_LEN+1];       // 设备类型:VS200,KDM2801E等
	char m_manuFactory[MAX_DESC_LEN+1];   // 设备厂商

	char m_ifName[MAX_DESC_LEN+1];        // 网卡名.
	char m_ipAddr[ADDR_STR_LEN+1];        // IP地址.
	char m_netMask[ADDR_STR_LEN+1];       // 子网掩码.
	char m_gateway[ADDR_STR_LEN+1];       // 网关.

	char m_RMSAddr[ADDR_STR_LEN+1];       // 注册RMS服务器地址.
	int m_maxBandWidthKb;       // NRU的最大数据带宽, 单位 Kb/S.
	bool m_online;              // 是否在线.
	bool m_used;                // 是否启用.
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
	int nVideoSampleRate;//视频采样率
	int nAudioSampleRate;//音频采样率
	u16 wLocalStartPort;//本地起始端口，仅平台1.0，用于计算本地VideoRtp接收端口(wLocalStartPort+4*playid),VideoRtcp、AudioRtp、AudioRtcp逐个加1
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

	u8	  m_byWatchTaskEnable;                     // ptz 操作后是否启动定时守望，非0则启用。
	u8	  m_byWatchTaskMinutes;                        // ptz 操作后几分钟启动定时守望
	u8	  m_byWatchTaskIntervals[MAX_WATCH_ON_NUM];    // 设置定时守望时间
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
	u8    m_byPrePosEnable;                      // 停止ptz操作后载入预置位使能，非0则启用。
	u8    m_byPrePosTime;                        // 停止ptz操作后几分钟后载入预置位
	u8    m_byPrePos;                            // 载入几号预置
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
	u32 m_dwSupportedAudioType;//支持的数据压缩格式（只读）;
	u32 m_dwAudioType;		//音频数据格式; 
	u8 m_byVolume;			//音量 0-25;
	u8 m_byAECState;		//回声抵消状态 DISABLE-无效，ENABLE-有效;
	u32 m_dwSmpRate;        //采样率 
	u8 m_bySmpBits;         //采样位数 
	u8 m_byChannle;         //声道 
	u32 m_dwSamplePerF;     //每帧样本数
	u32 m_dwReserved;		//保留字段

	//是否支持某种音频类型
	BOOL32 IsAudioTypeSupported(u32 dwAudioType) const
	{
		return m_dwSupportedAudioType & dwAudioType;
	}
	//设置音频类型支持
	void SetAudioTypeSupport(u32 dwAudioType)
	{
		m_dwSupportedAudioType = m_dwSupportedAudioType | dwAudioType;
	}
	//获取音频数据格式
	u32 GetAudioType() const
	{
		return m_dwAudioType;
	}
	//设置音频数据格式
	void SetAudioType(u32 dwAudioType)
	{
		m_dwAudioType = dwAudioType;
	}

	//获取音量 0-25
	u8 GetVolume() const
	{
		return m_byVolume;
	}
	//设置音量 0-25
	void SetVolume(u8 byVolume)
	{
		m_byVolume = byVolume;
	}

	//获取回声抵消状态 DISABLE-无效，ENABLE-有效
	BOOL32 IsAECState() const
	{
		return m_byAECState;
	}
	//设置回声抵消状态 DISABLE-无效，ENABLE-有效
	void SetIsAECState(BOOL32 bAECState)
	{
		m_byAECState = bAECState;
	}
	//获取采样率，单位为bps
	u32 GetSmpRate()
	{
		return m_dwSmpRate;
	}
	//设置采样率
	void SetSmpRate(u32 dwSmpRate)
	{
		m_dwSmpRate = dwSmpRate;
	}
	//获取采样位数，8位、16位、32位等
	u8 GetSmpBits()
	{
		return m_bySmpBits;
	}
	//设置采样位数
	void SetSmpBits(u8 bySmpBits)
	{
		m_bySmpBits = bySmpBits;
	}
	//获取单双声道，1-单声道，2-双声道
	u8 GetChannel()
	{
		return m_byChannle;
	}
	//设置单双声道
	void SetChannel(u8 byChannel)
	{
		m_byChannle = byChannel;
	}
	//获取每帧样本数
	u32 GetSamples()
	{
		return m_dwSamplePerF;
	}
	//设置每帧样本数
	void SetSamples(u32 dwSamples)
	{
		m_dwSamplePerF = dwSamples;
	}
}TAudioParams;

// 解码器选看状态
typedef struct tagDecodeWatchStatus
{
	TTPuChn m_tDecChn;		// 解码器ID
	TTPuChn m_tSrcPuChn[MAX_DECODE_CHN_NUM];		// 选看的编码器通道
}TDecodeWatchStatus;

// 录像参数
typedef struct tagRecordParam
{
	//注意! 录像类型只有在强制删除录像的操作中,才会使用到 TRecAlarmType。平时的查询等操作请参照 EmRecType
	DEVCHN m_DevChn;
	enum TRecAlarmType { e_IsALarm, e_NoIsAlarm, e_CanForceDel }; // 告警，非告警，可强制删除标志位
	enum { REC_UNLOCK, REC_LOCKED };
	u32 m_dwVodID; //录像ID;
	char m_ClientID[MAX_ID_LEN + 1]; //客户ID;
	u8 m_byRecType; //告警还是非告警;
	u32 m_StartTime; //开始和结束时间;
	u32 m_EndTime;
	char m_NruID[MAX_ID_LEN + 1]; //录像服务器ID;
	char m_szFilePath[MAXLEN_FILEPATH + 1]; //录像路径;
	char m_szFileName[MAXLEN_FILENAME + 1 - 4]; //录像名;由于录像名格式由cmu进行组织,且长度较为固定,其中有相当一部分空间未被使用
	//现取最后4位用于存放自动解锁日期
	u32 m_dwUnlockTime; //自动解锁日期(当m_byBitType第3个bit有效时该字段才有意义)
	char m_szFileAlias[MAXLEN_ALIAS + 1]; //录像别名; 
	u8 m_byIsHasAudio;		//是否使用音频
	u8 m_byIsGBRecord;		//是否是国标厂商的录像
	u8 m_byIsHasAutoUnlockTime;		//是否带有自动解锁日期
	u8 m_byVidEncFmt; //MPEG4, H264(kdvdef.h)
	u8 m_byAudioEncFmt;
	u32 m_dwRecSize; //录像大小（单位K）
	TTPuChn m_tPuChn; //前端;
	s8 m_szManuFac[MAXLEN_DEVICE_MANUFACTURER + 1]; //设备制造商
	u8 m_byRecTypeEx;  //录像类型  -- Del动态载荷值
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
	u8 m_byOperType; //操作类型，See enum 
	u32 m_dwReason;  //原因
	u32 m_dwReseve1; //保留字段1
	u16 m_wLockDays; //需要锁定的天数,0表示永久锁定
	u16 m_wLockPointType;  //锁定生效的起始点,从当前时间(LOCK_FROM_NOW),从录像保存时间(LOCK_FROM_STARTTIME)
}TOperRecordParam;

// 设备录像状态枚举
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
	emRecPlatPuInvalid = 0, // 不在录像
	emRecPlat = 1, // 有平台录像
	emRecPu = 2, // 有前端录像
	emRecPlatPu = 3, // 平台前端都在录像
};


//新搜索接口返回的ITEM里的结果类型枚举
enum emSearchResultType
{
	emSearchResultDeviceGroup = 1,
	emSearchResultDevice,
	emSearchResultVideosrc,
};

// 设备录像状态信息
typedef struct tagDevRecordInfo
{
	tagDevRecordInfo()
	{
		m_emDevRecStat = emRecPlatPuInvalid;
		memset(m_emPlatRecStat, 0, sizeof(m_emDevRecStat));
		memset(m_emPuRecStat, 0, sizeof(m_emDevRecStat));
	}

	DeviceID m_tDevID;

	TRecPlatPuStat m_emDevRecStat; // 是否存在前端或平台录像
	TRecStat m_emPlatRecStat[MAX_VID_CHN_NUM]; // 具体通道平台录像状态
	TRecStat m_emPuRecStat[MAX_VID_CHN_NUM]; // 具体通道前端录像状态, 前端录像只有Idel和Ok状态
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

//码流发送接收的地址信息
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
//不发码流的语音呼叫平台返回的用于自己建立码流发送所需要的信息
typedef struct tagTPuCallInfo
{
	//音频呼叫发送端的地址信息
	TMediaAddrInfo m_localAddr;
	//服务端接受码流的地址信息
	TMediaAddrInfo m_platAddr;
	//如果有NAT，服务端的NAT信息
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
	char m_chReserverd;//保留
}tagVoiceCallNatEx,*pTagVoiceCallNatEx;

// 搜索结果.
typedef struct tagDeviceGroupPathItem
{
	GroupID id;						// 组的ID.
	char szName[MAX_NAME_LEN + 1];	// 组的名字.
}TDeviceGroupPathItem;
typedef struct tagTSearchResultItem
{
	int type;		// 类型, 定义参见 emSearchResultType, 设备组/设备/视频源
	KDMNO id;		// id

	int vsId;		// 视频源id. 结果为设备组/设备时无意义.
	char szDevSrcAlias[MAX_NAME_LEN + 1]; // // 名称

	int groupDeepth;										// 上级组的数目.
	tagDeviceGroupPathItem devGroupPath[MAX_GROUP_DEEPTH];	// 上级组.

	BOOL32 online;

	u16 nDevType; // device type
	u16 nDevCap; // device capability

	DomainID szDomainId;
	char szManufacturer[MAXLEN_DEVICE_MANUFACTURER+1];

}TSearchResultItem;

//多视图设备树信息
typedef struct tagDeviceTree
{
	char id[MAX_NAME_LEN+1];	//设备树ID
	char name[MAX_NAME_LEN+1];//设备树名
	char version[MAX_NAME_LEN+1];//设备树的数据版本号
	char rootid[MAX_ID_LEN+1];	//树的根组id
}DeviceTree;
//多个设备树信息列表
typedef struct tagMultiViewDeviceTreeList
{
	DeviceTree trees[MAX_MULTIVIEW_DEVICE_TREE_NUM];
	int num;
}MultiViewDeviceTreeList;


enum emMcusdkTreeViewType
{
    emMcusdkTreeViewType_System = 0, //系统级的视图，多用户共享
    emMcusdkTreeViewType_User, //用户级的视图，用户独占 即收藏夹
};

typedef struct tagDeviceTree_V2
{
    char id[MAX_NAME_LEN+1];	//设备树ID
    char name[MAX_NAME_LEN+1];//设备树名
    char version[MAX_NAME_LEN+1];//设备树的数据版本号
    char rootid[MAX_ID_LEN+1];	//树的根组id
    int nType; //   emMcusdkTreeViewType
    int nReversed; //
}DeviceTree_V2;
//多个设备树信息列表
typedef struct tagMultiViewDeviceTreeList_V2
{
    DeviceTree_V2 trees[MAX_MULTIVIEW_DEVICE_TREE_NUM];
    int num;
}MultiViewDeviceTreeList_V2;

typedef struct tagMcusdkVersionInfo
{
	char sdkver[MAX_NAME_LEN + 1];	//Mcusdk自身的二进制版本号
	char cmsver[MAX_NAME_LEN + 1];	//平台的版本号
	char cuver[MAX_NAME_LEN+1];		//平台上的客户端cu的版本号
	char cuupdateurl[MAX_URL_LEN+1];	//平台上的客户端cu的下载路径
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

//码流GPS信息回调函数原型声明
typedef void(*PMCUSDK_GPS_CALLBACK)(u32 /*nPlayId*/, void * /*pGpsData*/, u32 /*nDataLen*/, void * /*pUserData*/);

/*解码器统计信息*/
typedef struct tagMcusdkDecStatis
{
	unsigned int		dwVideoFrameRate;	/*视频解码帧率*/
	unsigned int		dwVideoBitRate;   	/*视频解码码率*/
	unsigned int		dwAudioBitRate;   	/*语音解码码率*/
	unsigned int		dwVideoRecvFrame;	/*收到的视频帧数*/
	unsigned int		dwAudioRecvFrame;	/*收到的语音帧数*/
	unsigned int		dwVideoLoseFrame;	/*丢失的视频帧数*/
	unsigned int		dwAudioLoseFrame;	/*丢失的语音帧数*/
	unsigned int		dwVideoLoseRatio;	//视频丢失率,单位是% 	
	unsigned int		dwAudioLoseRatio;	//音频丢失率,单位是% 	
	unsigned int		dwPackError;		/*乱帧数*/
	unsigned int		dwIndexLose;		/*序号丢帧*/
	unsigned int		dwVideoSizeLose; 	/*大小丢帧*/
	unsigned int		dwVideoFullLose; 	/*满丢帧*/
	unsigned int		dwAudioSizeLose; 	/*大小丢帧*/
	unsigned int		dwAudioFullLose; 	/*满丢帧*/
	unsigned int		dwAvrVideoBitRate;   /*1分钟内视频解码平均码率*/
	unsigned int	  	dwAvrAudioBitRate;   /*1分钟内语音解码平均码率*/
	bool                bVidCompellingIFrm;  /*视频强制请求I帧*/
	unsigned int		dwDecdWidth;		/*码流的宽*/
	unsigned int		dwDecdHeight;   	/*码流的高*/
	unsigned int        dwCodecType;        /*解码类型,soft:0;hw:1;yuvcb:2;*/
	unsigned int        dwDrawMode;         /*绘图方式,d3d:0;ddraw:1;drawdib:2;direct:3*/
}DecStatis;


//与平台2.0兼容的PTZ控制命令, 用于 Kdm_PtzControl 接口, 支持多个PTZ参数.
enum EMcusdkPtzCmd
{
	McusdkPtzCmdInvalid = 0,			// 0	// 空操作.
	McusdkPtzNull = McusdkPtzCmdInvalid,
	McusdkPtzCommandDefineBegin = 1,
	// 与1.0里定义一致.
	McusdkPtzMoveUp = McusdkPtzCommandDefineBegin,			// 1	//向上移动
	McusdkPtzMoveDown,	    	// 2	//向下移动
	McusdkPtzMoveLeft,			// 3	//向左移动
	McusdkPtzMoveRight,			// 4	//向右移动
	McusdkPtzMoveHome,			// 5	//回归
	McusdkPtzMoveStop,			// 6	//停止移动
	McusdkPtzZoomIn,				// 7	//拉近摄像头
	McusdkPtzZoomOut,				// 8	//拉远摄像头
	McusdkPtzZoomStop,			// 9	//视野调节停止
	McusdkPtzFocusFar,		    // 10	//将焦距调远
	McusdkPtzFocusNear,			// 11	//将焦距调近
	McusdkPtzFocusAuto,			// 12	//自动调焦
	McusdkPtzFocusStop,			// 13	//调焦停止
	McusdkPtzPresetSave,	    	// 14	//摄象头预存
	McusdkPtzPresetCall,			// 15	//调摄象头预存
	McusdkPtzCameraReset,		 // 16	// 初始化摄像头 ??
	//PtzChangeVideoSrc,		// 16	// 切换视频源(摄像头)
	McusdkPtzBrightUp,			// 17	//画面调亮
	McusdkPtzBrightDown,			// 18	//画面调暗
	McusdkPtzBrightStop,			// 19	//停止调亮
	McusdkPtzCommandNew,			// 20	//新命令	  神马东西??	 1.0里没有用到.
	McusdkPtzCommandAppend,		// 21	//附加命令 神马东西?? 1.0里没有用到.
	McusdkPtzGotoPoint,			// 22	//中心定位
	McusdkPtzZoomArea,			// 23	//局部放大

	McusdkPtzAlecPanSpeed,	// 24	//艾立克水平移动速度设置命令，（内部使用） 没用到??
	McusdkPtzAlecTiltSpeed,	// 25	//艾立克垂直移动速度设置命令，（内部使用） 没用到??
	McusdkPtzSonySetBright,	// 26	//sony亮度调节启动命令（内部使用）		没用到??

	McusdkPtzMatrixSwitch,		// 27	//切换视频
	McusdkPtzMatrixVideoMix4,		// 28	//画面合成2×2
	McusdkPtzMatrixVideoMix9,		// 29	//画面合成3×3
	McusdkPtzMatrixVideoMix16,	// 30	//画面合成4×4
	McusdkPtzMatrixVideoMixPP,	// 31	//画面合成画中画

	McusdkPtzZoomAreaStop,		// 32    // 取消局部放大 

	////菜单//////////////////////////////////////////////////////////////////////	
	McusdkPtzMenuUp,				// 33	//菜单上
	McusdkPtzMenuDown,			// 34	//菜单下
	McusdkPtzMenuLeft,			// 35	//菜单左
	McusdkPtzMenuRight,			// 36	//菜单右

	McusdkPtzMenuShow,			// 37	//菜单显示
	McusdkPtzMenuHide,			// 38	//菜单隐藏

	McusdkPtzMenuEnter,			// 39	//菜单确定
	McusdkPtzMenuCancel,		    // 40	//菜单取消

	McusdkPtzPresetDel,			// 41	//删除摄象头预存 (没用到?)
	////矩阵切换//////////////////////////////////////////////////////////////////////
	McusdkPtzMatrixSwitchASC,	// 42	//正向切换
	McusdkPtzMatrixSwitchESC,	// 43	//反向切换
	McusdkPtzMatrixHoldImage,	// 44	//图像保持

	McusdkPtzMoveLeftUp,		//(u8)45		//向左上移动
	McusdkPtzMoveLeftDown,	//(u8)46		//向左下移动
	McusdkPtzMoveRightUp,		//(u8)47		//向右上移动
	McusdkPtzMoveRightDown,	//(u8)48		//向右下移动

	////巡航//////////////////////////////////////////////////////////////////////	
	McusdkPtzAutoScanStart = 128,  // 128	//开始自动巡航
	McusdkPtzAutoScanStop,       // 129	//停止自动巡航	
	McusdkPtzPresetScanStart,		// 130	//开始巡检(预置位轮巡?)
	McusdkPtzPresetScanStop,     // 131	//停止巡检(预置位轮巡?)
	McusdkPtzScanSpeedSet,		//(u8)132	//水平扫描速度（影响自动扫描速度）bySpeed(1-40s)	

	// 雨刷
	McusdkPtzStartWiper = 160,		//(u8)160	//开始雨刷，第一个参数为雨刷速度，值为0-15，其他参数置零
	McusdkPtzStopWiper,			//(u8)161	//停止雨刷

	//+ by maonanjing@2014-11-04
	McusdkPtzLightOn,            //(u8)162   //开启灯光
	McusdkPtzLightOff,           //(u8)163   //关闭灯光 
	McusdkPtzStartExt1,           //(u8)164   //扩展功能一（可能是开启喷水）
	McusdkPtzStopExt1,           //(u8)165   //关闭喷水扩展功能一
	McusdkPtzStartExt2,          //(u8)166   //扩展功能二（可能是开启除霜）
	McusdkPtzStopExt2,			//(u8)167   //关闭除霜扩展功能二

	//+ by maonanjing@2016-04-06
	McusdkPtzLock,				//(u8)168	//云解锁权限

	McusdkPtzCommandDefineEnd,			// Ptz命令定义结束.
};

//平台2.0PTZ控制的锁定反馈信息
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
    emRS_RECTYPE_ALL = 1,  // 全部
    emRS_RECTYPE_ALARM = 2, // 告警
    emRS_RECTYPE_HANDLE = 3, //手动
    emRS_RECTYPE_PLAN = 4,     //计划
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
    TRecordInfo tRecordInfo; //平台录像
    BOOL32 locked; // 录像是否被锁定
    u32 lockExpireTime; // 录像锁定的失效时间

    int nsubrecordnums;//子录像数量(暂不支持)
    McusdkSubRecordItem aSubRecordItem[MAX_REQ_DEV_SUBS_NUM];// 子录像（连续录像中的不同的录像段的类型）(暂不支持)
    
}McusdkLockRecordItem;

typedef struct tagMcusdkLockRecord
{
    int nLockNums;//需要锁定或解锁的录像数量
    tagMcusdkLockRecordItem aLockItem[MAX_REQ_DEV_SUBS_NUM];//需要锁定或解锁的录像
}McusdkLockRecord;

typedef struct tagMcusdkQueryLockedRecord
{
    DEVCHN devChn;   // 锁定录像的监控点. 其中设备ID可以为空, 表示搜索所有锁定录像. 
    BOOL32 enableTimeRange;// 是否使用时间段参数. 不启用的话搜索所有时间段的锁定录像.
    TPeriod timeRange;// 锁定时间段。
    u32 maxResultNum;//返回的最大结果数
    tagMcusdkQueryLockedRecord()
    {
        enableTimeRange = FALSE;
        maxResultNum = MAX_REQ_DEV_SUBS_NUM; // do not change
    }
}McusdkQueryLockedRecord;

typedef struct tagMcusdkQryLockedRecResult
{
    BOOL32 hasMoreResult;//有超出最大结果数的录像记录未返回.
    McusdkLockRecord tQryLockRecresult;//结果
    tagMcusdkQryLockedRecResult()
    {
        hasMoreResult = FALSE;
    }
}McusdkQryLockedRecResult;

enum EmMcusdkBatchOpType
{
    emOpStartPlatRecord,	// 开始平台录像
    emOpStopPlatRecord,	// 停止平台录像
    emOpStartPuRecord,	// 开始前端录像
    emOpStopPuRecrod,		// 停止前端录像
    emOpStartWiper,		// 开始雨刷
    emOpStopWiper,		// 停止雨刷
    emOpStopPuCall,		// 停止语音呼叫, 参数1:用户呼叫的PlayId 
    emOpLoadPresetPos,	// 前端载入预置位 参数1: 预置位ID.
    emOpLockRecord,	//  锁定平台录像. 参数1: 录像起始时间. 参数2: 录像结束时间. 时间格式都为标准时间字符串
};

typedef struct tagMcusdkBatchOperation
{
    GroupID treeId; // 树ID, 为空则为系统默认设备树
    GroupID groupId;// 组ID
    BOOL32 bRecursive;// 是否对下级分组做递归操作
    EmMcusdkBatchOpType operationType;// 操作类型
    u32 dwParamNum;//参数列表数量
    BatchOpParam strParamList[MAX_REQ_DEV_SUBS_NUM];// 参数列表, 根据操作类型不同,需要不同的参数.
    tagMcusdkBatchOperation()
    {
        bRecursive = FALSE;
        dwParamNum = 0;
    }
}McusdkBatchOperation;


//PTZ锁定请求
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

//PTZ锁定回复
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
	int errorCode;//平台返回的错误码
}McusdkPTZLockRsp;

//PTZ解锁请求
typedef struct tagMcusdkPTZUnLockReq
{
	tagMcusdkPTZUnLockReq()
	{
		memset(password, 0, sizeof(password));
	};
	DEVCHN devChn;	
	char password[MAX_NAME_LEN + 1];
}McusdkPTZUnLockReq;

//PTZ解锁回复
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


#define  ALARMLINK_ACTION_PLATFORMRECORD   0x01 //平台录像
#define  ALARMLINK_ACTION_PLAYONTV                0x02 // 上墙
#define  ALARMLINK_ACTION_READSECOND           0x04 // 读秒
#define  ALARMLINK_ACTION_IOOUTPUT                0x08 // io端口输出
#define  ALARMLINK_ACTION_CAMERAPREPOS       0x10 // 摄像头预置位设置 

typedef struct tagMcusdkAlarmLinkAction
{
    u32 dwActionType; // 多种告警联动类型 进行或的结果 ALARMLINK_ACTION_....
    char szDeviceId[MAX_ID_LEN+1]; // 联动的设备id
    int nSrcId; //视频源
    int ncamPrePos; // 摄像头预置位
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
    // 告警布防时间段列表
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

//预置位别名
typedef struct tagMcusdkPresetName
{
	int nPresetId;
	char szName[MAX_NAME_LEN + 1];
}McusdkPresetName;

//前端录像计划参数
typedef struct tagMcusdkRecordPlan
{
	ERecMode recMode;	//录像模式
	int nPrerecordDuration;	//预录时长（单位秒），0表示不预录
	int nRecordDurationAfterAlarm;	// 告警恢复后平台录像时间, 单位秒.
	
	BOOL32 bSupportChangeStreamType;       // 支持切换录像码流类型
	int nRecStreamType;                  // 录像码流类型。0-主流，1-辅流1，2-辅流2，3-辅流3

	BOOL32 bSupportSetRecDuration; //是否支持设置录像存储时长	
	BOOL32 bRecDurationEnabled; //当前是否启用录像存储时长设置
	int nRecStorageDuration; //录像存储时长（>=1天），0-系统默认

	int nTimeListNum;//下面这个数组中有效的字符串数
	char planedRecordCronTimeList[MAX_TIME_LIST_NUM][MAX_DESC_LEN+1];
}McusdkRecordPlan;


// 分区信息。
typedef struct tagMcusdkPartitionInfo
{
	int diskId;				// 所属磁盘Id.
	int partitionId;		// 分区Id.
	char partName[MAX_NAME_LEN+1];	// 分区名.
	int totalSize;			// 总空间, 单位 MB
	int freeSize;			// 空闲空间, 单位 MB.
	ERSPartState partState;	// 分区状态.
	char partType[MAX_SHOT_NAME_LEN+1];	// 分区格式( vbfs, ext3 )
	int abnNum;				// 异常次数.
	char mountPath[MAX_URL_LEN+1];	// 挂在路径.
	int start;				// 起始块位置.
	int end;				// 结束块位置
	int recordNum;			// 录像数.
}McusdkPartitionInfo;


//磁盘信息
typedef struct tagMcusdkDIskInfo
{
	int diskId;				// 磁盘Id.
	char diskName[MAX_NAME_LEN+1];	// 磁盘名.
	int diskSize;			// 容量. 单位MB.
	int diskAbnNum;			// 异常次数.
	ERSDiskState diskState;	// 磁盘状态.
	char diskSource[MAX_DESC_LEN+1];	// 来源.
	int cylinders;			// 柱面数.
	int heads;				// 磁头数.
	int sectors;			// 扇区数目
	int partitionNum;//下面的分区个数
	McusdkPartitionInfo partitionList[MAX_PARTITION_NUM];	// 分区列表.
}McusdkDIskInfo;

//获取分区绑定信息请求结构体
typedef struct tagMcusdkGetDeviceBindReq
{
	char *nruId;	// NRU的UUID
	char *diskMountPath;	// 分区的mount路径。
	int beginIndex;	// 起始序号.
	int num;			// 本次请求要的总数.
}McusdkGetDeviceBindReq;

//支持时区夏令时的同步录像分页同步查询请求结构体
typedef struct tagMcusdkQueryRecordReq
{
	DEVCHN devChn;	
	TPeriod timeRange;
	eRecordType recType;
	emRecordEventType recEvent;
	char *domainName;	
}McusdkQueryRecordReq;

//码流水印参数,直接设置给解码渲染模块的
typedef struct tagMcusdkWaterMark
{	
	emWaterMarkMode    eWMMode;	 //选择添加水印模式，可以用 或运算 一次设置
	BOOL32             bEnable;				//是否开启水印;默认关闭，TRUE开启
	unsigned int        uiARGB;				//字体颜色和透明度0xAARRGGBB
	unsigned int        uiFontSize;			//字体大小[16,2000]
	unsigned int        uiFontRotate;		//旋转角度【0~360】
	unsigned int        uiLayerMode;		//1：平铺，类似“井”字形均匀平铺，不会拉伸文字。文字太长，将被截断。
	char *strText;      //utf8文字内容，由于uniplay的限制，实际只能传递最多60个字母或30个汉字，超过的会被截断
	char *pstrFontPath; //utf8字库路径，如果为NULL，内部会选择一个默认的字库
	unsigned int uiWinWidth;   //水印窗口宽高
	unsigned int uiWinHeight;  //水印窗口宽高
	BOOL32         bAutoAdjustFont;//是否根据窗口自动调整字体大小 保证水印排布一致
	u32 m_dwReserve1;//保留字段1
	u32 m_dwReserve2;//保留字段2
}McusdkWaterMark;

//用户的水印参数，从平台获取的用户水印参数
typedef struct tagMcusdkUserWaterMark
{	
	BOOL32              bEnable;										//是否启用了水印
	EWarterMarkFontSizeLevel       uiFontSizeLevel;			//字体大小等级
	unsigned int        uiARGB;				//字体颜色和透明度0xAARRGGBB	
	unsigned int        uiFontRotate;		//旋转角度【0~360】
	unsigned int        uiLayerMode;		//1：平铺，类似“井”字形均匀平铺，不会拉伸文字。文字太长，将被截断。
	char szFontPath[MAX_URL_LEN + 1];	//字库文件所在路径
}McusdkUserWaterMark;


typedef struct   tagSetupDownloadRecordRsp
{
	int nPort;
	char serverIp[MAX_URL_LEN + 1];
	char recordFilePath[MAX_URL_LEN+1];
	char recordFileName[MAX_NAME_LEN+1];
}SetupDownloadRecordRsp;


//安全模式开启参数
typedef struct tagMcusdkSafeModeInfo
{
	char pemFile[260];//utf8表示的文件名 .pem 文件	
	char keyFile[260];//utf8表示的文件名，.crt 文件
	char keyPwd[MAX_PWD];//keyFile的文件读取保护密码
}McusdkSafeModeInfo;

#pragma pack()
#endif
