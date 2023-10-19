#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <iostream>

class Response {
public:
  Response();
  Response(int correct, int incorrect);

  void setCorrect(int correct);
  void setIncorrect(int incorrect);
  int getCorrect() const;
  int getIncorrect() const;
    
  bool operator==(const Response& rhs) const;

  friend std::ostream& operator<<(std::ostream& os, const Response& rhs);
private:
  int numCorrect;
  int numIncorrect;
};

#endif
