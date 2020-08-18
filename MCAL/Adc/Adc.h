 /******************************************************************************
 *
 * Module: Adc
 *
 * File Name: Adc.h
 *
 * Description: Header file for Adc Module.
 *
 * Author: Shreef Mohamed
 *
 * Created on: Aug 18, 2020
 *
 ******************************************************************************/
#ifndef ADC_H
#define ADC_H



/* Standard AUTOSAR types */
#include "Adc_Cfg.h"
#include "Std_Types.h"


/* Port Pre-Compile Configuration Header file */
#include "common_macros.h"
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for Adc init */
#define ADC_INIT_SID 		           	(uint8)0x00

/* Service ID for */

/* Service ID for */

/* Service ID for */

/* Service ID for */

/* Service ID for */

/* Service ID for */

/* Service ID for */


/*******************************************************************************
 *                        DET Error Codes                                      *
 *******************************************************************************/

/* DET code to report [] */
#define ADC_E_UNINIT					0x0A

/* DET code to report [] */
#define ADC_E_BUSY						0x0B

/* DET code to report [] */
#define ADC_E_IDLE						0x0C

/* DET code to report [] */
#define ADC_E_ALREADY_INITIALIZED		0x0D

/* DET code to report [] */
#define ADC_E_PARAM_POINTER				0x0E

/* DET code to report [] */
#define ADC_E_PARAM_POINTER				0x14

/* DET code to report [] */
#define ADC_E_PARAM_GROUP				0x15

/* DET code to report [] */
#define ADC_E_WRONG_CONV_MODE			0x16

/* DET code to report [] */
#define ADC_E_WRONG_TRIGG_SRC			0x17

/* DET code to report [] */
#define ADC_E_NOTIF_CAPABILITY			0x18

/* DET code to report [] */
#define ADC_E_BUFFER_UNINIT				0x19

/* DET code to report [] */
#define ADC_E_NOT_DISENGAGED			0x1A

/* DET code to report [] */
#define ADC_E_POWER_STATE_NOT_SUPPORTED 0x1B

/* DET code to report [] */
#define ADC_E_TRANSITION_NOT_POSSIBLE	0x1C

/* DET code to report [] */
#define ADC_E_PERIPHERAL_NOT_PREPARED	0x1D

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition of a Numeric ID of an ADC channel */
typedef uint8 Adc_ChannelType;

/* Type definition of a Numeric ID of an ADC channel Group */
typedef uint8 Adc_GroupType;

/* Type definition of reading the converted values of a channel group */
typedef sint16 Adc_ValueGroupType;

/* Type definition of Type of clock prescaler factor */
typedef uint16 Adc_PrescaleType;

/* Type definition of Type of conversion time,
 * time during which the sampled analog value is converted into digital representation */
typedef uint16 Adc_ConversionTimeType;

/* Type definition of Type of sampling time ,
 * i.e. the time during which the value is sampled, (in clock-cycles) */
typedef uint16 Adc_SamplingTimeType;

/* Type definition of Type of channel resolution in number of bits */
typedef uint8 Adc_ResolutionType;

/* Type definition of Current status of the conversion of the requested ADC Channel group */
typedef enum
{
	ADC_IDLE, //The conversion of the specified group has not been started (No result)
	ADC_BUSY, //The conversion of the specified group has been started and is still going on (No result)
	ADC_COMPLETED, //conversion round (not the final one) of the specified group has been finished
	ADC_STREAM_COMPLETED//Each channel of the selected group the number of samples to be acquired is available
}Adc_StatusType;

/* Type definition for configuring the trigger source for an ADC Channel group */
typedef enum
{
	ADC_TRIGG_SRC_SW, //Group is triggered by a software API call
	ADC_TRIGG_SRC_HW  //Group is triggered by a hardware event
}Adc_TriggerSourceType;

/* Type definition for configuring the conversion mode of an ADC Channel group */
typedef enum
{
	ADC_CONV_MODE_ONESHOT,
	ADC_CONV_MODE_CONTINUOUS
}Adc_GroupConvModeType;

/* Type definition for Priority level of the channel. Lowest priority is 0 */
typedef uint8 Adc_GroupPriorityType;

/* @TODO Type definition for?? */
typedef uint8 Adc_GroupDefType;

/*Type for configuring the number of group conversions in streaming access mode
 *(in single access mode, parameter is 1)*/
typedef uint8 Adc_StreamNumSampleType;

/* Type definition for configuring the streaming access mode buffer type */
typedef enum
{
	/*The ADC Driver stops the conversion as soon as the stream buffer is full (number of samples reached)*/
	ADC_STREAM_BUFFER_LINEAR,
	/*The ADC Driver continues the conversion even if the stream buffer is full (number of samples reached)*/
	ADC_STREAM_BUFFER_CIRCULAR
}Adc_StreamBufferModeType;

/* Type definition for configuring the access mode to group conversion results */
typedef enum
{
	ADC_ACCESS_MODE_SINGLE,   //Single value access mode.
	ADC_ACCESS_MODE_STREAMING //Streaming access mode.
}Adc_GroupAccessModeType;

/* Type for configuring on which edge of the hardware trigger signal the driver should react,
 * i.e. start the conversion (Only if supported by ADC Hardware )
 */
typedef enum
{
	/* Only if supported by ADC Hardware*/
	ADC_HW_TRIG_RISING_EDGE,//React on the rising edge of the hardware trigger signal
	ADC_HW_TRIG_FALLING_EDGE,//React on the falling edge of the hardware trigger signal
	ADC_HW_TRIG_BOTH_EDGES //React on both edges of the hardware trigger signal
}Adc_HwTriggerSignalType;

/* Type definition Type for the reload value of the ADC module embedded timer
 * (only if supported by the ADC hardware)
 */
typedef uint8 Adc_HwTriggerTimerType;

/* Type definition Type for configuring the prioritization mechanism */
typedef enum
{
	ADC_PRIORITY_NONE,  //priority mechanism is not available
	ADC_PRIORITY_HW,	//Hardware priority mechanism is available only
	ADC_PRIORITY_HW_SW	//Hardware and software priority mechanism is available
}Adc_PriorityImplementationType;

/* Replacement mechanism, which is used on ADC group level,
 * if a group conversion is interrupted by a group which has a higher priority
 */
typedef enum
{
	ADC_GROUP_REPL_ABORT_RESTART,
	ADC_GROUP_REPL_SUSPEND_RESUME
}Adc_GroupReplacementType;

typedef enum
{
	ADC_RANGE_UNDER_LOW,
	ADC_RANGE_BETWEEN,
	ADC_RANGE_OVER_HIGH,
	ADC_RANGE_ALWAYS,
	ADC_RANGE_NOT_UNDER_LOW,
	ADC_RANGE_NOT_BETWEEN,
	ADC_RANGE_NOT_OVER_HIGH
}Adc_ChannelRangeSelectType;

/* Type definition Type for alignment of ADC raw results in ADC result buffer (left/right alignment) */
typedef enum
{
	ADC_ALIGN_LEFT, // Left Alignment
	ADC_ALIGN_RIGHT // Right Alignment
}Adc_ResultAlignmentType;

/* Type definition Type for Power state currently active or set as target power state */
typedef enum
{
	ADC_FULL_POWER,
	// @TODO Rest of Power states is not supported
}Adc_PowerStateType;

/* Type definition Type for Result of the requests related to power state transitions */
typedef enum
{
	ADC_SERVICE_ACCEPTED=0,
	ADC_NOT_INIT=1,
	ADC_SEQUENCE_ERROR=2,
	ADC_HW_FAILURE=3,
	ADC_POWER_STATE_NOT_SUPP=4,
	ADC_TRANS_NOT_POSSIBLE=5
}Adc_PowerStateRequestResultType;


typedef struct
{

}Adc_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
void Adc_Init(const Adc_ConfigType* ConfigPtr);
Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr);
void Adc_DeInit(void);
void Adc_StartGroupConversion(Adc_GroupType Group);
void Adc_StopGroupConversion(Adc_GroupType Group);
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr);
void Adc_EnableHardwareTrigger(Adc_GroupType Group);
void Adc_DisableHardwareTrigger(Adc_GroupType Group);
void Adc_EnableGroupNotification(Adc_GroupType Group);
void Adc_DisableGroupNotification(Adc_GroupType Group);
Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group);
Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType Group, Adc_ValueGroupType** PtrToSamplePtr);
void Adc_GetVersionInfo(Std_VersionInfoType* versioninfo);
Std_ReturnType Adc_SetPowerState(Adc_PowerStateRequestResultType* Result);
Std_ReturnType Adc_GetCurrentPowerState(Adc_PowerStateType* CurrentPowerState,
										Adc_PowerStateRequestResultType* Result);
Std_ReturnType Adc_GetTargetPowerState(Adc_PowerStateType* TargetPowerState,
										Adc_PowerStateRequestResultType* Result);
Std_ReturnType Adc_PreparePowerState(Adc_PowerStateType PowerState, Adc_PowerStateRequestResultType* Result);
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

#endif
