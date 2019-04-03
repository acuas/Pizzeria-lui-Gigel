#ifndef PIZZA_PIZZAMARGHERITA_H
#define PIZZA_PIZZAMARGHERITA_H

#include "Pizza.h"

class PizzaMargherita : public Pizza {
    public:
        PizzaMargherita(int dimensiune, int blat);
        double getPret() override;
};


#endif //PIZZA_PIZZAMARGHERITA_H
