#include <vector>
#include <iostream>
#include "Code.hpp"

class Response
{
  public:
    Response(int num_correct, int num_incorrect);
    void check_response(Code guess, Code solution);
    int getCorrect(void);
    int getIncorrect(void);
    friend bool operator==(Response lhs, Response rhs);
    friend std::ostream& operator<<(std::ostream& os, Response rhs);
  private:
    int correct;
    int incorrect;
};
