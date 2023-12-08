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

void setCell(int a, int b, char c);

Board::Board(int sqSize)
  : value(BoardSize+1,BoardSize+1)
// Board constructor
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
    }
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
    throw rangeError("bad value in setCell");
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
        std::cout << " " << getCell(i,j) << " ";
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
  std::cout << std::endl;
}


void Board::printConflicts(void)
{}

void setCell(int a, int b, char c)
{
  (void) a;
  (void) b;
  (void) c;
}   
