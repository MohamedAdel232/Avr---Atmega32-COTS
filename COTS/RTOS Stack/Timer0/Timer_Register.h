/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   Timer0_Register.h                                                               */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        19/9/2023                                                                        */
/************************************************************************************************/

/* File guard */
#ifndef Timer_REGISTER_H
#define Timer_REGISTER_H

/* Registers Address */
#define TCCR0               *((volatile u8*)0x53)
#define TCCR0_CS00          0
#define TCCR0_CS01          1
#define TCCR0_CS02          2
#define TCCR0_WGM01         3
#define TCCR0_COM00         4
#define TCCR0_COM01         5
#define TCCR0_WGM00         6
#define TCCR0_FOC0          7

#define TCNT0               *((volatile u8*)0x52)

#define OCR0                *((volatile u8*)0x5C)

#define TIMSK               *((volatile u8*)0x59)
#define TIMSK_TOIE0         0
#define TIMSK_OCIE0         1

#define TIFR                *((volatile u8*)0x58)
#define TIFR_TOV0           0
#define TIFR_OCF0           1

#endif
