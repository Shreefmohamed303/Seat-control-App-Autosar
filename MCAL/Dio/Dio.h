 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.h
 *
 * Description: Header file for Dio Module.
 *
 * Author: Shreef Mohamed
 *
 * Created on: Aug 8, 2020
 *
 ******************************************************************************/
#ifndef DIO_H
#define DIO_H



/* Standard AUTOSAR types */
#include "Std_Types.h"


/* Dio Pre-Compile Configuration Header file */
#include "Dio_Cfg.h"

#include "Dio_Regs.h"

/* Non AUTOSAR files */
#include "common_macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           (uint8)0x00

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          (uint8)0x01

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              (uint8)0x02

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             (uint8)0x03

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     (uint8)0x04

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    (uint8)0x05

/* Service ID for DIO GetVersionInfo */
#define DIO_GET_VERSION_INFO_SID       (uint8)0x12

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           (uint8)0x11

/* Service ID for DIO Init Channel */
//#define DIO_INIT_SID                   (uint8)0x10



/*******************************************************************************
 *                        DET Error Codes                                      *
 *******************************************************************************/

/* DET code to report [Invalid channel name requested] */
#define DIO_E_PARAM_INVALID_CHANNEL_ID	0x0A

/* DET code to report [API service called with “NULL pointer” parameter] */
#define DIO_E_PARAM_CONFIG				0x10

/* DET code to report [Invalid port name requested] */
#define DIO_E_PARAM_INVALID_PORT_ID		0x14

/* DET code to report [Invalid ChannelGroup passed] */
#define DIO_E_PARAM_INVALID_GROUP		0x1F

/* DET code to report [API service called with a NULL pointer] */
#define DIO_E_PARAM_POINTER				0x20


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Type definition of a channel type, which consist of Numeric ID of a DIO channel */
typedef uint8 Dio_ChannelType;

/* Type definition of a port type, which consist of Numeric ID of a DIO port */
typedef uint8 Dio_PortType;

/* Type definition of a Dio Register Address ptr type, [pointer to take address of Port Reg address] */
typedef volatile uint8* Dio_RegAddressPtrType;

/* Type definition of a port type, which consist of the possible levels a DIO channel
 * can have (input or output)
 * STD_LOW  --> 0x00
 * STD_HIGH --> 0x01
 */
typedef uint8 Dio_LevelType;

/* Type definition of a port level type, which consist of Numeric ID the largest port size
 * If the uC owns ports of different port widths (e.g. 4, 8,16...Bit)
 * Dio_PortLevelType inherits the size of the largest port.
 */
typedef uint8 Dio_PortLevelType;

/* Type definition of a channel group, which consists of several adjoining channels within a port */
typedef struct
{
	/* defines the positions of the channel group */
	uint8 mask;

	/* defines the position of the Channel Group on the port, counted from the LSB */
	uint8 offset;

	/* defines port on which the Channel group is defined */
	Dio_PortType port;

}Dio_ChannelGroupType;

typedef struct
{
	Dio_ChannelType channels[DIO_NUM_OF_CONFIGURED_CHANNLES];
	Dio_PortType ports[DIO_NUM_OF_CONFIGURED_CHANNLES];
	Dio_ChannelGroupType groups[DIO_NUM_OF_CONFIGURED_CHANNLES];
}Dio_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function Declaration for DIO read Channel API */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* Function Declaration for DIO write Channel API */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/* Function Declaration for DIO read Port API */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/* Function Declaration for DIO write Port API */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/* Function Declaration for DIO read channel group API */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

/* Function Declaration for DIO write channel group API */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);

/* Function Declaration for DIO get version info API */
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo);

/* Function Declaration for DIO flip channel API */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
 extern const Dio_ConfigType Dio_Configurations;


#endif
