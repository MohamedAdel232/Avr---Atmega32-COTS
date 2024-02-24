/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   SSD_Interface.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        17/8/2023                                                                       */
/************************************************************************************************/

/* File guard */
#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

/* Macro for Common Type */
#define SSD_u8COMMON_ANODE				0
#define SSD_u8COMMON_CATHODE			1

typedef struct
{
	u8 Copy_u8EnablePort;
	u8 Copy_u8EnablePin;
	u8 Copy_u8Port;
	u8 Copy_u8ComType;
}SSD_T;

/* A function to turn on a SSD */
u8 SSD_u8EnableSSD (SSD_T *SSD);

/* A function to turn off a SSD */
u8 SSD_u8DisableSSD (SSD_T  *SSD);

/* A function to Set number on the SSD */
u8 SSD_s8SetNumber (SSD_T  *SSD, u8 Copy_u8Number);

#endif
