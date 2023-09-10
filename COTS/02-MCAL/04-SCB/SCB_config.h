/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 7 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : SCB_config.h               *****************/
/****************************************************************/
#ifndef SCB_CONFIG_H_
#define SCB_CONFIG_H_

/**
 * @brief Priority Grouping Configuration for System Control Block (SCB)
 *
 * This macro defines the priority grouping configuration for the System Control Block (SCB)
 * in an ARM Cortex-M microcontroller. The priority grouping determines how interrupt priorities
 * are organized in the NVIC (Nested Vectored Interrupt Controller).
 *
 * @note The value of this macro should be set to one of the following options:
 * - SCB_16GROUP_0SUB:  16 priority levels for group and 0 sub-priority levels.
 * - SCB_8GROUP_2SUB :  8 priority levels for group and 2 sub-priority levels.
 * - SCB_4GROUP_4SUB :  4 priority levels for group and 4 sub-priority levels.
 * - SCB_2GROUP_8SUB :  2 priority levels for group and 8 sub-priority levels.
 * - SCB_0GROUP_16SUB:  No priority grouping, 16 priority levels with no sub-prioritization.
 *
 * The choice of priority grouping affects how interrupt priorities are managed within the NVIC.
 * Select the appropriate option based on your application's requirements.
 *
 * @note The actual behavior of the priority grouping depends on how your code uses this macro
 * in conjunction with other NVIC and SCB configuration settings.
 *
 * @see NVIC_PriorityGroupConfig() for configuring the priority grouping dynamically.
 */
#define SCB_PRIORITY_GROUPING  SCB_16GROUP_0SUB



#endif /**< SCB_CONFIG_H_ */