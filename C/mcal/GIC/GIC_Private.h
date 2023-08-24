/**
 * @file   GIC_Private.h
 * @author :Mohamed Refat
 * @brief  : This file contain private macros and interfaces
 * @version: 0.1
 * @date   :2023-08-16
 */
#ifndef MCAL_GIC_GIE_PRIVATE_H_
#define MCAL_GIC_GIE_PRIVATE_H_


#define SREG_I        (7)

#define RCON_IPEN     (7)    /**Interrupt Priority Enable bit*/

#define Priority_Pin  (GET_BIT(RCON_REG, RCON_IPEN))

#if Priority_Pin == Priority_INTERRUPT_ENABLE
#define INTCON_GIEH   (7)    /**<High Priority Interrupt Enable bit*/
#define INTCON_GIEL   (6)     /**<Low Priority Interrupt Enable bit*/
#elif Priority_Pin == Priority_INTERRUPT_DISABLE
#define INTCON_GIE    (7)    /**<Global Interrupt Enable bit*/
#define INTCON_PEIE   (6)    /**<Peripheral Interrupt Enable bit*/
#endif

#endif /* MCAL_GIC_GIE_PRIVATE_H_ */
