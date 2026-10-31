class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        //add first 3 elements
        int closest_sum = nums[0] + nums[1] + nums[2];
        
        // Everything must remain inside this for-loop
        for (int i = 0; i < n - 2; i++) {
            //  Check i > 0 to avoid out-of-bounds crash
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                
                if (current_sum == target) {
                    return current_sum;
                }
                
                //  Compare current_sum distance against closest_sum distance
                if (abs(current_sum - target) < abs(closest_sum - target)) {
                    closest_sum = current_sum; //  Update closest_sum
                }
                
                if (current_sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        } 

        return closest_sum;
    }
};
