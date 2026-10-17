class Solution {
private:
    // Helper function to calculate the sum of digits
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Pair each element with its original index
        vector<pair<int, int>> indexedNums(n);
        for (int i = 0; i < n; ++i) {
            indexedNums[i] = {nums[i], i};
        }
        
        // Sort using lambda capturing 'this' to use the private helper method
        sort(indexedNums.begin(), indexedNums.end(), [this](const pair<int, int>& a, const pair<int, int>& b) {
            int sumA = getDigitSum(a.first);
            int sumB = getDigitSum(b.first);
            if (sumA != sumB) {
                return sumA < sumB;
            }
            return a.first < b.first;
        });
        
        // Cycle detection algorithm to count minimum swaps
        vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; ++i) {
            // Skip if the element is already visited or in its correct spot
            if (visited[i] || indexedNums[i].second == i) {
                continue;
            }
            
            int cycle_size = 0;
            int j = i;
            
            while (!visited[j]) {
                visited[j] = true;
                j = indexedNums[j].second;
                cycle_size++;
            }
            
            if (cycle_size > 0) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};
