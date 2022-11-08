#include "Deck.h"
#include <algorithm>
#include <iostream>

Deck::Deck()
    : deck()
{
    deck.reserve(52);
    for (Card::Ranks r = Card::TWO; r <= Card::ACE; r = static_cast<Card::Ranks>(static_cast<int>(r)+1))
    {
        for (Card::Suits s = Card::HEARTS; s <= Card::SPADES; s = static_cast<Card::Suits>(static_cast<int>(s)+1))
        {
            deck.push_back(new Card(r, s));
        }
    }
}

Deck::~Deck()
{
    for(Card* card : deck)
    {
        delete card;
    }
    deck.clear();

}

void Deck::Print()
{
    for(Card* card : deck)
    {
        card -> Print();
        std::cout << " ";
    }
}

void Deck::Shuffle()
{
    std::random_shuffle(deck.begin(), deck.end());
}