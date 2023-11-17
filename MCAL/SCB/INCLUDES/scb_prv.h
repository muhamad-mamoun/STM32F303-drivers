/*
=======================================================================================================================
Author       : Mamoun
Module       : System Control Block
File Name    : scb_prv.h
Date Created : Nov 16, 2023
Description  : Private file for the STM32 System Control Block driver.
=======================================================================================================================
*/


#ifndef MCAL_SCB_INCLUDES_SCB_PRV_H_
#define MCAL_SCB_INCLUDES_SCB_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#define SCB_AIRCR_PRIGROUP_FIELD                    (8U)     /* The number of the base bit for the PRIGROUP field. */
#define SCB_AIRCR_VECTKEY_FIELD                     (16U)    /* The number of the base bit for the VECTKEY field.  */
#define SCB_AIRCR_READ_VECTKEY                      (0XFA05) /* The key value to read in VECTKEY field.            */
#define SCB_AIRCR_WRITE_VECTKEY                     (0X05FA) /* The key value to write in VECTKEY field.           */

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef struct
{
    volatile uint32 CPUID;
    volatile uint32 ICSR;
    volatile uint32 VTOR;
    volatile uint32 AIRCR;
    volatile uint32 SCR;
    volatile uint32 CCR;
    volatile uint32 SHPR1;
    volatile uint32 SHPR2;
    volatile uint32 SHPR3;
    volatile uint32 SHCRS;
    volatile uint32 CFSR;
}SCB_registersType;

/*=====================================================================================================================
                                < Peripheral Registers and Bits Definitions >
=====================================================================================================================*/

#define SCB                              ((volatile SCB_registersType*)0XE000ED00) /* SCB registers base address. */

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/



#endif /* MCAL_SCB_INCLUDES_SCB_PRV_H_ */
