/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   Timer_Program.c                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        3/9/2023                                                                        */
/************************************************************************************************/

/* Include LIB files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include Header files */
#include "Timer_Config.h"
#include "Timer_Private.h"
#include "Timer_Interface.h"
#include "Timer_Register.h"

/* Global Pointer */
void (*Global_CallBack) (void)= NULL;

/* A function to initialize Timer0 */
void Timer_voidInit(void)
{
	/* Select Normal Mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	/* Select PreScaler 8 */
	TCCR0 &= 0b11111000;
	TCCR0 |= 0b00000010;

	TCNT0 = 192;

	/* Enable Interrupt */
	SET_BIT(TIMSK , TIMSK_TOIE0);

}

/* A function to set the preload */
void Timer_voidSetPreLoad (u8 Copy_u8PreLoad)
{
	TCNT0 = Copy_u8PreLoad;
}

/* Call back function */
void Timer_voidCallBack (void (*Copy_pvCallBack) (void))
{
	Global_CallBack = Copy_pvCallBack;
}

/* A function to initialize zero compare match */
void Timer_voidZeroCompareMatchInit (void)
{
	/* Select CTC mode */
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

	/* Select PreScaler 8 */
	TCCR0 &= 0b11111100;
	TCCR0 |= 0b00000010;

	OCR0 = 250;

	/* Enable Interrupt */
	SET_BIT(TIMSK , TIMSK_OCIE0);
}

void __vector_11 (void) __attribute__ ((signal));
void __vector_11 (void)
{
	Global_CallBack();
}
