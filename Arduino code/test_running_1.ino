#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int PinA0 = 0;
int led11 = 11; // LED11 use to learn how button work
int led12 = 12; // LED12 for extra function
int button = 8;
int count = 0;

unsigned long waitTime = 1000; // time hold button

boolean ledStatus = 0 ;        //LED11 off as default
boolean lastledStatus = 1;

/* Hold button */
boolean lastButton_HoldStatus = 1;
boolean buttonLongPress = 1;

/* Click button */
int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;

unsigned long lastChangedTime; /* last time changing state of hold button */

float Vout = 0;
float Temp = 0;

/* Function prototype */
void Led_blink();
void Temperature();
void Choose_program();

/* Setup */
void setup() {
  // put your setup code here, to run once:
  pinMode(led11, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  digitalWrite(led11, ledStatus);

  Serial.begin(9600);
}

void loop() {
  boolean reading = digitalRead(button);
  if(reading != lastButton_HoldStatus){
    lastButton_HoldStatus = reading;
    lastChangedTime = millis();
    
    Serial.print(". Now state of button_hold is: ");
    Serial.println(!lastButton_HoldStatus);
    lastledStatus =! ledStatus; /* use for hold button */
                                /* not changing the state when hold button */
                                /* but will change the state for next hold button */
  }
  if(millis() - lastChangedTime > waitTime){
    buttonLongPress = reading;
    lastChangedTime = millis();
    Serial.print("Event of hold: ");
    Serial.println(!buttonLongPress);
  }
  if(buttonLongPress == false){
    ledStatus = lastledStatus;
    buttonLongPress = true;
  }
  if(ledStatus == 1){
    Choose_program();
  }
  digitalWrite(led11, ledStatus);
}

void Led_blink(){
  digitalWrite(led12, HIGH);
  delay(50);
  digitalWrite(led12, LOW);
  delay(50);
}

void Temperature(){
  
  PinA0 = analogRead(A0);
  Vout = PinA0 / 0.2046;
  
  Temp = (Vout - 2098.84)/-10.817; /* range of temperature -10¤C to 50¤C */
                                   /* Caculated by equation V - V1 = (V2-V1)/(T2-T1)*(T-T1)  */
  Serial.print("PinA0 : ");
  Serial.print(PinA0);
  Serial.print(" Vout : ");
  Serial.print(Vout, 4);
  Serial.print(" Temperature : ");
  Serial.print(Temp);
  Serial.print("¤C");
  Serial.println();
  if(count==0){
    printtolcd("Temp", Temp);
    }
  else{
    printinlcd("Temp", Temp);
    }
  delay(50);
  count++;
}

void Choose_program(){
  buttonState = digitalRead(button);
    if(buttonState != lastButtonState){
      if(buttonState == 0){
        buttonPushCounter++;
        Serial.print(" Button count: ");
        Serial.print(buttonPushCounter);
        Serial.print("  ");
      }
    }  
    
    lastButtonState = buttonState;
    
    if(buttonPushCounter % 2 == 0){
      Led_blink();
      count=0;
    }
    else{
      Temperature();
    }
}
void printtolcd(char *s, float data){
  lcd.begin();
  lcd.setCursor(16,0);
  lcd.print(s);
  lcd.print(" ");
  lcd.print(data);
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
  lcd.scrollDisplayLeft();
  delay(30);
  }
}

void printinlcd(char *s, float data){
  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print(s);
  lcd.print(" ");
  lcd.print(data);
}
