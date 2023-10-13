#ifndef PIC_ISR_H_
#define PIC_ISR_H_

error_t ISR_Init(uint8_t kInterruptSource, void (*pFun)(void));

#endif
