/**
 * @file   EXTI_Private.h
 * @author :Mohamed Refat
 * @brief  :This file contain private macros and interfaces
 * @version: 0.1
 * @date   : 2023-08-16
 */
#ifndef MCAL_EXTI_PRIVATE_H_
#define MCAL_EXTI_PRIVATE_H_

#if MCU_TYPE == _AVR
#define GICR_INT0     (6)
#define GICR_INT1     (7)
#define GICR_INT2     (5)


#define MCUCR_ISC00   (0)
#define MCUCR_ISC01   (1)
#define MCUCR_ISC10   (2)
#define MCUCR_ISC11   (3)

#define MCUCSR_ISC2   (6)

#elif MCU_TYPE == _PIC

#define EXIT_LOW_PRIORITY  (0)
#define EXIT_HIGH_PRIORITY (1)

#define INTCON_RBIF        (0)      /**<RB Port Change Interrupt Flag bit*/
#define INTCON_INT0F       (1)      /**<INT0 External Interrupt Flag bit*/
#define INTCON_RBIE        (3)      /**<RB Port Change Interrupt Enable bit*/
#define INTCON_INT0E       (4)      /**<INT0 External Interrupt Enable bit*/

#define INTCON2_RBIP       (0)      /**<RB Port Change Interrupt Priority bit*/
#define INTCON2_INTEDG2    (4)      /**<External Interrupt 2 Edge Select bit*/
#define INTCON2_INTEDG1    (5)      /**<External Interrupt 1 Edge Select bit*/
#define INTCON2_INTEDG0    (6)      /**<External Interrupt 0 Edge Select bit*/

#define INTCON3_INT1IF     (0)      /**<INT1 External Interrupt Flag bit*/
#define INTCON3_INT2IF     (1)      /**<INT2 External Interrupt Flag bit*/
#define INTCON3_INT1IE     (3)      /**<INT1 External Interrupt Enable bit*/
#define INTCON3_INT2IE     (4)      /**<INT2 External Interrupt Enable bit*/
#define INTCON3_INT1IP     (6)      /**<INT1 External Interrupt Priority bit*/
#define INTCON3_INT2IP     (7)      /**<INT2 External Interrupt Priority bit*/

#endif /*MCU_TYPE*/


#endif /* MCAL_EXTI_PRIVATE_H_ */
