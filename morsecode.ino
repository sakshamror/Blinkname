int led_builtIn = 13; 
volatile int currentindex = 0; 

int buttonPin = 2; 
String name = "Saksham";  
bool isBlinking = false;

void setup() {
  pinMode(led_builtIn, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), start, FALLING);
  Serial.begin(9600); 
}

void start()
{
  isBlinking = true;
  currentindex = 0; 
}

void loop() {
   if (isBlinking) {  
    Serial.println(name);
    BlinkName();
    isBlinking = false;
  }

}

void BlinkName()
{
  for (currentindex; currentindex < name.length(); currentindex++) {
      BlinkCharacters(name[currentindex]);
      delay(1000);
    }
}

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

void BlinkCharacters(char curcharacter) {
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