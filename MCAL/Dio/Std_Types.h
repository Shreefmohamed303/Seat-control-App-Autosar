/**
 *
 * \brief Sprints AUTOSAR Master Class - SeatCtrlApp
 * \author Hassan Farahat
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */
 
#ifndef STD_TYPES_H
#define STD_TYPES_H

/* Platform Types */
typedef signed char         sint8;
typedef unsigned char       uint8;
typedef signed short        sint16;
typedef unsigned short      uint16;
typedef signed long         sint32;
typedef unsigned long       uint32;
typedef float               float32;
typedef double              float64;
typedef unsigned char       boolean;

/* AUTOSAR Types */
typedef uint8 Std_ReturnType;

/* AUTOSAR Defines */
#define TRUE      			1U
#define FALSE     			0U
#define E_NOT_OK    		1U
#define E_OK      			0U
#define STD_HIGH    		1U
#define STD_LOW     		0U
#define E_OK			0U
#define E_NOK			1U

/* Recently Added Types */
#define NULL
#define STD_ON			0x01
#define STD_OFF			0x00

typedef struct {
	// TODO: not done!!
	uint16 vendorID;
	uint16 moduleID;
	uint8  instanceID;

	uint8 sw_major_version;    /**< Vendor numbers */
	uint8 sw_minor_version;    /**< Vendor numbers */
	uint8 sw_patch_version;    /**< Vendor numbers */

	uint8 ar_major_version;    /**< Autosar spec. numbers */
	uint8 ar_minor_version;    /**< Autosar spec. numbers */
	uint8 ar_patch_version;    /**< Autosar spec. numbers */
} Std_VersionInfoType;

#endif
