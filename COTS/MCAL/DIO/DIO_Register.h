/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   DIO_Register.h                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        17/8/2023                                                                       */
/************************************************************************************************/

/* File guard */
#ifndef DIO_REGISTER_H
#define DIO_REGISTER_H

/* Registers for PORTA */
#define PORTA               *((volatile u8*) 0x3B)
#define DDRA                *((volatile u8*) 0x3A)
#define PINA                *((volatile u8*) 0x39)

/* Registers for PORTB */
#define PORTB               *((volatile u8*) 0x38)
#define DDRB                *((volatile u8*) 0x37)
#define PINB                *((volatile u8*) 0x36)

/* Registers for PORTC */
#define PORTC               *((volatile u8*) 0x35)
#define DDRC                *((volatile u8*) 0x34)
#define PINC                *((volatile u8*) 0x33)

/* Registers for PORTD */
#define PORTD               *((volatile u8*) 0x32)
#define DDRD                *((volatile u8*) 0x31)
#define PIND                *((volatile u8*) 0x30)

#endif