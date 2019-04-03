#include "Pizza.h"

Pizza::Pizza() {
    setDimensiune(30);
    setBlat(2);
}

Pizza::Pizza(int dimensiune, int blat) {
    setDimensiune(dimensiune);
    setBlat(blat);
}

int Pizza::getDimensiune() const {
    return dimensiune;
}

void Pizza::setDimensiune(int dimensiune){
    if (dimensiune == 30 || dimensiune == 50) {
        this->dimensiune = dimensiune;
    }
    else {
        // valoare implicita in caz de eroare
        this->dimensiune = 30;
        std::cout << "Eroare interna la setarea dimensiunii!\n";
    }
}

int Pizza::getBlat() const {
    return blat;
}

void Pizza::setBlat(int blat) {
    if (blat == 2 || blat == 3) {
        this->blat = blat;
    }
    else {
        // valoare implicita in caz de eroare
        this->blat = 2;
        std::cout << "Eroare interna la setarea blatului!\n";
    }
}

double Pizza::getPret() {
    return (dimensiune * blat) / 4.0;
}