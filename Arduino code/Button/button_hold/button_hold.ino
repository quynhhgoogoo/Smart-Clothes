int PinA0 = 0;
int led11 = 11; // LED11 use to learn how button work
int led12 = 12; // LED12 for extra function
int button = 8;

unsigned long waitTime = 1000; // time hold button

boolean ledStatus = 0 ;        //LED11 off as default
boolean lastledStatus = 1;

boolean lastButtonStatus = 1;
boolean buttonLongPress = 1;

unsigned long lastChangedTime;

float Vout = 0;
float Temp = 0;

/* Function prototype */
void Led_blink();
void Temperature();

void setup() {
  // put your setup code here, to run once:
  pinMode(led11, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  digitalWrite(led11, ledStatus);

  Serial.begin(9600);
  Serial.println("Start");
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean reading = digitalRead(button);
  if(reading != lastButtonStatus){
    lastButtonStatus = reading;
    lastChangedTime = millis();

    Serial.print("Change state of button at: ");
    Serial.print(lastChangedTime);
    Serial.print(". Now state is: ");
    Serial.println(lastButtonStatus);
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
    Led_blink();
    Temperature();
  }
  digitalWrite(led11, ledStatus);
}

void Led_blink(){
  digitalWrite(led12, HIGH);
  delay(200);
  digitalWrite(led12, LOW);
  delay(200);
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
  delay(1000);
}
