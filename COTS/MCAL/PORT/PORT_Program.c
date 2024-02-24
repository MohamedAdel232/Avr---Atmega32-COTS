/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   PORT_Program.c                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        21/8/2023                                                                       */
/************************************************************************************************/

/* Include LIB files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include Header files */
#include "PORT_Config.h"
#include "PORT_Private.h"
#include "PORT_Interface.h"
#include "PORT_Register.h"

/* A functio to set the direction & value of all PORTS */
void PORT_voidInit (void)
{
    DDRA = PORTA_DIR;
    DDRB = PORTB_DIR;
    DDRC = PORTC_DIR;
    DDRD = PORTD_DIR;

    PORTA = PORTA_INITIAL_VALUE;
    PORTB = PORTB_INITIAL_VALUE;
    PORTC = PORTC_INITIAL_VALUE;
    PORTD = PORTD_INITIAL_VALUE;
}
