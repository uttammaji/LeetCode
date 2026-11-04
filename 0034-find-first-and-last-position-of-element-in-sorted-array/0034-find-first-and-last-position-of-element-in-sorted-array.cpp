class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findBound(nums, target, true), findBound(nums, target, false)};
    }

private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int bound = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    right = mid - 1; // Look for smaller indices
                } else {
                    left = mid + 1;  // Look for larger indices
                }
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return bound;
    }
};
