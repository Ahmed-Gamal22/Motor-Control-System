# Motor-Control-System
Control the speed of a DC Motor using a potentiometer.
Potentiometer is connected to the MCU through ADC channel 0, DC Motor speed is controlled through a PWM signal generated from Timer0.
ADC value is displayed on the LCD all the time.
External Interrupt INT1 triggered using raising edge used to reverse the direction of the motor.
