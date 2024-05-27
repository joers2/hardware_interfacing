void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //1 led is verbonden met pin 13
  pinMode(10, OUTPUT); //de andere led is verbonden met pin 10

}

void loop() {
  // put your main code here, to run repeatedly:
  //Led 13 start als eerste. 
  digitalWrite(13, HIGH);
  //na 1500ms ookwel 1,5s, wordt de led die in pin 13 gezet gedimd, door de LOW.
  delay(1500);
  //Na de 1,5s vertraging die hierboven wordt benoemd, zal de led in pin 13 gedimd worden.
  digitalWrite(13, LOW);
  //De led in pin 13 wordt gedimd en tegelijkertijd wordt de led in pin 10 gestart.
  digitalWrite(10, HIGH);
  //Na een vertraging van 1500ms, of 1,5s, wordt de led in pin 10 gedimd.
  delay(1500);
  //Hier wordt de led in pin 10 weer gedimd. Hierna begint de loop weer van voor af aan, dus dat betekend dat nadat de led in pin 10 wordt gedimd, de led in pin 13 wordt weer opgelicht.
  digitalWrite(10, LOW);
}
