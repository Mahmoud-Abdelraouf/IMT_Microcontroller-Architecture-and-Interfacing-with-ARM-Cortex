/**
 * @file OS_private.h
 * @brief This file contains the private interface of the operating system module.
 *
 * This file should not be included directly by application code.
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 14 JUL 2023
 * @version V01
 * 
 */
#ifndef __OS_PRIVATE_H__
#define __OS_PRIVATE_H__


#define OS_TICK_TIME       1000

/**
 * @brief A struct representing a task in the operating system.
 *
 * This struct represents a task in the operating system. It contains the task's
 * priority, periodicity, task function, and first delay.
 */
typedef struct {
    u16 Periodicity;                /**< The periodicity of the task in microsecond. */
    void (*OS_pfSetTask)(void);     /**< A pointer to the function that implements the task. */
    u8 FirstDelay;                  /**< The initial delay of the task in ticks. */
    /**< The current state of the task's scheduler. */
} OS_Task_t;

/**
 * @brief An array containing the registered tasks for the operating system.
 *
 * This array holds the registered tasks for the operating system. Each task is represented
 * by a "SOS_Task_t" structure.
 */
static OS_Task_t OS_Tasks[OS_NUMBER_TASKS] = {NULL};


/**
 * @brief The scheduler function for the operating system.
 *
 * This function runs the task functions for each registered task at the appropriate times.
 *
 * @param[in]  None
 * @param[out] None
 *
 * @retval     None
 */
static void OS_voidSetScheduler(void);






#endif /**< __OS_PRIVATE_H__ */