// Definieer de pinnen die gebruikt worden
// In dit geval zijn het de pinnen in posities 13,12,11,10,9,8
const int ledPins[] = {13, 12, 11, 10, 9, 8};
// Het aantal gebruikte leds is 6
const int numLeds = 6;

// Definieer de potmeterwaarde als A5
const int potmeterWaarde = A5;

void setup() {
  // Configureer alle pinnen in de array genaamd ledPins als OUTPUT
  // En zet alle pinnen in de array gelijk aan
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);      // Hier worden ze dus als OUTPUT geconfigureerd
    digitalWrite(ledPins[i], HIGH);   // Hier worden ze allemaal gelijk aangezet
  }
  
  // Serial gebruik ik hier om te debuggen
  Serial.begin(9600);
}

void loop() {
  // De potwaarde wordt uitgemeten, vanuit de pin waar de potmeterWaarde in is geplaatst
  int potWaarde = analogRead(potmeterWaarde);
  
  // Hier wordt de potWaarde even in een println gezet, zodat ik kan controleren of het werkt
  Serial.println(potWaarde);
  
  // Hier wordt het aantal leds uitgeschakeld op basis van de waarde van de potmeter
  int ledsUit = map(potWaarde, 0, 1023, 0, numLeds);
  
  // Hier worden de juiste led's uitgeschakeld, op basis van de ledsUit hierboven
  for (int i = 0; i < numLeds; i++) {
    if (i < ledsUit) {
      digitalWrite(ledPins[i], LOW);    // Hier worden ze dan uitgezet
    } else {
      digitalWrite(ledPins[i], HIGH);   // Anders: Hier staan ze nog aan
    }
  }
  
  // Een korte delay voor de potmeter weer kan worden uitgelezen
  delay(100);
}
