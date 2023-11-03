#include <iostream>
#include <cmath>
#include "Deck.h"
#include "Card.h"
#include <ctime>

/********** PUBLIC FUNCTION DEFINITIONS **************/

Deck::Deck(void)
{
  this->header = new Card((CARDVALUE_T) 0, (SUIT_T) 0);
  Card* current_card = this->header;
  Card* next_card;
  for (int suit = 0; suit < (int) SUIT_NUM; suit++)
  {
    for(int value = 0; value < (int) CARDVALUE_NUM; value++)
    {
      if (value == 0 && suit == 0)
      {
        continue;
      }
      next_card = new Card((CARDVALUE_T) value, (SUIT_T) suit);
      current_card->setNext(next_card);
      current_card = current_card->getNext();
    }
  }
}

void Deck::shuffle(void)
{
  int cards = 0;
  Card* current_node = this->header;
  srand(time(NULL));
  while (current_node != nullptr)
  {
    cards++;
    current_node = current_node->getNext();
  }
  current_node = this->header;
  Card* swap_node;
  Card temp = Card(CARDVALUE_NUM, SUIT_NUM);
  while(cards > 0)
  {
    swap_node = current_node;
    int swap_card = rand()%cards;
    for(int i = 0; i < swap_card; i++)
    {
      swap_node = swap_node->getNext();
    }
    
    temp = Card(swap_node->getValue(), swap_node->getSuit());
    swap_node->setValue(current_node->getValue());
    swap_node->setSuit(current_node->getSuit());
    current_node->setValue(temp.getValue());
    current_node->setSuit(temp.getSuit());

    current_node = current_node->getNext();
    cards--;
  }
}

Card* Deck::deal(void)
{
  Card* dealt = this->header;
  this->header = dealt->getNext();
  dealt->setNext(nullptr);
  return dealt;
}

void Deck::replace(Card c)
{
  Card* last_card = header;
  while (last_card->getNext() != nullptr)
  {
    last_card = last_card->getNext();
  }
  Card* added_card = new Card(c);
  last_card->setNext(added_card);
}

std::ostream& operator<<(std::ostream& os, Deck& rhs)
{
  Card* current_card = rhs.header;
  while(current_card != nullptr)
  {
    os << *current_card;
    current_card = current_card->getNext();
  }
  return os;
}

Deck::~Deck()
{
  Card* current = this->header;
  //std::cout << "Head: " << header << std::endl;  // logging
  while (current != nullptr) {
    Card* next = current->getNext();
    //std::cout << "Next: " << next << std::endl;  // logging
    delete current;
    current = next;
  }
}
