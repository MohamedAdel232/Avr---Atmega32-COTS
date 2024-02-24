/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   Timer_Interface.h                                                               */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        3/9/2023                                                                        */
/************************************************************************************************/

/* File guard */
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

/* A function to initialize Timer0 */
void Timer_voidInit(void);

/* A function to set the preload */
void Timer_voidSetPreLoad (u8 Copy_u8PreLoad);

/* Call back function */
void Timer_voidCallBack (void (*Copy_pvCallBack) (void));

/* A function to initialize zero compare match */
void Timer_voidZeroCompareMatchInit (void);

#endif