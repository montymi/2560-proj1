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
