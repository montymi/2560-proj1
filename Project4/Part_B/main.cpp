#include <iostream>
#include <vector>
#include "Board.h"

bool solveBoard(Board board, int& recursions);

int main()
{
  ifstream fin;
  // Read the sample grid from the file.
  string fileName = "sudoku.txt";
  fin.open(fileName.c_str());
  if (!fin)
  {
    cerr << "Cannot open " << fileName << endl;
    exit(1);
  }
  try
  {
    Board b1(SquareSize);
    while (fin && fin.peek() != 'Z')
    {
      int recursions = 0;
      b1.initialize(fin);
      b1.print();
      b1.printConflicts();
      if(solveBoard(b1, recursions))
      {
        b1.print();
        std::cout << "solved with " << recursions << " recursions\n\n";
      }
      else
      {
        b1.print();
        std::cout << "no solution found after " << recursions << " recursions\n\n";
      }
    }
  }
  catch (indexRangeError &ex)
  {
    cout << ex.what() << endl;
    exit(1);
  }
}

bool solveBoard(Board board, int& recursions)
{
  std::vector<int> possibleValues = std::vector<int>(0);
  int possibleValCount = 0;
  int solvedValues = 0;
  for (int row = 0; row < SquareSize*SquareSize; row++)
  {
    for (int col = 0; col < SquareSize*SquareSize; col++)
    {
      for (int val = getValMin(); val < getValMax(); val++)
      {
        if (board.checkConflict(row,col,val))
        {
          possibleValues.push_back(val);
          possibleValCount++;
        }
      }
      if(possibleValCount == 1)
      {
        board.setCell(row, col, possibleValues[0]);
        solvedValues++;
      }
      possibleValues = std::vector<int>(0);
    }
  }
  if (board.checkSolved())
    return true;
  if (solvedValues == 0)
    return false;
  return solveBoard(board, ++recursions);
}
