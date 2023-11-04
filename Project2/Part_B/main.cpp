#include <iostream>
#include <vector>
#include "Deck.h"
#include "Card.h"


/**
 * @brief returns the way a score would change as the result of a card 
 * 
 * @param c: card to check
 * @param score: scoreboard
 * @retval -4 for lose all, -3 for set-to-one, -2 for lose half, -1 for 
 */
void scoreCard(Card* c, int& score);
/**
 * @brief starts the game
 *
 * @param deck: pointer to main deck
 * @retval void
 */
void playFlip(Deck* deck);

int main()
{
  Deck* deck = new Deck();  

  for (int i = 0; i < 3; i++)
  {
    deck->shuffle();      
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
    std::cout << "\nDo you want to flip a card? (y/n): ";
    std::cin >> action;
    if (action == "Y" || action == "y") {
      std::cout << "\nCard:\t" << *top24Cards[round];
      Card* drawn = top24Cards[round];
      scoreCard(drawn, score);
      std::cout << "\nScore: " << score;
      std::cout << "\nCurrent Hand:\n";
      for (int i = 0; i <= round; i++) {
        std::cout << *top24Cards[i];
      }
      round++;
    }
    else if (action == "N" || action == "n") {
      std::cout << "\nTop 24 cards:\n";
      for (int i = 0; i < 24; i++) {
        std::cout << *top24Cards[i];
      }
      std::cout << "\nRemaining cards in the deck:\n";
      std::cout << *deck;
      std::cout << "\nFinal Score: " << score << "\n\n------------------\n";
      play = false;
    }
    else {
       std::cout << "Please input a y/Y to flip or n/N to end\n";
    }
  }
  std::cout << "\nGame Ended.\nThanks for playing!";
}

void scoreCard(Card* c, int& score)
{
  switch (c->getValue()) {
    case CARDVALUE_ACE:
      score += 10;
      break;
    case CARDVALUE_KING:
      score += 5;
      break;
    case CARDVALUE_QUEEN:
      score += 5;
      break;
    case CARDVALUE_JACK:
      score += 5;
      break;
    case CARDVALUE_TEN:
      break;
    case CARDVALUE_NINE:
      break;
    case CARDVALUE_EIGHT:
      break;
    case CARDVALUE_SEVEN:
      score = score / 2;
      break;
    case CARDVALUE_SIX:
      score = 0;
      break;
    case CARDVALUE_FIVE:
      score = 0;
      break;
    case CARDVALUE_FOUR:
      score = 0;
      break;
    case CARDVALUE_THREE:
      score = 0;
      break;
    case CARDVALUE_TWO:
      score = 0;
      break;
    default: 
      break;
  }
  if (c->getSuit() == SUIT_HEARTS) { score += 1; }
}
