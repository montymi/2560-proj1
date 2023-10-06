#include <iostream>
#include <stdint.h>
#include "Mastermind.hpp"
#include "Response.hpp"
#include "Code.hpp"

// int main() {
//   std::cout << "Please enter game length and count\n";
//   int length, count;
//   std::cin >> length >> count;
//   Mastermind game(length, count);
//   game.PlayGame();
// }

int gamemode;
std::vector<int> results = {0, 0};
int length, range, num;
std::vector<std::vector<int>> guess_dir;

int main() {
  std::cout << "Welcome to Mastermind!\nSelect gamemode below:\n[1] Testing\n[2] Play\nEnter gamemode number: ";
  std::cin >> gamemode;
  if (gamemode == 1) {
      // part a: Test guesses
      length = 5;
      range = 7;
      Code secret(length, range); // {game} instance of code class
      secret.createRandomCode();
      Code guess(length, range);
      guess_dir.push_back({5, 0, 3, 2, 6});
      guess_dir.push_back({2, 1, 2, 2, 2});
      guess_dir.push_back({1, 3, 3, 4, 5});
      // guess_dir.push_back(secret.getCode()); // uncomment to show win screen
      std::cout << "Round | Guess | Results\n";
      for (int i = 0; i < guess_dir.size(); ++i) {
        num = i + 1;
        if (num >= 12) {
          std::cout << "Out of turns. You lost";
          return 1;
        }
        std::cout << num << " | ";
        for (int j = 0; j < length; ++j) {
          std::cout << guess_dir[i][j] << " ";
        }
        if (!guess.establishGuessCode(guess_dir[i])){
          return -1; // error
        }
        
        results[0] = secret.checkCorrect(guess); // pass in object of Code guess?
        results[1] = secret.checkIncorrect(guess); // same as above
        std::cout << "| " << results[0] << results[1] << std::endl;
        if (results[0] == length) {
          std::cout << "Congratulations! You beat Mastermind.\n";
          return 1;
        }
      }
      std::cout << "Secret: ";
      for (int k = 0; k < length; ++k) {
        std::cout << secret.getCode()[k];
      }
  } else if (gamemode == 2) {
      std::cout << "Length and digit range (separated by spaces): ";
      std::cin >> length >> range;
      Mastermind Game(length, range);
      Mastermind Test;
      // part b: Play Game
      Game.PlayGame();
  } else { 
      std::cout << "Please enter either 1 or 2\n";
  }
  return 1;
}
