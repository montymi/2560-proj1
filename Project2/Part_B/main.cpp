#include <iostream>
#include "Deck.h"

int main()
{
  Deck* deck = new Deck();  // TODO: compare against Deck deck = Deck()
  std::cout << *deck;       // which makes this << deck

  for (int i = 0; i < 3; i++)
  {
    deck->shuffle();      // and this deck.shuffle()
    std::cout  << "\n------ shuffle " << i + 1 << " ----\n\n" << *deck; // and this << deck
  }
  delete deck;          // this would be removed
  return 0;
}

void playFlip()
{
  std::string userInput;
  std::cout << "Flip (Y/n): ";
  std::cin >> userInput;

  if (userInput.empty() || userInput == "Y" || userInput == "y") {
      std::cout << "Flipping..." << std::endl;
  } else {
      std::cout << "Exiting." << std::endl;
  }
}
