/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   RTOS_Interface.h                                                                */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        19/9/2023                                                                       */
/************************************************************************************************/

/* File guard */
#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

/* A function to start RTOS */
void RTOS_voidStart(void);

/* A function to create task */
u8 RTOS_u8CreateTast(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (*Copy_pvTaskFunc)(void), u16 Copy_u16FirstDelay);

/* A function to suspend task */
void RTOS_voidSuspendTask(u8 Copy_u8Periority);

/* A function to resume task */
void RTOS_voidResumeTask(u8 Copy_u8Periority);

/* A function to delete task */
void RTOS_voidDeleteTask (u8 Copy_u8Periority);

#endif
