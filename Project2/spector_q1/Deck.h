#include <iostream>
#include "Card.h"

#ifndef DECK_H
#define DECK_H

class Deck
{
  public:
    Deck(void);
    void shuffle(void);
    friend std::ostream& operator<<(std::ostream& os, Deck rhs);
  private:
    Card* header;
};


#endif //DECK_H
