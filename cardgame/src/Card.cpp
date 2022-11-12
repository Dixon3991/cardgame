#include "../include/Card.h"
#include <iostream>
#include "../include/TColor.h"

Card::Card(Ranks RANK, Suits SUIT)
    : Rank(RANK),
      Suit(SUIT)
{
    //Nothing here...
}

Card::~Card()
{
    //Nothing here... memory leak gaurd
}

Card::Ranks Card::GetRank()
{
    return Rank;
}

Card::Suits Card::GetSuit()
{
    return Suit;
}

int Card::GetFaceValue()
{
    if (Rank <= TEN)
        return static_cast<int>(Rank);
    if(Rank <= KING)
        return 10;
        
    return 11;
}

void Card::Print()
{
    if(Rank <= TEN)
        std::cout << Rank;
    else if (Rank == JACK)
        std::cout << "J";
    else if (Rank == QUEEN)
        std::cout << "Q";
    else if (Rank == KING)
        std::cout << "K";
    else
        std::cout << "A";


    if (Suit == HEARTS)
        print("♥", color_red, color_white);
    else if (Suit == DIAMONDS)
        print("♦", color_red, color_white);
    else if (Suit == CLUBS)
        print("♣", color_black, color_white);
    else
        print("♠", color_black, color_white);
}