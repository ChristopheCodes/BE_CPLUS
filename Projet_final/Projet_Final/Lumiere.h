#ifndef LUMIERE_H
#define LUMIERE_H

// Classe abstraite représentant une lumière de type feu
class Lumiere {
public:
    virtual void setRouge() = 0;     // Activer le feu rouge
    virtual void setJaune() = 0;     // Activer le feu jaune
    virtual void setVert() = 0;      // Activer le feu vert
    virtual void eteindre() = 0;     // Éteindre la lumière
    virtual ~Lumiere() {}
};

#endif
