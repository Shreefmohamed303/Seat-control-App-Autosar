 /******************************************************************************
 *
 * Module: Dio_Regs
 *
 * File Name: Dio_Regs.h
 *
 * Description: Definitions of Dio Registers addresses in Micro-controller unit [Atmega16]
 *
 * Author: Shreef Mohamed
 *
 * Created on: Aug 10, 2020
 *
 ******************************************************************************/

#ifndef MCAL_PORT_DIO_REGS_H_
#define MCAL_PORT_DIO_REGS_H_

/* Definition of PORTA Registers */
#define PORTA_REG	((uint8)0x3B)
#define DDRA_REG	((uint8)0x3A)
#define PINA_REG 	((uint8)0x39)

/* Definition of PORTB Registers */
#define PORTB_REG	((uint8)0x38)
#define DDRB_REG	((uint8)0x37)
#define PINB_REG 	((uint8)0x36)

/* Definition of PORTC Registers */
#define PORTC_REG	((uint8)0x35)
#define DDRC_REG	((uint8)0x34)
#define PINC_REG 	((uint8)0x33)

/* Definition of PORTD Registers */
#define PORTD_REG	((uint8)0x32)
#define DDRD_REG	((uint8)0x31)
#define PIND_REG 	((uint8)0x30)

#endif /* MCAL_PORT_DIO_REGS_H_ */
