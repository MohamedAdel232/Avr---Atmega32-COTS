/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   ADC_Program.c                                                                   */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        1/9/2023                                                                        */
/************************************************************************************************/

/* Include LIB files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include Header files */
#include "ADC_Interface.h"
#include "ADC_Register.h"
#include "ADC_Config.h"
#include "ADC_Private.h"

/* Global Variables */
static u8* ADC_pu8Reading = NULL;
static void (*ADC_pvCallBackNotificationFunc)(void) = NULL;

u8 ADC_u8BusyState = IDLE;

/* A function to Initialize ADC */
u8 ADC_voidInit (void)
{
	/* A variable for Error State */
	u8 Local_Error_State = OK;

	/* Select Vref */
	switch (ADC_VOLTAGE_REFERENCE)
	{
	case ADC_AREF:  			CLR_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);
	break;
	case ADC_AVCC: 				SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);
	break;
	case ADC_INTERNAL_AREF:		SET_BIT(ADMUX, ADMUX_REFS0);
	SET_BIT(ADMUX, ADMUX_REFS1);
	break;
	default:					Local_Error_State = NOK;
	break;
	}

	/* Select Right or Left Adjust */
	switch (ADC_ADJUST)
	{
	case ADC_RIGHT_ADJUST:  CLR_BIT(ADMUX,ADMUX_ADLAR);    break;
	case ADC_LEFT_ADJUST:   SET_BIT(ADMUX,ADMUX_ADLAR);    break;
	default 			 :  Local_Error_State = NOK;
	break;
	}

	/* Select 128 Prescaler */
	ADCSRA &= ADC_ANALOG_PRE_SCALER_MASK;
	ADCSRA |= ADC_PRE_SCALLER;

	/* ADC Enable */
	SET_BIT(ADCSRA, ADCSRA_ADEN);

	return Local_Error_State;
}

/* A function to Get Channel Reading */
u8 ADC_u8StartConversionSynch (u8 Copy_u8Channel, u8* Copy_pu8Reading)
{
	/* Local Counter & Error State */
	u32 Local_u32Counter = 0;
	u8 Local_u8ErrorState = OK;

	if (ADC_u8BusyState == IDLE)
	{
		/* Make ADC Busy */
		ADC_u8BusyState = BUSY;

		/* Select ADC channel */
		ADMUX &= ADC_ANALOG_CHANNEL_MASK;
		ADMUX |= Copy_u8Channel;

		/* Start conversion */
		SET_BIT(ADCSRA, ADCSRA_ADSC);

		/* Polling until Conversion flag is set or Timeout is reached */
		while (((GET_BIT(ADCSRA, ADCSRA_ADIF)) == 0) && (Local_u32Counter != ADC_u32TIMEOUT))
		{
			Local_u32Counter++;
		}

		/*  */
		if (Local_u32Counter == ADC_u32TIMEOUT)
		{
			/* Loop is broken because timeout is reached */
			Local_u8ErrorState = NOK;
		}
		else
		{
			/* Loop is broken because flag is raised */
			/* clear flag */
			SET_BIT(ADCSRA, ADCSRA_ADIF);

			/* Return the reading */
			*Copy_pu8Reading = ADCH;

			/* Make ADC IDLE */
			ADC_u8BusyState = IDLE;
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}

	return Local_u8ErrorState;
}

/* A function to Get Channel Reading ASynchronous */
u8 ADC_u8StartConversionASynch (u8 Copy_u8Channel, u8* Copy_pu8Reading, void (*Copy_pvNotificationFunc) (void))
{
	u8 Local_u8ErrorState = OK;

	if (ADC_u8BusyState == IDLE)
	{
		if ((Copy_pu8Reading == NULL) || (Copy_pvNotificationFunc == NULL))
		{
			Local_u8ErrorState = NULL_POINTER;
		}
		else
		{
			/* Make ADC Busy */
			ADC_u8BusyState = BUSY;

			/* Make the Global variables equal to function arguments */
			ADC_pu8Reading = Copy_pu8Reading;
			ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc;

			/* Select ADC channel */
			ADMUX &= ADC_ANALOG_CHANNEL_MASK;
			ADMUX |= Copy_u8Channel;

			/* Start conversion */
			SET_BIT(ADCSRA, ADCSRA_ADSC);

			/* Enable ADC Interrupt */
			SET_BIT(ADCSRA, ADCSRA_ADIE);

		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}
	return Local_u8ErrorState;
}

/* ADC ISR */
void __vector_16 (void) __attribute__ ((signal));
void __vector_16 (void)
{
	/* Read ADC Result */
	*ADC_pu8Reading = ADCH;

	/* Make ADC IDLE */
	ADC_u8BusyState = IDLE;

	/* Notification function */
	ADC_pvCallBackNotificationFunc();

	/* Disable Interrupt */
	CLR_BIT(ADCSRA, ADCSRA_ADIE);
}
