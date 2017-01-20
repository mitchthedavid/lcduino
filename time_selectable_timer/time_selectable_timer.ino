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
int timer = 0;
int potPin = 2;    // select the input pin for the potentiometer


 
void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("press button to");
  lcd.setCursor(0,1);
  lcd.print("start");
  setBacklight(0,0,255); //changes backlight to blue
  
  pinMode(REDLITE, OUTPUT);
  pinMode(GREENLITE, OUTPUT);
  pinMode(BLUELITE, OUTPUT);

  brightness = 100;
  pinMode(LED_BUILTIN, OUTPUT);

  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}
 
 
void loop() {
  //reads value form potentioemeter
  val = analogRead(potPin);
  
  
 
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  //when the button is unpressed, the potentiometer value is taken, and is convereted to a time
if (buttonState == LOW)
{ val = analogRead(potPin);
  { lcd.clear();
 
  lcd.print("press to start.");
  lcd.setCursor(0,1);
  lcd.print("length: ");
  if (val <= 100)
  {
  timer=10;
  lcd.print(timer);
  }
  if (val > 100 && val <=200)
  { timer=15;
    lcd.print(timer);
  
  }
  if (val >200 && val <=300)
  { timer=20;
    lcd.print(timer);
  }
 if (val>300 && val <=400)
  {timer=25;
    lcd.print(timer);
    
  }
  if (val>400 && val <=500)
  {timer=30;
    lcd.print(timer);
    
  }
  if (val>500 && val <=600)
  {timer=35;
    lcd.print(timer);
    
  }
   if (val>600 && val <=700)
  {timer=40;
    lcd.print(timer);
   }
   if (val>700 && val <=800)
  {timer=45;
    lcd.print(timer);
   }
   if (val>800 && val <=900)
  {timer=50;
    lcd.print(timer);
   }
   if (val>900 && val <=1000)
  {timer=55;
    lcd.print(timer);
   }
   if (val >1000)
  {timer=60;
    lcd.print(timer);
   }
   lcd.print(" sec");
  

  delay(50);
 

}
}
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH, and the timer starts, and color fade begins
  if (buttonState == HIGH) {

      for (int i = timer; i >= 0; i--) {
     setBacklight(0, 255-((255/timer)*i), ((255/timer)*i));
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("time remaining: ");
     lcd.setCursor(0,1);
     lcd.print(i);
     lcd.print(" seconds.");
    delay(1000);
    
  
    lcd.clear();
    lcd.setCursor(0,0);
    
   
  }
  lcd.print("timer done!");
   for (int i = 0; i <= 255; i++) {
     setBacklight(0, 255-i, i);
     delay(5);
     lcd.clear();
    }
  lcd.clear();
 
  
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
