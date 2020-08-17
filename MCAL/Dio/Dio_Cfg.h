/*
 * Dio_Cfg.h
 *
 *  Created on: Aug 12, 2020
 *      Author: LENOVO
 */

#ifndef MCAL_DIO_DIO_CFG_H_
#define MCAL_DIO_DIO_CFG_H_

#include "Dio.h"

#define DIO_NUM_OF_CONFIGURED_CHANNLES		2

#define DioConf_LED1_CHANNEL_INDEX			0
#define DioConf_LED2_CHANNEL_INDEX			1

#define DioConf_LED1_CHANNEL_ID				DIO_ID_0
#define DioConf_LED2_CHANNEL_ID				DIO_ID_1

#define DioConf_LED1_PORT_INDEX				0
#define DioConf_LED2_PORT_INDEX				1

#define DioConf_LED1_PORT_ID				DIO_PORTA_ID
#define DioConf_LED2_PORT_ID				DIO_PORTA_ID

/*********************************************************************************
 * 						    PIN Definitions 								     *
 ********************************************************************************/
#define TOTAL_NUM_OF_PINS			(32U)
#define NUMBER_OF_CHANNELS_PER_PORT	(8U)
#define NUMBER_OF_PORTS				(4U)

#define DIO_PORTA_NUM_OF_CHANNELS	(8U)
#define DIO_PORTB_NUM_OF_CHANNELS	(8U)
#define DIO_PORTC_NUM_OF_CHANNELS	(8U)
#define DIO_PORTD_NUM_OF_CHANNELS	(8U)

#define DIO_PORTA_ID				(0U)
#define DIO_PORTB_ID				(1U)
#define DIO_PORTC_ID				(2U)
#define DIO_PORTD_ID				(3U)

#define DIO_ID_0					(0U)//A
#define DIO_ID_1					(1U)
#define DIO_ID_2					(2U)
#define DIO_ID_3					(3U)
#define DIO_ID_4					(4U)
#define DIO_ID_5					(5U)
#define DIO_ID_6					(6U)
#define DIO_ID_7					(7U)
#define DIO_ID_8					(8U)//B
#define DIO_ID_9					(9U)
#define DIO_ID_10					(10U)
#define DIO_ID_11					(11U)
#define DIO_ID_12					(12U)
#define DIO_ID_13					(13U)
#define DIO_ID_14					(14U)
#define DIO_ID_15					(15U)
#define DIO_ID_16					(16U)//c
#define DIO_ID_17					(17U)
#define DIO_ID_18					(18U)
#define DIO_ID_19					(19U)
#define DIO_ID_20					(20U)
#define DIO_ID_21					(21U)
#define DIO_ID_22					(22U)
#define DIO_ID_23					(23U)
#define DIO_ID_24					(24U)//D
#define DIO_ID_25					(25U)
#define DIO_ID_26					(26U)
#define DIO_ID_27					(27U)
#define DIO_ID_28					(28U)
#define DIO_ID_29					(29U)
#define DIO_ID_30					(30U)
#define DIO_ID_31					(31U)

#endif /* MCAL_DIO_DIO_CFG_H_ */
