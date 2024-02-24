/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   PORT_Register.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        21/8/2023                                                                       */
/************************************************************************************************/

/* File guard */
#ifndef PORT_REGISTER_H
#define PORT_REGISTER_H

/* Macros for each Direction register to each PORT */
#define DDRA                *((volatile u8*) 0x3A)
#define DDRB                *((volatile u8*) 0x37)
#define DDRC                *((volatile u8*) 0x34)
#define DDRD                *((volatile u8*) 0x31)

/* Macros for each Output register to each PORT */
#define PORTA               *((volatile u8*) 0x3B)
#define PORTB               *((volatile u8*) 0x38)
#define PORTC               *((volatile u8*) 0x35)
#define PORTD               *((volatile u8*) 0x32)

#endif