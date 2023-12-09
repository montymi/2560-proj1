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
  int solvedValues = 0;
  {
    //limit scope of variables so they clear before recurse
    std::vector<int> possibleValues = std::vector<int>(0);
    for (int row = 1; row <= SquareSize*SquareSize; row++)
    {
      for (int col = 1; col <= SquareSize*SquareSize; col++)
      {
        for (int val = getValMin(); val <= getValMax(); val++)
        {
          if ((board.isBlank(row,col)) && board.checkConflict(row,col,val))
          {
            possibleValues.push_back(val);
          }
        }
        if(board.isBlank(row,col) && possibleValues.size() == 0)
        {
          return false; //unsolvable puzzle
        }
        if(possibleValues.size() == 1)
        {
          board.setCell(row, col, possibleValues[0]);
          solvedValues++;
        }
        possibleValues = std::vector<int>(0);
      }
    }
  }
  
  {
    //limit scope of variables so they clear before recurse
    std::vector<int> candidateCells = std::vector<int>(0);  
    int solvedValues = 0;
    for (short i = 1; i <= SquareSize*SquareSize; i++)
    {
      for (short val = 1; val <= SquareSize*SquareSize; val++)
      {
        //check row for value
        if (board.checkConflict('r',i,val))
        {
          for(short j = 1; j <= SquareSize*SquareSize; j++)
          {
            if (board.isBlank(i,j) && board.checkConflict(i,j,val))
              candidateCells.push_back((i << 16) + j);
          }
          if(candidateCells.size() == 1)
          {
            board.setCell((candidateCells[0] & 0xFFFF0000) >> 16, (candidateCells[0] & 0xFFFF), val);
            solvedValues++;
          }
          candidateCells = std::vector<int>(0);
        }
        //check column for value
        if (board.checkConflict('c',i,val))
        {
          for(short j = 1; j <= SquareSize*SquareSize; j++)
          {
            if (board.isBlank(j,i) && board.checkConflict(j,i,val))
              candidateCells.push_back((j << 16) + i);
          }
          if(candidateCells.size() == 1)
          {
            board.setCell((candidateCells[0] & 0xFFFF0000) >> 16, (candidateCells[0] & 0xFFFF), val);
            solvedValues++;
          }
          candidateCells = std::vector<int>(0);
        }
        //check box for value
        if (board.checkConflict('b',i,val))
        {
          for(short j = 1; j <= SquareSize*SquareSize; j++)
          {
            int r = (3*((i-1)/3))+((j-1)/3)+1; // convert from house and
            int c = (3*((i-1)%3))+((j-1)%3)+1; // cell to row and column
            if (board.isBlank(r,c) && board.checkConflict(r,c,val))
              candidateCells.push_back((r << 16) + c);
          }
          if(candidateCells.size() == 1)
          {
            board.setCell((candidateCells[0] & 0xFFFF0000) >> 16, (candidateCells[0] & 0xFFFF), val);
            solvedValues++;
          }
          candidateCells = std::vector<int>(0);
        }
      }
    }
  }
  
  if (board.checkSolved())
    return true;
  if (solvedValues == 0)
  {
    std::vector<int> testVals;
    int minCol = -1, minRow = -1;
    {
      //limit scope of variables so they clear before recurse
      int minNumVals = getValMax() - getValMin() + 2;
      std::vector<int> possibleValues = std::vector<int>(0);
      for (int row = 1; row <= SquareSize*SquareSize; row++)
      {
        for (int col = 1; col <= SquareSize*SquareSize; col++)
        {
          for (int val = getValMin(); val <= getValMax(); val++)
          {
            if ((board.isBlank(row,col)) && board.checkConflict(row,col,val))
            {
              possibleValues.push_back(val);
            }
          }
          if(possibleValues.size() == 2)
          {
            testVals = possibleValues;
            minCol = col;
            minRow = row;
            goto lbl_break;
          }
          if(possibleValues.size() < minNumVals)
          {
            minNumVals = possibleValues.size();
            minCol = col;
            minRow = row;
            testVals = possibleValues;
          }
          possibleValues = std::vector<int>(0);
        }
      }
    }
    
    lbl_break: // this is the one acceptable use of goto according to the MISRA standard
    for (int i = 0; i < testVals.size(); i++)
    {
      Board b1 = board;
      b1.setCell(minRow, minCol, testVals[i]);
      if(solveBoard(b1, ++recursions))
      {
        board = b1;
        return true;
      }
    }
    return false;
  }
  
  return solveBoard(board, ++recursions);
}
