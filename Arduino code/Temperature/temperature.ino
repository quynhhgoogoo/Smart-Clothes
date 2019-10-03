
float PinA0 = 0; /* range from 0 to 1023 */
                 /* voltage generate from 0 - 5v */
                 /* so 1 voltage = 0.2046 (range of output) */
float Vout = 0;
float Temp = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
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
