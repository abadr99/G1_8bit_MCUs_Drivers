#ifndef HAL_LCD_INTERFACE_H_
#define HAL_LCD_INTERFACE_H_

#define LCD_ROW_1  1
#define LCD_ROW_2  2

#define LCD_COL_1  1
#define LCD_COL_2  2
#define LCD_COL_3  3
#define LCD_COL_4  4
#define LCD_COL_5  5
#define LCD_COL_6  6
#define LCD_COL_7  7
#define LCD_COL_8  8
#define LCD_COL_9  9
#define LCD_COL_10 10
#define LCD_COL_11 11
#define LCD_COL_12 12
#define LCD_COL_13 13
#define LCD_COL_14 14
#define LCD_COL_15 15
#define LCD_COL_16 16

void LCD_Init(void);
void LCD_ClearScreen(void);
void LCD_SendtChar(uint8_t Ch);
void LCD_SendString(uint8_t str[]);
void LCD_StoreCustomChar(uint8_t pChar_Arr[], uint8_t Location);
void LCD_SendCustomChar(uint8_t Location, uint8_t Row_Num, uint8_t Col_Num);
/**
 * @brief             :this function used to set cursor position
 *                      to display your data in s specific position
 *
 * @param Row_Num     :Row_Num    --> [LCD_ROW_1 , LCD_ROW_2]
 * @param Column_Num  :Column_Num --> [LCD_COL_1 , LCD_COL_2 ... LCD_COL_16]
 */
void LCD_SetPosition(uint8_t Row_Num, uint8_t Column_Num);

void LCD_SendNumber(sint16 Num);
void LCD_SendFloat(f32_t Num);

void LCD_EnableCursor(void);
void LCD_DisableCursor(void);

void LCD_ShiftRight(void);
void LCD_ShiftLeft(void);

void LCD_Display_On(void);
void LCD_Display_Off(void);

void LCD_Blink_On(void);
void LCD_Blink_Off(void);


#endif /* HAL_LCD_INTERFACE_H_ */
