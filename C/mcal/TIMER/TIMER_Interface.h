#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


error_t TIMER0_Init();
error_t TIMER0_Preload(uint16 value);
error_t TIMER0_Handle_ISR(void ( * pFunction) (void));
void TIMER0_WriteValue(uint16 value);
error_t TIMER0_ReadValue(uint16 * value);

#endif
