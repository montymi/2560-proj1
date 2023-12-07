#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <list>
#include <fstream>

typedef int ValueType;
const int SquareSize = 3; // The number of cells in a small square
// (usually 3). The board has
// SquareSize^2 rows and SquareSize^2
// columns.

class Board
// Stores the entire Sudoku board
{
public:
  Board(int);
  void clear(void);
  void initialize(ifstream &fin);
  void print(void);
  bool isBlank(int, int);
  ValueType getCell(int, int);
  void printConflicts(void);
private:
// The following matrices go from 1 to BoardSize in each
// dimension, i.e., they are each (BoardSize+1) * (BoardSize+1)
  matrix<ValueType> value;
};
