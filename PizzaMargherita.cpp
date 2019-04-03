#include "PizzaMargherita.h"

PizzaMargherita::PizzaMargherita(int dimensiune, int blat) : Pizza(dimensiune, blat) {
    // Nothing done yet
}

double PizzaMargherita::getPret() {
    return Pizza::getPret() + 5.99;
}