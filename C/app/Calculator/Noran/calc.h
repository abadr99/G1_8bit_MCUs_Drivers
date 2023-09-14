#ifndef CALC_H_
#define CALC_H_
/**
 * @brief When keyval is number the program
 *        will return this value
 */
#define NUMBER (1)
/**
 * @brief When keyval is operator the program
 *        will return this value
 */
#define OPERATOR (0)

#define OPERATOR_SIZE (30)
#define NUMBER_SIZE (31)
 /**
  * @brief This Function is used to detremine
  *        if the keyval is number or operator
  * @param key the key pressed.
  * @return uint8_t This Function returns NUMBER if the Parameter is number
  *                 and returns OPERATOR if it is operator
  */
uint8_t ISNUM(uint8_t key);
 /**
  * @brief This Function is used to detremine  the Precedence of the operator
  * @param operator
  * @return uint8_t This Function returns the Precedence of this operator
  *         compared to the previous operator
  */
uint8_t GetPrecedence(uint8_t operator);
/**
 * @brief This Function is used to evaluate the operation
 * @param num1 the first operand
 * @param num2 the second operand
 * @param operator the operator
 * @return sint32 the result from this operation
 */
sint32 Operate(sint32 num1, sint32 num2, uint8_t operator);
void Evaluate(sint32 *ar, uint8_t *arr, sint16 size1, sint16 size2);
#endif
