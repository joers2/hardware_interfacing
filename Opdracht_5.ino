#include <Servo.h>

// De pinnen toewijzen
const int button1Pin = 13;        // Pin waar de eerste drukknop op is aangesloten
const int button2Pin = 8;         // Pin waar de tweede drukknop op is aangesloten
const int servoPin = 3;           // Pin waar de Servomotor op is aangesloten

// Maak een servo object aan
Servo myServo;

// Variabelen om de status van de knoppen in op te slaan
int button1State = 0;
int button2State = 0;

// Variabelen om de vorige status van de knoppen bij te houden
int lastButton1State = HIGH;
int lastButton2State = HIGH;

// Timing variabelen
unsigned long previousMillis = 0;   // Deze variabele houdt de tijd bij, in ms, sinds de laatste keer dat de servo meter werd verplaatst
int currentAngle = 0;               // Deze variabele houdt de huidige hoek van de servo bij

void setup() {
  // De pinnen initialiseren
  pinMode(button1Pin, INPUT);     // Configureer de eerste drukknop als INPUT met interne pull-up weerstand
  pinMode(button2Pin, INPUT);     // Configureer de tweede drukknop als INPUT met interne pull-up weerstand
  
  // Bevestig de servo aan de servopin waar deze op is aangesloten
  myServo.attach(servoPin);       // In dit geval dus de 3e pin
  myServo.write(0);               // Initialiseer de servo positie op 0 graden
  
  // Dit is voor het debuggen
  Serial.begin(9600);
}

void loop() {
  // Lees de huidige status van de knoppen in
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  
  // Roep de functie aan om de servo te laten bewegen op de juiste manier
  moveServo(button1State, button2State);

  // Hier wordt de status van de knoppen bijgewerkt
  lastButton1State = button1State;
  lastButton2State = button2State;

  // Kleine vertraging
  delay(10);
}

void moveServo(int button1State, int button2State) {
  unsigned long currentMillis = millis();
  unsigned long interval = 0;

  if (button1State == LOW && button2State == LOW) {
    interval = 2000; // Allebei de knoppen worden ingedrukt, dus dan duurt het 2 seconden tot de servo van 0 naar 120 graden heeft gedraaid
  } else if (button1State == LOW) {
    interval = 5000; // Drukknop 1 wordt ingedrukt, dus dan duurt het 5 seconden om van 0 naar 120 graden te gaan
  } else if (button2State == LOW) {
    interval = 500; // Drukknop 2 worddt ingedrukt, dus dan duurt het 0,5s om van 0 naar 120 graden te gaan
  }

  // Bereken de huidige hoek op basis van de interval
  if (button1State == LOW || button2State == LOW) {               // Controleer of 1 van de knoppen wordt ingedrukt
    unsigned long elapsedTime = currentMillis - previousMillis;   // Bereken hoe lang het is geleden dan de servo voor het laatste heeft bewogen
    if (elapsedTime >= interval / 120) {                         
      previousMillis = currentMillis;                             // Update de vorige tijd, dat de servo voor het laatst heeft bewogen, naar de huidige tijd
      if (currentAngle < 120) {                                   // Controleer of de hoek minder is dan 120 graden
        currentAngle++;                                           // Verhoog de huidige hoek 
        myServo.write(currentAngle);                              // Beweeg de servo naar de nieuwe hoek
      }
    }
  } else {
    // Als er geen knop wordt ingedrukt, gaat de servo terug naar 0 graden
    unsigned long returnInterval = 0;
    if (lastButton1State == LOW && lastButton2State == LOW) {
      returnInterval = 500; // Allebei de knoppen worden losgelaten, dan duurt het 0,5s tot de servo van 120 graden terug gaat naar 0
    } else if (lastButton1State == LOW) {
      returnInterval = 5000; // Drukknop 1 wordt losgelaten, dan duurt het 5s tot de servo van 120 graden terug gaat naar 0
    } else if (lastButton2State == LOW) {
      returnInterval = 500; // Drukknop 2 wordt losgelaten, dan duurt het 0,5s tot de servo van 120 graden terug gaat naar 0
    }

    // Check commentaar hierboven voor het commentaar hiervan :)
    unsigned long elapsedTime = currentMillis - previousMillis;
    if (elapsedTime >= returnInterval / 120) {
      previousMillis = currentMillis;
      if (currentAngle > 0) {
        currentAngle--;
        myServo.write(currentAngle);
      }
    }
  }
}