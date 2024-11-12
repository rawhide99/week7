#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_PIN 7       // Pin for the LED
#define BUTTON_PIN 2    // Pin for the button

volatile bool ledState = false;      // LED state
volatile bool buttonPressed = false; // Button press state

void setup() 
{
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate

  // Set the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Set the button pin as an input with pull-up resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Timer1 setup for LED blinking (every 1s)
  TCCR1A = 0;                // Normal mode
  TCCR1B = (1 << WGM12) | (1 << CS12); // CTC mode, prescaler = 256
  OCR1A = 62499;              // Compare match value for 1s
  TIMSK1 = (1 << OCIE1A);    // Enable Timer1 compare interrupt

  // Timer2 setup for button press detection (every 100ms)
  TCCR2A = 0;                // Normal mode
  TCCR2B = (1 << WGM22) | (1 << CS22); // CTC mode, prescaler = 64
  OCR2A = 249;               // Compare match value for 100ms (16MHz / 64 prescaler / 10Hz)
  TIMSK2 = (1 << OCIE2A);    // Enable Timer2 compare interrupt
  
  sei();                     // Enable global interrupts
}

void loop() 
{
  // Main loop does not need to handle the LED or button directly

  // Check if the button was pressed (flag set by Timer2 ISR)
  if (buttonPressed) 
  {
    buttonPressed = false;  // Reset the flag after processing
    Serial.println("Button is pressed.");
  }
}

// Timer1 ISR: Handles LED blinking every 500ms
ISR(TIMER1_COMPA_vect) 
{
  ledState = !ledState;               // Toggle the LED state
  digitalWrite(LED_PIN, ledState);    // Update the LED pin
}

// Timer2 ISR: Handles button press detection every 100ms
ISR(TIMER2_COMPA_vect) 
{
  bool currentButtonState = digitalRead(BUTTON_PIN) == LOW;  // Check if button is pressed (active-low)

  static bool lastButtonState = HIGH;  // Initialize to HIGH (button not pressed)

  // Detect falling edge (button press detection)
  if (lastButtonState == HIGH && currentButtonState == LOW) 
  {
    buttonPressed = true;  // Set flag indicating button was pressed
  }

  // Update the last button state
  lastButtonState = currentButtonState;
}
