/*
=======================================================================================================================
Author       : Mamoun
Module       : NVIC
File Name    : nvic.c
Date Created : Nov 17, 2023
Description  : Source file for the STM32F303 NVIC driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../../SCB/INCLUDES/scb.h"
#include "../INCLUDES/nvic_prv.h"
#include "../INCLUDES/nvic_cfg.h"
#include "../INCLUDES/nvic.h"

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : NVIC_enableInterrupt
 * [Description]   : Enable a specific interrupt or exception.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_enableInterrupt(NVIC_interruptRequestType a_interruptRequestNumber)
{
    NVIC_errorStatusType LOC_errorStatus = NVIC_NO_ERRORS;

    if((a_interruptRequestNumber < NVIC_WWDG_IRQ) || (a_interruptRequestNumber > NVIC_FPU_IRQ))
    {
        LOC_errorStatus = NVIC_IRQ_NUM_ERROR;
    }

    else
    {
        SET_BIT(NVIC->ISER[NVIC_GET_EXCEPTION_REGISTER(a_interruptRequestNumber)],NVIC_GET_EXCEPTION_BIT(a_interruptRequestNumber));
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : NVIC_disableInterrupt
 * [Description]   : Disable a specific interrupt or exception.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_disableInterrupt(NVIC_interruptRequestType a_interruptRequestNumber)
{
    NVIC_errorStatusType LOC_errorStatus = NVIC_NO_ERRORS;

    if((a_interruptRequestNumber < NVIC_WWDG_IRQ) || (a_interruptRequestNumber > NVIC_FPU_IRQ))
    {
        LOC_errorStatus = NVIC_IRQ_NUM_ERROR;
    }

    else
    {
        SET_BIT(NVIC->ICER[NVIC_GET_EXCEPTION_REGISTER(a_interruptRequestNumber)],NVIC_GET_EXCEPTION_BIT(a_interruptRequestNumber));
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : NVIC_setInterruptPending
 * [Description]   : Set the pending status for a specific IRQ.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_setInterruptPending(NVIC_interruptRequestType a_interruptRequestNumber)
{
    NVIC_errorStatusType LOC_errorStatus = NVIC_NO_ERRORS;

    if((a_interruptRequestNumber < NVIC_WWDG_IRQ) || (a_interruptRequestNumber > NVIC_FPU_IRQ))
    {
        LOC_errorStatus = NVIC_IRQ_NUM_ERROR;
    }

    else
    {
        SET_BIT(NVIC->ISPR[NVIC_GET_EXCEPTION_REGISTER(a_interruptRequestNumber)],NVIC_GET_EXCEPTION_BIT(a_interruptRequestNumber));
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : NVIC_clearInterruptPending
 * [Description]   : Clear the pending status of a specific IRQ.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_clearInterruptPending(NVIC_interruptRequestType a_interruptRequestNumber)
{
    NVIC_errorStatusType LOC_errorStatus = NVIC_NO_ERRORS;

    if((a_interruptRequestNumber < NVIC_WWDG_IRQ) || (a_interruptRequestNumber > NVIC_FPU_IRQ))
    {
        LOC_errorStatus = NVIC_IRQ_NUM_ERROR;
    }

    else
    {
        SET_BIT(NVIC->ICPR[NVIC_GET_EXCEPTION_REGISTER(a_interruptRequestNumber)],NVIC_GET_EXCEPTION_BIT(a_interruptRequestNumber));
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : NVIC_getPendingStatus
 * [Description]   : Get the prending status of a specific IRQ.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 *                   <a_ptr2status>                -> Pointer to a variable to store the pending status.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_getPendingStatus(NVIC_interruptRequestType a_interruptRequestNumber, NVIC_pendingStatusType* a_ptr2status)
{
    NVIC_errorStatusType LOC_errorStatus = NVIC_NO_ERRORS;

    if(a_ptr2status == NULL_PTR)
    {
        LOC_errorStatus = NVIC_NULL_PTR_ERROR;
    }

    else if((a_interruptRequestNumber < NVIC_WWDG_IRQ) || (a_interruptRequestNumber > NVIC_FPU_IRQ))
    {
        LOC_errorStatus = NVIC_IRQ_NUM_ERROR;
    }

    else
    {
        *a_ptr2status = GET_BIT(NVIC->IABR[NVIC_GET_EXCEPTION_REGISTER(a_interruptRequestNumber)],NVIC_GET_EXCEPTION_BIT(a_interruptRequestNumber));
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : NVIC_setInterruptPriority
 * [Description]   : Set the priority value for a specific IRQ [Group and Subgroup].
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 *                   <a_priority>                  -> Indicates to the required priority group and subgroup.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 *                                                          - Priority Value Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_setInterruptPriority(NVIC_interruptRequestType a_interruptRequestNumber, uint8 a_priority)
{
    NVIC_errorStatusType LOC_errorStatus = NVIC_NO_ERRORS;

    if((a_interruptRequestNumber < NVIC_WWDG_IRQ) || (a_interruptRequestNumber > NVIC_FPU_IRQ))
    {
        LOC_errorStatus = NVIC_IRQ_NUM_ERROR;
    }

    else if(a_priority > NVIC_MAX_PRIORITY_GROUP_SUBGROUP_VALUE)
    {
        LOC_errorStatus = NVIC_PRIORITY_ERROR;
    }

    else
    {
        NVIC->IPR[a_interruptRequestNumber] = ((NVIC->IPR[a_interruptRequestNumber] & 0X0F) | ((a_priority & 0X0F) << 4));
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : NVIC_getInterruptPriority
 * [Description]   : Get the priority value of a specific IRQ.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 *                   <a_ptr2priority>              -> Pointer to a variable to store the IRQ priority.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_getInterruptPriority(NVIC_interruptRequestType a_interruptRequestNumber, uint8* a_ptr2priority)
{
    NVIC_errorStatusType LOC_errorStatus = NVIC_NO_ERRORS;

    if((a_interruptRequestNumber < NVIC_WWDG_IRQ) || (a_interruptRequestNumber > NVIC_FPU_IRQ))
    {
        LOC_errorStatus = NVIC_IRQ_NUM_ERROR;
    }

    else if(a_ptr2priority == NULL_PTR)
    {
        LOC_errorStatus = NVIC_NULL_PTR_ERROR;
    }

    else
    {
        *a_ptr2priority = GET_H_NIB(NVIC->IPR[a_interruptRequestNumber]);
    }

    return LOC_errorStatus;
}