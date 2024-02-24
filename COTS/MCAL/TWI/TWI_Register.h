/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   TWI_Register.h                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        12/9/2023                                                                       */
/************************************************************************************************/

/* File guard */
#ifndef TWI_REGISTER_H
#define TWI_REGISTER_H

/* Macros for register Addresses */
#define TWBR				*((volatile u8*)0x20)
#define TWBR_TWBR0			0
#define TWBR_TWBR1          1
#define TWBR_TWBR2          2
#define TWBR_TWBR3          3
#define TWBR_TWBR4          4
#define TWBR_TWBR5          5
#define TWBR_TWBR6          6
#define TWBR_TWBR7          7

#define TWCR				*((volatile u8*)0x56)
#define TWCR_TWIE			0
#define TWCR_TWEN           2
#define TWCR_TWWC           3
#define TWCR_TWSTO          4
#define TWCR_TWSTA          5
#define TWCR_TWEA           6
#define TWCR_TWINT          7

#define TWSR				*((volatile u8*)0x21)
#define TWSR_TWPS0			0
#define TWSR_TWPS1			1
#define TWSR_TWS3           3
#define TWSR_TWS4           4
#define TWSR_TWS5           5
#define TWSR_TWS6           6
#define TWSR_TWS7           7

#define TWDR				*((volatile u8*)0x23)
#define TWDR_TWD0			0
#define TWDR_TWD1			1
#define TWDR_TWD2			2
#define TWDR_TWD3           3
#define TWDR_TWD4           4
#define TWDR_TWD5           5
#define TWDR_TWD6           6
#define TWDR_TWD7           7

#define TWAR				*((volatile u8*)0x22)
#define TWAR_TWGCE			0
#define TWAR_TWA0			1
#define TWAR_TWA1			2
#define TWAR_TWA2           3
#define TWAR_TWA3           4
#define TWAR_TWA4           5
#define TWAR_TWA5           6
#define TWAR_TWA6           7

#endif
