#ifndef PIZZA_DRACULA_H
#define PIZZA_DRACULA_H

#include "Pizza.h"

class Dracula : public Pizza {
    public:
        Dracula(int dimensiune, int blat);
        double getPret() override;
};


#endif //PIZZA_DRACULA_H
