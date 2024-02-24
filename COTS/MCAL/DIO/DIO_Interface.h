/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   DIO_Interface.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        17/8/2023                                                                       */
/************************************************************************************************/

/* File guard */
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* Macros for each PORT */
#define DIO_u8PORTA                 0
#define DIO_u8PORTB                 1
#define DIO_u8PORTC                 2
#define DIO_u8PORTD                 3

/* Macros for each PIN */
#define DIO_u8PIN0                  0
#define DIO_u8PIN1                  1
#define DIO_u8PIN2                  2
#define DIO_u8PIN3                  3
#define DIO_u8PIN4                  4
#define DIO_u8PIN5                  5
#define DIO_u8PIN6                  6
#define DIO_u8PIN7                  7

/* Macros for PORT Direction */
#define DIO_u8PORT_INPUT            0x00
#define DIO_u8PORT_OUTPUT           0xff

/* Macros for PIN Direction */
#define DIO_u8PIN_INPUT             0
#define DIO_u8PIN_OUTPUT            1

/* Macros for PORT value */
#define DIO_u8PORT_LOW              0x00
#define DIO_u8PORT_HIGH             0xff

/* Macros for PIN value */
#define DIO_u8PIN_LOW               0
#define DIO_u8PIN_HIGH              1

/* Functions prototypes */

/* A function to Set direction of the whole PORT */
u8 DIO_u8SetPortDirection (u8 Copy_u8Port, u8 Copy_u8Direction);

/* A function to Set direction of the one pin */
u8 DIO_u8SetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

/* A function to Give value to all PORT */
u8 DIO_u8SetPortValue (u8 Copy_u8Port, u8 Copy_u8Value);

/* A function to Give value to one pin */
u8 DIO_u8SetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

/* A function to get a value of a pin */
u8 DIO_u8GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value);

#endif
