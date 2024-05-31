#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// De pinnen toewijzen
const int button1Pin = 13;      // Pin waar de eerste drukknop op is aangesloten
const int button2Pin = 8;       // Pin waar de tweede drukknop op is aangesloten

// Maak een LCD-object aan en stel de afmetingen in, (16x2), dit hoort bij dit scherm
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variabelen om de status van de knoppen in op te slaan
int button1State = 0;
int button2State = 0;

// Variabelen om de vorige status van de knoppen bij te houden
int lastButton1State = HIGH;
int lastButton2State = HIGH;

// Timing variabelen
unsigned long startTime = 0;            // Tijd waarop de stopwatch is gestart
unsigned long elapsedTime = 0;          // Tijd zolang de stopwatch bezig is
unsigned long lapTime = 0;              // De rondetijd
unsigned long button1PressTime = 0;     // Tijd waarop knop 1 voor het laatst is ingedrukt. Knop 1 wordt gebruikt om te starten of de pauze op te heffen

// Stopwatch status
bool running = false;                   // Geeft aan of de stopwatch op dit moment loopt
bool paused = false;                    // Geeft aan of de stopwatch is gepauzeerd
bool lap = false;                       // Geeft aan of er een ronde is geweest (dus of knop 1, 2 seconden is ingedrukt)

void setup() {
  // De pinnen intialiseren
  pinMode(button1Pin, INPUT);           // Configureer de eerste drukknop als INPUT met interne pull-up weerstand
  pinMode(button2Pin, INPUT);           // Configureer de tweede drukknop als INPUT met interne pull-up weerstand
  
  // Initialiseer het LCD
  lcd.init();
  lcd.backlight();                      // Hiermee wordt de achtergrondverlichting van het LCD-scherm aangezet
  lcd.clear();                          // Hiermee wordt het LCD-scherm gewist, zodat er geen  oude tekens op staan
  lcd.setCursor(0, 0);                  // Zet de cursorpositie in op de eerste regel en de eerste kolom (0.0)
  lcd.print("Stopwatch");               // Laat de tekst "stopwatch" zien op de eerste regel
  
  // Dit is voor het debuggen
  Serial.begin(9600);
}

void loop() {
  // Lees de huidige statuss van de knoppen 
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  
  // Controleer of beide knoppen tegelijkertijd zijn ingedrukt
  if (button1State == LOW && button2State == LOW) {
    // Als dat zo is, wordt de stopwatch gereset. De functie resetStopwatch wordt hier aangeroepen
    resetStopwatch();
  } else {
    // Controleer of knop 1 wordt ingedrukt
    if (button1State == LOW && lastButton1State == HIGH) {
      // Als knop 1 is ingedrukt, start de stopwatch of begin met het bijhouden van een ronde
      if (!running && !paused) {
        startStopwatch();
      } else if (paused) {
        resumeStopwatch();
      } else {
        button1PressTime = millis(); // Start met het bijhouden van de tijd dat de knop wordt ingedrukt
      }
    }

    if (button1State == LOW && running) {
      // Controleer of knop 1 voor 2 seconde wordt ingedrukt
      if (millis() - button1PressTime >= 2000 && !lap) {
        lapTime = elapsedTime;
        lap = true;
        displayTime(lapTime, 8, 1); // Toon de rondetijd
      }
    }

    if (button1State == HIGH && lastButton1State == LOW && running && lap) {
      // Als knop 1 wordt losgelaten na het meten van een ronde, wordt de ronde timer weer gereset
      lap = false;
    }

    if (button1State == HIGH && lastButton1State == LOW && running) {
      // Als knop 1 wordt losgelaten, nadat deze is ingedrukt, wordt de startTime geupdate om door te gaan vanuit de huidige tijd
      startTime = millis() - elapsedTime;
    }

    if (button2State == LOW && lastButton2State == HIGH && running) {
      // Als knop 2 wordt ingedrukt, wordt de stopwatch gepauzeerd
      pauseStopwatch();
    }
  }

  // Als de stopwatch bezig is, wordt de tijd continue bijgewerkt
  if (running && !paused && !lap) {
    elapsedTime = millis() - startTime;
    displayTime(elapsedTime, 0, 1);
  }

  // Hier worden de vorige knopstatussen bijgwerkt
  lastButton1State = button1State;
  lastButton2State = button2State;

  // En een kleine vertraging
  delay(10);
}

// Dit is een functie die gebruikt wordt om de stopwatch te starten
void startStopwatch() {
  startTime = millis();
  running = true;
  paused = false;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Stopwatch");
}

// Dit is een functie die gebruikt wordt om de stopwatch te pauzeren
void pauseStopwatch() {
  running = false;
  paused = true;
  lcd.setCursor(0, 0);
  lcd.print("Stopwatch");
}

// Dit is een functie die gebruikt wordt als de stopwatch weer wordt gestart na een pauze
void resumeStopwatch() {
  startTime = millis() - elapsedTime;
  running = true;
  paused = false;
  lcd.setCursor(0, 0);
  lcd.print("Stopwatch");
}

// Dit is een functie die gebruikt wordt om de stopwatch te resetten
void resetStopwatch() {
  running = false;
  paused = false;
  elapsedTime = 0;
  lapTime = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Reset");
  delay(1000); // Reset wordt kort getoond, voor de stopwatch opnieuw gaat beginnen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Stopwatch");
}

// Dit is een functie die gebruikt wordt om de tijd op het LCD scherm te tonen
void displayTime(unsigned long time, int col, int row) {
  int milliseconds = time % 1000;
  int seconds = (time / 1000) % 60;
  int minutes = (time / 60000) % 60;
  int hours = (time / 3600000);

  lcd.setCursor(col, row);
  if (hours < 10) lcd.print("0");
  lcd.print(hours);
  lcd.print(":");
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
  lcd.print(":");
  if (milliseconds < 100) lcd.print("0");
  if (milliseconds < 10) lcd.print("0");
  lcd.print(milliseconds);
}