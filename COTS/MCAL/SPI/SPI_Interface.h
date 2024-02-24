/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   SPI_Interface.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        5/9/2023                                                                        */
/************************************************************************************************/

/* File gaurd */
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/* A function to Initialize Master */
void SPI_voidMasterInit (void);

/* A function to Initialize Slave */
void SPI_voidSlaveInit (void);

/* A function to Transeive data */
u8 SPI_u8Transeive (u8 Copy_u8Data);

#endif