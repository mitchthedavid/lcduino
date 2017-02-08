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
int val = 0;       // variable to store the value coming from the sensorint 
int people = 0;
int potPin = 2;    // select the input pin for the potentiometer
int shortStick=0;


 
void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("press button to");
  lcd.setCursor(0,1);
  lcd.print("start");
  setBacklight(0,0,255);
  
  pinMode(REDLITE, OUTPUT);
  pinMode(GREENLITE, OUTPUT);
  pinMode(BLUELITE, OUTPUT);

  brightness = 100;
  pinMode(LED_BUILTIN, OUTPUT);

  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}
 
 
void loop() {
  
  val = analogRead(potPin);
  
  
 
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
if (buttonState == LOW)
{ val = analogRead(potPin);
  { lcd.clear();
 
  lcd.print("press to start.");
  lcd.setCursor(0,1);
  lcd.print("# people: ");
  if (val <= 100)
  {
  people=1;
  lcd.print(people);
  }
  if (val > 100 && val <=200)
  { people=2;
    lcd.print(people);
  
  }
  if (val >200 && val <=300)
  { people=3;
    lcd.print(people);
  }
 if (val>300 && val <=400)
  {people=4;
    lcd.print(people);
    
  }
  if (val>400 && val <=500)
  {people=5;
    lcd.print(people);
    
  }
  if (val>500 && val <=600)
  {people=6;
    lcd.print(people);
    
  }
   if (val>600 && val <=700)
  {people=7;
    lcd.print(people);
   }
   if (val>700 && val <=800)
  {people=8;
    lcd.print(people);
   }
   if (val>800 && val <=900)
  {people=9;
    lcd.print(people);
   }
   if (val>900 && val <=1000)
  {people=10;
    lcd.print(people);
   }
   if (val >1000)
  {people=11;
    lcd.print(people);
   }
   
  

  delay(50);
 shortStick=random(1,people);

}
}
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH, and the people starts
  if (buttonState == HIGH) {

  lcd.clear();   
  lcd.print("   #");
  lcd.print(shortStick);

  
  lcd.print(" gets the short end of the stick.");
  delay(200);
    for (int positionCounter = 0; positionCounter < 27; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(200);
  }
  
 
  
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
