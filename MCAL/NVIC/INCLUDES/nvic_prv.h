/*
=======================================================================================================================
Author       : Mamoun
Module       : NVIC
File Name    : nvic_prv.h
Date Created : Nov 17, 2023
Description  : Private file for the STM32F303 NVIC driver.
=======================================================================================================================
*/


#ifndef MCAL_NVIC_INCLUDES_NVIC_PRV_H_
#define MCAL_NVIC_INCLUDES_NVIC_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#define NVIC_MAX_PRIORITY_GROUP_SUBGROUP_VALUE          (15U)

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef struct
{
    volatile uint32 ISER[8];           /* Interrupt Set-enable Registers.      */
    volatile uint32 RESERVED0[24];     /* Reserved Registers.                  */
    volatile uint32 ICER[8];           /* Interrupt Clear-enable Registers.    */
    volatile uint32 RESERVED1[24];     /* Reserved Registers.                  */
    volatile uint32 ISPR[8];           /* Interrupt Set-pending Registers.     */
    volatile uint32 RESERVED2[24];     /* Reserved Registers.                  */
    volatile uint32 ICPR[8];           /* Interrupt Clear-pending Registers.   */
    volatile uint32 RESERVED3[24];     /* Reserved Registers.                  */
    volatile uint32 IABR[8];           /* Interrupt Active Bit Registers.      */
    volatile uint32 RESERVED4[56];     /* Reserved Registers.                  */
    volatile uint8  IPR[240];          /* Interrupt Priority Registers.        */
    volatile uint32 RESERVED5[643];    /* Reserved Registers.                  */
    volatile uint32 STIR;              /* Software Trigger Interrupt Register. */
}NVIC_registersType;

/*=====================================================================================================================
                                < Peripheral Registers and Bits Definitions >
=====================================================================================================================*/

#define NVIC                              ((volatile NVIC_registersType*)0XE000E100)

/*=====================================================================================================================
                                         < Function-like Macros >
=====================================================================================================================*/

/* Get the register number that includes the required IRQ bit. */
#define NVIC_GET_EXCEPTION_REGISTER(IRQ)     ((unsigned long)IRQ / (unsigned long)32)
/* Get the bit number for the required IRQ. */
#define NVIC_GET_EXCEPTION_BIT(IRQ)          ((unsigned long)IRQ % (unsigned long)32)

#endif /* MCAL_NVIC_INCLUDES_NVIC_PRV_H_ */
