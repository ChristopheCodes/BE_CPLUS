#include "FeuxTraffic.h"
#include "FeuxPieton.h"
#include "Controlleur.h"
#include "Buzzer.h"
#include <rgb_lcd.h>

#define LED_PIETON_PIN D5
#define BOUTON_PIN D6
#define BUZZER_PIN D7

rgb_lcd lcd;
FeuxTraffic feuxVoiture(&lcd);
FeuxPieton feuxPieton(LED_PIETON_PIN);
Buzzer buzzer(BUZZER_PIN);
Controlleur controlleur(&feuxVoiture, &feuxPieton, BOUTON_PIN, &lcd, &buzzer);

void setup() {
    controlleur.init();
}

void loop() {
    controlleur.update();
}
