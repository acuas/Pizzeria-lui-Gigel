#include "Cheesy.h"

Cheesy::Cheesy(int dimensiune, int blat) : Pizza(dimensiune, blat) {
    // Nothing done yet
}

double Cheesy::getPret() {
    return Pizza::getPret() + 7.99;
}