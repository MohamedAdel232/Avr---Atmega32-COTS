/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   ADC_Config.h                                                                    */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        1/9/2023                                                                        */
/************************************************************************************************/

/* File guard */
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* Macros to select voltage reference */
#define ADC_VOLTAGE_REFERENCE				ADC_AVCC


/* Macros to select Right or left Adjust  */
#define ADC_ADJUST							ADC_LEFT_ADJUST

/* Select Analog Channel */
#define ADC_ANALOG_CHANNEL					ADC_SINGLE_ENDDED_0

/* Select ADC Prescaler */
#define ADC_PRE_SCALLER						ADC_DIVIDED_BY_128

/* Select Timeout for Synch function */
#define ADC_u32TIMEOUT						50000




#endif
