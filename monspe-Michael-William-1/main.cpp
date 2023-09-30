#include <iostream>
#include <stdint.h>
#include "Mastermind.hpp"

int main() {
  std::cout << "Please enter game length and count\n";
  int length, count;
  std::cin >> length >> count;
  Mastermind game(length, count);
  game.PlayGame();
}