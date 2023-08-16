/**
 * @file   :GIC_Program.c
 * @author :
 * @brief  :This file contain the implementation of GIC function
 * @version:0.1
 * @date   :2023-08-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "../../common/Types.h"
#include "../../common/Registes.h"
#include "GIC_Privete.h"
#include "GIC_Interface.h"

error_t GIC_voidGlobalInterruptControl(uint8_t copyControl)
{
	error_t kErrorState = kNoError;
	switch (copyControl)
	{
		case GLOBAL_INTERRUPT_ENABLE  : SET_BIT(SREG_REG, SREG_I); break;
		case GLOBAL_INTERRUPT_DISABLE : CLR_BIT(SREG_REG, SREG_I); break;

		default: kErrorState = kNoError;	break;
	}
	return kFunctionParameterError;
}
