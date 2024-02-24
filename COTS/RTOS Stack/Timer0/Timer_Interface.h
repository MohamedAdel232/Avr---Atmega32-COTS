/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   Timer0_Interface.h                                                              */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        19/9/2023                                                                       */
/************************************************************************************************/

/* File guard */
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

/* A function to initialize Timer0 */
void Timer0_voidInit(void);

/* Call back function */
u8 Timer0_u8ComMatchSetCallBack (void (*Copy_pvCallBackFunc)(void));

#endif