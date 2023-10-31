// Define the built-in LED pin and current index for tracking characters
int led_builtIn = 13;
volatile int currentindex = 0;

// Define the button pin and initialize a name variable
int buttonPin = 2;
String name = "Saksham";
bool isBlinking = false;

// Setup function runs once at the start
void setup() {
  // Set the LED pin as an output
  pinMode(led_builtIn, OUTPUT);
  
  // Set the button pin as an input with a pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  // Attach an interrupt to the button pin that triggers the 'start' function on a falling edge
  attachInterrupt(digitalPinToInterrupt(buttonPin), start, FALLING);

  // Start serial communication for debugging
  Serial.begin(9600);
}

// 'start' function is triggered by the button press
void start() {
  // Set the flag to indicate that blinking should start
  isBlinking = true;
  // Reset the character index
  currentindex = 0;
}

// Loop function runs repeatedly
void loop() {
  // If the flag is set, start blinking the name
  if (isBlinking) {
    Serial.println(name);
    BlinkName();
    // Reset the flag to stop continuous blinking
    isBlinking = false;
  }
}

// Function to blink the name character by character
void BlinkName() {
  // Loop through each character in the name
  for (currentindex; currentindex < name.length(); currentindex++) {
    // Blink the Morse code representation of the character
    BlinkCharacters(name[currentindex]);
    // Delay before moving to the next character
    delay(1000);
  }
}

// Function to blink a dot in Morse code
void BlinkDot() {
  digitalWrite(led_builtIn, HIGH);
  delay(300);
  digitalWrite(led_builtIn, LOW);
  delay(300);
}

// Function to blink a dash in Morse code
void BlinkDash() {
  digitalWrite(led_builtIn, HIGH);
  delay(900);
  digitalWrite(led_builtIn, LOW);
  delay(300);
}

// Function to blink the Morse code representation of a character
void BlinkCharacters(char curcharacter) {
  // Switch case to determine the Morse code pattern for each character
  switch (curcharacter) {
    case 'a':
      BlinkDot();
      BlinkDash();
      break;
    case 'b':
      BlinkDash();
      BlinkDot();
      BlinkDot();
      BlinkDot();
      break;
    // Continue the switch case for the remaining characters...
  }
}
