#ifndef CONTROLLEUR_H
#define CONTROLLEUR_H

#include "FeuxTraffic.h"
#include "FeuxPieton.h"
#include "Buzzer.h"   
#include <rgb_lcd.h> // Librairie pour l'écran LCD

class Controlleur {
private:
    FeuxTraffic* feuxVoiture;  // Feu de circulation pour les voitures
    FeuxPieton* feuxPieton;    // Feu de circulation pour les piétons
    Buzzer* buzzer;            // Buzzer pour signaler les piétons
    int boutonPin;             // Pin du bouton
    unsigned long dernierChangement;
    int etat;                  // État actuel du système
    rgb_lcd* lcd;              // Pointeur vers le LCD

public:
    Controlleur(FeuxTraffic* voiture, FeuxPieton* pieton, int bouton, rgb_lcd* lcd, Buzzer* buzzer);
    void init();   // Initialiser le système
    void update(); // Mettre à jour le système
};

#endif
