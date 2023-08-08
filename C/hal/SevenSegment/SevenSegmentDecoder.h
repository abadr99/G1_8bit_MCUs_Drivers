#ifndef SEG_H_
#define SEG_H_


#define TOTAL_DECODER_PINS  (4)
#define MAX_NUM (9)
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
 * @brief sevenSegDecoder_t is the data type to define the seven segment
 * which is an array gathering all pins
 */
typedef struct
{
 sevenSegPin_t segment[TOTAL_DECODER_PINS];
}sevenSegDecoder_t;
/**
 * @brief This Function is used to initialize the seven segment
 * @param pSevenSeg pointer to the seven segment decoder
 * which is a struct from type sevenSegDecoder_t
 * @return error_t to handle error cases
 */
error_t SevenSegmentDecoder_Init(sevenSegDecoder_t * pSevenSeg);
/**
 * @brief This Function is used to set the seven segment to specific number
 * @param pSevenSeg pointer to the seven segment decoder
 * which is a struct from type sevenSegDecoder_t
 * @param number the number you want to set seven segment to
 * @return error_t handle error cases
 */
error_t SevenSegmentDecoder_Set( sevenSegDecoder_t * pSevenSeg, uint8_t number);

#endif /* SEG_H_ */
