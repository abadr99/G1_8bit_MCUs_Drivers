/**
 * @file    EXTI_Interface.h
 * @author : Mohamed Refat
 * @brief  : This file contain the prototype of the
 *              External Interrupts
 * @version:0.1
 * @date   :2023-08-16
 */
#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#define EXTI_INT0 (0)
#define EXTI_INT1 (1)
#define EXTI_INT2 (2)
#define EXTI_RB   (3)

#define EXTI_FALLING_EDGE (4)
#define EXTI_RISING_EDGE  (5)
#define EXTI_LOW_LEVEL    (6)
#define EXTI_ON_CHANGE    (7)

#define INTCON_RBIF        (0)      /**<RB Port Change Interrupt Flag bit*/
#define INTCON_INT0F       (1)      /**<INT0 External Interrupt Flag bit*/
#define INTCON_RBIE        (3)      /**<RB Port Change Interrupt Enable bit*/
#define INTCON_INT0E       (4)      /**<INT0 External Interrupt Enable bit*/

#define INTCON2_INTRBIP    (0)      /**<RB Port Change Interrupt Priority bit*/
#define INTCON2_INTEDG2    (4)      /**<External Interrupt 2 Edge Select bit*/
#define INTCON2_INTEDG1    (5)      /**<External Interrupt 1 Edge Select bit*/
#define INTCON2_INTEDG0    (6)      /**<External Interrupt 0 Edge Select bit*/

#define INTCON3_INT1IF     (0)      /**<INT1 External Interrupt Flag bit*/
#define INTCON3_INT2IF     (1)      /**<INT2 External Interrupt Flag bit*/
#define INTCON3_INT1IE     (3)      /**<INT1 External Interrupt Enable bit*/
#define INTCON3_INT2IE     (4)      /**<INT2 External Interrupt Enable bit*/
#define INTCON3_INT1IP     (6)      /**<INT1 External Interrupt Priority bit*/
#define INTCON3_INT2IP     (7)      /**<INT2 External Interrupt Priority bit*/

error_t EXTI_InterruptEnable (uint8_t kInterruptSource);
/**
 * @brief
 *
 * @param kInterruptSource :
 * @return  error_t   :NoError:
 *                          if function  parameter is Correct
 *                    :kFunctionParameterError:
 *                          if function  parameter is wrong
 */
error_t EXTI_InterruptDisable(uint8_t kInterruptSource);
/**
 * @brief : This fuction is used to Disable a specific External interrupt
 *
 * @param kInterruptSource  : copy from EXTI Number   OPTIONS:
 *                             [EXTI_INT0 ,EXTI_INT0 , EXTI_INT0]
 *
 * @param kSenseControl : copy From Sense control. OPTIONS:
 *                             EXTI_FALLING_EDGE   EXTI_RISING_EDGE
 *                             EXTI_LOW_LEVEL      EXTI_ON_CHANGE
 *
 * @note : For EXTI_INT2 the only valid sense control is
 *                          [EXTI_RISING_EDGE , EXTI_FALLING_EDGE ]
 *
 * @return  error_t :NoError:
 *                        if function  parameter is Correct
 *                  :kFunctionParameterError:
 *                          if function  parameter is wrong
 */
error_t EXTI_SetSenseControl(uint8_t kInterruptSource, uint8_t kSenseControl);
/**
 * @brief             : This function is used to set call back function
 *
 * @param kInterruptSource  : copy from EXTI Number   OPTIONS:
 *                             [EXTI_INT0 ,EXTI_INT0 , EXTI_INT0]
 *
 * @param pFun : pFun is a pointer to the function that will be passed to ISR
 * @return  error_t :NoError:
 *                        if function  parameter is Correct
 *                  :kFunctionParameterError:
 *                         if function  parameter is wrong
 */
error_t EXTI_SetCallBackFun  (uint8_t kInterruptSource, void (*pFun)(void));
#if MCU_TYPE == _PIC
/**
 * @brief       : This Function is used to Clear Flag of External Interrupt bit
 *
 * @param kInterruptSource :    copy from EXTI Number   OPTIONS:
 *                             [EXTI_INT0 ,EXTI_INT0 , EXTI_INT0]
 * @return error_t         :    :NoError:
 *                          if function  parameter is Correct
 *                    :kFunctionParameterError:
 *                          if function  parameter is wrong
 */
error_t EXTI_ClearFlag(uint8_t kInterruptSource);
/**
 * @brief       : This Function is used to Set Priority of External Interrupt
 *
 * @param kInterruptSource :    copy from EXTI Number   OPTIONS:
 *                             [EXTI_INT0 ,EXTI_INT0 , EXTI_INT0]
 * @param kInterruptPriority :  copy from EXIT Priority OPTIONS:
 *                             [EXIT_HIGH_PRIORITY, EXIT_LOW_PRIORITY ]
 * @return error_t
 */
error_t EXTI_SetPriority(uint8_t kInterruptSource, uint8_t kInterruptPriority);
#endif

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
