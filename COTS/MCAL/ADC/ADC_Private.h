/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   ADC_Private.h                                                                   */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        1/9/2023                                                                        */
/************************************************************************************************/

/* File guard */
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* Macros to select voltage reference */
#define ADC_AREF							0
#define ADC_AVCC							1
#define ADC_INTERNAL_AREF					2

/* Macros to select Right or left Adjust  */
#define ADC_RIGHT_ADJUST					0
#define ADC_LEFT_ADJUST						1

/* Select Analog Channel */
#define ADC_SINGLE_ENDDED_0					0
#define ADC_SINGLE_ENDDED_1					1
#define ADC_SINGLE_ENDDED_2					2
#define ADC_SINGLE_ENDDED_3					3
#define ADC_SINGLE_ENDDED_4					4
#define ADC_SINGLE_ENDDED_5					5
#define ADC_SINGLE_ENDDED_6					6
#define ADC_SINGLE_ENDDED_7					7

/* Analog Channel MASK */
#define ADC_ANALOG_CHANNEL_MASK				0b11100000

/* PreScaler MASK */
#define ADC_ANALOG_PRE_SCALER_MASK			0b11111000

/* Macros for ADC Prescaler */
#define ADC_DIVIDED_BY_2					0
#define ADC_DIVIDED_BY_2A					1
#define ADC_DIVIDED_BY_4					2
#define ADC_DIVIDED_BY_8					3
#define ADC_DIVIDED_BY_16					4
#define ADC_DIVIDED_BY_32					5
#define ADC_DIVIDED_BY_64					6
#define ADC_DIVIDED_BY_128					7

/* Macros for Busy State */
#define IDLE								0
#define BUSY								1


#endif
