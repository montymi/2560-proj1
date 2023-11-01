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
