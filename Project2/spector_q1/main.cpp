#include <iostream>
#include "Deck.h"

int main()
{
  Deck deck = Deck();
  std::cout << deck << "\n------------------------\n\n";
  deck.shuffle();
  std::cout << deck;
}
