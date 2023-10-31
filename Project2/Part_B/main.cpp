#include <iostream>
#include "Deck.h"

int main()
{
  Deck* deck = new Deck();
  std::cout << *deck;

  for (int i = 0; i < 3; i++)
  {
    std::cout << "Loop: " << i << std::endl;
    deck->shuffle();
    std::cout << "Successfully shuffled\n";
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
      std::cout << "Continuing with the flip..." << std::endl;
      // Place your flip code here
  } else {
      std::cout << "Exiting without flipping." << std::endl;
      // Exit or return as needed
  }
}
