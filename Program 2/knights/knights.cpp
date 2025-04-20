// File: knights.cpp -- BETH ALLEN SPRING 2025
// Gathers the information for the size of a chessboard and the starting point for the
// knight's tour.  The chessboard returns true or false indicating whether there is a solution
// Then provides the ability to display the board with the given path.
// Rows and Columns are indexed from 0 to N-1.
//-----------------------------------------------------------------------------

#include <iostream>

#include "ChessBoard.h"
using namespace std;

int main(void) {

    ChessBoard myBoard;
    int row, col;
    int N;

    cout << "Enter the board size (max of " << MAXSIZE << "): ";
    cin >> N;
    myBoard.createNewBoard(N);
    cout << "Enter starting square row number: (0-" << N-1 << "): ";
    cin >> row;
    cout << "Enter starting square col number: (0-" << N-1 << "): ";
    cin >> col;

    // start measuring time here
    if (myBoard.solveIt(row, col))
        cout << "\nSolved! ";
    else
        cout << "\nNo solution found! ";

    // end measuring time here, do computation and print it out

    myBoard.display(cout);

    return 0;
}