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
  std::vector<int> used = std::vector<int>(length, 0);
  for (int i = 0; i < length; i++)
    if (guess.confirmValue(i, code[i]))
      used[i] = 1;
  for (int guess_idx = 0; guess_idx < length; guess_idx++){ //iterate through guess array
    for (int check_idx = 0; check_idx < length; check_idx++)
    {
      if(check_idx == guess_idx) //don't check same position
        continue;
      if(used[check_idx])
        continue;
      if(guess.confirmValue(guess_idx, code[check_idx]))
      {
        used[check_idx = 1];
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
  for (int i = 0; i < length; i++)
  {
    code[i] = rand() % num_values;
  }
}

int Code::getLength(void)
{
  return length;
}

int Code::getNumValues(void)
{
  return num_values;
}

bool Code::operator==(Code rhs)
{
  return checkCorrect(rhs) == length;
}
