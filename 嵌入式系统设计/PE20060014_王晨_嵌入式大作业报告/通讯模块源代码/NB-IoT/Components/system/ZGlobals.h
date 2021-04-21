/*************************************************************************
  \file				ZGlobals.h
  \brief
		User definable Stack parameters.

  \author
		Johnason
  \internal
  	  Revision History:
  		DEC. 16, 2017		Johnason - Created
**************************************************************************/

#ifndef __ZGLOBALS_H__
#define __ZGLOBALS_H__

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
 * 							INCLUDES
 */
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "ZComDef.h"
#include "board.h"
//#include "szconfig.h"

/*********************************************************************
 * 							 MACROS
 */
#define HEART_PACKET_DEF       		"DC41885310"
#define HEART_TIME					"120"
#define HEART_PACKET_ON             1
#define NB_APN_IP  					"117.63.14.180"
#define NB_APN_PORT                 "5683"
#define NB_FOTA_ON 					0

#define SET_IPADDR_LEN 15
#define SET_HOST_NAME_LEN 65
#define SET_APNINFO_LEN 40
#define SET_APNNAME_LEN 16
#define SET_APNPASSWORD_LEN 16
#define SET_HOST_DNS_LEN 20
#define QUIT_CONFIG_TIME  180
/*********************************************************************
 * 							TYPEDEFS
 */

/*********************************************************************
 * 						GLOBAL VARIABLES
 */
extern uint8_t NB_version[] ;
extern uint8_t dtuid[8] ;
extern uint8_t serve_ipaddr[SET_IPADDR_LEN+1] ;//service ip address    //P S dns --->fota ip address
extern uint8_t serve_host_name[SET_HOST_NAME_LEN+1] ;//service host name 1
extern uint8_t port[6] ;
//extern uint8_t fota_user_name[SET_HOST_NAME_LEN+1] ;     // --->fota user name
//extern uint8_t fota_password[6] ;                        //--->fota password
extern uint8_t apninfo[SET_APNINFO_LEN+1] ;//
//extern uint8_t apnname[SET_APNNAME_LEN+1];
//extern uint8_t apnpassword[SET_APNPASSWORD_LEN+1];
extern bool rssi_disp ; //TRUE = TCP, FALSE = UDP
extern bool DebugInfoEnable ;            //������Ϣ���ʹ��
extern bool DeviceIdentEnable ;           //�豸��ʶʹ��
extern bool SMSComEnable ;               //�����շ�����ʹ��
//extern uint8_t UserName[SET_APNNAME_LEN];           //���Ų����û��绰����11λ
//extern uint8_t PassWord[SET_APNNAME_LEN];    /**/     //�û�����6λ
extern uint8_t BaudRateType ;            //�û��˴��ڱ�����
extern uint8_t DataBitType ;             //����λ 8/9
extern uint8_t CheckBitType ;            //У��λ
extern uint8_t StopBitType ;             //ֹͣλ ����Ϊ��
extern bool RegisterPacketEnable ;        //ע���ʹ�ܣ�����ʱ���ӳɹ��״η���������
//extern uint8_t RegisterPacketContent[81] ;   //ע������ݣ�����Ϊ�豸��ʶ��Ϣ
extern bool HeartbeatTimeEnable ;    //������ʹ��
extern uint8_t HeartbeatTime[6] ;        //����ʱ��  ��λs
//extern uint8_t HeartbeatData[81] ;       //�������ݰ�����
//extern uint8_t serve_host_name_sz[SET_HOST_NAME_LEN+1];//service host name sz
//extern uint8_t port_sz[6];
extern uint8_t HeartbeatTime[6];
//extern uint8_t NB_version[];
//extern uint8_t Heartpacket[heart_packet_len];
//extern uint32_t Hearttime;
//extern uint8_t Heartenable;
extern uint8_t FOTA_mode;
//extern oa_soc_set_parameter g_soc_param;
/*
 * Initialize the Z-Stack Globals.
 */
uint8_t zgInit( void );

/*
 * Initialize the RAM Items table with NV values.
 *    setDefault - if calling from outside ZGlobal use FALSE.
 */
void zgInitItems( uint8_t setDefault );

/*
 *  Set RAM variables from set-NV, if it exist in the zgItemTable
 */
void zgSetItem( uint16_t id, uint16_t len, void *buf );

/*
 *  Get RAM variables from set-NV, if it exist in the zgItemTable
 *  the space of the buf is allocate outside
 */
uint8_t zgGetItem( uint16_t id, uint16_t len, void *buf );

/*********************************************************************
*********************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* __ZGLOBALS_H__ */
