#include <iostream>
#include "Deck.h"
#include "Card.h"


/**
 * @brief returns the way a score would change as the result of a card 
 * 
 * @param c: card to check
 * @retval -4 for lose all, -3 for set-to-one, -2 for lose half, -1 for 
 */
int scoreCard(Card* c, int& score);
void playFlip(Deck* deck);

int main()
{
  Deck* deck = new Deck();  
  std::cout << *deck;    

  for (int i = 0; i < 3; i++)
  {
    deck->shuffle();      
    std::cout  << "\n------ shuffle " << i + 1 << " ----\n\n" << *deck; 
  }
  playFlip(deck);
  delete deck;          
  return 0;
}

void playFlip(Deck* deck)
{
  bool play = true;
  std::vector<Card*> top24Cards;
  for (int i = 0; i < 24; i++) {
      Card* currentCard = deck->deal();
      top24Cards.push_back(currentCard);
  }
  std::string action;
  int round = 0;
  int score = 0;
  while (round < 24 && play) {
     std::cout << "\nDo you want to flip the next card? (y/n): ";
     std::cin >> action;
     if (action == "Y" || action == "y") {
      std::cout << *top24Cards[round];
      Card* drawn = top24Cards[round];
      score = scoreCard(drawn, score);
      std::cout << "\nScore: " << score;
      std::cout << "\n\nCurrent Hand:\n";
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
      std::cout << *deck;
      play = false;
     }
     else {
       std::cout << "Please input a y/Y to flip or n/N to end\n";
     }
  }
  std::cout << "\nGame Ended.\nThanks for playing!";
}

int scoreCard(Card* c, int& score)
{
 if (c->getSuit() == SUIT_HEARTS) { score += 1; }
 switch (c->getValue()) {
   case CARDVALUE_ACE:
     return score + 10;
   case CARDVALUE_KING:
     return score + 5;
   case CARDVALUE_QUEEN:
     return score + 5;
   case CARDVALUE_JACK:
     return score + 5;
   case CARDVALUE_SEVEN:
     return score / 2;
   case CARDVALUE_EIGHT:
     return score;
   case CARDVALUE_NINE:
     return score;
   case CARDVALUE_TEN:
     return score;
   default: 
     return score = 0;
 }
}
