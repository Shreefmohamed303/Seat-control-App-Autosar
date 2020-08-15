 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for Port Module.
 *
 * Author: Shreef Mohamed
 *
 * Created on: Aug 10, 2020
 *
 ******************************************************************************/
#ifndef PORT_H
#define PORT_H



/* Standard AUTOSAR types */
#include "Std_Types.h"


/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* Non AUTOSAR files */
#include "common_macros.h"
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for Port init */
#define PORT_INIT_SID 		           (uint8)0x00

/* Service ID for Port Set Pin Direction */
#define PORT_SET_PIN_DIRECTION_SID     (uint8)0x01

/* Service ID for Port Refresh Port Direction */
#define PORT_REFRESH_PORT_DIR_SID      (uint8)0x02

/* Service ID for Port GetVersionInfo */
#define PORT_GET_VERSION_INFO_SID      (uint8)0x03

/* Service ID for Port SetPinMode */
#define PORT_SET_PIN_MODE_SID 	       (uint8)0x04



/*******************************************************************************
 *                        DET Error Codes                                      *
 *******************************************************************************/

/* DET code to report [Invalid Port Pin ID requested] */
#define PORT_E_PARAM_PIN				0x0A

/* DET code to report [Port Pin not configured as changeable] */
#define PORT_E_DIRECTION_UNCHANGEABLE	0x0B

/* DET code to report [API Port_Init service called with wrong parameter] */
#define PORT_E_INIT_FAILED				0x0C

/* DET code to report [API Port_SetPinMode service called when mode is unchangeable] */
#define PORT_E_PARAM_INVALID_MODE		0x0D

/* DET code to report [API Port_SetPinMode service called when mode is unchangeable] */
#define PORT_E_MODE_UNCHANGEABLE		0x0E

/* DET code to report [API service called without module initialization] */
#define PORT_E_UNINIT					0x0F

/* DET code to report [APIs called with a Null Pointer] */
#define PORT_E_PARAM_POINTER			0x10

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition of a port pin type, [Data type for the symbolic name of a port pin] */
typedef uint8 Port_PinType;

/* Type definition of a port type, [Data type for the symbolic name of the port of the pin] */
typedef enum
{
	PORTA_ID,
	PORTB_ID,
	PORTC_ID,
	PORTD_ID
}Port_PortType;

/* Type definition of a port Register Address ptr type, [pointer to take address of Port Reg address] */
typedef volatile uint8* Port_RegAddressPtrType;

/* Type definition of a Port Pin Mode, One of the Different port pin modes Pin mode (e.g. DIO, ADC, SPI …) */
typedef uint8 Port_PinModeType;

/* Type definition of a Pin direction changeable, ability to change pin Direction --> [STD_ON , STD_OFF] */
typedef uint8 Port_PinDirectionChangeable;

/* Type definition of a Pin Mode changeable, ability to change pin Mode --> [STD_ON , STD_OFF] */
typedef uint8 Port_PinModeChangeable;

/* Type definition of a port pin Direction type, which consist of the possible levels a PORT Pin
 * can have (input or output)
 * PORT_PIN_IN  --> 0x00
 * PORT_PIN_OUT --> 0x01
 */
typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT
}Port_PinDirectionType;

/* Type definition of a port input Mode Type */
typedef enum {
	PORT_PIN_DISABLE_PULLUP,
	PORT_PIN_ENABLE_PULLUP
} Port_PullupModeType;

/* Type definition of a port output Mode Type Initial */
typedef enum {
	PORT_PIN_INITIAL_LOW,
	PORT_PIN_INITIAL_HIGH
} Port_InitLevelType;


/* Type definition of a port Config type, which consists of several adjoining channels within a port */
typedef struct
{
	/* defines the pin symbolic Name of the port pin */
	Port_PinType pin;

	/* defines the pin symbolic Name of the port of the used pin */
	Port_PortType port;

	/* defines the Direction of the port pin */
	Port_PinDirectionType pinDirection;

	/* defines the pin mode of the port pin */
	Port_PinModeType pinMode;

	Port_PullupModeType pinPullupMode;

	Port_InitLevelType pinInitLevel;

	Port_PinDirectionChangeable PinDirectionChangeable;

	Port_PinModeChangeable PinModeChangeable;

}Port_ConfigChannelType;


typedef struct
{
	Port_ConfigChannelType	channels[PORT_NUM_OF_CONFIGURED_CHANNLES];
}Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function Declaration for PORT Init API */
void Port_Init(const Port_ConfigType* ConfigPtr);

/* Function Declaration for PORT set pin Direction API */
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);

/* Function Declaration for PORT set Refresh Direction Port API */
void Port_RefreshPortDirection(void);

/* Function Declaration for PORT get version info API */
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);

/* Function Declaration for PORTset pin mode API */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
 extern const Port_ConfigType Port_Configurations;

#endif
