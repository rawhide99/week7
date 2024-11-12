#include <Servo.h>

const int potPin = A0;      // Potentiometer connected to analog pin A0
const int servoPin = 9;     // Servo motor connected to digital pin 9
Servo myServo;               // Create a Servo object

void setup() 
{
    myServo.attach(servoPin); // Attach the servo to its pin
    Serial.begin(9600);        // Start serial communication for debugging
}

void loop() 
{
    int potValue = analogRead(potPin); // Read potentiometer value (0-1023)
    
    // Map potentiometer value to servo angle (180 degrees inverted)
    int angle = map(potValue, 0, 1023, 180, 0); // Inverted mapping

    myServo.write(angle); // Set servo position based on inverted potentiometer value
    Serial.print("Potentiometer Value: ");
    Serial.print(potValue);
    Serial.print(" -> Servo Angle: ");
    Serial.println(angle);

    delay(15); // Wait for the servo to reach the position
}