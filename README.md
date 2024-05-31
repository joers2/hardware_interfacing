
/r # Hardware interfacing
Periode 4, systeem. 

# Opdracht 1 

*Benodigdheden*

- 2 Led's
- 2 Resistors

*Plan van aanpak* 

Verbind led 1 met pin 13 en led 2 met pin 10 aan de plus (anode), te herkennen aan het de lange poot van de led. Beide leds worden verbonden met een resistor aan de min (cathode) van de breadboord, te herkennen aan de korte poot van de led. 
Het breadboord wordt verbonden door de min van de breadboord aan te sluiten aan de GND (ground) van de arduino. De plus van de breadboord wordt aangesloten op de 5V (5 volt) van de arduino. 

*Schematische opstelling*

![Schermafbeelding 2024-05-21 110202](https://github.com/joers2/hardware_interfacing/assets/150683529/25ecde4c-ab4e-46c8-b0f6-64d5d9c0df17)

*Demo*

https://github.com/joers2/hardware_interfacing/assets/150683529/274b5885-be82-4452-9507-4897bb8d35f4

# Opdracht 2

*Benodigdheden*

- 8 Led's
- 8 Resistors

*Plan van aanpak*

Verbind de 8 leds met de de pinnen 13 t/m 8, 4 en 1 (Ik vond het niet prettig dat alle draden zo dicht op elkaar zaten, dus heb daarom gekozen voor pin 4 en 1, i.p.v. 7 en 6.) aan de plus (anode). Alle leds worden verbonden met een resistor aan de min (cathode) van de breadboord.
Het breadboord wordt verbonden door de min van de breadboord aan te sluiten aan de GND (ground) van de arduino. De plus van de breadboord wordt aangesloten op de 5V (5 volt) van de arduino. 

*Schematische opstelling*

![Schermafbeelding 2024-05-21 135007](https://github.com/joers2/hardware_interfacing/assets/150683529/7ce1c4f0-89e4-4cd5-95f5-339dd30591f0)

*Demo*

https://github.com/joers2/hardware_interfacing/assets/150683529/b00159c1-f57b-4a87-b56a-42708d0b0c7f

# Opdracht 3

*Benodigdheden*

- 2 Led's
- 1 Drukknop
- 3 Resistors

*Plan van aanpak*

Verbind led 1 met pin 8, verbind led 2 met pin 10 en verbind de drukknop met pin 12 aan de plus (anode). De leds en de drukknop worden verbonden met een resistor aan de min (cathode). De drukknop wordt op de breadboord geplaatst, tussen de "poten" van de drukknop, zit 1 leeg gaatje. Zo weet je dat je de drukknop op de juiste manier hebt aangesloten. Als er 2 lege gaatjes zitten tussen de pootjes van de drukknop, heb je de drukknop niet op de juiste manier aangesloten.
Verbind de drukknop met een resistor aan de min (cathode) en de plus (anode) aan de juiste pin, in dit geval pin 12. 
Het breadboord wordt verbonden door de min van de breadboord aan te sluiten aan de GND (ground) van de arduino. De plus van de breadboord wordt aangesloten op de 5V (5 volt) van de arduino. 

*Schematische opstelling*

![Schermafbeelding 2024-05-27 120242](https://github.com/joers2/hardware_interfacing/assets/150683529/2f7d7492-8372-4d4c-a9cb-a7864a15af15)

*Demo*

https://github.com/joers2/hardware_interfacing/assets/150683529/d4754704-2b14-471e-b416-e79c72e1115c

# Opdracht 4

*Benodigdheden*

- 6 Led's
- Potmeter
- 6 Resistors

*Plan van aanpak*

Verbind de 6 leds met de pinnen 13 t/m 8 aan de plus (anode). Alle leds worden verbonden met een resistor aan de min (cathode) van de breadboord. 
De potmeter wordt op een andere manier aangesloten, namelijk: de linker pin naar de ground (min) van de breadbood. De rechter pin naar de anode (plus) van de breadboord en de middelste pin naar de analoge ingang A5 op de arduino. 
Het breadboord wordt verbonden door de min van de breadboord aan te sluiten aan de GND (ground) van de arduino. De plus van de breadboord wordt aangesloten op de 5V (5 volt) van de arduino. 

*Schematische opstelling*

![Schermafbeelding 2024-05-28 121117](https://github.com/joers2/hardware_interfacing/assets/150683529/8e45b607-3fb3-472a-8e4a-17730affcbef)

*Demo*

https://github.com/joers2/hardware_interfacing/assets/150683529/a3942acd-675b-4ef2-a221-62431a3f3686

# Opdracht 5

*Benodigdheden*

- 2 Drukknoppen
- Servomotor
- 2 Resistors

*Plan van aanpak*

Verbind de twee drukknopen met de pinnen 13 en 8 aan de plus (anode). De drukknoppen worden verbonden met een resistor aan de min (cathode) van de breadboord. 
De servomotor wordt op de volgende manier aangesloten: De ingang van de bruine kabel van de servomotor, gaat naar de cathode (min) van de breadboord. De ingang van de rode kabel van de servomotor, gaat naar de anode (plus) van de breadboord. De oranje kabel van de servomotor, gaat naar pin 3 van de arduino. 
Het breadboord wordt verbonden door de min van de breadboord aan te sluiten aan de GND (ground) van de arduino. De plus van de breadboord wordt aangesloten op de 5V (5 volt) van de arduino. 

*Schematische opstelling*

![Schermafbeelding 2024-05-28 135828](https://github.com/joers2/hardware_interfacing/assets/150683529/66e7e255-d9e8-4369-ac28-8de261c5eb2f)

*Demo*

https://github.com/joers2/hardware_interfacing/assets/150683529/15be0420-7059-4b2f-b97b-cf00991a5009

# Opdracht 6
*Benodigdheden*
- I2C LCD-scherm
- 2 Drukknoppen
- 2 Resistors

*Plan van aanpak*

Verbind de twee drukknopen met de pinnen 13 en 8 aan de plus (anode). De drukknoppen worden verbonden met een resistor aan de min (cathode) van de breadboord.
Het I2C LCD scherm wordt op een andere manier aangesloten. Het scherm heeft 4 afkortingen achterop staan, namelijk: GND, VCC, SDA, SCL. De GND (staat voor ground) van het scherm, wordt aangesloten op de cathode (min) van de breadboord. De VCC wordt aangesloten op de 5V, in dit geval de anode (plus) van het breadboord, gezien de 5V al is gebruikt om de breadboord te verbinden met de arduino. De SDA wordt aangesloten op de analoge ingang A4 op de arduino. De SCL wordt aangesloten op de analoge ingang A5 van de arduino. 
Het breadboord wordt verbonden door de min van de breadboord aan te sluiten aan de GND (ground) van de arduino. De plus van de breadboord wordt aangesloten op de 5V (5 volt) van de arduino. 

*Schematische opstelling*

![Schermafbeelding 2024-05-30 124900](https://github.com/joers2/hardware_interfacing/assets/150683529/17c2cb37-b952-414a-b0a5-323622064508)

*Demo*

https://github.com/joers2/hardware_interfacing/assets/150683529/da440b4e-41ba-48d0-a18a-f1b05eb2f6f3
