/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   GIE_Program.c                                                                   */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        26/8/2023                                                                       */
/************************************************************************************************/

/* Include LIB files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include Header files */
#include "GIE_Interface.h"
#include "GIE_Register.h"

/* A function to Enable the GIE */
void GIE_voidEnable(void)
{
    SET_BIT(SREG, SREG_I);
}

/* A function to Disaable the GIE */
void GIE_voidDisable(void)
{
    CLR_BIT(SREG, SREG_I);
}
