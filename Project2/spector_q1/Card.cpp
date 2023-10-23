#include <iostream>
#include "Card.h"

/********** PRIVATE FUNCTION DECLARATIONS ************/

std::string getValueString(CARDVALUE_T value);
std::string getSuitString(SUIT_T suit);

/********** PUBLIC FUNCTION DEFINITIONS **************/

Card::Card(CARDVALUE_T val, SUIT_T suit)
{
  this->value = val;
  this->suit = suit;
  this->next = (Card*) nullptr;
}

void Card::setValue(CARDVALUE_T val)
{
  this->value = val;
}

void Card::setSuit(SUIT_T suit)
{
  this->suit = suit;
}

void Card::setNextPointer(Card* card)
{
  next = card;
}

Card* Card::getNext(void)
{
  return this->next;
}

CARDVALUE_T Card::getValue(void)
{
  return this->value;
}

SUIT_T Card::getSuit(void)
{
  return this->suit;
}

void* Card::operator new(size_t size)
{
  void* p = ::operator new(size);
  return p;
}

std::ostream& operator<<(std::ostream& os, Card rhs)
{
  if (rhs.value >= CARDVALUE_NUMVALUES || rhs.value < 0 || rhs.suit >= SUIT_NUMSUITS || rhs.suit < 0)
  {
    os << "INVALID CARD\n";
  }
  else
  {
    os << getValueString(rhs.value) << " of " << getSuitString(rhs.suit) << "\n";
  }
  return os;
}

/********** PRIVATE FUNCTION DEFINITIONS *************/

std::string getValueString(CARDVALUE_T value)
{
  switch(value)
  {
    case CARDVALUE_ACE:
      return "Ace";
    case CARDVALUE_TWO:
      return "Two";
    case CARDVALUE_THREE:
      return "Three";
    case CARDVALUE_FOUR:
      return "Four";
    case CARDVALUE_FIVE:
      return "Five";
    case CARDVALUE_SIX:
      return "Six";
    case CARDVALUE_SEVEN:
      return "Seven";
    case CARDVALUE_EIGHT:
      return "Eight";
    case CARDVALUE_NINE:
      return "Nine";
    case CARDVALUE_TEN:
      return "Ten";
    case CARDVALUE_JACK:
      return "Jack";
    case CARDVALUE_QUEEN:
      return "Queen";
    case CARDVALUE_KING:
      return "King";
    default:
      return "";
  }
}

std::string getSuitString(SUIT_T suit)
{
  switch(suit)
  {
    case SUIT_DIAMONDS:
      return "diamonds";
    case SUIT_CLUBS:
      return "clubs";
    case SUIT_SPADES:
      return "spades";
    case SUIT_HEARTS:
      return "hearts";
    default:
      return "";
  }
}
