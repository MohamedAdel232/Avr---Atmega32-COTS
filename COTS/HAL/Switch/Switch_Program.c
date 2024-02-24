/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   Switch_Program.c                                                                */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        18/8/2023                                                                       */
/************************************************************************************************/

/* Include LIB files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/* Include Header files */
#include "DIO_Interface.h"
#include "Switch_Interface.h"
#include "Switch_Private.h"
#include "Switch_Config.h"

/* A function to get a value of a Switch */
u8 DIO_u8GetSitchValue (SWITCH_T *SWITCH, u8 Copy_u8Value)
{
	Copy_u8Value = 1;
	DIO_u8SetPinDirection(SWITCH -> Copy_u8Port, SWITCH -> Copy_u8Pin ,DIO_u8PIN_INPUT);
	switch (SWITCH -> Copy_u8ConnType)
	{
	case SWITCH_u8PULL_UP:
		DIO_u8GetPinValue(SWITCH -> Copy_u8Port, SWITCH -> Copy_u8Pin, &Copy_u8Value);
		DIO_u8SetPinValue(SWITCH -> Copy_u8Port, SWITCH -> Copy_u8Pin, DIO_u8PIN_HIGH);

		if (Copy_u8Value == 0)
		{
			return SWITCH_u8PRESSED;
		}
		else if (Copy_u8Value == 1)
		{
			return SWITCH_u8NOT_PRESSED;
		}
		break;
	case SWITCH_u8PULL_DOWN:
		DIO_u8GetPinValue(SWITCH -> Copy_u8Port, SWITCH -> Copy_u8Pin, &Copy_u8Value);
		if (Copy_u8Value == 1)
		{
			return SWITCH_u8PRESSED;
		}
		else if (Copy_u8Value == 0)
		{
			return SWITCH_u8NOT_PRESSED;
		}
		break;
	default: break;
	}
}
