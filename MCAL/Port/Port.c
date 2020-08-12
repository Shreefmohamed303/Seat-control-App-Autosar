 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for Port Module.
 *
 * Author: Shreef Mohamed
 *
 * Created on: Aug 8, 2020
 *
 ******************************************************************************/
 

#include "Port.h"
#include "Dio_Regs.h"

static Port_ConfigChannelType *ConfiguredChannels;

/*******************************************************************************
 *                         Function Definitions                                *
 *******************************************************************************/

static Port_PinType Port_getPinIndex(Port_PinType pin_id)
{
	return (Port_PinType)(pin_id%NUMBER_OF_PINS_PER_PORT);
}

static Port_PortType Port_getPortID(Port_PinType pin_id)
{
	return (Port_PortType) ( (pin_id/NUMBER_OF_PINS_PER_PORT) % (NUMBER_OF_PORTS) );
}

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port Driver module.
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	Port_RegAddressPtrType Port_Ptr;
	Port_RegAddressPtrType DDR_Ptr;

	/* Pointing to Channels Configuration in ConfigPtr by ConfiguredChannels pointer */
	ConfiguredChannels=(Port_ConfigChannelType *)ConfigPtr->channels;

	for(uint8 CH_itr=0 ; CH_itr<PORT_NUM_OF_CONFIGURED_CHANNLES ; CH_itr++)
	{
		/* Switch Case to update both Port_Ptr and DDR_Ptr with the new addresses */
		switch(ConfiguredChannels[CH_itr].port)
		{
		case PORTA_ID:
					 Port_Ptr=(Port_RegAddressPtrType)PORTA_REG;
					 DDR_Ptr =(Port_RegAddressPtrType)DDRA_REG;
			break;
		case PORTB_ID:
					 Port_Ptr=(Port_RegAddressPtrType)PORTB_REG;
					 DDR_Ptr =(Port_RegAddressPtrType)DDRB_REG;
			break;
		case PORTC_ID:
					 Port_Ptr=(Port_RegAddressPtrType)PORTC_REG;
					 DDR_Ptr =(Port_RegAddressPtrType)DDRC_REG;
			break;
		case PORTD_ID:
					 Port_Ptr=(Port_RegAddressPtrType)PORTD_REG;
					 DDR_Ptr =(Port_RegAddressPtrType)DDRD_REG;
			break;
		}

		/* Switch Case to update Port Register pin with value based on its Direction */
		switch(ConfiguredChannels[CH_itr].pinDirection)
		{
		case PORT_PIN_IN:
			CLEAR_BIT(*DDR_Ptr,ConfiguredChannels[CH_itr].pin);
			if(ConfiguredChannels[CH_itr].pinPullupMode==PORT_PIN_ENABLE_PULLUP)
			{
				// Enable Internal Pull up by set Port Reg Pin
				SET_BIT(*Port_Ptr,ConfiguredChannels[CH_itr].pin);
			}
			else if(ConfiguredChannels[CH_itr].pinPullupMode==PORT_PIN_DISABLE_PULLUP)
			{
				// Enable Internal Pull up by clear Port Reg Pin
				CLEAR_BIT(*Port_Ptr,ConfiguredChannels[CH_itr].pin);
			}
			else
			{}
			break;
		case PORT_PIN_OUT:
			SET_BIT(*DDR_Ptr,ConfiguredChannels[CH_itr].pin);
			if(ConfiguredChannels[CH_itr].pinPullupMode==PORT_PIN_INITIAL_HIGH)
			{
				// Initialize The Port Register Pin level with 1
				SET_BIT(*Port_Ptr,ConfiguredChannels[CH_itr].pin);
			}
			else if(ConfiguredChannels[CH_itr].pinPullupMode==PORT_PIN_INITIAL_LOW)
			{
				// Initialize The Port Register Pin level with 0
				CLEAR_BIT(*Port_Ptr,ConfiguredChannels[CH_itr].pin);
			}
			else
			{}
			break;
		}
	}

}

/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number.
*                  Direction - Port Pin Direction.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set the port pin direction.
************************************************************************************/
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
	Port_PortType Port;
	Port_PinType PinIndex;
	Port_RegAddressPtrType DDR_Ptr;
	if(Pin>PINS_NUM)
	{
		/* @TODO Raise Error */
	}
	else
	{
		/* Get port ID */
		Port = Port_getPortID(Pin);

		/* Switch Case to update DDR_Ptr with the new addresses */
		switch(Port)
		{
		case PORTA_ID:	DDR_Ptr =(Port_RegAddressPtrType)DDRA_REG;
			break;
		case PORTB_ID:	DDR_Ptr =(Port_RegAddressPtrType)DDRB_REG;
			break;
		case PORTC_ID:	DDR_Ptr =(Port_RegAddressPtrType)DDRC_REG;
			break;
		case PORTD_ID:	DDR_Ptr =(Port_RegAddressPtrType)DDRD_REG;
			break;
		}
	}
	/* Get Pin position in its Port */
	PinIndex=Port_getPinIndex(Pin);

	if(Direction==PORT_PIN_IN)
	{
		CLEAR_BIT(*DDR_Ptr,PinIndex);
	}
	else if(Direction==PORT_PIN_OUT)
	{
		SET_BIT(*DDR_Ptr,PinIndex);
	}
	else
	{

	}
}

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Refresh port direction.
************************************************************************************/
void Port_RefreshPortDirection(void)
{
	Port_RegAddressPtrType Port_Ptr;
	Port_RegAddressPtrType DDR_Ptr;

	for(uint8 CH_itr=0 ; CH_itr<PORT_NUM_OF_CONFIGURED_CHANNLES ; CH_itr++)
	{
		if(ConfiguredChannels[CH_itr].PinDirectionChangeable==STD_ON)
		{
			/* [SWS_Port_00061]
			 * Function shall exclude those port pins from refreshing
			 * that are configured as ‘pin direction changeable during runtime‘
			 */
			continue;
		}
		else
		{
			/* Switch Case to update both Port_Ptr and DDR_Ptr with the new addresses */
			switch(ConfiguredChannels[CH_itr].port)
			{
			case PORTA_ID:
						 Port_Ptr=(Port_RegAddressPtrType)PORTA_REG;
						 DDR_Ptr =(Port_RegAddressPtrType)DDRA_REG;
				break;
			case PORTB_ID:
						 Port_Ptr=(Port_RegAddressPtrType)PORTB_REG;
						 DDR_Ptr =(Port_RegAddressPtrType)DDRB_REG;
				break;
			case PORTC_ID:
						 Port_Ptr=(Port_RegAddressPtrType)PORTC_REG;
						 DDR_Ptr =(Port_RegAddressPtrType)DDRC_REG;
				break;
			case PORTD_ID:
						 Port_Ptr=(Port_RegAddressPtrType)PORTD_REG;
						 DDR_Ptr =(Port_RegAddressPtrType)DDRD_REG;
				break;
			}

			/* Switch Case to update Port Register pin with value based on its Direction */
			switch(ConfiguredChannels[CH_itr].pinDirection)
			{
			case PORT_PIN_IN:
				CLEAR_BIT(*DDR_Ptr,ConfiguredChannels[CH_itr].pin);
				if(ConfiguredChannels[CH_itr].pinPullupMode==PORT_PIN_ENABLE_PULLUP)
				{
					// Enable Internal Pull up by set Port Reg Pin
					SET_BIT(*Port_Ptr,ConfiguredChannels[CH_itr].pin);
				}
				else if(ConfiguredChannels[CH_itr].pinPullupMode==PORT_PIN_DISABLE_PULLUP)
				{
					// Enable Internal Pull up by clear Port Reg Pin
					CLEAR_BIT(*Port_Ptr,ConfiguredChannels[CH_itr].pin);
				}
				else
				{}
				break;
			case PORT_PIN_OUT:
				SET_BIT(*DDR_Ptr,ConfiguredChannels[CH_itr].pin);
				if(ConfiguredChannels[CH_itr].pinPullupMode==PORT_PIN_INITIAL_HIGH)
				{
					// Initialize The Port Register Pin level with 1
					SET_BIT(*Port_Ptr,ConfiguredChannels[CH_itr].pin);
				}
				else if(ConfiguredChannels[CH_itr].pinPullupMode==PORT_PIN_INITIAL_LOW)
				{
					// Initialize The Port Register Pin level with 0
					CLEAR_BIT(*Port_Ptr,ConfiguredChannels[CH_itr].pin);
				}
				else
				{}
				break;
			}
		}

	}
}

/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: Function to Return the version information of this module.
************************************************************************************/
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{

}

/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin  - Port Pin ID number
* 				   Mode - New Port Pin mode to be set on port pin.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set the port pin mode.
************************************************************************************/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
	for(uint8 CH_itr=0 ; CH_itr<PORT_NUM_OF_CONFIGURED_CHANNLES ; CH_itr++)
	{
		if(ConfiguredChannels[CH_itr].PinDirectionChangeable==STD_ON)
		{
			/* [SWS_Port_00061]
			 * Function shall exclude those port pins from refreshing
			 * that are configured as ‘pin direction changeable during runtime‘
			 */
			continue;
		}
		else
		{
			/* TODO Implement pin Modes */
		}
	}
}
