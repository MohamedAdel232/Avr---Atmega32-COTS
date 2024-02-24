/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   UART_Interface.h                                                                */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        4/9/2023                                                                        */
/************************************************************************************************/

/* File guard */
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/* A function to Initialize UART */
void UART_voidInit (void);

/* A function to Transmit Data */
void UART_voidSendData (u8 Copy_u8Data);

/* A function to Receive Data */
u8 UART_u8ReceiveData (void);

#endif
