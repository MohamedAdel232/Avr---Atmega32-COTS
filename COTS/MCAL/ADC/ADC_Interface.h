/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   ADC_Interface.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        1/9/2023                                                                        */
/************************************************************************************************/

/* File guard */
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/* A function to Initialize ADC */
u8 ADC_voidInit (void);

/* A function to Get Channel Reading Synchronous */
u8 ADC_u8StartConversionSynch (u8 Copy_u8Channel, u8* Copy_pu8Reading);

/* A function to Get Channel Reading ASynchronous */
u8 ADC_u8StartConversionASynch (u8 Copy_u8Channel, u8* Copy_pu8Reading, void (*Copy_pvNotificationFunc) (void));

#endif
