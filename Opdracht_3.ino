// De pinnen toewijzen
const int led1Pin = 8;       // Pin waar de eerste led op is aangesloten
const int led2Pin = 10;      // Pin waar de tweede led op is aangesloten
const int buttonPin = 12;    // Pin waar de drukknop op is aangesloten

//variabelen om de teller en de status van de knoppen bij te houden
int counter = 0;                // Hier wordt het aantal keer dat op de knop wordt gedrukt bijgehouden
bool buttonState = false;       // Hier wordt de huidige knoptoestand opgeslagen
bool lastButtonState = false;   // Hier wordt de vorige knoptoestand opgeslagen

void setup() {
  // De pinnen initialiseren
  pinMode(led1Pin, OUTPUT);   // Configureer de eerste led pin als OUTPUT
  pinMode(led2Pin, OUTPUT);   // Configureer de tweede led pin als OUTPUT
  pinMode(buttonPin, INPUT);  // Configureer de drukknop als INPUT met interne pull-up weerstand
  
  // Initialiseer de knop 
  digitalWrite(buttonPin, HIGH); // Schakel de interne pull-up weerstand in
  
  // Allebei de Led's staan uit bij het starten
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
}

void loop() {
  // Lees de huidige toestand van de knop in
  buttonState = digitalRead(buttonPin) == LOW; // LOW houdt in dat de knop is ingedrukt
  
  // Controleer of de knoptoestand is veranderd sinds de vorige loop
  if (buttonState && !lastButtonState) {
    // De teller gaat omhoog wanneer een knop wordt ingedrukt
    counter++;
    
    
      // Als de teller even is, gaat led1 aan en led2 uit
     if (counter % 2 == 0) {
      digitalWrite(led1Pin, HIGH);
      digitalWrite(led2Pin, LOW);
    } else {
      // Als de teller oneven is, zet led1 uit en led2 aan
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, HIGH);
    }
  }
  
  // Sla de huidige knoptoestand op voor de volgende loop
  lastButtonState = buttonState;
  
  // een delay van 50ms als contactdender
  delay(50);
}
