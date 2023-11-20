#include <iostream>
#include <vector>
#include "Dictionary.h"
#include "Grid.h"

const int MIN_LENGTH = 5;

void findMatches(Dictionary dict, Grid grid);
void searchDirections(Dictionary dict, Grid grid, int row, int col);

int main(){
  Dictionary dict = Dictionary();
  Grid grid = Grid("input15.txt");
  dict.readWords("dictionary.txt");
  dict.sortWords();
  findMatches(dict, grid);
  return 0;
}

void findMatches(Dictionary dict, Grid grid)
{
  int width = grid.getWidth(), height = grid.getHeight();
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      searchDirections(dict, grid, row, col);
    }
  }
}

void searchDirections(Dictionary dict, Grid grid, int row, int col)
{
  // directional arrays
  int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int direction = 0; direction < 8; direction++) {
    std::string current = "";
    int rd = row;
    int cd = col;

    while (current.length() <= dict.getMax()) {
      current += grid.getLetter(cd%grid.getWidth(), rd%grid.getHeight());
      if (current.length() >= MIN_LENGTH) {
        if (dict.lookupWord(current) != -1) {std::cout << "MATCH: ";}
        std::cout << current << std::endl;
      }
      rd += x[direction];
      cd += y[direction];
    }
  }
}
