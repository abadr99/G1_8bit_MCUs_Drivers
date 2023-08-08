#ifndef DC_MOTOR_H
#define DC_MOTOR_H


typedef struct
{
    port_t port;
    pin_t pin1;
    pin_t pin2;
}DcMotor_t;

error_t DcMotor_Init(DcMotor_t * DcMotor);
error_t DcMotor_ClockWise(DcMotor_t * DcMotor);
error_t DcMotor_AntiClockWise(DcMotor_t * DcMotor);
error_t DcMotor_Stop(DcMotor_t * DcMotor);

#endif
