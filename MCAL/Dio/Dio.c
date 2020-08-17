 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.c
 *
 * Description: Source file for Dio Module.
 *
 * Author: Shreef Mohamed
 *
 * Created on: Aug 8, 2020
 *
 ******************************************************************************/
 

#include "Dio.h"

/*******************************************************************************
 *                         Function Definitions                                *
 *******************************************************************************/
static Dio_ChannelType Dio_getPinIndex(Dio_ChannelType pin_id)
{
	return (Dio_ChannelType)(pin_id%NUMBER_OF_CHANNELS_PER_PORT);
}

static Dio_PortType Dio_getPortID(Dio_ChannelType pin_id)
{
	return (Dio_PortType) ( (pin_id/NUMBER_OF_CHANNELS_PER_PORT) % (NUMBER_OF_PORTS) );
}

/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return the value of the specified DIO channel.
************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	Dio_RegAddressPtrType Port_Ptr;
	Dio_ChannelType channelIndex;
	Dio_PortType port;
	Dio_LevelType result=0;

	if(ChannelId>TOTAL_NUM_OF_PINS)
	{
		/* @TODO Raise Error */
	}
	else
	{
		/* Get Port ID */
		port=Dio_getPortID(ChannelId);

		/* Switch Case to update DDR_Ptr with the new addresses */
		switch(port)
		{
		case DIO_PORTA_ID:	Port_Ptr =(Dio_RegAddressPtrType)PINA_REG;
			break;
		case DIO_PORTB_ID:	Port_Ptr =(Dio_RegAddressPtrType)PINB_REG;
			break;
		case DIO_PORTC_ID:	Port_Ptr =(Dio_RegAddressPtrType)PINC_REG;
			break;
		case DIO_PORTD_ID:	Port_Ptr =(Dio_RegAddressPtrType)PIND_REG;
			break;
		}

		/* Get Channel index in The port */
		channelIndex=Dio_getPinIndex(ChannelId);

		/* Get Channel Reading */
		result= (Dio_LevelType) GET_BIT(*Port_Ptr,channelIndex);
	}
	return result;
}

/************************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	Dio_RegAddressPtrType Port_Ptr;
	Dio_ChannelType channelIndex;
	Dio_PortType port;

	if(ChannelId>TOTAL_NUM_OF_PINS)
	{
		/* @TODO Raise Error */
	}
	else
	{
		/* Get Port ID */
		port=Dio_getPortID(ChannelId);

		/* Switch Case to update DDR_Ptr with the new addresses */
		switch(port)
		{
		case DIO_PORTA_ID:	Port_Ptr =(Dio_RegAddressPtrType)PORTA_REG;
			break;
		case DIO_PORTB_ID:	Port_Ptr =(Dio_RegAddressPtrType)PORTB_REG;
			break;
		case DIO_PORTC_ID:	Port_Ptr =(Dio_RegAddressPtrType)PORTC_REG;
			break;
		case DIO_PORTD_ID:	Port_Ptr =(Dio_RegAddressPtrType)PORTD_REG;
			break;
		}

		/* Get Channel index in The port */
		channelIndex=Dio_getPinIndex(ChannelId);

		/* Set Channel Level */
		switch(Level)
		{
		case STD_HIGH: 	SET_BIT(*Port_Ptr,channelIndex);
			break;
		case STD_LOW: 	CLEAR_BIT(*Port_Ptr,channelIndex);
			break;
		}
	}
}

/************************************************************************************
* Service Name: Dio_ReadPort
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO Port.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType
* Description: Function to Return the level of all channels of that port.
************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	Dio_ChannelType NumOfChannels=0;
	Dio_RegAddressPtrType DataReg_Ptr;
	Dio_PortLevelType result;

	if(PortId>NUMBER_OF_PORTS)
	{

	}
	else
	{
		/* Get Number of channels based on Port & update DataReg_Ptr with the new address*/
		switch(PortId)
		{
		case DIO_PORTA_ID: NumOfChannels = DIO_PORTA_NUM_OF_CHANNELS;
						   DataReg_Ptr = (Dio_RegAddressPtrType)PINA_REG;
			break;
		case DIO_PORTB_ID: NumOfChannels = DIO_PORTB_NUM_OF_CHANNELS;
						   DataReg_Ptr = (Dio_RegAddressPtrType)PINB_REG;
			break;
		case DIO_PORTC_ID: NumOfChannels = DIO_PORTC_NUM_OF_CHANNELS;
		   	   	   	   	   DataReg_Ptr = (Dio_RegAddressPtrType)PINC_REG;
			break;
		case DIO_PORTD_ID: NumOfChannels = DIO_PORTD_NUM_OF_CHANNELS;
		   	   	   	   	   DataReg_Ptr = (Dio_RegAddressPtrType)PIND_REG;
			break;
		}

		result=*DataReg_Ptr;
	}

	return result;
}

/************************************************************************************
* Service Name: Dio_WritePort
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO Port.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set all Channels level of that port.
************************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
	Dio_ChannelType NumOfChannels=0;
	Dio_RegAddressPtrType DataReg_Ptr;

	if(PortId>NUMBER_OF_PORTS)
	{

	}
	else
	{
		/* Get Number of channels based on Port & update DataReg_Ptr with the new address*/
		switch(PortId)
		{
		case DIO_PORTA_ID: NumOfChannels = DIO_PORTA_NUM_OF_CHANNELS;
						   DataReg_Ptr = (Dio_RegAddressPtrType)PORTA_REG;
			break;
		case DIO_PORTB_ID: NumOfChannels = DIO_PORTB_NUM_OF_CHANNELS;
						   DataReg_Ptr = (Dio_RegAddressPtrType)PORTB_REG;
			break;
		case DIO_PORTC_ID: NumOfChannels = DIO_PORTC_NUM_OF_CHANNELS;
		   	   	   	   	   DataReg_Ptr = (Dio_RegAddressPtrType)PORTC_REG;
			break;
		case DIO_PORTD_ID: NumOfChannels = DIO_PORTD_NUM_OF_CHANNELS;
		   	   	   	   	   DataReg_Ptr = (Dio_RegAddressPtrType)PORTD_REG;
			break;
		}

		*DataReg_Ptr=Level;
	}

}

/************************************************************************************
* Service Name: Dio_ReadChannelGroup
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelGroupIdPtr - Pointer to ChannelGroup.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType
* Description: Function to  read a subset of the adjoining bits of a port.
************************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
	Dio_ChannelType NumOfChannels=0;
	Dio_RegAddressPtrType DataReg_Ptr;
	Dio_PortType PortId=ChannelGroupIdPtr->port;
	uint8 mask= ChannelGroupIdPtr->mask;
	//uint8 offset= ChannelGroupIdPtr->offset;
	Dio_PortLevelType result;

	if(PortId>NUMBER_OF_PORTS)
	{

	}
	else
	{
		/* Get Number of channels based on Port & update DataReg_Ptr with the new address*/
		switch(PortId)
		{
		case DIO_PORTA_ID: NumOfChannels = DIO_PORTA_NUM_OF_CHANNELS;
						   DataReg_Ptr = (Dio_RegAddressPtrType)PINA_REG;
			break;
		case DIO_PORTB_ID: NumOfChannels = DIO_PORTB_NUM_OF_CHANNELS;
						   DataReg_Ptr = (Dio_RegAddressPtrType)PINB_REG;
			break;
		case DIO_PORTC_ID: NumOfChannels = DIO_PORTC_NUM_OF_CHANNELS;
		   	   	   	   	   DataReg_Ptr = (Dio_RegAddressPtrType)PINC_REG;
			break;
		case DIO_PORTD_ID: NumOfChannels = DIO_PORTD_NUM_OF_CHANNELS;
		   	   	   	   	   DataReg_Ptr = (Dio_RegAddressPtrType)PIND_REG;
			break;
		}

		result = (Dio_PortLevelType)(*DataReg_Ptr & mask);
	}

	return result;
}

/************************************************************************************
* Service Name: Dio_WriteChannelGroup
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelGroupIdPtr - Pointer to ChannelGroup.
* 					Level -Value to be written
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType
* Description: Function to set a subset of the adjoining bits of a port to a specified level.
************************************************************************************/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level)
{
	Dio_ChannelType NumOfChannels=0;
	Dio_RegAddressPtrType DataReg_Ptr;
	Dio_PortType PortId=ChannelGroupIdPtr->port;
	uint8 mask= ChannelGroupIdPtr->mask;
	uint8 offset= ChannelGroupIdPtr->offset;

	if(PortId>NUMBER_OF_PORTS)
	{

	}
	else
	{
		/* Get Number of channels based on Port & update DataReg_Ptr with the new address*/
		switch(PortId)
		{
		case DIO_PORTA_ID: NumOfChannels = DIO_PORTA_NUM_OF_CHANNELS;
						   DataReg_Ptr = (Dio_RegAddressPtrType)PORTA_REG;
			break;
		case DIO_PORTB_ID: NumOfChannels = DIO_PORTB_NUM_OF_CHANNELS;
						   DataReg_Ptr = (Dio_RegAddressPtrType)PORTB_REG;
			break;
		case DIO_PORTC_ID: NumOfChannels = DIO_PORTC_NUM_OF_CHANNELS;
						   DataReg_Ptr = (Dio_RegAddressPtrType)PORTC_REG;
			break;
		case DIO_PORTD_ID: NumOfChannels = DIO_PORTD_NUM_OF_CHANNELS;
						   DataReg_Ptr = (Dio_RegAddressPtrType)PORTD_REG;
			break;
		}

		*DataReg_Ptr = (Level<<offset) | (*DataReg_Ptr & (~mask));
	}

}

/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x12
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: Function to Return the version information of this module.
************************************************************************************/
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{

}


/************************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x11
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to flip the level of a channel and return the level of the channel after flip.
************************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	Dio_LevelType result;

	return result;
}
