/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   GIE_Register.h                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        26/8/2023                                                                       */
/************************************************************************************************/

/* File guard */
#ifndef GIE_REGISTER_H
#define GIE_REGISTER_H

/* Address of GIE register */
#define SREG        *((volatile u8*)0x5F)

/* Macro for the I pin */
#define SREG_I      7

#endif