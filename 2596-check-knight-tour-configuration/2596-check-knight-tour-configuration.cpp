class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expVal) {
        // Base Case 1: Out of bounds or current cell value does not match expected value
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal) {
            return false;
        }

        // Base Case 2: Successfully reached the last move of the tour
        if (expVal == n * n - 1) {
            return true;
        }

        // Explore all 8 possible moves of a knight
        int ans1 = isValid(grid, r - 2, c + 1, n, expVal + 1);
        int ans2 = isValid(grid, r - 1, c + 2, n, expVal + 1);
        int ans3 = isValid(grid, r + 1, c + 2, n, expVal + 1);
        int ans4 = isValid(grid, r + 2, c + 1, n, expVal + 1);
        int ans5 = isValid(grid, r + 2, c - 1, n, expVal + 1);
        int ans6 = isValid(grid, r + 1, c - 2, n, expVal + 1);
        int ans7 = isValid(grid, r - 1, c - 2, n, expVal + 1);
        int ans8 = isValid(grid, r - 2, c - 1, n, expVal + 1);

        // If any path successfully completes the full tour, return true
        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        // Start the search from the top-left cell (0, 0) expecting the move 0
        return isValid(grid, 0, 0, grid.size(), 0);
    }
};
