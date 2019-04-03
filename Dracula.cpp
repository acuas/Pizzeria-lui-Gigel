#include "Dracula.h"

Dracula::Dracula(int dimensiune, int blat) : Pizza(dimensiune, blat) {
    // Nothing done yet
}

double Dracula::getPret() {
    return Pizza::getPret() + 8.99;
}