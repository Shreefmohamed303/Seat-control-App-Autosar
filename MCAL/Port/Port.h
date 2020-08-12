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

/*********************************************************************************
 * 						PIN Definitions 										 *
 ********************************************************************************/

#define PORTA_ID					(0U)
#define PORTB_ID					(1U)
#define PORTC_ID					(2U)
#define PORTD_ID					(3U)

#define PORT_PIN0 					(Port_PinType)0
#define PORT_PIN1 					(Port_PinType)1
#define PORT_PIN2 					(Port_PinType)2
#define PORT_PIN3 					(Port_PinType)3
#define PORT_PIN4 					(Port_PinType)4
#define PORT_PIN5 					(Port_PinType)5
#define PORT_PIN6 					(Port_PinType)6
#define PORT_PIN7 					(Port_PinType)7

#define PINS_NUM					(32U)
#define NUMBER_OF_PINS_PER_PORT		(8U)
#define NUMBER_OF_PORTS				(4U)

//#define PORT_A_FIRST_ID				(0U)
//#define PORT_A_LAST_ID				(7U)
//
//#define PORT_B						(1U)
//#define PORT_B_FIRST_ID				(8U)
//#define PORT_B_LAST_ID				(15U)
//
//#define PORT_C						(2U)
//#define PORT_C_FIRST_ID				(16U)
//#define PORT_C_LAST_ID				(23U)

#define PORT_D						(3U)
#define PORT_D_FIRST_ID				(24U)
#define PORT_D_LAST_ID				(31U)

#define PIN_0						(0U)//A
#define PIN_1						(1U)
#define PIN_2						(2U)
#define PIN_3						(3U)
#define PIN_4						(4U)
#define PIN_5						(5U)
#define PIN_6						(6U)
#define PIN_7						(7U)
#define PIN_8						(8U)//B
#define PIN_9						(9U)
#define PIN_10						(10U)
#define PIN_11						(11U)
#define PIN_12						(12U)
#define PIN_13						(13U)
#define PIN_14						(14U)
#define PIN_15						(15U)
#define PIN_16						(16U)//c
#define PIN_17						(17U)
#define PIN_18						(18U)
#define PIN_19						(19U)
#define PIN_20						(20U)
#define PIN_21						(21U)
#define PIN_22						(22U)
#define PIN_23						(23U)
#define PIN_24						(24U)//D
#define PIN_25						(25U)
#define PIN_26						(26U)
#define PIN_27						(27U)
#define PIN_28						(28U)
#define PIN_29						(29U)
#define PIN_30						(30U)
#define PIN_31						(31U)


#endif
