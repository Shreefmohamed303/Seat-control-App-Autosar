 /******************************************************************************
 *
 * Module: Dio_PBcfg
 *
 * File Name: Dio_PBcfg.c
 *
 * Description: Source file for Post Build Configuration of Dio Module.
 *
 * Author: Shreef Mohamed
 *
 * Created on: Aug 14, 2020
 *
 ******************************************************************************/

#include "Dio.h"

const Dio_ConfigType Dio_Configurations =
{
	.channels[DioConf_LED1_CHANNEL_INDEX]=DioConf_LED1_CHANNEL_ID,
	.channels[DioConf_LED2_CHANNEL_INDEX]=DioConf_LED2_CHANNEL_ID,

	.ports[DioConf_LED1_PORT_INDEX]=DioConf_LED1_PORT_ID,
	.ports[DioConf_LED2_PORT_INDEX]=DioConf_LED2_PORT_ID
};




