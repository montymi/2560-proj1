#include <iostream>
#include <vector>
#include "Dictionary.h"
#include "Grid.h"

#define MIN_LENGTH = 5

void findMatches(Dictionary dict, Grid grid);
void search(Grid grid, int row, int col);

int main(){
  return 0;
}

void findMatches(Dictionary dict, Grid grid)
{
  Dictionary dict = Dictionary();
  (void) grid;
  int width = grid.getWidth(), height = grid.getHeight();
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      std::vector<std::string> found;
      search(grid, row, col, found);

      for (const string &match : found) {
        if dict.lookupWord(match) {std::cout << match << std::endl;}
      }
    }
  }
}

void search(Grid grid, int row, int col, std::vector found)
{
  int x[] = {};
  int y[] = {};

  for (int direction = 0; direction < 8; direction++) {
    string current = "";
    int rd = row + x[dir];
    int cd = col + y[dir];

    while (rd > -1 && rd < grid.getHeight() && cd > -1 && grid.getWidth()) {
      current += grid[rd][cd];
      if (current.length() >= MIN_LENGTH) {
        found.push_back(current);
      }
      rd += x[dir];
      cd += y[dir];
    }
  }
}
