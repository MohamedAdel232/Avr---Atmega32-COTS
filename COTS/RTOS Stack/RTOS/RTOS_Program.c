/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* File Name:   RTOS_Program.c                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        19/9/2023                                                                       */
/************************************************************************************************/

/* Include LIB files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include Header files */
#include "Timer_Interface.h"
#include "GIE_Interface.h"
#include "RTOS_Interface.h"
#include "RTOS_Config.h"
#include "RTOS_Private.h"

/* Array of tasks */
Task_t SystemTasks [TASK_NUMBER] = {{NULL}};

/* A function to start RTOS */
void RTOS_voidStart(void)
{
	Timer0_u8ComMatchSetCallBack(&voidScheduler);
	GIE_voidEnable();
	Timer0_voidInit();
}

/* A function to create task */
u8 RTOS_u8CreateTast(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (*Copy_pvTaskFunc)(void), u16 Copy_u16FirstDelay)
{
	u8 Local_u8ErrorState = OK;
	/* Check if the require Priority is empty or used before */
	if (SystemTasks[Copy_u8Priority].TaskFunc == NULL)
	{
	    SystemTasks [Copy_u8Priority].Periodicity = Copy_u16Periodicity;
	    SystemTasks [Copy_u8Priority].TaskFunc = Copy_pvTaskFunc;
	    /* Initialize task state */
	    SystemTasks [Copy_u8Priority].State = TASK_RESUMED;
	    SystemTasks [Copy_u8Priority].FirstDelay = Copy_u16FirstDelay;
	}
	else
	{
		/* Priority is reserved */
		Local_u8ErrorState = NOK;
	}
    return Local_u8ErrorState;
}

/* A function for Scheduler */
static void voidScheduler(void)
{
	u8 Local_u8TaskCounter;

	/* loop on all task to check their periodicity */
	for (Local_u8TaskCounter = 0; Local_u8TaskCounter < TASK_NUMBER; Local_u8TaskCounter++)
	{
		/* Check if task is suspended or not */
		if (SystemTasks[Local_u8TaskCounter].State == TASK_RESUMED)
		{
			if (SystemTasks[Local_u8TaskCounter].FirstDelay == 0)
			{
				/* invoke the task function */
				if (SystemTasks[Local_u8TaskCounter].TaskFunc != NULL)
				{
					SystemTasks[Local_u8TaskCounter].TaskFunc();
					SystemTasks[Local_u8TaskCounter].FirstDelay = SystemTasks[Local_u8TaskCounter].Periodicity-1;
				}
				else
				{
					SystemTasks[Local_u8TaskCounter].FirstDelay --;
				}
			}
		}
		else
		{
			/* Task is Suspended do nothing */
		}
	}
}

/* A function to suspend task */
void RTOS_voidSuspendTask(u8 Copy_u8Periority)
{
	SystemTasks[Copy_u8Periority].State = TASK_SUSPENDED;
}

/* A function to resume task */
void RTOS_voidResumeTask(u8 Copy_u8Periority)
{
	SystemTasks[Copy_u8Periority].State = TASK_RESUMED;
}

/* A function to delete task */
void RTOS_voidDeleteTask (u8 Copy_u8Periority)
{
	SystemTasks[Copy_u8Periority].TaskFunc = NULL;
}
