#ifndef FEUX_TRAFFIC_H
#define FEUX_TRAFFIC_H

#include <rgb_lcd.h>
#include <exception>
#include "Lumiere.h" // Classe de base pour les feux

// Exception pour signaler que le LCD n'est pas initialisé
class EcranNonInitialiseException : public std::exception {
public:
    const char* what() const noexcept override {
        return "LCD non initialise.";
    }
};

class FeuxTraffic : public Lumiere {
private:
    rgb_lcd* lcd; // Pointeur vers l'écran LCD

public:
    FeuxTraffic(rgb_lcd* lcd);
    void init();                  // Initialiser l'écran LCD
    void setRouge() override;     // Activer le feu rouge
    void setJaune() override;     // Activer le feu jaune
    void setVert() override;      // Activer le feu vert
    void eteindre() override;     // Éteindre les feux
    FeuxTraffic& operator=(const FeuxTraffic& other);
};

#endif


