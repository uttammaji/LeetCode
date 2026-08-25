class Solution {
public:
    int duplicateNumbersXOR(std::vector<int>& nums) {
        int counts[51] = {0};
        int result = 0;
        
        for (int num : nums) {
            counts[num]++;
            if (counts[num] == 2) {
                result ^= num;
            }
        }
        
        return result;
    }
};