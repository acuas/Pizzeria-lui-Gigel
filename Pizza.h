#ifndef PIZZA_PIZZA_H
#define PIZZA_PIZZA_H

#include <iostream>

class Pizza {
    private:
        int dimensiune;
        int blat;
    protected:
        // Am facut constructorii in mod special protected ca sa nu se poata creea in mod direct
        // instante ale clasei Pizza
        Pizza();
        Pizza(int dimensiune, int blat);
    public:
        // Getters and setters
        // Atentie la getters. Este o practica buna ca aceste metode sa fie constante.
        int getDimensiune() const;

        // In setters ar trebui sa aveti grija de obicei de tipul valorilor care pot fi
        // atribuite in cazul nostru exista doar doua tipuri de dimensiuni: 30 si 50.
        // Altfel vom afisare un mesaj de eroare
        void setDimensiune(int dimensiune);

        int getBlat() const;
        void setBlat(int blat);

        virtual double getPret();
};


#endif //PIZZA_PIZZA_H