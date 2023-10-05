#include "_Response.hpp"

Response::Response(int correct, int incorrect)
    : numCorrect(correct), numIncorrect(incorrect) {}

void Response::setCorrect(int correct) {
    numCorrect = correct;
}
void Response::setIncorrect(int incorrect) {
    numIncorrect = incorrect;
}
int Response::getCorrect() const {
    return numCorrect;
}
int Response::getIncorrect() const {
    return numIncorrect;
}
    
bool Response::operator==(const Response& rhs) const {
    if (numCorrect == rhs.getCorrect() | numIncorrect == rhs.getIncorrect()) { return true; }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Response& rhs) {
    return os;
}
