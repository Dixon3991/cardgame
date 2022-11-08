#include "Deck.h"
#include <ctime>
#include<stdlib.h>

int main()
{
    srand(time(nullptr));
    Deck carddeck;
    carddeck.Shuffle();
    carddeck.Print();
    system("pause");
    return 0;
}