class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                
                int num = board[r][c] - '1';          // Convert '1'-'9' to index 0-8
                int boxIndex = (r / 3) * 3 + (c / 3); // Identify which 3x3 sub-box (0-8)
                
                // If already seen in the current row, column, or 3x3 box, it's invalid
                if (rows[r][num] || cols[c][num] || boxes[boxIndex][num]) {
                    return false;
                }
                
                // Mark digit as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[boxIndex][num] = true;
            }
        }
        
        return true;
    }
};
