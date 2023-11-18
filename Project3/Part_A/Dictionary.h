#include <vector>
#include <iostream>

#ifndef DICTIONARY_H
#define DICTIONARY_H

class Dictionary
{
public:
  Dictionary(void);
  void readWords(std::string filename);
  void printWords(void);
  void sortWords(void);
  bool lookupWord(std::string word);
private:
  std::vector<std::string> wordlist;
};

#endif //DICTIONARY_H
