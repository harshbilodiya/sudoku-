//-------------------------------------------------------------------
// Harsh Bilodiya
//
// Sudoku Solver: C++ Implementation
//
// Disclaimer: A good 60 % of the code came from online sources.
//-------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

// Define global variables
#define EMPTY 0
#define N 9

// Headers for all functions (BGSU style)
void printMessage();
bool FindEmptyLocation(int grid[N][N], int &row, int &col);
bool isSafe(int grid[N][N], int row, int col, int num);
bool solveSudoku(int grid[N][N]);
bool UsedInRow(int grid[N][N], int row, int num);
bool UsedInCol(int grid[N][N], int col, int num);
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);
void printGrid(int grid[N][N]);

int main() {
	// Have user enter thier paritially filled puzzle 
	int grid[N][N] = {{0, 6, 1, 0, 4, 3, 0, 2, 7},
                         {3, 0, 4, 0, 0, 0, 0, 0, 6},
                         {0, 2, 5, 0, 9, 0, 3, 0, 4},
                         {0, 7, 0, 0, 1, 0, 0, 0, 2},
                         {0, 0, 0, 0, 5, 0, 0, 0, 0},
                         {6, 0, 0, 0, 3, 0, 0, 9, 0},
                         {2, 0, 9, 0, 6, 0, 7, 1, 0},
                         {1, 0, 0, 0, 0, 0, 8, 0, 5},
                         {5, 3, 0, 1, 7, 0, 2, 4, 0}};
	
	// Print welcome message
	printMessage();
                      
    if (solveSudoku(grid) == true) {
    	cout << "The solution to the sudoku defined in the program is: " << endl << endl;
    	// Use printGrid function to print solution
    	printGrid(grid);
    	}
    else { 
    		cout << "Sorry, no solutions" << endl;
    	}
    
    cout << "Thanks for using our solver, I bet you can't solve it as fast as I did! (▀̿Ĺ̯▀̿ ̿) " << endl;
    cout << endl;
    return 0;
}

// Implement functions

// Print a message when program is run
void printMessage() {
	cout << endl;
	cout << "*****************************************" << endl;
    cout << "*****************************************" << endl;
	cout << "**                HELLO                **" << endl;
	cout << "**    WELCOME TO OUR SUDOKU SOLVER     **" << endl;
    cout << "*****************************************" << endl;
    cout << "*****************************************" << endl;
}                

// Assign values to all unassigned locations for Sudoku solution
// Also used a recursion on solveSudoku untill the entire puzzle is solved
bool solveSudoku(int grid[N][N]) {
    int row, col;
    if (!FindEmptyLocation(grid, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = EMPTY;
        }
    }
    return false;
}

// Searches the grid to find an entry that is still unassigned
// This is a helper function
bool FindEmptyLocation(int grid[N][N], int &row, int &col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == EMPTY)
                return true;
    return false;
}

// Returns whether any assigned entry n the specified row matches given number
bool UsedInRow(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

// Returns whether any assigned entry in the specified column matches given number
bool UsedInCol(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
// Returns whether any assigned entry within the specified 3x3 box matches given number
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}

// Returns if it is legal to assign num to given column and row lcoations
bool isSafe(int grid[N][N], int row, int col, int num) {
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3 , col - col % 3, num);
}
 
// Print Grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout <<grid[row][col]<<"  ";
            cout << endl;
    }
    cout << endl;
}

