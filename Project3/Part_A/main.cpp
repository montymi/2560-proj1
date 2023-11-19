#include <iostream>
#include <vector>
#include "Dictionary.h"
#include "Grid.h"

const int MIN_LENGTH = 3;

void findMatches(Dictionary dict, Grid grid);
void search(Dictionary dict, Grid grid, int row, int col);

int main(){
  Dictionary dict = Dictionary();
  Grid grid = Grid("input15.txt");
  dict.readWords("dictionary.txt");
  findMatches(dict, grid);
  return 0;
}

void findMatches(Dictionary dict, Grid grid)
{
  int width = grid.getWidth(), height = grid.getHeight();
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      search(dict, grid, row, col);
    }
  }
}

void search(Dictionary dict, Grid grid, int row, int col)
{
  // directional arrays
  int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int direction = 0; direction < 8; direction++) {
    std::string current = "";
    int rd = row + x[direction];
    int cd = col + y[direction];

    while (rd > -1 && rd < grid.getHeight() && cd > -1 && cd < grid.getWidth()) {
      current += grid.getLetter(cd, rd);
      if (current.length() >= MIN_LENGTH) {
        std::cout << current << std::endl;
        if (dict.lookupWord(current)) {std::cout << current << std::endl;}
      }
      rd += x[direction];
      cd += y[direction];
    }
  }
}
