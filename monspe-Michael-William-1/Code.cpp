#include "Code.hpp"
#include <vector>
#include <cmath>

Code::Code(int length, int num_values)
{
  if(length == 0 || num_values == 0)
    return;
  code = std::vector<int>(length);
  this->length = length;
  this->num_values = num_values;
}

std::vector<int> Code::getCode()
{
  return code;
}


int Code::checkCorrect(Code guess)
{
  if (length != guess.getLength())
    return -1; //error
  if (num_values != guess.getNumValues())
    return -1;
  int result = 0;
  for (int i = 0; i < length; i++)
    if (guess.confirmValue(i, code[i]))
      result++;
  return result;
}

int Code::checkIncorrect(Code guess)
{
  if (length != guess.getLength())
    return -1; //error
  if (num_values != guess.getNumValues())
    return -1;
  int result = 0;
  std::vector<int> used_guess = std::vector<int>(length, 0);
  std::vector<int> used_check = std::vector<int>(length, 0);
  for (int i = 0; i < length; i++)
    if (guess.confirmValue(i, code[i]))
    {
      used_guess[i] = 1;
      used_check[i] = 1;
    }
  for (int guess_idx = 0; guess_idx < length; guess_idx++){ //iterate through guess array
    for (int check_idx = 0; check_idx < length; check_idx++)
    {
      if(check_idx == guess_idx) //don't check same position
        continue;
      if(used_guess[guess_idx] || used_check[guess_idx])
        continue;
      if(guess.confirmValue(guess_idx, code[check_idx]))
      {
        used_check[check_idx] = 1;
        used_guess[guess_idx] = 1;
        result++;
      }
    }
  }
  return result;
}

bool Code::confirmValue(int position, int value)
{
  return (code[position] == value);
}

void Code::createRandomCode(void)
{
  srand(time(NULL));
  for (int i = 0; i < length; i++)
  {
    code[i] = rand() % num_values;
  }
}

bool Code::establishGuessCode(std::vector<int> guesses)
{
  if(guesses.size() != length)
    return false;
  if (*std::max_element(guesses.begin(), guesses.end()) >= num_values || *std::min_element(guesses.begin(), guesses.end()) < 0) // changed this 
    return false;
  code = std::vector<int>(guesses.size());
  for (int i = 0; i < guesses.size(); i++)
    code[i] = guesses[i];
  return true;
}

int Code::getLength(void)
{
  return length;
}

int Code::getNumValues(void)
{
  return num_values;
}
