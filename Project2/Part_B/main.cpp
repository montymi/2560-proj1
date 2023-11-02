#include <iostream>
#include "Deck.h"

/********** PRIVATE FUNCTION DECLARATIONS ************/

void playFlip(void);

/******************** MAIN ***************************/

int main()
{
  playFlip();
  return 0;
}

/********** PRIVATE FUNCTION DEFINITIONS *************/

void playFlip(void)
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
