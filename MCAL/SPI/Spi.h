 /******************************************************************************
 *
 * Module: Spi
 *
 * File Name: Spi.h
 *
 * Description: Header file for Spi Module.
 *
 * Author: Shreef Mohamed
 *
 * Created on: Aug 16, 2020
 *
 ******************************************************************************/
#ifndef SPI_H
#define SPI_H



/* Standard AUTOSAR types */
#include "Std_Types.h"


/* Port Pre-Compile Configuration Header file */
#include "Spi_Cfg.h"

/* Non AUTOSAR files */
#include "common_macros.h"
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for Spi init */
#define SPI_INIT_SID 		           	(uint8)0x00

/* Service ID for Spi Deinit */
#define SPI_DEINIT_SID			    	(uint8)0x01

/* Service ID for Port Refresh Port Direction */
#define PORT_REFRESH_PORT_DIR_SID      	(uint8)0x02

/* Service ID for Port GetVersionInfo */
#define PORT_GET_VERSION_INFO_SID      	(uint8)0x03

/* Service ID for Port SetPinMode */
#define PORT_SET_PIN_MODE_SID 	       	(uint8)0x04



/*******************************************************************************
 *                        DET Error Codes                                      *
 *******************************************************************************/

/* DET code to report [Invalid channel ID requested] */
#define SPI_E_PARAM_CHANNEL				0x0A

/* DET code to report [Invalid job ID requested] */
#define SPI_E_PARAM_JOB					0x0B

/* DET code to report [Invalid SEQ ID requested] */
#define SPI_E_PARAM_SEQ					0x0C

/* DET code to report [API service called with wrong parameter] */
#define SPI_E_PARAM_LENGTH				0x0D

/* DET code to report [API service called with wrong parameter] */
#define SPI_E_PARAM_UNIT				0x0E

/* DET code to report [APIs called with a Null Pointer] */
#define SPI_E_PARAM_POINTER				0x10

/* DET code to report [API service used without module initialization] */
#define SPI_E_UNINIT					0x1A

/* DET code to report [Services called in a wrong sequence] */
#define SPI_E_SEQ_PENDING				0x2A

/* DET code to report [Synchronous transmission service called at wrong time] */
#define SPI_E_SEQ_IN_PROCESS			0x3A

/* DET code to report [API SPI_Init service called while the SPI driver has already been initialized] */
#define SPI_E_ALREADY_INITIALIZED		0x4A

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition of a range of specific status for SPI Handler/Driver */
typedef enum
{
	SPI_UNINIT, // The SPI Handler/Driver is not initialized or not usable.
	SPI_IDLE,   // The SPI Handler/Driver is not currently transmitting any Job.
	SPI_BUSY    // The SPI Handler/Driver is performing a SPI Job (transmit).
}Spi_StatusType;

/* Type definition of a range of specific Jobs status for SPI Handler/Driver */
typedef enum
{
	SPI_JOB_OK,		 //The last transmission of the Job has been finished success-fully.
	SPI_JOB_PENDING, //The SPI Handler/Driver is performing a SPI Job.this status is equal to SPI_BUSY
	SPI_JOB_FAILED,  //The last transmission of the Job has failed.
	SPI_JOB_QUEUEDAn //Asynchronous transmit Job has been accepted,
					 //while actual transmission for this Job has not started yet.
}Spi_JobResultType;

/* Type definition of a range of specific Sequences status for SPI Handler/Driver */
typedef enum
{
	SPI_SEQ_OK,      //The last transmission of the Sequence has been finished successfully.
	SPI_SEQ_PENDING, //The SPI Handler/Driver is performing a SPI Sequence.is equal to SPI_BUSY.
	SPI_SEQ_FAILED,  //The last transmission of the Sequence has failed.
	SPI_SEQ_CANCELED //The last transmission of the Sequence has been canceled by user.
}Spi_SeqResultType;

/* Type of application data buffer elements */
typedef uint8 Spi_DataBufferType;

/* Type for defining the number of data elements of the type Spi_DataBufferType
 * to send / receive by Channel
 */
typedef uint16 Spi_NumberOfDataType;

/* Type definition Specifies the identification (ID) for a Channel */
typedef uint8 Spi_ChannelType;

/* Type definition Specifies the identification (ID) for a Job */
typedef uint8 Spi_JobType;

/* Type definition Specifies the identification (ID) for a sequence of jobs */
typedef uint8 Spi_SequenceType;

/* Type definition Specifies the identification (ID) for a SPI HW microcontroller peripheral (unit) */
typedef uint8 Spi_HWUnitType;

typedef enum
{
	/*The asynchronous mechanism is ensured by polling,
	 *So interrupts related to SPI busses handled asynchronously are disabled
	 */
	SPI_POLLING_MODE,

	 /* The asynchronous mechanism is ensured by interrupt,
	 * So interrupts related to SPI busses handled asynchronously are enabled.
	 */
	SPI_INTERRUPT_MODE
}Spi_AsyncModeType;

typedef struct
{

}Spi_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
void Spi_Init(const Spi_ConfigType* ConfigPtr);
Std_ReturnType Spi_DeInit(void);
Std_ReturnType Spi_WriteIB(Spi_ChannelType Channel, const Spi_DataBufferType* DataBufferPtr);
Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence);
Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel, Spi_DataBufferType* DataBufferPointer);
Std_ReturnType Spi_SetupEB( Spi_ChannelType Channel,
							const Spi_DataBufferType* SrcDataBufferPtr,
							Spi_DataBufferType* DesDataBufferPtr,
							Spi_NumberOfDataType Length);
Spi_StatusType Spi_GetStatus(void);
Spi_JobResultType Spi_GetJobResult(Spi_JobType Job);
Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence);
void Spi_GetVersionInfo(Std_VersionInfoType* versioninfo);
Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence);
Spi_StatusType Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit);
void Spi_Cancel(Spi_SequenceType Sequence);
Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode);
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

#endif
