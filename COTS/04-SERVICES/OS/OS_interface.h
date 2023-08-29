/**
 * @file OS_interface.h
 * @brief This file contains the public interface of the operating system module.
 *
 * This file should be included by application code that uses the operating system module.
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 14 Jul 2023
 * @version V01
 * 
 */

#ifndef __OS_INTERFACE_H__
#define __OS_INTERFACE_H__


/**
 * @brief Creates a new task in the operating system.
 *
 * This function creates a new task with the given priority, periodicity, task function, and first delay.
 *
 * @param[in]  Copy_u8TaskPriority      The priority of the new task.
 * @param[in]  Copy_u16TaskPeriodicity  The periodicity of the new task in milliseconds.
 * @param[in]  Copy_pfTask              A pointer to the function that implements the new task.
 * @param[in]  Copy_u8FirstDelay        The initial delay of the new task in ticks.
 *
 * @retval     0                        The task was created successfully.
 * @retval     1                        An error occurred while creating the task.
 */
u8 SOS_u8CreateTask(u8 Copy_u8TaskPriority, u16 Copy_u16TaskPeriodicity, void (*Copy_pfTask)(void));

/**
 * @brief Starts the operating system scheduler.
 *
 * This function initializes the system tick timer and starts the operating system scheduler.
 * The scheduler runs the task functions for each registered task at the appropriate times.
 *
 * @param[in]  None
 * @param[out] None
 *
 * @retval     None
 */
void SOS_voidStart(void);






#endif /**< __OS_INTERFACE_H__ */