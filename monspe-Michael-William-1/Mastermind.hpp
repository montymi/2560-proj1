#include <vector>
#include <iostream>
#include "Response.hpp"
#include "Code.hpp"

class Mastermind
{
  public:
    Mastermind();
    Mastermind(int n, int m);
    void getSecret(void);
    Code humanGuess(void);
    // Response& getResponse(void);
    bool isSolved(Response& check);
    void PlayGame(void);
  private:
    int n, m;
    Code game;
};