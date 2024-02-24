/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   LED_Program.h                                                                    */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        17/8/2023                                                                       */
/************************************************************************************************/

/* Include LIB files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include Header files */
#include "DIO_Interface.h"
#include "LED_Interface.h"
#include "LED_Private.h"
#include "LED_Config.h"

/* A function to turn on a LED */
u8 LED_u8LedTurnOn (LED_T * LED)
{
	u8 Local_u8ErrorState = 0;
	DIO_u8SetPinDirection(LED->Copy_u8Port, LED->Copy_u8Pin, DIO_u8PIN_OUTPUT);
	if (LED->Copy_u8Pin <= 7 )
	{
		if (LED->Copy_u8ConnectionType == LED_u8SourceConnection)
		{
			DIO_u8SetPinValue(LED->Copy_u8Port, LED->Copy_u8Pin, DIO_u8PIN_HIGH);
		}
		else if (LED->Copy_u8ConnectionType == LED_u8SinkConnection)
		{
			DIO_u8SetPinValue(LED->Copy_u8Port, LED->Copy_u8Pin, DIO_u8PIN_LOW);
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}

	else
	{
		Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}

/* A function to turn off a LED */
u8 LED_u8LedTurnOff (LED_T * LED)
{
	u8 Local_u8ErrorState = 0;
	DIO_u8SetPinDirection(LED->Copy_u8Port, LED->Copy_u8Pin, DIO_u8PIN_OUTPUT);
	if (LED->Copy_u8Pin <= 7 )
	{
		if (LED->Copy_u8ConnectionType == LED_u8SourceConnection)
		{
			DIO_u8SetPinValue(LED->Copy_u8Port, LED->Copy_u8Pin, DIO_u8PIN_LOW);
		}
		else if (LED->Copy_u8ConnectionType == LED_u8SinkConnection)
		{
			DIO_u8SetPinValue(LED->Copy_u8Port, LED->Copy_u8Pin, DIO_u8PIN_HIGH);
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}

	else
	{
		Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}
