#include <iostream>
#include <vector>
#include "Dictionary.h"
#include "Grid.h"

const int MIN_LENGTH = 5;

void findMatches(Dictionary dict, Grid grid);
void search(Grid grid, int row, int col, std::vector<std::string> found);

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
      std::vector<std::string> found;
      search(grid, row, col, found);

      for (const std::string &match : found) {
        if (dict.lookupWord(match)) {std::cout << match << std::endl;}
      }
    }
  }
}

void search(Grid grid, int row, int col, std::vector<std::string> found)
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
        found.push_back(current);
      }
      rd += x[direction];
      cd += y[direction];
    }
  }
}
