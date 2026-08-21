class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto countLess = [&](int target) {
            int L = 0, R = nums.size();
            while (L < R) {
                int M = L + (R - L) / 2;
                if (nums[M] < target) L = M + 1;
                else R = M;
            }
            return L;
        };
        int neg = countLess(0);
        int pos = nums.size() - countLess(1);
        return max(neg, pos);
    }
};
