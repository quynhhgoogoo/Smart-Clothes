
// Function prototype
void off_LED12();
void interrupt_start();
void interrupt_end();

// Pin define
int interrupt_PIN  = 7; // Use for call interrupt function
int button         = 4; // Use to read value from button
int led_13         = 13; // Use for on/off system
int led_12_test    = 12;  // Use for testing purpose

/* --------------------------------------------------------*/

unsigned long waitTime = 1000; // time hold button

boolean ledStatus = 0 ;        //LED13 off as default
boolean lastledStatus = 1;

/* Hold button */
boolean lastButton_HoldStatus = 1;
boolean buttonLongPress = 1;
unsigned long lastChangedTime; // last time changing state of hold button

/* Click button */
int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;

/******** Program start ********/
// Setup
void setup()
{
   Serial.begin(9600);
   pinMode(led_13, OUTPUT);
   pinMode(led_12_test, OUTPUT);
   pinMode(interrupt_PIN, OUTPUT);
   pinMode(2, INPUT_PULLUP); // Use Pin_2 PULLUP for interrup
   pinMode(button, INPUT_PULLUP);
   attachInterrupt(0, off_LED12, LOW); // gọi hàm off_LED12 liên tục khi còn nhấn nút
   digitalWrite(led_13, ledStatus);

}

// Main loop
void loop()
{

  


  
  digitalWrite(led_13, HIGH);
  digitalWrite(led_12_test, HIGH);
  int buttonStatus = digitalRead(button);
  if(buttonStatus == LOW){
    interrupt_start();
  }
  else interrupt_end();
}
/******** Program end ********/

/*--------------------------------------------------------------------------*/

/******** Function define ********/
// Off LED power
void off_LED12(){
    digitalWrite(led_12_test, LOW); // LED_12 OFF
}

// Call interrupt function
void interrupt_start(){
  digitalWrite(interrupt_PIN, LOW); // pin_7 HIGH
}
void interrupt_end(){
  digitalWrite(interrupt_PIN, HIGH); // pin_7 LOW
}

/***********************************************************************************/
