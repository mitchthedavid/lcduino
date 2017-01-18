//include the libraries. read the liquidcrystal article on the arduino website for more info on the functions: https://www.arduino.cc/en/Reference/LiquidCrystal
#include <LiquidCrystal.h>
#include <Wire.h>
 
#define REDLITE 3
#define GREENLITE 5
#define BLUELITE 6

const int buttonPin = 2;     // the terminal of the pushbutton pin

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
 
// you can change the overall brightness by range 0 -> 255
int brightness = 255;
int buttonState= 0;


 
void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Press button to");
  lcd.setCursor(0,1);
  lcd.print("start timer.");
  setBacklight(0,255,0);
  
  pinMode(REDLITE, OUTPUT);
  pinMode(GREENLITE, OUTPUT);
  pinMode(BLUELITE, OUTPUT);

  brightness = 100;
  pinMode(LED_BUILTIN, OUTPUT);

  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}
 
 
void loop() {
 
 
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH, and the timer starts
  if (buttonState == HIGH) {

      for (int i = 30; i >= 0; i--) {
     setBacklight(0, 255-((255/30)*i), ((255/30)*i));
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Time Remaining: ");
     lcd.setCursor(0,1);
     lcd.print(i);
    delay(1000);
   
    
    lcd.clear();
    lcd.setCursor(0,0);
    
   
  }
  lcd.print("Timer Done.");\
    delay(2000);
  lcd.clear();
   lcd.print("Press button to");
  lcd.setCursor(0,1);
  lcd.print("start timer.");
  setBacklight(0,0,255);
  
  } 
 
}
 
 
 
void setBacklight(uint8_t r, uint8_t g, uint8_t b) {
  // normalize the red LED - its brighter than the rest!
  r = map(r, 0, 255, 0, 100);
  g = map(g, 0, 255, 0, 150);
 
  r = map(r, 0, 255, 0, brightness);
  g = map(g, 0, 255, 0, brightness);
  b = map(b, 0, 255, 0, brightness);
 
  // common anode so invert!
  r = map(r, 0, 255, 255, 0);
  g = map(g, 0, 255, 255, 0);
  b = map(b, 0, 255, 255, 0);
  Serial.print("R = "); Serial.print(r, DEC);
  Serial.print(" G = "); Serial.print(g, DEC);
  Serial.print(" B = "); Serial.println(b, DEC);
  analogWrite(REDLITE, r);
  analogWrite(GREENLITE, g);
  analogWrite(BLUELITE, b);
}
