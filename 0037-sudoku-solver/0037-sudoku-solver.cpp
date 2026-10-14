class Solution {
public:
    // This function checks if it's safe to put a number 'c' in a spot
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false;    // Rule 1: Already in this row?
            if (board[i][col] == c) return false;    // Rule 2: Already in this column?
            
            // Rule 3: Already in this small 3x3 block?
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true; // Safe to place!
    }

    // The main engine that solves the board
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                
                if (board[row][col] == '.') { // 1. Found an empty spot!
                    
                    for (char c = '1'; c <= '9'; c++) { // 2. Guess numbers 1 to 9
                        if (isValid(board, row, col, c)) { // 3. Check the rules
                            board[row][col] = c; // Write the number in pencil
                            
                            if (solve(board)) return true; // Keep going to next spots!
                            
                            board[row][col] = '.'; // 4. Erase it (Backtrack) if we got stuck later
                        }
                    }
                    return false; // Tell the previous step: "Hey, I'm stuck, change your choice!"
                }
            }
        }
        return true; // The whole board is full and perfect!
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
