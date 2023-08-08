#ifndef SEVEN_H_
#define SEVEN_H_

#define TOTAL_PINS (7)


#define MAX_NUM (9)


#define ZERO (0x3F)
#define ONE (0x06)
#define TWO (0x5B)
#define THREE (0x4F)
#define FOUR (0x66)
#define FIVE (0x6D)
#define SIX (0x7D)
#define SEVEN (0x07)
#define EIGHT (0x7F)
#define NINE (0x6F)
/**
 * @brief  sevenSegPin_t: is the data type to define the seven segment pin
 *         port: for avr [kPORTA ... kPORTD], for pic [kPORTA ... kPORTE]
 *         pin: [kPIN0 ... kPIN7]
 */
typedef struct
{
    port_t port;
    pin_t pin;
}sevenSegPin_t;
/**
 * @brief sevenSegment_t is the data type to define the seven segment
 * which is an array gathering all pins
 */
typedef struct
{
 sevenSegPin_t segment[TOTAL_PINS];
}sevenSegment_t;
/**
 * @brief This Function is used to initialize the seven segment
 * @param pSevenSeg pointer to the seven segment
 * which is a struct from type sevenSegment_t
 * @return error_t to handle error cases
 */
error_t SevenSegmentInit(sevenSegment_t* pSevenSeg);
/**
 * @brief This Function is used to set the seven segment to specific number
 * @param pSevenSeg pointer to the seven segment
 * which is a struct from type sevenSegment_t
 * @param number the number you want to set seven segment to
 * @return error_t handle error cases
 */
error_t SevenSegmentSet(sevenSegment_t * pSevenSeg, uint8_t number);
void SetNumber(sevenSegment_t * pSevenSeg, uint8_t number);
#endif /* SEVEN_H_ */
