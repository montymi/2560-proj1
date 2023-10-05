#include "Response.hpp"
#include <iostream>

Response::Response(int num_correct, int num_incorrect)
{
  correct = num_correct;
  incorrect = num_incorrect;
}

std::vector<unsigned char> Response::check_response(std::vector<int> guess, std::vector<int> solution);
{
  return vector<int>(0);
}

int Response::getCorrect(void)
{
  return correct;
}

int Response::getIncorrect(void)
{
  return incorrect;
}

bool operator==(Response lhs, Response rhs)
{
  return false;
}

std::ostream& operator<<(std::ostream& os, Response rhs)
{
  return os;
}

