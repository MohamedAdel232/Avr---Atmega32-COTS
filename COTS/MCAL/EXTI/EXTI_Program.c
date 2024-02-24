/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   EXTI_Program.c                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        26/8/2023                                                                       */
/************************************************************************************************/

/* Include LIB files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include Header files */
#include "EXTI_Interface.h"
#include "EXTI_Register.h"
#include "EXTI_Config.h"
#include "EXTI_Private.h"

/* Global Pointer to function to hold INT0 ISR Address */
void (*EXTI_pvInt0Func)(void) = NULL;
/* Global Pointer to function to hold INT1 ISR Address */
void (*EXTI_pvInt1Func)(void) = NULL;
/* Global Pointer to function to hold INT2 ISR Address */
void (*EXTI_pvInt2Func)(void) = NULL;

/* A function to initialize INT0 */
void EXTI_voidInt0Init(void)
{
#if (EXTI_SENSE_CONTROL == EXTI_LOW_LEVEL)
	CLR_BIT(MCUCR, MCUCR_ISC00);
	CLR_BIT(MCUCR, MCUCR_ISC01);

#elif (EXTI_SENSE_CONTROL == EXTI_ON_CHANGE)
	SET_BIT(MCUCR, MCUCR_ISC00);
	CLR_BIT(MCUCR, MCUCR_ISC01);

#elif (EXTI_SENSE_CONTROL == EXTI_FALLING_EDGE)
	CLR_BIT(MCUCR, MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);

#elif (EXTI_SENSE_CONTROL == EXTI_RISING_EDGE)
	SET_BIT(MCUCR, MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);

#else
#error "Wrong Input"

#endif

#if (EXTI0_STATE == EXTI0_ENABLE)
	SET_BIT(GICR, GICR_INT0);

#elif (EXTI0_STATE == EXTI0_DISABLE)
	SET_BIT(GICR, GICR_INT0);

#else
#error "Wrong Input"

#endif
}

/* A function to initialize INT1 */
void EXTI_voidInt1Init(void)
{
#if (EXTI_SENSE_CONTROL == EXTI_LOW_LEVEL)
	CLR_BIT(MCUCR, MCUCR_ISC10);
	CLR_BIT(MCUCR, MCUCR_ISC11);

#elif (EXTI_SENSE_CONTROL == EXTI_ON_CHANGE)
	SET_BIT(MCUCR, MCUCR_ISC10);
	CLR_BIT(MCUCR, MCUCR_ISC11);

#elif (EXTI_SENSE_CONTROL == EXTI_FALLING_EDGE)
	CLR_BIT(MCUCR, MCUCR_ISC10);
	SET_BIT(MCUCR, MCUCR_ISC11);

#elif (EXTI_SENSE_CONTROL == EXTI_RISING_EDGE)
	SET_BIT(MCUCR, MCUCR_ISC10);
	SET_BIT(MCUCR, MCUCR_ISC11);

#else
#error "Wrong Input"

#endif

#if (EXTI1_STATE == EXTI1_ENABLE)
	SET_BIT(GICR, GICR_INT1);

#elif (EXTI1_STATE == EXTI1_DISABLE)
	SET_BIT(GICR, GICR_INT1);

#else
#error "Wrong Input"

#endif
}


/* A function to initialize INT2 */
void EXTI_voidInt2Init(void)
{
#if (EXTI_SENSE_CONTROL == EXTI_FALLING_EDGE )
	CLR_BIT(MCUCSR, MCUCSR_ISC2);

#elif (EXTI_SENSE_CONTROL == EXTI_RISING_EDGE)
	SET_BIT(MCUCSR, MCUCSR_ISC2);

#else
#error "Wrong Input"

#endif

#if (EXTI2_STATE == EXTI2_ENABLE)
	SET_BIT(GICR, GICR_INT2);

#elif (EXTI2_STATE == EXTI2_DISABLE)
	CLR_BIT(GICR, GICR_INT2);

#else
#error "Wrong Input"

#endif
}

/* A function to initialize Sense control for  INT0 PreBuild  */
u8 EXTI_u8Int0SetSenseControl (u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8Sense)
	{
	case EXTI_LOW_LEVEL: 	CLR_BIT(MCUCR, MCUCR_ISC00);
							CLR_BIT(MCUCR, MCUCR_ISC01);  break;

	case EXTI_ON_CHANGE: 	SET_BIT(MCUCR, MCUCR_ISC00);
							CLR_BIT(MCUCR, MCUCR_ISC01);  break;

	case EXTI_FALLING_EDGE: CLR_BIT(MCUCR, MCUCR_ISC00);
							SET_BIT(MCUCR, MCUCR_ISC01);  break;

	case EXTI_RISING_EDGE: 	SET_BIT(MCUCR, MCUCR_ISC00);
							SET_BIT(MCUCR, MCUCR_ISC01);  break;

	default: Local_u8ErrorState = NOK; 					  break;
	}
	return Local_u8ErrorState;
}

/* A function to initialize Sense control for  INT1 PreBuild  */
u8 EXTI_u8Int1SetSenseControl (u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8Sense)
	{
	case EXTI_LOW_LEVEL: 	CLR_BIT(MCUCR, MCUCR_ISC10);
							CLR_BIT(MCUCR, MCUCR_ISC11);  break;

	case EXTI_ON_CHANGE: 	SET_BIT(MCUCR, MCUCR_ISC10);
							CLR_BIT(MCUCR, MCUCR_ISC11);  break;

	case EXTI_FALLING_EDGE: CLR_BIT(MCUCR, MCUCR_ISC10);
							SET_BIT(MCUCR, MCUCR_ISC11);  break;

	case EXTI_RISING_EDGE:  SET_BIT(MCUCR, MCUCR_ISC10);
							SET_BIT(MCUCR, MCUCR_ISC11);  break;

	default: Local_u8ErrorState = NOK; 					  break;
	}
	return Local_u8ErrorState;
}

/* A function to initialize Sense control for  INT2 PreBuild  */
u8 EXTI_u8Int2SetSenseControl (u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8Sense)
	{
	case EXTI_FALLING_EDGE: CLR_BIT(MCUCSR, MCUCSR_ISC2); break;
	case EXTI_RISING_EDGE:  SET_BIT(MCUCSR, MCUCSR_ISC2); break;
	default: Local_u8ErrorState = NOK; 					  break;
	}
	return Local_u8ErrorState;
}

/* A function to Enable Interrupts */
u8 EXTI_u8EnableInit (u8 Copy_u8Init)
{
	{
		u8 Local_u8ErrorState = OK;
		switch (Copy_u8Init)
		{
		case EXTI0: SET_BIT(GICR, GICR_INT0); break;
		case EXTI1: SET_BIT(GICR, GICR_INT1); break;
		case EXTI2: SET_BIT(GICR, GICR_INT2); break;
		default: Local_u8ErrorState = NOK; 	  break;
		}
		return Local_u8ErrorState;
	}
}

/* A function to Disable Interrupts */
u8 EXTI_u8DisableInit (u8 Copy_u8Init)
{
	{
		u8 Local_u8ErrorState = OK;
		switch (Copy_u8Init)
		{
		case EXTI0: CLR_BIT(GICR, GICR_INT0); break;
		case EXTI1: CLR_BIT(GICR, GICR_INT1); break;
		case EXTI2: CLR_BIT(GICR, GICR_INT2); break;
		default: Local_u8ErrorState = NOK; 	  break;
		}
		return Local_u8ErrorState;
	}
}

/* Call back for INT0 */
u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void))
{
		u8 Local_u8ErrorState = OK;
		if (Copy_pvInt0Func != NULL)
		{
			EXTI_pvInt0Func = Copy_pvInt0Func;
		}
		else
		{
			Local_u8ErrorState = NULL_POINTER;
		}
		return Local_u8ErrorState;
}


/* Call back for INT1 */
u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if (Copy_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func = Copy_pvInt1Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

/* Call back for INT2 */
u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if (Copy_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func = Copy_pvInt2Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

/* IST Of INT0 */
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if (EXTI_pvInt0Func != NULL)
		{
			EXTI_pvInt0Func();
		}
	else
	{
		/* Do nothin */
	}
}

/* IST Of INT1 */
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if (EXTI_pvInt1Func != NULL)
		{
			EXTI_pvInt1Func();
		}
	else
	{
		/* Do nothin */
	}
}

/* IST Of INT2 */
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if (EXTI_pvInt2Func != NULL)
		{
			EXTI_pvInt2Func();
		}
	else
	{
		/* Do nothin */
	}
}
