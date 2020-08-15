 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for Port Module.
 *
 * Author: Shreef Mohamed
 *
 * Created on: Aug 10, 2020
 *
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H


#define PORT_NUM_OF_CONFIGURED_CHANNLES		2

#define PortConf_LED1_CHANNEL_INDEX			0
#define PortConf_LED1_CHANNEL_ID			PORT_PIN_24
#define PortConf_LED1_PORT_ID				PORT_PORTD_ID
#define PortConf_LED1_DIRECTION				PORT_PIN_OUT
#define PortConf_LED1_INIT_VALUE			PORT_PIN_INITIAL_LOW

#define PortConf_LED2_CHANNEL_INDEX			1
#define PortConf_LED2_CHANNEL_ID			PORT_PIN_25
#define PortConf_LED2_PORT_ID				PORT_PORTD_ID
#define PortConf_LED2_DIRECTION				PORT_PIN_OUT
#define PortConf_LED2_INIT_VALUE			PORT_PIN_INITIAL_HIGH

/*********************************************************************************
 * 						PIN Definitions 										 *
 ********************************************************************************/

#define PORT_PORTA_ID					(0U)
#define PORT_PORTB_ID					(1U)
#define PORT_PORTC_ID					(2U)
#define PORT_PORTD_ID					(3U)


#define PINS_NUM						(32U)
#define NUMBER_OF_PINS_PER_PORT			(8U)
#define NUMBER_OF_PORTS					(4U)

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

//#define PORT_D						(3U)
//#define PORT_D_FIRST_ID				(24U)
//#define PORT_D_LAST_ID				(31U)

#define PORT_PIN_0						(0U)//A
#define PORT_PIN_1						(1U)
#define PORT_PIN_2						(2U)
#define PORT_PIN_3						(3U)
#define PORT_PIN_4						(4U)
#define PORT_PIN_5						(5U)
#define PORT_PIN_6						(6U)
#define PORT_PIN_7						(7U)
#define PORT_PIN_8						(8U)//B
#define PORT_PIN_9						(9U)
#define PORT_PIN_10						(10U)
#define PORT_PIN_11						(11U)
#define PORT_PIN_12						(12U)
#define PORT_PIN_13						(13U)
#define PORT_PIN_14						(14U)
#define PORT_PIN_15						(15U)
#define PORT_PIN_16						(16U)//c
#define PORT_PIN_17						(17U)
#define PORT_PIN_18						(18U)
#define PORT_PIN_19						(19U)
#define PORT_PIN_20						(20U)
#define PORT_PIN_21						(21U)
#define PORT_PIN_22						(22U)
#define PORT_PIN_23						(23U)
#define PORT_PIN_24						(24U)//D
#define PORT_PIN_25						(25U)
#define PORT_PIN_26						(26U)
#define PORT_PIN_27						(27U)
#define PORT_PIN_28						(28U)
#define PORT_PIN_29						(29U)
#define PORT_PIN_30						(30U)
#define PORT_PIN_31						(31U)


#endif



