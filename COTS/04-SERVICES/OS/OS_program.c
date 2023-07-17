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
u8 SOS_u8CreateTask(u8 Copy_u8TaskPriority, u16 Copy_u16TaskPeriodicity, void (*Copy_pfTask)(void), u8 Copy_u8FirstDelay)
{
    u8 Local_u8ErrorStatus = 0;
    if(Copy_pfTask != NULL)
    {
        SOS_Tasks[Copy_u8TaskPriority].Periodicity = Copy_u16TaskPeriodicity;
        SOS_Tasks[Copy_u8TaskPriority].OS_pfSetTask = Copy_pfTask;
        SOS_Tasks[Copy_u8TaskPriority].FirstDelay = Copy_u8FirstDelay;
    }
    else
    {
        Local_u8ErrorStatus = 1;
    }
    return Local_u8ErrorStatus;
}
void SOS_voidStart(void)
{
    /*****************************< Initialization *****************************/
    MSTK_voidInit();
    /**< Set the Tick time to be ===> 1msec */
    MSTK_voidSetIntervalPeriodic(SOS_TICK_TIME,SOS_voidSetScheduler);
}

static void SOS_voidSetScheduler(void)
{
    for (u8 Local_u8Count = 0; Local_u8Count < SOS_NUMBER_OS_TASKS;Local_u8Count++)
    {
        if(SOS_Tasks[Local_u8Count].OS_pfSetTask != NULL)
        {
            if(SOS_Tasks[Local_u8Count].FirstDelay == 0)
            {
                SOS_Tasks[Local_u8Count].FirstDelay = ((SOS_Tasks[Local_u8Count].Periodicity)/SOS_TICK_TIME)-1;
                SOS_Tasks[Local_u8Count].OS_pfSetTask();
            }
            else
            {
                SOS_Tasks[Local_u8Count].FirstDelay--;
            }
        }
    }
}
