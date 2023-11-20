/*
=======================================================================================================================
Author       : Mamoun
Module       : NVIC
File Name    : nvic.h
Date Created : Nov 17, 2023
Description  : Interface file for the STM32F303 NVIC driver.
=======================================================================================================================
*/


#ifndef MCAL_NVIC_INCLUDES_NVIC_H_
#define MCAL_NVIC_INCLUDES_NVIC_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The valid group levels for the NVIC. */
#if((NVIC_PRIORITY_GROUP_LEVEL != SCB_PRIGROUP_LEVEL_A) && \
    (NVIC_PRIORITY_GROUP_LEVEL != SCB_PRIGROUP_LEVEL_B) && \
    (NVIC_PRIORITY_GROUP_LEVEL != SCB_PRIGROUP_LEVEL_C) && \
    (NVIC_PRIORITY_GROUP_LEVEL != SCB_PRIGROUP_LEVEL_D) && \
    (NVIC_PRIORITY_GROUP_LEVEL != SCB_PRIGROUP_LEVEL_E))
#error "Invalid interrupt priority group level!"
#endif

/* Level A priority groups and subgroups. */
#if(NVIC_PRIORITY_GROUP_LEVEL == SCB_PRIGROUP_LEVEL_A)

#define NVIC_PRIORITY_GROUP_00_SUBGROUP_00          (0U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_00          (1U)
#define NVIC_PRIORITY_GROUP_02_SUBGROUP_00          (2U)
#define NVIC_PRIORITY_GROUP_03_SUBGROUP_00          (3U)
#define NVIC_PRIORITY_GROUP_04_SUBGROUP_00          (4U)
#define NVIC_PRIORITY_GROUP_05_SUBGROUP_00          (5U)
#define NVIC_PRIORITY_GROUP_06_SUBGROUP_00          (6U)
#define NVIC_PRIORITY_GROUP_07_SUBGROUP_00          (7U)
#define NVIC_PRIORITY_GROUP_08_SUBGROUP_00          (8U)
#define NVIC_PRIORITY_GROUP_09_SUBGROUP_00          (9U)
#define NVIC_PRIORITY_GROUP_10_SUBGROUP_00          (10U)
#define NVIC_PRIORITY_GROUP_11_SUBGROUP_00          (11U)
#define NVIC_PRIORITY_GROUP_12_SUBGROUP_00          (12U)
#define NVIC_PRIORITY_GROUP_13_SUBGROUP_00          (13U)
#define NVIC_PRIORITY_GROUP_14_SUBGROUP_00          (14U)
#define NVIC_PRIORITY_GROUP_15_SUBGROUP_00          (15U)

/* Level B priority groups and subgroups. */
#elif(NVIC_PRIORITY_GROUP_LEVEL == SCB_PRIGROUP_LEVEL_B)

#define NVIC_PRIORITY_GROUP_00_SUBGROUP_00          (0U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_01          (1U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_00          (2U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_01          (3U)
#define NVIC_PRIORITY_GROUP_02_SUBGROUP_00          (4U)
#define NVIC_PRIORITY_GROUP_02_SUBGROUP_01          (5U)
#define NVIC_PRIORITY_GROUP_03_SUBGROUP_00          (6U)
#define NVIC_PRIORITY_GROUP_03_SUBGROUP_01          (7U)
#define NVIC_PRIORITY_GROUP_04_SUBGROUP_00          (8U)
#define NVIC_PRIORITY_GROUP_04_SUBGROUP_01          (9U)
#define NVIC_PRIORITY_GROUP_05_SUBGROUP_00          (10U)
#define NVIC_PRIORITY_GROUP_05_SUBGROUP_01          (11U)
#define NVIC_PRIORITY_GROUP_06_SUBGROUP_00          (12U)
#define NVIC_PRIORITY_GROUP_06_SUBGROUP_01          (13U)
#define NVIC_PRIORITY_GROUP_07_SUBGROUP_00          (14U)
#define NVIC_PRIORITY_GROUP_07_SUBGROUP_01          (15U)

/* Level C priority groups and subgroups. */
#elif(NVIC_PRIORITY_GROUP_LEVEL == SCB_PRIGROUP_LEVEL_C)

#define NVIC_PRIORITY_GROUP_00_SUBGROUP_00          (0U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_01          (1U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_02          (2U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_03          (3U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_00          (4U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_01          (5U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_02          (6U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_03          (7U)
#define NVIC_PRIORITY_GROUP_02_SUBGROUP_00          (8U)
#define NVIC_PRIORITY_GROUP_02_SUBGROUP_01          (9U)
#define NVIC_PRIORITY_GROUP_02_SUBGROUP_02          (10U)
#define NVIC_PRIORITY_GROUP_02_SUBGROUP_03          (11U)
#define NVIC_PRIORITY_GROUP_03_SUBGROUP_00          (12U)
#define NVIC_PRIORITY_GROUP_03_SUBGROUP_01          (13U)
#define NVIC_PRIORITY_GROUP_03_SUBGROUP_02          (14U)
#define NVIC_PRIORITY_GROUP_03_SUBGROUP_03          (15U)

/* Level D priority groups and subgroups. */
#elif(NVIC_PRIORITY_GROUP_LEVEL == SCB_PRIGROUP_LEVEL_D)

#define NVIC_PRIORITY_GROUP_00_SUBGROUP_00          (0U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_01          (1U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_02          (2U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_03          (3U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_04          (4U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_05          (5U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_06          (6U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_07          (7U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_00          (8U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_01          (9U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_02          (10U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_03          (11U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_04          (12U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_05          (13U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_06          (14U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_07          (15U)

/* Level E priority groups and subgroups. */
#elif(NVIC_PRIORITY_GROUP_LEVEL == SCB_PRIGROUP_LEVEL_E)

#define NVIC_PRIORITY_GROUP_00_SUBGROUP_00          (0U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_01          (1U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_02          (2U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_03          (3U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_04          (4U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_05          (5U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_06          (6U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_07          (7U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_08          (0U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_09          (1U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_10          (2U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_11          (3U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_12          (4U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_13          (5U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_14          (6U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_15          (7U)

#endif

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    NVIC_NO_ERRORS,
    NVIC_IRQ_NUM_ERROR,
    NVIC_NULL_PTR_ERROR,
    NVIC_PRIORITY_ERROR,
}NVIC_errorStatusType;

typedef enum
{
    NVIC_NOT_PENDING_STATUS,
    NVIC_PENDING_STATUS,
}NVIC_pendingStatusType;

typedef enum
{
    NVIC_WWDG_IRQ                =  0,     /* Window Watchdog interrupt. */
    NVIC_PVD_IRQ                 =  1,     /* PVD through EXTI Line16 detection interrupt. */
    NVIC_TAMPER_STAMP_IRQ        =  2,     /* Tamper and TimeStamp interrupts through EXTI Line19. */
    NVIC_RTC_WKUP_IRQ            =  3,     /* RTC wakeup timer interrupt through EXTI Line20. */
    NVIC_FLASH_IRQ               =  4,     /* Flash global interrupt. */
    NVIC_RCC_IRQ                 =  5,     /* RCC global interrupt. */
    NVIC_EXTI0_IRQ               =  6,     /* EXTI Line0 interrupt. */
    NVIC_EXTI1_IRQ               =  7,     /* EXTI Line1 interrupt. */
    NVIC_EXTI2_TS_IRQ            =  8,     /* EXTI Line2 and Touch sensing interrupts. */
    NVIC_EXTI3_IRQ               =  9,     /* EXTI Line3. */
    NVIC_EXTI4_IRQ               = 10,     /* EXTI Line4. */
    NVIC_DMA1_Channel1_IRQ       = 11,     /* DMA1 channel 1 interrupt. */
    NVIC_DMA1_Channel2_IRQ       = 12,     /* DMA1 channel 2 interrupt. */
    NVIC_DMA1_Channel3_IRQ       = 13,     /* DMA1 channel 3 interrupt. */
    NVIC_DMA1_Channel4_IRQ       = 14,     /* DMA1 channel 4 interrupt. */
    NVIC_DMA1_Channel5_IRQ       = 15,     /* DMA1 channel 5 interrupt. */
    NVIC_DMA1_Channel6_IRQ       = 16,     /* DMA1 channel 6 interrupt. */
    NVIC_DMA1_Channel7_IRQ       = 17,     /* DMA1 channel 7 interrupt. */
    NVIC_ADC1_2_IRQ              = 18,     /* ADC1 and ADC2 global interrupt. */
    NVIC_USB_HP_CAN_TX_IRQ       = 19,     /* USB High Priority/CAN_TX interrupts. */
    NVIC_USB_LP_CAN_RX0_IRQ      = 20,     /* USB Low Priority/CAN_RX0 interrupts. */
    NVIC_CAN_RX1_IRQ             = 21,     /* CAN_RX1 interrupt. */
    NVIC_CAN_SCE_IRQ             = 22,     /* CAN_SCE interrupt. */
    NVIC_EXTI9_5_IRQ             = 23,     /* EXTI Line[9:5] interrupts. */
    NVIC_TIM1_BRK_TIM15_IRQ      = 24,     /* TIM1 Break/TIM15 global interrupts. */
    NVIC_TIM1_UP_TIM16_IRQ       = 25,     /* TIM1 Update/TIM16 global interrupts. */
    NVIC_TIM1_TRG_COM_TIM17_IRQ  = 26,     /* TIM1 trigger and commutation/TIM17 interrupts. */
    NVIC_TIM1_CC_IRQ             = 27,     /* TIM1 capture compare interrupt. */
    NVIC_TIM2_IRQ                = 28,     /* TIM2 global interrupt. */
    NVIC_TIM3_IRQ                = 29,     /* TIM3 global interrupt. */
    NVIC_TIM4_IRQ                = 30,     /* TIM4 global interrupt. */
    NVIC_I2C1_EV_IRQ             = 31,     /* I2C1 event interrupt & EXTI Line23 interrupt. */
    NVIC_I2C1_ER_IRQ             = 32,     /* I2C1 error interrupt. */
    NVIC_I2C2_EV_IRQ             = 33,     /* I2C2 event interrupt & EXTI Line24 interrupt. */
    NVIC_I2C2_ER_IRQ             = 34,     /* I2C2 error interrupt. */
    NVIC_SPI1_IRQ                = 35,     /* SPI1 global interrupt. */
    NVIC_SPI2_IRQ                = 36,     /* SPI2 global interrupt. */
    NVIC_USART1_IRQ              = 37,     /* USART1 global interrupt & EXTI Line 25. */
    NVIC_USART2_IRQ              = 38,     /* USART2 global interrupt & EXTI Line 26. */
    NVIC_USART3_IRQ              = 39,     /* USART3 global interrupt & EXTI Line 28. */
    NVIC_EXTI15_10_IRQ           = 40,     /* EXTI Line[15:10] interrupts. */
    NVIC_RTC_ALARM_IRQ           = 41,     /* RTC alarm interrupt. */
    NVIC_USBWAKEUP_IRQ           = 42,     /* USB wakeup from Suspend (EXTI line 18). */
    NVIC_TIM8_BRK_IRQ            = 43,     /* TIM8 break interrupt. */
    NVIC_TIM8_UP_IRQ             = 44,     /* TIM8 update interrupt. */
    NVIC_TIM8_TRG_COM_IRQ        = 45,     /* TIM8 Trigger and commutation interrupts. */
    NVIC_TIM8_CC_IRQ             = 46,     /* TIM8 capture compare interrupt. */
    NVIC_ADC3_IRQ                = 47,     /* ADC3 global interrupt. */
    NVIC_FMC_IRQ                 = 48,     /* FMC global interrupt. */
    NVIC_SPI3_IRQ                = 51,     /* SPI3 global interrupt. */
    NVIC_UART4_IRQ               = 52,     /* UART4 global and EXTI Line 34 interrupts. */
    NVIC_UART5_IRQ               = 53,     /* UART5 global and EXTI Line 35 interrupts. */
    NVIC_TIM6_DAC_IRQ            = 54,     /* TIM6 global and DAC1 underrun interrupts. */
    NVIC_TIM7_IRQ                = 55,     /* TIM7 global interrupt. */
    NVIC_DMA2_Channel1_IRQ       = 56,     /* DMA2 channel1 global interrupt. */
    NVIC_DMA2_Channel2_IRQ       = 57,     /* DMA2 channel2 global interrupt. */
    NVIC_DMA2_Channel3_IRQ       = 58,     /* DMA2 channel3 global interrupt. */
    NVIC_DMA2_Channel4_IRQ       = 59,     /* DMA2 channel4 global interrupt. */
    NVIC_DMA2_Channel5_IRQ       = 60,     /* DMA2 channel5 global interrupt. */
    NVIC_ADC4_IRQ                = 61,     /* ADC4 global interrupt. */
    NVIC_COMP1_2_3_IRQ           = 64,     /* COMP1 & COMP2 & COMP3 interrupts combined with EXTI [21 - 22 - 29] interrupts. */
    NVIC_COMP4_5_6_IRQ           = 65,     /* COMP4 & COMP5 & COMP6 interrupts combined with EXTI [30 - 31 - 32] interrupts. */
    NVIC_COMP7_IRQ               = 66,     /* COMP7 interrupt combined with EXTI Line 33 interrupt. */
    NVIC_I2C3_EV_IRQ             = 72,     /* I2C3 Event interrupt. */
    NVIC_I2C3_ER_IRQ             = 73,     /* I2C3 Error interrupt. */
    NVIC_USB_HP_IRQ              = 74,     /* USB High priority interrupt. */
    NVIC_USB_LP_IRQ              = 75,     /* USB Low priority interrupt. */
    NVIC_USB_WAKEUP_RMP_IRQ      = 76,     /* USB wake up from Suspend and EXTI Line 18. */
    NVIC_TIM20_BRK_IRQ           = 77,     /* TIM20 Break interrupt. */
    NVIC_TIM20_UP_IRQ            = 78,     /* TIM20 Upgrade interrupt. */
    NVIC_TIM20_TRG_COM_IRQ       = 79,     /* TIM20 Trigger and Commutation interrupt. */
    NVIC_TIM20_CC_IRQ            = 80,     /* TIM20 Capture Compare interrupt. */
    NVIC_FPU_IRQ                 = 81,     /* Floating point interrupt. */
}NVIC_interruptRequestType;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : NVIC_enableInterrupt
 * [Description]   : Enable a specific interrupt or exception.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_enableInterrupt(NVIC_interruptRequestType a_interruptRequestNumber);

/*=====================================================================================================================
 * [Function Name] : NVIC_disableInterrupt
 * [Description]   : Disable a specific interrupt or exception.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_disableInterrupt(NVIC_interruptRequestType a_interruptRequestNumber);

/*=====================================================================================================================
 * [Function Name] : NVIC_setInterruptPending
 * [Description]   : Set the pending status for a specific IRQ.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_setInterruptPending(NVIC_interruptRequestType a_interruptRequestNumber);

/*=====================================================================================================================
 * [Function Name] : NVIC_clearInterruptPending
 * [Description]   : Clear the pending status of a specific IRQ.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_clearInterruptPending(NVIC_interruptRequestType a_interruptRequestNumber);

/*=====================================================================================================================
 * [Function Name] : NVIC_getPendingStatus
 * [Description]   : Get the prending status of a specific IRQ.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 *                   <a_ptr2status>                -> Pointer to a variable to store the pending status.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_getPendingStatus(NVIC_interruptRequestType a_interruptRequestNumber, NVIC_pendingStatusType* a_ptr2status);

/*=====================================================================================================================
 * [Function Name] : NVIC_setInterruptPriority
 * [Description]   : Set the priority value for a specific IRQ [Group and Subgroup].
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 *                   <a_priority>                  -> Indicates to the required priority group and subgroup.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 *                                                          - Priority Value Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_setInterruptPriority(NVIC_interruptRequestType a_interruptRequestNumber, uint8 a_priority);

/*=====================================================================================================================
 * [Function Name] : NVIC_getInterruptPriority
 * [Description]   : Get the priority value of a specific IRQ.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 *                   <a_ptr2priority>              -> Pointer to a variable to store the IRQ priority.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_getInterruptPriority(NVIC_interruptRequestType a_interruptRequestNumber, uint8* a_ptr2priority);

#endif /* MCAL_NVIC_INCLUDES_NVIC_H_ */
