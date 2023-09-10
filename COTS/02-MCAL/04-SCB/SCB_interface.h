/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 7 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : SCB_interface.h            *****************/
/****************************************************************/
#ifndef SCB_INTERFACE_H_
#define SCB_INTERFACE_H_

/*****************************< Function to enable/disable global interrupts *****************************/
/**
 * @brief Set the Priority Grouping in the System Control Block (SCB).
 *
 * This function sets the priority grouping for the Nested Vectored Interrupt Controller (NVIC)
 * in the ARM Cortex-M microcontroller. The priority grouping determines how interrupt priorities
 * are organized.
 *
 * @param[in] Copy_PriorityGrouping The priority grouping configuration to set.
 *
 * @return None
 *
 * @note The "Copy_PriorityGrouping" parameter should be one of the predefined values for priority grouping.
 * @see SCB_PRIORITY_GROUPING
 */
void SCB_SetPriorityGrouping(u32 Copy_PriorityGrouping);

/**
 * @brief Disable global interrupts by setting the PRIMASK bit.
 *
 * This function disables global interrupts by setting the PRIMASK bit in the
 * Processor Status Register (PSR). This effectively prevents the processor
 * from servicing any interrupts until global interrupts are re-enabled.
 *
 * @return None
 */
void DisableGlobalInterrupts(void); 

/**
 * @brief Enable global interrupts.
 *
 * This function enables global interrupts by clearing the PRIMASK bit in the
 * Processor Status Register (PSR). This allows the processor to service
 * interrupts that were previously disabled using the `DisableGlobalInterrupts`
 * function.
 *
 * @return None
 */
void EnableGlobalInterrupts(void);

/*****************************< Function to enable/disable specific faults *****************************/
/**
 * @brief Enable the Memory Management Fault in the System Control Block (SCB).
 *
 * This function enables the Memory Management Fault, allowing the CPU to trigger
 * a fault handler when a memory management fault occurs.
 *
 * @return None
 */
void SCB_EnableMemFault(void);
/**
 * @brief Enable the Bus Fault in the System Control Block (SCB).
 *
 * This function enables the Bus Fault, allowing the CPU to trigger
 * a fault handler when a bus fault occurs.
 *
 * @return None
 */
void SCB_EnableBusFault(void);

/**
 * @brief Enable the Usage Fault in the System Control Block (SCB).
 *
 * This function enables the Usage Fault, allowing the CPU to trigger
 * a fault handler when a usage fault occurs.
 *
 * @return None
 */
void SCB_EnableUsageFault(void);

/**
 * @brief Clear the Memory Management Fault in the System Control Block (SCB).
 *
 * This function clears the Memory Management Fault status bit in SHCSR,
 * indicating that the memory management fault condition has been handled.
 *
 * @return None
 */
void SCB_ClearMemFault(void);

/**
 * @brief Clear the Bus Fault in the System Control Block (SCB).
 *
 * This function clears the Bus Fault status bit in SHCSR, indicating that
 * the bus fault condition has been handled.
 *
 * @return None
 */
void SCB_ClearBusFault(void);

/**
 * @brief Clear the Usage Fault in the System Control Block (SCB).
 *
 * This function clears the Usage Fault status bit in SHCSR, indicating that
 * the usage fault condition has been handled.
 *
 * @return None
 */
void SCB_ClearUsageFault(void);



#endif /**< SCB_INTERFACE_H_ */