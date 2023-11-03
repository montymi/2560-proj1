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
  std::vector<Card*> top24Cards;
  for (int i = 0; i < 24; i++) {
      Card* currentCard = deck.deal();
      top24Cards.push_back(currentCard);
  }
  std::string action;
  int round = 0;
  int score = 0;
  while (round < 24 || play) {
     std::cout << "\nDo you want to flip the next card? (y/n): ";
     std::cin >> action;
     if (action == "Y" || action == "y") {
      std::cout << "Drawn:\n" << *top24Cards[round];
      Card* drawn = top24Cards[round];
      switch (drawn->getValue()) {
        case CARDVALUE_ACE:
          score += 10;
        case CARDVALUE_KING:
          score += 5;
        case CARDVALUE_QUEEN:
          score += 5;
        case CARDVALUE_JACK:
          score += 5;
        case CARDVALUE_SEVEN:
          score = score / 2;
        case CARDVALUE_EIGHT:
          score = score;
        case CARDVALUE_NINE:
          score = score;
        case CARDVALUE_TEN:
          score = score;
        default: 
          score = 0;
      }
      if (drawn->getSuit() == SUIT_HEARTS) { score += 1; }
      std::cout << "Score: " << score;
      std::cout << "\nHand:\n";
      for (int i = 0; i <= round; i++) {
        std::cout << *top24Cards[i];
      }
      round++;
     }
     else if (action == "N" || action == "n") {
      std::cout << "Final Score: " << score << "\n\n------------------\n";
      std::cout << "\nTop 24 cards:\n";
      for (int i = 0; i < 24; i++) {
        std::cout << i+1 << "\t| " << *top24Cards[i];
      }
      std::cout << "\nRemaining cards in the deck:\n";
      std::cout << deck;       // which makes this << deck
      std::cout << "\nThanks for playing!";
      play = false;
     }
     else {
       std::cout << "Please input a y/Y to flip or n/N to end\n";
     }
  }
}
