/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   SSD_Program.c                                                                   */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        17/8/2023                                                                       */
/************************************************************************************************/

/* Include LIB files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include Header files */
#include "DIO_Interface.h"
#include "SSD_Interface.h"
#include "SSD_Private.h"
#include "SSD_Config.h"

/* Array for Seven Segment Numbers */
u8 SSD_u8SegmentNumberCathode [10] = {0b00111111,
									  0b00000110,
									  0b01011011,
									  0b01001111,
									  0b01100110,
								      0b01101101,
									  0b01111101,
									  0b00000111,
									  0b01111111,
									  0b01101111  };

/*u8 SSD_u8SegmentNumberAnode [10] = {0b00111111,
									0b00000110,
									0b01011011,
									0b01001111,
									0b01100110,
									0b01101101,
									0b01111101,
									0b00000111,
									0b01111111,
									0b01101111  };
*/


/* A function to turn on a SSD */
u8 SSD_u8EnableSSD (SSD_T *SSD)
{
	u8 Local_u8ErrorState = 0;
	DIO_u8SetPinDirection(SSD -> Copy_u8EnablePort, SSD -> Copy_u8EnablePin, DIO_u8PIN_OUTPUT);

	if (SSD -> Copy_u8ComType == SSD_u8COMMON_ANODE)
	{
		DIO_u8SetPinValue(SSD -> Copy_u8EnablePort, SSD -> Copy_u8EnablePin, DIO_u8PIN_HIGH);
	}
	else if (SSD -> Copy_u8ComType == SSD_u8COMMON_CATHODE)
	{
		DIO_u8SetPinValue(SSD -> Copy_u8EnablePort, SSD -> Copy_u8EnablePin, DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}

/* A function to turn off a SSD */
u8 SSD_u8DisableSSD (SSD_T *SSD)
{
	u8 Local_u8ErrorState = 0;
	DIO_u8SetPinDirection(SSD -> Copy_u8EnablePort, SSD -> Copy_u8EnablePin, DIO_u8PIN_OUTPUT);

	if (SSD -> Copy_u8ComType == SSD_u8COMMON_ANODE)
	{
		DIO_u8SetPinValue(SSD -> Copy_u8EnablePort, SSD -> Copy_u8EnablePin, DIO_u8PIN_LOW);
	}
	else if (SSD -> Copy_u8ComType == SSD_u8COMMON_CATHODE)
	{
		DIO_u8SetPinValue(SSD -> Copy_u8EnablePort, SSD -> Copy_u8EnablePin, DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}

/* A function to Set number on the SSD */
u8 SSD_s8SetNumber (SSD_T  *SSD, u8 Copy_u8Number)
{
	u8 Local_u8ErrorState = 0;
	DIO_u8SetPortDirection(SSD -> Copy_u8Port, DIO_u8PORT_OUTPUT);

	if (SSD -> Copy_u8ComType == SSD_u8COMMON_ANODE)
	{
		DIO_u8SetPortValue(SSD -> Copy_u8Port,  ~SSD_u8SegmentNumberCathode [Copy_u8Number]);
	}
	else if (SSD -> Copy_u8ComType == SSD_u8COMMON_CATHODE)
	{
		DIO_u8SetPortValue(SSD -> Copy_u8Port,  SSD_u8SegmentNumberCathode [Copy_u8Number]);
	}
	else
	{
		Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}
