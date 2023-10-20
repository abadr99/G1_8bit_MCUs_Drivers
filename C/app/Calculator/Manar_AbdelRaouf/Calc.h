#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_
#include "../../../utils/stack/stack.h"
/**
 * @brief This function is the  main function for my APP , All You have
 * have to do is call this for the App to start.
 * @param pKeypad pointer to Keypad is used
 * @param pLCD    pointer to LCD is used
 * @return error_t
 */
void Calculator_Init();
error_t Calculator(keypad_t * pKeypad, lcd_t * pLCD);
uint8_t Input(keypad_t * pKeypad);
void Output(lcd_t * pLCD, uint8_t outputChar);
f32_t Evaluate(f32_t num1, f32_t num2, uint8_t op);
uint8_t Priority(char op);
f32_t  IsEqual(charStack_t * opStack, f32_tStack_t * numStack);
void PushOp(charStack_t * opStack, f32_tStack_t * numStack, uint8_t op, lcd_t * pLCD);
void DisplayResult(lcd_t  * pLCD, f32_t result);
#endif
