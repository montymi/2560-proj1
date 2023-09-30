#include "Mastermind.hpp"
#include <iostream>
#include <math.h>
#include <stdint.h>
#include <vector>

#define MASTERMIND_MAX_GUESSES 12

Mastermind::Mastermind(int length, int number) {
  this->color_count = number;
  this->solution = std::vector<int>(length);
  for (int i = 0; i < length; i++) {
    this->solution[i] = rand() % number;
  }
}

std::vector<int> Mastermind::submit_guess(std::vector<int> guesses) {
  std::vector<int> result = std::vector<int>(guesses.size());
  std::vector<unsigned char> used = std::vector<unsigned char>(guesses.size());
  std::vector<int> response = {0,0};
  int guess_index = 0;
  for (int i = 0; i < solution.size(); i++) {
    result[i] = UINT8_MAX;
    used[i] = 0;
  }

  if (guesses.size() != solution.size())
    return result;
  int count = 0;
  for (int i = 0; i < solution.size(); i++) {
    if (guesses[i] == solution[i]) {
      result[i] = 2;
      used[i] = 1;
    }
  }
  for (int i = 0; i < guesses.size(); i++) {
    for (int j = 0; j < solution.size(); j++) {
      if (i == j) {
        continue;
      }
      if (!used[j] && guesses[i] == solution[j]) {
        result[i] = 1;
        used[j] = 1;
      }
    }
  }
  for (int i = 0; i < solution.size(); i++) {
    if (result[i] == UINT8_MAX) {
      result[i] = 0;
    }
  }
  return result;
}

void Mastermind::PlayGame(void) {
  std::vector<int> guess = std::vector<int>(solution.size());
  std::vector<int> result = std::vector<int>(solution.size());
  bool error_flag = false;
  int turn = 0;
  std::cout
      << "Each guess should be one line with " << solution.size()
      << " numbers, separated by spaces.\nEach number should be between 1 and "
      << color_count << std::endl;
  while (turn < MASTERMIND_MAX_GUESSES) {
    std::cout << "Guess " << turn + 1 << ": ";
    for (int i = 0; i < guess.size(); i++) {
      std::cin >> guess[i];
    }
    for (int i = 0; i < solution.size(); i++) {
      if (guess[i] < 0 || guess[i] >= color_count) {
        std::cout << "Invalid guess. All guesses must be between 0 and "
                  << color_count - 1 << std::endl;
        error_flag = true;
        break;
      }
    }
    if (!error_flag) {
      result = this->submit_guess(guess);
      turn++;
    }
    std::cout << "Response: ";
    for (int i = 0; i < result.size(); i++) {
      std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    error_flag = false;
  }
}