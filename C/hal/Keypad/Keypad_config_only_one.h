#ifndef CONFIG_H_
#define CONFIG_H_

#define Keypad_numberOfRows (4)
#define Keypad_numberOfCols (3)


uint8_t keypadButtons[Keypad_numberOfRows]
                     [Keypad_numberOfCols] = {{'1', '2', '3'},
                                              {'4', '5', '6'},
                                              {'7', '8', '9'},
                                              {'*', '0', '#'}
                                             };

#endif
