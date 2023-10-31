/**
 * @file Deck.h
 *
 * @brief Contains the data and functions for a single node on
 *  a singly linked list of playing cards, as well as enums for
 *  suits and card values
 */

#include <iostream>
#include "Card.h"

#ifndef DECK_H
#define DECK_H

class Deck
{
  public:
    Deck(void);
    void shuffle(void);
    Card* getHeader(void);
    Card* deal(void);
    void replace(Card* card);
    friend std::ostream& operator<<(std::ostream& os, Deck& rhs);
    ~Deck(void);
  private:
    Card* header;
};


#endif //DECK_H
