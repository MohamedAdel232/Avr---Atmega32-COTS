/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   Timer0_Program.c                                                                */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        19/9/2023                                                                       */
/************************************************************************************************/

/* Include LIB files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include Header files */
#include "Timer_Interface.h"
#include "Timer_Register.h"
#include "Timer_Config.h"
#include "Timer_Private.h"

/* Global Pointer */
static void (*Timer0_pvCompMatchCallBackFunc) (void)= NULL;

/* A function to initialize Timer0 */
void Timer0_voidInit(void)
{
	/* Select CTC Mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	
	/* Set the required Compar match value */
	TCNT0 = TIMER0_u8COM_MATCH_VAL;
	
	/* Compare match interrupt enable */
	SET_BIT(TIMSK, TIMSK_OCIE0);

	/* Select PreScaler 8 */
	TCCR0 &= TIMER_PRESCALER_MASK;
	TCCR0 |= TIMER0_u8PRESCALER;
}

/* Call back function */
u8 Timer0_u8ComMatchSetCallBack (void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if (Copy_pvCallBackFunc != NULL)
	{
		Timer0_pvCompMatchCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}


/* Timer0 Compare Match ISR */
void __vector_10 (void) __attribute__ ((signal));
void __vector_10 (void)
{
	if (Timer0_pvCompMatchCallBackFunc != NULL)
	{
		Timer0_pvCompMatchCallBackFunc();
	}
	else 
	{
		/* Nothing */
	}
}
