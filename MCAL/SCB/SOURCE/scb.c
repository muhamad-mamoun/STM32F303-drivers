/*
=======================================================================================================================
Author       : Mamoun
Module       : System Control Block
File Name    : scb.c
Date Created : Nov 16, 2023
Description  : Source file for the STM32 System Control Block driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/scb_prv.h"
#include "../INCLUDES/scb_cfg.h"
#include "../INCLUDES/scb.h"

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : SCB_setPriorityLevel
 * [Description]   : Set the priority group level [The bit point for the priority group and subgroup].
 * [Arguments]     : <a_priorityLevel>     -> Indicates to the required priority group level to be select.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Priority Level Error.
 ====================================================================================================================*/
SCB_errorStatusType SCB_setPriorityLevel(SCB_priorityLevelType a_priorityLevel)
{
    SCB_errorStatusType LOC_errorStatus = SCB_NO_ERRORS;

    if(a_priorityLevel > SCB_PRIGROUP_LEVEL_E)
    {
        LOC_errorStatus = SCB_PRIORITY_LEVEL_ERROR;
    }

    else
    {
        SCB->AIRCR = ((SCB->AIRCR & 0XF8FF) | (SCB_AIRCR_WRITE_VECTKEY << SCB_AIRCR_VECTKEY_FIELD) | (a_priorityLevel << SCB_AIRCR_PRIGROUP_FIELD));
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : SCB_getPriorityLevel
 * [Description]   : Set the value of the priority group level.
 * [Arguments]     : <a_ptr2priorityLevel>     -> Pointer to variable to store the priority level.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SCB_errorStatusType SCB_getPriorityLevel(SCB_priorityLevelType* a_ptr2priorityLevel)
{
    SCB_errorStatusType LOC_errorStatus = SCB_NO_ERRORS;

    if(a_ptr2priorityLevel == NULL_PTR)
    {
        LOC_errorStatus = SCB_NULL_PTR_ERROR;
    }

    else
    {
        *a_ptr2priorityLevel = ((SCB->AIRCR & 0X0700) >> SCB_AIRCR_PRIGROUP_FIELD);
    }

    return LOC_errorStatus;
}

