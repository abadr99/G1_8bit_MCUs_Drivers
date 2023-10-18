#ifndef CALC_H
#define CALC_H

void CalcConf(keypad_t *pKeypad, lcd_t *pLcd);
void Calculator(charStack_t *opStack,
                sint32_tStack_t *numStack, lcd_t *lcd, uint8_t key);
#endif
