int pedo = 2;
int pedoCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pedo, INPUT_PULLUP);
}

void loop() {
  int PedoStatus = digitalRead(pedo);   
  if(PedoStatus == HIGH){
     pedoCount++;
     delay(300);
  }else{}
  Serial.println(pedoCount);                      
}
