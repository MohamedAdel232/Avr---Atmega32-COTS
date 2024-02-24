/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   UART_Program.c                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        4/9/2023                                                                        */
/************************************************************************************************/

/* Include LIB files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include Header files */
#include "UART_Config.h"
#include "UART_Private.h"
#include "UART_Interface.h"
#include "UART_Register.h"

/* A function to Initialize UART */
void UART_voidInit (void)
{
	/* Local Variable to Enable writing on UCSRC Register */
	u8 Local_u8UCSRC = 0;

	/* Select UCSRC Register */
	SET_BIT(Local_u8UCSRC, UCSRC_URSEL);

	/* Select Asynchronous Mode */
	CLR_BIT(Local_u8UCSRC, UCSRC_UMSEL);

	/* Select 8-bit Character Size */
	SET_BIT(Local_u8UCSRC, UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC, UCSRC_UCSZ1);
	CLR_BIT(UCSRB, UCSRB_UCSZ2);

	/* selects the number of Stop Bits to be 1 */
	CLR_BIT(Local_u8UCSRC, UCSRC_USBS);

	/* Put the value on the register */
	UCSRC = Local_u8UCSRC;

	/* Select BaudRate 9600 bit/sec */
	UBRRL = 51;

	/* Enable Transmitter & Receiver */
	SET_BIT(UCSRB, UCSRB_TXEN);
	SET_BIT(UCSRB, UCSRB_RXEN);

}

/* A function to Transmit Data */
void UART_voidSendData (u8 Copy_u8Data)
{
	/* Polling until Data Register Empty */
	while ((GET_BIT(UCSRA, UCSRA_UDRE)) == 0);
	UDR = Copy_u8Data;
}

/* A function to Receive Data */
u8 UART_u8ReceiveData (void)
{
	/* Polling until UDR is ready to receive new data */
	while ((GET_BIT(UCSRA, UCSRA_RXC)) == 0);
	return UDR;
}
