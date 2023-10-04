/**
 * @file Code.hpp
 */

#ifndef CODE_HPP
#define CODE_HPP

#include <vector>

class Code{
  public:
    /**
     * @brief Constructer for Code
     * 
     * @param length: the length of the correct Code
     * @param num_values: the number of values each value in the code can be
     */
    Code(int length, int num_values);
    
    /**
     * @brief gets Code object's stored entry
     * 
     * @retval vector<int>
     */
    std::vector<int> getCode();

    /**
     * @brief counts the number of correct number, correct position
     * 
     * @param guess: the guessed code
     * @retval the number of correct or -1 on error
     */
    int checkCorrect(Code guess);
    
    /**
     * @brief counts the number of correct number, wrong position
     *
     * @param guess: the guessed code
     * @retval the number of correct or -1  on error
     */
    int checkIncorrect(Code guess);
    
    /**
     * @brief returns True if the number at a position is a value
     * 
     * @param position: the position to guess
     * @param value: the value geussed
     * @retval true if the guess is correct
     */
    bool confirmValue(int position, int value);
    
    /**
     * @brief Populates code vector with a random code
     */
    void createRandomCode(void);
    
    /**
     * @brief Populates code vector with values of a passed vector
     * 
     * @param guesses: the vector containing the desired code
     * @retval false on error
     */
    bool establishGuessCode(std::vector<int> guesses);
    
    /**
     * @brief Gets the length of the code
     * 
     * @retval length
     */
    int getLength();
    
    /**
     * @brief getter for number of possible values
     */
    int getNumValues();
    
    /**
     * @brief equivalence operater
     * 
     * @param rhs: right hand side Code of equals sign
     * @retval true if all codes and positions match
     */
    bool operator==(Code rhs);

  private:
    std::vector<int> code;
    int length;
    int num_values;
};

#endif
