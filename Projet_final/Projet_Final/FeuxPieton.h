#ifndef FEUX_PIETON_H
#define FEUX_PIETON_H

#include <Arduino.h>
#include "Lumiere.h" // Classe de base pour les feux

class FeuxPieton : public Lumiere {
private:
    int pinLED; // Pin de la LED piéton

public:
    FeuxPieton(int pin);
    void init();            // Initialiser la LED
    void setRouge() override; // Activer le feu rouge
    void setJaune() override; // Non applicable pour les piétons
    void setVert() override;  // Activer le feu vert
    void eteindre() override; // Éteindre le feu piéton
};

#endif
