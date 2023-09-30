#include <vector>
#include "Response.hpp"

class Mastermind
{
  public:
    Mastermind(int length, int number);
    void PlayGame(void);
  private:
    std::vector<int> solution;
    int color_count;
    std::vector<int> submit_guess(std::vector<int> guesses);
};