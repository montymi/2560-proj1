#include "Mastermind.hpp"
#include "Code.hpp"
#include <iostream>
#include <math.h>
#include <stdint.h>
#include <vector>

#define MASTERMIND_MAX_GUESSES 12

Mastermind::Mastermind() : n(5), m(10), game(5, 10) {}

Mastermind::Mastermind(int n, int m) : n(n), m(m), game(n, m) {}

void Mastermind::getSecret()
{
    std::cout << "Secret: ";
    for (int i = 0; i < game.getCode().size(); ++i) {std::cout << game.getCode()[i];}
    std::cout << std::endl;
}

Code Mastermind::humanGuess()
{
    Code human(n, m);
    std::vector<int> guess = std::vector<int>(n);
    for (int i = 0; i < n; ++i) { std::cin >> guess[i]; }
    for (int k = 0; k < n; ++k)
    {
        if (guess[k] >= m || guess[k] < 0) { return Code(0,0); }
    }
    if (human.establishGuessCode(guess)) { return human; }
    return Code(0,0);
}

Response Mastermind::getResponse(Code guess)
{
    Response res(guess.getLength(), guess.getNumValues());
    res.setCorrect(game.checkCorrect(guess));
    res.setIncorrect(game.checkIncorrect(guess));
    return res;
}

bool Mastermind::isSolved(Response& check)
{
  return (check.getCorrect() == n);
}

void Mastermind::PlayGame()
{
    this->game.createRandomCode();
    getSecret();
    std::cout << "Guess (separated by spaces):\n";
    for (int round = 1; round <= 10; ++round){
        Code input = humanGuess();
        Response results = getResponse(input);
        std::cout << results << std::endl;
        if (isSolved(results)) { std::cout << "Solved!\n"; break;}
    }
}
