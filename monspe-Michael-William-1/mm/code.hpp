#include <vector>

class Code{
  public:
    Code(int length, int range);
    void updateGuess(std::vector<int> entry);
    int checkCorrect(Code guess);
    int checkIncorrect();
    void createSecret();
    std::vector<int> getSecret();
  private:
    std::vector<int> secret;
    std::vector<int> guess;
    int length;
    int range;
};    
