class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Create an n x n grid initialized with 0s
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;
        
        while (top <= bottom && left <= right) {
            // 1. Traverse Right along the top row
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            top++;
            
            // 2. Traverse Down along the right column
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--;
            
            // 3. Traverse Left along the bottom row
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            bottom--;
            
            // 4. Traverse Up along the left column
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++;
        }
        
        return matrix;
    }
};
