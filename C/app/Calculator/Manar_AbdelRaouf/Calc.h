#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_
/**
 * @brief This function is the  main function for my APP , All You have
 * have to do is call this for the App to start.
 * @param pKeypad pointer to Keypad is used
 * @param pLCD    pointer to LCD is used
 * @return error_t
 */
error_t Calculator(keypad_t * pKeypad, lcd_t * pLCD);
f32_t Input(keypad_t * pKeypad);
void Output(lcd_t * pLCD, f32_t outputChar);
f32_t Evaluate(f32_t num1, f32_t num2, f32_t op);
uint8_t Priority(f32_t op);
f32_t  IsEqual(Stack_t * opStack, Stack_t * numStack);
void PushOp(Stack_t * opStack, Stack_t * numStack, f32_t op);
void DisplayResult(lcd_t  * pLCD, f32_t result);
#endif
