#ifndef _DMS_CONTROL_H_
#define _DMS_CONTROL_H_
#include "qmi_client.h"
#include "device_management_service_v01.h"
#include "simcom_common.h"

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef unsigned char boolean;
typedef unsigned char uint8;


enum {
    SIMCOM_NETWORK_TRYLTE_READ,
    SIMCOM_NETWORK_TRYLTE_WRITE
};

enum {
    DMSI_REPORT_SIMCOM_UNIVERSAL_INTERFACE_TRYLTE_URC,
    DMSI_REPORT_SIMCOM_UNIVERSAL_INTERFACE_MAX
};


    
int dms_init();
void dms_deinit();

/*****************************************************************************
* Function Name : get_imei
* Description   : 查询sim卡 IMSI
* Input         : 无
* Output        : pImsi
* Return        : 0： succes     -1： Fail
* Auther        : qjh
* Date          : 2018.04.26
*****************************************************************************/
int get_imei(char *pImei);

/*****************************************************************************
* Function Name : get_meid
* Description   : 查询sim卡 MEID
* Input         : 无
* Output        : pMeid
* Return        : 0： succes     -1： Fail
* Auther        : qjh
* Date          : 2018.04.26
*****************************************************************************/
int get_meid(char *pMeid);

/*****************************************************************************
* Function Name : get_meid
* Description   : 从NV中读取预设的MAC地址
* Input         : device_type
				  DMS_DEVICE_MAC_WLAN_V01 = 0   ---- WIFI MAC地址
				  DMS_DEVICE_MAC_BT_V01   = 1   ---- 蓝牙 MAC地址
				  DMS_DEVICE_MAC_LAN_V01  = 2   ---- ETH  MAC地址               
* Output        : mac_addr   需要预先分配至少6个byte的字符数组
* Return        : 0： succes     -1： Fail
* Auther        : qjh
* Date          : 2018.04.26
*****************************************************************************/		
int get_mac_address_from_nv(dms_device_mac_enum_v01 device_type, uint8_t *mac_addr);


/*****************************************************************************
* Function Name : get_rev_id
* Description   : get firmware revision identification
* Input         : pointer to buffer 
* Output        : firmware revision identification
* Return        : 0 succes   1 Fail
* Auther        : lhy
* Date          : 2018.08.16
*****************************************************************************/		
int get_rev_id(char *pRev_id);


/*****************************************************************************
* Function Name : dms_set_operating_mode
* Description	: set UE operating mode
* Input         : mode value

                       0 Online            (equal  at+cfun=1)
                       1 Low power         (equal  at+cfun=0)
                       2 Factory Test mode 
                       3 Offline
                       4 Resetting
                       5 Shutting down
                       6 Persistent low power 
                       7 Mode-only low power
                       
* Output        : NONE
* Return        : 0 succes     1 Fail
* Auther        : lhy
* Date          : 2018.08.16
*****************************************************************************/

int dms_set_operating_mode(unsigned char mode);

/*****************************************************************************
* Function Name : dms_get_operating_mode
* Description	: get UE operating mode
* Input         : NONE
* Output        : mode value
                       0 Online            (equal  at+cfun=1)
                       1 Low power         (equal  at+cfun=0)
                       2 Factory Test mode 
                       3 Offline
                       4 Resetting
                       5 Shutting down
                       6 Persistent low power 
                       7 Mode-only low power
                       
* Return        : 0 succes     1 Fail
* Auther        : zxs
* Date          : 2019.07.25
*****************************************************************************/

int dms_get_operating_mode(unsigned char* mode);


/*****************************************************************************
* Function Name : simcom_network_trylte
* Description	: network 2g to 4g
* Input         : mode
                    0  READ
                    1  WRITE
                if mode = WRITE
                :*urc_enable
                    0: DISABLE
                    1: ENABLE
                :*try_flag:
                    0 : NOT TRY LTE
                    NULL: not set
                        
* Output        
                if mode = READS
                :*urc_enable
                    0: DISABLE
                    1: ENABLE
                :*try_flag:
                    0: NOT TRY LTE
                    1: TRY LTE

* Return        : 0 succes     -1 Fail
* Auther        : hyc
* Date          : 2019.11.29
*****************************************************************************/

int simcom_network_trylte(int mode, int *urc_enable, int *try_flag);

int time_get_modem_cclk(uint64_t *msecs);

#endif


