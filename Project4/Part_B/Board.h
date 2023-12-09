#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <list>
#include <fstream>
#include <vector>

typedef int ValueType;
const int SquareSize = 3; // The number of cells in a small square
// (usually 3). The board has
// SquareSize^2 rows and SquareSize^2
// columns.

static const int BOX_CONTENTS[9][9][2] = {{{1,1},{1,2},{1,3},{2,1},{2,2},{2,3},{3,1},{3,2},{3,3}},
                                          {{1,4},{1,5},{1,6},{2,4},{2,5},{2,6},{3,4},{3,5},{3,6}},
                                          {{1,7},{1,8},{1,9},{2,7},{2,8},{2,9},{3,7},{3,8},{3,9}},
                                          {{4,2},{4,2},{4,3},{5,1},{5,2},{5,3},{6,1},{6,2},{6,3}},
                                          {{4,4},{4,5},{4,6},{5,4},{5,5},{5,6},{6,4},{6,5},{6,6}},
                                          {{4,7},{4,8},{4,9},{5,7},{5,8},{5,9},{6,7},{6,8},{6,9}},
                                          {{7,1},{7,2},{7,3},{8,1},{8,2},{8,3},{9,1},{9,2},{9,3}},
                                          {{7,4},{7,5},{7,6},{8,4},{8,5},{8,6},{9,4},{9,5},{9,6}},
                                          {{7,7},{7,8},{7,9},{8,7},{8,8},{8,9},{9,7},{9,8},{9,9}}};

int getValMin();
int getValMax();


class Board
// Stores the entire Sudoku board
{
public:
  Board(int);
  void clear(void);
  void clear(int, int);
  void initialize(ifstream &fin);
  void print(void);
  bool isBlank(int, int);
  ValueType getCell(int, int);
  void printConflicts(void);
  bool setCell(int, int, int);
  bool checkSolved(void);
  bool checkConflict(int r, int c, int val);
  bool checkConflict(char type, int num, int val);
private:
// The following matrices go from 1 to BoardSize in each
// dimension, i.e., they are each (BoardSize+1) * (BoardSize+1)
  matrix<ValueType> value;
  matrix<bool> row;
  matrix<bool> column;
  matrix<bool> box;
};
