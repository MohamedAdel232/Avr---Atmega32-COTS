/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   KPD_Config.h                                                                    */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        21/8/2023                                                                       */
/************************************************************************************************/

/* File guard */
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

/* Macro for the PORT & PINS the will be connected to the keypad */
#define KPD_PORT       				    DIO_u8PORTD

#define KPD_COL0_PIN					DIO_u8PIN0
#define KPD_COL1_PIN					DIO_u8PIN1
#define KPD_COL2_PIN					DIO_u8PIN2
#define KPD_COL3_PIN					DIO_u8PIN3

#define KPD_ROW0_PIN					DIO_u8PIN4
#define KPD_ROW1_PIN					DIO_u8PIN5
#define KPD_ROW2_PIN					DIO_u8PIN6
#define KPD_ROW3_PIN					DIO_u8PIN7

/* Macro for no pressed key state */
#define KPD_NO_PRESSED_KEY				 0xff

/* Macro of values of the buttons */
#define KPD_ARR_VAL						{{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'-'},{'c',0,'=','+'}}

#endif
