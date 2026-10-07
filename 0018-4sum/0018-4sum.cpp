class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> results;
        
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long current_sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (current_sum == target) {
                        results.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    } else if (current_sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        
        return vector<vector<int>>(results.begin(), results.end());
    }
};
