class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        //Cyclic Sort - Place each valid number x at index x - 1
        for (int i = 0; i < n; ++i) {
            //Keep swapping until the number is out of range [1, n] 
            //it is already at its correct target index position
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        //Find the first index where the number doesn't match its slot (i + 1)
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        //If all spots are perfect from 1 to n, the missing number is n + 1
        return n + 1;
    }
};