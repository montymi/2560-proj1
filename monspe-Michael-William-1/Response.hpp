#include <vector>
#include <iostream>

class Response
{
  public:
    Response(int num_correct, int num_incorrect);
    std::vector<unsigned char> check_response(std::vector<int> guess, std::vector<int> solution);
    int getCorrect(void);
    int getIncorrect(void);
    friend bool operator==(Response lhs, Response rhs);
    friend std::ostream& operator<<(std::ostream& os, Response rhs);
  private:
    int correct;
    int incorrect;
};
