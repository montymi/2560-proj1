#include "Response.hpp"

Response::Response() : numCorrect(0), numIncorrect(0) {}

Response::Response(int correct, int incorrect)
    : numCorrect(correct), numIncorrect(incorrect) {}

void Response::setCorrect(int correct) {
    this->numCorrect = correct;
}
void Response::setIncorrect(int incorrect) {
    this->numIncorrect = incorrect;
}
int Response::getCorrect() const {
    return this->numCorrect;
}
int Response::getIncorrect() const {
    return this->numIncorrect;
}
    
bool Response::operator==(const Response& rhs) const {
    if (this->numCorrect == rhs.getCorrect() && this->numIncorrect == rhs.getIncorrect()) { return true; }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Response& rhs) {
    os << "Correct: " << rhs.getCorrect() << ", Incorrect: " << rhs.getIncorrect();
    return os;
}
