/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   KPD_Program.h                                                                   */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        21/8/2023                                                                       */
/************************************************************************************************/

/* Include delay LIB */
#include <util/delay.h>

/* Include LIB files */
#include "STD_TYPES.h"

/* Include Header files */
#include "DIO_Interface.h"
#include "KPD_Config.h"
#include "KPD_Interface.h"
#include "KPD_Private.h"


/* A function to know if any button has been pressed */
u8 KPD_u8GetPressedKey (void)
{
    /* Variable for the key pressed value */
	u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY;
	u8 Local_u8RowIdx;
	u8 Local_u8CoulmnIdx;
	u8 Local_u8PinState;

	/* Array of values of the buttons */
	/* Static to save the Array in .data (RAM) to save space */
	 u8 Local_u8KDPArr[ROW_NUM][COLUMN_NUM] = KPD_ARR_VAL;

	 u8 Local_u8ColumnArr[COLUMN_NUM] = {KPD_COL0_PIN, KPD_COL1_PIN, KPD_COL2_PIN, KPD_COL3_PIN};

	 u8 Local_u8RowArr[ROW_NUM] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};

	for (Local_u8CoulmnIdx = 0; Local_u8CoulmnIdx < COLUMN_NUM; Local_u8CoulmnIdx++)
	{
		/* Activate Current Column */
		DIO_u8SetPinValue(KPD_PORT,Local_u8ColumnArr[Local_u8CoulmnIdx], DIO_u8PIN_LOW);

		for (Local_u8RowIdx = 0; Local_u8RowIdx < ROW_NUM; Local_u8RowIdx++)
		{
			/* Read the current Row */
			DIO_u8GetPinValue(KPD_PORT, Local_u8RowArr[Local_u8RowIdx], &Local_u8PinState);

			/* Check PIN state */
			if (DIO_u8PIN_LOW == Local_u8PinState)
			{
				Local_u8PressedKey = Local_u8KDPArr[Local_u8RowIdx][Local_u8CoulmnIdx];

				/* Polling until the key is released  */
				while (DIO_u8PIN_LOW == Local_u8PinState)
				{
					DIO_u8GetPinValue(KPD_PORT, Local_u8RowArr[Local_u8RowIdx], &Local_u8PinState);
				}
				//Local_u8PressedKey = Local_u8KDPArr [Local_u8RowIdx] [Local_u8CoulmnIdx];
				return Local_u8PressedKey;
			}

		}
		/* Deactivate the current Column */
		DIO_u8SetPinValue(KPD_PORT,Local_u8ColumnArr[Local_u8CoulmnIdx], DIO_u8PIN_HIGH);
	}
    return Local_u8PressedKey;
}
