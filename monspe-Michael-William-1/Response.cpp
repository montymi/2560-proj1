#include "Response.hpp"
#include "Code.hpp"
#include <vector>
#include <iostream>

Response::Response(int num_correct, int num_incorrect)
{
  correct = num_correct;
  incorrect = num_incorrect;
}

void Response::check_response(Code guess, Code solution)
{
  correct = solution.checkCorrect(guess);
  incorrect = solution.checkIncorrect(guess);
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
  return (lhs.correct == rhs.correct && lhs.incorrect == rhs.incorrect);
}

std::ostream& operator<<(std::ostream& os, Response rhs)
{
  os << "Results: correct: " << rhs.getCorrect() << ", incorrect: " << rhs.getIncorrect();
  return os;
}

