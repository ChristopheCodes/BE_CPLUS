// Controlleur.cpp
#include "Controlleur.h"
#include <vector> // STL - pour gérer dynamiquement les feux

Controlleur::Controlleur(FeuxTraffic* voiture, FeuxPieton* pieton, int bouton, rgb_lcd* lcd, Buzzer* buzzer)
    : feuxVoiture(voiture), feuxPieton(pieton), boutonPin(bouton), etat(0), dernierChangement(0), lcd(lcd), buzzer(buzzer) {}

void Controlleur::init() {
    try {
        feuxVoiture->init();
        feuxPieton->init();
        buzzer->init();
    } catch (const std::exception& e) {
        lcd->clear();
        lcd->setRGB(255, 0, 0); // Rouge pour indiquer une erreur
        lcd->print(e.what());
        while (true) {
            // Blocage en cas d'erreur critique
        }
    }

    pinMode(boutonPin, INPUT_PULLUP);

    lcd->begin(16, 2);
    lcd->setRGB(0, 255, 0);
    lcd->print("Feu: Vert");

    feuxVoiture->setVert();
    feuxPieton->setRouge();
}

void Controlleur::update() {
    // Initialisation du vecteur avec les feux
    std::vector<Lumiere*> lumieres = {feuxVoiture, feuxPieton};

    int compteur;
    bool bouttonAppuye ;
    switch (etat) {
        case 0: // Feux vert voitures
            compteur = 0; // Compteur pour les secondes (si appui sur le bouton)
            bouttonAppuye = false ; // Variable indiquant si le bouton a été appuyée
            // Vérification du bouton pendant 20 secondes maximum
            while (digitalRead(boutonPin) != HIGH && compteur < 20000) {
                delay(1);
                compteur++;
                if (digitalRead(boutonPin) == HIGH) {
                    buzzer->emettreSon(2000); // Émet un son pendant 2 secondes
                    bouttonAppuye = true ;
                    break;
                }
            }


            feuxVoiture->setJaune();
            if (bouttonAppuye) {
              buzzer->emettreSon(2000); // permet de prolonger le bruit du buzzer jusqu'à la fin du jaune
              bouttonAppuye = false ; 
            }
            feuxPieton->setRouge();
            lcd->setRGB(255, 255, 0); // Jaune
            etat = 2; // Passer à l'état suivant
            break;

        case 1: // Feux rouge voitures, vert piétons
            for (Lumiere* lumiere : lumieres) {
                if (lumiere == feuxVoiture) {
                    lumiere->setRouge(); // Rouge pour voitures
                } else if (lumiere == feuxPieton) {
                    lumiere->setVert(); // Vert pour piétons
                }
            }
            lcd->setRGB(255, 0, 0);    // Rouge
            delay(10000); // Attente pour les piétons

            // Retour au vert pour voitures
            for (Lumiere* lumiere : lumieres) {
                lumiere->eteindre(); // Éteindre tous les feux
            }
            feuxVoiture->setVert();
            feuxPieton->setRouge();
            lcd->setRGB(0, 255, 0); // Vert
            etat = 0; // Revenir à l'état initial
            break;

        case 2: // Transition voitures (jaune à rouge)
            delay(2000);
            for (Lumiere* lumiere : lumieres) {
                if (lumiere == feuxVoiture) {
                    lumiere->setRouge(); // Rouge pour voitures
                } else if (lumiere == feuxPieton) {
                    lumiere->setVert(); // Vert pour piétons
                }
            }
            lcd->setRGB(255, 0, 0);      // Rouge
            etat = 1; // Passer à l'état rouge pour voitures
            break;
    }
}
