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
  int lookupWord(std::string word);
  int getMax(void);
  void heapSort(void);
private:
  std::vector<std::string> wordlist;
  int longestWord;
};

#endif //DICTIONARY_H
