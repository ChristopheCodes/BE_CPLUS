#include "Buzzer.h"

// Constructeur pour initialiser le pin du buzzer
Buzzer::Buzzer(int pin) : pin(pin) {}

void Buzzer::init() {
    pinMode(pin, OUTPUT); // Configurer le pin en sortie
    eteindre();
}

// Faire sonner le buzzer pendant une durée donnée
void Buzzer::emettreSon(unsigned long duree) {
    digitalWrite(pin, HIGH); // Activer le buzzer
    delay(duree);            // Attendre la durée spécifiée
    eteindre();              // Éteindre le buzzer
}

// Éteindre le buzzer
void Buzzer::eteindre() {
    digitalWrite(pin, LOW); // Désactiver le buzzer
}
