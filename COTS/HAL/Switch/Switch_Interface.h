/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   Switch_Interface.h                                                              */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        18/8/2023                                                                       */
/************************************************************************************************/

/* File guard */
#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

/* Macros for Connection Type */
#define SWITCH_u8PULL_UP				0
#define SWITCH_u8PULL_DOWN				1

/* Macros for Button State */
#define SWITCH_u8PRESSED				0
#define SWITCH_u8NOT_PRESSED			1

typedef struct
{
	u8 Copy_u8Port;
	u8 Copy_u8Pin;
	u8 Copy_u8ConnType;
}SWITCH_T;

/* A function to get a value of a Switch */
u8 DIO_u8GetSitchValue (SWITCH_T *SWITCH, u8 Copy_u8Value);

#endif
