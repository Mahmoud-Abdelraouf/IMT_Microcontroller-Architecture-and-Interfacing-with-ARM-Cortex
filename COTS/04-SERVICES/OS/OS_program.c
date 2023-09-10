/**
 * @file OS_program.c
 * @brief This file contains the implementation of the operating system module.
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 14 JUL 2023
 * @version V01
 * 
 */
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "STK_interface.h"
/**< SERVICES */
#include "OS_config.h"
#include "OS_interface.h"
#include "OS_private.h"


/****************************************< FUNCTIONS IMPLEMENTATION ****************************************/
u8 OS_CreateTask(u8 Copy_u8TaskPriority, u16 Copy_u16TaskPeriodicity, void (*Copy_pfTask)(void), u8 Copy_u8FirstDelay)
{
    u8 Local_u8ErrorStatus = 0;

    if(Copy_pfTask != NULL)
    {
        OS_Tasks[Copy_u8TaskPriority].Periodicity = Copy_u16TaskPeriodicity;
        OS_Tasks[Copy_u8TaskPriority].OS_pfSetTask = Copy_pfTask;
        OS_Tasks[Copy_u8TaskPriority].FirstDelay = Copy_u8FirstDelay;
    }
    else
    {
        Local_u8ErrorStatus = 1;
    }

    return Local_u8ErrorStatus;
}
void OS_Start(void)
{
    /*****************************< Initialization *****************************/
    STK_Init();
    /**< Set the Tick time to be ===> 1msec */
    MSTK_voidSetIntervalPeriodic(OS_TICK_TIME, OS_SetScheduler);
}

static void OS_SetScheduler(void)
{
    for (u8 Local_u8Count = 0; Local_u8Count < OS_NUMBER_TASKS;Local_u8Count++)
    {
        if(OS_Tasks[Local_u8Count].OS_pfSetTask != NULL)
        {
            if(OS_Tasks[Local_u8Count].FirstDelay == 0)
            {
                OS_Tasks[Local_u8Count].FirstDelay = ((OS_Tasks[Local_u8Count].Periodicity) / OS_TICK_TIME)-1;
                OS_Tasks[Local_u8Count].OS_pfSetTask();
            }
            else
            {
                OS_Tasks[Local_u8Count].FirstDelay--;
            }
        }
    }
}
