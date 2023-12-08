#include <iostream>
#include <vector>
#include "Board.h"

bool solveBoard(Board& board, int& recursions);

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
      try{
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
      catch (overflowError &ex)
      {
        cout << ex.what() << endl;
      }
    }
  }
  catch (indexRangeError &ex)
  {
    cout << ex.what() << endl;
    exit(1);
  }
}

bool solveBoard(Board& board, int& recursions)
{
  std::vector<int> possibleValues = std::vector<int>(0);
  int solvedValues = 0;
  for (int row = 1; row <= SquareSize*SquareSize; row++)
  {
    for (int col = 1; col <= SquareSize*SquareSize; col++)
    {
      for (int val = getValMin(); val < getValMax(); val++)
      {
        if ((board.isBlank(row,col)) && board.checkConflict(row,col,val))
        {
          possibleValues.push_back(val);
        }
      }
      if(possibleValues.size() == 1)
      {
        std::cout << "solved (" << row << ", " << col << ") with val " << possibleValues[0] << "\n";
        board.setCell(row, col, possibleValues[0]);
        solvedValues++;
      }
      possibleValues = std::vector<int>(0);
    }
  }
  std::vector<int> candidateCells = std::vector<int>(0);
  for (short i = 1; i <= SquareSize*SquareSize; i++)
  {
    for (short val = 1; val <= SquareSize*SquareSize; val++)
    {
      //check row for value
      if (board.checkConflict('r',i,val))
      {
        for(short j = 1; j <= SquareSize*SquareSize; j++)
        {
          std::cout << "row " << i << ", col " << j  << ", val " << val <<" is:";
          if (board.isBlank(i,j) && board.checkConflict(i,j,val))
          {
            candidateCells.push_back((i << 16) + j);
            std::cout << " CANDIDATE\n";
          }
          else
            std::cout << " not possible\n";
        }
        if(candidateCells.size() == 1)
        {
          int a = (candidateCells[0] & 0xFFFF0000) >> 16, b = (candidateCells[0] & 0xFFFF);
          board.setCell((candidateCells[0] & 0xFFFF0000) >> 16, (candidateCells[0] & 0xFFFF), val);
          std::cout << "Placing " << val << " in cell (" << a << "," << b << ")\n";
          solvedValues++;
        }
        candidateCells = std::vector<int>(0);
      }
      //check column for value
      if (board.checkConflict('c',i,val))
      {
        for(short j = 1; j <= SquareSize*SquareSize; j++)
        {
          std::cout << "row " << j << ", col " << i  << ", val " << val <<" is:";
          if (board.isBlank(j,i) && board.checkConflict(j,i,val))
          {
            candidateCells.push_back((j << 16) + i);
            std::cout << " CANDIDATE\n";
          }
          else
          {
            std::cout << " not possible\n";
          }
        }
        if(candidateCells.size() == 1)
        {
          int a = (candidateCells[0] & 0xFFFF0000) >> 16, b = (candidateCells[0] & 0xFFFF);
          board.setCell((candidateCells[0] & 0xFFFF0000) >> 16, (candidateCells[0] & 0xFFFF), val);
          std::cout << "Placing " << val << " in cell (" << a << "," << b << ")\n";
          solvedValues++;
        }
        candidateCells = std::vector<int>(0);
      }
      //TODO: check box for value
    }
  }
  
  if (board.checkSolved())
    return true;
  if (solvedValues == 0)
    return false;
  recursions++;
  std::cout << "recursion " << recursions << std::endl;
  return solveBoard(board, recursions);
}
