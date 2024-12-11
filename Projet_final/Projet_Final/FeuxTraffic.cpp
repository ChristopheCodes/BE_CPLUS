#include "FeuxTraffic.h"

FeuxTraffic::FeuxTraffic(rgb_lcd* lcd) : lcd(lcd) {}

void FeuxTraffic::init() {
    if (!lcd) {
        throw EcranNonInitialiseException(); // Lever une exception si le LCD est null
    }
    lcd->begin(16, 2); // Initialiser l'écran LCD 16x2
    setVert();         // Par défaut, feu vert
}

void FeuxTraffic::setRouge() {
    lcd->clear();
    lcd->setRGB(255, 0, 0); // Couleur rouge
    lcd->print("Feu: Rouge");
}

void FeuxTraffic::setJaune() {
    lcd->clear();
    lcd->setRGB(255, 255, 0); // Couleur jaune
    lcd->print("Feu: Jaune");
}

void FeuxTraffic::setVert() {
    lcd->clear();
    lcd->setRGB(0, 255, 0); // Couleur verte
    lcd->print("Feu: Vert");
}

void FeuxTraffic::eteindre() {
    lcd->clear();
    lcd->setRGB(0, 0, 0); // Éteindre le rétroéclairage
    lcd->print("Feu: Eteint");
}

FeuxTraffic& FeuxTraffic::operator=(const FeuxTraffic& other) {
    if (this != &other) {
        this->lcd = other.lcd;
    }
    return *this;
}


