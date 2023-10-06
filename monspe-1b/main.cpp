#include <iostream>
#include <stdint.h>
#include "Mastermind.hpp"
#include "Response.hpp"
#include "Code.hpp"

int gamemode;
std::vector<int> results = {0, 0};
int length, range, num;
std::vector<std::vector<int>> guess_dir;

int main() {
  std::cout << "Length and digit range (separated by spaces): ";
  std::cin >> length >> range;
  Mastermind Game(length, range);
  Mastermind Test;
  Game.PlayGame();
  return 1;
}
