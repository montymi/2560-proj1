#include "Dictionary.h"
#include <iostream>
#include <vector>
#include <fstream>

Dictionary::Dictionary(void)
{
  wordlist = std::vector<std::string>();
}

void Dictionary::readWords(std::string filename)
{
  std::ifstream infile(filename);
  std::string next;
  while(getline(infile, next))
  {
    wordlist.push_back(next);
  }
}

void Dictionary::printWords(void)
{
  for(int i = 0; i < wordlist.size(); i++)
  {
    std::cout << wordlist[i] << std::endl;
  }
}

void Dictionary::sortWords(void)
{
  
}

bool Dictionary::lookupWord(std::string word)
{
  (void) word;
}
