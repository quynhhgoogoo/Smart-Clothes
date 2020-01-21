int ledPin = 13;
int button     = 4;

void tatled()
{
    digitalWrite(ledPin, LOW); // tắt đèn led
}

void setup()
{
   pinMode(ledPin, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(button, INPUT_PULLUP);
   pinMode(2, INPUT_PULLUP); // sử dụng điện trở kéo lên cho chân số 2, ngắt 0
   attachInterrupt(0, tatled, LOW); // gọi hàm tatled liên tục khi còn nhấn nút
}

void loop()
{
  digitalWrite(ledPin, HIGH);   // bật đèn led
  int buttonStatus = digitalRead(button);
  if(buttonStatus == HIGH){
    digitalWrite(7, HIGH);
  }
  else digitalWrite(7, LOW);
}
