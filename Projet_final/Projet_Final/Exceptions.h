#ifndef LUMIERE_EXCEPTIONS_H
#define LUMIERE_EXCEPTIONS_H

#include <exception>

// Exception pour signaler un problème d'initialisation
class LumiereNonInitialiseeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "La lumière na pas ete correctement initialise!";
    }
};

#endif
