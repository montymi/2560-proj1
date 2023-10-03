#include <vector>

class Code{
  public:
    Code(int length, int num_values);
    int checkCorrect(Code guess);
    int checkIncorrect(Code guess);
    bool confirmValue(int position, int value);
    void createRandomCode(void);
    int getLength();
    int getNumValues();
    bool operator==(Code rhs);
  private:
    std::vector<int> code;
    int length;
    int num_values;
};
