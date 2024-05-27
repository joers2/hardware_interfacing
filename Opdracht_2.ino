void setup() {
  // De pinnen worden als OUTPUT ingesteld
  // Op de plaatsen, 13,12,11,10,9,8,4,1
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT); 
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(1, OUTPUT);
}
 void loop(){
 
   // Een array zodat we de pinnen kunnen aansturen
  int pins[]={1,4,8,9,10,11,12,13};

  // Het aantal pinnen in de array worden bepaald
  int numPins = sizeof(pins) / sizeof(pins[0]);
  
  // Er wordt geloopt door de pinnen, van de eerste pin tot de laatste pin
  for (int i=0; i <numPins; i++){
  digitalWrite(pins[i], HIGH);    // Zet de huidige pin aan
    delay(100);                   // Een delay van 100ms
    digitalWrite(pins[i], LOW);   // Zet de huidige pin uit 
  }
  
  // Er wordt geloopt door de pinnen, van de laatste pin tot de eerste pin
  for (int i=numPins - 1; i>= 0; i--){
    digitalWrite(pins[i], HIGH);    // Zet de huidige pin aan
    delay(100);                     // Een delay van 100ms
    digitalWrite(pins[i], LOW);     // Zet de huidige pin uit
  }
 }

