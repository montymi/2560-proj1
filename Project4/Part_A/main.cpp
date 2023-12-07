#include <iostream>
#include "Board.h"

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
      b1.initialize(fin);
      b1.print();
      b1.printConflicts();
    }
  }
  catch (indexRangeError &ex)
  {
    cout << ex.what() << endl;
    exit(1);
  }
}
