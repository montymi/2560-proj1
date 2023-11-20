#include "Dictionary.h"
#include <iostream>
#include <vector>
#include <fstream>

/******* PRIVATE FUNCTION DECLARATIONS *********/

void convertToLower(char* str, int len);

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
  if (wordlist.size() == 0)
  {
    return;
  }
  for (int i = 0; i < wordlist.size(); i++)
  {
    convertToLower(&wordlist[i][0], wordlist[i].length());
  }
  int current_word = 0;
  std::string first = wordlist[0], temp;
  for (int i = 0; i < wordlist.size(); i++)
  {
    for (int j = i; j < wordlist.size(); j++)
    {
      if (wordlist[j] < first)
      {
        first = wordlist[j];
        current_word = j;
      }
    }
    wordlist[current_word] = wordlist[i];
    wordlist[i] = first;
    first = wordlist[i + 1];
    current_word = i + 1;
  }
}

int Dictionary::lookupWord(std::string word)
{
  int top = wordlist.size();
  int bottom = 0;
  int i = top / 2;
  while (wordlist[i] != word)
  {
    if(wordlist[i] > word)
    {
      if(i == top)
        i--;
      top = i;
    }
    if (wordlist[i] < word)
    {
      if(i == bottom)
        i++;
      bottom = i;
    }
    if (top == bottom)
    {
      return -1;
    }
    i = ((top - bottom) / 2) + bottom;
  }
  return i;
}

void convertToLower(char* str, int len)
{
  for (int i = 0; i < len; i++)
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
    {
      str[i] += 32;
    }
  }
}
