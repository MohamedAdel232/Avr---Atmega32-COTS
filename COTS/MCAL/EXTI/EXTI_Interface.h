/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   EXTI_Interface.h                                                                */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        26/8/2023                                                                       */
/************************************************************************************************/

/* File guard */
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/* Macros for Sense Control */
#define EXTI_LOW_LEVEL				1
#define EXTI_ON_CHANGE				2
#define EXTI_FALLING_EDGE			3
#define EXTI_RISING_EDGE			4

/* Macros for EXTI Number */
#define EXTI0						1
#define EXTI1						2
#define EXTI2						3

/* A function to initialize INT0 */
void EXTI_voidInt0Init(void);

/* A function to initialize INT1 */
void EXTI_voidInt1Init(void);

/* A function to initialize INT2 */
void EXTI_voidInt2Init(void);

/* A function to initialize Sense control for  INT0 PreBuild  */
u8 EXTI_u8Int0SetSenseControl (u8 Copy_u8Sense);

/* A function to initialize Sense control for  INT1 PreBuild  */
u8 EXTI_u8Int1SetSenseControl (u8 Copy_u8Sense);

/* A function to initialize Sense control for  INT2 PreBuild  */
u8 EXTI_u8Int2SetSenseControl (u8 Copy_u8Sense);

/* A function to Enable Interrupts */
u8 EXTI_u8EnableInit (u8 Copy_u8Init);

/* A function to Disable Interrupts */
u8 EXTI_u8DisableInit (u8 Copy_u8Init);

/* Call back for INT0 */
u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void));

/* Call back for INT0 */
u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void));

/* Call back for INT0 */
u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void));

#endif
