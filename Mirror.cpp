// Ali Woodward
// 2385718
// alwoodwadr@chapman.edu
// CPSC 350 Section 03
// Assignment	3- Game of life

// Mirror.cpp is a class that extends the Game class ti impleent the game rules when being played in classic mode.
// Mirror.cpp has many calls to other methods (such as playInside and playOutside) that are in the game class and used by every game mode

// Paremeters-
//char** currGen is the current generation of cells
//int numRows is the number of rows in the grid
//int numCols is the number of columns in the grid

//a char** value is returned that is the new 2d array for the next generation of cells
#include "Game.h"

char** Mirror::playMirror(char** currGen, int numRows, int columns){
  playInside(currGen, numRows, columns);

  //this for loop iterates through the column indexes (not including corners)
  //and sends each index at the top and bottom rows of the grid to the playOutside()
  //method to retrieve the classic neighbor counts for the elements
  for(int c = 1; c < cols -1; ++c){
    //find the classic neighbors of elements in the top row
    int topRowCount = playOutside(currGen, 0, c, "TR");
    //check for mirror neighbors
    if(currGen[0][c] == 'X'){
      ++topRowCount;
    }
    if(currGen[0][c-1] == 'X'){
      ++topRowCount;
    }
    if(currGen[0][c+1] == 'X'){
      ++topRowCount;
    }
    //generate new cells for elements in the top row now that we have neighbor count
    nextGen[0][c] = newCell(topRowCount, 0, c, currGen);

    //find the classic neighbors of elements in the bottom row
    int bottomRowCount = playOutside(currGen, rows-1, c, "BR");
    //checks for mirrored cells
    if(currGen[rows-1][c] == 'X'){
      ++bottomRowCount;
    }
    if(currGen[rows-1][c-1] == 'X'){
      ++bottomRowCount;
    }
    if(currGen[rows-1][c+1] == 'X'){
      ++bottomRowCount;
    }
    //generate new cells for elements in the bottom row now that we have neighbor count
    nextGen[rows-1][c] = newCell(bottomRowCount, rows-1, c, currGen);
  }

  //for loop that iterates through far left and right cols of the grid
  for(int r = 1; r < rows -1; ++r){

    //find the classic neighbors of elements in far left column
    int leftColCount = playOutside(currGen, r, 0, "LC");
    //check for mirrored cells
    if(currGen[r][0] == 'X'){
      ++leftColCount;
    }
    if(currGen[r+1][0] == 'X'){
      ++leftColCount;
    }
    if(currGen[r-1][0] == 'X'){
      ++leftColCount;
    }
    //generate new cells for elements in the bottom row now that we have neighbor count
    nextGen[r][0] = newCell(leftColCount, r, 0, currGen);

    //find the classic neighbors of elements in far left column
    int rightColCount = playOutside(currGen, r, cols-1, "RC");
    //check for mirrored cells
    if(currGen[r][cols-1] == 'X'){
      ++rightColCount;
    }
    if(currGen[r+1][cols-1] == 'X'){
      ++rightColCount;
    }
    if(currGen[r-1][cols-1] == 'X'){
      ++rightColCount;
    }
    //generate new cells for elements in the bottom row now that we have neighbor count
    nextGen[r][cols-1] = newCell(rightColCount, r, cols-1, currGen);

  }

  //checking for neighbors of each corner

  //topLeftCorner
  int topLeftCorner = playOutside(currGen, 0, 0, "TLC");
  //corner reflection x3
  if(currGen[0][0] == 'X'){
    topLeftCorner += 3;
  }
  //checks for relections in two bordering cells
  if(currGen[0][1] == 'X'){
    ++topLeftCorner;
  }
  if(currGen[1][0] == 'X'){
    ++topLeftCorner;
  }
  nextGen[0][0] = newCell(topLeftCorner, 0, 0, currGen);

  //top right corner

  int topRightCorner = playOutside(currGen, 0, cols-1, "TRC");
  if(currGen[0][cols-1] == 'X'){
    topRightCorner += 3;
  }
  //checks for relections in two bordering cells
  if(currGen[0][cols-2] == 'X'){
    ++topRightCorner;
  }
  if(currGen[1][cols-1] == 'X'){
    ++topRightCorner;
  }
  nextGen[0][cols-1] = newCell(topRightCorner, 0, cols-1, currGen);

  //bottom right corner
  int bottomRightCorner = playOutside(currGen, rows-1, cols-1, "BRC");
  if(currGen[rows-1][cols-1] == 'X'){
    bottomRightCorner += 3;
  }
  //checks for relections in two bordering cells
  if(currGen[rows-1][cols-2] == 'X'){
    ++bottomRightCorner;
  }
  if(currGen[rows-2][cols-1] == 'X'){
    ++bottomRightCorner;
  }
  nextGen[rows-1][cols-1] = newCell(bottomRightCorner, rows-1, cols-1, currGen);

  //bottom left corner
  int bottomLeftCorner = playOutside(currGen, rows-1, 0, "BLC");
  if(currGen[rows-1][0] == 'X'){
    bottomLeftCorner += 3;
  }
  //checks for relections in two bordering cells
  if(currGen[rows-1][1] == 'X'){
    ++bottomLeftCorner;
  }
  if(currGen[rows-2][0] == 'X'){
    ++bottomLeftCorner;
  }
  nextGen[rows-1][0] = newCell(bottomLeftCorner, rows-1, 0, currGen);

  return nextGen;
}
