/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   CLCD_Interface.h                                                                */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        19/8/2023                                                                       */
/************************************************************************************************/

/* File guard */
#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

/* A function to send Command */
void CLCD_voidSendCommand (u8 Copy_u8Command);

/* A function to send Data */
void CLCD_voidSendData (u8 Copy_u8Data);

/* A function to Initialize CLCD */
void CLCD_voidInit(void);

/* A function to send a string */
void CLCD_voidSentString (const char* Copy_pcString);

/* A function to go to specific location */
void CLCD_voidGoToXY (u8 Copy_u8XPos, u8 Copy_u8YPos);

/* A function to send a special Character */
void CLCD_voidSendSpecialCharacter (u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos);

/* A function to send Digit */
void CLCD_voidSendDigit (u8 Copy_u8Digit);

/* A function to send a number */
void CLCD_voidSendNumber (u16 Copy_u16Number);

/* A function for the stick man run */
void CLCD_voidStickManRun (void);

#endif
