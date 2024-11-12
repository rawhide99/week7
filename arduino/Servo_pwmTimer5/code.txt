#include <avr/io.h>
#include <avr/interrupt.h>

#define SERVO_PIN 9
volatile uint16_t pulseWidth = 1500;

void setup() 
{
  pinMode(SERVO_PIN, OUTPUT);
  TCCR1A = (1 << WGM11) | (1 << COM1A1); // Fast PWM mode, non-inverting
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Prescaler of 8
  ICR1 = 20000;
  sei();

}

void loop()
{
  for(int angle = 0; angle <= 180; angle += 10)
  {
    pulseWidth = map(angle, 0, 180, 1000, 2000);
    OCR1A = pulseWidth;
    delay(500);
  }

  for (int angle = 180; angle >= 0; angle -= 10) 
  {
    pulseWidth = map(angle, 0, 360, 1000, 2000);
    OCR1A = pulseWidth;
    delay(500);
  }

}
