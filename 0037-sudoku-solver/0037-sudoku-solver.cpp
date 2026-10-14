#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Helper function to check if placing 'digit' at board[row][col] is safe
    bool isSafe(vector<vector<char>>& board, int row, int col, char digit) {
        // 1. Check Row (Horizontal Line)
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == digit) {
                return false;
            }
        }

        // 2. Check Column (Vertical Line)
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == digit) {
                return false;
            }
        }

        // 3. Check 3x3 Small Grid
        // Find the starting row and column index of the local 3x3 grid
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == digit) {
                    return false;
                }
            }
        }

        // If no rules are broken, it is completely safe!
        return true;
    }

    // Helper function that uses recursion and backtracking to solve the puzzle
    bool helper(vector<vector<char>>& board, int row, int col) {
        // Base Case: If we reach row 9, it means we successfully filled the whole board
        if (row == 9) {
            return true;
        }

        // Move to the next row if we finish all columns of the current row
        int nextRow = row;
        int nextCol = col + 1;
        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        // If the current cell already has a number, skip it and move forward
        if (board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        // If the current cell is empty ('.'), try placing digits '1' to '9'
        for (char digit = '1'; digit <= '9'; digit++) {
            if (isSafe(board, row, col, digit)) {
                board[row][col] = digit; // Place the digit (Work)

                // Recursively call for the next cell
                if (helper(board, nextRow, nextCol)) {
                    return true; // If it returns true, puzzle is solved!
                }

                board[row][col] = '.'; // Backtracking step 
            }
        }

        return false; // If no digit fits, return false to trigger backtracking
    }

    // Main function called by LeetCode / User
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};
