/**
 * @file Card.h
 *
 * @brief Contains the data and functions for a single node on 
 *  a singly linked list of playing cards, as well as enums for
 *  suits and card values
 */

#include <iostream>

#ifndef CARD_H
#define CARD_H

typedef enum SUIT_T{
  SUIT_CLUBS,
  SUIT_DIAMONDS,
  SUIT_HEARTS,
  SUIT_SPADES,
  SUIT_NUM,
} SUIT_T;

typedef enum CARDVALUE_T{
  CARDVALUE_ACE,
  CARDVALUE_TWO,
  CARDVALUE_THREE,
  CARDVALUE_FOUR,
  CARDVALUE_FIVE,
  CARDVALUE_SIX,
  CARDVALUE_SEVEN,
  CARDVALUE_EIGHT,
  CARDVALUE_NINE,
  CARDVALUE_TEN,
  CARDVALUE_JACK,
  CARDVALUE_QUEEN,
  CARDVALUE_KING,
  CARDVALUE_NUM,
} CARDVALUE_T;

class Card{
  public:
    Card(CARDVALUE_T val, SUIT_T suit);
    void setValue(CARDVALUE_T val);
    void setSuit(SUIT_T suit);
    void setNext(Card* card);
    Card* getNext(void);
    CARDVALUE_T getValue(void);
    SUIT_T getSuit(void);
    void* operator new(size_t size);
    
    friend std::ostream& operator<<(std::ostream& os, Card rhs);
  private:
    Card* next;
    CARDVALUE_T value;
    SUIT_T suit;
};

#endif //CARD_H
