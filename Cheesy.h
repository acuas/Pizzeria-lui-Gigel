#ifndef PIZZA_CHEESY_H
#define PIZZA_CHEESY_H

#include "Pizza.h"

class Cheesy : public Pizza {
    public:
        Cheesy(int dimensiune, int blat);
        // Overriding
        double getPret() override;
};


#endif //PIZZA_CHEESY_H
