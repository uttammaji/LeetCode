#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        // Map to store how many times a particular prefix sum has appeared
        std::unordered_map<int, int> prefix_sums;
        
        // Base case: A prefix sum of 0 has occurred 1 time initially
        // (This catches subarrays that equal k starting directly from index 0)
        prefix_sums[0] = 1;
        
        int curr_sum = 0;
        int count = 0;
        
        for (int num : nums) {
            // 1. Update the running cumulative sum
            curr_sum += num;
            
            // 2. If (curr_sum - k) exists in the map, add its frequency to our count
            if (prefix_sums.find(curr_sum - k) != prefix_sums.end()) {
                count += prefix_sums[curr_sum - k];
            }
            
            // 3. Record/Increment the frequency of the current prefix sum
            prefix_sums[curr_sum]++;
        }
        
        return count;
    }
};
