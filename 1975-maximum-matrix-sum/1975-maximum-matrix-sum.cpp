class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalAbsSum = 0; // Tracks the total sum of all absolute values (long long prevents overflow)
        int negativeCount = 0;     // Tracks the total number of negative elements in the matrix
        int minAbsValue = INT_MAX; // Tracks the smallest absolute value found in the matrix

        // Outer loop to iterate through every row of the matrix
        for (int i = 0; i < matrix.size(); i++) {
            // Inner loop to iterate through every column element of the current row
            for (int j = 0; j < matrix[i].size(); j++) {
                int val = matrix[i][j]; // Extract the current element value
                
                totalAbsSum += abs(val); // Accumulate the absolute value into our running total sum
                
                // Check if the current element is a negative number
                if (val < 0) {
                    negativeCount++; // Increment our count of negative numbers
                }
                
                // Compare and update the minimum absolute value seen in the entire matrix
                minAbsValue = min(minAbsValue, abs(val));
            }
        }

        // If the total number of negative elements is even, they can all be flipped to positive
        if (negativeCount % 2 == 0) {
            return totalAbsSum; // Return the absolute sum directly since no elements need to stay negative
        }
        
        // If the count is odd, exactly one element must stay negative.
        // We choose the smallest element to be negative, subtracting it twice from our positive sum total.
        return totalAbsSum - 2LL * minAbsValue;
    }
};