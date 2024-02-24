/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   SPI_Private.h                                                                   */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        5/9/2023                                                                        */
/************************************************************************************************/

/* Include LIB Files */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/* Include Files */
#include "SPI_Interface.h"
#include "SPI_Config.h"
#include "SPI_Private.h"
#include "SPI_Register.h"

/* A function to Initialize Master */
void SPI_voidMasterInit (void)
{
	/* Select Master */
	SET_BIT(SPCR, SPCR_MSTR);

	/* Select SPI Clock: Fosc/16 */
	SET_BIT(SPCR, SPCR_SPR0);
	CLR_BIT(SPCR, SPCR_SPR1);
	CLR_BIT(SPSR, SPSR_SPI2X);

	/* Enable SPI */
	SET_BIT(SPCR, SPCR_SPE);
}

/* A function to Initialize Slave */
void SPI_voidSlaveInit (void)
{
	/* Select Slave */
	CLR_BIT(SPCR, SPCR_MSTR);

	/* Enable SPI */
	SET_BIT(SPCR,SPCR_SPE);
}

/* A function to Transeive data */
u8 SPI_u8Transeive (u8 Copy_u8Data)
{
	/* Send the Data */
	SPDR = Copy_u8Data;

	/* Polling until Transfer Complete */
	while ((GET_BIT(SPSR, SPSR_SPIF)) == 0);

	/* Receive Send Data */
	return SPDR;
}
