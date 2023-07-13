/*******************************************************/
/***** Author    : Mahmoud Abdelraouf Mahmoud   ********/
/***** Date		 : 20 Feb 2022                  ********/
/***** Version   : V01                          ********/
/***** Module    : OS_program.c                 ********/
/*******************************************************/
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "STK_interface.h"
/**< SERVICES */
#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

static OS_Task_t SOS_Tasks[SOS_NUMBER_OS_TASKS] = {0};

/****************************************< FUNCTIONS IMPLEMENTATION ****************************************/
u8 SOS_u8CreateTask(u8 Copy_u8TaskPriority, u16 Copy_u16TaskPeriodicity, void (*Copy_pfTask)(void))
{
    u8 Local_u8ErrorStatus = 0;
    if(Copy_pfTask != NULL)
    {
        SOS_Tasks[Copy_u8TaskPriority].Periodicity = Copy_u16TaskPeriodicity;
        SOS_Tasks[Copy_u8TaskPriority].OS_pfSetTask = Copy_pfTask;
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
    MSTK_voidSetIntervalPeriodic(1000,SOS_voidSetScheduler);

}

volatile u16 SOS_u16TickCount = 0;
static void SOS_voidSetScheduler(void)
{
    for (u8 Local_u8Count = 0; Local_u8Count < SOS_NUMBER_OS_TASKS;Local_u8Count++)
    {
        if((SOS_Tasks[Local_u8Count].Periodicity % SOS_u16TickCount) == 0)
        {
            SOS_Tasks[Local_u8Count].OS_pfSetTask();
        }
    }
    SOS_u16TickCount++;
}
