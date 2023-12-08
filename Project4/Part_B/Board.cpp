#include <iostream>
#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <list>
#include <fstream>
#include "Board.h"

const int Blank = -1; // Indicates that a cell is blank

const int BoardSize = SquareSize * SquareSize;
const int MinValue = 1;
const int MaxValue = 9;
int numSolutions = 0;

bool checkBox(matrix<ValueType> value, int i, int j, int c);
int getSubGroup(int i, int j);

Board::Board(int sqSize)
// Board constructor
: value(BoardSize+1,BoardSize+1),
  row(BoardSize+1,BoardSize+1),
  column(BoardSize+1,BoardSize+1),
  box(BoardSize+1,BoardSize+1)
{
  clear();
}

void Board::clear()
// Mark all possible values as legal for each board entry
{
  for (int i = 1; i <= BoardSize; i++)
    for (int j = 1; j <= BoardSize; j++)
    {
      value[i][j] = Blank;
      row[i][j] = false;
      column[i][j] = false;
      for (int val = 1; val <= BoardSize; val++)
        box[getSubGroup(i,j)][val] = false;
    }
}

void Board::clear(int i, int j) 
{
  ValueType val = getCell(i, j);
  setCell(i, j, Blank);
  row[i][val] = false;
  column[j][val] = false;
  box[getSubGroup(i,j)][val] = false;
}

void Board::initialize(ifstream &fin)
// Read a Sudoku board from the input file.
{
  char ch;
  clear();
  for (int i = 1; i <= BoardSize; i++)
  for (int j = 1; j <= BoardSize; j++)
  {
    fin >> ch;
    // If the read char is not Blank
    if (ch != '.')
      setCell(i,j,ch-'0'); // Convert char to int
    }
  }
  int squareNumber(int i, int j)
  // Return the square number of cell i,j (counting from left to right,
  // top to bottom. Note that i and j each go from 1 to BoardSize
  {
    // Note that (int) i/SquareSize and (int) j/SquareSize are the x-y
    // coordinates of the square that i,j is in.
    return SquareSize * ((i-1)/SquareSize) + (j-1)/SquareSize + 1;
  }

ostream &operator<<(ostream &ostr, vector<int> &v)
// Overloaded output operator for vector class.
{
  for (int i = 0; i < v.size(); i++)
    ostr << v[i] << " ";
  std::cout << std::endl;
  return ostr;
}

ValueType Board::getCell(int i, int j)
// Returns the value stored in a cell. Throws an exception
// if bad values are passed.
{
  if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
    return value[i][j];
  else
    throw rangeError("bad value in getCell");
}

bool Board::isBlank(int i, int j)
// Returns true if cell i,j is blank, and false otherwise.
{
  if (i < 1 || i > BoardSize || j < 1 || j > BoardSize)
    throw rangeError("bad value in isBlank");
  return (getCell(i,j) == Blank);
}

void Board::print()
// Prints the current board.
{
  for (int i = 1; i <= BoardSize; i++)
  {
    if ((i-1) % SquareSize == 0)
    {
      std::cout << " -";
      for (int j = 1; j <= BoardSize; j++)
        std::cout << "---";
      std::cout << "-";
      std::cout << std::endl;
    }
    for (int j = 1; j <= BoardSize; j++)
    {
      if ((j-1) % SquareSize == 0)
        std::cout << "|";
      if (!isBlank(i,j))
        std::cout << getCell(i,j);
      else
        std::cout << " ";
    }
    std::cout << "|";
    std::cout << endl;
  }
  std::cout << " -";
  for (int j = 1; j <= BoardSize; j++)
    std::cout << "---";
  std::cout << "-";
  std::cout << "\n\n";
}


void Board::printConflicts(void)
{
  // row 
  cout << "Row Conflicts\n";
  for (int i = 1; i <= BoardSize; i++)
  {
    std::cout << "Row " + std::to_string(i) + ": ";
    for (int j = 1; j <= BoardSize; j++)
    {
      if (row[i][j])
        std::cout << "T ";
      else
        std::cout << "F ";
    }
    std::cout << endl;
  }
  cout << "Column Conflicts\n";
  for (int i = 1; i <= BoardSize; i++)
  {
    std::cout << "Column " + std::to_string(i) + ": ";
    for (int j = 1; j <= BoardSize; j++)
    {
      if (column[i][j])
        std::cout << "T ";
      else
        std::cout << "F ";
    }
    std::cout << endl;
  }
  cout << "Box Conflicts\n";
  for (int i = 1; i <= BoardSize; i++)
  {
    std::cout << "Box " + std::to_string(i) + ": ";
    for (int j = 1; j <= BoardSize; j++)
    {
      if (box[i][j])
        std::cout << "T ";
      else
        std::cout << "F ";
    }
    std::cout << endl;
  }
  std::cout << endl;
  std::cout << endl;
}

bool Board::setCell(int i, int j, int c)
{
  if (i < 1 || i > BoardSize || j < 1 || j > BoardSize || c < 1 || c > BoardSize)
    throw rangeError("bad value in setCell");

  if (row[i][c] || column[j][c] || box[getSubGroup(i,j)][c])
    throw overflowError("value already in conflicts vectors");

  if (getCell(i, j) != Blank) {
    throw overflowError("Position: " + std::to_string(i) + "," + std::to_string(j) +
                        " already has value " + std::to_string(getCell(i, j)));
  } else {
    value[i][j] = c;
    row[i][c] = true;
    column[j][c] = true;
    box[getSubGroup(i,j)][c] = true;
  }

  return (getCell(i, j) == c);
}

bool Board::checkSolved(void)
{
  for (int i = 1; i <= BoardSize; i++)
  {
    for (int j = 1; j <= BoardSize; j++)
    {
      if (isBlank(i, j) || !row[i][j] || !column[i][j])
        return false;
      for (int val = 1; val <= BoardSize; val++)
        if (!box[getSubGroup(i,j)][val]) return false;
    }
  }
  return true;
}

bool Board::checkConflict(int r, int c, int val)
{
  return (!(column[c][val] || row[r][val] || box[getSubGroup(r,c)][val]));
}


bool Board::checkConflict(char type, int num, int val)
{
  switch (type)
  {
    case 'c':
    case 'C':
    case 0:
      for (int i = 0; i < 10; i++)
        column[num][i];
      return !column[num][val];
      break;
    case 'r':
    case 'R':
    case 1:
      return !row[num][val];
    case 'b':
    case 'B':
    case 2:
      return !box[num][val];
    default:
      return true;
  }
}

int getSubGroup(int i, int j) {
  // Divide the row and column indices by 3 to determine the subgroup
  int subgroupRow = (i-1) / SquareSize;
  int subgroupCol = (j-1) / SquareSize;

  // Calculate the subgroup number (1 through 9)
  int subgroup = subgroupRow * 3 + subgroupCol + 1;
  return subgroup;
}

int getValMin()
{
  return MinValue;
}
int getValMax()
{
  return MaxValue;
}
