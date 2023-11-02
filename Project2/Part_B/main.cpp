#include <iostream>
#include "Deck.h"

void playFlip(Deck& deck);

int main()
{
  Deck* deck = new Deck();  // TODO: compare against Deck deck = Deck()
  std::cout << *deck;       // which makes this << deck

  for (int i = 0; i < 3; i++)
  {
    deck->shuffle();      // and this deck.shuffle()
    std::cout  << "\n------ shuffle " << i + 1 << " ----\n\n" << *deck; // and this << deck
  }
  playFlip(*deck);
  delete deck;          // this would be removed
  return 0;
}

void playFlip(Deck& deck)
{
  bool play = true;
  std::cout << "\nTop 24 cards:\n";
  Card* currentCard = deck.deal();
  std::vector<Card*> top24Cards = {currentCard};
  for (int i = 0; i < 24; i++) {
      currentCard = deck.deal();
      top24Cards.push_back(currentCard);
      std::cout << i << "\t| " << *currentCard;
  }
  std::cout << "\nRemaining cards in the deck:\n";
  std::cout << deck;       // which makes this << deck
  std::string action;
  while (play) {
     std::cout << "\nDo you want to flip the next card? (Type 'flip' or 'quit'): ";
     std::cin >> action;
     if (action == "Y" || action == "y" || action.empty()) {
       std::cout << "Continuing...\n";
     }
     else if (action == "N" || action == "n") {
       std::cout << "Current Score: ";
       play = false;
     }
     else {
       std::cout << "Please input a y/Y to flip or n/N to end\n";
     }
  }
}
