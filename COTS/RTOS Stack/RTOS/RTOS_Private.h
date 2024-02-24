/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   RTOS_Private.h                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        19/9/2023                                                                       */
/************************************************************************************************/

/* File guard */
#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H

/* A struct for TCB */
typedef struct
{
	u16 Periodicity;
	void (*TaskFunc)(void);
	u8 State;
	u16 FirstDelay;
}Task_t;

/* A function for Scheduler */
static void voidScheduler(void);

/* Macros for Task State */
#define TASK_RESUMED			0
#define TASK_SUSPENDED			1

#endif
