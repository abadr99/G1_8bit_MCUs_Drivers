#ifndef BUZZER_H_
#define BUZZER_H

typedef enum
{
    kBuzzerActiveLow,
    kBuzzerActiveHigh
}BuzzerState_t;

/**
 * @brief Buzzer_t    : is the data type to define the Buzzer
 *        port        : for avr [kPORTA ... kPORTD], for pic [kPORTA ... kPORTE]
 *        pin         : [kPIN0 ... kPIN7]
 *        activeState : [kBuzzerActiveLow, kBuzzerActiveHigh]
 *
 */
typedef struct
{
    port_t port;
    pin_t pin;
    BuzzerState_t activeState;
}Buzzer_t;
/**
 * @brief This Function is used to initialize the Buzzer
 *
 * @param pBuzzer : pointer to Buzzer which is a struct from type @Buzzer_t
 */
void Buzzer_Init(Buzzer_t* pBuzzer);
/**
 * @brief This Function is used to turn on the Buzzer
 *
 * @param pBuzzer  : pointer to Buzzer which is a struct from type @Buzzer_t
 * @return error_t : This Function returns kNoError if the Parameter is correct
 *                   and returns kFunctionParameterError
 *                   if the Parameter isn't correct
 */
error_t Buzzer_TurnOn(Buzzer_t* pBuzzer);
/**
 * @brief This Function is used to turn off the Buzzer
 *
 * @param pBuzzer  : pointer to Buzzer which is a struct from type @Buzzer_t
 * @return error_t : This Function returns kNoError if the Parameter is correct
 *                   and returns kFunctionParameterError
 *                   if the Parameter isn't correct
 */
error_t Buzzer_TurnOff(Buzzer_t* pBuzzer);
#endif
