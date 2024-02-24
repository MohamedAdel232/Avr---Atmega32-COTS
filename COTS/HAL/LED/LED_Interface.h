/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   LED_Interface.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        17/8/2023                                                                       */
/************************************************************************************************/

/* File guard */
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#define LED_u8SourceConnection		0
#define LED_u8SinkConnection		1

typedef struct
{
	u8 Copy_u8Port;
	u8 Copy_u8Pin;
	u8 Copy_u8ConnectionType;

}LED_T;

/* A function to turn on a LED */
u8 LED_u8LedTurnOn (LED_T * LED);

/* A function to turn off a LED */
u8 LED_u8LedTurnOff (LED_T * LED);

#endif
