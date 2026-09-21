class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // 'k' acts as the pointer for the next unique element position
        int k = 1; 
        
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is different from the previous unique element
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i]; // Move it to the next unique position
                k++; // Increment the count of unique elements
            }
        }
        
        return k;
    }
};