// Pin configuration
int led_builtIn = 13; // Pin number for the built-in LED
volatile int currentindex = 0; // Index to keep track of the current character

// Button configuration
int buttonPin = 2; // Pin number for the button
String name = "Saksham"; // Name to be blinked in Morse code
bool isBlinking = false; // Flag to indicate if blinking is in progress

// Setup function runs once at the beginning
void setup() {
  pinMode(led_builtIn, OUTPUT); // Set LED pin as output
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with pull-up resistor
  attachInterrupt(digitalPinToInterrupt(buttonPin), start, FALLING); // Attach interrupt to the button pin, trigger on falling edge, call start function
  Serial.begin(9600); // Start serial communication for debugging
}

// Interrupt service routine (ISR) for the button press
void start() {
  isBlinking = true; // Set the flag to start blinking
  currentindex = 0; // Reset the character index
}

// Main loop that runs continuously
void loop() {
  if (isBlinking) { // Check if blinking is requested
    Serial.println(name); // Print the name to serial for debugging
    BlinkName(); // Call the function to blink the name in Morse code
    isBlinking = false; // Reset the blinking flag
  }
}

// Function to blink the characters of the name in Morse code
void BlinkName() {
  for (currentindex; currentindex < name.length(); currentindex++) { // Loop through each character in the name
    BlinkCharacters(name[currentindex]); // Call the function to blink the Morse code for the current character
    delay(1000); // Delay between characters
  }
}

// Functions to blink Morse code for dots and dashes
void BlinkDot() {
  digitalWrite(led_builtIn, HIGH);
  delay(300);
  digitalWrite(led_builtIn, LOW);
  delay(300);
}

void BlinkDash() {
  digitalWrite(led_builtIn, HIGH);
  delay(900);
  digitalWrite(led_builtIn, LOW);
  delay(300);
}

// Function to blink Morse code for each character
void BlinkCharacters(char curcharacter) {
  // Morse code for each letter
  if (curcharacter == 'a') {
    BlinkDot();
    BlinkDash();
  }
    if (curcharacter == 'b') {
    BlinkDash();
    BlinkDot();
    BlinkDot();
    BlinkDot();
  }
  if (curcharacter == 'c') {
    BlinkDash();
    BlinkDot();
    BlinkDash();
    BlinkDot();
  }
  if (curcharacter == 'd') {
    BlinkDash();
    BlinkDot();
    BlinkDot();
  }
  if (curcharacter == 'e') {
    BlinkDot();
  }
  if (curcharacter == 'f') {
    BlinkDot();
    BlinkDot();
    BlinkDash();
    BlinkDot();
  }
  if (curcharacter == 'g') {
    BlinkDash();
    BlinkDash();
    BlinkDot();
  }
  if (curcharacter == 'h') {
    BlinkDot();
    BlinkDot();
    BlinkDot();
    BlinkDot();
  }
  if (curcharacter == 'i') {
    BlinkDot();
    BlinkDot();
  }
  if (curcharacter == 'j') {
    BlinkDot();
    BlinkDash();
    BlinkDash();
    BlinkDash();
  }
  if (curcharacter == 'k') {
    BlinkDash();
    BlinkDot();
    BlinkDash();
  }
  if (curcharacter == 'l') {
    BlinkDot();
    BlinkDash();
    BlinkDot();
    BlinkDot();
  }
  if (curcharacter == 'm') {
    BlinkDash();
    BlinkDash();
  }
  if (curcharacter == 'n') {
    BlinkDash();
    BlinkDot();
  }
  if (curcharacter == 'o') {
    BlinkDash();
    BlinkDash();
    BlinkDash();
  }
  if (curcharacter == 'p') {
    BlinkDot();
    BlinkDash();
    BlinkDash();
    BlinkDot();
  }
  if (curcharacter == 'q') {
    BlinkDash();
    BlinkDash();
    BlinkDot();
    BlinkDash();
  }
  if (curcharacter == 'r') {
    BlinkDot();
    BlinkDash();
    BlinkDot();
  }
  if (curcharacter == 's') {
    BlinkDot();
    BlinkDot();
    BlinkDot();
  }
  if (curcharacter == 't') {
    BlinkDash();
  }
  if (curcharacter == 'u') {
    BlinkDot();
    BlinkDot();
    BlinkDash();
  }
  if (curcharacter == 'v') {
    BlinkDot();
    BlinkDot();
    BlinkDot();
    BlinkDash();
  }
  if (curcharacter == 'w') {
    BlinkDot();
    BlinkDash();
    BlinkDash();
  }
  if (curcharacter == 'x') {
    BlinkDash();
    BlinkDot();
    BlinkDot();
    BlinkDash();
  }
  if (curcharacter == 'y') {
    BlinkDash();
    BlinkDot();
    BlinkDash();
    BlinkDash();
  }
  if (curcharacter == 'z') {
    BlinkDash();
    BlinkDash();
    BlinkDot();
    BlinkDot();
  }
}
