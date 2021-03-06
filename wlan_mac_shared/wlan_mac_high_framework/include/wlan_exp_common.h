/** @file wlan_exp_common.h
 *  @brief Experiment Framework (Common)
 *
 *  This contains the code for WARPnet Experimental Framework.
 *
 *  @copyright Copyright 2013-2015, Mango Communications. All rights reserved.
 *          Distributed under the Mango Communications Reference Design License
 *				See LICENSE.txt included in the design archive or
 *				at http://mangocomm.com/802.11/license
 *
 *  @author Chris Hunter (chunter [at] mangocomm.com)
 *  @author Patrick Murphy (murphpo [at] mangocomm.com)
 *  @author Erik Welsh (welsh [at] mangocomm.com)
 */



/***************************** Include Files *********************************/
// Include xil_types so function prototypes can use u8/u16/u32 data types
#include "xil_types.h"
#include "warp_hw_ver.h"

#include "wlan_exp.h"

/*************************** Constant Definitions ****************************/
#ifndef WLAN_EXP_COMMON_H_
#define WLAN_EXP_COMMON_H_


// **********************************************************************
// WLAN Exp print levels
//
#define WLAN_EXP_PRINT_NONE                      0
#define WLAN_EXP_PRINT_ERROR                     1
#define WLAN_EXP_PRINT_WARNING                   2
#define WLAN_EXP_PRINT_INFO                      3
#define WLAN_EXP_PRINT_DEBUG                     4


#define wlan_exp_printf(level, type, format, args...) \
	                    do {  \
                            if (level <= wlan_exp_print_level) { \
                            	wlan_exp_print_header(level, type, __FILE__, __LINE__); \
                                xil_printf(format, ##args); \
                            } \
                        } while (0)


extern u8       wlan_exp_print_level;
extern char   * print_type_node;
extern char   * print_type_transport;
extern char   * print_type_event_log;
extern char   * print_type_stats;
extern char   * print_type_ltg;
extern char   * print_type_queue;



// **********************************************************************
// Network Configuration Information
//

// Default network info
//   The base IP address should be a u32 with (at least) the last octet 0x00
#define NODE_IP_ADDR_BASE           0x0a000000 //10.0.0.0
#define BROADCAST_DEST_ID           0xFFFF

// Default ports- unicast ports are used for host-to-node, multicast for triggers and host-to-multinode
#define NODE_UDP_UNICAST_PORT_BASE	9500
#define NODE_UDP_MCAST_BASE			9750



// **********************************************************************
// WARPNet Common Defines
//

#define PAYLOAD_PAD_NBYTES        2

#define RESP_SENT                 1
#define NO_RESP_SENT              0

#define LINK_READY                0
#define LINK_NOT_READY           -1

#define SUCCESS                   0
#define FAILURE                  -1

#define WN_CMD_TO_GRP(x)         ((x)>>24)
#define WN_CMD_TO_CMDID(x)       ((x)&0xffffff)

#define FPGA_DNA_LEN              2
#define IP_VERSION                4
#define ETH_ADDR_LEN	          6

#define WN_NO_TRANSMIT            0
#define WN_TRANSMIT               1


/*********************** Global Structure Definitions ************************/
// 
// WARPNet Message Structures
//

typedef struct{
	u32       cmd;
	u16       length;
	u16       numArgs;
} wn_cmdHdr;


typedef struct{
	void     *buffer;
	void     *payload;
	u32       length;
} wn_host_message;


typedef wn_cmdHdr wn_respHdr;


typedef int (*wn_function_ptr_t)();



// **********************************************************************
// WARPNet Tag Parameter Structure
//
typedef struct {
	u8    reserved;
	u8    group;
	u16   length;
	u32   command;
	u32  *value;
} wn_tag_parameter;



/*************************** Function Prototypes *****************************/
// 
// Define WARPNet Common Methods
//
void wlan_exp_configure(u32 type, u32 type_mask, u32 eth_dev_num);

void wlan_exp_print_header(u8 level, char * type, char * filename, u32 line);
void wlan_exp_print_mac_address(u8 level, u8 * mac_address);

void wlan_exp_set_print_level(u8 level);

void wlan_exp_get_mac_addr(u32 * src, u8 * dest);
void wlan_exp_put_mac_addr(u8 * src, u32 * dest);


//
// Define WARPNet Common Methods that must be implemented in child classes
//
u32  wlan_exp_get_id_in_associated_stations(u8 * mac_addr);


#ifdef _DEBUG_
void print_wn_parameters( wn_tag_parameter *param, int num_params );
#endif


#endif /* WLAN_EXP_COMMON_H_ */
