#pragma once

#include <vector>
#include "Card.h"

class Deck
{

    public:
        Deck();
        ~Deck();
        
        void Print();
        void Shuffle();

    private:
        std::vector<Card*> deck;

};