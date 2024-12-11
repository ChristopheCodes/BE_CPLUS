#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

// Classe pour gérer un buzzer
class Buzzer {
private:
    int pin; // Pin associé au buzzer

public:
    Buzzer(int pin);               // Constructeur
    void init();                   // Initialiser le buzzer
    void emettreSon(unsigned long duree); // Faire sonner le buzzer pendant une durée
    void eteindre();               // Éteindre le buzzer
};

#endif
