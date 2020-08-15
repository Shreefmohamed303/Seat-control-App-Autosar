 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.c
 *
 * Description: Pre-Compile Configuration Source file for Port Module.
 *
 * Author: Shreef Mohamed
 *
 * Created on: Aug 10, 2020
 *
 ******************************************************************************/

#include "Port.h"

const Port_ConfigType Port_Configurations =
{
	.channels[PortConf_LED1_CHANNEL_INDEX].pin=PortConf_LED1_CHANNEL_ID,
	.channels[PortConf_LED1_CHANNEL_INDEX].port=PORT_PORTD_ID,
	.channels[PortConf_LED1_CHANNEL_INDEX].pinDirection=PORT_PIN_OUT,
	.channels[PortConf_LED1_CHANNEL_INDEX].pinInitLevel=PORT_PIN_INITIAL_HIGH
};
