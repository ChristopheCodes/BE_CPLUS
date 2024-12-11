#include "FeuxPieton.h"

FeuxPieton::FeuxPieton(int pin) : pinLED(pin) {}

void FeuxPieton::init() {
    pinMode(pinLED, OUTPUT); // Configurer le pin comme sortie
    eteindre();
}

void FeuxPieton::setRouge() {
    digitalWrite(pinLED, HIGH); // Allumer la LED rouge
}

void FeuxPieton::setJaune() {
    // Pas applicable pour les piétons, reste inactif
}

void FeuxPieton::setVert() {
    digitalWrite(pinLED, LOW); // Éteindre la LED rouge (feu vert pour piétons)
}

void FeuxPieton::eteindre() {
    digitalWrite(pinLED, LOW); // Éteindre la LED
}
