#include <iostream>
#include "Deck.h"

int main()
{
  Deck* deck = new Deck();
  std::cout << *deck;

  for (int i = 0; i < 3; i++)
  {
    deck->shuffle();
    std::cout  << "\n------ shuffle " << i + 1 << " ----\n\n" << *deck;
  }
  delete deck;
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
