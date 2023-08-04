#ifndef HAL_LCD_CONFIGRATION_H_
#define HAL_LCD_CONFIGRATION_H_

/*
    NOTE::
    vss --> GND
    vdd --> vcc
*/

/**
 * Chose Mode [4bit or 8bit]
 *
 * options:
 *          LCD_8Bit
 *          LCD_4Bit
 */
#define LCD_MODE  LCD_4Bit
/**
 * Chose Nibble [High , Low]
 * options : LCD_HIGH_NIBBLE
 *           LCD_LOW_NIBBLE
 *
 * Note:  invlid in 8 bit Mode
 */

#define LCD_4_BIT_DATA_PIN  LCD_HIGH_NIBBLE

/*
    Chose Port Number for Control Pins:-
    CLCD_ControlPins_PortNum ::
                            kPORTA
                            kPORTB
                            kPORTC
                            kPORTD
 */
#define LCD_ControlPins_PortNum kPORTA

/* Control Pins From kPIN0 --> kPIN7 */
#define RS_PinNum kPIN0
#define RW_PinNum kPIN1
#define EN_PinNum kPIN2

/*
    Chose Port Number for Data Pins:-
    CLCD_DATA_PortNum ::
                            kPORTA
                            kPORTB
                            kPORTC
                            kPORTD
 */
#define LCD_DATA_PortNum kPORTD


#endif/* HAL_LCD_CONFIGRATION_H_ */
